//
//  main.cpp
//  LeetCode540_SingleElementInASortedArrau
//
//  Created by Rui on 1/10/18.
//  Copyright © 2018 Rui. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int n = nums.size();
        
        while(left < right)
        {
            int mid = (left + right) / 2; //create mid is in the middle of the array
            if(nums[mid] == nums[mid + 1]){//if nums[mid] == nums[mid + 1]
                if((n - 1 - mid) % 2 == 1){//if the right part is odd, which means the single is in the left part
                    right = mid;
                }else left = mid + 1;//else in the right part
            }else{
                if(mid == 0 || nums[mid] != nums[mid - 1])
                    return nums[mid];
                if((mid - left) % 2 == 0) right = mid; // if nums[mid] != nums[mid + 1], if the right part is even, the single in the left part
                else left = mid + 1;
            }
                
        }
        
        return nums[left];
    }
};

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while(left < right)
        {
            int mid = (left + right) / 2;
            
            if(nums[mid] == nums[mid ^ 1]) left = mid + 1; //use ^ to find the mid's partner, if it equals to its partner, the single is in the right part
            else right = mid;//else in the left part
            
            
        }
        
        return nums[left];
    }
};
