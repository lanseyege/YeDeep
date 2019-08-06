/*
 *Tensor.h

 * */

#ifndef SRC_TENSOR_H_
#define SRC_TENSOR_H_

#include <vector>
#include <iostream>
#include <string>
#include "Operator.h"

class Tensor{
    public:
        int index = 0;
        std::vector<Tensor*> children;
        //
        std::vector<float> value;
        std::vector<std::vector<float>> weight;
        std::vector<float> grad_value;

        bool require_grad = false;
        bool has_grad = false;
        float zeros = 1e-8;
        std::string name;

    public:
        Tensor();
        ~Tensor();
        Tensor(std::vector<float> other_value);

        void set_value(std::vector<float> other_value);
        void set_name(std::string name);
        std::vector<float>& grad();

        Tensor& operator+(Tensor& other);
        Tensor& operator-(Tensor& other);
        Tensor& operator*(Tensor& other);
        Tensor& operator/(Tensor& other);

};

#endif /* SRC_TENSOR_H_ */

