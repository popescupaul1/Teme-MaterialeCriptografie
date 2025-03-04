#include "functieIndicatoareEuler.hpp";

int main() {
    long long numar;
    cout << "Introdu un numar: ";
    cin >> numar;

    cout << "phi(" << numar << ") = " << functieIndicatoareEuler(numar) << endl;
    return 0;
}
