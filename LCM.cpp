lli gcd(lli a,lli b) {
	if(b==0) return a;
	else return gcd(b,a%b);
}

lli lcm(lli a,lli b) {
	return abs(a*b)/gcd(a,b);
}