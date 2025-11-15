# Algorithm Design - SYNTAX ERROR CORRECTION


## PROBLEM STATEMENT : 
We have the task of developing an algorithm for an advanced code editor that automatically corrects syntax errors in programming languages. It is assumed that we receive a clear specification of the valid syntax of the programming language in the form of a "rule" and a code snippet that contains syntax errors, meaning it does not conform to that rule.

Our objective is to build an algorithm that determines the minimum number of operations necessary to transform the given code snippet into one that adheres to the specified rule. These operations can include character substitutions, insertions, or deletions.

Let's take a concrete example to illustrate the problem: let's assume we have the following syntax rule for function declarations in the programming language:
"Each function must start with the keyword 'func', followed by the function name enclosed in parentheses."

A valid function declaration example would be “func(myFunction)”.

Given code snippet: “fnuc(myFuncion”

Our goal is to find the minimum number of operations needed to correct the code snippet so that it matches the defined rule. These operations could include, for example, swapping the characters "n" and "u" to get "func", then inserting the missing characters "t" and ")", so that we obtain "func(myFunction)" according to the given rule.


## PROBLEM DESCRIPTION :
In this project, we need to develop an algorithm for an advanced code editor aimed at automatically correcting syntax errors in programming languages. This algorithm receives two essential inputs: a clear specification of the valid syntax of the programming language in the form of a "rule" and a code snippet that does not conform to this rule.

Our objective is to determine the minimum number of operations necessary to transform the given code snippet into one that adheres to the specified rule. These operations can include character substitutions, insertions, or deletions.
To achieve this, our algorithm will need to compare the given code snippet with the specified syntax rules and identify and perform the necessary operations to correct any discrepancies. These operations can include character swaps, insertions of missing characters, or deletions.

The ultimate goal is to arrive at a code snippet that adheres to the syntax rules using the smallest possible number of operations. This will ensure that the corrected code snippet is functional and can be appropriately used within the given programming language. By addressing this problem, we aim to develop an efficient and accurate algorithm that facilitates the process of correcting syntax errors in source code, thereby improving the quality and efficiency of software development.


## EXAMPLE, IDEAS & SOLUTIONS :
A clear example is the one from the statement, which presents swapping and then inserting characters to ultimately obtain the correct version.

For verifying the correctness of the code, the examples that can be checked are at the user's discretion, being restricted only by the length of the words, which must be at least 2 characters long (e.g., me, you, up, go, etc.), with an example reaching up to 10 or 11 letters for verification (e.g., experiment, decisional, perspective). **BUT BE CAREFUL!** Any word longer than this becomes harder for the user to inspect and verify the program's correctness thoroughly.

To successfully complete such a program, we used 3 main functions :

**select_words(num_letters)** <-> **levenshtein_distance(s1, s2)** <-> **main()**.

The function 'select_words(num_letters)' displays a list of words of the specified length for the user to choose from. Although the function does not return anything, it shows the list of words that meet the length criterion.

The function 'levenshtein_distance(s1, s2)' implements the Levenshtein distance algorithm between two strings s1 and s2. This distance represents the minimum number of operations (insertion, deletion, or substitution of a single character) necessary to transform one string into the other. The algorithm works by using a matrix to calculate the transformation costs and finding the path with the lowest cost.

The 'main()' function is the entry point of the program and handles user interaction. Firstly, it prompts the user to enter the desired word length. Then, it displays the available words of that length. The user is asked to enter the chosen word and an incorrect version of that word. It then calculates and displays the Levenshtein distance between the two input words.

Essentially, this code allows the user to explore the concept of Levenshtein distance, which is useful in various fields such as spell checking, speech recognition, and bioinformatics.

> [!NOTE]
An example I tested is for length 4, then selecting the 'correct' option: **func(book)**. Testing this 'correct' option with the user-entered 'incorrect' option **"func(bocker)"**. Upon verification, it displayed **3**; the *'c'* was replaced with *'o'*, and *'e'* & *'r'* were removed to reach the initial (correct) version.


## USAGE :
To use this program, please download the files named: **"TEMA_PA.cbp"**, **"TEMA_PA.depend"**, **"TEMA_PA.layout"**, **"main.c"**, **"word_selector.c"**, **"word_selector.h"** (for C language).

To run the program correctly, open the file named **"TEMA_PA.cbp"** which will open the entire ready-to-run/test program. Otherwise, first open **"main.c"**, then **"word_selector.c"**, followed by **"word_selector.h"**.

The program will first ask you to enter the desired length of the words you want to test. The program will display a generated list that meets the requirement (length N / e.g., 5).

You will be asked to choose one of the displayed options by typing the chosen option (e.g., *'func(lemon)'*). The program will then ask you to enter an 'incorrect' version of the previously chosen option (e.g., *'func(lebron'*). After entering the data, the program will display the minimum number of operations to transform the 'incorrect' version into the 'correct' version (e.g., *3*).

> [!IMPORTANT]
For using the program in **Python**, please download the file: **"main.py"**. The usage of the program in **Python** is identical to that in **'C'**.


## CONTRIBUTIONS 
Project created by **Cristian Florin Cojocaru** (**CSE.1** - **University of Craiova / Faculty of Automatics, Computer Science and Electronics**). Contributions are welcome ! If you have suggestions for improving the code or documentation, please submit a pull request.


## LICENSE
This project is licensed under the [MIT License](LICENSE).


