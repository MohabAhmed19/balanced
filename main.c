#include<stdio.h>
#include<stdint.h>
#include<string.h>

#define STACK_SIZE 10

typedef struct stack {
	uint8_t elements[STACK_SIZE];
	int8_t top;
}ST_stack_t; // Type

/* Description:
 * - This function takes a reference to a stacks type
 * - Initialize this stack with Zeros
 * - Initialize the top with -1
 * Return:
 * - Nothing to return
 */
void createEmptyStack(ST_stack_t* stack);

/* Description:
 * - This function takes a reference to the stack and data to store
 * - Stores the data passed into the stack
 * Return:
 * - returns -1 if the stack is full
 * - returns 0 otherwise
 */
int8_t push(ST_stack_t* stack, uint8_t data);

/* Description:
 * - This function takes a reference to the stack
 * - Stores the data popped from the stack in a data variable
 * Return:
 * - returns -2 if the stack is empty
 * - returns 0 otherwise
 */
int8_t pop(ST_stack_t* stack, uint8_t* data);

/* Description:
 * - This function takes a reference to the stack
 * - Prints all stack's data starting from the top
 * Return:
 * - returns -1 if the stack is full
 * - returns -2 if the stack is empty
 * - returns 0 otherwise
 */
int8_t printStack(ST_stack_t* stack);

/* Description:
 * - This function takes a reference to the stack
 * - Stores its top data into a variable
 * Return:
 * - returns -2 if the stack is empty
 * - 0 otherwise
 */
int8_t getStackTop(ST_stack_t* stack, uint8_t* topData);

/* Description:
 * - This function takes a reference to the stack
 * - Checks if the stack is full or not
 * Return:
 * - returns -1 if the stack is full
 * - 0 otherwise
 */
int8_t isFull(ST_stack_t* stack);

/* Description:
 * - This function takes a reference to the stack
 * - Checks if the stack is empty or not
 * Return:
 * - returns -2 if the stack is empty
 * - 0 otherwise
 */
int8_t isEmpty(ST_stack_t* stack);

/* Description:
 * - This function takes an expression array max 10 characters
 * - Checks if the parentheses are balanced or not
 * - Checks the following parentheses types {, }, (, ) only
 * Return:
 * - returns -2 if the neither of paranthethes is used
 * - returns -1 if the parentheses are not balanced
 * - returns 0 if the parentheses are balanced
 */
int8_t isBalancedParanthethes(uint8_t* expression);

void main()
{
	int error,i=0;
	uint8_t arr[1000];
	printf("enter the expression to be checked\n");
	/*while (arr[i - 1] != '\n')
	{
		scanf("%c", &arr[i]);
		i++;
		printf("%c", arr[i - 1]);
	}*/
	scanf("%s", &arr);
	error = isBalancedParanthethes(arr);
	if (error==-2)
	{
		printf("neither of paranthethes is used");
	}
	if (error == -1)
	{
		printf("parentheses are not balanced");
	}
	else if(error==0)
	{
		printf("parentheses are balanced");
	}
	scanf("%d");
}

void createEmptyStack(ST_stack_t* stack)
{
	int i;
	for (i = 0; i < STACK_SIZE; i++)
	{
		stack->elements[i] = 0;
	}
	stack->top = -1;
}

int8_t push(ST_stack_t* stack, uint8_t data)
{
	if (stack->top == (STACK_SIZE - 1))
	{
		return -1;
	}
	else
	{
		(stack->top)++;
		stack->elements[stack->top] = data;
		return 0;
	}
}

int8_t pop(ST_stack_t* stack, uint8_t* data)
{
	if (stack->top == -1)
	{
		return -2;
	}
	else
	{
		*data = stack->elements[stack->top];
		(stack->top)--;
		return 0;
	}
}

int8_t printStack(ST_stack_t* stack)
{
	int i;
	if (stack == (STACK_SIZE - 1))
	{
		for (i = stack->top; i >= 0; i--)
		{
			printf("%c\n", stack->elements[i]);
		}
		return -1;
	}
	if (stack->top == -1)
	{
		return -2;
	}
	else
	{
		for (i = stack->top; i >= 0; i--)
		{
			printf("%c\n", stack->elements[i]);
		}
		return 0;
	}
}

int8_t getStackTop(ST_stack_t* stack, uint8_t* topData)
{
	if (stack->top == -1)
	{
		return -2;
	}
	else
	{
		*topData = stack->elements[stack->top];
		return 0;
	}
}

int8_t isFull(ST_stack_t* stack)
{
	if (stack->elements == (STACK_SIZE - 1))
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int8_t isEmpty(ST_stack_t* stack)
{
	if (stack->top == -1)
	{
		return -2;
	}
	else
	{
		return 0;
	}
}

int8_t isBalancedParanthethes(uint8_t* expression)
{
	ST_stack_t MyStack;
	int i=0, error, flag = 0, curly = 0, round = 0;
	uint8_t MyData=0;
	createEmptyStack(&MyStack);
	if (strlen(expression) > 10)
	{
		printf("You exceeded the maximum stack size");
		return 1;
	}
	for (i=0;i<strlen(expression);i++)
	{
		if (expression[i] == '{' || expression[i] == '}' || expression[i] == '(' || expression[i] == ')')
		{
			flag=1;
		}
		error = push(&MyStack, expression[i]);
	}
	if (flag == 0)
	{
		return -2;
	}
		
	for (i = 0; i < strlen(expression); i++)
	{
		error = pop(&MyStack, &MyData);
		if (MyData == '}')
			curly++;
		else if (MyData == '{')
			curly--;
		else if (MyData == ')')
			round++;
		else if (MyData == '(')
			round--;
	}
	if (curly < 0 || round < 0)
	{
		return -1;
	}
	else if (curly == 0 && round == 0)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}