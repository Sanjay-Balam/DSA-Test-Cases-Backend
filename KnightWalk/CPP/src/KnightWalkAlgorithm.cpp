#include "../include/KnightWalkAlgorithm.hpp"
#include <queue> // Include queue for BFS
#include <utility> // For std::pair
#include <iostream>

#define MAX 9999

bool KnightWalkAlgorithm::isValid(int x, int y, int N) {
    return (x >= 1 && x <= N && y >= 1 && y <= N);
}

int KnightWalkAlgorithm::knightwalk(std::vector<int>& KnightPos, std::vector<int>& TargetPos, int n) {
    std::queue<std::pair<std::pair<int, int>, int>> q;
    q.push({{KnightPos[0], KnightPos[1]}, 0});

    int Row[] = {2, 2, -2, -2, 1, 1, -1, -1};
    int Col[] = {1, -1, 1, -1, 2, -2, 2, -2};

    std::vector<std::vector<bool>> vis(n + 1, std::vector<bool>(n + 1, false));
    vis[KnightPos[0]][KnightPos[1]] = true;

    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        int currX = front.first.first;
        int currY = front.first.second;
        int dist = front.second;

        if (currX == TargetPos[0] && currY == TargetPos[1]) {
            return dist; // Return the distance if the target is reached
        }

        for (int i = 0; i < 8; ++i) {
            int newX = currX + Row[i];
            int newY = currY + Col[i];
            if (isValid(newX, newY, n) && !vis[newX][newY]) {
                vis[newX][newY] = true; // Mark the cell as visited
                q.push({{newX, newY}, dist + 1}); // Push the new position with incremented distance
            }
        }
    }
    return -1; // Return -1 if the target cannot be reached
}
