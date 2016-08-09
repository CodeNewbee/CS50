/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "dictionary.h"

//create trie data structure
typedef struct NODE
{
    bool is_word;
    struct NODE* children[27];
}NODE;
//initialize root node
NODE *ROOT_NODE = NULL;


//keep track of how many words are in dictionary
int WORD_COUNT;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    //temporary node holder, set it to root node
    NODE *current_node = ROOT_NODE;

    //iterate trough each letter of word
    for (int i = 0; i < 46; i++)
    {
        
        //temporary storage for letter
        char letter = tolower(word[i]);
        
        //check if dictionary word ends at same letter as the input word
        if(letter == '\0' && current_node->is_word == true)
        {
            return true;
        }
        else if (letter == '\0' && current_node->is_word == false)
        {
            return false;
        }
        
        //calculate index
        int index = (letter == '\'') ? 26 : letter - 'a';
        
        //check if word is stored in dictionary
        if(current_node->children[index] == NULL)
        {
            return false;
        }
        else
        {
            current_node = current_node->children[index];
        }
    }
    
    //so that meanie clang doesn't yell at me
    return true;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    //open dicionary
    FILE* dict = fopen(dictionary, "r");
    //return false if opening dictionary was unsuccessful
    if(dict == NULL)
    {
        return false;
    }
    
    ROOT_NODE = malloc(sizeof(NODE));
    
    //temp holder of current node pointer   
    NODE *current_node = ROOT_NODE;
    
    //iterate trough each character of dictionary
    for(int c = fgetc(dict); c != EOF; c = fgetc(dict))
    {
        //if reach end of word, indicate that last character node completes a word, move to next character
        if (c == '\n')
        {
            current_node -> is_word = true;
            WORD_COUNT++;
            current_node = ROOT_NODE;
            continue;
        }
        
        //determine node children array index
        int i = (c == '\'') ? 26 : c - 'a';
        
        //if neccesary node doesn't exist, create it and have children[i] point at it
        if(current_node->children[i] == NULL)
        {
            current_node->children[i] = malloc(sizeof(NODE));
        }
        
        //move to next node
        current_node = current_node->children[i];
    }
    
    //close dictionary file
    fclose(dict);
    
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    //return dictionary word count
    return WORD_COUNT;
}

/**
 * Frees memory from all node pointers by iterating trough them recursiely.
 */
void freenodes(NODE *node_ptr)
{
    for (int i = 0; i < 27; i++)
    {
        //go to next iteration if children[i] doesn't exsist
        if(node_ptr -> children[i] != NULL)
        {
            freenodes(node_ptr->children[i]);
        }
    }
    
    //free the node once iterated trough all its children
    free(node_ptr);
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    freenodes(ROOT_NODE);
    return true;
    
}
