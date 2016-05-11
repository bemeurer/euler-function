#include <primesieve.hpp>
#include <gmpxx.h>


mpz_class phi(mpz_class x) {
    // Just invert if negative
    if (mpz_cmp_d(x.get_mpz_t(), 0) < 0) {
        x *= -1;
    }

    // Definition
    if (x == 0) {
        return 0;
    }

    // phi(1), phi(2) = 1
    if (mpz_cmp_d(x.get_mpz_t(), 2) <= 0) {
        return 1;
    }

    // Lehmer's conjecture
    if (mpz_probab_prime_p(x.get_mpz_t(), 50)) {
        x -= 1;
        return x;
    }
    // Even number?
    if (mpz_even_p(x.get_mpz_t())) {
        mpz_class y = x;
        y /= 2;
        if (mpz_even_p(y.get_mpz_t())) {
            x = phi(y);
            x *= 2;
            return x;
        }
        return phi(y);
    }
    // For all primes smaller than n
    primesieve::iterator pi;
    mpz_class prime;
    mpz_class sqrtx;
    mpz_sqrt(sqrtx.get_mpz_t(), x.get_mpz_t());
    for (prime = pi.next_prime(); mpz_cmp; prime = pi.next_prime()) {
        mpz_class k = prime;
        // Check if k is a factor
        if (!mpz_divisible_p(x.get_mpz_t(), k.get_mpz_t())) {
            continue;
        }
        mpz_class o;
        mpz_div(o.get_mpz_t(), x.get_mpz_t(), k.get_mpz_t());
        mpz_class d = gcd(k, o);
        if (d == 1) {
            mpz_mul(x.get_mpz_t(), phi(k).get_mpz_t(), phi(o).get_mpz_t());
            return (x);
        } else {
            mpz_mul(x.get_mpz_t(), phi(k).get_mpz_t(), phi(o).get_mpz_t());
            mpz_class z;
            mpz_div(z.get_mpz_t(), x.get_mpz_t(), phi(d).get_mpz_t());
            return (z);
        }
    }

}