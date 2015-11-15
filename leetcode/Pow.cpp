class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(x==1.0)
            return x;
        if(x==-1.0 && n%2==0)
          return 1.0;
        else if(x==-1.0 && n%2==1)
            return -1.0;
          
        if(n<0)
            return 1.0/(pow(x, -n));
        if(n==0)
            return 1.0;
        if(n==1)
            return x;
        double tmp = pow(x, n/2);
        if(n%2 == 0)
            return tmp*tmp;
        else
            return tmp*tmp*x;
    }
};
