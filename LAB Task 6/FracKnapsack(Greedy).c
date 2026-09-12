#include <stdio.h>

struct Item {
    int weight;
    int profit;
    float ratio;
};

void sortItems(struct Item items[], int n) {

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            if (items[j].ratio < items[j + 1].ratio) {

                struct Item temp = items[j];

                items[j] = items[j + 1];

                items[j + 1] = temp;
            }
        }
    }
}

float fractionalKnapsack(struct Item items[], int n, int capacity) {

    float totalProfit = 0.0;

    sortItems(items, n);

    for (int i = 0; i < n; i++) {

        if (capacity >= items[i].weight) {

            capacity -= items[i].weight;

            totalProfit += items[i].profit;
        }

        else {

            float fraction =
                (float)capacity / items[i].weight;

            totalProfit +=
                items[i].profit * fraction;

            break;
        }
    }

    return totalProfit;
}

int main() {

    struct Item items[] = {
        {10, 60, 0},
        {20, 100, 0},
        {30, 120, 0}
    };

    int n = 3;
    int capacity = 50;

    for (int i = 0; i < n; i++) {

        items[i].ratio =
            (float)items[i].profit / items[i].weight;
    }

    float result =
        fractionalKnapsack(items, n, capacity);

    printf("Maximum Profit = %.2f\n", result);

    return 0;
}
