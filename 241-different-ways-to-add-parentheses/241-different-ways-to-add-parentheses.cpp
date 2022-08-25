class Solution {
public:
    vector<int> diffWaysToCompute(string ex) {
        vector<int>result;
        if(ex.find("-") == string::npos  && ex.find("+") ==string::npos && ex.find("*") == string::npos){
            result.push_back(stoi(ex));
        }else{
            for(int i = 0; i < ex.size() ;i++){
                if(!isdigit(ex[i])){
                    vector<int> left = diffWaysToCompute(ex.substr(0 , i));                    
                    vector<int> right = diffWaysToCompute(ex.substr(i + 1));
                    for(auto j : left){
                        for(auto k : right){
                            if(ex[i] == '+'){
                                result.push_back(j + k);
                            }
                            if(ex[i] == '-'){
                                result.push_back(j - k);
                            }
                            if(ex[i] == '*'){
                                result.push_back(j * k);
                            }
                        }
                    }

                    
                }
            }
        }
        return result;
        
    }
};