#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> arr = {2,5,1,7,8};
    int left = 0, right = arr.size()-1;
    while(left < right){
        swap(arr[left], arr[right]);
        left++;
        right--;
    }

    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
}