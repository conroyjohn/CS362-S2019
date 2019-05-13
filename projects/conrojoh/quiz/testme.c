#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    int min = 32; //seems like we need to include all the way down to 32
    int max = 125; //all the way up to 125
    char input = (rand() % (max + 1 - min)) + min;
    return input;
}

char *inputString()
{
    int min = 97; //a
    int max = 122; //z
    int str_length = 6; //set string length
    char str[str_length]; //create string
    int i; //create counter
    for(i = 0; i < str_length - 1; i++){ //loop through each character in string
      int val = (rand() % (max + 1 - min)) + min; //set to rand lowercase
      str[i] = val;
    }
    str[str_length] = '\0'; //terminate string
    char *return_str = malloc(sizeof(char) * 50); //create string pointer
    strcpy(return_str, str); //copy string
    return return_str; //return
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
