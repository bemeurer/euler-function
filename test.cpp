#include <iostream>
#include <unistd.h>
#include "csv.hpp"
#include "totient.hpp"
#include "test_extras.hpp"

class Test {
public:

    static bool passed;

    static void eval(bool (Test::*test)(bool), Test &testClass, std::string name, bool verbose);

    bool numeric(mpz_class x, mpz_class y, int n = 50, bool verbose = true);

    bool range(bool verbose);

    bool largeNumber(bool verbose);

};

bool Test::passed = true;

void Test::eval(bool (Test::*test)(bool), Test &testClass, std::string name, bool verbose) {
    if ((testClass.*test)(verbose)) {
        std::cout << color::green << name << " Test OK\n";
    }
    else {
        Test::passed = false;
        std::cout << color::red << name << " Test Failed\n";
    }
}

bool Test::numeric(mpz_class x, mpz_class y, int n, bool verbose) {
    mpz_class phi_res;
    bool res = true;
    for (int z = 1; z <= n; z++) {
        phi_res = phi(x);
        res = (phi_res == y);
    }
    if (verbose) {
        if (res) {
            std::cout << color::green << "----phi(" << x.get_str(10) << ") = " << phi_res.get_str(10) << "\n";
        }
        else {
            std::cout << color::red << "----phi(" << x.get_str(10) << ") = " << phi_res.get_str(10) << "\n";
        }
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
        if (Test::numeric(n, phi, 10, verbose)) {
        }
        else {
            passed = false;
        }
    }
    return passed;
}

bool Test::largeNumber(bool verbose) {
    bool passed = true;
    std::vector<std::vector<mpz_class>> pairs = // Vector or Array? Dan says array but vector has cool features
            {
                    {mpz_class("985763284578345834"),                      mpz_class("298498582277498400")},
                    //{mpz_class("43649128734981236498122387"),              mpz_class("43248678012493665314544000")}, //XXX: This one takes a while, why?
                    {mpz_class("98576328457834581423412342334"),           mpz_class("45827308937045311626868162560")},
                    {mpz_class("958324857389475983274569823476558973245"), mpz_class(
                            "644667608743795154660944983332241662208")}
            };

    for (auto const &v: pairs) { // XXX: Better way to do this?
        if (Test::numeric(v[0], v[1], 1, verbose)) {
        }
        else {
            passed = false;
        }
    }
    return passed;
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
    return Test::passed;
}