#include "SortingAlgorithm.hpp"
#include <iostream>
#include <chrono>
#include <unistd.h>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
using namespace chrono;
using namespace SortLibrary;
int main(int argc, char **argv)
{
    int n = 0;
    int size = atoi(argv[1]);
    vector <double> v(size);
    iota(v.begin(), v.end(),n); // già ordinati

    cout << " Vettore gia' ordinato : " << endl;
    cout << " Durata Bubble Sort " << SortLibrary::durataBubble(v) << " millisecondi " << endl;
    cout << " Durata Merge Sort " << SortLibrary::durataMerge(v) << " millisecondi " << endl;



    // PERTURBARE IN MANIERA RANDOMICA I PRIMI 1000 ELEMENTI
    for (unsigned int i=0; i<1000; i++)
    {
        v[i] = rand() % 10;
    }

    cout << " Vettore in cui ho perturbato i primi 1000 elementi : " << endl;
    cout << " Durata Bubble Sort " << durataBubble(v) << " millisecondi " << endl;
    cout << " Durata Merge Sort " << durataMerge(v) << " millisecondi " << endl;

    // VETTORE GENERATO CON NUMERI RANDOM
    for (unsigned int i=0; i < size; i++)
    {
        v[i] = rand() % 10;
    }

    cout << " Vettore con valori random dentro : " << endl;
    cout << " Durata Bubble Sort " << durataBubble(v) << " millisecondi " << endl;
    cout << " Durata Merge Sort " << durataMerge(v) << " millisecondi " << endl;

    // VETTORE CON VALORI DECRESCENTI
    generate(v.begin(), v.end(), [&size] () {return size--;});

    cout << " Vettore con valori decrescenti : " << endl;
    cout << " Durata Bubble Sort " << durataBubble(v) << " millisecondi " << endl;
    cout << " Durata Merge Sort " << durataMerge(v) << " millisecondi " << endl;

}
