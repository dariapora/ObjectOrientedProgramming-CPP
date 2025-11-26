// Moștenire (class ClassName : accessModifier ClassName2)

// Pentru a preveni mostenirea unei clase, se foloseste cuvantul cheie final:
// class Shape final { ... }


#include <iostream>
using namespace std;

class Shape
{
public:
    string culoare;
    Shape()
    {
        cout << "Am apelat constructorul fara parametri pentru Shape.";
    }
    Shape(string nume, int id, string culoare)
    {
        cout << "Am apelat constructorul cu parametri pentru Shape.";
        this->nume = nume;
        this->id = id;
        this->culoare = culoare;
    }

private:
    int id;

protected:
    string nume;
};

// Supradefinire = overriding

// Clasa Triangle mosteneste clasa Shape

class Triangle : public Shape // modificatorul de acces este obligatoriu, altfel default este private
{
protected:
    int l1, l2, l3;

public: 
    Triangle()
    {
        cout << "Am apelat constructorul pentru Triangle.";
    }
    Triangle(string nume, int id, string culoare, int l1, int l2, int l3) : Shape(nume, id, culoare)
    {
        cout << "Am apelat constructorul cu parametri pentru Triangle.";
        this->l1 = l1;
        this->l2 = l2;
        this->l3 = l3;
    }
};

int main()
{
    // Shape s;
    // Triangle t;
}