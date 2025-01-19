
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int token() {
    // Initialize the random number generator with the current time
    srand(time(NULL));
    
    // Generate a random number between 1000000000 and 9999999999
    long long random_number = (long long)rand() * 1000000000LL + (rand() % 1000000000LL);
    
    // Ensure the number is 10 digits
    if (random_number < 1000000000LL) {
        random_number += 1000000000LL;
    } //else if (random_number > 9999999999LL) 
    //   //{ // random_number = 999;}
        return random_number;
      
}
 