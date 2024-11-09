class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n1 = str1.size(), n2 = str2.size(),i=0,j=0;
        return (str1+str2==str2+str1)?str1.substr(0,gcd(n1,n2)):"";

    }
};