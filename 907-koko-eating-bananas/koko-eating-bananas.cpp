class Solution {
public:
    bool canEat(vector<int>& piles, int h, int k) {
        long long hours = 0;
        for (int p : piles) {
            hours += (p + k - 1) / k;   // ceil(p/k)
            if (hours > h) return false;
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        // int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canEat(piles, h, mid)) {
                // ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
