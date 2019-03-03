/* -----------------------------------------------------------------------
 * Gray Lunn
 * CS 362, Winter 2019
 * Random test for the Adventurer() function
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

#define asserttrue(bool) if(bool) else printf("TEST FAILED: '" #bool  "' on line %d.\n", __LINE__); // asserttrue used from piazza jonah siekkman



int main() {
    int i, n, r, p, deckCount, discardCount, handCount;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
     remodel, smithy, village, baron, great_hall};

    struct gameState G;



    printf ("Testing adventurer.\n");

    SelectStream(2);
    PutSeed(3);

    // ************************************************** //
    // * CardEffect(Adventurer) dependencies:
    // * Assume game is initialized properly
    // * hand with adventurer card
    // * initialized deck (with treasures), hand, and discard
    // * 
    // * 
    // *
    // * 
    // *
    // * 
    // *
    // * 
    // *
    // * 
    // ************************************************** //

    for (n = 0; n < 2000; n++) {
      	initializeGame(2, k, floor(Random()*INT_MAX), &G);
        p = floor(Random() * 2);
        checkCardAdventurer(p, &G);
    }


    exit(0);
}


int checkCardAdventurer(int p, struct gameState *post) {
  struct gameState pre;
  int bonus = Random() * INT_MAX;
  int r;

  pre->hand[p][(pre->handCount[p])++ - 1] = adventurer;
  memcpy (&pre, post, sizeof(struct gameState));


  //  printf ("drawCard PRE: p %d HC %d DeC %d DiC %d\n",
  //	  p, pre.handCount[p], pre.deckCount[p], pre.discardCount[p]);
    
  r = playCard(adventurer, Random()*MAX_HAND, Random()*MAX_HAND, Random()*MAX_HAND, post[post.handCount[p] - 1], &bonus);

  //printf ("drawCard POST: p %d HC %d DeC %d DiC %d\n",
  //      p, post->handCount[p], post->deckCount[p], post->discardCount[p]);


  assertTrue(r == 0);
  assertTrue(post.handCount[p] - 1 == pre->handCount[p]);

}