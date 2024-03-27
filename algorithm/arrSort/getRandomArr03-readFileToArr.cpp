#include <iostream>
#include <vector>
#include <random>
#include <fstream>

// 生成随机数组并写入文件的函数
void generateAndWriteRandomArrayToFile(int size, int min, int max, const std::string& filename) {
    std::random_device rd;  // 使用随机设备作为随机数种子
    std::mt19937 gen(rd()); // 使用 Mersenne Twister 引擎
    std::uniform_int_distribution<> dis(min, max); // 生成均匀分布的整数

    std::ofstream outputFile(filename); // 创建输出文件流

    if (!outputFile.is_open()) { // 检查文件是否成功打开
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    for (int i = 0; i < size; ++i) {
        int num = dis(gen); // 生成随机数
        outputFile << num << "\t"; // 将随机数写入文件
        if((i+1) % 10 == 0) {
            outputFile << std::endl;
        }
    }

    outputFile.close(); // 关闭文件流
    std::cout << "Random Array has been written to file: " << filename << std::endl;
}

// 从文件中读取随机数组的函数
std::vector<int> readRandomArrayFromFile(const std::string& filename) {
    std::ifstream inputFile(filename); // 创建输入文件流

    if (!inputFile.is_open()) { // 检查文件是否成功打开
        std::cerr << "Error opening file: " << filename << std::endl;
        return {};
    }

    std::vector<int> randomArray;
    int num;
    while (inputFile >> num) { // 从文件中逐行读取数字
        randomArray.push_back(num); // 将数字存储到数组中
    }

    inputFile.close(); // 关闭文件流
    return randomArray;
}

int main() {
    int size = 1000;   // 数组大小
    int min = 0;     // 随机数最小值
    int max = 1000;   // 随机数最大值
    std::string filename = "random_array.txt"; // 输出文件名

    // 生成随机数组并写入文件
    generateAndWriteRandomArrayToFile(size, min, max, filename);

    // 从文件中读取随机数组
    std::vector<int> randomArray = readRandomArrayFromFile(filename);

    // 打印读取的随机数组
    std::cout << "Random Array read from file: ";
    for (int num : randomArray) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
