#include <iostream>

template < typename T >
class Para
{
public:
    Para() {}
    Para(T pobiekt, T dobiekt) : pierwszy_obiekt{pobiekt}, drugi_obiekt{dobiekt} {}

    T getPierwszyObiekt() const { return pierwszy_obiekt; }
    T getDrugiObiekt() const { return drugi_obiekt; }

    T suma() const { return pierwszy_obiekt + drugi_obiekt; }

private:
    T pierwszy_obiekt, drugi_obiekt;
};

template < typename T, unsigned int N >
class TablicaPar
{
public:
    Para< T >& operator[](int i) { return tablica[i]; }

private:
    Para< T > tablica[N];
};

template < typename T >
class TablicaPar< T, 0 >
{
public:
    TablicaPar() { puts("Tablica jest pusta"); }
};

template < typename T >
struct S
{
    void print() { puts("Szablon ogólny"); }
};

template <>
struct S< double >
{
    void print() { puts("Specjalizacja dla double"); }
};

template < typename T >
T iloczyn(T tab[], int n)
{
    T wynik = static_cast< T >(1);
    for (int i = 0; i < n; i++)
        wynik = wynik * tab[i];
    return wynik;
}

int main()
{
    int tab1[]   = {1, 2, 3};
    int silnia_3 = iloczyn< int >(tab1, 3);
    std::cout << "3! = " << silnia_3 << std::endl;
    int tab2[]   = {1, 2, 3, 4, 5};
    int silnia_5 = iloczyn(tab2, 5);
    std::cout << "5! = " << silnia_5 << std::endl;
}

/* Po uruchomieniu otrzymano:
  3! = 6
  5! = 120
*/