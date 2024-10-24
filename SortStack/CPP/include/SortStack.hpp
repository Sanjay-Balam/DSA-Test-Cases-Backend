#ifndef SORTSTACK_HPP
#define SORTSTACK_HPP

#include <vector>
#include <stack>

class SortStack {
public:
    std::stack<int> sortstack(std::stack<int> &s);
    void solve(std::stack<int>& st);
    void sortedInsert(std::stack<int>& st, int ele);
};

#endif
