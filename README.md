# Sodoku solver
An algorithm that uses the Backtracking method to solve Sodoku at any given size.
The algorithm was implemented by using a stack of nodes, each node symbolizes the attempt to allocated some number to a specific cell.

The algorithm works as follows :  
* Try to insert 1
* if there is already a number - delete the node (attempt) and proceed to the cell right next to it (right hand side).
* if there is 1 in the corresponding row or column - attempt to insert 2 (and so forth, if 9 is reached, delete the node and pick the next node in the stack, giving a flag variable to know we can try to assign a different value in the previous node).
* if the insertion of the number is successful - do not delete the node but rather proceed to the cell right next to it (right hand side), not deleting the node makes it possible to return back and try a new number in case the following nodes don't yield a result.

## The sodoku problem is known to be a NP problem hence no faster solution can be found, either way the complexity time is O(n^n^2) where n is the size of the sodoku board.
