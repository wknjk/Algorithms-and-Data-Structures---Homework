# Course: Algorithms and Data Structures, 3rd semester
## Text of the homework:

### Modeling human knowledge in order to understand text by computers is the subject
intensive research. One of the ways to model that knowledge is directed
weight graph, where words are represented as nodes, and semantic relations
represent certain words as branches between them. The weight attached to the branch models
semantic similarity so that higher branch weights represent higher semantic similarity.
The weights are modeled with a real number in the range from 0 to 1.
Semantic similarities can represent synonyms, hyponyms, meronyms, holonyms,
etc. The most similar word to a given word is the one that has the greatest distance from the observed word
say. If the word A is similar to the word V with a coefficient of 0.19, it means that there is a branch
between A and V weight 0.19. If we look at the connection between the words A and S through the word V,
the similarity coefficients on that path are multiplied.

### Memory representation of the graph: 
Sequential representation using linearized adjacency lists


### Implemented fetures:
• Loading a graph from a text file of the specified format

• Adding a node to a graph and removing a node from a graph

• Add and remove a branch between two nodes in a graph

• Print the graph representation

• Delete graph from memory

### Interaction with the knowledge base:
• Finding k (entered by the user) semantically most similar words to the given one
words, in order from the most similar to the least similar (there may be less than k,
depending on node connectivity)

• Print all the words on the shortest path from one given word to another given word
words, in the format word1 -(similarity)->word2 -(similarity)->word3 ... etc.

• Finding all words that are strongly related to the given word (belong
same strongly connected component)

Notes: Although the completed task satisfied all the requirements of the subject, 
the chosen architecture is not good enough because it is not adapted to the modifications of the problem.
