const int dimension = 9;

class Sudoku {
    vector <vector <int> > matrix;

public:
    Sudoku (const vector <vector <int> > &m) : 
    matrix (dimension, vector <int> (dimension, 0)) {
        for (int i = 0; i < dimension; ++i)
            for (int j = 0; j < dimension; ++j)
                this->matrix[i][j] = m[i][j];
    }

    bool valid (int i, int j) {
        bool visited[10] = {};
        for (int k = 0; k < dimension; ++k) {
            if (visited[this->matrix[i][k]] and this->matrix[i][k] != 0) 
                return false;
            visited[this->matrix[i][k]] = true;
        }

        memset (visited, 0, sizeof (visited));
        for (int k = 0; k < dimension; ++k) {
            if (visited[this->matrix[k][j]] and this->matrix[k][j] != 0) 
                return false;
            visited[this->matrix[k][j]] = true;
        }
        
        memset (visited, 0, sizeof (visited));
        int x = (i / 3) * 3, y = (j / 3) * 3;
        for (int k = x; k < x + 3; ++k)
            for (int l = y; l < y + 3; ++l) {
                if (visited[this->matrix[k][l]] and this->matrix[k][l] != 0) 
                    return false;
                visited[this->matrix[k][l]] = true;
            }

        return true;
    }

    bool canPlace (int k, int x, int y) {
        this->matrix[x][y] = k;
        
        if (!valid (x, y)) {
            this->matrix[x][y] = 0;
            return false;
        }

        if (x == y and y == dimension - 1)
            return true;

        for (int i = 0; i < dimension; ++i)
            for (int j = 0; j < dimension; ++j)
                if (matrix[i][j] == 0) {
                    for (int k = 1; k <= 9; ++k) {
                            if (canPlace (k, i, j))
                                return true;
                            this->matrix[i][j] = 0;
                    }
                    return false;
                }
        return true;
    }

    //solve and return 
    vector <vector <int>> getSolution () {
        for (int i = 0; i < dimension; ++i)
            for (int j = 0; j < dimension; ++j)
                if (matrix[i][j] == 0) 
                    for (int k = 1; k <= 9; ++k)
                        if (canPlace (k, i, j)) 
                            return this->matrix;
        cerr << "Invalid Input!\nBroken Matrix:\n";
        return this->matrix;
    }
};
