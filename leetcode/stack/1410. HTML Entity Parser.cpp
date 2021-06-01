/*
HTML entity parser is the parser that takes HTML code as input and replace all the entities of the special characters by the characters itself.

The special characters and their entities for HTML are:

Quotation Mark: the entity is &quot; and symbol character is ".
Single Quote Mark: the entity is &apos; and symbol character is '.
Ampersand: the entity is &amp; and symbol character is &.
Greater Than Sign: the entity is &gt; and symbol character is >.
Less Than Sign: the entity is &lt; and symbol character is <.
Slash: the entity is &frasl; and symbol character is /.
Given the input text string to the HTML parser, you have to implement the entity parser.

Return the text after replacing the entities by the special characters.

 

Example 1:

Input: text = "&amp; is an HTML entity but &ambassador; is not."
Output: "& is an HTML entity but &ambassador; is not."
Explanation: The parser will replace the &amp; entity by &
Example 2:

Input: text = "and I quote: &quot;...&quot;"
Output: "and I quote: \"...\""
Example 3:

Input: text = "Stay home! Practice on Leetcode :)"
Output: "Stay home! Practice on Leetcode :)"
Example 4:

Input: text = "x &gt; y &amp;&amp; x &lt; y is always false"
Output: "x > y && x < y is always false"
Example 5:

Input: text = "leetcode.com&frasl;problemset&frasl;all"
Output: "leetcode.com/problemset/all"

*/


class Solution {
public:
    string entityParser(string text) {
        string ans = "";
        map<string,string>mp;
        mp["&quot;"] = "\"";
        mp["&apos;"] = "\'";
        mp["&amp;"] = "&";
        mp["&gt;"] = ">";
        mp["&lt;"] = "<";
        mp["&frasl;"] = "/";
        
        
        
        for(int i = 0;i<text.length();i++){
            if(text[i]!='&'){ans+=text[i];continue;}
            if(text[i]=='&'&&i<text.length()-1&&text[i+1]=='&'){ans+=text[i];continue;}
            
            string word="";
            while(i<text.length()){
                word+=text[i];
                if(text[i]==';')break;
                i++;
            }
            
            if(mp.find(word)!=mp.end())ans+=mp[word];
            else ans+=word;
        }
        
        return ans;
    }
};