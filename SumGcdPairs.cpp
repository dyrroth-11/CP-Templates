long long phi[MAX], result[MAX]; 
void computeTotient() 
{ 
    phi[1] = 1; 
    for (int i=2; i<MAX; i++) 
    { 
        if (!phi[i]) 
        { 
            phi[i] = i-1; 
            for (int j = (i<<1); j<MAX; j+=i) 
            { 
                if (!phi[j]) 
                    phi[j] = j; 
  
                phi[j] = (phi[j]/i)*(i-1); 
            } 
        } 
    } 
} 
  
void sumOfGcdPairs() 
{ 
    computeTotient(); 
  
    for (int i=1; i<MAX; ++i) 
    {  
        for (int j=2; i*j<MAX; ++j) 
            result[i*j] += i*phi[j]; 
    } 
    for (int i=2; i<MAX; i++) 
        result[i] += result[i-1]; 
} 
