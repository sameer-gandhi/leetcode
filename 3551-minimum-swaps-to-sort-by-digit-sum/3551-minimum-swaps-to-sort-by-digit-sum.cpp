class Solution {
public:
    static int getdigitsum(int num) {
        int sum = 0;
        while (num > 0) {
            int d = num % 10;
            sum += d;
            num /= 10;
        }
        return sum;
    }
    static bool fun(int x, int y) {
        int sx = getdigitsum(x);
        int sy = getdigitsum(y);
        if (sx != sy) {
            return sx < sy;
        }
        return x < y;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(nums.begin(), nums.end());
        sort(temp.begin(), temp.end(), fun);
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]] = i;
        }
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            int expectedval = temp[i];
            int currentval = nums[i];
            if (expectedval == currentval) {
                continue;
            }
            int expectedidx = mp[expectedval];
            nums[i] = expectedval;
            nums[expectedidx] = currentval;
            mp[expectedval] = i;
            mp[currentval] = expectedidx;
            swaps++;
        }
        return swaps;
    }
};