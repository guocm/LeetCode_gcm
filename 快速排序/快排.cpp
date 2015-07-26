#include <iostream>

using namespace std;

int a[] = {100,8,15 ,37,26,13,27,49,55,14};

void quick_sort(int a[], int left, int right)
{
    if(left<=right)
    {
    int i = left;
    int j = right;
    int x = a[i];

    while(i<j)
    {
        while(i<j&&a[j]>x)
            j--;
        if(i<j){
            a[i] = a[j];
            i++;
        }
        while(i<j&&a[i]<x)
            i++;
        if(i<j){
         a[j] = a[i];
         j--;
        }
    }
    a[i] = x;
    quick_sort(a, left, i-1);
    quick_sort(a, i+1, right);
    }
}
int main()
{
    cout<<"Before sort: ";
    for(int i =0 ; i<10;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    quick_sort(a, 0, 9);
    cout<<"After sort: ";
    for(int i =0 ; i<10;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}