#include <iostream>
#include <stdio.h>
#include <cmath>
#include <iomanip>

using namespace std;

const int MAX_N = 500005;
int main() {
	int n;
	int m[MAX_N], p[MAX_N], c[MAX_N];
	scanf("%d", &n);
	for (int i=0; i<n; ++i)  scanf("%d%d%d", m+i, p+i, c+i);
	long long m_sum = 0;
	long long p_sum = 0;
	long long c_sum = 0;
	long long m_sq_sum = 0;
	long long p_sq_sum = 0;
	long long c_sq_sum = 0;
	for (int i = 0; i < n; ++i) {
		m_sum += m[i]; m_sq_sum += m[i] * m[i];
		p_sum += p[i]; p_sq_sum += p[i] * p[i];
		c_sum += c[i]; c_sq_sum += c[i] * c[i];
	}
	long long mp = 0;
	long long mc = 0;
	long long pc = 0;
	for (int i = 0; i < n; ++i) {
		mp += m[i] * p[i];
		mc += m[i] * c[i];
		pc += p[i] * c[i];
	}
	double sm = sqrt(n * m_sq_sum - m_sum * m_sum);
	double sp = sqrt(n * p_sq_sum - p_sum * p_sum);
	double sc = sqrt(n * c_sq_sum - c_sum * c_sum);
	double rmp = (n * mp - m_sum * p_sum) / (sm * sp);
	double rmc = (n * mc - m_sum * c_sum) / (sm * sc);
	double rpc = (n * pc - p_sum * c_sum) / (sp * sc);
	cout << fixed << setprecision(2) << rmp << endl;
	cout << fixed << setprecision(2) << rpc << endl;
	cout << fixed << setprecision(2) << rmc << endl;
	return 0;
}
