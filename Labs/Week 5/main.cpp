#include <iostream>
using namespace std;

class Pisica
{
    int varsta;
    string nume;
    public: 
    
    Pisica(int varsta, string nume)
    {
        this->varsta = varsta;;
        this->nume = nume;
    }

    Pisica();

    Pisica (const Pisica&)
    {
        this->nume = nume;
        this->varsta = varsta;
    }
    friend ostream& operator<<(ostream& os, Pisica& source)
    {
        os << "Numele pisicii este: " << source.nume << ", iar varsta ei este " << source.varsta << ".\n";
        return os;
    }

    friend istream& operator >>(istream& is, Pisica& dest)
    {
        cout << "Dati nume: "; is >> dest.nume;
        cout << "Dati varsta: "; is >> dest.varsta;
        return is;
    }
    
    Pisica operator+(int v)
    {
        Pisica p;
        p.nume = this->nume;
        p.varsta = this->varsta+v;
        return p;
    }

    Pisica operator+(const Pisica& p)
    {
        Pisica newP;
        newP.nume = this->nume + " " + p.nume;
        newP.varsta = this->varsta + p.varsta;
        return newP;
    }

    Pisica& operator++()
    {
        varsta++;
        return *this;
    }

    Pisica operator++(int)
    {
        Pisica copie(*this);
        ++*this;
        return copie;
    }

};

int main()
{
    Pisica p1(4, "Lara");
    Pisica p2(1, "Yvonne");
    cin >> p2;
    cout << p1 << p2;
}