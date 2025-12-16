#include <iostream>
#include <vector>
using namespace std;

class Student {
private:
    string nume;
    string prenume;
    int varsta;
public:
    Student() {
        nume = "Doe";
        prenume = "John";
        varsta = 1;
    }
    Student(string nume, string prenume, int varsta) {
        this->nume = nume;
        this->prenume = prenume;
        this->varsta = varsta;
    }
    friend ostream& operator << (ostream &os, Student* s) {
        os << "Nume: " << s->nume << endl;
        os << "Prenume: " << s->prenume << endl;
        os << "Varsta: " << s->varsta << endl;
        return os;
    }
};

class Grupa {
private: Student **studenti;
    int lungime;
public:
    Grupa() {
        this->studenti = new Student * [0];
        this->lungime;
    }

    void adauga(Student *student) {
        Student **temp = new Student*[this->lungime+1];
        for (int i=0; i<this->lungime; i++) {
            temp[i] = this->studenti[i];
        }
        temp[this->lungime] = student;
        delete[] this->studenti;
        this->studenti = temp; // dar fara stergerea vectorului, acesta ramane in memorie => memory leak
        this->lungime++;
        //nu trebuie sters temp, pentru ca este in stack si se sterge automat
    }

    friend ostream& operator << (ostream& os, Grupa* g) {
        for (int i=0; i<g->lungime; i++) {
            os << g->studenti[i];
        }
        return os;
    }
};

template <typename T> // pentru cod generic. daca difera doar tipul de date, dar logica este identica, se folosesc template-urile

class Colectie {
private:
    T** elemente;
    int lungime;
public:
    void adauga(T *element) { // asta, totusi, e redundant. poate fi folosit stl
        T **temp = new T*[this->lungime+1];
        for (int i=0; i<this->lungime; i++) {
            temp[i] = this->elemente[i];
        }
        temp[this->lungime] = element;
        delete[] this->elemente;
        this->elemente = temp;
        this->lungime++;
    }
};


int main() {
    Grupa* g = new Grupa();
    Student* ion = new Student("Popescu", "Ion", 12);
    Student* george = new Student("Georgescu", "George", 11);
    Student* maria = new Student("Marinovici", "Maria", 11);
    Student* iliuta = new Student("Popescu", "Iliuta", 11);

    cout << "Afisez grupa goala" << endl;
    cout << g;
    cout << "==================" << endl;

    cout << "Afisez doar pe Ion" << endl;
    g->adauga(ion);
    cout << g;
    cout << "==================" << endl;

    cout << "Afisez pe toti" << endl;
    g->adauga(george);
    g->adauga(maria);
    g->adauga(iliuta);
    cout << g;
    cout << "==================" << endl;

    vector<Student*> grupastl;
    grupastl.push_back(ion);

    Colectie<Student>* grupa = new Colectie<Student>();
    // Colectie<Animal>* zoo = new Colectie<Animal>();
}
