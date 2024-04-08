#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

void generateRandomNumbers(const std::string &filename, int count)
{
    std::ofstream file(filename);

    if (!file.is_open())
    {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }

    std::random_device rd;                                   // 随机数种子
    std::mt19937 generator(rd());                            // 随机数生成器
    std::uniform_int_distribution<int> distribution(1, 1e9); // 生成范围为1到1000的均匀分布整数

    for (int i = 0; i < count; ++i)
    {
        file << distribution(generator) << std::endl;
    }

    file.close();
}

void splitFile(const std::string &inputFile, const std::string &outputFilePrefix, int chunkSize, int &fileIndex)
{
    std::ifstream input(inputFile);
    std::vector<int> numbers;
    numbers.reserve(chunkSize); // 预留空间

    std::string line;
    while (std::getline(input, line))
    {
        std::istringstream iss(line);
        std::copy(std::istream_iterator<int>(iss), std::istream_iterator<int>(), std::back_inserter(numbers));

        if (numbers.size() >= chunkSize)
        {
            std::sort(numbers.begin(), numbers.end());
            std::ofstream output(outputFilePrefix + std::to_string(fileIndex++) + ".tmp");
            std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<int>(output, " "));
            output << "\n"; // 添加换行符
            numbers.clear();
        }
    }

    if (!numbers.empty())
    {
        std::sort(numbers.begin(), numbers.end());
        std::ofstream output(outputFilePrefix + std::to_string(fileIndex++) + ".tmp");
        std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<int>(output, " "));
        output << "\n"; // 添加换行符
        numbers.clear();
    }
}

void mergeFiles(const std::string &outputFile, const std::string &inputFilePrefix, int fileCount)
{
    std::vector<std::ifstream> inputs(fileCount);
    std::vector<int> numbers(fileCount);
    std::vector<bool> activeInputs(fileCount, true);

    for (int i = 0; i < fileCount; i++)
    {
        inputs[i].open(inputFilePrefix + std::to_string(i) + ".tmp");
        inputs[i] >> numbers[i];
    }

    std::ofstream output(outputFile);

    struct Compare
    {
        bool operator()(const std::pair<int, int> &a, const std::pair<int, int> &b)
        {
            return a.first > b.first;
        }
    };

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Compare> pq;

    for (int i = 0; i < fileCount; i++)
    {
        if (activeInputs[i])
        {
            pq.push({numbers[i], i});
            if (!(inputs[i] >> numbers[i]))
            {
                activeInputs[i] = false;
            }
        }
    }

    while (!pq.empty())
    {
        int minValue = pq.top().first;
        int minIndex = pq.top().second;
        pq.pop();

        output << minValue << "\n";

        if (activeInputs[minIndex])
        {
            pq.push({numbers[minIndex], minIndex});
            if (!(inputs[minIndex] >> numbers[minIndex]))
            {
                activeInputs[minIndex] = false;
            }
        }
    }

    for (int i = 0; i < fileCount; i++)
    {
        inputs[i].close();
    }
}

void deleteTempFiles(const std::string &inputFilePrefix, int fileCount)
{
    for (int i = 0; i < fileCount; i++)
    {
        std::string fileName = inputFilePrefix + std::to_string(i) + ".tmp";
        std::remove(fileName.c_str());
    }
}

int main()
{
    const std::string filename = "numbers.txt";
    const int count = 1e7;
    const std::string inputFile = "numbers.txt";
    const std::string outputFile = "sorted_numbers.txt";
    const std::string tempFilePrefix = "temp_";
    const int chunkSize = 100000;
    int fileIndex = 0;

    generateRandomNumbers(filename, count);
    splitFile(inputFile, tempFilePrefix, chunkSize, fileIndex);
    mergeFiles(outputFile, tempFilePrefix, fileIndex);
    deleteTempFiles(tempFilePrefix, fileIndex);

    return 0;
}
