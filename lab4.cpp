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

int main()
{

    TablicaPar< int, 3 > TablicaTrzechInt;
    TablicaTrzechInt[0] = Para< int >{1, 2};
    TablicaTrzechInt[1] = Para< int >{3, 4};
    TablicaTrzechInt[2] = Para< int >{5, 6};
    int sumaInt         = 0;
    for (int i = 0; i < 3; i++)
        sumaInt += TablicaTrzechInt[i].suma();
    std::cout << "Suma par tablicy z int: " << sumaInt << std::endl;

    TablicaPar< double, 3 > TablicaTrzechDbl;
    TablicaTrzechDbl[0] = Para< double >{1.1, 2.2};
    TablicaTrzechDbl[1] = Para< double >{3.3, 4.4};
    TablicaTrzechDbl[2] = Para< double >{5.5, 6.6};
    double sumaDbl      = 0.;
    for (int i = 0; i < 3; i++)
        sumaDbl += TablicaTrzechDbl[i].suma();
    std::cout << "Suma par tablicy z double: " << sumaDbl << std::endl;
}

/* Po uruchomieniu otrzymano:
  Suma par tablicy z int: 21
  Suma par tablicy z double: 23.1
*/