#include <iostream>
using namespace std;

int main() {
	int T; cin>>T;
	long long int S;long long int L;
	while(T--){
	    cin>>S>>L; int Arr[S]; int Cmax = 0;
	    
        for(int i = 0; i < S; i++){
	        cin>>Arr[i];
	    }

        int ans = 0;
        for (int j = 0; j < S; j++){
            int CurrEle = Arr[j];
            
            if (CurrEle <= (L + 1)/2){
                Cmax = L - CurrEle;
            } else {
                Cmax = CurrEle - 1;
            }
            

            ans += Cmax; Cmax = 0;
        }
        cout<<ans; 
	}
	return 0;
}
