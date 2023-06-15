class Solution {
public:
    void rotate(vector<int>& arr, int d) {
        int n = arr.size();
        d %= n;
        vector<int> temp;
        for(int i=n-d;i<n;i++){
            temp.push_back(arr[i]);
        }
        for(int i = n-d-1; i >= 0; i--){
            arr[i+d] = arr[i];
        }
        for(int i=0;i<d;i++){
            arr[i] = temp[i];
        }

    //    Left rotate by k == Right rotate by n-k 
    //    int k = n-d;
    //    k %= n;
	//    vector<int> temp;
	//    for(int i=0;i<k;i++){
	//        temp.push_back(arr[i]);
	//    }
	//    for(int i=k;i<n;i++){
	//        arr[i-k] = arr[i];
	//    }
	//    for(int i=n-k;i<n;i++){
	//        arr[i] = temp[i-n+k];
	//    }
        // Reverse approcah
        // k = k%nums.size();
        // reverse(nums.begin(), nums.end());
        // reverse(nums.begin(), nums.begin()+k);
        // reverse(nums.begin()+k, nums.end());
    }
};
