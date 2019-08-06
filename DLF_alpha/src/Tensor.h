/*
 *Tensor.h

 * */

#ifndef SRC_TENSOR_H_
#define SRC_TENSOR_H_

#include <vector>
#include <iostream>
#include <string>

#include "Operator.h"
#include "Matrix.h"

class Tensor{
    public:
        int index = 0;
        std::vector<Tensor*> children;
        //
        //std::vector<float> value;
        Matrix value;
        std::vector<Matrix*> weight;
        //Matrix weight;
        //std::vector<float> grad_value;
        Matrix grad_value;

        bool require_grad = false;
        bool has_grad = false;
        float zeros = 1e-8;
        std::string name;

    public:
        Tensor();
        ~Tensor();
        Tensor(Matrix& other_value);

        void set_value(Matrix other_value);
        void set_name(std::string name);
        Matrix& grad();

        Tensor& operator+(Tensor& other);
        Tensor& operator-(Tensor& other);
        Tensor& operator*(Tensor& other);
        Tensor& operator/(Tensor& other);

};

#endif /* SRC_TENSOR_H_ */

