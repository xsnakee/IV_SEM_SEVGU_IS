#include <iostream>

int mover(int n){
	size_t i;
	for (i = n; i >0; --i){
		
		int k = mover(n-1);
		if (i != n) std::cout << i;
	}
	std::cout<<std::endl;
	return i;
}


int mover2(int n, int k){
	
	for (size_t i = 1; i <= n; ++i){
		
		
	}
}


int main(){
	
	mover(3);
	
	return 0;
}
