/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
 #include <algorithm>
 #include <vector>
 #include <utility>
 
 using namespace std;
 
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = intervals.size();
        pair<int, int> *p = new pair<int, int>[len];
        for(int i=0; i<len; i++)
            p[i] = make_pair(intervals[i].start, intervals[i].end);
        sort(p, p+len);
        vector<Interval> res;
        res.clear();
          
        if(len == 0)
            return res;
        
        int start=p[0].first, end=p[0].second;
        for(int i=1; i<len; i++){
            if(p[i].first > end){
                res.push_back(*(new Interval(start, end)));
                start = p[i].first;
                end = p[i].second;
            }
            else{
                end = max(end, p[i].second);
            }
        }
        res.push_back(*(new Interval(start, end)));
        return res;
    }
};
