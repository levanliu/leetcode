#include <iostream>
#include <string>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <chrono>

// 消息类，封装要发送的字符串
class Message {
public:
    // 默认构造函数
    Message() : data("") {}
    // 带参数的构造函数
    Message(const std::string& d) : data(d) {}
    // 赋值运算符
    Message& operator=(const Message& other) {
        if (this != &other) {
            data = other.data;
        }
        return *this;
    }
    // 序列化方法，将消息转换为字符串
    std::string serialize() const {
        return data;
    }
    // 反序列化方法，将字符串转换为消息
    void deserialize(const std::string& s) {
        data = s;
    }
private:
    std::string data; // 消息的数据
};

// 消息队列类，存储消息对象
class MessageQueue {
public:
    // 推入消息，向队列尾部添加一个消息
    void push(const Message& msg) {
        std::unique_lock<std::mutex> lock(mtx); // 上锁
        queue.push(msg); // 将消息加入队列
        cv.notify_one(); // 通知等待的线程
    }
    // 等待消息，从队列头部取出一个消息，如果队列为空，则阻塞等待
    void wait(Message& msg) {
        std::unique_lock<std::mutex> lock(mtx); // 上锁
        while (queue.empty()) { // 如果队列为空
            cv.wait(lock); // 等待条件变量
        }
        msg = queue.front(); // 取出队列头部的消息
        queue.pop(); // 弹出队列头部的消息
    }
    // 轮询消息，从队列头部取出一个消息，如果队列为空，则立即返回false
    bool poll(Message& msg) {
        std::unique_lock<std::mutex> lock(mtx); // 上锁
        if (queue.empty()) { // 如果队列为空
            return false; // 返回false
        }
        msg = queue.front(); // 取出队列头部的消息
        queue.pop(); // 弹出队列头部的消息
        return true; // 返回true
    }
private:
    std::queue<Message> queue; // 队列容器
    std::mutex mtx; // 互斥量
    std::condition_variable cv; // 条件变量
};

// 生产者类，向消息队列发送消息
class Producer {
public:
    // 构造函数，接收一个消息队列的引用
    Producer(MessageQueue& mq) : queue(mq) {}
    // 启动线程，发送若干条消息
    void start() {
        thread = std::thread([this] {
            for (int i = 0; i < 10; i++) { // 循环10次
                std::string s = "Hello " + std::to_string(i); // 生成一个字符串
                Message msg(s); // 创建一个消息对象
                queue.push(msg); // 向消息队列推入消息
                std::cout << "Producer send: " << msg.serialize() << std::endl; // 打印发送的消息
                std::this_thread::sleep_for(std::chrono::seconds(1)); // 睡眠1秒
            }
            Message msg("Bye"); // 创建一个结束消息
            queue.push(msg); // 向消息队列推入消息
            std::cout << "Producer send: " << msg.serialize() << std::endl; // 打印发送的消息
        });
    }
    // 等待线程结束
    void join() {
        thread.join();
    }
private:
    MessageQueue& queue; // 消息队列的引用
    std::thread thread; // 线程对象
};

// 消费者类，从消息队列接收消息
class Consumer {
public:
    // 构造函数，接收一个消息队列的引用
    Consumer(MessageQueue& mq) : queue(mq) {}
    // 启动线程，接收若干条消息
    void start() {
        thread = std::thread([this] {
            Message msg; // 创建一个消息对象
            while (true) { // 无限循环
                queue.wait(msg); // 从消息队列等待消息
                std::cout << "Consumer receive: " << msg.serialize() << std::endl; // 打印接收的消息
                if (msg.serialize() == "Bye") { // 如果是结束消息
                    break; // 跳出循环
                }
            }
        });
    }
    // 等待线程结束
    void join() {
        thread.join();
    }
private:
    MessageQueue& queue; // 消息队列的引用
    std::thread thread; // 线程对象
};

int main() {
    MessageQueue mq; // 创建一个消息队列对象
    Producer p(mq); // 创建一个生产者对象
    Consumer c(mq); // 创建一个消费者对象
    p.start(); // 启动生产者线程
    c.start(); // 启动消费者线程
    p.join(); // 等待生产者线程结束
    c.join(); // 等待消费者线程结束
    return 0;
}

