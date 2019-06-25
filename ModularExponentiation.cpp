// Most Optimized Iterative Version
// For arbitrary x,y and m
//In general m = 1e9+7

long long modExpo (int x, int y, int m) {
    if (y == 0)
        return 1;

    x = x % m;
    long long res = 1;
    while (y > 0) {
        if (y%2)
            res = (res * x) % m;
        x = (x * x) % m; 
        y = y/2;
    }
    return res;
}
