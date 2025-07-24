#include "whatever.hpp"
#include <iostream>
#include <string>

int main()
{
    std::cout << "=== Testing swap function ===" << std::endl;
    
    int a = 2;
    int b = 3;
    
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
    
    std::string c = "chaine1";
    std::string d = "chaine2";
    
    std::cout << "Before swap: c = " << c << ", d = " << d << std::endl;
    ::swap(c, d);
    std::cout << "After swap: c = " << c << ", d = " << d << std::endl;
    
    std::cout << std::endl << "=== Testing min function ===" << std::endl;
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    
    std::cout << std::endl << "=== Testing max function ===" << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
    
    std::cout << std::endl << "=== Testing edge cases ===" << std::endl;
    
    int equal1 = 5;
    int equal2 = 5;
    
    std::cout << "min(5, 5) = " << ::min(equal1, equal2) << std::endl;
    std::cout << "max(5, 5) = " << ::max(equal1, equal2) << std::endl;
    
    float f1 = 3.14f;
    float f2 = 2.71f;
    
    std::cout << "min(3.14f, 2.71f) = " << ::min(f1, f2) << std::endl;
    std::cout << "max(3.14f, 2.71f) = " << ::max(f1, f2) << std::endl;
    
    return 0;
}
