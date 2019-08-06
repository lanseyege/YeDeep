/*
 *Tensor.cpp
 * */

#include "Tensor.h"

Operator opt;

Tensor::Tensor(){ index = 0; }

Tensor::~Tensor(){ }

Tensor::Tensor(std::vector<float> other_value){
    index = 0;
    Tensor::value = other_value;
}

void Tensor::set_value(std::vector<float> other_value){
    Tensor::value = other_value;
}

void Tensor::set_name(std::string name){
    Tensor::name = name;
}

std::vector<float>& Tensor::grad() {
    if(this->grad_value.size() != 0){
        return this->grad_value;
    }
    for(std::size_t i = 0; i < this->children.size(); ++i) {
        Tensor* child = this->children[i];
        opt.add_mul_ac(this->weight[i], child->grad(), this->grad_value);
    }
    this->has_grad = true;
    return this->grad_value;
}

Tensor& Tensor::operator+(Tensor& other){
    Tensor* result = (new Tensor()); result->set_name("temp");
    unsigned int lens = other.value.size();
    std::vector<float> grad_value_(lens);
    std::fill(grad_value_.begin(), grad_value_.end(), 1.0);
    std::fill(result->value.begin(), result->value.end(), 0.0);

    std::cout<<"+1"<<std::endl;
    opt.add(this->value, other.value, result->value); // @suppress("Invalid arguments")
    std::cout<<"+2"<<std::endl;
    other.children.push_back(result);
    other.weight.push_back(grad_value_);
    this->children.push_back(result);
    this->weight.push_back(grad_value_);

    std::cout<<"+3"<<std::endl;
    std::cout<<grad_value.size()<<std::endl;
    return *result;
}

Tensor& Tensor::operator-(Tensor& other){
    Tensor& result = *(new Tensor());
    result.set_name("res");
    unsigned int lens = other.value.size();
    std::vector<float> grad_value_(lens), grad_value__(lens);
    std::fill(grad_value_.begin(), grad_value_.end(), 1.0);
    std::fill(grad_value__.begin(), grad_value__.end(), -1.0);
    std::fill(result.value.begin(), result.value.end(), 0.0);

    opt.sub(this->value, other.value, result.value);
    other.children.push_back(&result);
    other.weight.push_back(grad_value__);
    this->children.push_back(&result);
    this->weight.push_back(grad_value_ );

    return result;
}

Tensor& Tensor::operator*(Tensor& other){
    Tensor& result = *(new Tensor());
    std::fill(result.value.begin(), result.value.end(), 0.0);

    opt.mul(this->value, other.value, result.value);

    other.children.push_back(&result);
    other.weight.push_back(this->value);
    this->children.push_back(&result);
    this->weight.push_back(other.value);

    return result;
}

Tensor& Tensor::operator/(Tensor& other){
    Tensor& result = *(new Tensor());
    unsigned int lens = other.value.size();
    std::vector<float> a_(lens), b_(lens);
    for(unsigned int i = 0; i < lens; i++){
        b_.push_back(1.0 / other.value[i]);
        a_.push_back(-1.0 / other.value[i]*result.value[i]);
    }
    std::fill(result.value.begin(), result.value.end(), 0.0);

    opt.div(this->value, other.value, result.value);

    other.children.push_back(&result);
    other.weight.push_back(a_);
    this->children.push_back(&result);
    this->weight.push_back(b_);
    return result;
}


