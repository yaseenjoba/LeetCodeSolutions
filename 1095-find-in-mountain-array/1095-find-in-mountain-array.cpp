/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int l = 0 , r = mountainArr.length() - 1;
        while(l < r){
          int mid = l + (r - l)/2;
          if(mountainArr.get(mid) > mountainArr.get(mid + 1)){
            r = mid;
          }else l = mid + 1;
        }
        int mo = l;
        cout<<mo<<endl;
        l = 0 , r = mo;
        while(l < r){
          int mid = l + (r -l)/2;
          if(mountainArr.get(mid) >= target)r = mid;
          else  l = mid + 1;
        }
        if(mountainArr.get(l) == target)return l;
        l = mo + 1 , r = mountainArr.length() - 1;
        while(l < r){
          int mid = l + (r -l + 1)/2;
          if(mountainArr.get(mid) >= target)l = mid;
          else  r = mid - 1;
        }
        if(mountainArr.get(l) == target)return l;
        return -1;
    }
};