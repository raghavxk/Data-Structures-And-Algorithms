#include <bits/stdc++.h>

#define deb(x) cout << (#x) << " is " << (x) << endl
#define nline "\n"
#define read(x) int x; cin>>x
#define SaveTime() ios_base::sync_with_stdio(false);std::cin.tie(NULL)
#define setDecimalPrecision(Precision) fixed<<showpoint<<setprecision(Precision)
typedef long long int ll;

const int MOD = 1000000007;

using namespace std;

void PrintVect(vector<int> vi) {
    ll size = vi.size();
    for (ll i = 0; i < size; ++i) {
        cout << vi[i] << " ";
    }
    cout << nline;
    return;
}

void LetterCasePermutation(string input,string output){
    if(input.length()==0){
        cout<<output<<nline;
        return;
    }
    if(isdigit(input[0])){
        output.push_back(input[0]);
        input.erase(input.begin()+0);
        LetterCasePermutation(input,output);
        return;
    }    
    if(isalpha(input[0])){
        string output_1= output;
        string output_2= output;
        output_1.push_back(tolower(input[0]));
        output_2.push_back(toupper(input[0]));
        input.erase(input.begin()+0);
        LetterCasePermutation(input,output_1);
        LetterCasePermutation(input,output_2);
        return;
    }
    return;
}

int solve() {
    LetterCasePermutation("ab1c","");
    return 0;
}

int main() {
    SaveTime();
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif

    int T = 1;
    cin >> T;
    while (T--)
        solve();

    return 0;
}
