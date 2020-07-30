
ll iv[N],f1[N],f2[N];
 
iv[1]=1;f1[0]=1;f2[0]=1;//Base Cases

for(int i=2;i<N;i++){
    iv[i]=M-M/i*iv[M%i]%M;
}
for(int i=1;i<N;i++){
    f1[i]=f1[i-1]*i%M;
    f2[i]=f2[i-1]*iv[i]%M;
}