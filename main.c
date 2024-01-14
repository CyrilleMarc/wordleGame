
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "wordleTest.c"
#include "wordleTest.h"

int main()
{
    char **wordsListInArray = NULL;
    int sizeList = 0;
    const char *filename = "liste.txt";
    char wordToFind[6] = {0};
    char propositionWord[6] = {'*', '*', '*', '*', '*'};
    char word[6] = {0};
    int testTry = 5;
    char **bufferTab = NULL;

    printf("Nombre d'essais : %d\n", testTry);

    srand(time(NULL));

    if (loadFile(filename, &wordsListInArray, &sizeList) == 0)
    {
        findRandomWordInList(wordsListInArray, sizeList, wordToFind);
        printf("Le mot à trouver est : %s\n", wordToFind);

        findRandomWordInList(wordsListInArray, sizeList, propositionWord);
        printf("La proposition de l'ordinateur est : %s\n", propositionWord);
    }
    else
    {
        perror("Failure, file not loaded");
        return 1;
    }

    int FirstResult = compareWords(wordToFind, propositionWord);
    if (FirstResult == 0)
    {
        printf("\x1b[32mBravo vous avez trouvé le mot !!!\x1b[0m\n");
        return 0;
    }
    else
    {
        scoring(wordToFind, propositionWord, &bufferTab);
    }

    decrease_test_try(testTry, wordToFind);
    findBestWordInList(wordsListInArray, sizeList);

    // scoring(wordToFind, propositionWord);
    // checkThePlaceToTheGoodLetter(wordToFind, propositionWord);
    // compareWords(wordToFind, propositionWord);
    // }
    free(wordsListInArray);
    return 0;
}
