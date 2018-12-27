## Tic Tac Toe Game in C

**Author**: *bsandeepan95.work@gmail.com (Sandeepan B)*

**Date**: *08-Dec-2018*

#### Notes:

1. This project was created using CodeLite on Ubuntu 18.04 (*Bionic Beaver*). I have added the project configuration files to ***.gitignore*** as these configurations are not portable AFAIK. Therefore, only the main files are here. Just copy-paste them to your project directory and then *build and run* it.
2. I wish to keep this project ***Pointer-free*** as - 
   * any computer where this code will run will not need pointers for performance.
   * If you wish to master pointers for embedded C coding or such, games are the least useful resource for that. Try out real and related projects on Github or elsewhere.
   * pointer concepts are *double-edge swords IMO*, and also not portable to apply on many other popular programming languages.
3. I wish implement a better draw checking code that does not need a counter for filled boxes. Can you help?
4. Why did I implement my own bool datatype? Because **stdbool.h** was not present in my env. Moreover, to meet the needs of our program, a simple manual typedef enum is enough and seems portable.
5. Some code here may not be compatible with C89 standards (like int declaration in for loops). May fix it soon, or not.
----------------------------------------------

### Code Details:

#### Edit Log:

1. Initial code is complete to deploy. (15-Dec-2018)  
2. Successfully(?) implemented logic to run the game multiple times based on user's choice. (17-Dec-2018)  
3. ***ERROR:*** user giving char/str input for box number can cause segmentation error. Maybe try to not implement scanf at all? use fgets with strtol?? (27-Dec-2018)
4. Created Github Repo for the project (27-Dec-2018)

#### To add:

1. Implement ttt_list as a *2d array*. Try to think how to make it work for 5x5 and 7x7 boards.  
**Note:** Making the board names relevant as 00, 01, 02,... RowColumn may prove beneficial. Use string.h for ease maybe?)
2. New code for 5x5 and 7x7 print_board function (what if an automated drawing loop can be designed for it? It should print the cell numbers into the cells also.)
3. ***IMPORTANT!!*** Can you make this playable in PVC?  
    **Note:** Read on [Minimax algorithm][link 1] for PvC. Read [*this Medium article*][link 2] also.


[link 1]: https://en.wikipedia.org/wiki/Minimax
[link 2]: https://medium.freecodecamp.org/how-to-make-your-tic-tac-toe-game-unbeatable-by-using-the-minimax-algorithm-9d690bad4b37
