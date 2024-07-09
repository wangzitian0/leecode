/*
9:24 - 10:17

lots of edge case.
debug at local and 1 accepted.


*/

class Solution {
private:
    bool isDigits(string s) {
        if(s.size()==0)return false;
        for(int i=0;i<s.size();i++)
            if(!(s[i]>='0'&&s[i]<='9'))
                return false;
        return true;
    }
    bool isInt(string s) {
        if(s.size()==0)return false;
        if(s[0]=='-'||s[0]=='+')
            s = s.substr(1,s.size()-1);
        if(s.size()==0)return false;
        return isDigits(s);
    }

    bool isDec(string s) {
        if(s[0]=='-'||s[0]=='+')
            s = s.substr(1,s.size()-1);
        int n = s.size();
        if(n==1)return false;

        for(int i=0;i<n;i++)
            if(s[i]=='.'){
                bool pre = isDigits(s.substr(0,i));
                bool pst = isDigits(s.substr(i+1,n-1-i));
                if(i==0) return pst;
                if(i==n-1) return pre;
                return pre && pst;
            }
        return false;
    }
public:
    bool isNumber(string s) {
        if (isInt(s)||isDec(s))return true;
        int n=s.size();
        for (int i=0;i<n;i++){
            if (s[i] == 'e' || s[i] == 'E'){
                if (i==0||i==n-1)return false;
                string pre = s.substr(0,i);
                string pst = s.substr(i+1,n-1-i);
                return (isInt(pre)||isDec(pre))&&isInt(pst);
            }
        }
        return false;
    }
};