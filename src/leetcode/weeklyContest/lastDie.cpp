#include <iostream>
#include <vector>
#include <random>
#include <thread>
#include <future>
#include <functional>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <map>
using namespace std;

class ThreadPool
{
public:
    using Task = std::function<void()>;

private:
    std::vector<std::thread> mWorkers; // workers container.
    std::queue<Task> mTasks;           // tasks queue
    std::thread mManager;              // manager thread
    std::mutex mQueueMutex;            // queue mutex
    std::condition_variable mCondVar;  // condition variable
    bool mStop;
    std::size_t mNumThreads; // the number of elements in a container

public:
    // the constructor function only be used for direct initialization
    explicit ThreadPool(std::size_t numThreads)
        : mStop(false), mNumThreads(numThreads)
    {
        for (std::size_t i = 0; i < numThreads; i++)
        {
            mWorkers.emplace_back([this]
                                  {
                while (true)
                {
                    Task task;
                    {
                        std::unique_lock<std::mutex> lock{ mQueueMutex };
                        //释放锁，并将调用线程置于休眠状态，直到满足以下条件之一  (mStop变为true或者任务容器mTasks不为空)
                        //在满足条件之后，并且收到notify_one()或者notify_all()将会重新去获得锁。
                        mCondVar.wait(lock, [this] { return mStop || !mTasks.empty(); });
                        if (mStop && mTasks.empty())
                            return;
                        task = std::move(mTasks.front());
                        mTasks.pop();
                    }
                    task();
                    std::this_thread::sleep_for(std::chrono::seconds(3));
                } });
        }

        // Start the manager thread
        mManager = std::thread([this]
                               {
            while (!mStop)
            {
                std::unique_lock<std::mutex> lock{ mQueueMutex };
                //释放锁，并将调用线程置于休眠状态 1 秒，之后收到notify_one()或者notify_all()会重新获得锁
                mCondVar.wait_for(lock, std::chrono::seconds(1));
                if (mStop)
                    return;
                auto tasksSize = mTasks.size();
                auto workersSize = mWorkers.size();
                auto threadsRatio = tasksSize / (workersSize + 1);

                // check if the number of tasks is greater than 
                // the number of workers and if the task-to-worker ratio is greater than 2
                if (tasksSize > workersSize && threadsRatio > 2)
                {
                    std::cout << "Adding new worker thread\n";
                    mWorkers.emplace_back([this] {
                        while (true)
                        {
                            Task task;
                            {
                                std::unique_lock<std::mutex> lock{ mQueueMutex };
                                mCondVar.wait(lock, [this] { return mStop || !mTasks.empty(); });
                                if (mStop && mTasks.empty())
                                    return;
                                task = std::move(mTasks.front());
                                mTasks.pop();
                            }
                            task();
                        }
                    });
                }
                // check if the number of tasks is less than half the number of workers
                // and if the number of workers is greater than the initial number of threads
                else if (tasksSize < workersSize / 2 && workersSize > mNumThreads)
                {
                    std::cout << "Removing worker thread\n";
                    // Here we detach the thread so that it continues executing on its own
                    // and can be cleaned up by the operating system
                    mWorkers.back().detach();
                    mWorkers.pop_back();
                }
            } });
    }

    ~ThreadPool()
    {
        {
            std::unique_lock<std::mutex> lock{mQueueMutex};
            mStop = true;
        }
        // Notify all threads and the manager thread to stop
        mCondVar.notify_all();
        // Wait for manager thread to finish
        mManager.join();
        // Wait for all worker threads to finish
        for (auto &worker : mWorkers)
            if (worker.joinable())
                worker.join();
    }

    /** F &&f, Args &&...args work for perfect forwarding
     */
    template <typename F, typename... Args>
    auto enqueue(F &&f, Args &&...args) -> std::future<typename std::result_of<F(Args...)>::type>
    {
        // typedef for the return type of the function or function object F when it is called with the arguments Args....
        using return_type = typename std::result_of<F(Args...)>::type;
        // creates a std::shared_ptr to a std::packaged_task that wraps a callable object f and its arguments args....
        // wraps a callable object (such as a function, function pointer, or function object) and allows you to invoke it later and obtain its result through a std::future.
        // The template parameter return_type() represents the return type of the callable object.
        auto task = std::make_shared<std::packaged_task<return_type()>>(
            std::bind(std::forward<F>(f), std::forward<Args>(args)...));
        std::future<return_type> res = task->get_future();
        {
            std::unique_lock<std::mutex> lock{mQueueMutex};
            if (mStop)
                throw std::runtime_error("enqueue on stopped ThreadPool");

            //*task is dereferences
            // non-copyable or non-movable element.
            mTasks.emplace([task]()
                           { (*task)(); });
        }
        // Notify one of the worker threads that a new task is available
        mCondVar.notify_one();
        return res;
    }
};

int findHighestSurvivor(int n)
{
    if (n <= 0)
        return 0;

    vector<int> people(n);
    for (int i = 0; i < n; i++)
    {
        people[i] = i + 1;
    }

    std::random_device rd;
    std::mt19937 rng(rd());

    while (people.size() > 1)
    {
        std::uniform_int_distribution<int> dist(0, people.size() - 1);
        int indexToRemove = dist(rng);
        while (indexToRemove % 2 != 0)
        {
            indexToRemove = dist(rng);
        }
        people.erase(people.begin() + indexToRemove);
    }
    return people[0];
}

void solution()
{
    constexpr int N = 605;
    int dp[N][N];

    int n = 600;
    
    dp[1][0] = 0;
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            double jd2 = (double)(j / 2);         // before j
            double jp1d2 = (double)((j + 1) / 2); // after j
            double ip1d2 = (double)((i + 1) / 2); // total
            dp[i][j] = dp[i - 1][j - 1] * jd2 / ip1d2 +
                       dp[i - 1][j] * (ip1d2 - jp1d2) / ip1d2;
        }
    }
    cout << dp[n][n] << endl;
}

int main()
{
    ThreadPool pool(16);

    std::mutex result_mutex;
    // std::vector<int> results(1000000);
    std::vector<std::future<int>> results;

    for (size_t i = 0; i < 10000000; i++)
    {
        results.emplace_back(pool.enqueue(
            [i]()
            { return findHighestSurvivor(600); }));
    }

    std::map<int, int> ans;
    for (auto &res : results)
    {
        ans[res.get()]++;
    }
    int s = 0, key = -1;
    for (auto it = ans.begin(); it != ans.end(); it++)
    {
        if (s < it->second)
        {
            key = it->first;
            s = it->second;
        }
    }
    std::cout << key << " " << s << std::endl;
    return 0;
}