complex* fft(complex* vals, long long int n) {
	if(n==1) return vals;
	complex *ae = (complex*)(malloc((n/2)*sizeof(complex)));
	complex *ao = (complex*)(malloc((n/2)*sizeof(complex)));
	for(int i =0 ;i<n-1;i+=2) {
		ae[i/2] = vals[i];
	}
	for(int i=1;i<n;i+=2) {
		ao[i/2] = vals[i];
	}
	complex *ye = (complex*)(malloc((n/2)*sizeof(complex)));
	complex *yo = (complex*)(malloc((n/2)*sizeof(complex)));
	complex *y = (complex*)(malloc(n*sizeof(complex))); 
 	ye = fft(ae,n/2);
	yo = fft(ao,n/2);
	complex wn = complex(cos(2*pi/n),sin(2*pi/n)),w = complex(1,0);
	for(int k=0;k<(n/2);k++) {
		y[k] = ye[k] + w*yo[k];
		y[k+(n/2)] = ye[k] - w*yo[k];
		w=w*wn;
	}
	return y;
}