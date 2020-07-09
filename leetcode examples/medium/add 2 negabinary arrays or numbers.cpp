Given two numbers arr1 and arr2 in base -2, return the result of adding them together.

Each number is given in array format:  as an array of 0s and 1s, from most significant bit to least significant bit.  
For example, arr = [1,1,0,1] represents the number (-2)^3 + (-2)^2 + (-2)^0 = -3.  A number arr in array format is also guaranteed to have no leading zeros: 
either arr == [0] or arr[0] == 1.

Return the result of adding arr1 and arr2 in the same format: as an array of 0s and 1s with no leading zero

Input: arr1 = [1,1,1,1,1], arr2 = [1,0,1]
Output: [1,0,0,0,0]
Explanation: arr1 represents 11, arr2 represents 5, the output represents 16

class Solution {
public:
    vector<int>convert(long long int sum)
    {
        vector<int>v;
        if(sum==0)
        {
            vector<int>zero;
            zero.push_back(0);
            return zero;
        }
        while(sum!=0)
        {
            if(abs(sum%2)==1)
            {
                v.push_back(1);
                sum=(sum-1)/(-2);
            }
            else
            {
                v.push_back(0);
                sum=(sum)/(-2);
            }
        }
        reverse(v.begin(),v.end());
        return v;
    }
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        long long int n=arr1.size();
        long long int m=arr2.size();
        long long int i,j,s=0;
        long long int k=n-1;
        for(i=0;i<n;i++)
        {
            if(arr1[i]==1)
            s=s+pow(-2,k);
            k--;
        }
        k=m-1;
        for(i=0;i<m;i++)
        {
            if(arr2[i]==1)
            s=s+pow(-2,k);
            k--;
        }
        return convert(s);// convert number back to normal form
        
    }
};
---------------------------------------------------------------------------------------------------------------------------------------------------

Maybe write a base2 addition first?
Add minus -?
Done.
 vector<int> addBinary(vector<int>& A, vector<int>& B) {
        vector<int> res;
        int carry = 0, i = A.size() - 1, j = B.size() - 1;
        while (i >= 0 || j >= 0 || carry) {
            if (i >= 0) carry += A[i--];
            if (j >= 0) carry += B[j--];
            res.push_back(carry & 1);
            carry = (carry >> 1);
        }
        reverse(res.begin(), res.end());
        return res;
    }

    vector<int> addNegabinary(vector<int>& A, vector<int>& B) {
        vector<int> res;
        int carry = 0, i = A.size() - 1, j = B.size() - 1;
        while (i >= 0 || j >= 0 || carry) {
            if (i >= 0) carry += A[i--];
            if (j >= 0) carry += B[j--];
            res.push_back(carry & 1);
            carry = -(carry >> 1);
        }
        while (res.size() > 1 && res.back() == 0)
            res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }

