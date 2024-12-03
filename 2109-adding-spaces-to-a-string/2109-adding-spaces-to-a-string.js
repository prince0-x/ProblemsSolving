/**
 * @param {string} s
 * @param {number[]} spaces
 * @return {string}
 */
var addSpaces = function(s, spaces) {
    let ans ="";
    let j=0;
    for(let i=0;i<spaces.length;i++)
    {
        while(j<s.length && j<spaces[i])
        {
            ans+=s[j];
            j++;
        }
        if(j==spaces[i])
        {
            ans+=" ";
        }
    }
    while(j<s.length)
    {
        ans+=s[j];
        j++;
    }
    return ans;
};