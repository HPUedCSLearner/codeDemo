#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

#include <chrono>

using namespace std;

std::vector<int> readRandomArrayFromFile(const std::string& filename);
void checkSortArr(vector<int>& arr, int n);

void merge(vector<int>& arr, int left, int mid, int right, int* arrBuf)
{
    int i = left, j = mid+1, p = left;  // a1,[left, mid]; a2, [mid+1, right]
    while(i<=mid && j<= right) {        // 归并子数组a1,子数组a2到buf中
        if(arr[i] < arr[j]) {
            arrBuf[p++] = arr[i++];
        } else {
            arrBuf[p++] = arr[j++];
        }
    }
    while(i<=mid) arrBuf[p++] = arr[i++];   // 归并剩余子数组的数据，到buf中
    while(j<=right) arrBuf[p++] = arr[j++];

    for(int i = left; i <= right; ++i) {    // 将在buf中排好序的数组元素，赋值回原来的数组arr
        arr[i] = arrBuf[i];
    }
}

void partation(vector<int>& arr, int left, int right, int* arrBuf) {
    if(left >= right) return;               // 递归出口

    int mid = left + (right-left)/2;

    partation(arr, left, mid, arrBuf);      // 划分子数组
    partation(arr, mid+1, right, arrBuf);

    merge(arr, left, mid, right, arrBuf);   // 归并两个有序的子数组

}

// mergeSort的入口函数
void mergeSort(vector<int>& arr, int nums)
{
    int *arrBuf = new int [nums];
    partation(arr, 0, nums-1, arrBuf);
    delete[] arrBuf;
}


int main() {
    std::string filename = "random_array.txt"; // 输出文件名
    // 从文件中读取随机数组
    std::vector<int> arr = std::move(readRandomArrayFromFile(filename));
    int n = arr.size();

    auto start = std::chrono::high_resolution_clock::now();
    // 排序
    // testSwapVector();
    mergeSort(arr, n);
    auto end = std::chrono::high_resolution_clock::now();


    // 查看排序结果
    for(const auto& a : arr) {
        cout << a << " ";
    } 
    cout << endl;

    // 计算持续时间，转换为合适的单位显示
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Function took " << duration.count() << " microseconds to execute.\n";

    checkSortArr(arr, n);

    return 0;
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
    return std::move(randomArray);
}

void checkSortArr(vector<int>& arr, int n)
{
    bool flag = true;
    for(int i = 1; i < n; ++i) {
        if(arr[i] < arr[i-1]) {
            flag = false;
            cout << arr[i] << " " << arr[i-1] << endl;
            break;
        }
    }
    if(flag) {
        cout << "Check Sort Result OK !!!" << endl;
    } else {
        cout << "Sort Arr ERROR !!!" << endl;
    }
}