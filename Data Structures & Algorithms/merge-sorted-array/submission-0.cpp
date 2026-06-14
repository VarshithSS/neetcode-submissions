class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // if(m==0) {nums1[0]=nums2[0];return;}
        // if(n==0) return;
        vector<int> v = nums1;
        int p1 = 0 , p2 =0 ,c=0;
        while(p1!=m || p2!=n)
        {
            if(p1!=m && p2!=n)
            {
                if(v[p1]<nums2[p2])
                {
                    nums1[c]=v[p1];
                    p1++;
                    c++;
                }
                else
                {
                    nums1[c]=nums2[p2];
                    p2++;
                    c++;
                }
            }
            else if(p1!=m)
            {
                nums1[c]=v[p1];
                    p1++;
                    c++;
            }
             else if(p2!=n)
             {
                  nums1[c]=nums2[p2];
                    p2++;
                    c++;
             }
        }
        return;
    }
};