#pragma once
#include <iostream>
#include <cmath>
#include <random>

class vect                              // Abstract parent class
{
public:
    vect(){};
    ~vect(){};
    
    virtual double magnitude() = 0;     // Pure virtual function
    
    virtual void print(){};             // Virtual function
    
private:
};


class vect2 : public vect               // Derived class
{
public:
    vect2();                            // vector with random components between 0 and 1
    
    vect2(double x, double y) : vect(){ // vector with desired components
        _x = x;
        _y = y;
        }

    double magnitude(){return sqrt(_x*_x + _y*_y);}
    void print();
    
    vect2 operator+(const vect2&);      // Overloaded operator
    
    
private:
    double _x, _y;
    };

