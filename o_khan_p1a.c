#include <stdlib.h>
 
int normal_summation(int);
int gauss_summation(int);

main(void){
    /* const int res1 = normal_summation(100); */ 
    const int res2 = gauss_summation(100); 
    /* cout << "The sum upto 100 using normal method is -> " << res1 << ENDL; */
    cout << "The sum upto 100 using gauss method is -> " << res2 << ENDL;
}

int normal_summation(const int number){
    int sum = 0, iter = 1;
    for(; iter <= number; iter++) sum = sum + iter;
    return sum;
}

int gauss_summation(const int number){
    return ((number + 1) * number ) / 2;
}

