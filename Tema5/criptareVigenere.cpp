#include "cripto_tools.hpp"

void criptareVigenere(ifstream& in, ofstream& out, const string& cheie) {
    char c;
    int index = 0;
    int lungime_cheie = cheie.length();

    while (in >> noskipws >> c) {
        int cod_c = da_cod(c);
        if (cod_c == -1) {
            out << c; 
            continue;
        }

        int cod_key = da_cod(cheie[index % lungime_cheie]);
        out << da_caracter((cod_c + cod_key) % N);
        index++; 
    }
}

int main() {
    ifstream f("alfabet.txt");
    if (!f) {
        cout << "Eroare la deschiderea fisierului alfabet.txt" << endl;
        return 1;
    }
    citesteAlfabet(f);
    f.close();

    ifstream fin("sursa.txt");
    ofstream fout("destinatie.txt");

    if (!fin || !fout) {
        cout << "Eroare la deschiderea fisierelor de intrare/iesire" << endl;
        return 1;
    }

    string cheie = "MUZICA";
    criptareVigenere(fin, fout, cheie);

    fin.close();
    fout.close();

    return 0;
}