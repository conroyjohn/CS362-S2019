#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "adventurer"

int main() {
    int newActions = 0;
    int newCoins = 4;
    int newBuys = 1;
    int newCards = 2;
    int discarded = 1;
    int shuffledCards = 0;
    int coin_bonus = 0;

    int handpos = 0;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    int temphand[MAX_HAND];
	  struct gameState G, testG;
	  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

    int cardReturned;


	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// ----------- TEST 1: Baron --------------
	printf("TEST1: For choice1 == 0 : actions should not increase, coins should not increase, buy should increase by 1\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
  //memcpy(testG.deck[thisPlayer], coppers, sizeof(int) * MAX_DECK);

  cardReturned = cardEffect(baron, 0, 0, 0, &testG, handpos, &coin_bonus);

  printf("num actions = %d, expected = %d\n", testG.numActions, G.numActions + newActions);
  assert(testG.numActions == (G.numActions + newActions));
  printf("num coins = %d, expected = %d\n", testG.coins, G.coins + 0);
  assert(testG.coins == G.coins + 0);
  printf("num buy = %d, expected = %d\n", testG.numBuys, G.numBuys + newBuys);
  assert(testG.numBuys == G.numBuys + newBuys);

  // ----------- TEST 2: Baron --------------
	printf("TEST2: For choice1 == 1 : actions should not increase, coins should increase by 4, buy should increase by 1\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
  //memcpy(testG.deck[thisPlayer], coppers, sizeof(int) * MAX_DECK);

  cardReturned = cardEffect(baron, 1, 0, 0, &testG, handpos, &coin_bonus);

  printf("num actions = %d, expected = %d\n", testG.numActions, G.numActions + newActions);
  assert(testG.numActions == (G.numActions + newActions));
  printf("num coins = %d, expected = %d\n", testG.coins, G.coins + newCoins);
  assert(testG.coins == G.coins + newCoins);
  printf("num buy = %d, expected = %d\n", testG.numBuys, G.numBuys + newBuys);
  assert(testG.numBuys == G.numBuys + newBuys);


	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);


	return 0;
}
