 struct TrieNode{
        bool end;
        TrieNode *children[26];
     TrieNode()
    {
        end=false;
        for(int i=0;i<26;i++)
        {
           children[i]=NULL;
        }
    }
     
    };
   
class Trie {
public:
   
    Trie() {
        root = new TrieNode();
    }
    void insert(string word) {
        int word_len = word.length();
        int k = 0;
        TrieNode *cur = root;
        
        for (int i = 0; i < word_len; i++)
        {
            k = word[i] - 'a';
            
            if (cur->children[k] == NULL)
            {
                cur->children[k] = new TrieNode();
            }
            
            cur = cur->children[k];
        }
        
        cur->end = true;
    }
    
    bool search(string word) {
      int word_len = word.length();
        int k = 0;
        TrieNode *cur = root;
        
        for (int i = 0; i < word_len; i++)
        {
            k = word[i] - 'a';
            cur = cur->children[k];
            
            if (cur == NULL)
                return false;
        }
        
        return cur->end;  
    }
    
    bool startsWith(string prefix) {
        int word_len = prefix.length();
        int k = 0;
        TrieNode *cur = root;
        
        for (int i = 0; i < word_len; i++)
        {
            k = prefix[i] - 'a';
            cur = cur->children[k];
            
            if (cur == NULL)
                return false;
        }
        
        return true;
    }
    private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
 
 
 //Other Way
   struct TrieNode{
        TrieNode* children[26];
        bool endOfWord;
        string word;
    };

    TrieNode* createTrieNode()
    {
        TrieNode* temp = new TrieNode();
        temp->endOfWord= false;
        temp->word = "";
        for(int i=0;i<26;i++)
        {
            temp->children[i]=NULL;
        }
        return temp;
    }

    void insertWord(string &word, TrieNode* root)
    {
        int n = word.size();
        for(int i=0;i<n;i++)
        {
            if(root->children[word[i]-'a']==NULL)
            {
                root->children[word[i]-'a'] = createTrieNode();
            }
            root=root->children[word[i]-'a'];
        }
        root->word = word;
        root->endOfWord = true;
    }