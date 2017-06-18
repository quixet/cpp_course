// main.cpp
// GAME OF LIFE
// Source file for an implementation of Conway's Game of Life
// Illustrating the use of classes, pointer arithmetic, random engines and other basic concepts


#include <stdio.h>
#include <vector>       // Not a vector like in physics! A std library container - google it for details
#include <iostream>     // Input/output
#include <string>
#include "board.cpp"    // Source file for the class we'll be using



// Some error messages for use in the throw/catch error handling
std::vector<std::string> MyExceptions = {"Invalid arguments. Correct format: <rows> <columns> <initial # of alive cells> <generations>", "ERROR: initial population greater than available squares."};



int main(int argc, char **argv)
// The 'main' function - needed for C++ programs; central function from which all others are called
// Arguments are parameters passed to the program from Terminal at runtime
//-------argc - number of arguments, including the name of the program
//-------argv - argument vector - holds all the arguments; at least argv[0] will be the name of the program
{
    int rows, cols, start, gens;
    
    try{                        // Error handling throw/catch structure
        if (argc != 5){
            throw 0;
        }
        rows = atoi(argv[1]);   // atoi typecasts (changes) a char to an int - necessary!
        cols = atoi(argv[2]);
        start = atoi(argv[3]);
        gens = atoi(argv[4]);
        
        if (start > rows*cols) throw 1; // Can't overfill 
        
        }
    catch(int ex){
        std::cout << MyExceptions[ex] << std::endl;
        exit(EXIT_FAILURE);
        }
    
    // Creating an instance of our board class
    board game(rows,cols);
    
    // Initial values
    game.randomize(start);
    
    // Playing the game
    game.evolve(gens);
}