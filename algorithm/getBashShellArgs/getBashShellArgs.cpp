#include <iostream>
#include <vector>
#include <string>

int main(int argc, char* argv[]) {
    // 将命令行参数存储到向量中
    std::vector<std::string> args;
    for (int i = 0; i < argc; ++i) {
        args.push_back(argv[i]);
    }

    // 打印命令行参数的个数
    std::cout << "Number of command line arguments: " << args.size() << std::endl;

    // 打印命令行参数的值
    std::cout << "Command line arguments:" << std::endl;
    for (int i = 0; i < args.size(); ++i) {
        std::cout << "Argument " << i << ": " << args[i] << std::endl;
    }

    return 0;
}
