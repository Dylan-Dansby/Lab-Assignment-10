/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Trie structure
struct Trie
{	
    int isword;
    struct Trie* next[26];
};

// Inserts the word to the trie structure
void insert(struct Trie *pTrie, char *word,int len)
{
    if(len==strlen(word)){
        pTrie->isword=1;
        return;
    }
    int nextIndex = word[len] - 'a';
    if(pTrie->next[nextIndex]==NULL){
        pTrie->next[nextIndex]=createTrie();
    }
    insert(pTrie,word,len+1);
    
}

// computes the number of occurances of the word
int numberOfOccurances(struct Trie *pTrie, char *word)
{
    struct trie* temp=pTrie;
    int counter = 0;
    for(int i=0;i<26;i++){
        if(temp->isword==1 && temp==word){
            counter++;
        }
    }
}

// deallocate the trie structure
struct Trie *deallocateTrie(struct Trie *pTrie)
{
    struct trie* temp=pTrie;
    pTrie->isword=0;
    for(int i=0;i<26;i++){
        if(temp->next[i]!=NULL){
            free(temp->next[i]);
        }
    }
    free(pTrie);
}

// Initializes a trie structure
struct Trie *createTrie()
{
    struct trie* newtrie=malloc(sizeof(struct trie));
    newTrie->isword=0;
    
    for(int i=0;i<26;i++){
        newtrie->next[i]=NULL;
    }
    return newtrie;
}

// this function will return number of words in the dictionary,
// and read all the words in the dictionary to the structure words
int readDictionary(char *filename, char **pInWords)
{
}

int main(void)
{
	char *inWords[256];
	
	//read the number of the words in the dictionary
	int numWords = readDictionary("dictionary.txt", inWords);
	for (int i=0;i<numWords;++i)
	{
		printf("%s\n",inWords[i]);
	}
	
	struct Trie *pTrie = createTrie();
	for (int i=0;i<numWords;i++)
	{
		insert(pTrie, inWords[i]);
	}
	// parse lineby line, and insert each word to the trie data structure
	char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};
	for (int i=0;i<5;i++)
	{
		printf("\t%s : %d\n", pWords[i], numberOfOccurances(pTrie, pWords[i]));
	}
	pTrie = deallocateTrie(pTrie);
	if (pTrie != NULL)
		printf("There is an error in this program\n");
	return 0;
}
