[目录](../README.md)

[toc]


### 生成随机数数组
[getRandomArr01.cpp;](./getRandomArr/getRandomArr01.cpp)
[getRandomArr02-writeToFile.cpp;](./getRandomArr/getRandomArr02-writeToFile.cpp)
[getRandomArr03-readFileToArr.cpp;](./getRandomArr/getRandomArr03-readFileToArr.cpp)

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


### 排序
[sort.cpp](./arrSort/sort.cpp)

#### 1、直接插入排序
[0,j]  是已经排好序的元素；
[i,n-1]是没有排好序的元素；
需要在[0,j]中找到元素arr[i],的出入位置；
在查找过程中，后移比arr[i]的元素；
```cpp
void insertSort(vector<int>& arr, int n)
{
    int tmp, j;
    for(int i = 1; i < n; ++i) {
        j = i-1;
        tmp = arr[i];
        while(j>=0 && tmp < arr[j]) {
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = tmp;
    }
}
```
#### 2、选择排序
寻找未排序部分的最小值，然后交换到未排序数组的第一个元素；
```cpp
void selectSort(vector<int>& arr, int n)
{
    int k;
    for(int i = 0; i < n; ++i) {
        k = i;
        for(int j = i+1; j < n; ++j) {
            if(arr[j] < arr[k]) k = j;
        }
        swap(arr[i], arr[k]);
    }
}

```
#### 3、冒泡排序
冒泡排序需要进行n-1轮；
每轮冒泡把最大值后移到已排序部分；
```cpp
void bubleSort(vector<int>& arr, int n)
{
    for(int i = 0; i < n-1; ++i) {
        for(int j = 1; j < n-i; ++j) {
            if(arr[j-1] > arr[j]) swap(arr[j-1], arr[j]);
        }
    }
}
```