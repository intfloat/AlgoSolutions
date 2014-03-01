#include <iostream>
#include <vector>
using namespace std;
int s;     //s����ʾҪ��ɵ������εı߳�
int n;     //n(1<=n<=16)����ʾ��ľ�ĸ���
int side[11];   //side[i]��������߳�Ϊi��С�����εĸ���������Լ�������εı߳����Ϊ10
int cols[41];   //cols[i]��ʾ��i���Ѿ���ռ�õ�����+1,����С��������ʼ
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
 
