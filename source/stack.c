////////////////////////////////////////////////////////////////
//a_brainfuck_interpreter
//stack.c
//implementation for linked list based stack
//
//Author:
//Thomas Lavastida
//December 16, 2015
////////////////////////////////////////////////////////////////

//includes
#include <stdlib.h>
#include "stack.h"

//stack node definition
struct stack_node {
    struct stack_node* next;
    int data;
};

void new_stack( stack* this_stack ) {
    if( this_stack ) {
	this_stack->head = NULL;
	this_stack->size = 0;
    }
    else
	exit(-1);
}

void push( stack* this_stack, int new_data ) {
    node *new_node, *tmp;
    if( this_stack->head == NULL ) { 
	//empty stack case
	//create new node
	new_node = (node*)malloc(sizeof(node));
	if( new_node == NULL )
	    exit(-1);
	new_node->next = NULL;
	new_node->data = new_data;
	
	//set top of stack to new_node
	this_stack->head = new_node;
	this_stack->size = 1;
    }
    else {
	//otherwise
	//create new node
	new_node = (node*)malloc(sizeof(node));
	if( new_node == NULL )
	    exit(-1);
	new_node->next = NULL;
	new_node->data = new_data;

	//put new node on stack
        tmp = this_stack->head;
	this_stack->head = new_node;
	new_node->next = tmp;
	this_stack->size++;
    }
}

int pop( stack* this_stack ) {
    int ret = -1;
    node *tmp;
    if ( !this_stack || !this_stack->head )
	exit(-1);
    else {
	ret = this_stack->head->data;
	tmp = this_stack->head->next;
	free(this_stack->head);
	this_stack->head = tmp;
	this_stack->size--;
    }
    return ret;
}
