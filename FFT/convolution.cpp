#include <cmath>
#include <cstdio>
#include <iostream>
#include <complex>
#define complex complex<long double>
using namespace std;
// const complex iota = complex(0,1);
long double pi = acos(-1);

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
	// free(ae); free(ao); free(ye); free(yo);
	return y;
}

complex* inverse_fft(complex* vals, long long int n) {
	if(n==1) return vals;
	complex be[n/2];
	complex bo[n/2];
	for(int i=0;i<n-1;i+=2) {
		be[i/2]=vals[i];
	}
	for(int i=1;i<n;i+=2) {
		bo[i/2]=vals[i];
	}
	complex *xe = (complex*)(malloc((n/2)*sizeof(complex)));
	complex *xo = (complex*)(malloc((n/2)*sizeof(complex)));
	complex *x = (complex*)(malloc(n*sizeof(complex)));
	xe = inverse_fft(be,n/2);
	xo = inverse_fft(bo,n/2);
	complex wn = complex(cos(2*pi/n),-sin(2*pi/n)), w= complex(1,0);
	for(int k=0;k<(n/2);k++) {
		x[k] = xe[k] + w*xo[k];
		// x[k]/=complex(n,0);
		x[k+(n/2)] = xe[k] - w*xo[k];
		// x[k+(n/2)] /= complex(n,0);
		w*=wn;
	}
	// free(be); free(bo); free(xe); free(xo);
	return x;
}


int main() {

	long long int t,n,N;
	long double r,img;	
	cin>>t;
	while(t--) {
		cin>>n;

		//padding the coefficients
		N=1;
		while(N<2*n) {
			N*=2;
		}
		// cout<<N<<"***\n";	//Testing the padding

		//taking input
		complex* valsa = (complex*)malloc(N*sizeof(complex));
		complex* valsb = (complex*)malloc(N*sizeof(complex));
		complex* vals = (complex*)malloc(N*sizeof(complex));
		for(int i=0;i<n;i++) {
			cin>>r>>img;
			valsa[i]=complex(r,img);
		}
		for(int i=0;i<n;i++) {
			cin>>r>>img;
			valsb[i]=complex(r,img);
		}
		for(int i=n;i<N;i++) {
			valsa[i]=complex(0.0,0.0);
			valsb[i]=complex(0.0,0.0);
		}

		//calculating point form
		complex* finala = fft(valsa,N);
		complex* finalb = fft(valsb,N);
		for(int i=0;i<N;i++) {
			vals[i] = finala[i]*finalb[i];
		}
		complex* final = inverse_fft(vals,N);	
		// cout.precision(3);
		for(int i=0;i<N;i++) {
			final[i]/=complex(N*1.0,0.0);
			r = real(final[i]); img = imag(final[i]);
			if(r<0 && abs(r)<=(0.0001)) r=0.0;
			if(img<0 && abs(img)<=(0.0001)) img=0.0;
			cout.precision(3);
			cout<<fixed<<complex(r,img)<<'\n';
			// cout<<'(';
			// printf("%0.3lf",r);
			// cout<<',';
			// printf("%0.3lf",img);
			// cout<<")\n";
		}
	}
    return 0;
}