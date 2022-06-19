class Solution {
public:
    struct node{
       int nxt[26];
       int ctr , val;
       bool en;
      vector<string>temp;
       node(){
          memset(nxt , -1  , sizeof nxt);
          ctr = val = 0; 
          en = false;
       }
    };
    vector<node>trie;
    void add(string &s){
       int cur = 0;
       for(int i = 0 ; i< s.size();i++){
          if(trie[cur].nxt[s[i] - 'a'] == - 1){
             trie.push_back(node());
             trie[cur].nxt[s[i] - 'a'] = trie.size() - 1;
          }
          cur = trie[cur].nxt[s[i] - 'a'];
          trie[cur].ctr++;
           trie[cur].temp.push_back(s);
       }
       trie[cur].en = true;

    }
    vector<string> search(string &s){
       int cur = 0;
       for(int i = 0 ; i< s.size();i++){
          if(trie[cur].nxt[s[i] - 'a'] == - 1){
              vector<string>x;
             return x;
          }
          cur = trie[cur].nxt[s[i] - 'a'];
       }
       return trie[cur].temp;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
       vector<vector<string>>ans;
       trie.push_back(node());
        for(auto i : products){
            string s = i;
            add(s);
        }
        string k = "";
        for(auto i : searchWord){
            k+=i;
            vector<string>t = search(k);
            sort(t.begin() , t.end());
            if(t.size() > 3){
                ans.push_back({t[0] , t[1] , t[2]});
            }else
            ans.push_back(t);
        }
        return ans;
        
        
        
    }
};