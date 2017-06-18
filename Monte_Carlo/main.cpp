// main.cpp
// PI BY MONTE CARLO
// Calculating pi by generating random vectors
// Uses the vect class

#include <stdio.h>
#include <vect.cpp>
#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> myExceptions = {"Invalid input, please enter an integer.", "That would take too long."};

double calculatePi(int);

int main(int argc, char **argv)
{
    vect2 test;
    
    std::cout << "//////////////////////////////////////////" << std::endl;
    std::cout << "//                                      //" << std::endl;
    std::cout << "//          PI BY MONTE CARLO           //" << std::endl;
    std::cout << "//                                      //" << std::endl;
    std::cout << "//////////////////////////////////////////" << std::endl;
    
    std::cout << "20 iterations: " << calculatePi(20) << std::endl;
    std::cout << "50 iterations: " << calculatePi(50) << std::endl;
    std::cout << "100 iterations: " << calculatePi(100) << std::endl;
    std::cout << "1000 iterations: " << calculatePi(1000) << std::endl;
    std::cout << "10000 iterations: " << calculatePi(10000) << std::endl;
    
    std::cout << myExceptions[0] << std::endl;
    std::cout << myExceptions[1] << std::endl;
    
    int iterations;
    bool valid = false;
    while (!valid){
        try{
            valid = 1;
            std::cout << "Desired number of iterations: " << std::endl;
            std::cin >> iterations;
            
            if (std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
                throw 0;
            }
            else if (iterations > 10000000){
                throw 1;
            }
        }
        catch(int ex){ 
            std::cout << myExceptions[ex] << std::endl; 
            valid = 0;
            }
    }
    
    std::cout << iterations << " iterations: " << calculatePi(iterations) << std::endl;
    
};

double calculatePi(int iter){
    
    int count_in = 0;
    
    for (int i = 0; i < iter; i++){
        
        vect2 rando;
        
        if(rando.magnitude() <= 1.0) count_in++;
        
        }
    
    return 4.0 * count_in / iter;
    }
