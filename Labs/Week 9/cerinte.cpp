#include <iostream>
using namespace std;

// Definiți următoarea structură de obiecte

// Vehicul (ID, nume, serie) -> (porneste(), detalii())
// Aerian (ID, nume, serie, număr motoare) -> (anuntaDecolare(mesaj))
// Comercial (ID, nume, serie, număr motoare, serie, număr locuri business class, numar locuri economy class, număr persoane in echipaj) -> (anuntaDecolare(punetiCenturile))
// Cargo (ID, nume,serie,  număr motoare, capacitate transport, număr de persoane în echipaj) -> (anuntaDecolare(asiguratiMarfa))

class Vehicul
{
protected:
    int id;
    string nume;
    string serie;

public:
    void porneste()
    {
        cout << "Vehiculul a pornit." << endl;
    }

    void detalii()
    {
        cout << "ID: " << id << ", Nume: " << nume << ", Serie: " << serie << endl;
    }
};

class VehiculAerian : public Vehicul
{
protected:
    int numarMotoare;

public:
    void anuntaDecolare(string mesaj)
    {
        cout << "Anunt de decolare: " << mesaj << endl;
    }
};

class Comercial : public VehiculAerian
{
protected:
    int numarLocuriBusinessClass;
    int numarLocuriEconomyClass;
    int numarPersoaneEchipaj;

public:
    void anuntaDecolare(string punetiCenturile)
    {
        cout << "Anunt de decolare pentru comercial: " << punetiCenturile << endl;
    }
};

class Cargo : public VehiculAerian
{
protected:
    int capacitateTransport;
    int numarPersoaneEchipaj;

public:
    void anuntaDecolare(string asiguratiMarfa)
    {
        cout << "Anunt de decolare pentru cargo: " << asiguratiMarfa << endl;
    }
};

int main()
{
    VehiculAerian va;
    va.porneste();
}