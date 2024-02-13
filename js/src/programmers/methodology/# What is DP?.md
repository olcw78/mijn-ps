# What is DP?

explore all possible solutions to a problem. As such, it is capable of solving a wide variety of problems that often have the following characteristics.

1. The problem can be broken down into "overlapping subproblems" - smaller versions of the original problem that are re-used multiple times.
2. The problem has an "optimal substructure" - an optimal solution can be formed from optimal solutions to the overlapping subproblems of the original problem.

## divide and conquer

The Fibonacci sequence is a class example used to explain DP.
If you want to find the Nth Fibonacci number F(n), you can break it down into smaller subproblems - find F(n - 1) and F(n - 2) instead. then, adding the solutions to these subproblems together gives the answer to the original question, F(n - 1) + F(n - 2) = F(n), which means the problem has optimal substructure, since a problem F(n) to the original problem can be foremd from the solutions to the subproblems.

These subproblems are also overlapping - for example, we'd need F(4) to calculate both F(5) and F(6).

Greedy algorithm have optimal substructure, but not overlapping subproblems. Divide and conquer algorithms break a problem into subproblems.

DP differ from avoiding unnecessary recalculation of overlapping subproblems, and use the results of those subproblems to solve the initial complex problem.

## Top-down and Bottom-up

1. Bottom-up, also known as tabulation.
2. Top-down, also known as memoization.

- Bottom-up (Tabulation)

implemented with iteration and starts at the base cases.

```python
// Pseudocode
F = array of length (n + 1)
F[0] = 0
F[1] = 1
for i from 2 to n:
    F[i] = F[i - 1] + F[i - 2] 
```

- Top-down (Memoization)
recursion and made efficient with memoization.
memoizing a result means to store the result of a function call, usually in a hashmap or an array, so that when the same function call is made again, we can simply return the memoized result instead of recalculating the result.

```python
// Pseudocode
memo = hashmap
Function F(int i):
    if i is 0 or 1:
        return i
    if i doesn't exist in memo:
        memo[i] = F(i - 1) + F(i - 2)
    return memo[i]
```

## Welke methode is beter?

- A bottom-up implementation's runtime is usually faster, as iteration does not have the overhead that recursion does.
- A top-down implementation is usually much easier to write. recursion, the ordering of subproblems does not matter, whereas with tabulation, we need to go through a logical ordering of solving algorithms.

