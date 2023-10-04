/*
Algorithm

1. Take two initial values x0 and x1 such that f(x0)*f(x1) < 0, i.e., f(x0) and f(x1) have opposite signs.
2. Bisect [x0, x1] to get x, i.e., x = (x0 + x1)/2
3. If f(x0)*f(x) < 0, then root lies in [x0, x] and assign x1 = x, go to step 2
4. Else root lies in [x, x1] and assign x0 = x, go to step 2
5. To stop the procedure on basis of iterations or given specified/ allowed errror (0.001, 0.0001, 0.00001).
6. Print the value of root as (x0 + x1)/2

we get roots in x
f(x) = x^3-5x+1 = 0

*/

#include<stdio.h>
#include<math.h>

float f(float x)
{
    return (pow(x,3) - 4*x -9);
}

int main(){
    float x0, x1, x2,e;
    int flag = 1, itr;
    do{
        printf("Enter the value of x0, x1, allowed error and maximum iterations: ");
        scanf("%f %f",&x0, &x1 );
        if(f(x0)*f(x1) > 0.0){
            printf("Incorrect Initial Guesses.\n");
            flag = 0;
        }
        else{
            flag = 1;
        }
    }while(flag == 0);

    printf("Enter the allowed error: ");
    scanf("%f",&e);
    
    do{
        x2 = (x0 + x1)/2;
        if(f(x0)*f(x2) < 0){
            x1 = x2;
        }
        else{
            x0 = x2;
        }
        itr++;
        printf("Iteration %d: x = %f\n",itr,x2);
    }while(fabs(f(x2)) > e);

    printf("The root of the equation after %d iterations is %f\n",itr, x2);
    return 0;
    

}