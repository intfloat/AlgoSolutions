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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
          vector<Interval> res;
        res.clear();
        int len = intervals.size();
        int start=newInterval.start;
        int end=newInterval.end;
          
        if(len==0){
            res.push_back(newInterval);
            return res;
        }
        
        for(int i=0; i<len; i++){
            if(intervals[i].end < start)
                res.push_back(intervals[i]);
            else if(intervals[i].start > end){
                res.push_back(newInterval);
                for(;i<len; i++)
                    res.push_back(intervals[i]);
                return res;
            }
            else if(intervals[i].end>=end && intervals[i].start<=start){
                for(;i<len; i++)
                    res.push_back(intervals[i]);
                return res;
            }
            else if(intervals[i].end>=start && intervals[i].end<=end){
                Interval in(min(start, intervals[i].start), end);
                //res.push_back(in);
                for(;i<len; i++){
                    if(intervals[i].start <= in.end)
                        in.end = max(in.end, intervals[i].end);
                    else{
                        res.push_back(in);
                        //res.push_back(intervals[i]);
                        for(;i<len;i++)
                            res.push_back(intervals[i]);
                        return res;
                    }
                }// end for
                res.push_back(in);
                return res;
            }// end else
            
            // another case
            else if(intervals[i].start>=start && intervals[i].start<=end){
                Interval in(start, max(end, intervals[i].end));
                for(;i<len; i++){
                    if(intervals[i].start <= in.end)
                        in.end = max(in.end, intervals[i].end);
                    else{
                        res.push_back(in);
                        //res.push_back(intervals[i]);
                        for(;i<len;i++)
                            res.push_back(intervals[i]);
                        return res;
                    }
                }// end for
                res.push_back(in);
                return res;
            }
            
        }// end for loop
        
        if(start > intervals[len-1].end)
            res.push_back(newInterval);
        
        return res;
    }
};
