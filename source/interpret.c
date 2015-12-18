////////////////////////////////////////////////////////////////
//a_brainfuck_interpreter
//interpret.c
//Implementation of interpret function
//
//Author:
//Thomas Lavastida
//December 18, 2015
////////////////////////////////////////////////////////////////

//includes
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

//functions

//interprets the bf instructions in the array pointed to
//by instr_mem containing num_elts commands
//uses mem_size for the bf machinge memory size
int interpret( char* instr_mem, int num_elts, int mem_size ) {
    //setup machine vars
    char* instr_ptr;  //instruction pointer
    char* data_ptr;   //data pointer
    char* data_mem;   //data memory

    char instr; //current instruction
    stack s;  //stack for keeping track of [ ] cmds

    //initialize machine
    //data memory with mem_size number of cells, initiallized to 0's
    data_mem = (char*)calloc( mem_size*sizeof(char*) );
    if( data_mem == NULL ) {
	printf( "runtime error: calloc failed\n" );
	return -1;
    }
    //if no failure, data_ptr initially points to beginning of array
    data_ptr = data_mem;

    //instr_ptr initially points to first command
    instr_ptr = instr_mem;
    
    //loop until the end of the program
    //last command is at instr_mem + num_elts
    while ( instr_ptr != ( instr_mem + num_elts ) ) {
	//fetch instruction
	instr = *instr_ptr;

	//decode and execute instruction
	switch ( instr ) {
	case '>':
	    data_ptr++;
	    break;
	case '<':
	    data_ptr--;
	    break;
	case '+':
	    (*data_ptr)++;
	    break;
	case '-':
	    (*data_ptr)--;
	    break;
	case '.':
	    putchar(*data_ptr);
	    break;
	case ',':
	    *data_ptr = getchar();
	    break;
	case '[':
	    if ( *data_ptr ) {
		push( &s, 0, instr_ptr );
		//move to next instruction
	    }
	    else {
		//skip to instr after matching ]
	    }
	    break;
	case ']':
	    break;
	case default:
	    //ignore
	    break;
	}
    }

}

