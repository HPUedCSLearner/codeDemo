#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

std::vector<int> readRandomArrayFromFile(const std::string& filename);

void insertSort(vector<int>& arr, int n);
void selectSort(vector<int>& arr, int n);
void bubleSort(vector<int>& arr, int n);

int main() {
    std::string filename = "random_array.txt"; // 输出文件名
    // 从文件中读取随机数组
    std::vector<int> arr = std::move(readRandomArrayFromFile(filename));
    int n = arr.size();

    // 排序
    // sort(arr.begin(), arr.end());
    insertSort(arr, n);
    // selectSort(arr, n);
    // bubleSort(arr, n);

    // 查看排序结果
    for(const auto& a : arr) {
        cout << a << " ";
    } 
    cout << endl;


    return 0;
}

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

void bubleSort(vector<int>& arr, int n)
{
    for(int i = 0; i < n-1; ++i) {
        for(int j = 1; j < n-i; ++j) {
            if(arr[j-1] > arr[j]) swap(arr[j-1], arr[j]);
        }
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