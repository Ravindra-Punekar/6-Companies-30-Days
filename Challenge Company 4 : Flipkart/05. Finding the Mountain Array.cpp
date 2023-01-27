/*
https://leetcode.com/problems/find-in-mountain-array/
*/

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
        int l=0, r = mountainArr.length()-1;
        while(l<r){
            int mid = l+(r-l)/2;
            if(mountainArr.get(l)<=mountainArr.get(mid) ){
                if(mountainArr.get(mid) >= mountainArr.get(mid+1)) r = mid;
                else l= mid+1;
            }
            else r=mid;
        }
        int peakindex = l;

        l=0, r = peakindex; //find in left side of peak ele
        while(l<r){
            int mid = l+(r-l)/2;
            if(mountainArr.get(mid)==target)    return mid;
            else if(mountainArr.get(mid) > target) r = mid;
            else l = mid+1;
        }
        
        l=peakindex,  r = mountainArr.length(); //find in right side of peak ele
        while(l<r){
            int mid = l+(r-l)/2;
            if(mountainArr.get(mid)==target)    return mid;
            else if(mountainArr.get(mid)< target) r = mid;
            else l = mid+1;
        }
        return -1;      //does not exist
    }
};
