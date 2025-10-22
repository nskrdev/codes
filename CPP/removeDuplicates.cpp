#include<iostream>
using namespace std;

int main(){
    int arr[] = {10,10,12,12,15,19};
    int n =6;

    int j =0;
    for (int i=0; i<n; i++){
        if (i ==n -1 || arr[i]!= arr[i+1]){
            arr[j]=arr[i];
            j++;
        }
    }
    cout<<"no duplicates: ";
    for(int i=0; i<j;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

