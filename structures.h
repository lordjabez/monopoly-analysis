/*****************************************

   Author:       Jud Neer
   Date:         6-1-99
   File Name:    structures.h
   Description:  Data types and basic functions for Monopoly
   Remarks:      (none)



******************************************/
/* Preprocessor Directives */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERSION "v1.0\0"

#define MAXPLAYERS ( 8 )
#define DEFAULTPLAYERS ( 1 )
#define DEFAULTGAMES ( 1000 )
#define DEFAULTTURNS ( 100 )

#define NUMSQUARES ( 40 )
#define NUMCARDS ( 16 )
#define MAXNAME ( 25 )

#define RANDOM( lower, upper ) \
              ( (int)( (1+(upper)-(lower)) * rand( ) / (float)RAND_MAX + (lower) ) )

#define DICE ( RANDOM(1,6) + RANDOM(1,6) )



/*****************************************/
/* Data Types */

typedef struct player {
   char square;
   unsigned int turncount;
   unsigned int movecount;
   unsigned int hitcount[40];
   unsigned int stopcount[40];
   } PLAYER;

typedef struct square {
   char name[MAXNAME];
   char action;
   int value;
   unsigned int hitcount;
   unsigned int stopcount;
   } SQUARE;

typedef struct card {
   char name[MAXNAME];
   char action;
   int value;
   } CARD;



/*****************************************/
/* Functions */

void format_screen ( );
void set_parameters( unsigned int *numplayers, unsigned int *maxgames, unsigned int *maxturns, int argc, char *argv[] );
void zero_variables( PLAYER p[MAXPLAYERS], unsigned int numplayers );
void increment_counters( PLAYER p[MAXPLAYERS], unsigned int numplayers, SQUARE s[NUMSQUARES], unsigned int *totalmoves, unsigned int *totalturns );




void format_screen( ) {

   system( "cls" );
   srand( time() );
   fprintf( stdout, "The Monopoly Simulator %s\n", VERSION );
   fprintf( stdout, "By Jud Neer\n\n" );

}



void set_parameters( unsigned int *numplayers, unsigned int *maxgames, unsigned int *maxturns, int argc, char *argv[] ) {

   if( argc > 1 ) {
      sscanf( argv[1], "%d", numplayers );
      *numplayers = ( *numplayers <= MAXPLAYERS ) ? *numplayers : MAXPLAYERS;
   }
   if( argc > 2 ) {
      sscanf( argv[2], "%d", maxgames );
   }
   if( argc > 3 ) {
      sscanf( argv[3], "%d", maxturns );
   }

}



void zero_variables( PLAYER p[MAXPLAYERS], unsigned int numplayers ) {

   int playercount, squarecount;

   for( playercount = 0; playercount < numplayers; playercount++ ) {

      p[playercount].square = 0;
      p[playercount].movecount = 0;
      p[playercount].turncount = 0;

      for( squarecount = 0; squarecount < NUMSQUARES; squarecount++ ) {
         p[playercount].hitcount[squarecount] = 0;
         p[playercount].stopcount[squarecount] = 0;
      }

   }

}



void increment_counters( PLAYER p[MAXPLAYERS], unsigned int numplayers, SQUARE s[NUMSQUARES], unsigned int *totalmoves, unsigned int *totalturns ) {

   int playercount, squarecount;

   for( playercount = 0; playercount < numplayers; playercount++ ) {
      *totalmoves += p[playercount].movecount;
      *totalturns += p[playercount].turncount;
   }

   for( squarecount = 0; squarecount < NUMSQUARES; squarecount++ ) {
      for( playercount = 0; playercount < numplayers; playercount++ ) {
         s[squarecount].hitcount += p[playercount].hitcount[squarecount];
         s[squarecount].stopcount += p[playercount].stopcount[squarecount];
      }
   }

}