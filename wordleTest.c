#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



int loadFile(const char *filename, char ***wordsInListArray, int *sizeList)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("file not found");
        return 1;
    }
    *sizeList = 0;
    char word[6] = {0};
    while (fscanf(file, "%s", word) == 1)
    {
        (*sizeList)++;
    }

    *wordsInListArray = malloc((*sizeList) * sizeof(char *));
    if (*wordsInListArray == NULL)
    {
        perror("Failure, memory not allocated");
        fclose(file);
        return 1;
    }
    rewind(file);

    for (int i = 0; i < *sizeList; ++i)
    {
        (*wordsInListArray)[i] = malloc(strlen(word) + 1);

        if ((*wordsInListArray)[i] == NULL)
        {
            perror("Failure, memory not allocated");
            fclose(file);
            return 1;
        }
        fscanf(file, "%s", (*wordsInListArray)[i]);
    }
    fclose(file);
    return 0;
}

int findRandomWordInList(char **wordsInListArray, int sizeList, char *wordToFind)
{
    int randomNumber = rand() % sizeList;
    strcpy(wordToFind, wordsInListArray[randomNumber]);
    return 0;
}

int firstResult(const char *wordToFind, const char *propositionWord)
{
    int FirstResult = strcmp(wordToFind, propositionWord);
    return FirstResult;
}

int scoring(const char *wordToFind, const char *propositionWord)
{
    int commonLetter = 0;
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (wordToFind[i] == propositionWord[j])
            {
                commonLetter++;
                break;
            }
        }
    }
    return commonLetter;
}

int compareWords(const char *word, const char *propositionWord)
{
    if (strcmp(word, propositionWord) == 0)
    {
        return 0;
    }
    return 1;
}

int findBestWordInList(char **wordsInListArray, int sizeList, const char *propositionWord)
{
    for (int i = 0; i < sizeList; ++i)
    {
        char word[6];
        strcpy(word, wordsInListArray[i]);
        int commonLetter = compareWords(word, propositionWord);

        if (commonLetter == 0)
        {
            printf("word found\n");
        }
    }
    return 0;
}
