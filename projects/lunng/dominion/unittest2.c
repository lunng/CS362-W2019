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
    int numPlayer = MAX_PLAYERS;
    int counter;
    int i; 
    int j; 
    int k;
    int copyDeck[MAX_DECK];
    int copyHand[MAX_HAND];
    int hands[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    // arrays of all coppers, silvers, and golds

    printf ("TESTING fullDeckCount():\n");
    for (i = 0; i < 10; i++)
    {
        for(j = 0; j < 20; j++){
            for(k = 0; k < 20; k++){
                memset(copyDeck, council_room, sizeof(int) * MAX_DECK);
                memset(copyHand, council_room, sizeof(int) * MAX_HAND);
                for(counter = 0; counter < k; counter++){
                    copyDeck[counter] = adventurer;
                }
                for(counter = 0; counter < j; counter++){
                    copyHand[counter] = adventurer;
                }
                for(counter = 0; counter < MAX_PLAYERS; counter++){
                    G.deckCount[counter] = MAX_DECK;
                    G.handCount[counter] = MAX_HAND;
                    G.discardCount[counter] = MAX_DECK;                
                    memcpy(G.deck[counter], copyDeck, sizeof(int) * MAX_DECK);
                    memcpy(G.hand[counter], copyHand, sizeof(int) * MAX_HAND);
                    memcpy(G.discard[counter], copyDeck, sizeof(int) * MAX_DECK);
                }

                for(counter = 0; counter < MAX_PLAYERS; counter++){
                    printf("fullDeckCount: %d expected: %d\n", fullDeckCount(counter, adventurer, &G), (j + 2 * k) );
                    asserttrue(fullDeckCount(counter, adventurer, &G) == (j + 2 * k));
                }

                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                initializeGame(numPlayer, hands, seed, &G); // initialize a new game
            }
        }



                
    }

    return 0;
}
