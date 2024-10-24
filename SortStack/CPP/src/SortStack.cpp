#include "../include/SortStack.hpp"

void SortStack::sortedInsert(std::stack<int>& st, int ele) {
    if(st.empty() || st.top() < ele) {
        st.push(ele);
        return;
    }
    int temp = st.top();
    st.pop();
    sortedInsert(st, ele);
    st.push(temp);
}

void SortStack::solve(std::stack<int>& st) {
    if(st.empty()) {
        return;
    }
    int temp = st.top();
    st.pop();
    solve(st);
    sortedInsert(st, temp);
}

std::stack<int> SortStack::sortstack(std::stack<int>& st) {
    solve(st);
    return st;
}
