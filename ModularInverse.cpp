lli gcdExtended(lli a, lli b, lli *x, lli *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    lli x1, y1; // To store results of recursive call 
    lli gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 

lli modInverse(lli a, lli m) 
{ 
    lli x, y; 
    if(a<0) a+=m;
    lli g = gcdExtended(a, m, &x, &y);
    lli res = (x%m + m) % m; 
    return res; 
}