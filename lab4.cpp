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

int main()
{

    TablicaPar< int, 3 > TablicaTrzechInt;
    TablicaTrzechInt[0] = Para< int >{1, 2};
    TablicaTrzechInt[1] = Para< int >{3, 4};
    TablicaTrzechInt[2] = Para< int >{5, 6};
    std::cout << "Suma pierwszej pary w TablicaTrzechInt: " << TablicaTrzechInt[0].suma()
              << std::endl;

    TablicaPar< double, 0 > PustaTablicaDouble;
}

/* Po uruchomieniu otrzymano:
  Suma pierwszej pary w TablicaTrzechInt: 3
  Tablica jest pusta
*/