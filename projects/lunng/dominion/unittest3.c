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

#ifndef asserttrue
#define asserttrue(bool) if(bool) printf("TEST SUCCESSFULLY COMPLETED.\n"); else printf("TEST FAILED: '" #bool  "' on line %d.\n", __LINE__); // asserttrue used from piazza jonah siekkman
#endif

int main() {
    int seed = 1000;
    int supplies = treasure_map + 1;
    int numPlayer = MAX_PLAYERS;
    int i, count;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    // arrays of all coppers, silvers, and golds

#define asserttrue(bool) if(bool) printf("TEST SUCCESSFULLY COMPLETED.\n"); else printf("TEST FAILED: '" #bool  "' on line %d.\n", __LINE__);
    printf ("TESTING isGameOver():\n");
  


    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    G.supplyCount[province] = 0;

    asserttrue(isGameOver(&G) == 1); // check if the game is over

    count = 0;

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); // initialize a new game
    for(i = 0; i < supplies; i++){
        

        if(i == province){ continue; }
        G.supplyCount[i] = 0;
        count++;

        if(count >= 3){
            asserttrue(isGameOver(&G) == 1); // check if the game is over
        }
        else{
            asserttrue(isGameOver(&G) == 0); // check if the game is over
        }
    }
    return 0;
}
