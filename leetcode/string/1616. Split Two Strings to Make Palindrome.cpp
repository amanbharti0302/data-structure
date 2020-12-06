/*
You are given two strings a and b of the same length. Choose an index and split both strings at the same index, splitting a into two strings: aprefix and asuffix where a = aprefix + asuffix, and splitting b into two strings: bprefix and bsuffix where b = bprefix + bsuffix. Check if aprefix + bsuffix or bprefix + asuffix forms a palindrome.
When you split a string s into sprefix and ssuffix, either ssuffix or sprefix is allowed to be empty. For example, if s = "abc", then "" + "abc", "a" + "bc", "ab" + "c" , and "abc" + "" are valid splits.
Return true if it is possible to form a palindrome string, otherwise return false.
Notice that x + y denotes the concatenation of strings x and y.

Example 1:

Input: a = "x", b = "y"
Output: true
Explaination: If either a or b are palindromes the answer is true since you can split in the following way:
aprefix = "", asuffix = "x"
bprefix = "", bsuffix = "y"
Then, aprefix + bsuffix = "" + "y" = "y", which is a palindrome.
Example 2:

Input: a = "abdef", b = "fecab"
Output: true
Example 3:

Input: a = "ulacfd", b = "jizalu"
Output: true
Explaination: Split them at index 3:
aprefix = "ula", asuffix = "cfd"
bprefix = "jiz", bsuffix = "alu"
Then, aprefix + bsuffix = "ula" + "alu" = "ulaalu", which is a palindrome.

========================================================================================> My appproach
I am using kmp algorithm
but getting wrong several times
i will see it later date : 7/12/2020 :: 2:27 AM    //trying to debug
*/

vector<int>prefix_function(string s){
    vector<int>lps(s.length(),0);
    for(int i=1;i<s.length();i++){
        int j = lps[i-1];
        while(j>0&&s[j]!=s[i])j=lps[j-1];
        if(s[i]==s[j])j++;
        lps[i]=j;
    }
    return lps;
}

bool check(vector<int>lps,int al){
    for(int i=0;i<lps.size();i++){
        if(lps[i]>0&&(lps[i]==(lps.size()-(i+1))||lps[i]+1==(lps.size()-(i+1)))){/*cout<<i<<" "<<lps[i]<<" "<<lps.size();*/return true;}
    }
    return false;
}

class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        string t1=a,t2=b;
        reverse(t1.begin(),t1.end());
        reverse(t2.begin(),t2.end());
        
        if(t1==a||t2==b)return true;
        
        vector<int>lps1 = prefix_function(a+'?'+t2);
        vector<int>lps2 = prefix_function(b+'?'+t1);
        
        if(check(lps1,a.length())==true)return true;
        //cout<<"okk"<<" ";
        if(check(lps2,b.length())==true)return true;        
        return false;
    }
};