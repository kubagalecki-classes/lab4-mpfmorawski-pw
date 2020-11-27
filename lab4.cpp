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
    Para< int > paraInt1(1, 2);
    Para< int > paraInt2(3, 4);
    Para< int > paraInt3(5, 6);

    TablicaPar< int, 3 > TablicaTrzechInt;
    TablicaTrzechInt[0] = paraInt1;
    TablicaTrzechInt[1] = paraInt2;
    TablicaTrzechInt[2] = paraInt3;
    int sumaInt         = 0;
    for (int i = 0; i < 3; i++)
        sumaInt += TablicaTrzechInt[i].suma();

    std::cout << "Suma par tablicy z int: " << sumaInt << std::endl;

    Para< double > paraDbl1(1.1, 2.2);
    Para< double > paraDbl2(3.3, 4.4);
    Para< double > paraDbl3(5.5, 6.6);

    TablicaPar< double, 3 > TablicaTrzechDbl;
    TablicaTrzechDbl[0] = paraDbl1;
    TablicaTrzechDbl[1] = paraDbl2;
    TablicaTrzechDbl[2] = paraDbl3;
    double sumaDbl      = 0.;
    for (int i = 0; i < 3; i++)
        sumaDbl += TablicaTrzechDbl[i].suma();

    std::cout << "Suma par tablicy z double: " << sumaDbl << std::endl;
}

/* Po uruchomieniu otrzymano:
  Suma par tablicy z int: 21
  Suma par tablicy z double: 23.1
*/