/*
 * LCS - longest common subsequence
 * Subsequence - charactors in the same order which may not be contiguous ( picking 0 or more charactors, but order should be maintained)
 * subtring - contiguous charactors of a string
 *
 * problem : length of longest common subsequence
 *
 * ex. s1 = 'ABCDGH' s2 = 'AEDFHR' ans= 'ADH' len = 3
 *
 * variations :
 * 1. min insertions and deletions to convert  s1 into s2: LCS - l is the lcs, then n-l deletions and m-l insetions 
 * 2. longest palindromic subsequence : s1 and s2 is reverse of s1, so answere is their LCS
 * 3. shortest common supersequence : need to insert charactors which are not present  so ans is L + (n-L) + (m-L);
 * 4. Longest repeating subsequence : same as LCS with s1 and s2 being the same strings but when charactors matches 
 *                                    we need to additionally check if their indexes are diff otherwise go to else part and take max
 * 5. Priting the LCS : traverse from right most bottom cell and traverse back ( refere gfg article )
 * */

#include <algorithm>
#include <cfloat>
#include <iostream>
#include <string>
#include<vector>
using namespace std;


int lcs(string s1, string s2){
    // time & space - O(n*m)
    const int n = s1.size();
    const int m = s2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    /* 
     * if size of array is 0 then lcs if 0 base casebase
     * base case - first row all 0 and first col all 0 
     * */
    for(int i=0; i<=n; i++) dp[i][0]= 0; // 1st col 0
    for(int j=0; j<=m; j++) dp[0][j] = 0; // 1st row 0
    
    // dp logic
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    // cout << "print dp table \n";
    // for(auto &x: dp){
    //     for(auto &y: x) cout << y << " ";
    //     cout << "\n";
    // }

    return dp[n][m];

}

// int n - size of s1, m = size of s2
int recursive_lcs(string s1, string s2, int n, int m){
    // time - O(2^(n+m))
    // base case
    if(n == 0 or m ==0) return 0;

    if(s1[n-1] == s2[m-1]) return 1 + recursive_lcs(s1, s2, n-1, m-1);

    // if last char does not match remove last one, try for both and take max
    return max(recursive_lcs(s1,  s2, n-1, m), recursive_lcs(s1, s2, n, m-1));
}

int main(){
    string s1 = "AXYZ", s2 = "BAZ"; // ans:AZ
    const int n = s1.size();
    const int m = s2.size();
    cout << "s1 : " << s1 << " s2 : " << s2 << "\n";
    cout << "recursive solution : " << recursive_lcs(s1, s2, n, m) << "\n";
    cout << "DP solution : " << lcs(s1, s2) << "\n";
    return 0;
}
