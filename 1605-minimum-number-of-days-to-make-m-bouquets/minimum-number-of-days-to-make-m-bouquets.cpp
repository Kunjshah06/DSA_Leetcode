#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMake(vector<int>& bloomDay, int m, int k, int day) {
        int bouquets = 0;
        int flowers = 0;

        for (int d : bloomDay) {
            if (d <= day) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }
        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long totalFlowers = (long long)m * k;
        if (totalFlowers > bloomDay.size())
            return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        int answer = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canMake(bloomDay, m, k, mid)) {
                answer = mid;
                high = mid - 1;   // try earlier day
            } else {
                low = mid + 1;    // need more days
            }
        }

        return answer;
    }
};
