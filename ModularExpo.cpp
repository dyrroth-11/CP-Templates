 long long int modExp(long long int x,long long int n,long long int M)
 {
   long long  int result=1;
    while(n>0)
    {
        if(n&1)
            result=(result * x)%M;
        x=(x*x)%M;
        n=n/2;
    }
    return result;
 }