/*
Used 30+min
should split in the process when the first version.
71. Simplify Path

*/
class Solution {
private:
    vector<string> split_slash(string path) {
        vector<string>ans;
        string cur;
        path += '/';
        for(int i=0;i<path.size();i++) {
            if(path[i]=='/'){
                ans.push_back(cur);
                cur.clear();
            } else {
                cur+=path[i];
            }
        }
        return ans;
    };
public:
    string simplifyPath(string path) {

        vector<string> seg = split_slash(path);

        vector<string> ans;
        for (int i=0;i<seg.size();i++) {
            if(seg[i].size()==0)
                continue;
            if(seg[i].size()==1&&seg[i][0]=='.')
                continue;
            if(seg[i].size()==2&&seg[i][0]=='.'&&seg[i][1]=='.') {
                if(ans.size())ans.pop_back();
                continue;
            }
            // normal path
            ans.push_back(seg[i]);
        }
        string resp;
        for(auto i : ans) {
            resp += '/' + i;
        }
        if(!resp.size())resp+='/';
        return resp;
    }
};