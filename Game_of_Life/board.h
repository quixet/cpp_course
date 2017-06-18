// board.h
// GAME OF LIFE
// Header for class of 'boards' for Conway's game of life

#pragma once
#include <array>
#include <random>
#include <stdlib.h>


class board
{
public:
    board(int,int);                         // Constructor
    ~board(){delete _grid;};                // Destructor - MUST delete object on the heap!
    
    // fetching
    int getW(){return _width;}
    int getH(){return _height;}
    int getval(int row, int col){ return *(*(_grid+row-1)+col-1);}
    
    // initialise randomly
    void randomize(int);
    
    // evolution
    void step();        // Applies Game rules to evolve board once
    void evolve(int);   // Steps and prints board for some number of iterations
    
    void print();       // Prints board
    
    
private:
    int _width;
    int _height;
    bool** _grid;           // Pointer to an array of pointers to bools on the heap
    int _pop;
    };
