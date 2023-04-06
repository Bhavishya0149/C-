#include<string>
#include <iostream>
using namespace std;

int main() {
	
	int T; cin>>T;
	
	while(T--){
	    int N; string S;
	    cin>>N; cin>>S;
	    
        int soln = 0;

	    string ans = "";
	    
	    for(int i = 0; i < N; i++){
	        ans += "0";
	    }
	    
	    for(int i = 1; i <= N; i++){
	        
	        int temp = char(S[i - 1]) ^ char(ans[i - 1]);
	        // char temp2 = to_string(temp);
            ans[i] = char(temp + 48);
	        // cout<<temp<<endl;
	    }
	    
        int count = 0;
        for(int i = 0; i < N; i++){
            if(ans[i] == '1') count++;
        } soln = count;

        ans = "";
	    
	    for(int i = 0; i < N; i++){
	        ans += "1";
	    } 
	    
	    for(int i = 1; i <= N; i++){
	        
	        int temp = char(S[i - 1]) ^ char(ans[i - 1]);
	        // char temp2 = to_string(temp);
            ans[i] = char(temp + 48);
	        // cout<<temp<<endl;
	    }

        count = 0;
        for(int i = 0; i < N; i++){
            if(ans[i] == '1') count++;
        } 

        if(count > soln) soln = count;

        cout<<count<<endl;

	}

	
	return 0;
}
