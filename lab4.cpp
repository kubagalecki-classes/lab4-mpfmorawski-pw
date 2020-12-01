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
struct S
{
    void print() { puts("Szablon ogólny"); }
};

template <>
struct S< double >
{
    void print() { puts("Specjalizacja dla double"); }
};

int main()
{

    S< int >    StructInt;
    S< double > StructDouble;
    StructInt.print();
    StructDouble.print();
}

/* Po uruchomieniu otrzymano:
  Suma par tablicy z int: 21
  Suma par tablicy z double: 23.1
*/