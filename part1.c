#include <stdio.h>
#include <stdlib.h>

int get_size();
int check_power_two( int x);
int get_nums(int nums[] , int size);
void validate_nums(int nums[] , int size_input);


int main() {

// getting size of input
    int size_input = 0;
    size_input = get_size() ;
    if (size_input == -1 ) return 0 ;

// getting the numbers
    int *nums = (int*)malloc(sizeof(int)*size_input);
    if (nums == NULL) printf("Error occured");
    for (int i=0 ; i<size_input ; i++) nums[i]=0 ;
    if( get_nums( nums , size_input) == -1 ) return 0;

//checking which numbers are power of 2
    validate_nums(nums , size_input);

    free(nums);

    return 0 ;


}

int get_size(){

    int size_input = 0;
    printf("Enter size of input:\n");
    if(scanf("%d", &size_input) != 1){
        printf("Invalid size");
        return -1 ;
    }
    //checking if input is valid
    if( size_input <= 0){
        printf("Invalid size");
        return -1 ;
    }
    return size_input;
}

int check_power_two( int x){

    int j=0 ;
    int two_power_j = 1 ;

   while ( two_power_j < x){
       two_power_j = 2*two_power_j ;
       j++;
   }

   // x=2^j return j
   if(x==two_power_j) return j;
   // x != 2^j return error
   return -1;
}

int get_nums(int nums[] , int size){

    printf("Enter numbers:\n");

    for( int i=0 ; i < size ; i++) {
        if ( !scanf("%d", &nums[i]) ) {
            printf("Invalid number");
            return -1;
        }
    }

    return 0;
}

void validate_nums(int nums[] , int size_input){

    int sum_of_exp = 0;

    for ( int i=0 ; i < size_input ; i++){
        int exp=check_power_two(nums[i]);
        if( exp != -1) {
            printf( "The number %d is a power of 2: %d = 2^%d\n" , nums[i] , nums[i] , exp );
            sum_of_exp+=exp;
        }
    }

    printf("Total exponent sum is %d" , sum_of_exp);

}
