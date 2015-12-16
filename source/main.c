////////////////////////////////////////////////////////////////
//a_brainfuck_interpreter
//main.c
//file containing main function and other top level code
//
//Author:
//Thomas Lavastida
//December 16, 2015
////////////////////////////////////////////////////////////////

//includes
#include <stdio.h>
#include <stdlib.h>

//function declarations


//main function definition
int main( int argc, char* argv[] ) {
    FILE* infile;
    //parse args
    if( argc != 2 )
	printf( "help: %s filename.bf\n", argv[0] );
    else
	infile = fopen( argv[1], "r" );
    
    
    //cleanup resources
    fclose( infile );

    //done
    return 0;
}
