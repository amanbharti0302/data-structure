/*
127. Word Ladder
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words such that:
The first word in the sequence is beginWord.
The last word in the sequence is endWord.
Only one letter is different between each adjacent pair of words in the sequence.
Every word in the sequence is in wordList.
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog" with 5 words.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no possible transformation.
*/

class Solution {
public:
    int ladderLength(string a, string b, vector<string>& c) {
    set<string>s;
    for(int i=0;i<c.size();i++)if(c[i]!=a)s.insert(c[i]);
    queue<string>q;
    int cnt =0;
    q.push(a);
    q.push("-1");
    while(q.size()>1){
        string temp = q.front();
        q.pop();
        
        if(temp==b)return cnt+1;
        if(temp=="-1"){cnt++;q.push("-1");}
        
        for(int i=0;i<temp.length();i++){
            string t = temp;
            for(char j='a';j<='z';j++){
                if(temp[i]==j)continue;
                t[i] = j;
                if(s.find(t)!=s.end()){
                    s.erase(t);
                    q.push(t);
                }
            }
        }
    }
    
    return 0;
    }
};