WORDS = [
    "up", "go", "dog", "cat", "car", "book", "tree", "lamp", "lemon", "tiger",  # Lista de cuvinte din care se poate alege.
    "snake", "mouse", "window", "banana", "pencil", "dragon", "sunset", "elephant", 
    "airplane", "birthday", "breakfast", "celebrate", "happiness", "landscape",
    "volleyball", "Inequality", "Grapefruit"
]

def select_words(num_letters):
    print("Alege una dintre urmatoarele cuvinte:")  # Solicita utilizatorului sa aleaga un cuvant.
    for word in WORDS:  # Parcurge lista de cuvinte.
        if len(word) == num_letters:  # Verifica daca cuvantul are numarul dorit de litere.
            print(f"func({word})")  # Afiseaza cuvantul intre paranteze.

def levenshtein_distance(s1, s2):
    m = len(s1)  # Lungimea primului sir.
    n = len(s2)  # Lungimea celui de-al doilea sir.
    dp = [[0] * (n + 1) for _ in range(m + 1)]  # Initializeaza o matrice pentru programare dinamica.

    for i in range(m + 1):  # Parcurge lungimea primului sir.
        for j in range(n + 1):  # Parcurge lungimea celui de-al doilea sir.
        
            if i == 0:  # Daca primul sir este gol.
                dp[i][j] = j  # Costul transformarii celui de-al doilea sir intr-un prim sir gol este j.
                
            elif j == 0:  # Daca al doilea sir este gol.
                dp[i][j] = i  # Costul transformarii primului sir intr-un al doilea sir gol este i.
                
            elif s1[i - 1] == s2[j - 1]:  # Daca caracterele de pe pozitiile curente sunt la fel.
                dp[i][j] = dp[i - 1][j - 1]  # Nu se incurca cost suplimentar.
            else:  # Daca caracterele sunt diferite.
                dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1])  # Calculeaza costul.

    return dp[m][n]  # Returneaza costul final calculat.

def main():
    num_letters = int(input("Introduceti numarul de litere pentru cuvantul pe care doriti sa-l alegeti (intre 2 si 10): "))  # Solicita utilizatorului lungimea cuvantului.

    select_words(num_letters)  # Apeleaza functia pentru a afisa cuvintele de lungime dorita.

    chosen_word = input("Introduceti cuvantul ales: ")  # Solicita utilizatorului sa introduca cuvantul ales.
    incorrect_word = input("Introduceti o versiune incorecta a cuvantului: ")  # Solicita utilizatorului sa introduca o versiune incorecta a cuvantului.

    distance = levenshtein_distance(chosen_word, incorrect_word)  # Calculeaza distanta Levenshtein intre cuvantul ales si cel incorect.

    print(f"Numarul minim de operatii pentru a transforma '{incorrect_word}' in '{chosen_word}' este {distance}")  # Afiseaza distanta Levenshtein calculata.

if __name__ == "__main__":
    main()  # Apeleaza functia principala daca scriptul este executat direct.

