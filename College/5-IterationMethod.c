#include <stdio.h>
#include <math.h>

float f(float x){
    return cos(x) - 3 * x + 1;
}

float fix(float x){
    return (1.0 / 3.0) * (cos(x) + 1); // Fixed-point iteration formula
}

float df(float x){
    return -sin(x) - 3;
}

int main(){
    float x0, e; 
    printf("Enter x and error : ");
    scanf("%f %f",&x0, &e);

    float x = x0;
    int itr = 0;

    while(fabs(f(x)) > e){
        if(fabs(df(x)) < 1){ // Check if the derivative is too close to zero
            printf("Change the value of x\n");
            return 1;
        }

        x = fix(x); // Use the fixed-point iteration formula
        itr++;

        printf("Value at iteration %d is %f\n", itr, x);
    }

    printf("Approximate root: %f\n", x);
    return 0;
}
