#include "cripto_tools.hpp"

int MasseyOmura(int p, int eA, int eB, int m) {
    if (eA > p - 1 || eB > p - 1) {
        std::cerr << "Numar e introdus invalid.\n";
        return 1;
    }

    int dA = invers(eA, p - 1);
    int dB = invers(eB, p - 1);

    int C1 = a_la_b_mod_c(m, eB, p);  
    int C2 = a_la_b_mod_c(C1, eA, p);  
    int C3 = a_la_b_mod_c(C2, dB, p);  
    int Cmes = a_la_b_mod_c(C3, dA, p);

    std::cout << "Mesajul este: " << Cmes << "\n";
    return Cmes;
}