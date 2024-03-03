This C++ program solves the problem of identifying the longest and second longest compounded words from a list of alphabetically sorted words stored in input text files. A compounded word is defined as one that can be constructed by concatenating shorter words found within the same file. The program utilizes a Trie data structure to efficiently store and search for words, reducing the time complexity of search operations. It follows a recursive approach to determine if a word is compounded by checking if its prefixes and suffixes are present in the Trie.

Design Decisions:
Trie Data Structure: The program employs a Trie data structure for efficient storage and retrieval of words. Each node in the Trie represents a character, and children nodes represent subsequent characters in the word.
Recursive Search: To identify compounded words, the program recursively checks if a word can be formed by concatenating shorter words present in the Trie.
Efficiency: The program prioritizes efficiency by utilizing the Trie data structure, which reduces the time complexity of search operations, enabling quick identification of compounded words even for large input lists.

Steps to Execute:
Ensure you have a C++ compiler installed on your system.
Download the provided C++ source code file.
Compile the source code using the C++ compiler. For example, using g++ compiler: g++ -o compounded_words compounded_words.cpp.
Execute the compiled program with input files as arguments. For example: ./compounded_words Input_01.txt Input_02.txt.
The program will display the longest and second longest compounded words found in each input file along with the time taken to process each file.

Approach:
Trie Construction: The program constructs a Trie by inserting each word from the input file into the Trie.
Compound Word Identification: It recursively checks if each word is compounded by searching for its prefixes and suffixes in the Trie.
Longest and Second Longest: After identifying compounded words, it finds the longest and second longest compounded words from the list of words.

Conclusion:
This program provides an efficient solution to the problem of identifying compounded words from a list of alphabetically sorted words. By utilizing the Trie data structure and a recursive approach, it achieves quick and accurate identification of compounded words, demonstrating an effective engineering solution.
