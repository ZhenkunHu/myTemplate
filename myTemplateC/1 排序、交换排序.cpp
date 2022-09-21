#include <stdio.h>
using namespace std;

void bubleSort(int a[],int n) {
    for(int i=0;i<n-1;i++) {
        bool flag=false;
        for(int j=n-1;j>i;j--)
            if(a[j-1]>a[j]) {
                int tem=a[j-1];
                a[j-1]=a[j];
                a[j]=tem;
                flag=true;
            }
        if(flag==false) return;
    }
}

//partition once
int Partition(int a[],int low,int high) {
    int pivot=a[low];
    while(low<high) {
        while(low<high&&a[high]>=pivot) --high;
        a[low]=a[high];
        while(low<high&&a[low]<=pivot) ++low;
        a[high]=a[low];
    }
    a[low]=pivot;//a[low]=a[high]
    return low;
}
void quickSort(int a[],int low,int high) {
    if(low<high) {
        int pivotPos=Partition(a,low,high);
        quickSort(a,low,pivotPos-1);
        quickSort(a,pivotPos+1,high);
    }
}



int main() {
    int a[10];
    for(int i=0;i<10;i++) {
        a[9-i]=i;
    }
    for(int i=0;i<10;i++) {
        printf("%d",a[i]);
    }
    quickSort(a,0,9);
    for(int i=0;i<10;i++) {
        printf("%d",a[i]);
    }
	return 0;
}
