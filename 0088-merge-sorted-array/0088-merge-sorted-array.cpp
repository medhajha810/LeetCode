class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /*for(int i=m,j=0;i<m+n,j<n;i++,j++){
            nums1[i]=nums2[j];
        }
        sort(nums1.begin(),nums1.end());*/
        int i = m - 1;         
        int j = n - 1;         
        int k = m + n - 1;   
        while(i >= 0 && j >= 0) {
            if(nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        while(j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};
