#include "bits/stdc++.h"
#define ll long long
using namespace std;


int cntInversionBrute(int arr[],int n)
{
	int cnt=0;

	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++){
			if(arr[i] > arr[j]){
				cnt++;
			}
		}
	}

	return cnt;
}

int merge(int arr[],int l,int mid,int h)
{
	int cnt=0;

	int a = mid-l+1;
	int b = h-mid;
	int temp[a+b];

	int i=l;
	int j=mid+1;
	int k=0;

	while(i<=mid && j<=h){

		if(arr[i] <= arr[j]){
			temp[k] = arr[i];
			k++;
			i++;
		}else{
			cnt += mid-i+1;

			temp[k] = arr[j];
			k++;
			j++;
		}

	}

	while(i<=mid){     // for leftout items
		temp[k] = arr[i];
		i++;
		k++;
	}
	while(j<=h){     // for leftout items
		temp[k] = arr[j];
		j++;
		k++;
	}

	 //// copy back to main array from temp
	k=0;
	for(int x=l;x<=h;x++)
	{
		arr[x] = temp[k];
		k++;
	}
	return cnt;

}
int mergeSort(int arr[],int l,int h)
{
	int inv_count = 0;
	if(h>l)
	{
		int mid = (l+h)/2;
		inv_count += mergeSort(arr,l,mid);
		inv_count += mergeSort(arr,mid+1,h);

		inv_count += merge(arr,l,mid,h);

	}

	return inv_count;
}

int main(void){
	ios::sync_with_stdio(0); cin.tie(0);

// write code here
	int arr[] = {4,5,6,3,1,7,2};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << "Inversion count with brute force : " << cntInversionBrute(arr,n) << endl;
	cout <<"Inversion count with merge sort : " <<  mergeSort(arr,0,n-1) << endl;;

	for(int i=0;i<n;i++){
		cout << arr[i] << " ";
	}

return 0;
}