#include <iostream>
#include <utility>
#include <cstring>



class Vector
{
private:
    int size;
    int capacity;
    public:
    int* arr;

    Vector(): size{0},capacity{0}{};
    Vector(int s = 0,int c = 10)
        :size{s},capacity{c},arr{new int[c]}{}
    ~Vector()
    {
        delete [] arr;
    }
     Vector(const Vector &other)
        :size{other.size},capacity{other.capacity}
    {
        arr = new int[other.capacity];
        std::memcpy(arr, other.arr, size * sizeof(int));
    }
    Vector(Vector&& other) noexcept
        :size{other.size},capacity{other.capacity},arr{other.arr}
    {
        other.size = 0;
        other.capacity = 0;
        other.arr = nullptr;
    }
     Vector &operator=(const Vector &other)
        {
            if (this != &other)
            {
                delete[] arr;

                size = other.size;
                capacity = other.capacity;
                arr = new int[capacity];
                std::memcpy(arr, other.arr, size * sizeof(int));
            }
            return *this;
        }

    Vector& operator = (Vector&& other) noexcept
    {
        if(this != &other)
        {
            delete [] arr;
            arr = other.arr;
            other.arr = nullptr;
            size = other.size;
            capacity = other.capacity;
            other.size = 0;
            other.capacity = 0;
        }

        return *this;
    }

void push_back(int val) {
        if (capacity == size) {
            capacity *= 2;
            int* tmp = arr;
            arr = new int[capacity];
            std::memcpy(arr, tmp, size * sizeof(int));
            delete[] tmp;
        }
        arr[size] = val;
        size++;
    }
};

int main()
{
    Vector vec(0,1);
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    Vector vec2 = vec;
     vec2 = vec;

    for (size_t i = 0; i < 3; i++)
    {
         std::cout << vec2.arr[i] << std::endl;
    }
    
  
    return 0;
}