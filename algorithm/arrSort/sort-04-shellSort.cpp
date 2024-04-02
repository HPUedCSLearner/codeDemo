#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <chrono>

using namespace std;

std::vector<int> readRandomArrayFromFile(const std::string& filename);
void checkSortArr(vector<int>& arr, int n);

// [0, i]表示有序元素
// [i+1, n-1] 表示待排序元素
// 初始状态，i = 0, 第一个元素是有序的，还有n-1个元素需要进行插入排序
void insertSort(vector<int>& arr, int n)
{
    int i = 0, k;
    for(int j = i+1; j < n; ++j) {
        k = j;
        while(k-1 >= 0 && arr[k] < arr[k-1]) {   // 我比你小，你往后库对库对（后移）
            swap(arr[k], arr[k-1]);         
            --k;
        }
    }
}

void shellSort(vector<int>& arr, int n)
{
    int j;
    for(int gap = n/2; gap >= 1; gap /= 2) {    // gap排序的次数，当gap==1的时候，数组基本有序，大大减少了数组的移动，或交换次数
        for(int i = gap; i < n; ++i) {
            j = i;
            while(j-gap >= 0 && arr[j] < arr[j-gap]) {
                swap(arr[j], arr[j-gap]);
                j -= gap;
            }
        }
    }
}

int main() {
    std::string filename = "random_array.txt"; // 输出文件名
    // 从文件中读取随机数组
    std::vector<int> arr = std::move(readRandomArrayFromFile(filename));
    int n = arr.size();

    auto start = std::chrono::high_resolution_clock::now();
    // 排序
    // testSwapVector();
    // insertSort(arr, n);
    shellSort(arr, n);
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