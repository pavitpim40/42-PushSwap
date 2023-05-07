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

// STACK_UTIL
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

// Basic Operation
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
void s_swap_top(Stack *stack)
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
void shift_up(Stack *stack) 
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

void r_shift_up(Stack *stack_one, Stack *stack_two)
{

	if(stack_one && stack_two == NULL)
	{
		shift_up(stack_one);
		printf("r%s\n",stack_one->name);
	}
	else if(stack_one && stack_two)
	{
		shift_up(stack_one);
		shift_up(stack_two);
		printf("rr\n");
	}
}

// rra,rrb,rrr
void shift_down(Stack *stack)
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

void rr_shift_down(Stack *stack_one, Stack *stack_two)
{

	if(stack_one && stack_two == NULL)
	{
		shift_down(stack_one);
		printf("rr%s\n",stack_one->name);
	}
	else if(stack_one && stack_two)
	{
		shift_down(stack_one);
		shift_down(stack_two);
		printf("rrr\n");
	}
}

// pa,pb v2
void p_move_top(Stack *stack_src,Stack *stack_dst)
{
		if(stack_src->size == 0)
			return;
		int data = stack_src->top->data;
		push(stack_dst,data);
		pop(stack_src);
		printf("p%s\n",stack_dst->name);
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
	// swap_head(stack);
	rr_shift_down(stack,NULL);
	p_move_top(stack,stack_b);
	p_move_top(stack,stack_b);
	p_move_top(stack,stack_b); 
	print_stack(stack);
	print_stack(stack_b);

	s_swap_top(stack_b);
	// action_push_stack(stack_b,stack);
	rr_shift_down(stack,stack_b);
	r_shift_up(stack_b,stack);
	s_swap_top(stack);
	print_stack(stack);
	print_stack(stack_b);

	// swap_head(stack_b);
	// action_reverse_rotate(stack);
	// print_stack(stack);
	// print_stack(stack_b);

	// swap_head(stack);
	// print_stack(stack);

	printf("TOP %d\n", stack->top->data);
	printf("BOT %d\n", stack->bottom->data);
	
	free_stack(stack);
	free_stack(stack_b);
}

// s -> s_swap_top
// p -> p_move_top
// r -> r_insert_bot
// rr -> rr_insert_top

// s -> s_swap_top
// p -> p_move_top
// r -> r_shift_up
// rr -> rr_shift_down