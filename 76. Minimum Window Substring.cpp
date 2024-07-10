/*
9:10 - 10:10
Very hard.
thought it like loan;
countT is the balance
i add the item to ans, then pay back the loan on specific count.
if all count balanced, the [head,i] was valid.
then move head util the count is going to unbalanced.
*/

class Solution {
public:
    string minWindow(string s, string t) {
        // O(10e5 )
        int countT[256]={},sumT=t.size();
        for(int i=0;i<t.size();i++) {
            countT[t[i]]--;
        }
        int head=0;
        int minAns=0x7fffffff,ansS,ansT;
        for(int i=0;i<s.size();i++) {
            if(countT[s[i]]<0) {
                sumT--;
            }
            countT[s[i]]++;
            if(sumT<=0) {
                while(countT[s[head]]>0) {
                    countT[s[head]]--;
                    head++;
                }
                if(i-head+1<minAns) {
                    minAns = i-head+1;
                    ansS=head;
                    ansT=i+1;
                }
            }
        }
        if (minAns == 0x7fffffff) return string();
        return s.substr(ansS, minAns);
    }
};