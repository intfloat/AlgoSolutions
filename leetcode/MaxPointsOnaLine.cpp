// MaxPointsOnaLine.cpp

#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    // O(N^2) solution
    int maxPoints(vector<Point> &points) {
        // vector<pair<int, int> > p;
        // p.clear();
        map<double, int> m;     
        int n = points.size();
        if(n <= 2) return n;
        int res = 0;
        int same_point = 0;
        double inf = std::numeric_limits<double>::infinity();
        for(int i=0; i<n; i++){
            m.clear();
            same_point = 0;
            int cur = 0;
            for(int j=i; j<n; j++){
                if(points[i].x==points[j].x && points[i].y==points[j].y){
                    same_point++;                   
                    continue;
                }
                if(points[i].x==points[j].x){
                    m[inf]++;
                    cur = max(cur, m[inf]);
                    continue;
                }
                double dy = points[i].y-points[j].y;
                double dx = points[i].x-points[j].x;
                double slope = dy/dx;
                m[slope]++;
                cur = max(cur, m[slope]);
            }// end internal for loop
            res = max(res, cur+same_point);
        }// end external for loop
        return res;
    }// end method maxPoints
};
