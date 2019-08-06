#ifndef TEST1_CLASS_H
#define TEST1_CLASS_H

#include <iostream>
#include <iomanip>

#include "mkl.h"
#include "mkl_lapacke.h"

class Matrix{
public:
    Matrix(std::size_t rVal);
    Matrix(std::size_t rVal, std::size_t cVal);
    Matrix(const Matrix& rhs);
    ~Matrix();
    void resize(std::size_t rVal, std::size_t cVal);
    std::size_t rows() const;
    std::size_t cols() const;
    float* get_data() const;
    void inverse();

    void init(); 
    void init(float a); 
    
    Matrix& operator=(const Matrix& rhs);
    Matrix& operator*=(float scala);
    Matrix& operator+=(const Matrix& other);
    Matrix& operator-=(const Matrix& other);
    Matrix operator-() const;
    
    Matrix& operator*(const Matrix& other);
    Matrix& operator-(const Matrix& other);
    Matrix& operator+(const Matrix& other);
    Matrix& operator/(const Matrix& other);

private:
    std::size_t _Rows;
    std::size_t _Cols;
    float* _Data;
};


#endif
