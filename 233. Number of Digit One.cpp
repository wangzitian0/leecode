// Not familiar with those indexes. nearly 1 hour.
// 1, 10, 11, 12, 13
// f[i] // the 1 number inside [0 -> 10^(i))
// f[i]=10*f[i-1]+10^(i-1)
// f[i]=i*10^(i-1)
// for 12358
// 0.... => sum+=f[4]
// 1.... => sum+=rest number of ....
// 10... => sum+=f[3]
// 11... => sum+=f[3] + 10^3
// 12... => sum+=rest number of ...
class Solution {
public:
    int countDigitOne(int n) {
        vector<int> digis;
        vector<int> po = {1};
        int restNum = n;
        for (int i=0;i<=8;i++) {
            po.push_back(po[i] * 10);
        }
        while (n > 0) {
            digis.push_back(n % 10);
            n /= 10;
        }
        int sum = 0;
        int preNumberOf1 = 0;
        for (int pos = digis.size() - 1; pos >= 0; pos--) {
            for (int i = 0; i < digis[pos]; i++) {
                if(pos>0)
                    sum += pos*po[pos-1];
                if (i == 1)
                    sum += po[pos];
                restNum -= po[pos];
            }
            if (digis[pos] == 1) {
                sum += restNum+1;
            }
            cout<<sum<<endl;
        }
        return sum;
    }
};