/*****************************************

   Author:       Jud Neer
   Date:         6-1-99
   File Name:    monopoly.c
   Description:  Simulates a game of Monopoly, and takes statistics on the results
   Remarks:      (none)



******************************************/
/* Preprocessor Directives */

#include "structures.h"
#include "properties.h"
#include "cards.h"
#include "game.h"
#include "stats.h"



/*****************************************/
/* Main Function */

int main( int argc, char *argv[] ) {

   /* Game Variables */
      unsigned int game, turn, players;
      unsigned int numplayers = DEFAULTPLAYERS, maxgames = DEFAULTGAMES, maxturns = DEFAULTTURNS;
      unsigned int totalmoves = 0, totalturns = 0;
      SQUARE s[NUMSQUARES];
      CARD chance[NUMCARDS], cc[NUMCARDS];
      PLAYER p[MAXPLAYERS];


   /* Initialize Screen, Board, and Cards */
      format_screen( );
      set_parameters( &numplayers, &maxgames, &maxturns, argc, argv );
      zero_variables( p, numplayers );
      load_squares( s );
      load_cards( CHANCEFILE, chance );
      load_cards( CCFILE, cc );


   /* Play Games */
      for( game = 0; game < maxgames; game++ ) {
         zero_variables( p, numplayers );
         for( turn = 0; turn < maxturns; turn++ ) {
            for( players = 0; players < numplayers; players++ ) {
               take_turn( &p[players], s, chance, cc );
            }
         }
         increment_counters( p, numplayers, s, &totalmoves, &totalturns );
      }


   /* Write Statistics */
      prob_data( s, totalturns );


   /* Close Program */
      fprintf( stdout, "Players: %d\n", numplayers );
      fprintf( stdout, "Games: %d\n", maxgames );
      fprintf( stdout, "Turns per game: %d\n", maxturns );
      fprintf( stdout, "Total moves: %d\n", totalmoves );
      fprintf( stdout, "Total turns: %d\n", totalturns );
      return( EXIT_SUCCESS );

}