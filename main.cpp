#include <iostream>
#include "utils.h"

using namespace std;
bool isAbundant(int num){
    return sum(listDivisors(num)) > num;
}
int main() {
    vector<long long> abundants;
    for(int i = 11; i < 29000; i++){
        if(isAbundant(i)){
            abundants.push_back(i);
        }
    }
    printVec(abundants);
    unordered_set<long long> isSumOfAbundants;
    for(int i = 0 ; i < abundants.size(); i++){
        for(int j = i; j < abundants.size(); j++){
            isSumOfAbundants.insert(abundants[i]+abundants[j]);
        }
    }
    long long ans = 0;
    for(int i = 1 ; i < 29000; i++){
        if(isSumOfAbundants.find(i) == isSumOfAbundants.end()){
            ans +=i;
        }
    }
    cout<<ans;
    return 0;
}
