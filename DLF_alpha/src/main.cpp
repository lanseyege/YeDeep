/*
 *  * main.cpp
 *   *
 *    *  Created on: 2019年7月15日
 *     *      Author: gesey
 *      */

#include "Tensor.h"
#include<iostream>
using namespace std;

int main(){
    int N = 10;
    std::vector<float> t1, t2;
    std::vector<float> Ngrad;
    float k;
    for(int i = 0; i < N; i++){
        k = ((double) rand() / (RAND_MAX)) ;
        t1.push_back(k);
        k = ((double) rand() / (RAND_MAX)) + 1;
        t2.push_back(k);
        Ngrad.push_back(1.0);
    }
    cout<<"a: ";
    for (int i = 0; i < N; i++){
        cout << t1[i] <<" ";
    }
    cout <<endl;
    cout <<"b: ";
    for (int i = 0; i < N; i++){
        cout << t2[i] <<" ";
    }
    cout <<endl;

    cout<<"grad3"<<endl;
    Tensor a, b;
    a.set_value(t1);a.set_name("a");
    b.set_value(t2);b.set_name("b");
    cout<<"grad4 "<<a.value.size()<<endl;
    //Tensor& c = (a + (b - (a * b)));
    //Tensor d = a / b;
    //Tensor e = a * b;
    //Tensor c = d - e;
    Tensor& c = a + b;
    cout<<c.index<<endl;
    cout<<c.name<<endl;
    c.set_name("res2");
    cout <<"c: ";
    for (int i = 0; i < N; i++){
        cout << c.value[i] << " ";
    }
    cout <<endl;
    c.grad_value = Ngrad;
    c.has_grad = true;
    cout<<c.grad()[0]<<endl;
    cout<<"grad1"<<endl;
    vector<float> a_grad = a.grad();
    cout<<b.grad_value.size()<<endl;
    vector<float> b_grad = b.grad();
    cout<<"a grad ";
    for(int i = 0; i < N; i++){
        cout<<a_grad[i]<<" ";
    }
    cout<<endl;
    cout<<b_grad.size()<<endl;
    cout<<"b grad ";
    for(int i = 0; i < N; i++){
        cout<<b_grad[i]<<" ";
    }
    cout<<endl;
}

