import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

///**
// * Definition for an interval.
class Interval {
    int start;
    int end;
    Interval() { start = 0; end = 0; }
    Interval(int s, int e) { start = s; end = e; }
}

class IntervalWithIndex {
    Interval interval;
    int pos;
    IntervalWithIndex(int s, int e, int pos) {
        this.interval = new Interval(s, e);
        this.pos = pos;
    }
}

public class Solution {
    public int[] findRightInterval(Interval[] intervals) {
        List<IntervalWithIndex> startList = new ArrayList<>(), endList = new ArrayList<>();
        for (int i = 0; i < intervals.length; ++i) {
            startList.add(new IntervalWithIndex(intervals[i].start, intervals[i].end, i));
            endList.add(new IntervalWithIndex(intervals[i].start, intervals[i].end, i));
        }
        Collections.sort(startList, new Comparator<IntervalWithIndex>() {
            @Override
            public int compare(IntervalWithIndex o1, IntervalWithIndex o2) {
                return o1.interval.start - o2.interval.start;
            }
        });
        Collections.sort(endList, new Comparator<IntervalWithIndex>() {
            @Override
            public int compare(IntervalWithIndex o1, IntervalWithIndex o2) {
                return o1.interval.end - o2.interval.end;
            }
        });
        int[] res = new int[intervals.length];
        int ptr = 0;
        for (IntervalWithIndex obj : endList) {
            while (ptr < startList.size() && startList.get(ptr).interval.start < obj.interval.end) {
                ++ptr;
            }
            if (ptr >= startList.size()) {
                res[obj.pos] = -1;
            } else {
                res[obj.pos] = startList.get(ptr).pos;
            }
        }
        return res;
    }
}