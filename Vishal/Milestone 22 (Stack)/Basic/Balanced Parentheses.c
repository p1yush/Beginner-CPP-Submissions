#include<stdio.h>

typedef struct
{
    int data;
    struct Stack* next;
} stack;

stack *top = NULL;

int isEmpty()
{
    return (top == NULL);
}

void Push(int x)
{
    stack *newNode = (stack*)malloc(sizeof(stack));

    if(!newNode)
    {
        printf("Stack is Full.\n");
        return;
    }
    newNode -> data = x;
    newNode -> next = top;
    top = newNode;
}
void Pop( )
{
    if(!isEmpty())
    {
        stack *temp = top;
        top = temp -> next;
        free(temp);
    }
}

int Top()
{
    if(!isEmpty())
        return top -> data;
}

int isPair(char x,char y)
{
    if(x == ')' && y == '(')
        return 1;

    else if(x == '}' && y == '{')
        return 1;

    else if(x == ']' && y == '[')
        return 1;

    return 0;
}
int CheckBalancedParenthese(char *arr)
{
    int n  = strlen(arr);

    for(int i=0; i<n; i++)
    {
        if(arr[i] == '(' || arr[i] == '{' || arr[i] == '[')
            Push(arr[i]);
        else if(arr[i] == ')' || arr[i] == '}' || arr[i] == ']')
        {
            if((!isPair(arr[i],Top())) || isEmpty())
                return 0;
            else
                Pop();
        }
    }
    return (isEmpty());
}

int main()
{
    char arr[100];
    printf("Enter the String : ");
    scanf("%s",arr);

    if(CheckBalancedParenthese(arr))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}