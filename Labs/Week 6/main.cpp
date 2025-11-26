#include <iostream>
using namespace std;

class Numbers
{
    int size;
    int *p;

public:
    Numbers(int s, int *c)
    {
        p = new int[s];
        for (int i = 0; i < s; i++)
        {
            p[i] = c[i];
        }
        size = s;
    }
    friend ostream &operator<<(ostream &os, const Numbers &other)
    {
        for (int i = 0; i < other.size; i++)
        {
            os << other.p[i] << " ";
        }
        return os;
    }
    int &operator[](int index)
    {
        if (index >= 0 && index < size)
            return p[index];
        cerr << ("indexul nu exista!"); //
    }
};

int main()
{
    int s;
    cin >> s;
    int *vec = new int[s]; // alocam s elemente in memorie pt vector
    for (int i = 0; i < s; i++)

    {
        vec[i] = i;
    }
    Numbers m(s, vec);
    cout << m;
    cout << m[17];
    try
    {
        cout << m[17];
    }
    catch (exception &x)
    {
        cout << x.what();
    }
    cout << "dupa executie" << endl; // de scris operatorul functie () si operatorul cast din seminar
}