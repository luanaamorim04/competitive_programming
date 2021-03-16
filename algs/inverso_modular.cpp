ll inv(ll a, ll b){
    return a>1 ? b-inv(b%a,a)*b/a : 1;
}