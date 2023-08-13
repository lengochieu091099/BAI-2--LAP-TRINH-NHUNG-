int ktnguyento(int n) {
    int i;
	int count=0;
	if(n<2){
		return 0;
		}
	for(i=2;i<n;i++){
		if(n%i==0){
			count++;	
		}
	}
	if(count==0){
		return 1;
		}
	else return 0;		
}