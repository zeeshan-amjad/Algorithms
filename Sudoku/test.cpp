#include <iostream>
#include <vector>
#include "sudoku.h"
using namespace std;

const int dimension = 9;

int main () {
	cout << "FORMAT: Enter 0 for empty cells\n\n";
    vector <vector <int> > matrix (dimension, vector <int> (dimension, 0));
    cout << "Number of puzzles to be solved: ";
    int t;
    cin >> t;
    while (t--) {
    	cout << "\nEnter the matrix:\n";
        for (int i = 0; i < dimension; ++i)
            for (int j = 0; j < dimension; ++j)
                cin >> matrix[i][j];
        Sudoku S (matrix);
        matrix = S.getSolution ();
        cout << "\nSolution:\n";
        for (int i = 0; i < dimension; ++i) {
            for (int j = 0; j < dimension; ++j)
                cout << matrix[i][j] << ' ';
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;
}