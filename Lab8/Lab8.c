//
// APS105 Lab 8 Lab8.c
//
// This is a program written to maintain a personal music library,
// using a linked list to hold the songs in the library.
//
// Author: <kyu bum kim>
// Student Number: <1003969100>
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// A node in the linked list

// Each string in the node is declared as a character pointer variable,
// so they need to be dynamically allocated using the malloc() function,
// and deallocated using the free() function after use.
typedef struct node {
    char *artist;
    char *songName;
    char *genre;
    struct node *nextNode ;
} Node;
const int MAX_LENGTH = 1024;
// Declarations of linked list functions
//
// DECLARE YOUR LINKED-LIST FUNCTIONS HERE
//
// Declarations of support functions
// See below the main function for descriptions of what these functions do
Node *new(char artist[], char songName[], char genre[], Node *nextNode, Node *head);
Node *insert(char artist[], char songName[], char genre[], Node *nextNode);
void print(Node *nextNode);
Node *delete(Node *head);
void search(Node *head);
Node *quit(Node *head);
void inputStringFromUser( char prompt[], char s[], int arraySize ) ;
void songNameDuplicate( char songName[] ) ;
void songNameFound( char songName[] ) ;
void songNameNotFound( char songName[] ) ;
void songNameDeleted( char songName[] ) ;
void artistFound( char artist[] ) ;
void artistNotFound( char artist[] ) ;
void printMusicLibraryEmpty( void ) ;
void printMusicLibraryTitle( void ) ;


int main( void ) {
    // Declare the head of the linked list.
    //   ADD YOUR STATEMENT(S) HERE
    Node *head = NULL;
    // Announce the start of the program
    printf( "Personal Music Library.\n\n" ) ;
    printf( "%s", "Commands are I (insert), D (delete), S (search by song name),\n""P (print), Q (quit).\n" ) ;
    
    char response , promptName[ MAX_LENGTH + 1 ], promptArtist[ MAX_LENGTH + 1 ], promptGenre[ MAX_LENGTH + 1 ];
    char input[ MAX_LENGTH + 1 ] ;
    do {
        inputStringFromUser( "\nCommand", input, MAX_LENGTH ) ;

        // Response is the first character entered by user.
        // Convert to uppercase to simplify later comparisons.
        response = toupper( input[0] ) ;

        if( response == 'I' )
        {
            // Insert a song into the linked list.
            // Maintain the list in alphabetical order by song name.
            //   ADD STATEMENT(S) HERE
            head = insert(promptArtist, promptName, promptGenre, head);
        }
        else if( response == 'D' ) {
            // Delete a song from the list.

            head = delete (head);

            //   ADD STATEMENT(S) HERE
            
        }
        else if( response == 'S' ) {
            // Search for a song by its name.

            search (head);
            //   ADD STATEMENT(S) HERE

        }
        else if( response == 'P' ) {
            // Print the music library.
            print(head);
            //   ADD STATEMENT(S) HERE

        }
        else if( response == 'Q' ) {
            ; // do nothing, we'll catch this below
        }
        else {
            // do this if no command matched ...
            printf( "\nInvalid command.\n" ) ;
        }
    } while( response != 'Q' ) ;
 
    // Delete the entire linked list.
    //   ADD STATEMENT(S) HERE
    head = quit(head);
    printMusicLibraryEmpty();
    printf ("\n");
    // Print the linked list to confirm deletion.
    //   ADD STATEMENT(S) HERE

    return 0 ;
}

// Support Function Definitions

// Prompt the user for a string safely, without buffer overflow
void inputStringFromUser(char prompt[], char s[], int maxStrLength) {
    int i = 0;
    char c;
    
    printf( "%s --> ", prompt ) ;
    while( i < maxStrLength && (c = getchar()) != '\n' )
        s[i++] = c ;
    s[i] = '\0' ;
}

// Function to call when the user is trying to insert a song name
// that is already in the personal music library.
void songNameDuplicate( char songName[] ) {
    printf( "\nA song with the name '%s' is already in the music library.\n"
            "No new song entered.\n", songName);
}

// Function to call when a song name was found in the personal music library.
void songNameFound( char songName[] ) {
    printf( "\nThe song name '%s' was found in the music library.\n",
           songName ) ;
}

// Function to call when a song name was not found in the personal music library.
void songNameNotFound( char songName[] ) {
    printf( "\nThe song name '%s' was not found in the music library.\n",
           songName);
}

// Function to call when a song name that is to be deleted
// was found in the personal music library.
void songNameDeleted( char songName[] ) {
    printf( "\nDeleting a song with name '%s' from the music library.\n",
           songName);
}

// Function to call when printing an empty music library.
void printMusicLibraryEmpty(void) {
    printf( "\nThe music library is empty.\n" ) ;
}

// Function to call to print a title when the entire music library is printed.
void printMusicLibraryTitle(void) {
    printf( "\nMy Personal Music Library: \n" ) ;
}

// Add your functions below this line.

void print(Node *head)
{
    Node *current = head;
    if (head != NULL)
        printMusicLibraryTitle();
    while (current != NULL)
    {
        printf("\n%s \n", current -> songName);
        printf("%s \n", current -> artist);
        printf("%s \n", current -> genre);
        current = current -> nextNode;
    }
    if (head == NULL)
    {
        printMusicLibraryEmpty();
    }
}

Node *newNode(char promptArtist[], char promptName[], char promptGenre[], Node *nextNode)
{
    Node *t;
    t = (Node *)malloc(sizeof(Node));
        if (t != NULL)
        {
            t -> songName = malloc (strlen(promptName) + 1);
            strcpy(t -> songName, promptName);
            t -> artist = malloc (strlen(promptArtist) + 1);
            strcpy(t -> artist, promptArtist);
            t -> genre = malloc (strlen(promptGenre) + 1);
            strcpy(t -> genre, promptGenre);
            t -> nextNode = nextNode;
        }
    return t;
}

Node *insert(char promptArtist[], char promptName[], char promptGenre[], Node *head)
{
    Node *current = head;
    inputStringFromUser( "Song name", promptName ,MAX_LENGTH + 1);
    inputStringFromUser( "Artist", promptArtist ,MAX_LENGTH + 1);
    inputStringFromUser( "Genre", promptGenre ,MAX_LENGTH + 1);
        
    //empty
    if (head == NULL)
    {
        head = newNode(promptArtist, promptName, promptGenre, NULL);
        return head;
    }
    
    else if (strcmp (promptName, head -> songName) < 0)
    {
        head = newNode(promptArtist, promptName, promptGenre, head);
        return head;
    }
    
    else if (current != NULL && current -> nextNode == NULL)
    {
        if (strcmp( promptName, head -> songName) == 0)
            {
                songNameDuplicate(promptName);
                return head;
            }
        else if(strcmp (promptName, head -> songName) > 0 )
        {
            current -> nextNode = newNode(promptArtist, promptName, promptGenre, NULL);
            return head;
        }
    }
    //in ordered list
    while (current -> nextNode != NULL)
    {
        if (strcmp(promptName, current -> songName ) == 0)
        {
            songNameDuplicate(promptName);
            return head;
        }
        else if( strcmp ( promptName, current -> songName ) > 0 && strcmp ( promptName, current -> nextNode -> songName) < 0)
        {
            current -> nextNode = newNode(promptArtist, promptName, promptGenre, current -> nextNode);
            return head;
        }
        current = current -> nextNode;
    }
    
    //at end
    if (strcmp(promptName, current -> songName) > 0)
    {
        current -> nextNode = newNode(promptArtist, promptName, promptGenre, NULL);
        return head;
    }
    return head;
}

void search(Node *head)
{
    char searchSong[MAX_LENGTH + 1];
    Node *current = head;
    inputStringFromUser( "\nEnter the name of the song to search for", searchSong ,MAX_LENGTH + 1);
    while (current != NULL)
    {
        if (strcmp(searchSong, current -> songName) == 0)
        {
            songNameFound(searchSong);
            printf("\n%s\n%s\n%s\n", current -> songName, current -> artist, current -> genre);
            return;
        }    
        current = current -> nextNode;
    }
    songNameNotFound(searchSong);
    return;
}

Node *delete(Node *head)
{
    char search [MAX_LENGTH + 1];
    Node *current = head;
    inputStringFromUser( "\nEnter the name of the song to be deleted", search ,MAX_LENGTH + 1);
    if (current == NULL)
    {
        songNameNotFound(search);
        return NULL;
    }
    else if (head -> nextNode == NULL && strcmp(search, head -> songName) == 0)
    {
        songNameDeleted(search);
        free (head -> songName);
        free (head -> artist);
        free (head -> genre);
        free (head);
        return NULL;
    }
    else if (head != NULL && strcmp (search, head -> songName) == 0)
    {
        Node *firstNode = head;
        head = head -> nextNode;
        songNameDeleted(search);
        free (firstNode -> songName);
        free (firstNode -> artist);
        free (firstNode -> genre);
        free (firstNode);
        return head;
    }
    else if (head != NULL)
    {
        Node *current = head;
        while (current -> nextNode != NULL)
        {
            if ( strcmp (search, current -> nextNode -> songName) == 0)
            {
                Node *nodeToRemove = current -> nextNode;
                current -> nextNode = current -> nextNode -> nextNode;
                songNameDeleted(search);
                free (nodeToRemove -> songName);
                free (nodeToRemove -> artist);
                free (nodeToRemove -> genre);
                free (nodeToRemove);
                return head;
            }
            else
            current = current -> nextNode;
        }
    }
    
    return head;
}

Node *quit(Node *head)
{
    while (head != NULL)
    {
        Node *secondNode = head -> nextNode;
        songNameDeleted(head -> songName);
        free (head -> songName);
        free (head -> artist);
        free (head -> genre);
        free(head);
        head = secondNode;
    }
    
    return NULL;
}





