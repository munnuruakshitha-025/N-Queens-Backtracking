# N-Queens Problem Using Backtracking

## Aim

To implement the N-Queens problem using the Backtracking technique and find a valid arrangement of N queens on an N × N chessboard such that no two queens attack each other.

## Problem Statement

The N-Queens problem is a classic problem in which N queens must be placed on an N × N chessboard.

The queens must be placed such that:

* No two queens are in the same row.
* No two queens are in the same column.
* No two queens are on the same diagonal.

The problem can be solved efficiently using the **Backtracking technique**.

## Case Study

### College Exam Hall Seating Arrangement

Consider a college exam hall represented as an N × N grid.

Each queen represents a student, and each row/column represents a possible seating position.

The objective is to arrange N students such that no two students conflict with each other according to the given restrictions.

Similarly, in the N-Queens problem, queens are placed on the chessboard such that no two queens attack each other.

This demonstrates how backtracking can be used to find a valid arrangement while undoing incorrect choices.

## Example

For `N = 4`, we need to place 4 queens on a 4 × 4 chessboard.

One valid solution is:

```text
. Q . .
. . . Q
Q . . .
. . Q .
```

Here:

* `Q` represents a queen.
* `.` represents an empty position.

The positions of the queens are:

```text
(1,2)
(2,4)
(3,1)
(4,3)
```

No two queens share the same row, column, or diagonal.

## Backtracking Approach

Backtracking builds the solution step by step.

For each row:

1. Try placing a queen in each column.
2. Check whether the position is safe.
3. If the position is safe, place the queen.
4. Move to the next row.
5. If no safe position is available, remove the previously placed queen.
6. Try another position.
7. Continue until all queens are placed.

The process of removing a previously placed queen is called **backtracking**.

## Algorithm

1. Read the value of `N`.
2. Create an `N × N` chessboard initialized with `0`.
3. Start placing queens from the first row.
4. For every column in the current row:

   * Check whether placing a queen is safe.
5. A position is safe if:

   * No queen exists in the same column.
   * No queen exists on the upper-left diagonal.
   * No queen exists on the upper-right diagonal.
6. If the position is safe:

   * Place the queen.
   * Recursively try to place a queen in the next row.
7. If the recursive call fails:

   * Remove the queen.
   * Try the next column.
8. If all N queens are placed:

   * A solution is found.
9. Display the chessboard.

## Backtracking Function

The recursive function follows this logic:

```text
solve(row)

If row == N
    return true

For each column
    If position is safe
        Place queen

        If solve(row + 1)
            return true

        Remove queen

Return false
```

## Program

The implementation is provided in `N_Queens.cpp`.

## Sample Input

```text
4
```

Where:

* `4` = number of queens and size of the chessboard.

## Sample Output

```text
Enter number of queens: 4

N-Queens Solution:

. Q . .
. . . Q
Q . . .
. . Q .

Solution Vector:
2 4 1 3

Solution found successfully.
```

### Solution Vector Explanation

The solution vector represents the column position of the queen in each row.

For the above solution:

| Row | Queen Column |
| --- | ------------ |
| 1   | 2            |
| 2   | 4            |
| 3   | 1            |
| 4   | 3            |

Therefore:

```text
Solution Vector = [2, 4, 1, 3]
```

This means:

* Row 1 → Queen at column 2
* Row 2 → Queen at column 4
* Row 3 → Queen at column 1
* Row 4 → Queen at column 3


## Complexity Analysis

Let `N` be the number of queens.

### Time Complexity

The backtracking algorithm may try multiple possible arrangements of queens.

The worst-case time complexity is approximately:

**O(N!)**

### Space Complexity

The chessboard requires:

**O(N²)**

Additional recursion stack requires:

**O(N)**

Therefore, the overall space complexity is:

**O(N²)**

## Why Backtracking Works

Backtracking is suitable for the N-Queens problem because it explores possible arrangements systematically.

Whenever a partial arrangement cannot lead to a valid solution, the algorithm immediately removes the last queen and tries another position.

This avoids continuing with an invalid arrangement.

## Applications

Backtracking is used in many problems such as:

* N-Queens
* Sudoku Solver
* Graph Coloring
* Hamiltonian Cycle
* Maze Solving
* Permutation Generation
* Constraint Satisfaction Problems

## Technologies Used

* C++
* Data Structures and Algorithms
* Backtracking
* Recursion

## Key Concepts

* Backtracking
* Recursion
* N-Queens Problem
* Chessboard Representation
* Constraint Checking
* State Space Search
* Time and Space Complexity

## Result

The N-Queens problem was successfully implemented using the Backtracking technique. The algorithm places queens row by row, checks whether each position is safe, and backtracks whenever a valid arrangement cannot be obtained.
