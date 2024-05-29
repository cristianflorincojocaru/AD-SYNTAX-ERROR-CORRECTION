#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "word_selector.h" // Includ fisierul header pentru a accesa functia select_words().

#define MAX_WORD_LENGTH 20

// Functie pentru a returna minimul dintre doua numere intregi.
int MinOfTwo(int a, int b) {
    return a < b ? a : b;
}

// Functie pentru a calcula distanta Levenshtein intre doua siruri de caractere.
int levenshtein_distance(const char *s1, const char *s2) {
    int m = strlen(s1);
    int n = strlen(s2);
    int dp[m + 1][n + 1]; // Matrice pentru stocarea rezultatelor intermediare.

    // Initializarea matricei dp.
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0)
                dp[i][j] = j; // Initializam prima linie cu valori de la 0 la n.
            else if (j == 0)
                dp[i][j] = i; // Initializam prima coloana cu valori de la 0 la m.
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1]; // Caracterele sunt identice, nu este nevoie de nicio operatie.
            else
                // Daca caracterele nu sunt identice, alegem minimul dintre operatiile de inserare, stergere si inlocuire si adaugam 1.
                dp[i][j] = 1 + MinOfTwo(MinOfTwo(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]);
        }
    }

    return dp[m][n]; // Returnam rezultatul final, care este stocat in coltul din dreapta jos al matricei.
}

int main() {
    int num_letters;
    printf("Introduceti numarul de litere pentru cuvantul pe care doriti sa-l alegeti (intre 2 si 10): ", MAX_WORD_LENGTH - 1);
    scanf("%d", &num_letters);

    select_words(num_letters); // Apelam functia select_words() pentru a alege cuvintele cu numarul specificat de litere.

    char chosen_word[MAX_WORD_LENGTH];
    printf("Introduceti cuvantul ales: ");
    scanf("%s", chosen_word);

    char incorrect_word[MAX_WORD_LENGTH];
    printf("Introduceti o versiune incorecta a cuvantului: ");
    scanf("%s", incorrect_word);

    // Calculam distanta Levenshtein intre cuvantul corect si varianta incorecta introdusa de utilizator.
    int distance = levenshtein_distance(chosen_word, incorrect_word);

    // Afisam rezultatul.
    printf("Numarul minim de operatii pentru a transforma '%s' in '%s' este %d\n", incorrect_word, chosen_word, distance);

    return 0;
}
