#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define TESTCARD "adventurer"

int main() {
    int newCards = 2;
    int discarded = 1;
    int seed = rand() % 1000;
    int temphand[MAX_HAND];
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
  int randDeckCount = rand() % MAX_DECK;

  testG.handCount[thisPlayer] = randHandSize;
  G.handCount[thisPlayer] = randHandSize;

  testG.deckCount[thisPlayer] = randDeckCount;
  G.deckCount[thisPlayer] = randDeckCount;

  int replace, j;
  for(j = 0; j < randDeckCount; j++){
    replace = rand() % 12;
    if(replace == 0){
      testG.deck[thisPlayer][j] = copper;
    } else if(replace == 1){
      testG.deck[thisPlayer][j] = silver;
    } else if(replace == 2){
      testG.deck[thisPlayer][j] = gold;
    }
  }

	cardReturned = caseAdventurer(thisPlayer, &testG, temphand, temphand);

	if(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded){
    passed++;
  } else {
    failed++;
  };
}
  printf("\nTest ran %d times. Random testing of %s passed %d times, failed %d times\n\n",i, TESTCARD, passed, failed);
	return 0;
}
