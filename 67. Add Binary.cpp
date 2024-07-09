/*
10:23-10:30
big number add
easy.

*/
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int len = max(a.size(),b.size());
        int mod = 0;
        string ans;
        for(int i=0;i<len;i++){
            if(i<a.size())
                mod+=a[i]-'0';
            if(i<b.size())
                mod+=b[i]-'0';
            ans.push_back(mod%2+'0');
            mod/=2;
        }
        while(mod){
            ans.push_back(mod%2+'0');
            mod/=2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};