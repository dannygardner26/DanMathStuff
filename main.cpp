#include <iostream>
#include "utils.h"

using namespace std;

// Fibonacci numbers upto n = 5
int scale = 10000;
// Function to find nth
// Fibonacci number
int detectCycle(vector<long long> &arr){
    
        vector<long long> a = {arr[0]};
        vector<long long> b = {arr[1]};
    
    

    for(int i = 2; i < scale; i+=2){
        if(a == b){
            return i/2;
        }
        if(i+5 < arr.size()){
            if(arr[i+1] == 0 &&
            arr[i+2] == 0 &&
            arr[i+3] == 0 &&
            arr[i+4] == 0 &&
            arr[i+5] == 0
            ){
                cout<<endl<"0s"<<end;
            }
        }

        a.push_back(b[0]);
        b.erase(b.begin());
        b.push_back(arr[i]);
        b.push_back(arr[i+1]);
    }
    

    a = {arr[1]};
    b = {arr[2]};
    for(int i = 3; i < scale; i+=2){
        if(a == b){
            return i/2;
        }

        a.push_back(b[0]);
        b.erase(b.begin());
        b.push_back(arr[i]);
        b.push_back(arr[i+1]);
    }



    printDec(arr, 20);
    return -1;
}
vector<long long> getRepeatingDecimal(long long b){

    // a/b or 1/b
    vector<long long> arr(scale);
    long long a = 10;
    long long i = 0;
    while(i < scale){
        if(a / b == 0){
        a  *= 10;
        arr[i] = 0;
        
        } 
        else{
            arr[i] = a/b;
            i += log10(a);
            a = a%b;
            
        }   
        if(a == 0){
            break;
        }
    }
    return arr;
    
    
}

int main() {
    long long maxLen = 0;
    long long maxNum = 0;
    for(long long i = 6; i <= 1000; i++){
        vector<long long> myTemp = getRepeatingDecimal(i);
        long long len = detectCycle(myTemp);
        if(len == -1){
            cout<<endl<<i<<" has overflow"<<endl;
        }

        if(len > maxLen){
            maxLen = len;
            maxNum = i;
        }
    }
    cout<<endl<<"MaxLen: "<<maxLen<<" MaxNum: "<<maxNum<<endl;
    return 0;
}
