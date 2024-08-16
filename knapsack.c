#include <stdio.h>

int knapsack(int W, int wt[], int val[], int n) {
    int dp[W+1];
    for (int w = 0; w <= W; w++)
        dp[w] = 0;
    
    for (int i = 0; i < n; i++) {
        for (int w = W; w >= wt[i]; w--) {
            if (dp[w - wt[i]] + val[i] > dp[w]) {
                dp[w] = dp[w - wt[i]] + val[i];
            }
        }
    }
    return dp[W];
}

int main() {
    int W, n;

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int wt[n], val[n];

    printf("Enter the weights of the items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &wt[i]);

    printf("Enter the values of the items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &val[i]);

    printf("Maximum value in Knapsack: %d\n", knapsack(W, wt, val, n));

    return 0;
}
