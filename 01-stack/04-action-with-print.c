#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int	data;
	struct node* next;
	struct node* prev;
} Node;

typedef struct {
	Node* top;
	Node* bottom;
	int	size;
	char *name;
} Stack;

Stack *create_stack(char *name)
{
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	if(stack == NULL)
		return (NULL);
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	stack->name = name;
	return stack;
}

// Basic Stack
void push(Stack *stack, int data)
{
	Node* node = (Node *)malloc(sizeof(Node));
	if(node == NULL)
		return;
	node->data = data;
	node->next = NULL;
	node->prev = stack->top; // if 1st element to push ?
	// printf("STACK->TOP %p\n",stack->top);
	// stack is not empty before
	if(stack->top != NULL)
		stack->top->next = node;
	stack->top = node;
	if(stack->size == 0)
		stack->bottom = node;
	stack->size++;
}

int	pop(Stack* stack)
{
	if(stack->size == 0)
		return (-1);
	
	int	data = stack->top->data; // ดึง data มาก่อน
	Node *temp = stack->top; // เก็บตัวชี้หัวไว้
	stack->top = stack->top->prev; // เขยิบไปชี้ตัวก่อนหน้า
	if(stack->top != NULL)
		stack->top->next = NULL; // ถ้ามีตัว top ให้ชี้ไปที่ null
	stack->size--;
	free(temp);
	return data;
}


// sa,sb
void swap_head(Stack *stack)
{
	if(stack->size < 2)
		return;
	
	Node* first = stack->top;
	Node* second = first->prev;
	Node* third = second->prev;

	first->prev = third;
	if(third != NULL)
		third->next = first;
	first->next = second;
	second->prev = first;
	second->next = NULL;
	

	if(third == NULL)
		stack->bottom = first;
	// or
	// if (stack->bottom == first) {
    //     stack->bottom = second;
    // }
	stack->top = second;
	printf("s%s\n",stack->name);
}

// ra,rb,rr
void action_rotate(Stack *stack) 
{
    if (stack == NULL || stack->size < 2) 
        return;
    
    Node *top = stack->top;
    Node *bottom = stack->bottom;

	stack->top = top->prev;
    top->prev->next = NULL;
    
	bottom->prev = top;
	top->next = bottom;
	top->prev = NULL;
  
    stack->bottom = top;
}


// rra,rrb,rrr
void action_reverse_rotate(Stack *stack)
{
	if (stack == NULL || stack->size < 2) 
        return;
    
    Node *top = stack->top;
    Node *bottom = stack->bottom;

	stack->bottom = bottom->next;
	top->next = bottom;
	bottom->prev = top;
	bottom->next->prev = NULL;
	bottom->next = NULL;

	stack->top = bottom;
	
}

// pa,pb
// void action_push_stack(Stack *stack_src,Stack *stack_dst)
// {
// 		if(stack_src->size == 0)
// 			return;

// 		Node *top_src = stack_src->top;
// 		stack_src->top = top_src->prev;
// 		top_src->prev->next = NULL;

// 		Node *top_dst = stack_dst->top;
// 		if(top_dst != NULL)
// 		{
// 			top_dst->next = top_src;
// 			top_src->prev = top_dst;
// 		}
// 		else 
// 			top_src->prev = NULL;
			
// 		stack_dst->top = top_src;
// 		stack_src->size--;
// 		stack_dst->size++;
// }

// pa,pb v2
void action_push_stack(Stack *stack_src,Stack *stack_dst)
{
		if(stack_src->size == 0)
			return;
		int data = stack_src->top->data;
		push(stack_dst,data);
		pop(stack_src);
}

void free_stack(Stack *stack) {
    Node *current = stack->top;
    Node *next;
    while (current != NULL) {
        next = current->prev;
        free(current);
        current = next;
    }
    free(stack);
}

void print_stack(Stack* stack) {
    printf("Stack: ");
    Node* node = stack->top;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->prev;
    }
    printf("\n");
}

int main() {
    Stack *stack = create_stack("a");
	Stack *stack_b = create_stack("b");

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);

    print_stack(stack);

	// pop(stack);
	swap_head(stack);
	// action_rotate(stack);
	action_push_stack(stack,stack_b);
	action_push_stack(stack,stack_b);
	action_push_stack(stack,stack_b); 
	print_stack(stack);
	print_stack(stack_b);

	swap_head(stack);
	// action_push_stack(stack_b,stack);
	print_stack(stack);
	print_stack(stack_b);

	swap_head(stack_b);
	action_reverse_rotate(stack);
	print_stack(stack);

	// swap_head(stack);
	// print_stack(stack);

	printf("TOP %d\n", stack->top->data);
	printf("BOT %d\n", stack->bottom->data);
	
	free_stack(stack);
	free_stack(stack_b);
}