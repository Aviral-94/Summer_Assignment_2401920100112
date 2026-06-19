#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> d;  // stores indices of useful elements
        vector<int> r;

        // Process first k elements
        for (int i = 0; i < k; i++) {
            while (!d.empty() && nums[i] >= nums[d.back()]) {
                d.pop_back();
            }
            d.push_back(i);
        }

        // Process remaining elements
        for (int i = k; i < n; i++) {
            // The front of deque is the largest for the previous window
            r.push_back(nums[d.front()]);

            // Remove elements out of current window
            while (!d.empty() && d.front() <= i - k) {
                d.pop_front();
            }

            // Remove smaller elements from the back
            while (!d.empty() && nums[i] >= nums[d.back()]) {
                d.pop_back();
            }

            // Add current element index
            d.push_back(i);
        }

        // Push maximum of last window
        r.push_back(nums[d.front()]);
        return r;
    }
};