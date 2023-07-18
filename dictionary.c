// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"
#include <math.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 100007;
//number of words in dic
int numberOfWords = 0;


// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    char wordLC[LENGTH + 1]="";

    for(int i = 0, n = strlen(word) ; i < n; i++)
    {
        wordLC[i] = tolower(word[i]);
    }
    //printf("%s\n",wordLC);
    //printf( "original word is %s, lower case word is %s \n",wordLC,word);
    node *ptr = table[hash(wordLC)];

    if (ptr == NULL) return false;

    do
    {
        if (!strcasecmp(ptr -> word,wordLC)) // return zero means true
        {
            return true;
        }
        else // returns positive or negative means false
        {
            node *temp = ptr -> next;
            ptr = temp;
        }
    }
    while(ptr != NULL);
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    const int p = 33;
    long p_pow = 1;
    int hashS = 0;
    for(int i = 0, n = (strlen(word) - 1); i < n; i++)
    {
        hashS = (hashS + (abs(word[i]-'a') + 1) * p_pow) % N;
        p_pow = (p_pow * p) % N;
    }

    return hashS;
}


// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *wP = fopen(dictionary,"r");

    if (wP == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];

    /*
    while (!feof(wP))
    {
        unsigned int hashN;
        node *txt = malloc(sizeof(node));
        //txt->next = NULL;

        if(txt == NULL)
        {
            return false;
        }

        fscanf(wP,"%s", txt->word);
    */
    while (fscanf(wP,"%s", word) != EOF)
    {
        unsigned int hashN;
        node *txt = malloc(sizeof(node));

        if(txt == NULL)
        {
            return false;
        }

        strcpy(txt->word, word);
        //fgets(txt->word, LENGTH+1, wP); // will read one whole line with \n at the end of it for mode details check test // you can use fscanf() it scans word by word

        hashN = hash(word);


        //printf("word is %s Hash is %i and word count is: %i \n", txt->word, hashN, ++wordcount);

        txt->next = table[hashN];
        table[hashN] = txt;
        numberOfWords++;
        /*
        for( int i = 0; *wP != '\0' ; i++)
        {
            fgetc(node->word[i],1,wP); //fgetc returns EOF, fgets returns NULL
            // Reading stops after an EOF or a newline For fgets
        }
        */
    }
    fclose(wP);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return numberOfWords;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    int i = 0;
    for(; i<N; i++)
    {
        if(table[i] != NULL)
        {
            node *ptr = table[i];
            while(ptr->next != NULL)
            {
                node *ptr2 = ptr->next;
                free(ptr);
                ptr = ptr2;
            }
            free(ptr);
        }
    }
    //printf ( "i is %i and N is %i\n",i,N);
    if (i == N)
    {
        return true;
    }
    return false;
}
