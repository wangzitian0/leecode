// 21:45 - 22:15
// super edge cases, wa x2
// used over 10 min to handle the case
// 1B 100k 1000 100
// wa1 100k -> One Hundred
// wa2 100 -> One Hundred Zero
class Solution {
    vector<string> belowTwenty = {
        "Zero",    "One",     "Two",       "Three",    "Four",
        "Five",    "Six",     "Seven",     "Eight",    "Nine",
        "Ten",     "Eleven",  "Twelve",    "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

    vector<string> tens = {"",      "",      "Twenty",  "Thirty", "Forty",
                           "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    vector<string> thousands = {"", "Thousand", "Million", "Billion"};
    string hu = "Hundred";

public:
    string numberToWords(int num) {
        vector<int> nums;
        while (num > 0) {
            nums.push_back(num % 1000);
            num /= 1000;
        }
        string ans;
        for (int i = nums.size() - 1; i >= 0; i--) {
            int cur = nums[i];
            if (cur / 100 != 0) {
                ans += belowTwenty[cur / 100] + " ";
                ans += hu + " ";
            }
            if (cur % 100 && cur % 100 < 20) {
                ans += belowTwenty[cur % 100] + " ";
            } else {
                if (cur / 10 % 10) {
                    ans += tens[cur / 10 % 10] + " ";
                }
                if (cur % 10) {
                    ans += belowTwenty[cur % 10] + " ";
                }
            }
            if (cur && i) {
                ans += thousands[i] + " ";
            }
        }
        if (ans.size() == 0) {
            ans = belowTwenty[0] + " ";
        }
        ans.pop_back();
        return ans;
    }
};