#include <bits/stdc++.h>

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

template<int MOD>
struct ModInt {
    static const int Mod = MOD;
    unsigned x;
    ModInt(): x(0) { }
    ModInt(signed sig) { int sigt = sig % MOD; if(sigt < 0) sigt += MOD; x = sigt; }
    ModInt(signed long long sig) { int sigt = sig % MOD; if(sigt < 0) sigt += MOD; x = sigt; }
    int get() const { return (int)x; }

    ModInt &operator+=(ModInt that) { if((x += that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(ModInt that) { if((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }

    ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
    ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
    ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
};
typedef ModInt<1000000007> mint;

template<typename T>
static size_t &hash_combine(size_t &x, const T &y) {
    return x ^= hash<T>()(y) + 0x9e3779b9 + (x << 6) + (x >> 2);
}

struct State {
    static int Width;
    static const int MaxWidth = 8;
    char clus[MaxWidth+1];
    char hidden;
    char y, x;
    char edgenum;
    State addcell(bool b) const {
        State t;
        rep(i, Width) t.clus[i+1] = clus[i];
        int left = x == 0 ? -1 : 0, up = y == 0 ? -1 : Width-1;
        bool leftb = left != -1 && clus[left] != -1, upb = up != -1 && clus[up] != -1;
        if(!b) {
            t.clus[0] = -1;
        }else if(leftb && upb) {
            int leftc = clus[left], upc = clus[up];
            t.clus[0] = leftc;
            rep(i, Width+1) if(t.clus[i] == upc)
                t.clus[i] = leftc;
        }else if(leftb) {
            t.clus[0] = clus[left];
        }else if(upb) {
            t.clus[0] = clus[up];
        }else {
            t.clus[0] = Width+1;
        }
        t.renumber();
        bool newhidden =
            t.clus[Width] != -1 &&
            count(t.clus, t.clus + Width, t.clus[Width]) == 0;
        t.hidden = hidden + newhidden;
        t.clus[Width] = -1;
        if(x + 1 == Width) t.y = y + 1, t.x = 0;
        else t.y = y, t.x = x + 1;
        t.edgenum = edgenum + (!b ? 0 : 1 - leftb - upb);
        return t;
    }
    static State initState() {
        State s;
        rep(i, Width) s.clus[i] = -1;
        s.hidden = 0;
        s.y = s.x = 0;
        s.edgenum = 0;
        return s;
    }
    bool operator==(const State &that) const {
        bool b = true;
        rep(i, Width) b &= clus[i] == that.clus[i];
        b &= hidden == that.hidden;
        b &= y == that.y;
        b &= x == that.x;
        b &= edgenum == that.edgenum;
        return b;
    }
    struct Hash {
        size_t operator()(const State &s) const {
            size_t h = 0;
            rep(i, Width) hash_combine(h, s.clus[i]);
            hash_combine(h, s.hidden);
            hash_combine(h, s.y);
            hash_combine(h, s.x);
            hash_combine(h, s.edgenum);
            return h;
        }
    };
    int numClusters() const {
        char t[MaxWidth+1] = {};
        int cs = 0;
        rep(i, Width) {
            int x = clus[i];
            if(x != -1 && t[x] == 0)
                t[x] = ++ cs;
        }
        return cs;
    }
    bool isOK() const {
        int cc = hidden + numClusters();
        return (hidden + (numClusters() > 0)) <= 1 && edgenum == cc;
    }
    bool lastOK() const {
        int cc = hidden + numClusters();
        return cc <= 1 && edgenum == cc;
    }
private:
    void renumber() {
        char t[MaxWidth+2] = {};
        int cs = 0;
        rep(i, Width) {
            int x = clus[i];
            if(x != -1 && t[x] == 0)
                t[x] = ++ cs;
        }
        rep(i, Width)
            clus[i] = clus[i] == -1 ? -1 : t[clus[i]] - 1;
    }
};
int State::Width;

unordered_map<State,mint,State::Hash> memo;

int H, W;
char c[101][8+1];

mint rec(const State &s) {
    auto it = memo.find(s);
    if(it != memo.end()) return it->second;
    mint &r = memo[s];
    if(s.y == H)
        return r = s.lastOK() ? 1 : 0;
    r = mint();
    if(c[s.y][s.x] != '.') {
        State t = s.addcell(false);
        if(t.isOK()) r += rec(t);
    }
    if(c[s.y][s.x] != '#') {
        State t = s.addcell(true);
        if(t.isOK()) r += rec(t);
    }
    return r;
}

int main(){
    while(~scanf("%d%d", &H, &W)) {
        rep(i, H) scanf("%s", c[i]);
        State::Width = W;
        memo.clear();
        mint ans = rec(State::initState());
        printf("%d\n", ans.get());
    }
    return 0;
}
