
#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <random>
#include <map>
#include "arbin.h"

using namespace std;
using namespace chrono;

void tester(vector<int> valeurs, string type) {
    arbre a;
    map<int, int> m;

    cout << "\n===== " << type << " =====" << endl;

    // ABR : insertion
    auto debut = high_resolution_clock::now();
    for (int v : valeurs)
        a.inserer(v);
    auto fin = high_resolution_clock::now();
    cout << "ABR - Insertion : "
         << duration_cast<microseconds>(fin - debut).count()
         << " us" << endl;

    // map : insertion
    debut = high_resolution_clock::now();
    for (int v : valeurs)
        m.insert({v, v});
    fin = high_resolution_clock::now();
    cout << "map - Insertion : "
         << duration_cast<microseconds>(fin - debut).count()
         << " us" << endl;

    // ABR : recherche
    debut = high_resolution_clock::now();
    for (int v : valeurs)
        a.rechercher(v);
    fin = high_resolution_clock::now();
    cout << "ABR - Recherche : "
         << duration_cast<microseconds>(fin - debut).count()
         << " us" << endl;

    // map : recherche
    debut = high_resolution_clock::now();
    for (int v : valeurs)
        m.find(v);
    fin = high_resolution_clock::now();
    cout << "map - Recherche : "
         << duration_cast<microseconds>(fin - debut).count()
         << " us" << endl;

    // ABR : suppression
    debut = high_resolution_clock::now();
    for (int v : valeurs)
        a.supprimer(v);
    fin = high_resolution_clock::now();
    cout << "ABR - Suppression : "
         << duration_cast<microseconds>(fin - debut).count()
         << " us" << endl;

    // map : suppression
    debut = high_resolution_clock::now();
    for (int v : valeurs)
        m.erase(v);
    fin = high_resolution_clock::now();
    cout << "map - Suppression : "
         << duration_cast<microseconds>(fin - debut).count()
         << " us" << endl;
}

int main() {
    const int N = 32000;
    vector<int> valeurs(N);

    for (int i = 0; i < N; i++)
        valeurs[i] = i + 1;

    tester(valeurs, "Valeurs ordonnees");

    mt19937 gen(random_device{}());
    shuffle(valeurs.begin(), valeurs.end(), gen);

    tester(valeurs, "Valeurs aleatoires");

    return 0;
}
