class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2)return 1; 
        int i=0, j;
        for(i=0;i<s1.size();i++)if(s1[i]!=s2[i]){break;}
        for(j=i+1;j<s1.size();j++)if(s1[j]!=s2[j]){break;}
        swap(s1[i],s1[j]);
        return s1==s2;
    }
};