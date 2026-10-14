class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, int> mp;   // stores next greater for each element
        stack<int> st;
        
        // Step 1: Process nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; i--) {
            
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            
            if (st.empty())
                mp[nums2[i]] = -1;
            else
                mp[nums2[i]] = st.top();
            
            st.push(nums2[i]);
        }
        
        // Step 2: Build result for nums1
        vector<int> result;
        for (int num : nums1) {
            result.push_back(mp[num]);
        }
        
        return result;
    }
};