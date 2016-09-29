#include <iostream>
#define MOD 1000000007
using namespace std;

long long fast_pow (long long b, int e) {
    b = b % MOD;
    long long ans = 1;
    while (e > 0) {
        if (e & 1)
            ans = (ans * b) % MOD;
        e /= 2;
        b = (b * b) % MOD;
    }
    return ans % MOD;
}

int main() {
    
	  return 0;
}
