#include <iostream>
#include <primesieve.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/miller_rabin.hpp>
#include <boost/math/common_factor.hpp>


using namespace boost::multiprecision;

cpp_int phi(const cpp_int x) {
    if (x == 1) {
        return 1;
    }
    if (miller_rabin_test(x, 50)) {
        return x-1;
    }
    if (x % 2 == 0){
        cpp_int y = x >> 1;
        return !(y & 1) ? phi(y)<<1 : phi(y);
    }
    primesieve::iterator pi;
    cpp_int prime;
    for (prime = pi.next_prime(); prime < x; prime=pi.next_prime())
    {
        cpp_int k = prime; // Kaput
        if (x % k) continue;
        cpp_int o = x/k;
        cpp_int d = boost::math::gcd(k, o);
        return d == 1 ? phi(k)*phi(o) : phi(k)*phi(o)*d/phi(d); // Kaput
    }
}

int main(void) {
    cpp_int small = 99;
    cpp_int large = 756928375693284658;
    std::cout << phi(small);
    return 0;
}
