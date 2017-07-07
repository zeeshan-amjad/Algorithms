#include <iostream>
#include <vector>
using namespace std;

vector <int> CUMLSUM (const vector <int> &v) { //pass the vector containing the data
        vector <int> temp; //Create an empty vector
        for (vector <int>::const_iterator it = v.begin(); it != v.end(); ++it)
                if (it == v.begin())
                        temp.push_back (*it); //First element is itself the cumulative sum
                else
                        temp.push_back (temp[temp.size() - 1] + *it); //next element = prev + current element
        return temp;
}

int main () {
        vector <int> v (10, 1), s = CUMLSUM (v); //v is the vector containing data and s is the vector containing the cumulative sum
        for (vector <int>::const_iterator it = s.begin(); it != s.end(); ++it)
                cout << *it << ' ';
        cout << '\n';
        return 0;
}
