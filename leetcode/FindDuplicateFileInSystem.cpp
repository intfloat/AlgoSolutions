class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> res;
        map<string, vector<string> > content2path;
        for (auto& path : paths) {
            bool in_dir = true, in_name = false, in_content = false;
            string dir, name, content;
            for (int i = 0; i < path.size(); ++i) {
                if (in_dir && path[i] != ' ') {
                    dir.push_back(path[i]);
                } else if (in_dir && path[i] == ' ') {
                    in_dir = false;
                    dir.push_back('/');
                    in_name = true;
                } else if (in_name && path[i] != '(' && path[i] != ' ') {
                    name.push_back(path[i]);
                } else if (in_name && path[i] == '(') {
                    in_name = false;
                    in_content = true;
                } else if (in_content && path[i] != ')') {
                    content.push_back(path[i]);
                } else if (in_content && path[i] == ')') {
                    in_content = false;
                    in_name = true;
                    if (content2path.find(content) == content2path.end()) {
                        vector<string> v;
                        content2path[content] = v;
                    }
                    content2path[content].push_back(dir + name);
                    content.clear();
                    name.clear();
                }
            }
        }
        for (auto it = content2path.begin(); it != content2path.end(); ++it) {
            if (it->second.size() > 1) {
                res.push_back(it->second);
            }
        }
        return res;
    }
};
