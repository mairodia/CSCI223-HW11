// ============================================================================
// File: matching_bytes.c (Spring 2018)
// ============================================================================
// Programmer: Jennifer King
// Date: 3/22/2018
// Project: Matching Bytes
// Professor: Scott Edwards
// Class: CSCI 223F | TR 4:30PM
// Description:
//      This is a small exercise dealing with void pointers. Arrays are allocated
//      off the stack so that they contain random values. Then their contents are
//      displayed to stdout as individual bytes. The user is then prompted for a
//      target search byte, and the number of matching bytes for an array is
//      displayed.
// ============================================================================

#include    <stdio.h>
#include    <stdint.h>
#include    <stdlib.h>

// defined constants
#define MAX_WIDTH       20
#define NUMELEMS        50

// type definitions
typedef unsigned char   Byte;

// function prototypes
void DispBytes(void *array, int numBytes);

// ==== main ==================================================================
//
// ============================================================================

int     main(void)
{
    auto    double          myDoubles[NUMELEMS];
    auto    int             myInts[NUMELEMS];
    auto    char            myChars[NUMELEMS];
    auto    Byte            target;
    auto    int             numMatches;

    // char array
    puts("Here's the array of chars as bytes: ");
    DispBytes(myChars, sizeof(myChars));
    printf("Enter the target byte as a hex value: ");
    if (1 != scanf("%hhx", &target))
        {
        puts("Error reading hexadecimal value...");
        exit(EXIT_FAILURE);
        }

    numMatches = CountMatchBytes(myChars, sizeof(myChars), target);
    printf("There %s %d matching byte%s.\n\n", (1 == numMatches ? "is" : "are")
                                             , numMatches
                                             , (1 == numMatches ? "" : "s"));
    // int array
    puts("Here's the array of ints as bytes: ");
    DispBytes(myInts, sizeof(myInts));
    printf("Enter the target byte as a hex value: ");
    if (1 != scanf("%hhx", &target))
        {
        puts("Error reading hexadecimal value...");
        exit(EXIT_FAILURE);
        }

    numMatches = CountMatchBytes(myInts, sizeof(myInts), target);
    printf("There %s %d matching byte%s.\n\n", (1 == numMatches ? "is" : "are")
                                             , numMatches
                                             , (1 == numMatches ? "" : "s"));
    // double array
    puts("Here's the array of doubles as bytes: ");
    DispBytes(myDoubles, sizeof(myDoubles));
    printf("Enter the target byte as a hex value: ");
    if (1 != scanf("%hhx", &target))
        {
        puts("Error reading hexadecimal value...");
        exit(EXIT_FAILURE);
        }

    numMatches = CountMatchBytes(myDoubles, sizeof(myDoubles), target);
    printf("There %s %d matching byte%s.\n\n", (1 == numMatches ? "is" : "are")
                                             , numMatches
                                             , (1 == numMatches ? "" : "s"));

    return  0;

}  // end of "main"

void DispBytes(void *array, int numBytes)
{
    auto int *intVal = array;
    
    for(int index = 0; index < numBytes; index++)
    {
        printf("%.2hhx", intVal[index]);
        printf(" ");
        if((index+1)%20 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
}

int CountMatchBytes(void *array, int numBytes, int target)
{
    auto int count = 0;
    auto int *intVal = array;

    for(int index = 0; index < numBytes; index ++)
    {
        if(intVal[index] == target)
        {
            count ++;
        }
    }
    return count;
}
