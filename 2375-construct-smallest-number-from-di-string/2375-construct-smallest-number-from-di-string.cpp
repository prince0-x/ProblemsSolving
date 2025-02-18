class Solution {
public:
    string smallestNumber(string pattern) {
        string result = "";
        buildSequence(0, 0, pattern, result);
        reverse(result.begin(), result.end());
        return result;
    }
    int buildSequence(int currentIndex, int currentCount, string pattern,
                      string& result) {
        if (currentIndex != pattern.size()) {
            if (pattern[currentIndex] == 'I')
                buildSequence(currentIndex + 1, currentIndex + 1, pattern,
                              result);
            else
                currentCount = buildSequence(currentIndex + 1, currentCount,
                                             pattern, result);
        }

        result += to_string(currentCount + 1);
        return currentCount + 1;
    }
};