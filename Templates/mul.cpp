
ll mul(ll x,ll y,ll MOD){
    x=x%MOD,y=y%MOD;
    return ((x*y-(ll)(((long double)x*y+0.5)/MOD)*MOD)%MOD+MOD)%MOD;
}