#include<bits/stdc++.h>
#include<iostream>
#include <iomanip>
#include<map>
using namespace std;

 //MACROS
#define ll long long int
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define up upper_bound
#define bs binary_search
#define umap unordered_map
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define d0(x) cout<<(x)<<" "
#define d1(x) cout<<(x)<<endl
#define d2(x,y) cout<<(x)<<" "<<(y)<<endl
#define max3(a,b,c) max(max((a),(b)),(c))
#define max4(a,b,c,d) max(max((a),(b)),max((c),(d)))
#define min3(a,b,c) min(min((a),(b)),(c))
#define min4(a,b,c,d) min(min((a),(b)),min((c),(d)))
#define all(v) (v).begin(),(v).end()
#define scan2d(dp,n,compo) for(int i=0;i<n;i++){for(int j=0;j<compo;j++)cin>>dp[i][j];}
#define scan1d(dp,n) for(int i=0;i<n;i++)cin>>dp[i];
#define print2d(dp,n,compo) for(int i=0;i<n;i++){for(int j=0;j<compo;j++)cout<<dp[i][j]<<" ";cout<<"\n";}
#define print1d(dp,n) for(int i=0;i<n;i++)cout<<dp[i]<<" ";cout<<"\n";
//Constraints
ll eps = 1e-10;
ll zero = acos(1.0);
ll pi = acos(-1.0);
const ll MOD = 1e9+7;
const ll mod = 998244353;
const ll inf = 2e18;
const ll INF = 2e18;
const int N = 100050;
const int M = 1055;

bool f(const int x, const int y){
    return (x>y);
}

bool f1( const pair<ll,ll>&A, const pair<ll,ll>&B){
    return (A.first > B.first);
}

ll gcd(ll a,ll b){       //gcd
    if(b==0)
        return a;
    return gcd(b,a%b);
}

ll LCM(ll x, ll y){
    return ((x*y)/gcd(x,y));
}
ll _ceil(ll a, ll b){
    if(a%b==0)
        return (a/b);           //ceil
    else
        return (a/b)+1;
}
bool isPrime(int n)              //Check Prime
{
    if (n <= 1)  return false;
    if (n <= 3)  return true;
    if (n%2 == 0 || n%3 == 0) return false;

    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;
    return true;
}

int modu(int a, int b){
    if(a>=b)
        return(a-b);      //taking positive value
    else
        return(b-a);
}

//The below function is used to compare two maps
bool map_compare (map<char,int> &lhs, map<char,int> &rhs) {
    // No predicate needed because there is operator== for pairs already.
    return lhs.size() == rhs.size()
        && std::equal(lhs.begin(), lhs.end(),
                      rhs.begin(),rhs.end());
}


void init_code(){
   #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}


bool Issafe(vector<vector<ll>>&grid, ll i, ll j, ll k, ll N){
    for(ll z=0; z<N ; z++){
        if(grid[z][j]==k || grid[i][z]==k){
            return false;
        }
    }

    ll s=(sqrt(N));

    ll r=(i-(i%s));
    ll t=(j-(j%s));

    for(ll a=0; i<s; i++){
        for(ll b=0; b<s; b++){
            if(grid[r+a][t+b]==k)return false;
        }
    }
    return true;
}

bool solve_suduko( vector<vector<ll>> &grid , ll N){
ll i, j;
ll key=0;
for(i=0; i<N ; i++){
    for(j=0; j<N; j++){
        if(grid[i][j]==0){
            key=(-1);
            break;
        }
    }
    if(key==(-1))
        break;
}

if(i==(N)&& j==(N)){
    return true;
}

for(ll k=1; k<=N ; k++){
    if(Issafe(grid,i,j,k,N)){
        grid[i][j]=k;
        if(solve_suduko(grid,N)==true)
            return true;
        grid[i][j]=0;

    }

}
return false;
}

int main(){ 
    io;
 init_code();

 cout<<"Enter the size of the grid"<<endl;
 ll N;
 cin>>N;

vector<vector<ll>>grid;

for(ll i=0; i<N; i++){
    vector<ll>v;
    for(ll j=0; j<N; j++){
    ll a;cin>>a;
    v.pb(a);
    }
    grid.pb(v);
}

if(solve_suduko(grid,N)){
    cout<<"Yes, Suduko is solvable . The solution is given as"<<endl;

    print2d(grid,N,N);

}
else{
    cout<<"No! Suduko cannot be solved"<<endl;
}

return 0;

}
