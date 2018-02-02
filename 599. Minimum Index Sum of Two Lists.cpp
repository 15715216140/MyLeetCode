599. Minimum Index Sum of Two Lists
DescriptionHintsSubmissionsDiscussSolution
Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings.

You need to help them find out their common interest with the least list index sum. If there is a choice tie between answers, output all of them with no order requirement. You could assume there always exists an answer.

Example 1:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
Output: ["Shogun"]
Explanation: The only restaurant they both like is "Shogun".
Example 2:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["KFC", "Shogun", "Burger King"]
Output: ["Shogun"]
Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).
Note:
The length of both lists will be in the range of [1, 1000].
The length of strings in both lists will be in the range of [1, 30].
The index is starting from 0 to the list length minus 1.
No duplicates in both lists.
题目大意： 折中找出两人最喜欢的餐厅 
		map记录第一人喜欢的餐厅，记录坐标 
		到第二个人时，遇到第一个人也喜欢的就记录下坐标，并加到此餐厅的记录上，， 
		-10000是为了，findmin时不被（只有一餐厅的情况影响）； 

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ans;
        map<string,int> m;
        int minn = 0;
        for(int i = 0; i < list1.size(); i++) 
            m[list1[i]]  += i;
        for(int i = 0; i < list2.size(); i++) {
            if( m.count(list2[i]) == 1) {
                m[list2[i]] = m[list2[i]]+ i - 10000;
                minn = min(minn,m[list2[i]]);
            }
        for(int i = 0; i < list2.size(); i++) 
            if( m[list2[i]]  == minn) 
                ans.push_back(list2[i]);
        return ans;
        
    }
};
