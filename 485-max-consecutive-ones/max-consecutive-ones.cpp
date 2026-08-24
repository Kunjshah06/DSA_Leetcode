class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_ones = 0;
        int current_counts = 0;
        int n = nums.size();

        for(int i = 0;i<n;i++){
            if(nums[i] == 1){
                current_counts++;
            }
            else{
                max_ones = max(max_ones, current_counts);
                current_counts = 0;
            }
        }
        return max(max_ones,current_counts);
    }
};