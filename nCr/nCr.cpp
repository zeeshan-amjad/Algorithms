#define MOD 1000000007

long long fact[100005], comb[100005];

long long fast_pow (long long b, int e) {       //fast exponentiation
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

void init() {           //factorial initializer
    fact[0] = 1;
    for (int i = 1; i <= 100000; ++i)
        fact[i] = (i * fact[i - 1]) % MOD;
}

void combination(n) {
    comb[0] = comb[n] = 1;
    for (int i = 1; i < n; ++i) 
        comb[i] = (fact[n] * fast_pow (fact[n - i] * fact[i], MOD - 2)) % MOD;    // inverse modulo in action
}
