#include <iostream>
using namespace std;

int x, y, d;

void extendedEuclid (int a, int b) {
	if (!b) {
		d = a;
		x = 1;
		y = 0;
		return;
	}

	extendedEuclid (b, a % b);
	
	int x1 = y;
	int y1 = x - (a / b) * y;
	x = x1;
	y = y1;
}

int main () {
	extendedEuclid (25, 18);
	cout << x << ' ' << y << ' ' << d << '\n';
	return 0;
}