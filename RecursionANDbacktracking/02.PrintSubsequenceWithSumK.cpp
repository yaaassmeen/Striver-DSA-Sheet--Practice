#include<bits/stdc++.h>
using namespace std;

void printS(int ind, vecotr<int> &ans, int s, int sum, int arr[], int n){
  if(ind==n){
    if(s == sum) for(auto it : ds) cout<<it<<" ";
    cout<<endl;
  }
  //NOT PICK;
  printS(ind+1, ds, s, sum, arr, n);

  //PICK
  ds.push_back(arr[ind]);
  s += arr[ind];
  printS(ind+1, ds, s, sum, arr, n);
  ds.pop_back();
  s -= arr[ind];
}

int main(){
  int arr[] = {1,2,1};
  int sum = 2;
  int n = 3;
  vector<int> ds;
  printS(0, ds, 0, sum, arr, n);
}
