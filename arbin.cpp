#include <iostream>
#include <chrono>
#include <vector>
#include "arbin.h"

using namespace std;
using namespace chrono;

int main() {
    const int N = 10007;
    vector<int> valeurs;
    for (int i = 0; i < N; i++)
        valeurs.push_back((i * 7919) % N);
    arbre a;
    auto debut = high_resolution_clock::now();
    for (int val : valeurs)
        a.inserer(val);
    auto fin = high_resolution_clock::now();
    auto tInsertion = duration_cast<nanoseconds>(fin - debut).count();
    debut = high_resolution_clock::now();
    for (int val : valeurs)
        a.rechercher(val);
    fin = high_resolution_clock::now();
    auto tRecherche = duration_cast<nanoseconds>(fin - debut).count();
    debut = high_resolution_clock::now();
    for (int val : valeurs)
        a.supprimer(val);
    fin = high_resolution_clock::now();
    auto tSuppression = duration_cast<nanoseconds>(fin - debut).count();
    cout << "Nombre de valeurs : " << N << endl;
    cout << "Insertion : " << tInsertion << " ns" << endl;
    cout << "Recherche : " << tRecherche << " ns" << endl;
    cout << "Suppression : " << tSuppression << " ns" << endl;
    return 0;
}