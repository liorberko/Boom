#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>


template<typename T>
class array
{
private:
    T* data;
    int max_size;
public:
  
    array(int size) : data(new T[size]), max_size(size) { }
    array() : data(nullptr), max_size(0) { }

    array(const array& arr) : max_size(arr.size())
    {
        T* new_data = new T[arr.size()];
        try
        {
            for (int i =0 ; i < arr.size(); i++)
            {
                new_data[i] = arr[i];
            }
        } catch (...) {
            delete[] new_data;
            throw;
        }
        data = new_data;
    }
    
    ~array()
    {
        if (data != nullptr)
        {
            delete[] data;
        }
    }

    array& operator=(const array& target_arr)
    {
        if (this == &target_arr)
        {
            return *this;
        }
        T* temp_data = new T[target_arr.size()];
        try 
        {
            for(int i = 0 ; i < target_arr.size(); i++)
            {
                temp_data[i] = target_arr[i];
            }
        } catch (...) {
            delete[] temp_data;
            throw;
        }

        delete[] data;
        data = temp_data;
        max_size = target_arr.max_size;
        return *this;
    }

    int size() const noexcept
    {
        return max_size;
    }

    T& operator[](int index)
    {
        return data[index];
    }
    const T& operator[](int index) const
    {
        return data[index];
    }
};
#endif