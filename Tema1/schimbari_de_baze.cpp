#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int ConvertireInBaza10(string numar, int baza) {
	int numarFinal = 0, putere = 1, cifra = 0;
	for (int i = numar.size() - 1; i >= 0; i--) {
		cifra = isdigit(numar[i]) ? numar[i] - '0' : numar[i] - 'A' + 10;
		numarFinal += cifra * putere;
		putere *= baza;
	}
	return numarFinal;
}

string ConvertireDinBaza10(int numar, int baza) {
	string rezultat = "";
	while (numar > 0) {
		int cifra = numar % baza;
		rezultat = (cifra < 10 ? char(cifra + '0') : char(cifra - 10 + 'A')) + rezultat;
		numar /= baza;
	}
	if (rezultat.empty()) return "0";
	else return rezultat;
}

int main() {
	string numar;
	int baza1, baza2;

	cout << "Introduce, pe rand, un numar, prima baza si a doua baza:";
	cin >> numar >> baza1 >> baza2;

	if (baza1 < 2 || baza1 > 26 || baza2 < 2 || baza2 > 26) {
		cout << "Eroare: Bazele trebuie sa fie intre 2 si 26!" << endl;
		return 1;
	}

	int numarBazaB1 = ConvertireInBaza10(numar, baza1);
	string numarBazaB2 = ConvertireDinBaza10(numarBazaB1, baza2);

	cout << "Numar final: " << numarBazaB2 << endl;
	return 0;
}