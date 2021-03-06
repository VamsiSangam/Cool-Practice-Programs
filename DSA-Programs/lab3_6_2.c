#include <stdio.h>

struct stack {
	unsigned int size;
	int data[100];
};

int push_stack(struct stack * s_ptr, int * top, int new_element);
int pop_stack(struct stack * s_ptr, int * top);
int top_stack(struct stack s, int top);
int size_stack(struct stack s, int top);
int is_empty(struct stack s, int top);
int is_full(struct stack s, int top);
struct stack copy_stack(struct stack s, int top, int * top_copy);
void print_stack(struct stack s_copy, int top_copy);

int main()
{	
	int ch;
	int top;
	int top_copy;
	int status;
	int top_element;
	int new_element;
	int pop_element;
	int flag;
	int size;

	struct stack s;
	struct stack s_copy;

	s.size = 100;	
	top = -1;
	
	do {
		printf("\t\tMenu\n");
		printf("1. Push : Insert a new element\n");
		printf("2. Pop : Removes the top element\n");
		printf("3. Top : Last element inserted into the stack\n");
		printf("4. Size : No. of elements in the stack\n");
		printf("5. Is the stack empty?\n");
		printf("6. Is the stack full?\n");
		printf("7. Copy the created stack to another stack\n");
		printf("8. Print the copied stack\n");
		printf("9. Exit\n");
		printf("Enter choice: ");
		scanf("%d", &ch);

		switch (ch) {
			case 1:	printf("Enter new value to be pushed: ");
				scanf("%d", &new_element);
				status = push_stack(&s, &top, new_element);
				if (status == 1) {
					printf("%d pushed onto the stack!\n\n", new_element);
				}
				break;

			case 2:	pop_element = pop_stack(&s, &top);
				if (pop_element != -9999) {
					printf("\n%d removed from stack!\n\n", pop_element);
				}
				break;

			case 3:	top_element = top_stack(s, top);
				if (top_element == -9999) {
					printf("Stack empty!\n");
				} else {	
					printf("%d is the top element in the stack!\n\n", top_element);
				}
				break;

			case 4: size = size_stack(s, top);
				printf("%d elements are present in the stack!\n\n", size);
				break;

			case 5: flag = is_empty(s, top);
				if (flag == 0) {
					printf("Stack is not empty!\n\n");
				} else {
					printf("Stack is empty!\n\n");
				}
				break;

			case 6:	flag = is_full(s, top);
				if (flag == 0) {
					printf("Stack is not full!\n\n");
				} else {
					printf("Stack is full!\n\n");
				}
				break;

			case 7: s_copy = copy_stack(s, top, &top_copy);
				break;
	
			case 8: print_stack(s_copy, top_copy);
				break;

			default: continue;
		}

	} while (ch != 9);

	return 0;
}

int push_stack(struct stack * s_ptr, int * top, int new_element)
{
	if (*top == (s_ptr->size-1)) {
		printf("Stack Overflow!\n\n");
		return 0;
	} else {
		*top = *top + 1;
		s_ptr->data[*top] = new_element;
		return 1;
	}
}

int pop_stack(struct stack * s_ptr, int * top)
{
	int pop_element;

	if (*top == -1) {
		printf("Stack Underflow!\n\n");
		return -9999;
	} else if (*top == 0) {
		pop_element = s_ptr->data[*top];
		*top = -1;
		return pop_element;
	} else {
		pop_element = s_ptr->data[*top];
		*top = *top - 1;
		return pop_element;
	}
}

int top_stack(struct stack s, int top) 
{
	if (top == -1)	{
		return -9999;
	} else {
		return 	s.data[top];
	}
}

int size_stack(struct stack s, int top)
{
	int size;

	size = 0;

	if (top == -1) {
		return 0;
	} else {
		for (size = 1; size <= top; size++);
		return size;
	}
}

int is_empty(struct stack s, int top) 
{ 
	if (top == -1) {
		return 1;
	} else {
		return 0;
	}
}

int is_full(struct stack s, int top)
{
	if (top == s.size) {
		return 1;
	} else {
		return 0;
	}
}

struct stack copy_stack(struct stack s, int top, int * top_copy)
{
	int i;
	struct stack s_copy;
	
	*top_copy = top;

	if (top != -1) {
		for (i = 0; i <= top; i++) {
			s_copy.data[i] = s.data[i];
		}
		printf("Stack copied successfully!\n\n")
	}
	
	return s_copy;
}

void print_stack(struct stack s_copy, int top_copy)
{
	int i;
	
	if (top_copy == -1) {
		printf("Stack is empty!\n");
	} else {
		printf("\nCopied Stack contains: \n");

		for (i = 0; i <= top_copy; i++) {
			printf("%d\n", s_copy.data[i]);
		}
	}
}

