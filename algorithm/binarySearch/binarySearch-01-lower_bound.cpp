#include <iostream>
#include <vector>
#include <sstream>

// 二分查找函数
int binarySearch(const std::vector<int>& array, int target) {
    int n = array.size();
    // int l = 0, r = n - 1;
    int l = 0, r = n; // std::lower_bound()
    int mid;

    while(l<r) {
        mid = l + (r - l) / 2;
        if(array[mid] >= target) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    // Debug
    std::cout << "r, l:" << r << " " << l << std::endl;

    // 程序结束，l == r
    return l;
}

int main(int argc, char* argv[]) {
    // 参数判断
    if(argc != 2) {
        std::cout << "Error, need a parameter" << std::endl;
        return -1;
    }

    std::stringstream ss;
    ss << argv[1];


    std::vector<int> array = {1, 3, 5, 7, 9, 11, 11, 15, 17, 19}; // 有序数组
    int target = 13; // 要查找的目标值

    ss >> target;

    // 在数组中查找目标值
    int index = binarySearch(array, target);

    return 0;
}
