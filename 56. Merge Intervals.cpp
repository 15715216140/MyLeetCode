Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

Seen this question in a real interview before?  YesNo

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        Interval t;
        int a[3000] = {0}, aa[3000] = {0};
        vector<Interval> ans;
        for(int i = 0; i < intervals.size(); i++) {//差分思想 
            if(intervals[i].start == intervals[i].end) {
                aa[intervals[i].start]++;
            }
            else {
                a[intervals[i].start+1]++;
                a[intervals[i].end+1]--;
            }
        }
        for(int i = 1; i < 3000; i++) {
            a[i]  += a[i-1];
        }
        for(int i = 0; i <3000; i++) {
            if(aa[i] >= 1 && a[i] < 1 && a[i+1] < 1 ) {
                t.start = t.end = i;
                ans.push_back(t);
            }
            if(a[i] >= 1) {//判断是否单独数字 
                t.start = i-1;
                for(int j = i+1; j<=3000; j++){
                    if(a[j] < 1) {
                        t.end = j-1;
                        ans.push_back(t);
                        i = j-1;
                        break;
                    }
                    
                }
            }
        }
        return ans;
    }
};
