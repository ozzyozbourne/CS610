#include <stdlib.h>

float factorial(int);

main(void) {
    cout.precision(10);
    int number;  
     
    cout << "Enter a positive number to find factorial" << ENDL;
    cin >> number;
    
    const float res = factorial(number);
    cout <<"The factorial is -> "<< res <<ENDL; 
}

float factorial(const int number){
    int i; 
    float res = 1.0;
    for(i = 1; i <= number; i++ ) res = res * i;
    return res; 
}

