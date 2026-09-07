class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;

        int n = s.size();

        vector<long long> dp(n + 1, 0);
        vector<int> last(26, -1);

        // Empty subsequence
        dp[0] = 1;

        for (int i = 0; i < n; i++) {

            int c = s[i] - 'a';

            // Every existing subsequence:
            // 1. doesn't take s[i]
            // 2. takes s[i]
            dp[i + 1] = (2 * dp[i]) % MOD;

            // Remove duplicates
            if (last[c] != -1) {
                dp[i + 1] -= dp[last[c]];

                if (dp[i + 1] < 0)
                    dp[i + 1] += MOD;
            }

            // Update last occurrence
            last[c] = i;
        }

        // Remove empty subsequence
        return (dp[n] - 1 + MOD) % MOD;
    }
};