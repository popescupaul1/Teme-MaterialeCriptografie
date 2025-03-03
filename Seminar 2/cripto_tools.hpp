#include <iostream>
using namespace std;

int modulo(int a, int n) {
	if (a >= 0 && n > 0)
		return a % n;
	if (a < 0 && n > 0)
		return a % n + n;
	if (n == 0)
		return -1;
}

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

int cmmdc(int a, int b) {
	if (a * b == 0) return a + b;   //if (a == 0) return b; if (b == 0) return a;
	
	int rest = 0;
	while (b) {
		rest = modulo(a, b);
		a = b;
		b = rest;
	}
	return a;
}

int invers(int a, int n) {
	int q, r, x0 = 1, x1 = 0, copy_n = n;
	a = modulo(a, n);
	while (n) {
		r = n;
		q = a / n;
		n = a % n;
		a = r;

		r = x1;
		x1 = x0 - q * x1;
		x0 = r;
	}
	if (a == 1)
		return modulo(x0, copy_n);
	return -1;
}
