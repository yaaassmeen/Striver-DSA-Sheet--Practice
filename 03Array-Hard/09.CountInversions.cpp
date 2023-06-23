//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


#define ll long long

class Solution {
    ll cnt = 0;

    void merge(vector<ll> &arr, ll low, ll mid, ll high) {
        vector<ll> temp; // temporary array
        ll left = low;      // starting index of left half of arr
        ll right = mid + 1;   // starting index of right half of arr

        // storing elements in the temporary array in a sorted manner
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            } else {
                temp.push_back(arr[right++]);
                cnt += mid - left + 1;
            }
        }

        // if elements on the left half are still left
        while (left <= mid) {
            temp.push_back(arr[left++]);
        }

        // if elements on the right half are still left
        while (right <= high) {
            temp.push_back(arr[right++]);
        }

        // transferring all elements from temporary to arr
        for (ll i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    void mergeSort(vector<ll> &arr, ll low, ll high) {
        if (low >= high) {
            return;
        }

        ll mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);       // left half
        mergeSort(arr, mid + 1, high);  // right half
        merge(arr, low, mid, high);     // merging sorted halves
    }

public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N) {
        // Your Code Here
        vector<ll> temp(arr, arr + N);  // Convert arr to vector
        mergeSort(temp, 0, N - 1);
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends
