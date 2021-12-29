#include <stdio.h>
#include "typedef.h"

/*
Functions Declaration
*/
uint8_t IsSorted(uint32_t *arr , uint8_t arr_size);
void swap( uint32_t *xp, uint32_t *yp);
void BubbleSort(uint32_t *arr , uint8_t arr_size);
sint8_t binarySearch(uint32_t *arr , uint8_t size , uint32_t number);

void main()
{
    uint32_t arr[]={1,8,3,2,9};

    printf("Test case searching for 2 in the given array:");
    for(int i=0;i<5;i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n the index of %d after sorted: %d\n",2,binarySearch(arr,5,2));


}



/*
    IsSorted Function check the array sorted or not
    return 1 if sorted and 0 if not
    Input: array of u32 , size or array
    Output: u8 1 if sorted and 0 if not sorted
*/
uint8_t IsSorted(uint32_t *arr , uint8_t arr_size)
{
    uint8_t index;
    for(index=0;index<arr_size-1;index++)
    {
        if(arr[index]>arr[index+1])
        {
            return 0;
        }
    }
    return 1;
}

/*
    swap function takes 2 pointers to u32 and swap them
    Input: pointer1 , pointer2
    Output: void
*/
void swap( uint32_t *xp, uint32_t *yp)
{
    uint32_t u8_temp=*xp;
            *xp=*yp;
            *yp=u8_temp;
}


/*
    BubbleSort function that arrange array of u32 in ascending order
    Input: array of u32 , array size
    Output: void
*/
void BubbleSort(uint32_t *arr , uint8_t arr_size)
{
    uint8_t local_index;
    uint16_t local_index2;
    for(local_index=0;local_index<arr_size-1;local_index++)
    {
        for(local_index2=0;local_index2<arr_size-local_index-1;local_index2++)
        {
            if(arr[local_index2]>arr[local_index2+1])
            {
                swap(&arr[local_index2],&arr[local_index2+1]);
            }
        }
    }

}

/*
    binary Search function to search for a number in a given array of u32
    Inputs: array of u32 , array size , number you want to check
    Output: Index of the number in the array if found and -1 if not found
*/
sint8_t binarySearch(uint32_t *arr , uint8_t size , uint32_t number)
{
    uint8_t u8_low =0 ,u8_high = size-1,u8_mid;
    if(IsSorted(arr,size))
    {
    }
    else
        BubbleSort(arr,size);
    while(u8_low<=u8_high)
    {

        u8_mid=(u8_high+u8_low)/2;
        if(number == arr[u8_mid])
        {
            return u8_mid;
        }
        else if(number <arr[u8_mid])
        {
            u8_high = u8_mid-1;
        }
        else if(number >arr[u8_mid])
        {
            u8_low = u8_mid+1;
        }
    }

    return -1;
}


