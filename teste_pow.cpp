#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>

using namespace std;

int main()
{    
    int base = 10;
    unsigned long exp = 5;

    int power = pow(base, exp);
    
    cout << power << endl;
    
    return 0;
}