#include "iter.hpp"
#include <iostream>
#include <string>

template<typename T>
void printElement(const T& element)
{
    std::cout << element << " ";
}

template<typename T>
void doubleElement(T& element)
{
    element *= 2;
}

template<typename T>
void incrementElement(T& element)
{
    element++;
}

void printInt(int n)
{
    std::cout << "[" << n << "] ";
}

void printString(const std::string& s)
{
    std::cout << "\"" << s << "\" ";
}

class TestFunctor
{
public:
    template<typename T>
    void operator()(const T& element) const
    {
        std::cout << "Functor: " << element << " ";
    }
};

int main()
{
    std::cout << "=== Testing iter with integers ===" << std::endl;
    
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intSize = sizeof(intArray) / sizeof(intArray[0]);
    
    std::cout << "Original array: ";
    iter(intArray, intSize, printElement<int>);
    std::cout << std::endl;
    
    std::cout << "Using regular function: ";
    iter(intArray, intSize, printInt);
    std::cout << std::endl;
    
    iter(intArray, intSize, doubleElement<int>);
    std::cout << "After doubling: ";
    iter(intArray, intSize, printElement<int>);
    std::cout << std::endl;
    
    iter(intArray, intSize, incrementElement<int>);
    std::cout << "After incrementing: ";
    iter(intArray, intSize, printElement<int>);
    std::cout << std::endl;
    
    std::cout << std::endl << "=== Testing iter with strings ===" << std::endl;
    
    std::string stringArray[] = {"Hello", "World", "Template", "Programming"};
    size_t stringSize = sizeof(stringArray) / sizeof(stringArray[0]);
    
    std::cout << "String array: ";
    iter(stringArray, stringSize, printElement<std::string>);
    std::cout << std::endl;
    
    std::cout << "Using regular function: ";
    iter(stringArray, stringSize, printString);
    std::cout << std::endl;
    
    std::cout << std::endl << "=== Testing iter with const array ===" << std::endl;
    
    const double constArray[] = {3.14, 2.71, 1.41, 1.73};
    size_t constSize = sizeof(constArray) / sizeof(constArray[0]);
    
    std::cout << "Const double array: ";
    iter(constArray, constSize, printElement<double>);
    std::cout << std::endl;
    
    std::cout << std::endl << "=== Testing iter with functor ===" << std::endl;
    
    TestFunctor functor;
    std::cout << "Using functor with integers: ";
    iter(intArray, intSize, functor);
    std::cout << std::endl;
    
    std::cout << "Using functor with strings: ";
    iter(stringArray, stringSize, functor);
    std::cout << std::endl;
    
    std::cout << std::endl << "=== Testing edge cases ===" << std::endl;
    
    std::cout << "Testing with nullptr (should not crash): ";
    iter(static_cast<int*>(0), 5, printElement<int>);
    std::cout << "OK" << std::endl;
    
    std::cout << "Testing with zero length: ";
    iter(intArray, 0, printElement<int>);
    std::cout << "OK" << std::endl;
    
    return 0;
}
