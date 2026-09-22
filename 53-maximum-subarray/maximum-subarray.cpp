class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int sum = 0;

        for(int num:nums){
            sum += num;
            maxSum = max(sum, maxSum);
            if(sum < 0){
                sum = 0;
                continue;
            }


        }
        return maxSum;
    }
};