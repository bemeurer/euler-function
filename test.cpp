#include "totient.hpp"
#include <iostream>

int main(void)
{
    mpz_class a;
    a = "-195349285623987465324987562398476";
    std::cout << phi(1).get_str(10) << "\n";
    std::cout << phi(2).get_str(10) << "\n";
    std::cout << phi(3).get_str(10) << "\n";
    std::cout << phi(4).get_str(10) << "\n";
    std::cout << phi(5).get_str(10) << "\n";
    std::cout << phi(6).get_str(10) << "\n";
    //std::cout << phi(a).get_str(10) << "\n";
}