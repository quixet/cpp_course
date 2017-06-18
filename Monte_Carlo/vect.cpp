#pragma once
#include "vect.h"



vect2::vect2(){
    
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_real_distribution<double> dist(0.0,1.0);
    
    _x = dist(generator);
    _y = dist(generator);
    
    }

vect2 vect2::operator+(const vect2& second){
    
    vect2 newvec(_x + second._x, _y + second._y);
    return newvec;
    }
    
void vect2::print(){
    std::cout << "(" << _x << "," << _y << ")" << std::endl;
    
    }

