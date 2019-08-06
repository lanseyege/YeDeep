#include "test1.h"

Matrix::Matrix(std::size_t rVal){
    _Rows = rVal;
    _Cols = _Rows;
    _Data = new float[_Rows * _Cols];
}

Matrix::Matrix(std::size_t rVal, std::size_t cVal){
    _Rows = rVal;
    _Cols = cVal;
    _Data = new float[_Rows * _Cols];
    /*
    for(std::size_t ix = 0; ix != _Rows * _Cols; ++ix){
        _Data[ix] = 1.0;
    }
    */
}

Matrix::Matrix(const Matrix& rhs){
    _Rows = rhs._Rows;
    _Cols = rhs._Cols;
    _Data = new float[_Rows * _Cols];
    /*
    for(std::size_t ix = 0; ix != _Rows * _Cols; ++ix){
        *(_Data + ix) = *(rhs._Data + ix);
    }*/
}

Matrix::~Matrix(){
    delete[] _Data;
}

void Matrix::resize(std::size_t rVal, std::size_t cVal){
    delete[] _Data;
    _Rows = rVal;
    _Cols = cVal;
    _Data = new float[_Rows * _Cols];
}

void Matrix::init(float a){
    std::size_t rows, cols;
    rows = this->_Rows;
    cols = this->_Cols;
    for(std::size_t i = 0; i < rows * cols; ++i){
        this->_Data[i] = a;
    }
}

void Matrix::init(){
    std::size_t rows, cols;
    rows = this->_Rows;
    cols = this->_Cols;
    for(std::size_t i = 0; i < rows * cols; ++i){
        this->_Data[i] = ((float) rand() / (RAND_MAX);
    }
}

std::size_t Matrix::rows() const{
    return _Rows;
}

std::size_t Matrix::cols() const{
    return _Cols;
}

float* Matrix::get_data() const{
    return this->_Data;
}

void Matrix::inverse(){
    int *ipiv = new int[_Rows * _Cols];
    LAPACKE_ssytrf(LAPACK_ROW_MAJOR, 'U', _Rows, _Data, _Rows, ipiv);
    LAPACKE_ssytri(LAPACK_ROW_MAJOR, 'U', _Rows, _Data, _Rows, ipiv);
    delete[] ipiv;
    for(std::size_t j = 0; j < _Cols; ++j){
        for(std::size_t i = j + 1; i < _Rows; ++i){
            _Data[i * _Cols + j] = _Data[j * _Cols + i];
        }
    }
}

Matrix& Matrix::operator=(const Matrix& rhs){
    resize(rhs._Rows, rhs._Cols);
    for(std::size_t ix = 0; ix != _Rows * _Cols; ++ix){
        *(_Data + ix) = *(rhs._Data + ix);
    }
    return *this;
}
    
Matrix& Matrix::operator*=(float scala){
    for(std::size_t ix = 0; ix != _Rows * _Cols; ++ix) {
        *(_Data + ix) *= scala;
    }
    return *this;
}

Matrix& Matrix::operator+=(const Matrix& other){
    for(std::size_t ix = 0; ix != _Rows * _Cols; ++ix){
        *(_Data + ix) += *(other._Data + ix);
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& other){
    for(std::size_t ix = 0; ix != _Rows * _Cols; ++ix){
        *(_Data + ix) -= *(other._Data + ix);
    }
    return *this;
}

Matrix Matrix::operator-() const{
    Matrix mat(_Rows, _Cols);
    for(std::size_t ix = 0; ix != _Rows * _Cols; ++ix){
        *(mat._Data + ix) = 0 - *(_Data + ix);
    }
    return mat;
}
/*
Matrix& Matrix::operator*(const Matrix& other, bool is_vec=true){
    rows1 = this->_Rows;
    cols1 = this->_Cols;
    rows2 = other._Rows;
    cols2 = other._Cols;
    Matrix mat(rows1, cols2);
    cblas_sgemv(CblasRowMajor, CblasNoTrans, rows1, cols1, alpha=1.0, this->_Data, rows1, other->_Data, 1, 0.0, y=mat, 1);
    return mat; 
}*/

Matrix& Matrix::operator*(const Matrix& other){
    std::size_t rows1 = this->_Rows;
    std::size_t cols1 = this->_Cols;
    std::size_t rows2 = other._Rows;
    std::size_t cols2 = other._Cols;
    std::cout<<rows1<<" "<<cols1<<" "<<rows2<<" "<<cols2<<std::endl;
    if (cols1 != rows2){
        std::cout<<"dimensions are not match"<<std::endl;
        return *(Matrix*)NULL;
    }
    std::cout<<"hehe1"<<std::endl;
    //Matrix& mat = *(new Matrix(rows1, cols2));
    Matrix* mat = (new Matrix(rows1, cols2));
    //Matrix mat(rows1, cols2);
    mat->init();
    std::cout<<mat->_Data[0]<<" "<<this->_Data[0]<<" "<<other._Data[0]<<std::endl;
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, rows1, cols2, cols1, 1.0, this->_Data, cols1, other._Data, cols2, 0.0, mat->_Data, cols2);
    return *mat; 
}

Matrix& Matrix::operator-(const Matrix& other){
    std::size_t rows1, cols1, rows2, cols2;
    rows1 = this->_Rows;
    cols1 = this->_Cols;
    rows2 = other._Rows;
    cols2 = other._Cols;
    if (rows1 != rows2 || cols1 != cols2) {
        std::cout<<" dimensions not match... "<<std::endl;
        return *(Matrix*)NULL;
    }
    Matrix* mat(rows1, cols2);
    mat->init();
    for(std::size_t ix = 0; ix != _Rows * _Cols; ++ix){
        mat->_Data[ix] = this->_Data[ix] - other._Data[ix];   
    }
    return *mat;
}

Matrix& Matrix::operator+(const Matrix& other){
    std::size_t rows1, cols1, rows2, cols2;
    rows1 = this->_Rows;
    cols1 = this->_Cols;
    rows2 = other._Rows;
    cols2 = other._Cols;
    if (rows1 != rows2 || cols1 != cols2) {
        std::cout<<" dimensions not match... "<<std::endl;
        return *(Matrix*)NULL;
    }
    Matrix* mat(rows1, cols2);
    mat->init();
    for(std::size_t ix = 0; ix != _Rows * _Cols; ++ix) {
        mat->_Data[ix] = this->_Data[ix] + other._Data[ix];   
    }
    return *mat;
}

Matrix& Matrix::operator/(const Matrix& other){
    std::size_t rows1, cols1, rows2, cols2;
    rows1 = this->_Rows;
    cols1 = this->_Cols;
    rows2 = other._Rows;
    cols2 = other._Cols;
    if (rows1 != rows2 || cols1 != cols2) {
        std::cout<<" dimensions not match... "<<std::endl;
        return *(Matrix*)NULL;
    }
    Matrix* mat(rows1, cols2);
    mat->init();
    for(std::size_t ix = 0; ix != _Rows * _Cols; ++ix) {
        mat->_Data[ix] = this->_Data[ix] / other._Data[ix];   
    }
    return *mat;
}

