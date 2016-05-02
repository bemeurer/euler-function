#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EulerTest
#include <iostream>
#include <boost/test/unit_test.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include "totient.hpp"
using namespace boost::multiprecision::literals;
BOOST_AUTO_TEST_SUITE(euler_suite)

BOOST_AUTO_TEST_CASE(Test1)
{
    // Testing known values from -10 to 10
    BOOST_REQUIRE_EQUAL(phi(-0xA_cppi), 0x4_cppi); //phi(-10) == 4
    BOOST_REQUIRE_EQUAL(phi(-0x9_cppi), 0x6_cppi); //phi(-9) == 6
    BOOST_REQUIRE_EQUAL(phi(-0x8_cppi), 0x4_cppi); //phi(-8) == 4
    BOOST_REQUIRE_EQUAL(phi(-0x7_cppi), 0x6_cppi); //phi(-7) == 6
    BOOST_REQUIRE_EQUAL(phi(-0x6_cppi), 0x2_cppi); //phi(-6) == 2
    BOOST_REQUIRE_EQUAL(phi(-0x5_cppi), 0x4_cppi); //phi(-5) == 4
    BOOST_REQUIRE_EQUAL(phi(-0x4_cppi), 0x2_cppi); //phi(-4) == 2
    BOOST_REQUIRE_EQUAL(phi(-0x3_cppi), 0x2_cppi); //phi(-3) == 2
    BOOST_REQUIRE_EQUAL(phi(-0x2_cppi), 0x1_cppi); //phi(-2) == 1
    BOOST_REQUIRE_EQUAL(phi(-0x1_cppi),0x1_cppi); //phi(-1) == 1
    BOOST_REQUIRE_EQUAL(phi(0x0_cppi), 0x0_cppi); //phi(0) == 0
    BOOST_REQUIRE_EQUAL(phi(0x1_cppi), 0x1_cppi); //phi(1) == 1
    BOOST_REQUIRE_EQUAL(phi(0x2_cppi), 0x1_cppi); //phi(2) == 1
    BOOST_REQUIRE_EQUAL(phi(0x3_cppi), 0x2_cppi); //phi(3) == 2
    BOOST_REQUIRE_EQUAL(phi(0x4_cppi), 0x2_cppi); //phi(4) == 2
    BOOST_REQUIRE_EQUAL(phi(0x5_cppi), 0x4_cppi); //phi(5) == 4
    BOOST_REQUIRE_EQUAL(phi(0x6_cppi), 0x2_cppi); //phi(6) == 2
    BOOST_REQUIRE_EQUAL(phi(0x7_cppi), 0x6_cppi); //phi(7) == 6
    BOOST_REQUIRE_EQUAL(phi(0x8_cppi), 0x4_cppi); //phi(8) == 4
    BOOST_REQUIRE_EQUAL(phi(0x9_cppi), 0x6_cppi); //phi(9) == 6
    BOOST_REQUIRE_EQUAL(phi(0xA_cppi), 0x4_cppi); //phi(10) == 4

    //Testing some awkwardly specific values
    BOOST_REQUIRE_EQUAL(phi(0x1D6B4_cppi), 0xBB80_cppi); //phi(120500) == 48000
    BOOST_REQUIRE_EQUAL(phi(0x6B37_cppi), 0x3D38_cppi); //phi(27447) == 15672

    //Test a very large even number
    BOOST_REQUIRE_EQUAL(phi(0x7B5C27EBB069E210ADA7B445E2F4C4E437F0FB27582BF975033AE2E2140399534_cppi),0x283DEB1F4A1D02D20566156741FEAE4423F908532E8D800A72341770878408280_cppi);

    //Test a very large odd number
    //BOOST_REQUIRE_EQUAL(phi(0x429F025FCAEBB19194130352AAFF5AE2335F25B95C112DEDC2163A0E55E8ED481_cppi), 0x391A6EEB10B111133F943FC987453F7B2076B70F564DBCB6CC955106616A40A00_cppi);

    //Test a very large prime number
    BOOST_REQUIRE_EQUAL(phi(0x1CCA2D61C8B9093F473C1FA8E3C7C654A8A66B1626DA78D234292117DD7D46A41_cppi), 0x1CCA2D61C8B9093F473C1FA8E3C7C654A8A66B1626DA78D234292117DD7D46A40_cppi);
}
BOOST_AUTO_TEST_SUITE_END()