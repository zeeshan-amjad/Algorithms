#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include <vector>
using namespace std;

class Sudoku {
public:
    Sudoku (const vector<vector <int>> &);

    //validates the sudoku matrix state
    bool valid (int, int);

    //check if k can be placed at coordinates (x,y)
    bool canPlace (int, int, int); 

    //return solution
    vector <vector <int>> getSolution (); 
    
private:
    vector <vector <int>> matrix;
};

#endif