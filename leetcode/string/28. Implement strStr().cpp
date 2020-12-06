/*
Implement strStr().
Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
Clarification:
What should we return when needle is an empty string? This is a great question to ask during an interview.
For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Example 3:

Input: haystack = "", needle = ""
Output: 0

==============================================================>
Using kmp algorithm we can find substring easily
first we find lps array using prefix function named as lpsf
after that we find the length of prefix needle in array 
*/
vector<int> lpsf(string s) {
    int n = s.length();
    vector<int> lps(n,0);
    for (int i = 1; i < n; i++) {
        int j = lps[i-1];
        while (j > 0 && s[i] != s[j])
            j = lps[j-1];
        if (s[i] == s[j])
            j++;
        lps[i] = j;
    }
    return lps;
}

class Solution {
int kmpf(string a,string b){
 vector<int> lps = lpsf(b+"?"+a);

 for(int i=0;i<lps.size();i++)if(lps[i]==b.length())return i-2*b.length();
 return -1;
}
    
public:
    int strStr(string haystack, string needle) {
        if(needle=="")return 0;
        if(needle.length()>haystack.length())return -1;
        return kmpf(haystack,needle);
    }
};