////////////////////////////////////////////////////////////////
//a_brainfuck_interpreter
//lex.h
//file containin text scanning interface declaration
//
//Author:
//Thomas Lavastida
//December 17, 2015
////////////////////////////////////////////////////////////////

//includes
#include <stdio.h>

//function declarations
int first_pass( FILE* infile, char* buffer, int* num_toks );

int second_pass( char* buffer );
