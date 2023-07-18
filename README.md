# Spell-Check
A spell checker program in C

The project involves implementing a spell checker program in C. The goal is to create the fastest spell checker possible, focusing on the actual "wall-clock" time rather than asymptotic time complexity. The program consists of three main files: speller.c, dictionary.c, and dictionary.h.

In dictionary.h, various syntax and preprocessor directives are explained. The file defines constants, includes necessary libraries, and provides function prototypes for check, hash, load, size, and unload.

In dictionary.c, a hash table implementation is used to load a dictionary of words from disk into memory. The provided code in this file is incomplete, requiring the implementation of functions such as load, check, size, and unload. The hash function is also implemented based on the first letter of each word, but it can be improved for efficiency.

In speller.c, the main program is provided, which includes benchmarking and timing functionalities. The getrusage function is used to measure the execution time of the implemented functions. The program takes a dictionary file and a text file as input and performs spell-checking on the text, reporting any misspelled words along with various statistics.

The project focuses on optimizing the implementation of the spell checker functions using a hash table data structure. The goal is to minimize the execution time of load, check, size, and unload while ensuring correctness and handling different cases such as case insensitivity and possessives. Memory management and avoiding memory leaks are also important considerations.

Usage 

$ ./speller texts/lalaland.txt > student.txt
