#include <stdio.h>
#include <stdlib.h>

/*header of the functions*/
int enter_values (int *tab,int n);
int chekIfIsPowerOfTwo(int n);
int printIfPowerOfTwo(const int *array,int sum,int n);

/*this program receives a list from the user and prints the numbers from the list which are power of 2.
then it prints the sum of all the exponents of the numbers displays*/
int main(){
    int n;
    printf("Enter size of input:\n");
    scanf("%d",&n);
    if (n>0){
        printf("Enter numbers:\n");
        int *array=NULL;  //array initialization
        array=malloc(n*sizeof(*array)); //dynamic allocation of array
        if(array==NULL){
            return 0; //verify if the allocation worked well
        }
        if (enter_values(array,n)){ //enter the value in the tab and if it failed because of wrong input user stop
            return 0;
        }
        int sum=0;
        sum=printIfPowerOfTwo(array,sum,n);
        printf("Total exponent sum is %d\n",sum);
        free(array);
    }
    else{
        // case the input for the size of tab is smaller than 0
        printf("Invalid size\n");
        return 0;
    }
}

/*this function asks the user to enter integer values in a list(parameter int *array) of size n(parameter n)
 returns 1 if the function failed(the user has written a letter instead of a number)
 return 0 if the user successfully completed the list*/
int enter_values (int *array,int n){
    int i;
    for (i=0;i<n;i+=1)
    {
        if ((scanf("%d",(array+i)))!=1) //get an integer from the user and check if the input is an integer or something else.
        {
            printf("Invalid number\n");
            return -1;// in case that the input is false (the user wrote something different from an integer)
        }
    }
    return 0; // the list correctly completed by the user
}
/*this function check if a number is a power of 2
 if it is the function return the power of 2
 if it's not the function return -1*/
int chekIfIsPowerOfTwo(int n){
    if (n==0 ){
        return -1;
    }
    int counter=0;
    if (n==1){
        return 0;// because 2 power 0 = 1
    }
    while(n!=1)
        if (n%2==0){
            counter++;
            n/=2; //divide the number per 2 k times until n==1 or n not a multiple of 2
        }
        else{
            return -1;// in the case that the number is not a power of 2
        }
    return counter; // this is the exposant
}
/*this function receive the pointer on array(int *array),the sum(sum), and the lengh of the array(n)
pass over all the values in the array
if a value is a power of 2: print the exponent
add the exponent to the total sum and return the sum*/
int printIfPowerOfTwo(const int *array,int sum,int n){
    int i;
    for (i=0;i<n;i+=1){
        int exposant=chekIfIsPowerOfTwo(*(array+i)); //the value is the exposent if the number tab[i] is a power of 2
        if (exposant!=-1){                       //and -1 if the number is not a power of 2
            printf("The number %d is a power of 2: %d = 2^%d\n",*(array+i),*(array+i),exposant);
            sum+=exposant;
        }
    }
    return sum;
}
