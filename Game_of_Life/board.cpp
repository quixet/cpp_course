// board.cpp
// GAME OF LIFE
// Class of 'boards' for Conway's game of life

#pragma once
#include "board.h"          // Including our header with the class declaration - read this first

board::board(int hei, int wid): _width(wid), _height(hei) 
// Contructor
{
    bool** ary = new bool*[_height];        // Pointer to an array of pointers to bools (Phew!)
    for(int i = 0; i < _height; ++i){
        ary[i] = new bool[_width];          // Pointer to an array of bools
        *(ary[i]) = 0;
        }
    _grid = ary;
    _pop = 0;
};


void board::randomize(int start){
    
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_real_distribution<double> dist(0.0,1.0);
    
    _pop = 0;
    
    while (_pop < start){
        int col_num = floor(dist(generator) * _width);
        int row_num = floor(dist(generator) * _height);
        if (*(*(_grid+row_num)+col_num) == 0){
            *(*(_grid+row_num)+col_num) = 1;
            _pop++;
        }
    }
};

void board::step(){
    
    for (int i = 0; i < _height; i++){      // row count
        for (int j = 0; j < _width; j++){   // col count
        
 //           std::cout << "row " << i << " col " << j << std::endl;
        
            int toprow, botrow, leftcol, rightcol;  // indices
            
            j == 0           ? leftcol = _width-1    : leftcol = j-1;   // Left edge
            j == _width - 1  ? rightcol = 0          : rightcol = j+1;  // Right edge
            
            i == 0           ? toprow = _height-1    : toprow = i-1;    // Top edge
            i == _height -1  ? botrow = 0            : botrow = i+1;    // Bottom edge
            
            
            int neicount = 0;
            
            if (*(*(_grid + toprow) + leftcol) == 1) {neicount++;}// std::cout<<"TL"<<std::endl;}
            if (*(*(_grid + botrow) + leftcol) == 1) {neicount++;}// std::cout<<"BL"<<std::endl;}
            if (*(*(_grid + toprow) + rightcol) == 1) {neicount++;}// std::cout<<"TR"<<std::endl;}
            if (*(*(_grid + botrow) + rightcol) == 1) {neicount++;}// std::cout<<"BR"<<std::endl;}
            if (*(*(_grid + toprow) + j) == 1) {neicount++;}// std::cout<<"T"<<std::endl;}
            if (*(*(_grid + botrow) + j) == 1) {neicount++;}// std::cout<<"B"<<std::endl;}
            if (*(*(_grid + i) + leftcol) == 1) {neicount++;}// std::cout<<"L"<<std::endl;}
            if (*(*(_grid + i) + rightcol) == 1) {neicount++;}// std::cout<<"R"<<std::endl;}
            
            //report
            
            
            if (*(*(_grid + i) + j) == 1){
                if (neicount < 2 || neicount > 3){ 
                    *(*(_grid + i) + j) = 0;
                    _pop--;
    //                std::cout << "neicount " << neicount << ", dies" << std::endl;
                    }
    //            else std::cout << "neicount " << neicount << ", survives" << std::endl;
                }
            else{
                if(neicount == 3){ 
                    *(*(_grid + i) + j) = 1;
                    _pop++;
      //              std::cout << "neicount " << neicount << ", sprouts" << std::endl;
                    }
                }
            }
        }
    };

void board::print(){
     for (int i = 0; i < _height; i++){
         for (int j = 0; j < _width; j++){
            *(*(_grid+i)+j) == 1 ? std::cout << "O" : std::cout << "_";
             }
            std::cout << std::endl;
         }
    std::cout << std::endl << std::endl;
    };
    
void board::evolve(int gens){
    
    std::cout << "pop " << _pop << std::endl;
    this->print();
    
    for (int gen = 0; gen < gens; gen++){
        if (_pop == 0) return;
        this->step();
        std::cout << "pop " << _pop << std::endl;
        this->print();
        sleep(20);
        }
    }