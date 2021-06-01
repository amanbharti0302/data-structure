/*
1202. Smallest String With Swaps
Medium

723

26

Add to List

Share
You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.

You can swap the characters at any pair of indices in the given pairs any number of times.
Return the lexicographically smallest string that s can be changed to after using the swaps. 

Example 1:

Input: s = "dcab", pairs = [[0,3],[1,2]]
Output: "bacd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[1] and s[2], s = "bacd"
Example 2:

Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
Output: "abcd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[0] and s[2], s = "acbd"
Swap s[1] and s[2], s = "abcd"
Example 3:

Input: s = "cba", pairs = [[0,1],[1,2]]
Output: "abc"
Explaination: 
Swap s[0] and s[1], s = "bca"
Swap s[1] and s[2], s = "bac"
Swap s[0] and s[1], s = "abc"

====================================================================>>My Approach
It is a wonderful question as we can think simply to apply dfs in this question
as we can do as many swaps we can do
than why not we simply take all those nodes which is connected and sort them and again replace them at those nodes
this is the basic idea
I did same 
i stored all connected index every time using dfs and stored them in idx
and after that i make a temp string and in which i pushed all those characters which is stored at these idx's values
now i simply sort temp string and also sorted idx so i that i can get sorted indexes in idx
after that in i replaced these sorted string at these indexes of idx
at last i returned string
*/

vector<int>adj[100005];
vector<bool>visited;
vector<int>idx;

void dfs(int src){
    visited[src]=true;
    idx.push_back(src);
    for(auto x:adj[src])
        if(!visited[x])dfs(x);
}

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        visited.assign(s.length(),false);
        for(auto x:pairs){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        for(int i=0;i<s.length();i++){
            if(visited[i]||adj[i].size()==0)continue;
            idx.clear();
            dfs(i);
            string temp = "";
            for(auto x:idx)temp+=s[x];
            sort(temp.begin(),temp.end());
            sort(idx.begin(),idx.end());
            int y=0;
            for(auto x:idx)
                if(x<s.length())s[x]=temp[y++];
        }
        
        return s;
    }
};