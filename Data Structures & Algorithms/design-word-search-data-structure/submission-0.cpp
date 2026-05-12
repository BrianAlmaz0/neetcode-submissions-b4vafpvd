class TrieNode{
public:
    unordered_map<char, TrieNode*> children;
    bool endOfWord;
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;

        for(char ch : word){
            if(!curr->children.count(ch)){
                curr->children[ch] = new TrieNode();
            }
            curr = curr->children[ch];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

    bool dfs(string& word, int i, TrieNode* node){
        if(i == word.size()) return node->endOfWord;

        char ch = word[i];

        if(ch == '.'){
            for(auto& pair : node->children){
                if(dfs(word, i + 1, pair.second)) return true;
            }
            return false;
        }

        if(!node->children.count(ch)) return false;

        return dfs(word, i + 1, node->children[ch]);
    }
};
