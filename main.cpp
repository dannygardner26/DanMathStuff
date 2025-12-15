#include <iostream>
#include "utils.h"

using namespace std;

int main() {
   long long ans = 0;
   for(long long i = 2; i < 2000000; i++){
        if(isPrime(i)){
            ans+=i;
        }
   }
   cout<<ans;
}

