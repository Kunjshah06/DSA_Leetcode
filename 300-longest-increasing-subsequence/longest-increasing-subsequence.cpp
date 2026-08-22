class Solution {
public:
    int n;
    int dp[2501][2501];
    int solve(vector<int> &nums,int i, int P){
        if(i >= n){
            return 0;
        }
        if( P!=-1 && dp[i][P] != -1){
            return dp[i][P];
        }
        int take = 0;
        if( P == -1 || nums[i] > nums[P]){
            take = 1 + solve(nums,i+1,i);
        }
        
        int skip = solve(nums,i+1,P);
        
        if(P != -1){
            dp[i][P] = max(take,skip);
        }
        return max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,-1);
    }
};