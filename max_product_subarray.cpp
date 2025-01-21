#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
Given an integer array nums, find a 
subarray
 that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

*/


// Writing the function to find the max product subarray
int maxProduct(vector<int>& a) {
        int i,n=a.size();
        int negmin = INT_MIN;				                    // TO STORE THE MIN NEGATIVE PRODUCT
        int pro=1,mpro=INT_MIN;                                 // STORING THE CURRENT PRODUCT , MAX PRODUCT
        for(i=0;i<n;i++)
        {
            pro*=a[i];                                          // RUNNING PREFIX PRODUCT
            if(pro>0)
            {
            	mpro=max(mpro,pro);                             // IF POSITIVE PRODUCT JUST STORE IT IF ITS MAX
			}
            else if(pro<0)
            {
                if(negmin==INT_MIN)                             // IF NO NEGATIVE PRODUCT SO FAR JUST SAVE pro ELSE STORE (PREFIX PRODUCT)/(MIN NEG PREFIX PRODUCT SO FAR)
               		mpro=max(mpro,pro); 
               	else
               		mpro=max(mpro,pro/negmin);
                negmin=max(negmin,pro);                         // UPDATE THE NEG. PREFIX PRODUCT
			}
            else											    // IF PRODUCT =0 , RESET PREFIX PRODUCT AND NEGATIVE PREFIX PRODUCT
            {
                mpro=max(mpro,pro);                             
                negmin = INT_MIN;
                pro=1;
            }
        }
        return mpro;
    }
int main()
{
	int n,x;

	//DEFINE ARRAY SIZE
	cin>>n;
	
	vector<int>v;

	//FILL THE ARRAY
	for(int j=0;j<n;j++)
	{
		cin>>x;
		v.push_back(x);
	}

	//CALL THE FUCTION TO FIND MAX PRODUCT SUBARRAY
	int pro = maxProduct(v);

	//PRINT THE RESULT
	cout<<pro<<"\n";
	return 0;
}

