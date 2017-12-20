/*
简单模拟就好，字符串处理我使用sprintf来格式化省掉一些不必要的麻烦

*/

class Solution {
public:
    string countAndSay(int n) {
        char cstr[100000];
        string s="1";
        while(--n>0){
            int len = s.size(), cnt = 1;
            char lastc = s[0];
            string t="";
            for(int i=1;i<=len;i++) {
                if(i<len&&s[i]==lastc)
                    cnt++;
                else {
                    sprintf(cstr,"%d%c",cnt,lastc);
                    t += cstr;
                    lastc=s[i];
                    cnt=1;
                }
            }
            s=t;
        }
        return s;
    }
};