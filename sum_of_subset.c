//sub set
#include <stdio.h>

int main() {
    int S[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}
    int d = 5;
    int n = sizeof(S) / sizeof(S[0]);
    int dp[n+1][1000] = {0}
    int subset[1000];

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) 
        for (int j = 0; j <= d; j++)
            dp[i][j] = dp[i-1][j] || (j >= S[i-1] && dp[i-1][j-S[i-1]]);

    void findSubsets(int i, int sum, int size) {
        if (!sum) { for (int j = 0; j < size; j++) printf("%d ", subset[j]); printf("\n"); return; }
        if (dp[i-1][sum]) findSubsets(i-1, sum, size);
        if (sum >= S[i-1] && dp[i-1][sum-S[i-1]]) subset[size] = S[i-1], findSubsets(i-1, sum-S[i-1], size+1);
    }

    dp[n][d] ? findSubsets(n, d, 0) : printf("No subset.\n");
    return 0;
}
