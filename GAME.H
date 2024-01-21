/*****************************************

   Author:       Jud Neer
   Date:         6-1-99
   File Name:    game.h
   Description:  Functions that control gameplay
   Remarks:      (none)



******************************************/
/* Preprocessor Directives */



/*****************************************/
/* Functions */

void take_turn( PLAYER *p, SQUARE s[NUMSQUARES], CARD chance[NUMCARDS], CARD cc[NUMCARDS] );
void do_action( PLAYER *p, SQUARE s[NUMSQUARES], CARD chance[NUMCARDS], CARD cc[NUMCARDS], char action, int value );



void take_turn( PLAYER *p, SQUARE s[NUMSQUARES], CARD chance[NUMCARDS], CARD cc[NUMCARDS] ) {

      p->turncount++;

      p->square += DICE;
      if ( p->square >= NUMSQUARES ) {
         p->square -= NUMSQUARES;
      }
      s[p->square].hitcount++;
      do_action( p, s, chance, cc, s[p->square].action, s[p->square].value );

}



void do_action( PLAYER *p, SQUARE s[NUMSQUARES], CARD chance[NUMCARDS], CARD cc[NUMCARDS], char action, int value ) {

   switch( action ) {
      case 'p':
         break;
      case 'r':
         break;
      case 't':
         break;
      case '?':
         break;
      case 'c':  /* FIX THIS!!!!! */
         advance_cards( cc );
         do_action( p, s, chance, cc, cc[NUMCARDS-1].action, cc[NUMCARDS-1].value );
         break;
      case 'g':
         p->square = value;
         s[p->square].hitcount++;
         do_action( p, s, chance, cc, s[p->square].action, s[p->square].value );
         break;
   }

}