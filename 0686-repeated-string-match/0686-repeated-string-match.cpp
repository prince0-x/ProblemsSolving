#include <string>

class Solution {
public:
    int repeatedStringMatch(std::string a, std::string b) {
        std::string repeatA = "";
        int count = 1;

        while (repeatA.length() < b.length()) {
            repeatA += a;
            count++;
            if (repeatA.find(b) != std::string::npos) return count-1;
        }

        // One more repetition to check if b is fully contained
        repeatA += a;
        count++;
        if (repeatA.find(b) != std::string::npos) return count-1;

        return -1;
    }
};