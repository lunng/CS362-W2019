/* -----------------------------------------------------------------------
 * Gray Lunn
 * CS 362, Winter 2019
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

#define asserttrue(bool) if(bool) printf("TEST SUCCESSFULLY COMPLETED.\n"); else printf("TEST FAILED: '" #bool  "' on line %d.\n", __LINE__); // asserttrue used from piazza jonah siekkman

int main() {
    int seed = 1000;
    int numPlayer = MAX_PLAYERS;
    int i, card;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    // arrays of all coppers, silvers, and golds

    printf ("TESTING adventurer():\n");

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, hands, seed, &G); // initialize a new game

    G.coins = 6;
    G.buys = 2;
    playCard(0,0,0,0,&G);


    return 0;
}
