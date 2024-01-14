#pragma once

int loadFile(const char *filename, char ***wordsListInArray, int *sizeList);
int findRandomWordInList(char **wordsListInArray, int sizeList, char *wordToFind);
int compareWords(const char *wordToFind, const char *propositionWord);
void scoring(const char *wordToFind, const char *propositionWord, char ***bufferTab);
int decrease_test_try(int testTry, const char *wordToFind);
int findBestWordInList(char **wordsListInArray, int sizeList, char **bufferTab, char ***secondArray);