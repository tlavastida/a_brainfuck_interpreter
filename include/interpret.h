////////////////////////////////////////////////////////////////
//a_brainfuck_interpreter
//interpret.h
//Declarations for function to interpret a brainfuck program
//
//Author:
//Thomas Lavastida
//December 18, 2015
////////////////////////////////////////////////////////////////

//includes


//functions

//interprets the bf instructions in the array pointed to
//by instr_mem containing num_elts commands
//uses mem_size for the bf machinge memory size
int interpret( char* instr_mem, int num_elts, int mem_size  );
