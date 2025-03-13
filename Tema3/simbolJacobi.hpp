#include <iostream>
using namespace std;

int simbolJacobi(int a, int n) {
    if (n <= 0 || n % 2 == 0)
        throw invalid_argument("n trebuie sa fie un numar impar pozitiv");

    a = a % n;
    int result = 1;

    while (a) {
        while (a % 2 == 0) { 
            a /= 2;
            if (n % 8 == 3 || n % 8 == 5)
                result = -result;
        }

        a = a ^ n;
        n = a ^ n;
        a = a ^ n;

        if (a % 4 == 3 && n % 4 == 3)
            result = -result;

        a %= n; 
    }

    return (n == 1) ? result : 0;
}