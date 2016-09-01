const int MDIR = 0;
const int MFILE = 1;
const int MOTHER = 2;
class Solution {
private:
    string s;
    int ptr;
    bool hasNext() {
        return (ptr < (int)s.size());
    }
    pair<string, int> next() {
        string res;
        if (s[ptr] == '\n' || s[ptr] == '\t') {
            res.push_back(s[ptr++]);
            return make_pair(res, MOTHER);
        } else {
            int type = MDIR;
            while (ptr < (int)s.size() && s[ptr] != '\n' && s[ptr] != '\t') {
                if (s[ptr] == '.') type = MFILE;
                res.push_back(s[ptr]);
                ++ptr;
            }
            return make_pair(res, type);
        }
    }

public:
    int lengthLongestPath(string input) {
        this->s = input;
        this->ptr = 0;
        vector<int> acc;
        int ret = 0;
        while (this->hasNext()) {
            int cur = 0;
            int tcnt = 0;
            while (this->hasNext()) {
                pair<string, int> r = this->next();
                if (r.first == "\t") {
                    assert(r.second == MOTHER);
                    ++tcnt;
                }
                else {
                    while ((int)acc.size() > tcnt) acc.pop_back();
                    if (r.second == MDIR) {
                        if (acc.empty()) acc.push_back(r.first.size());
                        else acc.push_back(r.first.size() + acc.back());
                    } else { // it is a file
                        cur = acc.empty() ? 0 : acc.back() + acc.size();
                        cur += r.first.size();
                    }
                    assert(!this->hasNext() || this->next().first == "\n");
                    break;
                }
            }
            ret = max(ret, cur);
        }
        return ret;
    }
};
