/*****************************************

   Author:       Jud Neer
   Date:         6-1-99
   File Name:    properties.h
   Description:  Functions for the board layout and properties
   Remarks:      (none)



******************************************/
/* Preprocessor Directives */

#define SQUAREFILE "squares.dat"



/*****************************************/
/* Data Types */



/*****************************************/
/* Functions */

void load_squares( SQUARE s[NUMSQUARES] );



void load_squares( SQUARE s[NUMSQUARES] ) {

   FILE *data;
   int i;

   if( !( data = fopen(SQUAREFILE, "r") ) ) {
      fprintf( stderr, "ERROR: Board data file not found\n\n" );
      exit( EXIT_FAILURE );
   }

   for( i = 0; i < NUMSQUARES; i++ ) {
      fgets( s[i].name, MAXNAME, data );
      s[i].name[strlen(s[i].name) - 1] = '\0';
      fscanf( data, "%c", &s[i].action );
      fscanf( data, "%d", &s[i].value );
      fgetc( data );
      s[i].hitcount = 0;
   }

   fclose( data );

}