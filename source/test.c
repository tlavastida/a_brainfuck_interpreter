////////////////////////////////////////////////////////////////
// a_brainfuck_interpreter
// test.c
// test program for linked list based stack
//
// Author:
// Thomas Lavastida
// December 16, 2015
////////////////////////////////////////////////////////////////

//includes
#include <stdio.h> //for output
#include <stdlib.h> //for possible mallocs
#include "stack.h" //module under test
#include <string.h> //for strlen

int main() {
    stack test_stack;
    int ret;
    int i;
  
    char str[50] = "(a+b)*((x-y)(x+(y-3)))";
    int len = strlen( str );

    //test new_stack
    new_stack( &test_stack );

    //test push
    for ( i = 1; i <= 10; i++ ) {
	push( &test_stack, i , NULL);
    
    }

    printf( "after push: \tsize = %d\n", test_stack.size);

    //test pop
    while ( test_stack.size != 0 ) {
	ret = pop( &test_stack, NULL );
	printf("ret = %d\n", ret);
    }

    printf( "after pop: \tsize = %d\n", test_stack.size);

    int size_at_start = test_stack.size;
    int pass = 0;
    //parantheses matching test
    for (i = 0; i < len; i++) {
	if ( str[i] == '(' ) {
	    //push
	    push( &test_stack, 1, NULL );
	}
	else if( str[i] == ')' ) {
	    if( test_stack.size == size_at_start ) {
		pass = -1;
		break;
	    }
	    else { //pop
		ret = pop( &test_stack, NULL );
	    }
	}
    }

    if( pass == -1 )
	pass = 0;
    else {
	pass = size_at_start == test_stack.size ? 1 : 0;
    }
    
    if( pass )
	printf("%s is balanced\n", str);
    else
	printf("%s is not balanced\n", str);

    printf( "All tests passed, no crashes!\n");
    return 0;
}
