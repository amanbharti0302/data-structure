/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words such that:

The first word in the sequence is beginWord.
The last word in the sequence is endWord.
Only one letter is different between each adjacent pair of words in the sequence.
Every word in the sequence is in wordList.
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore no possible transformation
*/

class Solution {
public:
    vector<vector<string>>ans;
    map<string,set<string>>adj;
    void dfs(string &a,string &b,vector<string>&path){
        path.push_back(a);

        if(a==b){ans.push_back(path);path.pop_back();return;}
        for(auto to : adj[a]){
            dfs(to,b,path);
        }
        
        path.pop_back();
    }
    
    vector<vector<string>> findLadders(string a, string b, vector<string>& c){
        ans.clear();adj.clear();
        set<string>dict;
        for(auto x:c)dict.insert(x);
        
        queue<string>q;
        map<string,int>visited;
        
        q.push(a);
        visited[a]=0;
        
        while(q.size()>0){
            string temp = q.front();
            q.pop();
                        
            for(int i=0;i<temp.size();i++){
                string t = temp;
                for(int j='a';j<='z';j++){
                    if(t[i]==j)continue;
                    t[i]=j;
                    if(dict.find(t)!=dict.end()){
                        if(visited.count(t)==0){
                            visited[t]=visited[temp]+1;
                            q.push(t);
                            adj[temp].insert(t);
                        }
                        else if(visited[temp]+1==visited[t]){
                            adj[temp].insert(t);
                        }
                    }
                }   
            }
            
        }
        
        vector<string>path;
        dfs(a,b,path);
        return ans;
    }
};