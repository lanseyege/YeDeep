/*
 *  * Operator.h
 *   *
 *    *  Created on: 2019年7月10日
 *     *      Author: gesey
 *      */

#ifndef SRC_OPERATOR_H_
#define SRC_OPERATOR_H_
#include <vector>
#include <iostream>

class Operator{
    public:
        Operator();
        ~Operator();
        template<typename T>
            void add(std::vector<T> a, std::vector<T> b, std::vector<T>& c);
        template<typename T>
            void add_ac(std::vector<T> a, std::vector<T> b, std::vector<T>& c);
        template<typename T>
            void add_mul_ac(std::vector<T> a, std::vector<T> b, std::vector<T>& c);
        template<typename T>
            void sub(std::vector<T> a, std::vector<T> b, std::vector<T>& c);
        template<typename T>
            void mul(std::vector<T> a, std::vector<T> b, std::vector<T>& c);
        template<typename T>
            void div(std::vector<T> a, std::vector<T> b, std::vector<T>& c);
};

template<typename T>
void Operator::add(std::vector<T> a, std::vector<T> b, std::vector<T>& c){
    unsigned int lens1 = a.size();
    unsigned int lens2 = b.size();
    if (lens1 != lens2){
        std::cout<<"add: "<<lens1<<" "<<lens2<<std::endl;
        return ;
    }
    unsigned int lens3 = c.size();
    if (lens3 == 0){
        for (unsigned int i = 0; i < lens1; i++){
            c.push_back(0.0);
        }
    }
    for (unsigned int i = 0; i < lens1; i++){
        c[i] = a[i] + b[i];
    }
    return ;
}
/*
 * template<typename T>
 * std::vector<T> Operator::add_ac(std::vector<T> a, std::vector<T> b, std::vector<T> c){
 *  auto lens1 = a.size();
 *      auto lens2 = b.size();
 *          if (lens1 != lens2)
 *                  return NULL;
 *                      for (auto i = 0; i < lens1; i++){
 *                              c[i] += a[i] + b[i];
 *                                  }
 *                                      return c;
 *                                      }*/
template<typename T>
void Operator::add_ac(std::vector<T> a, std::vector<T> b, std::vector<T>& c){
    unsigned int lens1 = a.size();
    unsigned int lens2 = b.size();
    if (lens1 != lens2){
        std::cout<<"add_ac: "<<lens1<<" "<<lens2<<std::endl;
        return ;
    }
    unsigned int lens3 = c.size();
    std::cout<<"lens3: "<<std::endl;
    if (lens3 == 0){
        for (unsigned int i = 0; i < lens1; i++){
            c.push_back(0.0);
        }
    }
    for (unsigned int i = 0; i < lens1; i++){
        c[i] += a[i] + b[i];
    }
    return ;
}
template<typename T>
void Operator::add_mul_ac(std::vector<T> a, std::vector<T> b, std::vector<T>& c){
    unsigned int lens1 = a.size();
    unsigned int lens2 = b.size();
    if (lens1 != lens2){
        std::cout<<"add_mul_ac: "<<lens1<<" "<<lens2<<std::endl;
        return ;
    }
    unsigned int lens3 = c.size();
    std::cout<<"lens3: "<<lens3<<std::endl;
    if (lens3 == 0){
        for (unsigned int i = 0; i < lens1; i++){
            c.push_back(0.0);
        }
    }
    for (unsigned int i = 0; i < lens1; i++){
        c[i] += a[i] * b[i];
    }
    return ;
}
template<typename T>
void Operator::sub(std::vector<T> a, std::vector<T> b, std::vector<T>& c){
    unsigned int lens1 = a.size();
    unsigned int lens2 = b.size();
    if (lens1 != lens2){
        std::cout<<"sub: "<<lens1<<" "<<lens2<<std::endl;
        return ;
    }
    unsigned int lens3 = c.size();
    if (lens3 == 0){
        for (unsigned int i = 0; i < lens1; i++){
            c.push_back(0.0);
        }
    }
    for (unsigned int i = 0; i < lens1; i++){
        c[i] = a[i] - b[i];
    }
    return ;
}

template<typename T>
void Operator::mul(std::vector<T> a, std::vector<T> b, std::vector<T>& c){
    unsigned int lens1 = a.size();
    unsigned int lens2 = b.size();
    if (lens1 != lens2){
        std::cout<<"mul: "<<lens1<<" "<<lens2<<std::endl;
        return ;
    }
    unsigned int lens3 = c.size();
    if (lens3 == 0){
        for (unsigned int i = 0; i < lens1; i++){
            c.push_back(0.0);
        }
    }
    for (unsigned int i = 0; i < lens1; i++){
        c[i] = a[i] * b[i];
    }
    return ;
}

template<typename T>
void Operator::div(std::vector<T> a, std::vector<T> b, std::vector<T>& c){
    unsigned int lens1 = a.size();
    unsigned int lens2 = b.size();
    if (lens1 != lens2){
        std::cout<<"div: "<<lens1<<" "<<lens2<<std::endl;
        return ;
    }
    unsigned int lens3 = c.size();
    if (lens3 == 0){
        for (unsigned int i = 0; i < lens1; i++){
            c.push_back(0.0);
        }
    }
    for (unsigned int i = 0; i < lens1; i++){
        c[i] = a[i] / b[i];
    }
    return ;
}


#endif /* SRC_OPERATOR_H_ */

