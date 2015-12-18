////////////////////////////////////////////////////////////////
// a_brainfuck_interpreter
// stack.h
// interface for linked list based stack
//
// Author:
// Thomas Lavastida
// December 16, 2015
////////////////////////////////////////////////////////////////

//stack node structure
struct stack_node;
typedef struct stack_node node;

//stack structure
typedef struct {
    node* head;
    int size;
} stack;

//operations:

//intializes a new stack
void new_stack( stack* this_stack );

//pushes a node onto the stack containing new_data
void push( stack* this_stack, int new_data, char* new_ptr );

//deletes top of stack and returns data contained in node
int pop( stack* this_stack, char** ret_ptr );

