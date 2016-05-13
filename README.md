# Arbitrary precision Euler's Totient in C++

This is a **very** fast implementation of
[Euler's Totient Function](https://en.wikipedia.org/wiki/Euler%27s_totient_function)
using C++, GMP, and Primesieve. Arbitrary precision functionality is still on
 the works, it's tricky to implement and buffer overflows are a constant
 nuisance . This drinks **heavily** from
 [clarsen](https://github.com/cslarsen)'s design, but aims to improve it for
 the particular purpose of arbitrary precision.

## Dependencies

*   [primesieve](http://primesieve.org) - Fast prime generation
*   [GMP](http://gmplib.org) - Arbitrary precision

## Usage

Simply `#include "totient.hpp"` in your code.

## TODO

*   Use GMP instead of cpp_int :white_check_mark:
*   Use Baillie-PSW for primality instead of Miller-Rabin :clock4:
*   Generate primes using multithreading :x:
*   Re-write prime generator to use arbitrary precision :x:

<sub>:white_check_mark: - Done, :clock4: - On the works,  :x: - To do</sub>
