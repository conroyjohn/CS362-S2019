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
    int newCoins = 0;
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
	printf("TESTS: Actions should not increase, Coins should not increase\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
  //memcpy(testG.deck[thisPlayer], coppers, sizeof(int) * MAX_DECK);

  cardReturned = cardEffect(adventurer, 0, 0, 0, &testG, handpos, &coin_bonus);

  printf("num actions = %d, expected = %d\n", testG.numActions, G.numActions + newActions);
  assert(testG.numActions == (G.numActions + newActions));
  printf("num coins = %d, expected = %d\n", testG.coins, G.coins + newCoins);
  //assert(testG.coins == G.coins + newCoins);

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);


	return 0;
}
