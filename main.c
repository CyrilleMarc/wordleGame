#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wordleTest.c"

int loadFile(const char *filename, char ***wordsInListArray, int *sizeList);
int findRandomWordInList(char **wordsInListArray, int sizeList, char *wordToFind);
int firstResult(const char *wordToFind, const char *propositionWord);
int scoring(const char *wordToFind, const char *propositionWord);
int compareWords(const char *word, const char *propositionWord);
int findBestWordInList(char **wordsInListArray, int sizeList, const char *propositionWord);

int main()
{
    char **wordsInListArray = NULL;
    int sizeList = 0;
    const char *filename = "liste.txt";
    char wordToFind[6] = {0};
    char propositionWord[6] = {0}; // Correction : initialiser la propositionWord
    int tries = 5;

    srand(time(NULL));

    if (loadFile(filename, &wordsInListArray, &sizeList) == 0)
    {
        findRandomWordInList(wordsInListArray, sizeList, wordToFind);
        printf("Le mot à trouver est : %s\n", wordToFind);

        findRandomWordInList(wordsInListArray, sizeList, propositionWord);
        printf("La proposition de l'ordinateur est : %s\n", propositionWord);

        for (int i = 0; i < sizeList; ++i)
        {
            free(wordsInListArray[i]);
        }
        free(wordsInListArray);
    }
    else
    {
        perror("Failure, file not loaded");
        return 1;
    }

    int FirstResult = firstResult(wordToFind, propositionWord);
    if (FirstResult == 0)
    {
        printf("Bravo vous avez trouvé le mot!!!\n");
        // int boolFoundWord = 1;  // Correction : cette variable n'est pas utilisée
        return 0;
    }
    else
    {
        int commonLetter = scoring(wordToFind, propositionWord);
        if (commonLetter)
        {
            printf("Lettres en commun: \x1b[32m%d\x1b[0m\n", commonLetter);
        }
        else
        {
            findRandomWordInList(wordsInListArray, sizeList, propositionWord);
            printf("La proposition de l'ordinateur est : %s\n", propositionWord);
        }
    }

    return 0;
}
