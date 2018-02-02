581. Shortest Unsorted Continuous Subarray
DescriptionHintsSubmissionsDiscussSolution
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.
�������м��ң� r >= 0 , l < nums.size(), return r-l > 0 ? r-l+1 : 0; 
�⼸������Ҫ���ǵ��߽�����:��ȫ��˳�����(��Ȼ�������ݲ�����) 

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> t(nums);
        sort(nums.begin(),nums.end());
        int l = 0, r = nums.size()-1;
        while(l < nums.size() && nums[l] == t[l]) l++;
        while(r >= 0 && nums[r] == t[r]) r--;
        return r-l > 0 ? r-l+1 : 0;
    }
};
