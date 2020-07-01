#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
    int sum=0;
    string a[8];
    for(int i=0; i<8; i++){
        cin >> a[i];
        }
    int b[8];
    iota(b,b+8,0);
    do{
        int check=0;
        for(int i=0; i<8; i++){
            if(a[b[i]][i] =='*'){
                break;
            }
            else{
                check+=1;
            }
        }
        int check2=0;
        for(int i=0; i<8; i++){
            int m=0;
            for(int j=0; j<8; j++){
                if(i!=j){
                    if(abs(i-j)==abs(b[i]-b[j])){
                        m=1;
                        break;
                    }
                }
            }
            if(m==1){
            break;
            }
            check2+=1;
        }
        if(check==8 && check2==8){
            sum++;
        }

    }while(next_permutation(b,b+8));
    cout << sum;
}
