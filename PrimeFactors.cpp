//Modify as required by the program.
//Complexity of O(root(n));

void primeFactors(lli n)  
{  
    if(n%2==0) cout<<2<<' ';
    while (n % 2 == 0)  
    {  
        n = n/2;  
    }  
    // n must be odd at this point. So we can skip   
    for (lli i = 3; i <= sqrt(n); i = i + 2)  
    {  
        if(n%i==0) cout<<i<<' ';  
        while (n % i == 0)  
        {
            n = n/i;  
        }  
    }  
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2  
    if (n > 2)  
        cout << n << " ";  
}