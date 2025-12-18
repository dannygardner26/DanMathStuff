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

vector<vector<int>> stringToGrid(string str){
    vector<int> flat;
    istringstream iss(str);
    int num;
    while(iss >> num){
        flat.push_back(num);
    }
    int n = sqrt(flat.size());
    vector<vector<int>> grid(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            grid[i][j] = flat[i * n + j];
        }
    }
    return grid;
}
int numDivisors(long long num){
    unordered_map<long,long> myMap = toFrequencyMap(pFactorize(num));
    
    long long ans = 1;
    for(const auto& [key, value] : myMap){
        if(value != 0){
            ans *= (value+1);
        }
    }
    return ans;
}
long long summate(long long a){
    return (a*(a+1))/2;
}
long long collatz(long long runs, long long num, unordered_map<long long, long long> &master){
    if(num <= 1){
        return runs;
    }
    long long orig = num;
    if(master.find(num) != master.end()){
        return master[num] + runs;
    }
    if(num%2 == 0){
        num/=2;
    }else{
        num= num*3+1;
    }
    long long res = collatz(runs+1, num, master);
    master[orig] = res-runs;
    return res;
}
vector<long long> longestCollatz(){
    int maxRun = 0;
    int maxVal = 0;
    unordered_map<long long, long long> master;
    for(long long i = 1 ; i <= 1000000; i++){
        long long store = collatz(0,i,master);
        
        if(store > maxRun){
            maxRun = store;
            maxVal = i;
        }
    }
    vector<long long> myAns = {maxRun, maxVal};
    return myAns;
}
long long uniquePaths(long long n){
    vector<vector<long long>> arr(n, vector<long long>(n,0));
    arr[0][0] = 1;
    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            
            long long sum = 0;
            if(c > 0){
                sum += arr[r][c-1];
            }
            if(r > 0){
                sum += arr[r-1][c];
            }
            arr[r][c] = sum;
            if(c == 0 && r == 0){
                arr[c][r] = 1;
            }
        }
    }
    return arr[n-1][n-1];
}
#include <bits/stdc++.h>
using namespace std;

string numToWords(int n) {
    vector<string> below_20 = {"", "one", "two", "three", "four", "five", "six", "seven",
                               "eight", "nine", "ten", "eleven", "twelve", "thirteen",
                               "fourteen", "fifteen", "sixteen", "seventeen", "eighteen",
                               "nineteen"};
    vector<string> tens = {"", "", "twenty", "thirty", "forty", "fifty", "sixty",
                           "seventy", "eighty", "ninety"};

    if (n == 1000) return "one thousand";

    if (n >= 100) {
        int h = n / 100;
        int r = n % 100;
        if (r == 0)
            return below_20[h] + " hundred";
        else
            // British usage: include "and"
            return below_20[h] + " hundred and " + numToWords(r);
    }

    if (n >= 20) {
        int t = n / 10;
        int r = n % 10;
        if (r == 0)
            return tens[t];
        else
            return tens[t] + "-" + below_20[r];
    }

    return below_20[n];
}

int letterCountNoSpaceHyphen(const string &s) {
    int cnt = 0;
    for (char c : s) {
        if (isalpha(static_cast<unsigned char>(c)))
            ++cnt;
    }
    return cnt;
}
vector<vector<int>> parseLines(const string& str) {
      vector<vector<int>> result;
      istringstream lines(str);
      string line;

      while (getline(lines, line)) {
          vector<int> row;
          istringstream iss(line);
          int num;
          while (iss >> num) {
              row.push_back(num);
          }
          if (!row.empty()) {
              result.push_back(row);
          }
      }
      return result;
  }

#endif
