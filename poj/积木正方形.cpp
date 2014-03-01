#include <iostream>
#include <vector>
using namespace std;
int s;     //s，表示要组成的正方形的边长
int n;     //n(1<=n<=16)，表示积木的个数
int side[11];   //side[i]用来保存边长为i的小正方形的个数，这里约定正方形的边长最大为10
int cols[41];   //cols[i]表示第i列已经被占用的行数+1,即最小可用行起始
vector<int> result;
int backTrace(int a)
{
 int selectCol, minRow, i, j, flag;
 if (a == n) return 1;
 minRow = 41;
 for (i = 1; i <= s; ++i)
  if (cols[i] < minRow)
  {
   selectCol = i;
   minRow = cols[i];
  }
 for (i = 10; i > 0; --i)
 {
  if (side[i] && selectCol-1+i <= s && minRow-1+i <= s)
  {
   flag = 1;
   for (j = selectCol; j < selectCol + i; ++j)
    if (cols[j] > minRow)
    {
     flag = 0;
     break;
    }
   if (flag)
   {
    for (j = selectCol; j < selectCol + i; ++j) cols[j] += i;
    side[i]--;
    if (backTrace(a + 1)) return 1;
    else
    {
     for (j = selectCol; j < selectCol + i; ++j) cols[j] -= i;
     side[i]++;
    }
   }
  }
 }

 return 0;
}
int main()
{
 int cases = 0;
 int i, temp;
 cin>>cases;
 int area;
 while (cases > 0)
 {
  cases--;
  cin>>s>>n;
  memset(side, 0, sizeof(side));
  area = 0;
  for (i = 0; i < n; ++i)
  {
   cin>>temp;
   side[temp]++;
   area += temp * temp;
  }
  if (area != s * s)
   result.push_back(0);
  else
  {
   for (i = 1; i <= 40; ++i) cols[i] = 1;
   int rr = backTrace(0);
   result.push_back(rr);
  }
 }
 for (i = 0; i < result.size(); ++i)
  if (result[i]) cout<<"yes"<<endl;
  else cout<<"no"<<endl;
   system("pause");
 return 0;
}
 
