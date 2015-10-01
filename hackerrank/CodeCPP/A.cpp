#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;
class Student {
private:
    int total;
public:
    Student(): total(0) {}
    void Input() {
        for (int i = 0; i < 5; ++i) {
            int score;
            scanf("%d", &score);
            this->total += score;
        }
    }
    int CalculateTotalScore() {
        return this->total;
    }
};
int main() {
   int n;
     cin>>n;
     Student s[n];
     for(int i=0;i<n;i++)
      s[i].Input();
     int count=0;
     int krish_score=s[0].CalculateTotalScore();
     for(int i=1;i<n;i++)
    {
      int total=s[i].CalculateTotalScore();
      if(total>krish_score)
        count++;
    }
     cout<<count;
    return 0;
}
