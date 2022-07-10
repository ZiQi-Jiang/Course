#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <cstdio>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;
 
int main(){
	
	ios::sync_with_stdio(false);
	
	int n,r;
	cin>>n>>r;
	
	int a[n];
	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	if(r+r>=n){
		for(int i=0;i<n;i++){
			if(i!=0)
			cout<<" ";
			cout<<a[i];
		}
	}
	else{
		sort(a+r,a+n-r);
		for(int i=0;i<n;i++){
			if(i!=0)
			cout<<" ";
			cout<<a[i];
		}
	}
	
	return 0;
}