/* Optimal Page Replacement Algo*/

#include<stdio.h> 

int linearSearch(int arr[], int size, int key){
	for(int i=0;i<size;i++){
		if(arr[i]==key){
			return i;
		}
		return size+1;
	}
}

int max(int arr[], int size){
	int a=0;
	for(int i=0;i<size;i++){
		if(arr[a]<arr[i]){
			a=i;
		}
	}
	return a;
}

int Optimal(int arr[], int size, int pages[], int numPages, int*ph, int*pf){
	int temp[size];
	for(int i=0;i<numPages;i++){
		if(linearSearch(arr,size,pages[i])!=size+1){
			*ph+=1;
		}
		else{
			for(int j=0;j<size;j++){
				temp[j] = linearSearch(pages,numPages,arr[j]);
			}
			int k = max(temp,size);
			arr[k] = pages[i];
			*pf+=1;
		}
	}
	return 0;
}


int main(){
	int arr[] = {0,0,0};
	int size = 3;
	int pages[] = {1,2,5,3,5,4,2,3,5,3,2};
	int numPages = 11;
	int ph = 0;
	int pf = 0;
	Optimal(arr,size,pages,numPages,&ph,&pf);
	printf("Optimal: ph: %d pf: %d\n",ph,pf);
	return 0;
}
