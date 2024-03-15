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
        outputFile << num << " "; // 将随机数写入文件
    }

    outputFile.close(); // 关闭文件流
    std::cout << "Random Array has been written to file: " << filename << std::endl;
}

int main() {
    int size = 100;   // 数组大小
    int min = 0;     // 随机数最小值
    int max = 10000;   // 随机数最大值
    std::string filename = "random_array.txt"; // 输出文件名

    // 生成随机数组并写入文件
    generateAndWriteRandomArrayToFile(size, min, max, filename);

    return 0;
}
