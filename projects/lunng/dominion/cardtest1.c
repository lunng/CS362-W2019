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
    int i, j, card, numTreasure, numTreasurePrime, handSize, bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    // arrays of all coppers, silvers, and golds

    printf ("TESTING adventurer():\n");

    for(j = 0; j < 20; j++){
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        initializeGame(numPlayer, k, seed, &G); // initialize a new game


        
        G.whoseTurn = 0;
        card = -1;
        numTreasure = 0;
        gainCard(adventurer,&G,2,0);
        handSize = G.handCount[0];
        for(i = 0; i < MAX_HAND; i++){
            if(G.hand[0][i] == adventurer){
                card = i;
            }
            if(G.hand[0][i] == copper || G.hand[0][i] == silver || G.hand[0][i] == gold){
                numTreasure++;
            }
        }
        if(card == -1){
            printf("error card not found\n");
            return -1;
        }
        bonus = 0;
        cardEffect(adventurer, -1, -1, -1, &G, i, &bonus);
        numTreasurePrime = 0;
        for(i = 0; i < MAX_HAND; i++){
            if(G.hand[0][i] == copper || G.hand[0][i] == silver || G.hand[0][i] == gold){
                numTreasurePrime++;
            }
        }

        printf("init: %d fin: %d\n", numTreasure ,numTreasurePrime);
        printf("size1: %d size2: %d\n", handSize, G.handCount[0]);
        asserttrue(handSize + 1 == G.handCount[0]);
        asserttrue(numTreasurePrime == numTreasure + 2);
    }




    return 0;
}

