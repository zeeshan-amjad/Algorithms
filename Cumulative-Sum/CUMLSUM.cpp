#include <iostream>
#include <vector>
using namespace std;

vector <int> CUMLSUM (const vector <int> &v) {
        vector <int> temp;
        for (vector <int>::const_iterator it = v.begin(); it != v.end(); ++it)
                if (it == v.begin())
                        temp.push_back (*it);
                else
                        temp.push_back (temp[temp.size() - 1] + *it);
        return temp;
}

int main () {
        vector <int> v (10, 1), s = CUMLSUM (v);
        for (vector <int>::const_iterator it = s.begin(); it != s.end(); ++it)
                cout << *it << ' ';
        cout << '\n';
        return 0;
}
