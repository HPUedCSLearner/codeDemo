[目录](../README.md)

[toc]


### 生成随机数数组
[getRandomArr01.cpp](./getRandomArr/getRandomArr01.cpp)
[getRandomArr02-writeToFile.cpp](./getRandomArr/getRandomArr02-writeToFile.cpp)
[getRandomArr03-readFileToArr.cpp](./getRandomArr/getRandomArr03-readFileToArr.cpp)

写文件的基本操作
```C++
#include <fstream>
    std::ofstream outputFile(filename); // 创建输出文件流

    if (!outputFile.is_open()) {    // 检查文件是否成功打开
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    for (int i = 0; i < size; ++i) {
        int num = dis(gen);         // 生成随机数
        outputFile << num << " ";   // 将随机数写入文件
    }

    outputFile.close(); // 关闭文件流
```

读文件的基本操作
```C++
// 创建输入文件流
// 检查文件是否成功打开
// 从文件中逐行读取数字
// 关闭文件流
#include <fstream>
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
```