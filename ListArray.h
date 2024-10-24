#include <ostream>
#include "List.h"
#include <stdexcept>

template <typename T>
class ListArray : public List<T> {
private:
    T* arr;  
    int max; 
    int n;   
    static const int MINSIZE = 2;   

  
    void resize(int new_size) {
        if (new_size < MINSIZE) new_size = MINSIZE;
        T* new_arr = new T[new_size];
        
        
        for (int i = 0; i < n; ++i) {
            new_arr[i] = arr[i];
        }

        delete[] arr;
        arr = new_arr;
        max = new_size;
    }

public:
    
    ListArray() : arr(new T[MINSIZE]), max(MINSIZE), n(0) {}

    
    ~ListArray() {
        delete[] arr;
    }

    
    T operator[](int pos) const {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Index out of range");
        }
        return arr[pos];
    }

    
    friend std::ostream& operator<<(std::ostream& out, const ListArray<T>& list) {
        out << "[";
        for (int i = 0; i < list.n; ++i) {
            out << list.arr[i];
            if (i < list.n - 1) {
                out << ", ";
            }
        }
        out << "]";
        return out;
    }

    
    void insert(int pos, const T& element) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Index out of range");
        }
        if (n == max) {
            resize(max * 2); // Redimensionar si el array está lleno.
        }
        for (int i = n; i > pos; --i) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = element;
        ++n;
    }

    
    void remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Index out of range");
        }
        for (int i = pos; i < n - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        --n;

        
        if (n < max / 4 && max / 2 >= MINSIZE) {
            resize(max / 2);
        }
    }

    
    int size() const override {
        return n;
    }

    
    void append(const T& element) override {
        if (n == max) {
            resize(max * 2);
        }
        arr[n++] = element;
    }

    
    void prepend(const T& element) override {
        insert(0, element);
    }
};



