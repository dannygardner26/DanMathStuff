#ifndef UTILS_H
#define UTILS_H
#include <vector>
#include <iostream>
#include <cmath>
#include <unordered_map>
#include <sstream>
using namespace std;

// Add your reusable helper functions here

vector<long> pFactorize(long num){
    vector<long> ans;
    for(int i = 2; i <= sqrt(num); i++){
        if(num % i == 0){
            ans.push_back(i);
            vector<long> next = pFactorize(num/i);
            ans.insert(ans.end(), next.begin(),next.end());
            return ans;
        }
    }
    if(num > 1){
        ans.push_back(num);
    } 
    return ans;
}
unordered_map<long, long> toFrequencyMap(const vector<long>& vec){
    unordered_map<long, long> freq;
    for(const long& item : vec){
        freq[item]++;
    }
    return freq;
}
void printVec(vector<long> &vec){
    cout<<endl;
    for(int num : vec){
        cout << num<< ", ";
    }
    cout<<endl;
}
bool isPrime(long num){
    if(num < 2) return false;
    for(int i = 2; i <= sqrt(num); i++){
        if(num % i == 0) return false;
    }
    return true;
}

long nthPrime(int n){
    int count = 0;
    long num = 1;
    while(count < n){
        num++;
        if(isPrime(num)){
            count++;
        }
    }
    return num;
}

int largestPrimeVal(int num){
    unordered_map<long,long> master;
    unordered_map<long,long> curr;
    for(int i = 2; i < num; i++){
        curr = toFrequencyMap(pFactorize(i));
        for(auto& [key, val] : curr){
            master[key] = max(master[key], val);
        }
    }
    int ans = 1;
    for(auto& [key,val] : master){
        ans = ans * pow(key,val);
    }
    return ans;
}
bool isPythagTrip(long a, long b, long c){
    return ((a*a)+(b*b) == (c*c));
}

vector<vector<int>> stringToGrid(string str, int n){
    vector<vector<int>> grid(n, vector<int>(n));
    istringstream iss(str);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            iss >> grid[i][j];
        }
    }
    return grid;
}

#endif
