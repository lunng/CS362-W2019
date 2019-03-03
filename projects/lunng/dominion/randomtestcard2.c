/* -----------------------------------------------------------------------
 * Gray Lunn
 * CS 362, Winter 2019
 * Random test for the Great_hall() function
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

#define asserttrue(bool, l, r) if(bool) ;else printf("TEST FAILED: '" #bool  "' on line %d.\nLeft value: %d\t Right value: %d \n", __LINE__, l, r); // asserttrue used from piazza jonah siekkman



int main() {
    int i, n, r, p, deckCount, discardCount, handCount;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
     remodel, smithy, village, baron, great_hall};

    struct gameState G;




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

    for (n = 0; n < 200000; n++) {
        initializeGame(2, k, floor(Random()*INT_MAX), &G);
        p = floor(Random() * 2);
        checkCardVillage(p, &G);
    }


    exit(0);
}


int checkCardVillage(int p, struct gameState *post) {
  struct gameState pre;
  int bonus = Random() * INT_MAX;
  int r;

  post->hand[p][(post->handCount[p])++ - 1] = village;
  memcpy (&pre, post, sizeof(struct gameState));


  //  printf ("drawCard PRE: p %d HC %d DeC %d DiC %d\n",
  //    p, pre.handCount[p], pre.deckCount[p], pre.discardCount[p]);
    
  r = Village(village, Random()*MAX_HAND, Random()*MAX_HAND, Random()*MAX_HAND, post, post->handCount[p] - 1, &bonus);

  //printf ("drawCard POST: p %d HC %d DeC %d DiC %d\n",
  //      p, post->handCount[p], post->deckCount[p], post->discardCount[p]);


  asserttrue(r == 0, r, 0);
  asserttrue(post->handCount[p] + 1 == pre.handCount[p], post->handCount[p] + 1, pre.handCount[p]);
  asserttrue(post->numActions - 2 == pre.numActions, post->numActions - 2, pre.numActions);
  asserttrue(post->handCount[p] >= 0, post->handCount[p], 0);
  asserttrue(post->deckCount[p] >= 0, post->deckCount[p], 0);


}