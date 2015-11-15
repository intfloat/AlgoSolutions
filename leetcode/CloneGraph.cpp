// CloneGraph.cpp

#include <map>
#include <set>

using namespace std;
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *root;
    map<int, UndirectedGraphNode *> m;
    set<UndirectedGraphNode *> visited;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==NULL) return NULL;
        m.clear(); visited.clear();
        root = new UndirectedGraphNode(node->label);
        m[node->label] = root;
        clone(root, node);
        return root;
    }

    // clone the graph recursively
    void clone(UndirectedGraphNode *cnode, UndirectedGraphNode *onode){
        // avoid visiting same node more than once
        if(visited.find(cnode)!=visited.end()) return;
        vector<UndirectedGraphNode *> nei = onode->neighbors;
        for(int i=0; i<nei.size(); i++){
            UndirectedGraphNode *t = NULL;
            // never seen this node
            if(m.find(nei[i]->label) == m.end()){
                t = new UndirectedGraphNode(nei[i]->label);
                m[nei[i]->label] = t;
                (cnode->neighbors).push_back(t);
            }
            // already seen this node
            else{
                t = m[nei[i]->label];
                (cnode->neighbors).push_back(t);
            }
        }
        visited.insert(cnode);
        for(int i=0; i<nei.size(); i++){
            clone((cnode->neighbors)[i], nei[i]);
        }
        return;
    }

};