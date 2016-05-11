#include "totient.hpp"
#include <iostream>

int main(void) {
    mpz_class foo;
    foo = "-195349285623987465324987562398476";
    for (int a = 0; a <= 100; a++) {
        //std::cout << phi(a).get_str(10) << "\n";
    }
    std::cout << phi(foo).get_str(10) << "\n";
}