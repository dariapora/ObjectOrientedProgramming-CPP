#include <iostream>
#include <math.h>
using namespace std;

//Definiti clasa Triunghi
class Triunghi
{
private:
    //Definiti 3 campuri de tip numeric real, denumite latura1, latura2, latura3
    float latura1, latura2, latura3;

public:
    static int count;
    int current_count;

    //Definiti un constructor fara parametri care initializeaza cele 3 laturi cu valorile 3, 4, respectiv 5
    Triunghi()
    {
        current_count = ++count;
        latura1 = 3;
        latura2 = 4;
        latura3 = 5;
    }

    //Definiti un constructor cu parametri care initializeaza cele 3 laturi cu valorile primite de la metoda care apeleaza. 
    Triunghi(int latura1, int latura2, int latura3)
    {
        current_count = ++count;
        this->latura1 = latura1;
        this->latura2 = latura2;
        this->latura3 = latura3;
    }

    //Creati metode de acces pentru cele 3 laturi
    float get_latura1()
    {
        return latura1;
    }

    float get_latura2()
    {
        return latura2;
    }

    float get_latura3()
    {
        return latura3;
    }

    void set_latura(int indice_latura, int valoare)
    {
        if (indice_latura == 1)
            latura1 = valoare;
        else if (indice_latura == 2)
            latura2 = valoare;
        else if (indice_latura == 3)
            latura3 = valoare;
    }

    // Definiti o metoda publica ce returneaza perimetrul triunghiului
    float get_perimetru()
    {
        return get_latura1() + get_latura2() + get_latura3();
    }

    //Definiti o metoda publica ce returneaza aria triunghiului
    float get_aria()
    {
        float semi_perimetru = get_perimetru() / 2;
        return (sqrt(semi_perimetru * (semi_perimetru - get_latura1()) * (semi_perimetru - get_latura2()) * (semi_perimetru * get_latura3())));
    }

    //Implementati o metoda prin care sa se poata determina, la orice moment in cadrul executiei programului, cate instante ale clasei Triunghi sunt alocate in memorie.
    float get_count()
    {
        return current_count;
    }

    ~Triunghi()
    {
        cout << "Se distruge instanta cu numarul " << current_count << ".\n";
        count--;
    }
};

int Triunghi::count = 0;

int main()
{

    // Alocati dinamic un triunghi, folosind constructorul fara parametri
    Triunghi *triunghi_dinamic = new Triunghi();

    // Afisati perimetrul si aria triunghiului, precum si numarul de instante din acest moment
    cout << "Perimetrul triunghiului stocat la adresa " << triunghi_dinamic << " este " << triunghi_dinamic->get_perimetru() << ", iar aria este " << triunghi_dinamic->get_aria() << ".\n";
    cout << "In acest moment se afla " << Triunghi::count << " instante.\n";

    // Alocati static un triunghi, folosind constructorul cu parametri, cu valorile laturilor 1, 3 si 5
    Triunghi triunghi_static(1, 3, 5);

    // Modificati valoarea latura1 cu 3, iar valoarea latura2 cu 5
    triunghi_static.set_latura(1, 3);
    triunghi_static.set_latura(2, 5);

    // Afisati perimetrul si aria noului triunghi, precum si numarul de instante din acest moment

    cout << "Perimetrul triunghiului stocat la adresa " << &triunghi_static << " este " << triunghi_static.get_perimetru() << ", iar aria este " << triunghi_static.get_aria() << endl;
    cout << "In acest moment se afla " << Triunghi::count << " instante.\n";

    //Dealocati unul dintre cele doua triunghiuri (cel pentru care este posibila aceasta operatie)
    delete triunghi_dinamic;
    
    //Afisati din nou numarul de instante din acest moment
    cout << "In acest moment se afla " << Triunghi::count << " instante.\n";

    return 0;
}