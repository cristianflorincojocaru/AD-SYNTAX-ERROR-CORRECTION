#include "word_selector.h" // Includerea fisierului header pentru a accesa declaratia functiei select_words().
#include <stdio.h>
#include <string.h>

#define NUM_WORDS 30
#define MAX_WORD_LENGTH 20

// Definim o matrice de caractere pentru a stoca cuvintele disponibile.
char words[NUM_WORDS][MAX_WORD_LENGTH] = {
    "up",
    "go",
    "dog",
    "cat",
    "car",
    "book",
    "tree",
    "lamp",
    "lemon",
    "tiger",
    "snake",
    "mouse",
    "window",
    "banana",
    "pencil",
    "dragon",
    "sunset",
    "elephant",
    "airplane",
    "birthday",
    "breakfast",
    "celebrate",
    "happiness",
    "landscape",
    "volleyball",
    "Inequality",
    "Grapefruit"
};

// Functie pentru a afisa cuvintele cu numarul specificat de litere.
void select_words(int num_letters) {
    printf("Alege unul dintre cuvintele urmatoare:\n");
    for (int i = 0; i < NUM_WORDS; i++) {
        if (strlen(words[i]) == num_letters) {
            printf("func(%s)\n", words[i]); // Modificarea pentru a afișa cuvintele între paranteze.
        }
    }
}
