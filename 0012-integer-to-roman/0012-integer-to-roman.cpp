class Solution {
public:
    string intToRoman(int num) {
        vector<int>v = {1 , 4 , 5 , 9 ,10 , 40 , 50, 90 , 100 , 400 ,500 , 900 , 1000};
        map<int, string>mm;
        mm[1] = "I";        
        mm[4] = "IV";       
        mm[5] = "V";
        mm[9] = "IX";
        mm[10] = "X";
        mm[40] = "XL";
        mm[50] = "L";
        mm[90] = "XC";        
        mm[100] = "C";        
        mm[400] = "CD";
        mm[500] = "D";
        mm[900] = "CM";
        mm[1000] = "M";
        
        sort(v.rbegin() , v.rend());
        string ans = "";
        for(auto &i : v){
           int t = num/i;
           while(t--){
               ans+=mm[i];
           }
            num%=i;
        }

    return ans;

    }
};