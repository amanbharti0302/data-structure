/*A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.
Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
*/

class Trie {
public:
    /** Initialize your data structure here. */
    Trie *next [26];
    bool wordend;
    
    Trie() {
        for(int i = 0;i<26;i++)this->next[i] = NULL;
        this->wordend = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie * root = this;
        int n = word.length();
        
        for(int i = 0;i<n;i++){
            char curr = word[i];
            if(root->next[curr-'a']==NULL){root->next[curr-'a'] = new Trie();}
            root= root->next[curr-'a'];
            
            if(i==n-1)root->wordend = true;
        }        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *root = this;
        int n = word.length();
        
        for(int i = 0;i<n;i++){
            char curr = word[i];
            if(root->next[curr-'a']==NULL)return false;
            root= root->next[curr-'a'];
            if(i==n-1&&root->wordend!=true)return false;
        }
        
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        Trie *root = this;
        int n = word.length();
        
        for(int i = 0;i<n;i++){
            char curr = word[i];
            if(root->next[curr-'a']==NULL)return false;
            root= root->next[curr-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */