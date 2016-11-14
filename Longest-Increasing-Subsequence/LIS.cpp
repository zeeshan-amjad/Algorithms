#include <iostream>
using namespace std;

int size, lis[1000006];

int lowerBound (int a[], int n, int val) {
	int l = 0, r = n - 1;
	while (r >= l) {
		int mid = l + (r - l) / 2;
		if (a[mid] < val)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return l;
}
 
void LIS (int a[], int n) {
	int len[n], arr[n], l = 1, Root[n] = {0};

	len[0] = 0, arr[0] = a[len[0]];
 
	for (int i = 1; i < n; ++i) {
		int p = lowerBound (arr, l, a[i]);
		len[p] = i, arr[p] = a[len[p]];
		l = max (l, p + 1);
		Root[i] = len[p - 1];
	}
 	
	int c = len[l - 1], i = l - 1;
	while (1) {
		lis[i--] = a[c];
		if (!c)
			break;
		c = Root[c];
	}

	size = l;
}
