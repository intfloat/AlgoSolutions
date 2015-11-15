// WildcardMatching.cpp
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!*s && !*p) return true;

        int ms_max = 1;//size of *s
        const char* ss = s;
        while(*ss){ ++ms_max;++ss;}
        int np_max = 1;
        const char* pp = p;
        while(*pp){if(*pp!='*')++np_max;++pp;}
        if(ms_max < np_max) return false;

        vector<vector<bool> > r(2, vector<bool>(ms_max, false));
        bool flag = 1;
        r[0][0] = true;
        do{//*p
            int ms = 1;
            ss = s;
            if (*p == '*'){
                while(*p == '*') ++p;
                --p;
                r[flag][0] = r[!flag][0];
                for( ;ms <= ms_max; ++ms){//up and left
                    if (r[!flag][ms] || r[flag][ms-1]) break;
                    else r[flag][ms] = false;
                }
                for(;ms <= ms_max; ++ms){
                    r[flag][ms] = true;
                }
            }
            else{
                do{
                    bool r_flag = false;
                    if (*ss == *p || *p == '?'){
                        r_flag = r[!flag][ms-1];//diagnal
                    }
                    r[flag][ms]=r_flag;
                    ++ms;++ss;
                }while(*ss);//*s
                r[flag][0] = false;
            }
            ++p;
            flag = !flag;
        }while(*p);
        return r[!flag][ms_max-1];
    }
};
