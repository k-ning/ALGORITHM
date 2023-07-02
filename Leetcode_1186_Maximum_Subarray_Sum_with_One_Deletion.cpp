class Solution {
public:
    int maximumSum(vector<int>& arr) {

        size_t size = arr.size();
        vector<vector<int> > subarraymax(size, vector<int>(size, INT_MIN));
        int maxvalue = INT_MIN;

        for (size_t i = 0; i < arr.size(); i++) {

            subarraymax[i][i] = arr[i];
 
            int currentsum = arr[i];

            for (size_t j = i + 1; j < arr.size(); j++) {

                currentsum += arr[j];

                subarraymax[i][j] = currentsum;

            }

        }

        for (size_t i = 0; i < arr.size() - 1; i++) {

            for (size_t j = arr.size() - 1; j > i; j--) {

                int max = subarraymax[i][j];
                
                for (size_t k = j; k > i; k--) {
                    
                    int sum = max - arr[k];

                    if (sum > subarraymax[i][j]) subarraymax[i][j] = sum;

                }

            }

        }
        
        for (size_t l = 0; l < arr.size(); l++) {

            for (size_t k = 0; k < arr.size(); k++) {

                if (maxvalue <= subarraymax[l][k]) maxvalue = subarraymax[l][k];

            }
        }

        return maxvalue;
    }
};