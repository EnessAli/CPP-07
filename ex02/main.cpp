#include <iostream>
#include <Array.hpp>
#include <cstdlib>
#include <ctime>

#define MAX_VAL 750

class TestClass
{
private:
    int _value;

public:
    TestClass() : _value(0) {}
    TestClass(int value) : _value(value) {}
    TestClass(const TestClass& other) : _value(other._value) {}
    TestClass& operator=(const TestClass& other)
    {
        if (this != &other)
            _value = other._value;
        return *this;
    }
    
    int getValue() const { return _value; }
    void setValue(int value) { _value = value; }
};

std::ostream& operator<<(std::ostream& os, const TestClass& obj)
{
    os << obj.getValue();
    return os;
}

void testBasicFunctionality()
{
    std::cout << "=== Testing Basic Functionality ===" << std::endl;
    
    Array<int> empty;
    std::cout << "Empty array size: " << empty.size() << std::endl;
    
    Array<int> numbers(5);
    std::cout << "Numbers array size: " << numbers.size() << std::endl;
    std::cout << "Initial values: " << numbers << std::endl;
    
    for (unsigned int i = 0; i < numbers.size(); ++i)
    {
        numbers[i] = static_cast<int>(i * 10);
    }
    std::cout << "After assignment: " << numbers << std::endl;
    
    Array<int> copy(numbers);
    std::cout << "Copy: " << copy << std::endl;
    
    copy[0] = 999;
    std::cout << "After modifying copy[0]:" << std::endl;
    std::cout << "Original: " << numbers << std::endl;
    std::cout << "Copy: " << copy << std::endl;
    
    Array<int> assigned;
    assigned = numbers;
    std::cout << "Assigned: " << assigned << std::endl;
}

void testExceptionHandling()
{
    std::cout << std::endl << "=== Testing Exception Handling ===" << std::endl;
    
    Array<int> arr(3);
    
    try
    {
        arr[0] = 42;
        arr[1] = 84;
        arr[2] = 126;
        std::cout << "Valid access successful: " << arr << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }
    
    try
    {
        std::cout << "Trying to access arr[-2]..." << std::endl;
        arr[static_cast<std::size_t>(-2)] = 0;
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    
    try
    {
        std::cout << "Trying to access arr[3] (size is 3)..." << std::endl;
        arr[3] = 0;
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    
    try
    {
        Array<int> emptyArr;
        std::cout << "Trying to access empty array..." << std::endl;
        emptyArr[0] = 0;
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
}

void testWithCustomClass()
{
    std::cout << std::endl << "=== Testing with Custom Class ===" << std::endl;
    
    Array<TestClass> objects(3);
    std::cout << "Initial custom objects: " << objects << std::endl;
    
    for (unsigned int i = 0; i < objects.size(); ++i)
    {
        objects[i].setValue(static_cast<int>(i + 1) * 100);
    }
    std::cout << "After setting values: " << objects << std::endl;
    
    Array<TestClass> copyObjects(objects);
    copyObjects[1].setValue(555);
    std::cout << "Original after copy modification: " << objects << std::endl;
    std::cout << "Copy: " << copyObjects << std::endl;
}

void testOriginalMain()
{
    std::cout << std::endl << "=== Testing Original Main Logic ===" << std::endl;
    
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    std::srand(static_cast<unsigned int>(std::time(0)));
    
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = std::rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
    
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            delete[] mirror;
            return;
        }
    }
    std::cout << "Deep copy test passed!" << std::endl;
    
    try
    {
        numbers[static_cast<std::size_t>(-2)] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Negative index exception: " << e.what() << std::endl;
    }
    
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Out of bounds exception: " << e.what() << std::endl;
    }
    
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = std::rand();
    }
    
    delete[] mirror;
    std::cout << "Original main logic test completed successfully!" << std::endl;
}

int main()
{
    testBasicFunctionality();
    testExceptionHandling();
    testWithCustomClass();
    testOriginalMain();
    
    return 0;
}