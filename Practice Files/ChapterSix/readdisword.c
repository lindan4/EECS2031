#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5000
#define THIRTY_TWO 32

int wordPos = 0;

struct distinctWord {
	
	char *word;
	int frequency;
} allWords[MAX_SIZE];

struct distinctWord *createDistinctWord(char *aWord);
char *duplicateWord(char *s);
void printWord();
struct distinctWord *findWord(char *searchWord);
void sortWords();
int getGreatestFreq();

int main(void)
{
	int c, position;
	char oneWord[MAX_SIZE];
	char *dupWort;
	struct distinctWord *newWord, *oldWord;
	
	printf("Enter words: ");
	position = 0;
	while ((c = getchar()) != EOF && (c != '\n'))
	{
		if (c == ' ' || c == '\t')
		{
			while (c == ' ' || c == '\t')
			{
				c = getchar();
			}
			if (c != '\n')
			{
				//Content of oneword is replaced frequently, and as a result, maybe that's why it is pointing to the last string it saw
				oneWord[position] = '\0';
				dupWort = (char *) duplicateWord(oneWord);
				
				oldWord = (struct distinctWord *) findWord(dupWort);
	
				if (oldWord != NULL)
				{
					oldWord->frequency = oldWord->frequency + 1;
		
				}
				else
				{
					newWord = (struct distinctWord *) createDistinctWord(dupWort);
					allWords[wordPos] = *newWord;
					wordPos++;
				}
				position = 0;
				oneWord[position] = c;
				position++;
			}
		}
		else
		{
			oneWord[position] = c;
			position++;
		}
	}
	oneWord[position] = '\0';
	
	dupWort = (char *) duplicateWord(oneWord);
	oldWord = (struct distinctWord *) findWord(dupWort);
	
	if (oldWord != NULL)
	{
		oldWord->frequency = oldWord->frequency + 1;
		
	}
	else
	{
		newWord = (struct distinctWord *) createDistinctWord(dupWort);
		allWords[wordPos] = *newWord;
		wordPos++;
	}
	printWord();
	sortWords();
	printWord();
}

struct distinctWord *createDistinctWord(char *aWord)
{

	struct distinctWord *newWord = (struct distinctWord *) malloc(sizeof(struct distinctWord));
	if (newWord == NULL)
	{
		printf("Not enough space\n");
		return NULL;
	}
	else
	{
		newWord->word = aWord;
		newWord->frequency = 1;
		return newWord;
	}

}

char *duplicateWord(char *s)
{
	//Ah. Use malloc so that everything is separate
	char *wordArray = (char *) malloc(MAX_SIZE * sizeof(char));
	int count = 0;
	while (*s != '\0')
	{
		*(wordArray + count) = *s;
		count++;
		s++;
	}
	*(wordArray + count) = '\0';
	return wordArray;
}

void printWord()
{
	int i;
	struct distinctWord *theWord;
	for (i = 0; i < wordPos; i = i + 1)
	{
		//Issue: only prints out last word
		theWord = &allWords[i];
		printf("%d Word: %s, Freq: %d\n", i, theWord->word, theWord->frequency);
		
	}
}

struct distinctWord *findWord(char *searchWord)
{
	int i;
	struct distinctWord *wordLook;
	
	for (i = 0; i < wordPos; i = i + 1)
	{
		wordLook = &allWords[i];
		if (strcmp(wordLook->word, searchWord) == 0)
		{
			return wordLook;
		}
	}
	return NULL;
}


void sortWords()
{	
	struct distinctWord *tempo = (struct distinctWord *) malloc(MAX_SIZE * sizeof(struct distinctWord));
	struct distinctWord *accessToWord;
	
	int getMaxCount = getGreatestFreq();
	int i, j, k, pos;
	pos = 0;
	
	//Hmm???
	for (i = getMaxCount; i >= 0; i = i - 1)
	{
		for (j = 0; j < wordPos; j = j + 1)
		{
			accessToWord = &allWords[j];
			//printf("%d %d Access to word %s %d\n", i, j, accessToWord->word, accessToWord->frequency);
			if ((accessToWord->frequency) == i)
			{
				//printf("Does it go here?\n");
				*(tempo + pos) = *accessToWord;
				pos++;
			}
			//Check if the integer equals i, then add it to the temp list
		}
	}
	for (k = 0; k < wordPos; k = k + 1)
	{
		allWords[k] = *(tempo + k);
	}
	
}

int getGreatestFreq()
{
	int i;
	int max = 0;
	for (i = 0; i < wordPos; i = i + 1)
	{
		
		max = (allWords[i].frequency > max) ? allWords[i].frequency : max;
		//printf("Frequency %d\n Max %d\n", allWords[i].frequency, max);
	}
	return max;
}


