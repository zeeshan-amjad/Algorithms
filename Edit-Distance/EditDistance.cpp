//Tested for the problem UVa 1207 (Prince and Princess).

#include <iostream>
using namespace std;

int l1, l2, dp[1000][1000];
string a, b;

int editDistance (string a, string b) {
	for (int i = 0; i <= l1; ++i)
        	for (int j = 0; j <= l2; ++j) {
                	if (!i || !j) {
				dp[i][j] = i + j;
				continue;
			}
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
				continue;
			}
                        dp[i][j] = min (min (dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                }
	return dp[l1][l2];
}

int main () {

	return 0;
}
