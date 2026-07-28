class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor)
            return 1;
        bool sign = true;
        if(dividend>=0 && divisor<0)
            sign = false;
        if(dividend<0 && divisor>0)
            sign = false;
        long ans = 0;
        long n = llabs((long long)dividend);
        long d = llabs((long long)divisor);
        while(n>=d){
            int cnt = 0;
            while(n>=(d<<(cnt+1)))
                cnt++;
            ans += 1LL<<cnt;
            n -= d*(1LL<<cnt);
        }
        if(ans==(1LL<<31) && sign==true)
            return INT_MAX;
        if(ans==(1LL<<31) && sign==false)
            return INT_MIN;
        return sign? (int)ans : (int)(-1*ans);
    }
};