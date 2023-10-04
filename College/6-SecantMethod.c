// Secant method
// this method gives the fastest roots and 

#include<stdio.h>
#include<math.h>

float f(float x)
{
    return (pow(x,3) - 5*x + 1);
}

int main(){
    float x0, x1, x2,e;
    int flag = 1, itr;
    do{
        printf("Enter the value of x0, x1 : ");
        scanf("%f %f",&x0, &x1);
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
        x2 = x1 - ((x1-x0)/(f(x1)-f(x0)))*f(x1);
        x0 = x1;
        x1 = x2;
        itr++;
        printf("Iteration %d: x = %f\n",itr,x2);
    }while(fabs(f(x2)) > e);

    printf("The root of the equation after %d iterations is %f\n",itr, x2);
    return 0;
    

}