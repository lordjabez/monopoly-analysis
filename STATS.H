/*****************************************

   Author:       Jud Neer
   Date:         6-1-99
   File Name:    stats.h
   Description:  Functions that write the game statistics to files
   Remarks:      (none)



******************************************/
/* Preprocessor Directives */

#define PROBFILE "prob.txt"



/*****************************************/
/* Functions */

void sort( SQUARE s[NUMSQUARES] );
void prob_data( SQUARE s[NUMSQUARES], unsigned int turncount );



void sort( SQUARE s[NUMSQUARES] ) {

   int i, j;
   SQUARE temp;

   for( i = 0; i < NUMSQUARES-1; i++ ) {
      for( j = i + 1; j < NUMSQUARES; j++ ) {
         if( s[i].hitcount < s[j].hitcount ) {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
         }
      }
   }

}



void prob_data( SQUARE s[NUMSQUARES], unsigned int turncount ) {

   FILE *data;
   SQUARE temp[NUMSQUARES];
   int i;

   if( !( data = fopen(PROBFILE, "w") ) ) {
      fprintf( stderr, "ERROR: Could not write to %s\n\n", PROBFILE );
      exit( EXIT_FAILURE );
   }

   for( i = 0; i < NUMSQUARES; i++ ) {
      temp[i] = s[i];
   }
   sort( temp );

   fprintf( data, "%-25s %7s %15s\n", "Property", "Hits", "Probability" );
   fprintf( data, "-------------------------------------------------\n\n" );

   for( i = 0; i < NUMSQUARES; i++ ) {
      fprintf( data, "%-25s %7d %15.9f\n", temp[i].name, temp[i].hitcount, temp[i].hitcount / (double)turncount );
   }

   fclose( data );

}