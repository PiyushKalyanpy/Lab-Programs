#include <stdio.h>
#include <math.h>

// Newton Raphson Method is the best Method to find the root of the equation

float f(float x){
    return x*x*x - 5*x + 1;
}

float df(float x){
    return 3*x*x - 5;
}

int main(){
    float x0, e; // take any value of x0 between 0 and 1
    printf("Enter x and error : ");
    scanf("%f %f",&x0, &e);

    float x = x0;
    int itr=0;

    while(fabs(f(x))>e){
        if(df(x)==0){
            printf("Method Failed ! ");
            return 1;
        }

        x=x-(f(x)/df(x));
        itr++;

        printf("Value at iteration : %d is %f\n", itr, x);
    }
    
    printf("Approximate root after %d iterations: %f\n", itr, x);

    return 0;
}


