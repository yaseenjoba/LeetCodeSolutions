/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<pair<Node* , int>>pq;
        map<int , vector<Node*>>level;;
        pq.push({root , 0});
        while(!pq.empty()){
            pair<Node* , int>s = pq.front();
            pq.pop();
            if(s.first == NULL)continue;
            level[s.second].push_back(s.first);
            pq.push({s.first->left ,s.second + 1});           
            pq.push({s.first->right ,s.second + 1});
        }
        for(auto i : level){
            vector<Node*>v = i.second;
            for(int i = 0 ; i< v.size();i++){
                if(i + 1 == v.size())break;
                v[i]->next = v[i + 1];
            }
            v[v.size() - 1]->next = NULL;
        }
        return root;
    }
};