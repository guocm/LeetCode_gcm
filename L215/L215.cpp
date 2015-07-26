#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

class Solution {
public:
    int quick_sort(vector<int>& a, int left, int right, int k)
    {
        if(left<=right)
        {
            int i = left;
            int j = right;
            int x = a[i];        
	        while(i<j)
	        {
	            while(i<j&&a[j]>x)
	                j--;
	            if(i<j){
	                a[i] = a[j];
	                i++;
	            }
	            while(i<j&&a[i]<x)
	                i++;
	            if(i<j){
	                a[j] = a[i];
	                j--;
	            }
	        }
	        a[i] = x;
	        cout << "k: " << k << ", right - i + 1: " << right - i + 1 << ", x: " << x << ", i: " << i << endl;
	        if (k == right + 1 - i)
	            return x;
	        else if (k > right + 1 - i)
	            return quick_sort(a, left, i-1, k-(right + 1 - i));
	        else
	            return quick_sort(a, i+1, right, k);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        return quick_sort(nums, 0, len - 1, k);
    }
};

int main()
{
  Solution sol;
  int arr[] = {-1,2,0};
  std::vector<int> v(arr, arr+3);
  cout << sol.findKthLargest(v, 2) << endl;
  return 0;
}