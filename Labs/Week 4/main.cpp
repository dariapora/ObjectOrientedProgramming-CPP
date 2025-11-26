#include <iostream>
using namespace std;

// Definiti clasa Pasare
class Pasare
{

    // Definiti doua campuri, Inaltime (de tip numeric intreg) si Canta (de tip bool)
private:
    unsigned int inaltime;
    bool canta;

    // Definiti un constructor fara parametri, care seteaza cele doua campuri cu valorile default ale tipurilor lor
public:
    Pasare() : inaltime(0), canta(false){};

    // Definiti un constructor cu parametri care poate primi de la apelant valorile pentru ambele campuri
    Pasare(unsigned int inaltime, bool canta)
    {
        this->inaltime = inaltime;
        this->canta = canta;
    }

    // Definiti metode de acces
    void set_inaltime(unsigned int val)
    {
        inaltime = val;
    }

    void set_canta(bool val)
    {
        canta = val;
    }

    unsigned int get_inaltime() { return inaltime; }
    bool get_canta() { return canta; }

    // Definiti un constructor de copiere pentru clasa Pasare
    Pasare(const Pasare &sursa)
    {
        inaltime = sursa.inaltime;
        canta = sursa.canta;
    }

    // Supraincarcati operatorul = pentru clasa Pasare
    Pasare &operator=(const Pasare &sursa)
    {
        if (this != &sursa)
        {
            inaltime = sursa.inaltime;
            canta = sursa.canta;
        }
        return *this;
    }

    //Definiti o metoda de afisare care va afisa urmatorul text:
    //“Pasarea canta: <Canta>; Are inaltimea de: <Inaltime>; 
    //Inaltimea este stocata la adresa: <AdresaInaltime>”
    void afisare()
    {
        cout << (canta ? "Pasarea canta, are inaltimea de: " : "Pasarea nu canta, are inaltimea de: ") << inaltime << ". Inaltimea este stocata la adresa " << &inaltime << endl;
    }

};

int main()
{

    //Alocati static un obiect de tip Pasare numit p1, apeland constructorul fara parametri. 
    Pasare p1;

    //Pasarea p1 nu canta si are inaltimea de 15cm
    p1.set_canta(false);
    p1.set_inaltime(15);

    //Alocati static un obiect de tip Pasare numit p2, folosind constructorul cu parametri. Pasarea canta si are 20cm inaltime
    Pasare p2(20, true);

    //Alocati static un obiect de tip Pasare numit p3, folosind constructorul de copier, care sa aiba aceleasi valori ale campurilor precum obiectul p2
    Pasare p3 = p2;

    //Alocati static un obiect de tip Pasare numit p4, folosind constructorul fara parametri
    Pasare p4;

    //Folositi supraincarcarea operatorului = pentru a asigna obiectului p4 valorile proprietatilor obiectului p2
    p4 = p2;

    //Modificati inaltimea obiectului p2 in 55cm
    p2.set_inaltime(55);

    //Afisati cele 4 obiecte folosind metoda definita la punctul 8 
    p1.afisare();
    p2.afisare();
    p3.afisare();
    p4.afisare();
    return 0;
}