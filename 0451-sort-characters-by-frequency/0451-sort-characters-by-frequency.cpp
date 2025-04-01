class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        vector<int> freq(62, 0);

        for (auto i : s) {
            if (isupper(i)) {
                freq[i - 'A' + 26]++;
            } else if (islower(i)) {
                freq[i - 'a']++;
            } else if (isdigit(i)) {
                freq[i - '0' + 52]++;
            }
        }

        vector<pair<int, char>> freq_p;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                freq_p.push_back({freq[i], i + 'a'});
            }
            if (freq[i + 26] > 0) {
                freq_p.push_back({freq[i + 26], i + 'A'});
            }
        }

        for (int i = 0; i < 10; i++) {
            if (freq[i + 52] > 0) {
                freq_p.push_back({freq[i + 52], i + '0'});
            }
        }

        sort(freq_p.begin(), freq_p.end(), [](const pair<int, char>& a, const pair<int, char>& b) {
            return a.first > b.first;
        });

        for (auto i : freq_p) {
            ans += string(i.first, i.second);
        }

        return ans;
    }
};