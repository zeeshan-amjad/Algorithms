#include <iostream>
#include <climits>
using namespace std;

#define SIZE 100000
int a[SIZE];

int kadane () {
        int s = 0, m = INT_MIN;
        for (int i = 0; i < SIZE; ++i) {
                s = max (0, s + a[i]);
                m = max (m, s);
        }
        if (!m) { 			//if all elements are negative
                m = INT_MIN;
                for (int i = 0; i < SIZE; ++i)
                        m = max (m, a[i]);
        }
        return m;
}


int main () {

	return 0;
}
