// Implementation of 0/1 knapsack using dynamic programming
#include <iostream>
#include <iomanip>
using namespace std;

int max(int x, int y) {
    return (x > y) ? x : y;
}

int knapSack(int C, int w[], int p[], int n) { 
    int A[n + 1][C + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= C; j++) {
            if (i == 0 || j == 0)
                A[i][j] = 0;
            else if (w[i - 1] <= j)
                A[i][j] = max(A[i - 1][j], p[i - 1] + A[i - 1][j - w[i - 1]]);
            else
                A[i][j] = A[i - 1][j];
        }
    }

    cout << "Dynamic Programming Matrix:\n";
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= C; j++) {
            cout << setw(2) << A[i][j] << " ";
        }
        cout << "\n";
    }

    int profit = A[n][C];
    int wt = C;
    for (int i = n; i > 0 && profit > 0; i--) {
        if (profit == A[i - 1][wt])
            cout << "Item " << i << " is not included -> 0\n";
        else {
            cout << "Item " << i << " is included -> 1\n";
            profit -= p[i - 1];
            wt -= w[i - 1];
        }
    }

    return A[n][C];
}

int main() {
    cout << "Enter the number of objects for a Knapsack: ";
    int n, K_capacity;
    cin >> n;

    int p[n], w[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter Profit and weight for item " << i << ": ";
        cin >> p[i] >> w[i];
    }

    cout << "Enter the capacity of knapsack: ";
    cin >> K_capacity;

    cout << "Maximum Profit for 0/1 Knapsack: " << knapSack(K_capacity, w, p, n) << "\n";

    return 0;
}
