#include <iostream>
#include <vector>
#include <random>

// 生成随机数组的函数
std::vector<int> generateRandomArray(int size, int min, int max) {
    std::random_device rd;  // 使用随机设备作为随机数种子
    std::mt19937 gen(rd()); // 使用 Mersenne Twister 引擎
    std::uniform_int_distribution<> dis(min, max); // 生成均匀分布的整数

    std::vector<int> randomArray;
    for (int i = 0; i < size; ++i) {
        randomArray.push_back(dis(gen)); // 生成随机数并添加到数组中
    }
    return std::move(randomArray);
}

int main() {
    int size = 100;   // 数组大小
    int min = 0;     // 随机数最小值
    int max = 10000;   // 随机数最大值

    // 生成随机数组
    std::vector<int> randomArray = generateRandomArray(size, min, max);

    // 打印随机数组
    std::cout << "Random Array:" << std::endl;
    for (int num : randomArray) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
