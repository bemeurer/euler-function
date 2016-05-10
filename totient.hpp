#include <primesieve.hpp>
#include <gmpxx.h>


mpz_class phi(mpz_class x){
    if(mpz_cmp_d(x.get_mpz_t(), 0) < 0){
        x*= -1;
    }
    if (x == 0){
        return 0;
    }
    if (mpz_cmp_d(x.get_mpz_t(), 2) <= 0){
        return 1;
    }
    if (mpz_probab_prime_p(x.get_mpz_t(), 50))
    {
        x -= 1;
        return x;
    }
    if(mpz_even_p(x.get_mpz_t())){
        mpz_class y = x;
        y /= 2;
        if(mpz_even_p(y.get_mpz_t())){
            x = phi(y);
            x *= 2;
            return x;
        }
        return phi(y);
    }
    primesieve::iterator pi;
    mpz_class prime;
    mpz_class sqrtx;
    mpz_sqrt(sqrtx.get_mpz_t(), x.get_mpz_t());
    for (prime = pi.next_prime();mpz_cmp ; prime =pi.next_prime())
    {//prime <= sqrtx
        mpz_class k = prime;
        if(! mpz_divisible_p(x.get_mpz_t(), k.get_mpz_t()))
        {
            continue;
        }
        mpz_class o;
        mpz_div(o.get_mpz_t(), x.get_mpz_t(), k.get_mpz_t());
        mpz_class d = gcd(k, o);
        if (d ==1){
            mpz_mul(x.get_mpz_t(), phi(k).get_mpz_t(), phi(o).get_mpz_t());
            return (x);
        }else{
            mpz_mul(x.get_mpz_t(), phi(k).get_mpz_t(), phi(o).get_mpz_t());
            mpz_class z;
            mpz_div(z.get_mpz_t(), x.get_mpz_t(), phi(d).get_mpz_t());
            return(z);
        }
    }
}


/*

    primesieve::iterator pi;
    cpp_int prime;
    std::cout << "Starting prime loop\n";
    for (prime = pi.next_prime(); prime <= boost::multiprecision::sqrt(x); prime=pi.next_prime())
    {
        cpp_int k = prime;
        if (x % k) continue;
        cpp_int o = x/k;
        cpp_int d = boost::math::gcd(k, o);
        if (d == 1) {
            return phi(k) * phi(o);
        }
        return phi(k) * phi(o) * d / phi(d);
    }
}*/