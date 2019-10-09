#include<stdio.h>
display_fibonacci( &array_hold_variable ,&fiboNumber);
int main(){
int fiboNumber,i;
printf("please enter the  number you want to find fibonacci\n");
scanf("%d",&fiboNumber);
int array_hold_variable[fiboNumber];
for(i=0;i<fiboNumber;i++)
{
if(i<=1){

array_hold_variable[i]=i;
}

else{
array_hold_variable[i]=array_hold_variable[i-1]+array_hold_variable[i-2];
}
}


display_fibonacci( &array_hold_variable ,&fiboNumber);

}

display_fibonacci( int *array_hold_variable[] ,int *num_of_terms){
int counter;
for(counter=0;counter<*num_of_terms;counter++){
printf(" %d ",*(array_hold_variable+counter));
}
}



