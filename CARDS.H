/*****************************************

   Author:       Jud Neer
   Date:         6-1-99
   File Name:    cards.h
   Description:  Functions for Community Chest and Chance cards
   Remarks:      (none)



******************************************/
/* Preprocessor Directives */

#define CHANCEFILE "chance.dat"
#define CCFILE "cc.dat"



/*****************************************/
/* Functions */

void load_cards( char filename[15], CARD card[NUMCARDS] );
void shuffle_cards( CARD card[NUMCARDS] );
void advance_cards( CARD card[NUMCARDS] );



void load_cards( char filename[15], CARD card[NUMCARDS] ) {

   FILE *data;
   int i;

   if( !( data = fopen(filename, "r") ) ) {
      fprintf( stderr, "ERROR: Card data file not found\n\n" );
      exit( EXIT_FAILURE );
   }

   for( i = 0; i < NUMCARDS; i++ ) {
      fgets( card[i].name, MAXNAME, data );
      card[i].name[strlen(card[i].name) - 1] = '\0';
      fscanf( data, "%c", &(card[i].action) );
      fscanf( data, "%d", &(card[i].value) );
      fgetc( data );
   }

   shuffle_cards( card );

   fclose( data );

}



void shuffle_cards( CARD card[NUMCARDS] ) {

   CARD temp;
   int i, j;
   int rcard;

   for( i = 0; i < 7; i++ ) {
      for( j = 0; j < NUMCARDS; j++ ) {
         if( RANDOM(0,1) ) {
            rcard = RANDOM( 0, NUMCARDS - 1 );
            temp = card[j];
            card[j] = card[rcard];
            card[rcard] = temp;
         }
      }
   }

}



void advance_cards( CARD card[NUMCARDS] ) {

   CARD temp;
   int i;

   temp = card[0];
   for( i = 0; i < NUMCARDS - 1; i++ ) {
      card[i] = card[i+1];
   }
   card[NUMCARDS - 1] = temp;

}