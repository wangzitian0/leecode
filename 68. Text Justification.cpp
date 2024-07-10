/*
10:23-10:30
a RE // ignored the case ["a"] should be 'a_____'.

*/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> resp;
        int s=0;
        while(s<words.size()){
            int current_line_len = -1;
            int t=s;
            while(current_line_len+words[t].size()+1<=maxWidth){
                current_line_len+=words[t].size()+1;
                if(++t==words.size())break;
            }
            int extra_buffer_len = maxWidth - current_line_len;
            int extra_buffer = t-s-1;
            string ans;
            ans+=words[s];
            for(int i=s+1;i<t;i++){
                int mod = 1;
                if (i-s<=extra_buffer_len%extra_buffer) mod++;
                ans += string(extra_buffer_len/extra_buffer+mod,' ');
                ans+=words[i];
            }
            if(extra_buffer == 0){
                ans += string(extra_buffer_len, ' ');
            }
            if (t==words.size()) {
                ans = words[s];
                for(int i=s+1;i<t;i++){
                    ans += ' '+words[i];
                }
                ans += string(extra_buffer_len,' ');
            }
            resp.push_back(ans);
            s=t;
        }
        return resp;
    }
};