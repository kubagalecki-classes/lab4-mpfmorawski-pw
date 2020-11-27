#include <iostream>

template < typename T >
class Para
{
public:
    Para(T pobiekt, T dobiekt) : pierwszy_obiekt{pobiekt}, drugi_obiekt{dobiekt} {}

    T getPierwszyObiekt() const { return pierwszy_obiekt; }
    T getDrugiObiekt() const { return drugi_obiekt; }

    T suma() const { return pierwszy_obiekt + drugi_obiekt; }

private:
    T pierwszy_obiekt, drugi_obiekt;
};

int main()
{
    Para< int > paraInt(1, 2);
    std::cout << paraInt.getDrugiObiekt() << std::endl;

    Para< double > paraDouble(1.1, 2.2);
    std::cout << paraDouble.getPierwszyObiekt() << std::endl;

    std::cout << paraInt.suma() << std::endl;
    std::cout << paraDouble.suma() << std::endl;
}

/* Po uruchomieniu otrzymano:
  2
  1.1
  3
  3.3
*/