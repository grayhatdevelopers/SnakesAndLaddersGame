# SnakesAndLaddersGame
Snakes and Ladders Implementation with Driver function, written in C++ with standard Data Structures
By: Saad Bazaz

There's a lot to cover, so I'll keep it crisp. Can't write much at this hour anyway.


======= fileHandler =======

The fileHandler contains a function which can read *any* map you throw at it (if it's formatted the right way... it'll throw an error 
otherwise). By default, it loads "map.txt" from the relative folder but if you enter a file name which is available in \User_Maps\ 
then it'll get it.

This is achieved by using two vectors, one as a main reference, the other as a reverser. The end result? The entire map is loaded sequentially
to a string vector. Had the original design of the map been such it would have been easier... "Kher", if I had implemented custom maps I'd
load them sequentially. Might do it someday just for fun.

The other functions serve no purpose as of yet.



====== Queue ======

A self implemented Queue ADT. Nothing special here.



====== Stack ======

Tricky part here, had to create two Stack ADTs.
RollStack (as per assignment requirements):
  Contains push_roll() and various other functions present in the assignment Test cases. Specialised for storing integers of dice rolls.
  
Templatized Stack ADT:
  Contains generic Stack functions. I had to use it to reverse the Queue whenever a dice roll equaled to 3.



====== 4DLinkedList ======

As per assignment requirements, it is a 4D linked list with Tile containing up, down, left and right pointers, and two data members 
(one for storing the number of the Tile and the other as a special, initialized with "" by default).
It has too many functions for me to explain in this text file.



====== Map ======

Contains the Map class. Initializes Map through the string vector obtained from the fileHandler. Uses rows and columns to define the 
"Edges", and assigns the Ladders and Snakes with their respective up and down pointers using a combination of two vectors (for each) 
- one storing the value (which is checked whenever the function lands on a special tile), the other storing the address of the last 
found occurence of said special value. This creates a smooth connection of each and every ladder/snake tile from beginning to end.

Theoretically, this can also load custom maps with no problem. And ANY number of ladders/snakes. As long as they don't exist on the
edge, as the up and down pointers are already occupied (I found that an issue during my work).



====== SnakesAndLadders.h ======

Contains main two classes: Player and Game. These pretty much aid the entire driver function. Game contains RollDice(), 
TransverseBoard() etc as per assignment requirements. Also contains ThrowDice(), a random number generator.


