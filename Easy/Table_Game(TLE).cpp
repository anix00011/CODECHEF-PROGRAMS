#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    char M[100001];
     char N[100001];
    while (t-- > 0) {
        cin>>M;
        cin>>N;
        int N1 = strlen(N) + 1;
        int M1 = strlen(M) + 1;
        vector< vector<int> > v(N1, vector<int>(M1));
        //int v[N1][M1];
        v[0][0] = 0;
            for (int i = 1; i < N1; i++) {
                v[i][0] = N[i - 1] - '0';
            }
            for (int i = 1; i < M1; i++) {
                v[0][i] = M[i - 1] - '0';
            }
            for (int i = 1; i < 3; i++) {
                for (int j = 1; j < M1; j++) {
                    if ((v[i - 1][j] & v[i][j - 1]) == 0) v[i][j] = 1;
                    else v[i][j] = 0;
                }
            }
            for (int i = 3; i < N1; i++) {
                for (int j = 1; j < 3; j++) {
                    if ((v[i - 1][j] & v[i][j - 1]) == 0) v[i][j] = 1;
                    else v[i][j] = 0;
                }
            }
            int Q ;
            cin>>Q;
            int b[Q];
            for (int i = 0; i < Q; i++) {
                int a1;
                cin>>a1;
                int a2;
                cin>>a2;
                if(a1>2&&a2>2) {
                    if (a1 < a2) cout<< v[2][a2 - (a1 - 2)];
                    else cout<< v[a1 - (a2 - 2)][2];
                }else {
                    cout<<v[a1][a2];
                }
            }
           cout<<"\n";
        }
}
