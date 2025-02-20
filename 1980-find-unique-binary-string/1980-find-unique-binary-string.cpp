class Solution {
public:
    
    string help2(int n, int dig) {
        return bitset<16>(n).to_string().substr(16 - dig);
    }

    
    int help1(string s) {
        int ans = 0;
        for (char c : s) {
            ans = (ans << 1) + (c - '0');
        }
        return ans;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        for (auto &str : nums) {
            s.insert(help1(str));
        }

        for (int i = 0; i < (1 << n); i++) {
            if (s.find(i) == s.end()) {
                return help2(i, n);
            }
        }
        return ""; 
    }
};
