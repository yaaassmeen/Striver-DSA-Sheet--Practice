#include<bits/stdc++.h>
using namespace std;

int printS(int ind, int s, int sum, int arr[], int n){
  if(ind == n){
    if(s == sum) return 1;
    return 0;
  }
  s += arr[ind];
  int l = printS(ind+1, s, sum, arr, n);
  s-= arr[ind];
  int r = printS(ind+1, s, sum, arr, n);
  return l+r;
}

int main(){
  int arr[] = {1,2,1};
  int n = 3;
  int sum = 2;
  int s = 0;
  cout<<printS(0,0,sum,arr,n);
  return 0;
}
