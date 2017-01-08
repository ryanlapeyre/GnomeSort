#include <stdio.h>
#include <time.h>
#include <stdio.h>
#include <ctype.h> 
#include <stdlib.h>
#include <stdbool.h> 
#define SORTSIZE 8
#define RANDOMRANGE 10
void GnomeSort2DimensionalArray(int[][SORTSIZE]);
void GnomeSortPointers(int*);
void GnomeSortArray(int[]);
void RandomizeArray(int[]);
void RandomizePointer(int*);
void Randomize2DimensionalArray(int[][SORTSIZE]);
void PrintArray(int[]);
void PrintPointer(int*);
void Print2DimensionalArray(int[][SORTSIZE]);
int main (void)
{
    srand(time(NULL)); 
    //Array Sort
    int arrayElements [SORTSIZE] = {0};
    puts("");
    RandomizeArray(arrayElements);
    puts("One Dimensional Array Elements (least to greatest)");
    PrintArray(arrayElements);
    GnomeSortArray(arrayElements);
    PrintArray(arrayElements);
    puts("");
    //Pointer Sort
    int* pointerElements = malloc(sizeof(int)*SORTSIZE);
    RandomizePointer(pointerElements);
    puts("One Dimensional Pointer Elements (greatest to least)");
    PrintPointer(pointerElements);
    GnomeSortPointers(pointerElements);
    PrintPointer(pointerElements);
    free(pointerElements);
    puts("");
    //2Dimensional Array Sort
    int arrayElements2Dimensional[SORTSIZE][SORTSIZE] = {{0}};
    Randomize2DimensionalArray(arrayElements2Dimensional);
    puts("Two Dimensional Array Elements (least to greatest)");
    Print2DimensionalArray(arrayElements2Dimensional);
    GnomeSort2DimensionalArray(arrayElements2Dimensional);
    Print2DimensionalArray(arrayElements2Dimensional);
    puts("");
    return 1;
}


void GnomeSort2DimensionalArray(int arrayElements2Dimensional[][SORTSIZE] )
{
    int gnomeCounter = 0;
    int spareItem = 0;
    int rowCounter = 0;
    for(rowCounter = 0; rowCounter < SORTSIZE; rowCounter++)
    {
        gnomeCounter = 0;
        while(gnomeCounter < SORTSIZE)
        {
            if(gnomeCounter == 0 ||  arrayElements2Dimensional[rowCounter][gnomeCounter] >= arrayElements2Dimensional[rowCounter][gnomeCounter - 1])
            {
                //Sort comparison is the SAME. This means this sort will organize our items from least to greatest.
                //AKA it follows the comparison symbol, unlike most sorts.
                gnomeCounter += 1;
            }
            else //Otherwise, we swap the items and keep stepping backwards until that item is in the correct spot.
            {
                spareItem = arrayElements2Dimensional[rowCounter][gnomeCounter - 1];
                arrayElements2Dimensional[rowCounter][gnomeCounter - 1] = arrayElements2Dimensional[rowCounter][gnomeCounter];
                arrayElements2Dimensional[rowCounter][gnomeCounter] = spareItem;
                gnomeCounter -= 1;
                // the gnome is stepping through his potted plants ;)
            }
        }
    }
    return;
}
void GnomeSortPointers(int* pointerElements)
{
    int gnomeCounter = 0;
    int spareItem = 0;
    while(gnomeCounter < SORTSIZE)
        if(gnomeCounter == 0 ||  * (pointerElements + gnomeCounter  ) <=  *( pointerElements + gnomeCounter - 1 ) )
        {    
            //Sort will be organized from biggest to smallest AKA it follows the comparison operator.
            gnomeCounter += 1;
        }
        else
        {
            spareItem = *( pointerElements + gnomeCounter - 1 );
            *(pointerElements + gnomeCounter - 1 ) = * (pointerElements + gnomeCounter);
            *(pointerElements + gnomeCounter) = spareItem;
            gnomeCounter -= 1;
        }
    return;
}
void GnomeSortArray(int arrayElements[])
{
    int gnomeCounter = 0;
    int spareItem = 0;
    while(gnomeCounter < SORTSIZE)
    {    
        if(gnomeCounter == 0 ||  arrayElements[gnomeCounter] >= arrayElements[gnomeCounter - 1])
        {
            //This sort will organize our items from least to greatest.
            //AKA it follows the comparison symbol, unlike most sorts.
            gnomeCounter += 1;
        }
        else //Otherwise, we swap the items and keep stepping backwards until that item is in the correct spot.
        {
            // Symbols to show swapping example.
            // (5*) = 5^
            // 4^ = (4)
            // (5) = (5*)
            spareItem = arrayElements[gnomeCounter - 1];
            arrayElements[gnomeCounter - 1] = arrayElements[gnomeCounter];
            arrayElements[gnomeCounter] = spareItem;
            gnomeCounter -= 1;
        }
    }
    return;
}
void RandomizeArray(int arrayElements[])
{
    int counter = 0;
    for(counter = 0; counter < SORTSIZE; counter++)
    {
        arrayElements[counter] = rand() % RANDOMRANGE;
    }
    return;
}
void RandomizePointer(int* pointerElements)
{
    int counter = 0;
    for(counter = 0; counter < SORTSIZE; counter++)
    {
        *(pointerElements + counter) = rand() % RANDOMRANGE;
    }
    return;
} 
void Randomize2DimensionalArray(int arrayElements2Dimensional[][SORTSIZE])
{
    int firstCounter = 0;
    int secondCounter = 0;
    for(firstCounter = 0; firstCounter < SORTSIZE; firstCounter++)
    {
        for(secondCounter = 0; secondCounter < SORTSIZE; secondCounter++)
        {
            arrayElements2Dimensional[firstCounter][secondCounter] = rand() % RANDOMRANGE;
        }
    }
    return;
}

void PrintArray(int arrayElements[]) 
{
    int counter = 0;
    for(counter = 0; counter < SORTSIZE; counter++)
    {
        printf("%d | " , arrayElements[counter]);
    }
    puts("");
    return;
}
void PrintPointer(int* pointerElements)
{
    int counter = 0;
    for(counter = 0; counter < SORTSIZE; counter++)
    {
        printf("%d | " ,  *(pointerElements + counter) );
    }
    puts("");   
    return;
}
void Print2DimensionalArray(int arrayElements2Dimensional[][SORTSIZE])
{
    int firstCounter = 0;
    int secondCounter = 0;
    for(firstCounter = 0; firstCounter < SORTSIZE; firstCounter++)
    {
        for(secondCounter = 0; secondCounter < SORTSIZE; secondCounter++)
        {
            printf("%d | " , arrayElements2Dimensional[firstCounter][secondCounter] );
        }
        puts("");
    }
    puts("");
    return;
}
