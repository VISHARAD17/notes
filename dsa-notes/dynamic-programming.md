# Dynamic Programming


Dynamic Programming is Optimization over recursion.


## 1. Longest Common Subsequence (LCS)

```java
Class Solution(){
    public int longestCommonSubsequence(String text1, String text2) {
        int m = text1.length();
        int n = text2.length();
        int[][] dp = new int[m + 1][n + 1];

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1.charAt(i - 1) == text2.charAt(j - 1)) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
}
```

---

## 2. 0/1 Kanpsack Problem

#### Problem: 
    Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
#### Explanation:
    Exaplnation: For each item, we have two choices, either to include the item in the knapsack or exclude it. We choose the option that gives us the maximum value without exceeding the weight capacity of the knapsack.


```java
Class Solution {
    public int knapsack(int W, int wt[], int val[], int n) {
        int[][] dp = new int[n + 1][W + 1];

        for (int i = 1; i <= n; i++) {
            for (int w = 0; w <= W; w++) {
                if (wt[i - 1] <= w) {
                    dp[i][w] = Math.max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
                } else {
                    dp[i][w] = dp[i - 1][w];
                }
            }
        }
        return dp[n][W];
    }
}

```



