class Solution {
public:
    string orderlyQueue(string s, int k) 
    {        
        if (k > 1){  
            sort(s.begin(), s.end());
        }else {
                string result = s;
                for (int i=0; i<s.length(); i++)
                {
                    s = s.substr(1) + s[0];
                    result = min(result, s);
                }
                return result;
            }
            return s;
	}
};