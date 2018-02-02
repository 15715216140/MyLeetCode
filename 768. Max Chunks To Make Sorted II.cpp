768. Max Chunks To Make Sorted II
DescriptionHintsSubmissionsDiscussSolution
DiscussPick One
This question is the same as "Max Chunks to Make Sorted" except the integers of the given array are not necessarily distinct, the input array could be up to length 2000, and the elements could be up to 10**8.

Given an array arr of integers (not necessarily distinct), we split the array into some number of "chunks" (partitions), and individually sort each chunk.  After concatenating them, the result equals the sorted array.

What is the most number of chunks we could have made?

Example 1:

Input: arr = [5,4,3,2,1]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [5, 4], [3, 2, 1] will result in [4, 5, 1, 2, 3], which isn't sorted.
Example 2:

Input: arr = [2,1,3,4,4]
Output: 4
Explanation:
We can split into two chunks, such as [2, 1], [3, 4, 4].
However, splitting into [2, 1], [3], [4], [4] is the highest number of chunks possible.
Note:

arr will have length in range [1, 2000].
arr[i] will be an integer in range [0, 10**8].
 
题目大意：找出容器中相对有序（类似快排中的相对有序）的区块的个数（最多可划分出多少块） 
如（4,2,1,3） （9,5,6,7,8）	共两块

题解： sum[i]表示  前i项; 从0开始,  如果某块乱序和==有序和，则此块相对有序; ans++,
		因为若某块区域相当有序,则前面区域一定相对有序,从0开始不影响; 
		 
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> b(arr);
        sort(b.begin(),b.end());
        int sum1 = 0, sum2 = 0, ans = 0;
        for(int i = 0; i < arr.size(); i++) {
            sum1 += b[i];
            sum2 += arr[i];
        	if(sum1 == sum2)    ans++;
        }
		return ans;
    }
};
