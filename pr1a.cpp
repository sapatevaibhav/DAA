// Implement fractional Knapsack Problem using greedy approch
#include <iostream>
#include <algorithm>
using namespace std;

struct Item
{
    int profit, weight;
    Item(int p, int w) : profit(p), weight(w) {}
};

int compareByRatio(Item a, Item b) { return (float)a.profit / a.weight > (float)b.profit / b.weight; }
int compareByProfit(Item a, Item b) { return (float)a.profit > (float)b.profit; }
int compareByWeight(Item a, Item b) { return (float)a.weight < (float)b.weight; }

double fractionalKnapsack(Item arr[], int capacity, int size, int (*compare)(Item, Item))
{
    sort(arr, arr + size, compare);
    int curWeight = 0;
    float totalProfit = 0.0;
    for (int i = 0; i < size; i++)
    {
        if (curWeight + arr[i].weight <= capacity)
        {
            curWeight += arr[i].weight;
            totalProfit += arr[i].profit;
        }
        else
        {
            float remain = capacity - curWeight;
            totalProfit += arr[i].profit * (remain / arr[i].weight);
            break;
        }
    }
    return totalProfit;
}

int main()
{
    int capacity = 25;
    Item arr[] = {{24, 24}, {18, 10}, {18, 10}, {10, 7}};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Case 1 (Maximum profit): " << fractionalKnapsack(arr, capacity, size, compareByProfit) << endl;
    cout << "Case 2 (Minimum Weight): " << fractionalKnapsack(arr, capacity, size, compareByWeight) << endl;
    cout << "Case 3 (Profit/Weight ratio): " << fractionalKnapsack(arr, capacity, size, compareByRatio) << endl;

    return 0;
}
