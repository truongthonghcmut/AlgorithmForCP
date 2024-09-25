#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll inf = 1e18;
const ll mod = 1000000007;
const ld eps = 1e-9;
const ll mxN = 1e5;
#define pll pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>
#define sll set<ll>
// Suffix Tree (Trie)
struct TrieNode {
    TrieNode* next[26] = {};
    int cnt = 0; // how many strings have suffix are represented by this vertex
    int exist = 0; // how many strings are represented by this vertex
};

TrieNode* root = new TrieNode();

// Insert a word in suffix tree
void insert(string word) {
    TrieNode* node = root;
    for(char ch: word) {
        if(!node->next[ch - 'a']) node->next[ch - 'a'] = new TrieNode();
        node->next[ch - 'a']->cnt += 1;
        node = node->next[ch - 'a'];
    }
    node->exist += 1;
}

// Find if a word is in the suffix tree
bool find(string target) {
    TrieNode* node = root;
    for(char ch: target) {
        if(!node->next[ch - 'a']) return false;
        node = node->next[ch - 'a'];
    }
    return node->exist > 0;
}

void dfs(TrieNode* root, string& curr, vector<string>& sort_str) {
    if(root == nullptr) return;
    for(int i = 1; i <= root->exist; i++) {
        sort_str.push_back(curr);
    }
    for(int i = 0; i < 26; i++) {
        curr = curr + char(i + 'a');
        dfs(root->next[i], curr, sort_str);
        curr.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    vector<string> words = {"aa", "bab", "a", "babc", "abac", "accb", "bccaa", "bb", "cacab", "cb"};
    for(string word: words) insert(word);

    cout << find("bccaa") << "\n";
    cout << find("bccaab") << "\n";
    
    // Sort the strings in directionary order
    vector<string> sort_str;
    string curr = "";
    dfs(root, curr, sort_str);
    cout << "Directionary order: \n";
    for(string it: sort_str) cout << it << " ";

    return 0;
}