class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        //Get the sizes of both input arrays
        int n = nums1.size();
        int m = nums2.size();

        // Merge the arrays into a single sorted array.
        vector<int> merge;

        for(int i=0;i<n;i++)
        {
            merge.push_back(nums1[i]);
        }
        for(int i=0;i<m;i++)
        {
            merge.push_back(nums2[i]);
        }
       
      // Sort the merged array
        sort(merge.begin(),merge.end());

      // Calculate the total elements in the array 
      int total = merge.size();

      if(total % 2 == 1)
      {
          // If the total number of elements is odd
          return static_cast<double>(merge[total/2]);
      }
      else {
          // / If the total number of elements is even
          int mid1 = merge[total / 2 - 1];
          int mid2 = merge[total / 2];

          return (static_cast<double>(mid1) + static_cast<double>(mid2)) / 2.0;
      }
    }
};