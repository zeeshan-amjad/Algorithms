#include <iostream>
#include <cstring>
#define MAX 1000001
#define MOD 1000000007
using namespace std;

int F[MAX];
bool match[MAX];

void build_failure_function (string pattern) {
    memset (F, 0, sizeof (F));
    memset (match, 0, sizeof (match));
    F[0] = F[1] = 0;
    for (int i = 2; i <= pattern.size(); ++i) {
        int j = F[i - 1];
        while (1) {
            if (pattern[i - 1] == pattern[j]) {
                F[i] = j + 1;
                break;
            }

            if (!j) {
                F[i] = 0;
                break;
            }

            j = F[j];
        }
    }
}

void kmp (string text, string pattern) {
    build_failure_function (pattern);
    int i = 0, j = 0;
    while (j < text.size()) {
        if (text[j] == pattern[i]) {
            i++, j++;
            if (i == pattern.size())
                match[j - 1] = 1, i = F[i];
        }

        else if (i > 0)
            i = F[i];

        else
            j++;
    }
}
