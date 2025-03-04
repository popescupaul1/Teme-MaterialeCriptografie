#include <iostream>
using namespace std;

long long functieIndicatoareEuler(long long numar) {
    if (numar == 1) return 1;

    long long rezultat = numar;
    long long p = 2;

    while (p * p <= numar) {
        if (numar % p == 0) {
            while (numar % p == 0)
                numar /= p;
            rezultat -= rezultat / p;
        }
        if (p == 2)  p++;
        else p += 2;
    }

    if (numar > 1)
        rezultat -= rezultat / numar;

    return rezultat;
}