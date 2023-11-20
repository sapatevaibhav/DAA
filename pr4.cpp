/*
Write a program to solve the travelling salesman problem and to print the path and the cost using LC Branch and Bound.
*/
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

#define N 5

int M[N][N] = {
    {0, 20, 30, 10, 11},
    {15, 0, 16, 4, 2},
    {3, 5, 0, 2, 4},
    {14, 6, 18, 0, 3},
    {16, 4, 7, 16, 0}};
int cost = INT_MAX;
int best_path[N];

void tsp_branch_and_bound(int path[N], bool visited[N], int bound, int level) {
    if (level == N) {
        int current_cost = bound + M[path[N - 1]][path[0]];
        if (current_cost < cost) {
            cost = current_cost;
            copy(path, path + N, best_path);
        }
        return;
    }

    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            int new_bound = bound + M[path[level - 1]][i];
            if (new_bound < cost) {
                path[level] = i;
                visited[i] = true;
                tsp_branch_and_bound(path, visited, new_bound, level + 1);
                visited[i] = false;
            }
        }
    }
}

int main() {
    int path[N];
    bool visited[N] = {false};
    path[0] = 0;
    visited[0] = true;
    tsp_branch_and_bound(path, visited, 0, 1);

    cout << "Min Cost: " << cost << endl;
    cout << "Best Path: ";
    for (int i = 0; i < N; ++i) {
        cout << best_path[i] << " --> ";
    }
    cout << best_path[0] << endl;

    return 0;
}