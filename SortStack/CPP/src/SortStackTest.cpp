#include "../include/SortStackTest.hpp"
#include "../include/SortStack.hpp"
#include <stack>

bool SortStackTester::test(std::stack<int> st, std::stack<int> output) { // Change input to be a copy of the stack
    SortStack obj;
    std::stack<int> result = obj.sortstack(st); 

    if (result.size() != output.size()) {
        return false; 
    }

    // Use a temporary stack to compare elements
    std::stack<int> temp;

    // Compare elements
    while (!result.empty()) {
        int resultTop = result.top();
        int outputTop = output.top();

        // Push the elements to a temporary stack for later restoration
        temp.push(resultTop);
        result.pop();
        output.pop();

        if (resultTop != outputTop) {
            // Restore the stacks
            while (!temp.empty()) {
                result.push(temp.top());
                temp.pop();
            }
            return false; // If any element does not match, return false
        }
    }

    // Restore the stacks
    while (!temp.empty()) {
        result.push(temp.top());
        temp.pop();
    }

    return true; // If all elements matched, return true
}
