#include <iostream>

/* PARA */
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
/* KONIEC PARA */

/* TABLICA PAR */
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
/* KONIEC TABLICA PAR */

/* ZADANIE 6 */
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
/* KONIEC ZADANIE 6 */

/* ZADANIE 8 - Szablony funkcji */
template < typename T >
T iloczyn(T tab[], int n)
{
    T wynik = static_cast< T >(1);
    for (int i = 0; i < n; i++)
        wynik = wynik * tab[i];
    return wynik;
}
/* KONIEC ZADANIE 8 */

/*  ZADANIE 9 - Dedukcja arguemntów funkcji */
template < typename T >
T sumaPary(const Para< T >& para)
{
    return para.suma();
}
/*  KONIEC ZADANIE 9 */

int main()
{
    Para< int > para{3, 5};
    std::cout << sumaPary(para) << std::endl;
}

/* Po uruchomieniu otrzymano:
  8
*/