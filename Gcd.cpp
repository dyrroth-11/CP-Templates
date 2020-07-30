long long int gcd(long long int A,long long int B) {
    if(B==0)
        return A;
    else
        return gcd(B, A % B);
}