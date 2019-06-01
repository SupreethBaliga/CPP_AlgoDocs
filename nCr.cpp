long int nCr(long int n,long int r)			//change the data-type as per requirement
{
	long int ans=1;
	for(long int i=1; i<=r ; i++)
	{
		ans=( ans* ( n-i+1 ) / i);
	}
	return ans;
}
