class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>before(n, 0),after(n , 0);
        stack<int>s1 , s2;
        before[0] = 1;
        for(int i = 0;  i < n ;i++){
            while(!s1.empty() && arr[s1.top()] >= arr[i]){
                s1.pop();
            }
            if(s1.empty()){
                before[i] = i + 1;
            }else{
                before[i] = i - s1.top();
            }
            s1.push(i);
        }
        after[n - 1] = 1;
        for(int i = n - 1;i >=0 ;i--){
            while(!s2.empty() && arr[s2.top()] > arr[i]){
                s2.pop();
            }
            if(s2.empty()){
                after[i] = n - i;
            }else{
                after[i] = s2.top() - i;     
            }
            s2.push(i);
        }
        long long ans = 0;
        int mod = 1e9 + 7;
        for(int i = 0; i < n ;i++){
            //cout<<arr[i]<<" -> "<<before[i]<<" : "<<after[i]<<endl;
            long long x = before[i] * after[i];
            x%= mod;
            ans+=(x * arr[i] * 1ll)%mod ;
            ans%= mod;
        }
        return ans;
        
        
    }
};