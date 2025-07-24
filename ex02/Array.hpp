#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <cstddef>

template<typename T>
class Array
{
private:
    T*          _array;
    std::size_t _size;

public:
    Array() : _array(0), _size(0) {}
    
    Array(unsigned int n) : _array(0), _size(n)
    {
        if (n > 0)
        {
            _array = new T[n];
            for (std::size_t i = 0; i < _size; ++i)
            {
                _array[i] = T();
            }
        }
    }
    
    Array(const Array& other) : _array(0), _size(other._size)
    {
        if (_size > 0)
        {
            _array = new T[_size];
            for (std::size_t i = 0; i < _size; ++i)
            {
                _array[i] = other._array[i];
            }
        }
    }
    
    Array& operator=(const Array& other)
    {
        if (this != &other)
        {
            delete[] _array;
            
            _size = other._size;
            if (_size > 0)
            {
                _array = new T[_size];
                for (std::size_t i = 0; i < _size; ++i)
                {
                    _array[i] = other._array[i];
                }
            }
            else
            {
                _array = 0;
            }
        }
        return *this;
    }
    
    ~Array()
    {
        delete[] _array;
    }
    
    T& operator[](std::size_t index)
    {
        if (index >= _size)
        {
            throw std::out_of_range("Array index out of bounds");
        }
        return _array[index];
    }
    
    const T& operator[](std::size_t index) const
    {
        if (index >= _size)
        {
            throw std::out_of_range("Array index out of bounds");
        }
        return _array[index];
    }
    
    std::size_t size() const
    {
        return _size;
    }
};

#include <iostream>

template<typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr)
{
    os << "[";
    for (std::size_t i = 0; i < arr.size(); ++i)
    {
        os << arr[i];
        if (i < arr.size() - 1)
            os << ", ";
    }
    os << "]";
    return os;
}

#endif
