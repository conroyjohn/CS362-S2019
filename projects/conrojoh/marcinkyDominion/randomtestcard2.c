#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define TESTCARD "village"

int main() {
    int newCards = 1;
    int newActions = 2;
    int discarded = 1;
    int handpos = 0;
    int seed = rand() % 1000;
    srand(time(NULL));
	  struct gameState G, testG;
	  int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

    int cardReturned, passed = 0, failed = 0;

    int i;
    for(i = 0; i < 1000; i++){
      int numPlayers = rand() % (MAX_PLAYERS + 1 - 2) + 2;
      int thisPlayer = rand() % (numPlayers - 1);


	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);
  // copy the game state to a test case
  memcpy(&testG, &G, sizeof(struct gameState));

  int randHandSize = rand() % MAX_HAND;
  int randNumActions = rand() % 5 + 1;

  testG.handCount[thisPlayer] = randHandSize;
  G.handCount[thisPlayer] = randHandSize;

  testG.numActions = randNumActions;
  testG.numActions = randNumActions;

	cardReturned = caseVillage(thisPlayer, &testG, handpos);
  if(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded &&
	testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards &&
  testG.numActions == G.numActions + newActions){
    passed++;
  } else {
    failed++;
  };
}
  printf("\nRandom testing of %s passed %d times, failed %d times\n\n", TESTCARD, passed, failed);
	return 0;
}
