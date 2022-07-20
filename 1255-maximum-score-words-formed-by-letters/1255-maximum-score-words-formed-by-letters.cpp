class Solution {
public:
    vector<int>s;
    vector<string>word;
    int sol(map<char ,int>&freq , int i){
        if(i == word.size())return 0;
        
        bool can = true;
        map<char , int> temp = freq;
        int score = 0;
        for(auto j : word[i]){
            if(freq[j] == 0){
                can = false;
                break;
            }
            score+=s[j - 'a']; 
            freq[j]--;
        }
        if(can){
            return max(sol(temp , i + 1) , score + sol(freq , i  + 1));
        }
        return sol(temp , i + 1);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        s = score , word = words;
        map<char , int>mm;
        for(auto i : letters){
            mm[i]++;
        }
        return sol(mm , 0);
    }
};