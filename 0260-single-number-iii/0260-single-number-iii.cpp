class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        unsigned int exor = 0;

        for (int i = 0; i < n; i++) {
            exor = exor ^ static_cast<unsigned int>(nums[i]);
        }

        unsigned int rightmost = exor & (~exor + 1u);

        int b1 = 0;
        int b2 = 0;

        for (int i = 0; i < n; i++) {
            if (static_cast<unsigned int>(nums[i]) & rightmost) {
                b1 = b1 ^ nums[i];
            } else {
                b2 = b2 ^ nums[i];
            }
        }

        return {b1, b2};
    }
};