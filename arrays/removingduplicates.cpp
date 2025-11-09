#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> arr = {1,1,1,2,3,4,4,4,5,5,6,7,9,9};
    int i = 0;
    for(int j = 0; j < arr.size(); j++){
        if(arr[i] != arr[j]){
            i++;
            arr[i] = arr[j];
        }
    }
    
    for(int j = 0; j <= i; j++){
        cout << arr[j] << " ";
    }
    return 0;
}