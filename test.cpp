#include <iostream>
#include "csv.hpp"
#include "totient.hpp"

bool test(mpz_class x, mpz_class y, int n = 50);

bool rangeTest(bool verbose);

int main(void) {
    if (rangeTest(false)) {
        std::cout << "phi(0) - phi(500) | OK";
    }
}

bool test(mpz_class x, mpz_class y, int n) {
    bool res = true;
    for (int z = 1; z <= n; z++) {
        res = (phi(x) == y);
    }
    return (res);
}

bool rangeTest(bool verbose) {
    bool passed = true;
    io::CSVReader<2> in("phi_results.csv");
    in.read_header(io::ignore_extra_column, "n", "phi");
    int n;
    int phi;
    while (in.read_row(n, phi)) {
        if (test(n, phi, 10)) {
            if (verbose) {
                std::cout << "phi(" << n << ") = " << phi << " | OK\n";
            }
        }
        else {
            if (verbose) {
                std::cout << "phi(" << n << ") = " << phi << " | FALSE\n";
            }
            passed = false;
        }
    }
    return (passed);
}