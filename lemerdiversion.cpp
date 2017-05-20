#include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;

long length(int n){
  int d=1;
  if(n<=9){
    return d;
  }
  else{
    return d+length(n/10);
  }
}
long radix(long b,long zx,long *t){
  long i=0;
  long a[length(zx)];
  long za=zx;
  long zq=za/b;
  a[i]=za-zq*b;
  while(zq>0l){
    i++;
    za=zq;
    zq=za/b;
    a[i]=za-zq*b;
  }
  *t=i;
  zx=a[*t];
  return zx;
}
void lehmer(long x,long y,long b){
  float init=clock();
  long u,t,T;
  long xp,yp,q,Q,A,B,C,D;
  long xt,yt;
  int count=0,count1=0;
  while(y>=b){
    xp=radix(b,x,&xt);
    yp=radix(b,y,&yt);
    //cout<<yt<<"\t"<<yp<<endl;
    //cout<<yt<<"\t"<<xp<<endl;
    A=1;D=1;B=0;C=0;
    if(xt==yt){
      while((yp+C)!=0 && (yp+D)!=0){
        q=(xp+A)/(yp+C);
        Q=(xp+B)/(yp+D);
        //cout<<xp<<"\t"<<yp<<"\t"<<A<<"\t"<<B<<"\t"<<C<<"\t"<<D<<"\t"<<q<<"\t"<<Q<<endl;
        if(q!=Q) break;
        t=A-q*C;A=C;C=t;
        t=B-q*D;B=D;D=t;
        t=xp-q*yp;xp=yp;yp=t;
        count1++;
      }
    }
    if(B==0l){
      T=x%y;x=y;y=T;
    }
    else{
      T=A*x+B*y;
      u=C*x+D*y;
      x=T;
      y=u;
    }
    count++;
    //cout<<x<<"\t"<<y<<endl;
  }
  while(y>0){
    u=x%y;
    x=y;
    y=u;
    //cout<<x<<"\t"<<y<<endl;
  }
  cout<<x<<endl;
  float fin=clock_t();
  cout<<"redujo a"<<endl;
  double seg=(double)(fin-init)/CLOCKS_PER_SEC;
  cout<<seg*1000<<"milisegundos\n";
  cout<<count*count1<<" iteracione"<<endl;
}
long euclidesbinario(long x, long y)
{
    float init=clock();
    long g=1,t;
    int count=0;
    int contg=0;
    int count2=0;
    while(x%2==0 && y%2==0)
    {
        x/=2;
        y/=2;
        g*=2;
        //cout<<x<<"\t"<<y<<"\t"<<g<<endl;
        count++;
    }
    while(x!=0)
    {
        int count1=0;
        while(x%2==0)
        {
            x/=2;
            count1++;
         }
        int count3=0;
        while(y%2==0)
        {
            y/=2;
            count3++;
        }
        //cout<<x<<"\t"<<y<<"\t"<<t<<endl;
        contg=count1+count3;
        t=abs(x-y)/2;
        if (x>=y)x=t;
        else y=t;
        //cout<<"\n x->"<<x<<endl;
        //cout<<" y->"<<y<<endl;
        count2++;
    }
    float fin=clock_t();
    cout<<"redujo a"<<endl;
    double seg=(double)(fin-init)/CLOCKS_PER_SEC;
    cout<<seg*1000<<"milisegundos\n";
    cout<<count+(count2*contg)<<"iteracione \n";
    return g*y;
}
long minimo(long a, long b)
{
    float init=clock();
    long r;
    int count=0;
    r=a%b;
    while (r!=0){
        if(r>b/2)
            r=b-r;
        else{
            a=b;b=r;
            r=a%b;
        }
        //cout<<r<<"\t"<<a<<"\t"<<b<<endl;
        count++;
    }
    //cout<<b<<endl;
    float fin=clock_t();
    cout<<"redujo a"<<endl;
    double seg=(double)(fin-init)/CLOCKS_PER_SEC;
    cout<<seg*1000<<"milisegundos\n";
    cout<<count<<"iteracione \n";
    return b;
}
int gcd2(int A, int B){
  float init=clock();
  int count=0;
	while(B!=0){
		int R=A%B;
		A=B;
		B=R;
    //cout<<R<<"\t"<<A<<"\t"<<B<<endl;
    count++;
	}
  float fin=clock_t();
  cout<<"redujo a"<<endl;
  double seg=(double)(fin-init)/CLOCKS_PER_SEC;
  cout<<seg*1000<<"milisegundos\n";
  cout<<count<<endl;
  return A;
}
int main(int argc, char const *argv[]) {
  long x,y,b;
  while(true){
    cin>>x>>y>>b;
    lehmer(x,y,b);
    cout<<euclidesbinario(x,y)<<endl;
    cout<<minimo(x,y)<<endl;
    cout<<gcd2(x,y)<<endl;
  }
    return 0;
}
