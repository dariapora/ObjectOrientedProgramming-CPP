#include <iostream>
#include <math.h>
using namespace std;

// Definiti clasa Paralelipiped, cu 3 campuri numerice intregi: Lungime, Latime, Inaltime
class Paralelipied
{
    int lungime, latime, inaltime;

    // Supraincarcati operatorul >> pentru a putea permite citirea tuturor campurilor dintr-o singura instructiune
    friend istream& operator>>(istream& is, Paralelipied& p)
    {
        cout << "Lungime: ";
        is >> p.lungime;
        cout << "Latime: ";
        is >> p.latime;
        cout << "Inaltime: ";
        is >> p.inaltime;
        return is;
    }

    // Supraincarcati operatorul << pentru a putea permite afisarea tuturor campurilor dintr-o singura instructiune
    friend ostream& operator>>(ostream &os, Paralelipied& p)
    {
        cout << "Lungimea este: " << p.lungime << "\n";
        cout << "Latimea este: " << p.latime << "\n";
        cout << "Inaltimea este: " << p.inaltime << "\n";
    }

    // Supraincarcati operatorul + care va returna suma volumelor instantei curente de paralelipiped si al unei alte instante primite ca parametru
    int operator+(Paralelipied &p)
    {
        int volum_curent = this->get_volum();
        int volum_parametru = p.get_volum();
        return volum_curent+volum_parametru;
    }

    // Supraincarcati operatorul – care va returna diferenta absoluta a volumelor instantei curente de paralelipiped si al unei alte instante primite ca parametru
    int operator-(Paralelipied &p)
    {
        int volum_curent = this->get_volum();
        int volum_parametru = p.get_volum();
        return abs(volum_curent+volum_parametru);
    }

    public:
    
    // Definiti o metoda care calculeaza volumul paralelipipedului
    int get_volum()
    {
        return (this->latime*this->inaltime*this->lungime);
    }


};



