#include "../include/SortStackTest.hpp"
#include "../include/SortStack.hpp"
#include <stack>




std::stack<int> SortStack::sortstack(std::stack<int> st) {
    solve(st); // Sort the stack
    return st; // Return the sorted stack
}
