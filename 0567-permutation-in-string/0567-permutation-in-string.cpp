class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())return false;

        int h1[26]={0}, h2[26]={0};

        for(int i =0;i<s1.size() ; i++){
            h1[s1[i]-'a']++;
            h2[s2[i]- 'a']++;
        }
        int matches =0;
        for(int i =0;i<26;i++){
            if(h1[i]==h2[i])matches++;
        }
        

        int i = 0;
        for(int j = s1.size(); j<s2.size(); j++){
            if(matches==26)return true;

            int index1 = s2[j]- 'a';
            h2[index1]++;
            if(h1[index1]==h2[index1])matches++;
            else if(h1[index1]+1==h2[index1]) matches--; //previously were equal
          

            int index2 = s2[i]-'a';
            h2[index2]--;
            if(h1[index2]==h2[index2])matches++;
            else if(h1[index2]-1==h2[index2]) matches--;//previously were equal
            


            i++;
        }
        return matches ==26;
    }
};