////////////////////////////////////////////////////////////////
//a_brainfuck_interpreter
//lex.c
//file containing text scanning functions implementations
//
//Author:
//Thomas Lavastida
//December 17, 2015
////////////////////////////////////////////////////////////////

//includes
#include "scan.h"
#include "stack.h"

//returns 0 on no errors, -1 otherwise
//fills buffer with all valid bf characters
int first_pass( FILE* infile, char* buffer, int* num_toks ) {
    int i;
    char curr; 
    stack s;

    new_stack( &s );
    i = 0;
    curr = fgetc( infile );
    while ( !feof( infile ) ) {
	switch ( curr ) {
	case '>':
	case '<':
	case '+':
	case '-':
	case '.':
	case ',':
	case '[':
	case ']':
	    //valid bf characters
	    buffer[i] = curr;
	    i++;
	    break;
	case ' ':
	case '\t':
	case '\v':
	case '\f':
	case '\r':
	case '\n':
	    //whitespace characters - pass over
	    break;
	default:
	    /*
	    //anything else is illegal (for now)
	    printf( "error: %s is illegal bf\n", &curr );
	    return -1;
	    */
	    //trying do nothing for default case
	    break;
	}

	if ( curr == '[' )
	    push( &s, 1, NULL );
	else if ( curr == ']' ) {
	    if (s.size == 0) {
		//can't remove
		printf("error: unbalanced ] in source file\n");
		return -1;
	    }
	    else 
		pop( &s, NULL );
	}

	curr = fgetc( infile );
    }

    if( s.size != 0 ) {
	printf("error: unbalanced ] in source file\n");
	return -1;
    }
    
    *num_toks = i;
    return 0;
}
