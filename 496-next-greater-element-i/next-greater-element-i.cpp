class Solution {
public:
    vector<int> findMin(vector<int> &nums2){
        int n = nums2.size();
        stack<int> st;
        vector<int> b(n,-1);
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && nums2[st.top()]<=nums2[i])
                st.pop();
            if(!st.empty())
                b[i] = nums2[st.top()];
            st.push(i);
        }
        return b;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        vector<int> b = findMin(nums2);
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    res.push_back(b[j]);
                    break;
                }
            }
        }
        return res;
    }
};