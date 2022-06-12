class Solution {
public:
    bool isValid(int x, vector<char>& letters, char target){
        return letters[x]>target;
    }
    
    int bs(int st , int en,vector<char>& letters, char target){
        while(st<en){
            int mid= st+(en-st)/2;
             if(isValid(mid,letters,target))
                en=mid;
             else
                st=mid+1;
        }
        return st;
    }
    char nextGreatestLetter(vector<char>& letters, char target) {
        int c =bs(0,letters.size(),letters,target);
        
        return c>=letters.size()?letters[0]:letters[c];
    }
};