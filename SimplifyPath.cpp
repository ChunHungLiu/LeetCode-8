class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dir;
        
        size_t found = path.find_first_of('/', 0);
        while (found != string::npos) {
            size_t nxt = path.find_first_of('/', found+1);
            string name = (nxt == string::npos) ? path.substr(found+1) : path.substr(found+1, nxt-found-1);
            if (name == "..") { 
                if (dir.size() > 0) { dir.pop_back(); }
            } else {
                if (name.size() > 0 && name != ".") { dir.push_back(name); }
            }
            found = nxt;
        }

        string res = "/";
        for (int i = 0; i < dir.size(); ++i) {
            res += dir[i];
            if (i != dir.size()-1) { res += "/"; }
        }

        return res;
    }
};