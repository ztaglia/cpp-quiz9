#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    int* p = new int(42);
    std::cout << *p << std::endl;
    return 0;
}