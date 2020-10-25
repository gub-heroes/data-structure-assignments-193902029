#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 99999

int stack[SIZE];

// Initially stack is empty 
int top = -1;


/* Function declaration to perform push and pop on stack */
void push(int element);
int  pop();


void main()
{
    int arr[] = { 17, 5, 123, 25, 12, 83 };
    int reservedArr[9999];
    int reservedElemCount = -1;
    int targetNum = 123;
    int targetIndex = 0;
    int totalElem = sizeof(arr)/sizeof(arr[0]);
    
    // Initialize stack with elements from arr
    for (int i = 0; i < totalElem; i++)
    {
        push(arr[i]);
        if (arr[i] == targetNum) {
            targetIndex = i;
        }    
    };
    printf("Initialized the data... \n");
    
    // pop the data from stack until the targetElement index and push the data into reservedArr but don't push the targetNum to reservedArr
    for (int i = 0; i < (totalElem - targetIndex); i++)
    {
        int currentNum = pop();
        if (currentNum != targetNum) {
           reservedArr[i] = currentNum;
           reservedElemCount++;
        }
        
    }
    // finally push the data from reservedArr to stack
    for (int i = reservedElemCount; i >= 0; i--)
    {
        push(reservedArr[i]);
    }
    
    // show the results
    printf("After removing element the stack is: \n");
    for (int i = 0; i <= top; i++)
    {
        printf("%d \n", stack[i]);
    }
}




void push(int element)
{
    // Check stack overflow
    if (top >= SIZE)
    {
        printf("Stack Overflow, can't add more element element to stack.\n");
        return;
    }

    // Increase element count in stack
    top++;

    // Push element in stack
    stack[top] = element;

}


int pop()
{
    if (top < 0)
    {
        printf("Stack is empty.\n");

        return INT_MIN;
    }
    return stack[top--];
}