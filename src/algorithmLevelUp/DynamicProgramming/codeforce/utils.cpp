#include <iostream>
#include <iostream>
#include <chrono>
#include <vector>
#include <set>
#include <map>
#include<math.h>
#include <stack>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#include <iomanip>
#include <bitset>
#include <utility>
#include <string>
#include <cctype>
#include <iomanip>
#include <numeric> // for NTH
#define bye return;
#define endl '\n'
#define ll long long
#define li long int
#define lli long long int
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define Number_of_leading_zeroes_l(num) __builtin_clz(num)
#define Number_of_leading_zeroes_ll(num) __builtin_clzll(num)
#define Number_of_trailing_zeroes_ll(num) __builtin_ctz(num)
#define pop_count_int(num) __builtin_popcount(num)
#define pop_count_l(num) __builtin_popcountl(num)
#define pop_count_ll(num) __builtin_popcountll(num)
#define ison(num, bit) (num & (1 << bit))
#define setoffif(num, bit) (num ^= (1 << bit)) // iff (num &(1<<bit))
#define setoff(num, bit) (num &= ~(1 << bit))
#define seton(num, bit) (num |= (1 << bit))
#define flipbit(num, bit) (num ^= (1 << bit))
#define LSB(num) (num & (-num))
#define indx_of_MSB(n)  _lg(n) // zero based from right 
#define Num_of_Digits(n) ((ll)log10(n) + 1)
#define ceill(n, m) (((n) / (m)) + (((n) % (m) ) ? 1 : 0))
#define lastOne(x) (__builtin_clzll(x)) 
#define fixed(n) fixed << setprecision(n)
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define Time cerr << "Time Taken: " << (float)clock() / CLOCKS_PER_SEC << " Secs" << "\n";
#define Pi  3.14159265358979323846264
#define INF_LL 0x3f3f3f3f3f3f3f3f
#define INF_INT 0x3f3f3f3f
#define sin(a) sin((a)*PI/180)
#define cos(a) cos((a)*PI/180)
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define M 32     //the size of the bitset must be a constant number. You can't read n and then declare bitset<n>
#define bitset(n) bitset<M>(n) // zero based , indexing beginning from the right not left 
// #define ordered_set tree<pair<int, int>, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>
// #define ordered_map tree<int, int, less<>, rb_tree_tag, tree_order_statistics_int_update>
ll sgn(ll x){ if(x > 0) return 1; if(x < 0) return -1; return 0;}
ll mod = 1e9 + 7;
ll mul(ll a, ll b) { return ((a % mod) * (b % mod)) % mod; }
ll add(ll a, ll b) { return ((a % mod) + (b % mod)) % mod; }
ll sub(ll a, ll b) { return ((a % mod) - (b % mod) + mod) % mod; }
const ll   llmin  = -1e18 ;
const ll   llmax  =  1e18 ;
const int  imin   = -1e9  ;
const int  imax   =  1e9  ;
const int  N      = 2e5   ;
using namespace std;
void AC() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); // or cin.tie(NULL)
    cout.tie(nullptr);  // or cout.tie(0)
}
void file_set(){ //string& file_name
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    // freopen((file_name+".in").c_str(), "r", stdin);
    // freopen((file_name+".out").c_str(), "w", stdout);
}
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.second < b.second);
}
    // THOSE WHO CAN'T REMEMBER THE PAST'RE CONDEMNED TO REPEAT IT (USE DP -_-) - George Santayana
    // PUSH HARDER THAN YESTERDAY IF YOU WANT A DIFFERENT TOMORROW !
    //YOU DON'T HAVE TO BE A GENIUS , YOU NEED TO BE DETERMINED .
const  ll MAX = 1e5+2;
ll vis[MAX];
ll fast_pow(ll a , ll b ){
    ll ans = 1 ;
    while (b > 0)
    {
        if(b&1){
            ans = mul(ans , a);
        }
        a = mul(a , a) ;
        b >>= 1 ;
    }
    ans = ans % mod ;
    return ans ; 
}
void LELLO(){
    ll n , k ; cin >> n  >> k ;
    cout<< fast_pow(n , k ) <<endl;
}
void driver(ll t=1)
{

    while (t--) LELLO();
    Time 
}
signed main()
{
    AC();
    // file_set();
    ll test ; cin >> test ;
    driver(test);
}
