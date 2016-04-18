# Arbitrary precision Euler's Totient in C++

This is a **very** fast implementation of
[Euler's Totient Function](https://en.wikipedia.org/wiki/Euler%27s_totient_function)
using C++, Boost, and Primesieve.

## Dependencies
* [primesieve](http://primesieve.org) - Fast prime generation
* [Boost](http://boost.org) - Primality test and arbitrary precision

## Usage
Simply `#include "totient.h"` in your code.

## TODO
* Use GMP instead of cpp_int
* Use Baillie-PSW for primality instead of Miller-Rabin
* Generate primes using multithreading
