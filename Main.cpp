#include <iostream>
#include "Polinom.h"
#include "Ednochlen.h"

int main()
{
    Ednochlen a[2] = { {7,5}, {3,2} };
    Polinom b(2, a);
    b.print();
    std::cout << std::endl;


    /*Ednochlen c = { 3,5 };
    b -= c;
    b.print();
    std::cout << std::endl;

    Ednochlen d = { 3,3 };
    b -= d;
    b.print();
    std::cout << std::endl;*/

    /*Polinom e = b + d;
    e.print();*/

    double g = b(2);
    std::cout << g;


}