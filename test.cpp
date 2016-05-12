#include <iostream>
#include "csv.hpp"
#include "totient.hpp"
#include "rlutil.h"
bool test(mpz_class x, mpz_class y, int n = 50);

bool rangeTest(bool verbose);

int main(int argc, char* argv[])
{





    if (rangeTest(false))
    {
        rlutil::setColor(rlutil::GREEN);
        std::cout << "phi(0) - phi(500) | OK\n";
    }
    else
    {
        rlutil::setColor(rlutil::RED);
        std::cout << "phi(0) - phi(500) | FAIL\n";
    }
}

bool test(mpz_class x, mpz_class y, int n)
{
    bool res = true;
    for (int z = 1; z <= n; z++)
    {
        res = (phi(x) == y);
    }
    return res;
}

bool rangeTest(bool verbose)
{
    bool passed = true;
    io::CSVReader<2> in("phi_results.csv");
    in.read_header(io::ignore_extra_column, "n", "phi");
    int n;
    int phi;
    while (in.read_row(n, phi))
    {
        if (test(n, phi, 10))
        {
            if (verbose)
            {
                std::cout << "phi(" << n << ") = " << phi << " | OK\n";
            }
        }
        else {
            if (verbose)
            {
                std::cout << "phi(" << n << ") = " << phi << " | FALSE\n";
            }
            passed = false;
        }
    }
    return true;
}