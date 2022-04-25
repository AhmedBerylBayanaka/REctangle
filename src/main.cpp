#include <iostream>
#include "include/rectangle.hpp"

using namespace std;


int main()
{
    persegiPanjang pP_1 (6.0, 3.0, 8.0, 4.0);
    persegiPanjang pP_2 (10, 5, 8, 4);

    persegiPanjang pP_3(0,0,0,0);
    pP_3 = pP_1 + pP_2;

    pP_1[1];

    return 0;
}
