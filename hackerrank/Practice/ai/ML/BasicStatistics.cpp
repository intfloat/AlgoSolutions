#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int n;
	long long sum = 0;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		sum += t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());	
	// mean
	double mean = sum / (n * 1.0);
	cout << fixed << setprecision(1) << mean << endl;
	// median
	if (n % 2 == 1)
		cout << fixed << setprecision(1) << v[n/2] << endl;
	else
		cout << fixed << setprecision(1) << (v[(n/2)-1] + v[n/2]) / 2.0 << endl;
	// mode
	int index = 0;
	int mx = 1;
	int cur = 1;
	for (int i = 1; i < n; ++i) {
		if (v[i] == v[i-1]) {
			++cur;
			if (cur > mx) { mx = cur; index = i; }			
		}
		else {
			cur = 1;
		}
	}
	cout << v[index] << endl;
	// standard deviation
	double st = 0;
	for (int i = 0; i < n; ++i) {
		st += (v[i] - mean) * (v[i] - mean);
	}
	double sd = sqrt(st) / n;
	st = sqrt(st / n);	
	cout << fixed << setprecision(1) << st << endl;
	// 95% confidence interval
	cout << fixed << setprecision(1) << (mean - 1.96 * sd) << " " << (mean + 1.96 * sd) << endl;
	return 0;
}

