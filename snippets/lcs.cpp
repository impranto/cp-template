lli LCS(const vl &a, const vl &b) {
    lli n = a.size(), m = b.size();
    vector<vl> dp(n + 1, vl(m + 1, 0));
    for (lli i = 1; i <= n; i++) {
        for (lli j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}