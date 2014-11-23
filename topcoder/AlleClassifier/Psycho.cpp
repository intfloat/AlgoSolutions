const int RANDOM_FEATURES = 5;
const int RANDOM_POSITIONS = 4;
const int TREES_NO = 250;
const double TIME_LIMIT = 58.0;
const bool FORCE_CLASS_1 = true;
const bool FORCE_CLASS_6 = false;

#define TIMERS

#include <cassert>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>
#include <sstream>
#include <set>
#include <map>
//#include <pmmintrin.h>
#include <sys/time.h>

using namespace std;

#define INLINE   inline __attribute__ ((always_inline))
#define NOINLINE __attribute__ ((noinline))

#define ALIGNED __attribute__ ((aligned(16)))

#define likely(x)   __builtin_expect(!!(x),1)
#define unlikely(x) __builtin_expect(!!(x),0)

#define SSELOAD(a)     _mm_load_si128((__m128i*)&a)
#define SSESTORE(a, b) _mm_store_si128((__m128i*)&a, b)

#define FOR(i,a,b)  for(int i=(a);i<(b);++i)
#define REP(i,a)    FOR(i,0,a)
#define ZERO(m)     memset(m,0,sizeof(m))
#define ALL(x)      x.begin(),x.end()
#define PB          push_back
#define S           size()
#define LL          long long
#define ULL         unsigned long long
#define LD          long double
#define MP          make_pair
#define X           first
#define Y           second
#define VC          vector
#define PII         pair <int, int>
#define VI          VC < int >
#define VVI         VC < VI >
#define VVVI        VC < VVI >
#define VPII        VC < PII >
#define VD          VC < double >
#define VVD         VC < VD >
#define VS          VC < string >
#define VVS         VC < VS >
#define DB(a)       cerr << #a << ": " << (a) << endl;

template<class T> void print(VC < T > v) {cerr << "[";if (v.S) cerr << v[0];FOR(i, 1, v.S) cerr << ", " << v[i];cerr << "]" << endl;}
template<class T> string i2s(T x) {ostringstream o; o << x; return o.str();}
VS splt(string s, char c = ' ') {VS all; int p = 0, np; while (np = s.find(c, p), np >= 0) {if (np != p) all.PB(s.substr(p, np - p)); p = np + 1;} if (p < s.S) all.PB(s.substr(p)); return all;}

ULL getTicks() {
#ifdef __i386
    ULL time;
    __asm__ volatile ("rdtsc" : "=A" (time));
    return time;
#else
    ULL timelo, timehi;
    __asm__ volatile ("rdtsc" : "=a" (timelo), "=d" (timehi));
    return (timehi << 32) + timelo;
#endif
}

double convertTicks(ULL time) {
#ifdef LOCAL
    return time / 3.3e9;
#else
    return time / 1.8e9;
#endif
}

double getTime() {
    // return convertTicks(getTicks());
	timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec + 1e-6 * tv.tv_usec;
}


struct RNG {
    unsigned int MT[624];
    int index;
    
    void init(int seed = 1) {
        MT[0] = seed;
        FOR(i, 1, 624) MT[i] = (1812433253UL * (MT[i-1] ^ (MT[i-1] >> 30)) + i);
        index = 0;
    }
    
    void generate() {
        const unsigned int MULT[] = {0, 2567483615UL};
        REP(i, 227) {
            unsigned int y = (MT[i] & 0x8000000UL) + (MT[i+1] & 0x7FFFFFFFUL);
            MT[i] = MT[i+397] ^ (y >> 1);
            MT[i] ^= MULT[y&1];
        }
        FOR(i, 227, 623) {
            unsigned int y = (MT[i] & 0x8000000UL) + (MT[i+1] & 0x7FFFFFFFUL);
            MT[i] = MT[i-227] ^ (y >> 1);
            MT[i] ^= MULT[y&1];
        }
        unsigned int y = (MT[623] & 0x8000000UL) + (MT[0] & 0x7FFFFFFFUL);
        MT[623] = MT[623-227] ^ (y >> 1);
        MT[623] ^= MULT[y&1];
    }
    
    unsigned int rand() {
        if (index == 0) {
            generate();
        }
        
        unsigned int y = MT[index];
        y ^= y >> 11;
        y ^= y << 7  & 2636928640UL;
        y ^= y << 15 & 4022730752UL;
        y ^= y >> 18;
        index = index == 623 ? 0 : index + 1;
        return y;
    }
    
    INLINE int next(int x) {
        return rand() % x;
    }
    
    INLINE int next(int a, int b) {
        return a + (rand() % (b - a));
    }
    
    INLINE double nextDouble() {
        return (rand() + 0.5) * (1.0 / 4294967296.0);
    }
};

static RNG rng;

struct Timer {
#ifdef TIMERS
    ULL ticks;
    const string name;
    bool running;
    int count;
    int count2;

    Timer(string _name) : name(_name) {
        ticks = 0;
        count = 0;
        count2 = 0;
        running = false;
    }
    
    INLINE void clear() {
        ticks = 0;
        count = 0;
        count2 = 0;
        running = false;
    }
   
    INLINE void start() {
        if (running) return;
        ticks = getTicks() - ticks;
        running = true;
    }
   
    INLINE void stop() {
        if (!running) return;
        ticks = getTicks() - ticks;
        running = false;
        count++;
    }
   
    INLINE void stop(int add) {
        if (!running) return;
        ticks = getTicks() - ticks;
        running = false;
        count++;
        count2 += add;
    }
   
    INLINE double elapsed() {
        return convertTicks(running ? getTicks() - ticks : ticks);
    }
   
    void show() {
        if (count == 0 && count2 == 0) return;
        cerr << name << ": " << elapsed() << " count: " << count;
        if (count2) cerr << " - " << count2;
        cerr << endl;
    }
#else
    Timer(string) { }
    double elapsed() { }
    void start() { }
    void stop() { }
    void stop(int add) { }
    void show() { }
#endif
};

struct TreeNode {
	bool leaf;
	
	int level;
	int feature;
	double value;
	double result;
	int left;
	int right;
	
	TreeNode() {
		leaf = false;
		level = -1;
		feature = -1;
		value = 0;
		result = 0;
		left = -1;
		right = -1;
	}
};

double maxZClass1;
double minZClass6;

class DecisionTree {
	public:
	VC < TreeNode > nodes;
	VI oobSamples;
	
	DecisionTree() { }
	
	DecisionTree(VVD &features, VD &results, int minNodeSize, int maxLevel = 18) {
		int curNode = 0;
		
		TreeNode root;
		root.level = 0;
		nodes.PB(root);
		
		set < int > groupsSet;
		REP(i, features.S) groupsSet.insert(features[i][0]);
		VI groups(ALL(groupsSet));
		
		// random_shuffle(ALL(groups));
		VI chosenGroups(groups.S);
		REP(i, groups.S + groups.S) chosenGroups[rng.next(groups.S)]++;
		
		VI rootBag;
		REP(i, features.S) REP(j, chosenGroups[features[i][0]]) rootBag.PB(i);
		// REP(i, features.S) if (rng.nextDouble() < 0.7) rootBag.PB(i);
		// REP(i, features.S) rootBag.PB(rng.next(features.S));
		
		VI used(features.S);
		REP(i, rootBag.S) used[rootBag[i]] = 1;
		REP(i, features.S) if (used[i] == 0) oobSamples.PB(i);
		
		
		VVI nodeBags;
		nodeBags.PB(rootBag);
		
		
		while (curNode < nodes.S) {
			TreeNode &node = nodes[curNode];
			
			bool equal = true;
			FOR(i, 1, nodeBags[curNode].S) if (results[nodeBags[curNode][i]] != results[nodeBags[curNode][i - 1]]) {
				equal = false;
				break;
			}
			
			if (equal || nodeBags[curNode].S <= minNodeSize || node.level >= maxLevel) {
				node.leaf = true;
				for (int p : nodeBags[curNode]) node.result += results[p];
				assert(nodeBags[curNode].S > 0);
				if (nodeBags[curNode].S) node.result /= nodeBags[curNode].S;
				curNode++;
				continue;
			}
			
			int bestFeature = -1;
			int bestLeft, bestRight;
			double bestValue = 0;
			double bestMSE = 1e99;
			
			REP(i, RANDOM_FEATURES) {
				int featureID = 1 + rng.next(features[0].S - 1);
				REP(j, RANDOM_POSITIONS) {
					double splitValue = features[nodeBags[curNode][rng.next(nodeBags[curNode].S)]][featureID];
					double sumLeft = 0;
					double sumRight = 0;
					int totalLeft = 0;
					int totalRight = 0;
					for (int p : nodeBags[curNode]) {
						if (features[p][featureID] < splitValue) {
							sumLeft += results[p];
							totalLeft++;
						} else {
							sumRight += results[p];
							totalRight++;
						}
					}
					
					if (totalLeft == 0 || totalRight == 0)
						continue;
					
					double meanLeft = totalLeft == 0 ? 0 : sumLeft / totalLeft;
					double meanRight = totalRight == 0 ? 0 : sumRight / totalRight;
					
					double mse = 0;
					for (int p : nodeBags[curNode]) {
						if (features[p][featureID] < splitValue) {
							mse += (results[p] - meanLeft)  * (results[p] - meanLeft);
						} else {
							mse += (results[p] - meanRight) * (results[p] - meanRight);
						}
					}
					
					if (mse < bestMSE) {
						bestMSE = mse;
						bestValue = splitValue;
						bestFeature = featureID;
						bestLeft = totalLeft;
						bestRight = totalRight;
					}
				}
			}
			
			if (bestLeft == 0 || bestRight == 0) {
				node.leaf = true;
				for (int p : nodeBags[curNode]) node.result += results[p];
				assert(nodeBags[curNode].S > 0);
				if (nodeBags[curNode].S) node.result /= nodeBags[curNode].S;
				curNode++;
				continue;
			}
			
			double nextValue = -1e99;
			for (int p : nodeBags[curNode]) if (features[p][bestFeature] < bestValue) nextValue = max(nextValue, features[p][bestFeature]);
			
			TreeNode left;
			TreeNode right;
			
			left.level = right.level = node.level + 1;
			node.feature = bestFeature;
			node.value = (bestValue + nextValue) / 2.0;
			node.left = nodes.S;
			node.right = nodes.S + 1;
			
			nodeBags.PB(VI(bestLeft));
			nodeBags.PB(VI(bestRight));
			for (int p : nodeBags[curNode]) {
				if (features[p][node.feature] < node.value) {
					nodeBags[node.left][--bestLeft] = p;
				} else {
					nodeBags[node.right][--bestRight] = p;
				}
			}
			
			nodes.PB(left);
			nodes.PB(right);
			curNode++;
		}
	}
	
	double estimate(VD &features) {
		TreeNode *pNode = &nodes[0];
		while (true) {
			if (pNode->leaf) return pNode->result;
			pNode = &nodes[features[pNode->feature] < pNode->value ? pNode->left : pNode->right];
		}
	}
};

class RandomForest {
	VC < DecisionTree > trees;
	VVD features;
	VD results;

	public:
	void clear() {
		features.clear();
		results.clear();
		trees.clear();
	}
	
	void train(VVD &_features, VD &_results, int treesNo = 100, int minNodeSize = 100) {
		if (features.S == 0) {
			features = _features;
			results = _results;
		}
		assert(features.S == results.S);
		REP(i, treesNo) trees.PB(DecisionTree(_features, _results, minNodeSize));
	}
	
	double estimate(VD &features) {
		if (trees.S == 0) return 0.0;
	
		double sum = 0;
		REP(i, trees.S) sum += trees[i].estimate(features);
		return sum / trees.S;
	}
	
	double estimateLastTree(VD &features) {
		if (trees.S == 0) return 0.0;
		return trees[trees.S - 1].estimate(features);
	}
	
	VD calcOOB() {
		VD w(features.S);
		VD v(features.S);
		VD rv(features.S);
		for (auto t : trees) for (int i : t.oobSamples) {
			v[i] += t.estimate(features[i]);;
			w[i] += 1;
		}
		
		REP(i, rv.S) rv[i] = v[i] / w[i];
		return rv;
	}
	
};

int groupID(string s) {
	return s == "0" ? 0 : s == "0 or 1" ? 1 : s == "1" ? 2 : s == "1 or 2" ? 3 : s == "2" ? 4 : 5;
}

VVD extractFeatures(VVS &data) {
	map<string, VI> sets;
	REP(i, data.S) sets[data[i][0]].PB(i);
	
	VVD rv(data.S);
	int group = 0;
	for (auto p : sets) {
		VD vx, vy, vz;
		VI vp, vi;
		for (int i : p.Y) {
			double x = atof(data[i][2].c_str());
			double y = atof(data[i][3].c_str());
			double z = x - y;
			vi.PB(atoi(data[i][1].c_str()));
			vp.PB(i);
			vx.PB(x);
			vy.PB(y);
			vz.PB(z);
		}
		
		VI tvi(ALL(vi));
		sort(ALL(tvi));
		int maxID = tvi[tvi.S - 1];
		// map<int, int> mvi;
		// REP(i, tvi.S) mvi[tvi[i]] = i;
		// REP(i, vi.S) vi[i] = mvi[vi[i]];
		
		
		int n = vp.S;
		
		const double MP_GEN[][3] = {
			// {2.0, 0.1, 0.0}, 
			// {2.0, 0.25, 0.0}, 
			// {2.0, 1.0, 0.0}, 
			// {2.0, 1.0, -0.05}, 
			// {2.5, 1.0, 0.0}, 
			// {2.5, 1.0, -0.05}, 
			// {3.0, 0.1, -0.05},
			// {3.0, 1.0, 0.0}, 
			// {3.0, 1.0, -0.05}};
			{2.0, 0.1, 0.0},
			{2.0, 0.25, 0.0},
			{2.0, 1.0, 0.0},
			{3.0, 0.1, -0.0},
			{3.0, 0.25, -0.25},
			{3.0, 1.0, -0.5}};
			
		const int MP_NO = sizeof(MP_GEN)/sizeof(double[3]);
		double MPs[MP_NO];
		double MPAs[MP_NO];
		double MPBs[MP_NO];
		VD MP_SCORE[MP_NO];
		VD MP_SCOREA[MP_NO];
		VD MP_SCOREB[MP_NO];
		REP(i, MP_NO) {
			REP(j, n) {
				double av = 0;
				double pa = 0, pb = 0;
				REP(k, n) if (j != k) {
					double v = 1.0 / (MP_GEN[i][1] + pow(abs(vz[j] - vz[k]), MP_GEN[i][0]));
					av += v;
					if (vz[k] < vz[j]) pa += v; else pb += v;
				}
				av += vz[j] * MP_GEN[i][2];
				MP_SCORE[i].PB(av);
				MP_SCOREA[i].PB(pa);
				MP_SCOREB[i].PB(pb);
			}
			double bv;
			bv = -1e99; REP(j, n) if (MP_SCORE[i][j] > bv) MPs[i] = vz[j], bv = MP_SCORE[i][j];
			bv = -1e99; REP(j, n) if (MP_SCOREA[i][j] > bv) MPAs[i] = vz[j], bv = MP_SCOREA[i][j];
			bv = -1e99; REP(j, n) if (MP_SCOREB[i][j] > bv) MPBs[i] = vz[j], bv = MP_SCOREB[i][j];
		}
		
		VC < pair < double, int > > sortedZ; REP(i, n) sortedZ.PB(MP(vz[i], i));
		sort(ALL(sortedZ));
		VI vo(n); REP(i, n) vo[sortedZ[i].Y] = i;
		
		REP(i, n) {
			VD v;
			
			v.PB(group);
			v.PB(vz[i]);
			v.PB(n);
			v.PB(vx[i]);
			v.PB(vy[i]);
			// v.PB(vi[i] == n - 1 ? 1 : 1. * vi[i] / (n - 1));
			// v.PB(vi[i]);
			v.PB((double)maxID / n);
			v.PB(min(vx[i], vy[i]));
			// v.PB(max(vx[i], vy[i]));
			REP(j, MP_NO) v.PB(vz[i] - MPs[j]);
			// REP(j, MP_NO) v.PB(vz[i] - MPAs[j]);
			
			int pz = 0; REP(j, n) if (sortedZ[j].X == MPs[1]) pz = j;
			int opz = pz;
			double maxDist = 0;
			double dd15 = 0;
			double dd14 = 0;
			double dd13 = 0;
			double dd12 = 0;
			while (vz[i] != sortedZ[pz].X) {
				int npz = vz[i] > sortedZ[pz].X ? pz + 1 : pz - 1;
				maxDist = max(maxDist, abs(sortedZ[pz].X - sortedZ[npz].X));
				dd15 += pow(abs(sortedZ[pz].X - sortedZ[npz].X), 1.5);
				dd14 += pow(abs(sortedZ[pz].X - sortedZ[npz].X), 1.4);
				dd13 += pow(abs(sortedZ[pz].X - sortedZ[npz].X), 1.3);
				dd12 += pow(abs(sortedZ[pz].X - sortedZ[npz].X), 1.2);
				pz = npz;
			}
			v.PB(vz[i] > MPs[1] ? maxDist : -maxDist);
			// v.PB(vz[i] > MPs[1] ? dd12 : -dd12);
			v.PB(vz[i] > MPs[1] ? dd15 : -dd15);
			// v.PB(vz[i] > MPs[1] ? dd25 : -dd25);
			// v.PB(vz[i] > MPs[1] ? dd30 : -dd30);
			// v.PB(vz[i] > MPs[1] ? dd / n : -dd / n);
			// sort(ALL(dist));
			// v.PB(vz[i] > MPs[1] ? dist[dist.S / 2] : dist[dist.S / 2]);
			
			
			double avg = 0;
			int no = 0;
			FOR(j, min(opz, vo[i]), max(opz, vo[i]) + 1) avg += sortedZ[j].X, no++;
			assert(no > 0);
			avg /= no;
			double stddev = 0;
			FOR(j, min(opz, vo[i]), max(opz, vo[i]) + 1) stddev += (sortedZ[j].X - avg) * (sortedZ[j].X - avg);
			stddev /= no;
			stddev = sqrt(stddev);
			v.PB(stddev);			
			
			// double spacing[] = {0.10, 0.25, 0.50, 0.75, 1.25};
			double spacing[] = {0.10, 0.25, 0.50, 0.75};
			// double spacing[] = {0.10, 0.15, 0.25, 0.35, 0.50};
			REP(j, sizeof(spacing)/sizeof(double)) {
				pz = opz;
				double d = 0;
				while (pz && sortedZ[pz - 1].X + spacing[j] > sortedZ[pz].X) d += sortedZ[pz].X - sortedZ[pz - 1].X, pz--;
				double startLen = d;
				int startNo = abs(opz - pz);
				pz = opz;
				d = 0;
				while (pz < n - 1 && sortedZ[pz + 1].X - spacing[j] < sortedZ[pz].X) d -= sortedZ[pz].X - sortedZ[pz + 1].X, pz++;
				double endLen = d;
				int endNo = abs(opz - pz);
				v.PB(startLen);
				// v.PB(startNo);
				// v.PB(endLen);
				// v.PB(endNo);
				// v.PB(startLen + endLen > 0 ? startLen / (startLen + endLen) : -1);
			}
			
			
			/*
			REP(j, n) if (sortedZ[j].X == MPs[4]) opz = j;
			REP(j, sizeof(spacing)/sizeof(double)) {
				pz = opz;
				double d = 0;
				while (pz && sortedZ[pz - 1].X + spacing[j] > sortedZ[pz].X) d += sortedZ[pz].X - sortedZ[pz - 1].X, pz--;
				double startLen = d;
				int startNo = abs(opz - pz);
				pz = opz;
				d = 0;
				while (pz < n - 1 && sortedZ[pz + 1].X - spacing[j] < sortedZ[pz].X) d -= sortedZ[pz].X - sortedZ[pz + 1].X, pz++;
				double endLen = d;
				int endNo = abs(opz - pz);
				v.PB(startLen);
				// v.PB(startNo);
				// v.PB(endLen);
				// v.PB(endNo);
				// v.PB(startLen + endLen > 0 ? startLen / (startLen + endLen) : -1);
			}
			*/
			
			v.PB((double)vo[i] / n);
			
			// v.PB(group);
			// v.PB(vz[i]);
			// v.PB(vx[i]);
			// v.PB(vy[i]);
			
			rv[vp[i]] = v;
			
			
			
		}
		group++;
	}
	
	return rv;
}

RandomForest rf[6];

/*
void train(VVS &data, bool useTime = false) {
	double xTime = getTime();

	maxZClass1 = 1e6;
	minZClass6 = -1e6;
	REP(i, data.S) {
		double z = atof(data[i][2].c_str()) - atof(data[i][3].c_str());
		int group = groupID(data[i][4]);
		if (group != 0) maxZClass1 = min(maxZClass1, z);
		if (group != 5) minZClass6 = max(minZClass6, z);
	}
	
	VVD features = extractFeatures(data);
	VI groups;
	REP(i, data.S) groups.PB(groupID(data[i][4]));
	VD results[6];
	REP(i, 6) {
		rf[i].clear();
		REP(j, groups.S) results[i].PB(groups[j] == i);
	}
	
	if (useTime) {
		int treesNo = 0;
		while (getTime() - xTime < TIME_LIMIT) {
			REP(i, 6) rf[i].train(features, results[i], 1, 1);
			treesNo++;
		}
		DB(treesNo);
	} else {
		REP(i, 6) rf[i].train(features, results[i], TREES_NO, 1);
	}
	
	// DB(getTime() - xTime);
}

VI predict(VVS &data, bool boost = true) {
	double xTime = getTime();
	VVD features = extractFeatures(data);
	VI rv;
	REP(i, data.S) {
		VD v(6);
		REP(j, 6) v[j] = rf[j].estimate(features[i]);
		int bv = 0;
		if (boost) {
			// v[0] = v[0] * 1.35 + 0.10;
			// v[1] = v[1] * 1.35 + 0.10;
			// v[5] = v[5] * 1.35 + 0.10;
			v[0] = v[0] * 1.1 + 0.20;
			v[1] = v[1] * 1.1 + 0.20;
			v[5] = v[5] * 1.1 + 0.20;
		}
		REP(j, 6) if (v[j] > v[bv]) bv = j;
		
		double z = atof(data[i][2].c_str()) - atof(data[i][3].c_str());
		if (FORCE_CLASS_1 && z < maxZClass1) bv = 0;
		if (FORCE_CLASS_6 && z > minZClass6) bv = 5;
		
		rv.PB(bv);
	}
	// DB(getTime() - xTime);
	return rv;
}
*/

double startTime = 0;

VI trainAndPredict(VVS &train, VVS &test, bool useTime = false, bool boost = true) {
	maxZClass1 = 1e6;
	minZClass6 = -1e6;
	REP(i, train.S) {
		double z = atof(train[i][2].c_str()) - atof(train[i][3].c_str());
		int group = groupID(train[i][4]);
		if (group != 0) maxZClass1 = min(maxZClass1, z);
		if (group != 5) minZClass6 = max(minZClass6, z);
	}
	
	VVD trainFeatures = extractFeatures(train);
	VVD testFeatures = extractFeatures(test);
	
	VI groups;
	REP(i, train.S) groups.PB(groupID(train[i][4]));
	VD results[6];
	REP(i, 6) {
		rf[i].clear();
		REP(j, groups.S) results[i].PB(groups[j] == i ? 1.0 : 0.0);
	}
	
	VVD pred(test.S, VD(6, 0));
	
	int treesNo = 0;
	
	while (true) {
		if (!useTime && treesNo >= TREES_NO || useTime && getTime() - startTime > TIME_LIMIT) break;
		REP(i, 6) {
			rf[i].train(trainFeatures, results[i], 1, 1);
			REP(j, test.S) pred[j][i] += rf[i].estimateLastTree(testFeatures[j]);
		}
		treesNo++;
	}
	if (useTime) DB(treesNo);
	
	REP(i, test.S) REP(j, 6) pred[i][j] /= treesNo;
	
	VI rv;
	REP(i, test.S) {
		int bv = 0;
		if (boost) {
			pred[i][0] = pred[i][0] * 1.1 + 0.20;
			pred[i][1] = pred[i][1] * 1.1 + 0.20;
			pred[i][5] = pred[i][5] * 1.1 + 0.20;
		}
		REP(j, 6) if (pred[i][j] > pred[i][bv]) bv = j;
		
		double z = atof(test[i][2].c_str()) - atof(test[i][3].c_str());
		if (FORCE_CLASS_1 && z < maxZClass1) bv = 0;
		if (FORCE_CLASS_6 && z > minZClass6) bv = 5;
		
		rv.PB(bv);
	}
	
	return rv;
}

/*
VI predict(VVS &data, bool boost = true) {
	double xTime = getTime();
	VVD features = extractFeatures(data);
	VI rv;
	REP(i, data.S) {
		VD v(6);
		REP(j, 6) v[j] = rf[j].estimate(features[i]);
		int bv = 0;
		if (boost) {
			// v[0] = v[0] * 1.35 + 0.10;
			// v[1] = v[1] * 1.35 + 0.10;
			// v[5] = v[5] * 1.35 + 0.10;
			v[0] = v[0] * 1.1 + 0.20;
			v[1] = v[1] * 1.1 + 0.20;
			v[5] = v[5] * 1.1 + 0.20;
		}
		REP(j, 6) if (v[j] > v[bv]) bv = j;
		
		double z = atof(data[i][2].c_str()) - atof(data[i][3].c_str());
		if (FORCE_CLASS_1 && z < maxZClass1) bv = 0;
		if (FORCE_CLASS_6 && z > minZClass6) bv = 5;
		
		rv.PB(bv);
	}
	// DB(getTime() - xTime);
	return rv;
}

VI predictOOB(VVS &data, bool boost = true) {
	VD v[6];
	REP(i, 6) v[i] = rf[i].calcOOB();
	
	VI rv;
	REP(i, v[0].S) {
		int bv = 0;
		if (boost) {
			v[0][i] = v[0][i] * 1.35 + 0.10;
			v[1][i] = v[1][i] * 1.35 + 0.10;
			v[5][i] = v[5][i] * 1.35 + 0.10;
		}
		REP(j, 6) if (v[j][i] > v[bv][i]) bv = j;
		double z = atof(data[i][2].c_str()) - atof(data[i][3].c_str());
		if (FORCE_CLASS_1 && z < maxZClass1) bv = 0;
		if (FORCE_CLASS_6 && z > minZClass6) bv = 5;
		rv.PB(bv);
	}
	return rv;
}*/

double score(VI &predicted, VI &correct, bool simple = false) {
	int score = 0;
	if (simple) {
	REP(i, predicted.S)
		score += predicted[i] == correct[i] ? 2 : 0;
	} else {
		REP(i, predicted.S)
			score += predicted[i] == correct[i] ? 2 : predicted[i] >= 2 && predicted[i] <= 4 && (correct[i] < 2 || correct[i] > 4) ? 0 : 1;
	}
	return 1e6 * score / 2 / correct.S;
}

class AlleleClassifier{public: VS classify(VS &_trainingData, VS &_testData) {
	startTime = getTime();

	rng.init(1);
		
	VVS trainingData, testData;
	for (string s : _trainingData) trainingData.PB(splt(s, ','));
	for (string s : _testData) testData.PB(splt(s, ','));

	// train(trainingData, true);
	// VI prediction = predict(testData);
	VI prediction = trainAndPredict(trainingData, testData, true);
	VS rv;
	string groups[] = {"0", "0 or 1", "1", "1 or 2", "2", ">2"};
	REP(i, prediction.S) rv.PB(groups[prediction[i]]);
	return rv;
}};