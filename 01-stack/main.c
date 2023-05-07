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
} Stack;

Stack *create_stack()
{
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	if(stack == NULL)
		return (NULL);
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	return stack;
}

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

// ???
void swap_top_bottom(Stack *stack) {
    if (stack == NULL || stack->size < 2) {
        return;
    }
    
    Node *top = stack->top;
    Node *bottom = stack->bottom;
    
    // Swap top and bottom nodes
    stack->top = bottom;
    stack->bottom = top;
    
    // Update next and prev pointers for top and bottom nodes
    top->next = bottom->next;
    bottom->prev = top->prev;
    bottom->next = NULL;
    top->prev = NULL;
    
    // Update next and prev pointers for nodes adjacent to top and bottom nodes
    if (top->next != NULL) {
        top->next->prev = top;
    }
    if (bottom->prev != NULL) {
        bottom->prev->next = bottom;
    }
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
    Stack *stack = create_stack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);

    print_stack(stack);

	// pop(stack);
	// swap_head(stack);
	action_rotate(stack);
	print_stack(stack);

	swap_head(stack);
	print_stack(stack);

	// swap_head(stack);
	action_reverse_rotate(stack);
	print_stack(stack);

	// swap_head(stack);
	// print_stack(stack);

	printf("TOP %d\n", stack->top->data);
	printf("BOT %d\n", stack->bottom->data);
	

}