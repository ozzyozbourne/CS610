#include <stdlib.h>

float factorial(int);

main(void) {
    int number;
    cout << "Enter a number" << ENDL;
    cin >> number;
    cout << "The factorial is -> " << factorial(number) <<ENDL;
}

float factorial(const int number){
    int i = 1;
    float res = 1.0;
    for(; i <= number; i++ ) res = res * i;
    return res;
}

