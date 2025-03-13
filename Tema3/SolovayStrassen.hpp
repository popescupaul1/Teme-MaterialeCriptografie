#include <iostream>
using namespace std;

int a_la_b_mod_c(int a, int b, int c) {

	a = a % c;
	int p = 1;
	while (b) {
		if (b % 2) {
			p = (p * a) % c;
		}
		a = (a * a) % c;
		b /= 2;
	}
	return p;
}

bool SolovayStrassen(long long n, int k) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false; 

    srand(time(0)); 

    for (int i = 0; i < k; i++) {
        long long a = 2 + rand() % (n - 3); 
        int jacobi = simbolJacobi(a, n);
        if (jacobi == 0) return false;

        long long rezultatTest = a_la_b_mod_c(a, (n - 1) / 2, n);

        if ((rezultatTest - jacobi) % n != 0)
            return false; 
    }

    return true; 
}