// Polimorfismul: supradefinirea metodelor si functii virtuale. Clase abstracte.

#include<iostream>
using namespace std;

class Animal
{
protected:
	char* nume; // din enunt => pointer la vector de caractere
	int varsta;

public:
	Animal(const char* nume, int varsta)  // const ca sa pot folosi nume ca un string
	{
		this->nume = new char[strlen(nume) + 1];
		strlcpy(this->nume, nume, strlen(nume) + 1);
		this->varsta = varsta;
	}
	Animal()
	{
		delete this->nume;
	}

	void WhaiAmI()
	{
		cout << "Sunt animal" << endl;
	}
	virtual void Display()
	{
		cout << "Nume: " << this->nume << endl;
		cout << "Varsta: " << this->varsta << endl;
	}
	virtual void Speak() = 0;
};

class Dog:public Animal
{
protected:
	string owner;
public:
	Dog(const char* nume, int varsta, string owner) : Animal(nume, varsta)
	{
		this->owner = owner;
	}

	void WhaiAmI()
	{
		cout << "Sunt caine" << endl;
	}

	void Display()
	{
		Animal::Display();
		cout << "Stapan: " << this->owner << endl;
	}

	void Speak() override
	{
		cout << "Ham Ham!!" << endl;
	}
};

class Cat :public Animal
{
protected:
	string rasa;
public:
	Cat(const char* nume, int varsta, string rasa) :Animal(nume, varsta)
	{
		this->rasa = rasa;
	}

	void WhaiAmI()
	{
		cout << "Sunt pisica" << endl;
	}

	void Display()
	{
		Animal::Display();
		cout << "Rasa: " << this->rasa << endl;
	}

	void Speak() override  //**
	{
		cout << "miauu!!" << endl;
	}
};

int main()
{
	//char* nume;
	//strcpy_s(nume, 7, "Fuzica");
	//Animal a("Fuzica",4);  //merge daca nu am ce e cu **
	Dog d("Roger", 8, "Lucian");
	Cat c("Papufea", 1, "British shorthair");

	/*a.WhaiAmI();
	d.WhaiAmI();
	c.WhaiAmI();

	a.Display();
	d.Display();
	c.Display();*/

	//Animal* animale //fac dinamic pt 1.ca la vector static tr sa stiu cat (biti) ar tr sa sar astfel incat sa ajung la urmatorul animal 2. ca sa pointeze fiecare la o alta clasa
	/*Animal* a2 = new Animal("Fuzica2", 5);
	Dog* d2 =  new Dog("Roger2", 9, "Lucian2");
	Cat* c2 = new Cat("Papufea2", 2, "British shorthair 2");*/

	/*a2->WhaiAmI();
	d2->WhaiAmI();
	c2->WhaiAmI();*/

	//Animal* a2 = new Animal("Fuzica2", 5); //merge daca nu am ce e cu **
	Animal* d2 = new Dog("Roger2", 9, "Lucian2");
	Animal* c2 = new Cat("Papufea2", 2, "British shorthair 2");

	Animal* a3;
	int numar;
	cin >> numar;
	if (numar % 2 == 0)
	{
		a3= new Dog("Roger3", 9, "Lucian3");
	}
	else
	{
		a3 = new Cat("Papufea3", 3, "British shorthair 3");
	}

	a3->Display(); 
	a3->Speak();

}
