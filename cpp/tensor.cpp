#pragma once
#include "root.cpp"

template <typename T, int dim> struct Tensor {
    // T* data;
	vector<T> data;
	int size;
    std::array<int, dim> shape;
	std::array<int, dim> strides;

    Tensor() : data{}, size{}, shape{}, strides{} {}

    Tensor(std::array<int, dim> shape, const T& t = T{}) : shape{shape} {
        strides[dim - 1] = 1;
        for (int i = dim - 1; i > 0; i--)
			strides[i-1] = strides[i] * shape[i];
        size = strides[0] * shape[0];
        data = vector<T>(size, t);
    }

    Tensor(Tensor const &t) : data(t.data), size{t.size}, shape{t.shape}, strides{t.strides} {}

    // ~Tensor() { delete[] data; }
    
    T& operator[] (std::array<int, dim> &&idx) {
        auto pos = 0;
        for (int i = 0; i < dim; i++)
            pos += strides[i] * idx[i];
        return data[pos];
    }

    T& operator[] (int i) {
        return data[i];
    }
};

TT, int dim> istream& operator >> (istream &s, Tensor<T, dim> &t) {
    for (auto &i : t.data)
        s >> i;

    return s;
}