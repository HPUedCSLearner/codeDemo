#include <iostream>

using std::cout;
using std::endl;

//没有函数的开销，效率相对比较高
#define multiply(x, y) ((x) *(y))

//函数调用是有开销的

//内联函数特点：遇到函数调用的时候，直接用函数体里面的内容去替换
inline 
int add(int x, int y)
{
    return x + y;
}

int main(int argc, char **argv)
{
    int a = 3, b = 4;
    cout << "multiply(a, b) = " << multiply(a, b) << endl;//形式类似函数
    cout << "multiply(3 + 4, 5 + 6) = " << multiply(3 + 4, 5 + 6) << endl;//3 + 4 * 5 + 6
    cout << "add(a, b) = " << add(a, b) << endl;// a + b
    return 0;
}

