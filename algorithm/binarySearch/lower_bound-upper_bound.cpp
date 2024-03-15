#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 2, 4, 5, 5, 7, 8, 9};

    // 使用 lower_bound 查找第一个大于或等于 2 的元素
    auto lower = std::lower_bound(vec.begin(), vec.end(), 2);
    std::cout << "Lower Bound: " << *lower << std::endl;
    std::cout << "Lower Bound Idx: " << lower - vec.begin() << std::endl;

    // 使用 upper_bound 查找第一个大于 3 的元素
    auto upper = std::upper_bound(vec.begin(), vec.end(), 2);
    std::cout << "Upper Bound: " << *upper << std::endl;
    std::cout << "Upper Bound Idx: " << upper - vec.begin() << std::endl;


    return 0;
}