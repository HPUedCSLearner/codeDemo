#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <chrono>

using namespace std;

std::vector<int> readRandomArrayFromFile(const std::string& filename);
void checkSortArr(vector<int>& arr, int n);

void quickSort(vector<int>& arr, int left, int right)
{
    // 递归出口
    if(left >= right) return;
    

    int tmp = arr[left]; // pivot
    int i = left, j = right;
    
    // 找到数组arr范围[left, right]中，元素arr[left]的真正插入位置i
    while(i < j) {
        while(i<j && arr[j] >= tmp) --j;
        if(i<j) {
            arr[i] = arr[j];
            ++i;
        }
        while(i<j && arr[i] < tmp) ++i;
        if(i<j) {
            arr[j] = arr[i];
            --j;
        }
    }
    arr[i] = tmp;

    // 排序数组arr范围[left, i-1]
    quickSort(arr, left, i-1);
    // 排序数组arr范围[i+1, right]
    quickSort(arr, i+1, right);
}


int main() {
    std::string filename = "random_array.txt"; // 输出文件名
    // 从文件中读取随机数组
    std::vector<int> arr = std::move(readRandomArrayFromFile(filename));
    int n = arr.size();

    auto start = std::chrono::high_resolution_clock::now();
    // 排序
    // testSwapVector();
    quickSort(arr, 0, n-1);
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