// Replace Words (Medium)
 
// In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word derivative. For example, when the root "help" is followed by the word "ful", we can form a derivative "helpful".
// Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the derivatives in the sentence with the root forming it. If a derivative can be replaced by more than one root, replace it with the root that has the shortest length.
// Return the sentence after the replacement.

// Example 1:
// Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
// Output: "the cat was rat by the bat"

#include<bits/stdc++.h>
using namespace std;

class Trie{
public:
    Trie *children[26];
    bool isEnd;
    
    Trie(){
        for (int i=0;i<26;i++){
            children[i] = nullptr;
        }
        isEnd = false;
    }
};

class Solution {
public:
    Trie* root = new Trie();
    
    void insert(string word){
        Trie* node = root;
        for (auto c : word) {
            int i = c - 'a';
            if (node->children[i] == nullptr) {
                node->children[i] = new Trie();
            }
            node = node->children[i];
        }
        node->isEnd = true;
    }
    
    string search(string word){
        Trie* node = root;
        string res;
        for (auto c : word) {
            int i = c - 'a';
            if (node->children[i] == nullptr) {
                return word;
            }
            res += c;
            if (node->children[i]->isEnd) {
                return res;
            }
            node = node->children[i];
        }
        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        for (string word : dictionary) {
            insert(word);
        }

        stringstream ss(sentence);
        string word, result;
        while (ss >> word) {
            if (!result.empty()) {
                result += " ";
            }
            result += search(word);
        }
        return result;
    }
};

signed main()
{    
    string s;
    getline(cin,s,'\n');
    int n;
    cin>>n;
    vector<string>dict(n);
    for (int i=0;i<n;i++){
        cin>>dict[i];
    }
    Solution ob;
    auto ans = ob.replaceWords(dict,s);
    cout<<ans;
    return 0;
}