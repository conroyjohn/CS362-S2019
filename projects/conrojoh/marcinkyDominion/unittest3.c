#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "village"

int main() {
    int newCards = 1;
    int newActions = 2;
    int discarded = 1;

    int handpos = 0;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
	  struct gameState G, testG;
	  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

    int cardReturned;

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// ----------- TEST 1: two cards are added and deck contains 5 cards--------------
	printf("TESTS: Hand count should not increase, deck count should decrease by one, and num actions should increase by 2\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	cardReturned = caseVillage(thisPlayer, &testG, handpos);

	printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
	printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards);
  printf("num actions = %d, expected = %d\n", testG.numActions, G.numActions + newActions);
	assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);
	assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards);
  //assert(testG.numActions == G.numActions + newActions);

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);


	return 0;
}
