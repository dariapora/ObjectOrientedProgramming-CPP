#include<iostream>
using namespace std;
class Vehicul {
protected:
	int id;
	string nume;
	string serie;

public:
	Vehicul(int id, string nume, string serie) {
		this->id = id;
		this->nume = nume;
		this->serie = serie;
	}

	void porneste() {
		cout << "Am pornit!" << endl;
	}

	void detalii() {
		cout << this->id << endl;
		cout << this->nume << endl;
		cout << this->serie << endl;
	}
};

class VehiculAerian: public Vehicul {
protected:
	int nrMotoare;

public:
	void porneste() {
		cout << "Vaj!";
	}

	void detalii() {
		Vehicul::detalii(); // Astfel, this merge la clasa de baza
		cout << this->nrMotoare;
	}

	VehiculAerian(int id, string nume, string serie, int nrMotoare):Vehicul(id, nume, serie) {
		this->nrMotoare = nrMotoare;

	}
	
	void anuntaDecolare() {
		cout << "Am decolat! Yey!" << endl;
	}
};

int main() {
	VehiculAerian va(1,"737", "ABC", 2);
	va.detalii();
}