class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0] , r  = matrix[n - 1][n -1];
        while(l  <  r){
            int mid = l + (r - l)/2;
            int c = count(matrix , n , mid);
            if(c >= k){
                r = mid;
            }else l = mid + 1;
        }
        return l;
    }
    int count(vector<vector<int>>& matrix,int n, int target){
        int curr_row=n-1,curr_col=0,count=0;
        while(curr_row>=0 && curr_col<n)
        {
            if(matrix[curr_row][curr_col]<=target)
            {
                count+=(curr_row+1);
                curr_col++;
            }
            else
                curr_row--;
        }
        return count;
    }
};