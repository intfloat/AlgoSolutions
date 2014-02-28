#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

// a * x + b * y = gcd(a, b), return gcd(a, b)
// answers will be stored in variables x and y
long long extGcd(long long a, long long b, long long& x, long long& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  } else {
    int g = extGcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
  }
}

// ASSUME: gcd(a, m) == 1, m is greater than a
// return minimal positive a^(-1) (mod m)
long long modInv(long long a, long long m) {
  long long x, y;
  extGcd(a, m, x, y);
  return (x % m + m) % m;
}

int main(){
    long long x, y;
    long long res = extGcd(7, 23, x, y);
    cout<<"x: "<<x<<endl;
    cout<<"y: "<<y<<endl;
    cout<<res<<endl;
    cout<<"Inverse: "<<modInv(7, 23)<<endl;
    cout<<"Q6: "<<(modInv(3, 19)*5)%19<<endl;
    res = 0;
    for(int i=1; i<35; i++){
        if(__gcd(i, 35) == 1) ++res;
    }
    cout<<"Q7: "<<res<<endl;
    return 0;
}
