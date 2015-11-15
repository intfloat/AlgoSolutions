// PalindromePartitioning.cpp
class Solution {
public:
    bool pal[1500][1500];
    int len;
    void preprocess(string s){
        for(int i=0; i<len; i++)
            for(int j=i; j<len; j++)
                pal[i][j] = false;
        int left, right;
        for(int i=0; i<len; i++){
            left = right = i;
            while(left>=0 && right<len && s[left]==s[right])
                pal[left--][right++] = true;
        }
        for(int i=0; i<len; i++){
            left = i; right = i+1;
            while(left>=0 && right<len && s[left]==s[right])
                pal[left--][right++] = true;
        }
        return;
    }

    vector<vector<string> > partition(string s) {
        vector<vector<string> > res[2000];
        len = s.size();
        for(int i=0; i<len; i++) res[i].clear();
        preprocess(s);
        vector<string> cur;
        cur.clear(); cur.push_back(s.substr(0, 1));
        res[0].push_back(cur);
        for(int i=1; i<len; i++){
            if(pal[0][i]){
                cur.clear(); cur.push_back(s.substr(0, i+1));
                res[i].push_back(cur);
            }           
            for(int j=i; j>0; j--){
                if(pal[j][i]){
                    string last = s.substr(j, i-j+1);
                    for(int k=0; k<res[j-1].size(); k++){
                        cur = res[j-1][k];
                        cur.push_back(last);
                        res[i].push_back(cur);
                    }
                }// end if clause
            }// end internal for loop
        }// end external for loop
        return res[len-1];
    }
};