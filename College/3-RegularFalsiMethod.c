/*

formula -> x= x0 - ((x1-x0)/(f(x1)-f(x0)))*f(x0)
same as Bisection Menthod only formula is changed

* this method is faster than Bisection Method

take a equation in form of sin cos log 
for written -> same code different output 

*/

#include<stdio.h>
#include<math.h>

float f(float x)
{
    return sin(x) - log(x) + cos(x);
}

int main(){
    float x0, x1, x,e;
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
        x = x0 - ((x1-x0)/(f(x1)-f(x0)))*f(x0);
        if(f(x0)*f(x) < 0){
            x1 = x;
        }
        else{
            x0 = x;
        }
        itr++;
        printf("Iteration %d: x = %f\n",itr,x);
    }while(fabs(f(x)) > e);

    printf("The root of the equation after %d iterations is %f\n",itr, x);
    return 0;
    

}

