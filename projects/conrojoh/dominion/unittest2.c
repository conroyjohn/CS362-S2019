#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "adventurer"

int main() {
    int newCards = 2;
    int discarded = 1;
    int shuffledCards = 0;

    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    int temphand[MAX_HAND];
	  struct gameState G, testG;
	  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

    int cardReturned;

    // arrays of all coppers, silvers, and golds
    int coppers[MAX_DECK];
    int silvers[MAX_DECK];
    int golds[MAX_DECK];
    int i;
    for (i = 0; i < MAX_DECK; i++)
    {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// ----------- TEST 1: Adventurer --------------
	printf("TESTS: Hand Count should be increased by 1 net of discard\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
  //memcpy(testG.deck[thisPlayer], coppers, sizeof(int) * MAX_DECK);

  cardReturned = adventurerCard(&testG, thisPlayer, temphand);

	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);


	return 0;
}
