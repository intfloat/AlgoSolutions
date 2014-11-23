#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// Recursive algorithm
// Related to the rotation of coordination
class FractalPicture {
public:
	double getLength(int, int, int, int);
	double ans;
	double get(int g, int x1, int y1, int x2, int y2){
		if(g > 500)
			return 0.0;
		// An illegal rectangle
		if(x1>x2 || y1>y2)
			return 0.0;
		if(x1>=27 || x2<=-27 || y1>=81 || y2<=0)
			return 0.0;
		// All are included
		if(x1<=-27 && y1<=0 && x2>=27 && y2>=81)
			return 81+(500-g)*54;
		double res = 0;
		if(x1<=0 && x2>=0)
			res += max(min(54, y2)-max(0, y1), 0);
		// Left
		res += get(g+1, max(3*(y1-54), -27), max(-3*x2, 0), min(27, 3*(y2-54)), min(81, -3*x1))/(3.0);
		// Right
		res += get(g+1, max(-27, -(y2-54)*3), max(0, 3*x1), min(27, (-3)*(y1-54)), min(3*x2, 81))/(3.0);
		// North
		res += get(g+1, max(-27, 3*x1), max(0, 3*(y1-54)), min(3*x2, 27), min(3*(y2-54), 81))/(3.0);
		
		return res;
	}
};

double FractalPicture::getLength(int x1, int y1, int x2, int y2) {
	ans = 0;
	ans = get(1, x1, y1, x2, y2);
	return ans;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
