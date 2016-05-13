#include <iostream>
#include <unistd.h>
#include "csv.hpp"
#include "totient.hpp"
#include "rlutil.h"

class Test {
public:
    bool numeric(mpz_class x, mpz_class y, int n = 50);

    bool range(bool verbose);

    bool largeNumber(bool verbose);

    static void eval(bool (Test::*test)(bool), Test &testClass, std::string name, bool verbose);
};

bool Test::numeric(mpz_class x, mpz_class y, int n) {
    bool res = true;
    for (int z = 1; z <= n; z++) {
        res = (phi(x) == y);
    }
    return res;
}

bool Test::range(bool verbose) {
    bool passed = true;
    io::CSVReader<2> in("phi_results.csv");
    in.read_header(io::ignore_extra_column, "n", "phi");
    int n;
    int phi;
    while (in.read_row(n, phi)) {
        if (Test::numeric(n, phi, 10)) {
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
    return passed;
}

bool Test::largeNumber(bool verbose) {
    bool passed = true;
    mpz_class pairs[10][10] = {{mpz_class("985763284578345834"),            mpz_class("298498582277498400")},
                               {mpz_class("98576328457834581423412342334"), mpz_class(
                                       "45827308937045311626868162560")}};
    if (Test::numeric(pairs[0][0], pairs[0][1], 1)) {
        if (verbose) {
            std::cout << "phi(" << pairs[0][0].get_str(10) << ") = " << pairs[0][1].get_str(10) << " | OK\n";
        }
        else {
            std::cout << "phi(" << pairs[0][0].get_str(10) << ") = " << pairs[0][1].get_str(10) << " | FALSE\n";
            passed = false;
        }
    }
    return passed;
}

void Test::eval(bool (Test::*test)(bool), Test &testClass, std::string name, bool verbose) {
    if ((testClass.*test)(verbose)) {
        rlutil::setColor(rlutil::GREEN);
        std::cout << name << " Test OK\n";
    }
    else {
        rlutil::setColor(rlutil::RED);
        std::cout << name << " Test Failed\n";
    }
}
int main(int argc, char* argv[])
{
    int opt;
    opterr = 0;
    bool verbose = false;
    while ((opt = getopt(argc, argv, "vt:")) != -1)
    {
        switch (opt) {
            case 'v':
                verbose = true;
                break;
            case 't':
                Test tClass;
                switch (optarg[0]) {
                    case 'r':
                        Test::eval(&Test::range, tClass, "Range", verbose);
                        break;
                    case 'l':
                        Test::eval(&Test::largeNumber, tClass, "Large Number", verbose);
                        break;
                    default:
                        Test::eval(&Test::range, tClass, "Range", verbose);
                        Test::eval(&Test::largeNumber, tClass, "Large Number", verbose);
                        break;
                }
                break;
            default:
                std::cerr << "Unknown option '" << char(opt) << "'\n";
                break;
        }
    }
}