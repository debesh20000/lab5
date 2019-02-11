#include<iostream>

using namespace std;

//recieves the values and swaps
void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}

//divides the array into two 
int partition(int arr[],int low,int high){

	int i=low-1;
//assigning the last element of array as pivot
	int p=arr[high];

	for(int j=low;j<=high-1;j++)
	{
//bringing elements on two sides of the pivot
		if(arr[j]<=p)
		{
			i++;    
//increment index of smaller element 
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return(i+1);

}

//  function that implements QuickSort 
void quicks(int arr[],int low,int high)
{

	//termination condition for the recursion
	if(low<high){
		//calling partition function
		int pi=partition(arr,low,high);
		quicks(arr,low,pi-1);     //recursion
		quicks(arr,pi+1,high);
	}

}

//displaying the array
void disp(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout <<arr[i]<<",";
	}
}

//main function
int main()
{
	int arr[]={3, 4, 7, 6 , 9 , 1, 2, 8, 10, 5};

	//gives its size
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<"sorted list is="<<endl;
	quicks(arr,0,n-1);
 	disp(arr, n);
}