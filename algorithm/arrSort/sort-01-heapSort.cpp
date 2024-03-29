#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

#include <chrono>

using namespace std;

std::vector<int> readRandomArrayFromFile(const std::string& filename);

void heapify(vector<int>& arr, int n, int i);
void heapSort(vector<int>& arr, int n);

void testSwapVector()
{
    // vector<int> a{1, 2, 3, 4};   // swap(a[0], b[1]) ok
    int a[] = {1, 2, 3, 4};         // swap(a[0], b[1]) ok
    for(const auto& i : a){
        cout << i << " ";
    } cout << endl;

    swap(a[0], a[1]);

    for(const auto& i : a){
        cout << i << " ";
    } cout << endl;
}
// 1 2 3 4 
// 2 1 3 4

int main() {
    std::string filename = "random_array.txt"; // 输出文件名
    // 从文件中读取随机数组
    std::vector<int> arr = std::move(readRandomArrayFromFile(filename));
    int n = arr.size();

    auto start = std::chrono::high_resolution_clock::now();
    // 排序
    // testSwapVector();
    heapSort(arr, n);
    auto end = std::chrono::high_resolution_clock::now();


    // 查看排序结果
    for(const auto& a : arr) {
        cout << a << " ";
    } 
    cout << endl;


    // 计算持续时间，转换为合适的单位显示
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Function took " << duration.count() << " microseconds to execute.\n";


    return 0;
}

// 单口递归
void heapify(vector<int>& arr, int n, int i) // max Heap
{
    int maxIdx = i;
    int leftSon = 2 * i + 1;
    int rightSon = 2 * i + 2;
    if(leftSon < n && arr[leftSon] > arr[maxIdx])
        maxIdx = leftSon;
    if(rightSon < n && arr[rightSon] > arr[maxIdx])
        maxIdx = rightSon;
    if(i != maxIdx) {
        swap(arr[i], arr[maxIdx]);
        heapify(arr, n, maxIdx);
    }
}

void heapSort(vector<int>& arr, int n) {
    // 建堆
    for(int i = n/2-1; i >= 0; --i) {
        heapify(arr, n, i);
    }
    // 排序
    for(int i = n-1; i > 0; --i) {
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
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