#include <bits/stdc++.h>
#include<stdio.h>

using namespace std;

void swap(int arr[][50001], int i, int k, int j)
{
    int temp = arr[i][k];
    arr[i][k] = arr[i][j];
    arr[i][j] = temp;
}

void printArray(int arr[][50001], int i, int size)
{
    
    for (int j=0; j < size; j++)
        printf("%d ", arr[i][j]);
    printf("\n");
}

int partition(int arr[][50001], int i, int l, int r)
{   
    int pivot = arr[i][r];
    int p = l-1;
    for(int j=l; j<=r-1; j++)
    {
        if(arr[i][j]<pivot)
        {
            p++;
            swap(arr, i, p, j);
        }
    }
    swap(arr, i, p+1, r);

    return p+1;
}


void quicksort(int arr[][50001], int i, int l, int r)
{   
    if(l<r)
    {   

        int pi = partition(arr, i, l, r);


        quicksort(arr, i, l, pi-1);
        quicksort(arr, i, pi+1, r); 
    }
    
}


 
// Driver program to test above functions
int main()
{   
    int n[5];

    for (int i = 0; i < 5; ++i)
    {
        cin>>n[i];
    }

    int arr[5][50001];

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < n[i]; ++j)
        {
            cin>>arr[i][j];
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        quicksort(arr, i, 0, n[i]-1);

        //printArray(arr, i, n[i]);
    }

    


    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

    int resultSize = n[0]+n[1]+n[2]+n[3]+n[4];
    int result[resultSize];
    int resultidx = 0;
    bool noElement = false;
    int n2[5] = {0};




    for (int i = 0; i < 5; ++i)
    {
        if (n2[i] < n[i])
        {
            pq.push(make_pair(arr[i][n2[i]], i));
        }else
        {
            pq.push(make_pair(INT_MAX, i));
        }
        n2[i]++;
    }

    int i=0;
    int count[6] = {0};
    while(noElement == false)
    {   
        
        if (count[5] == 5)
        {
            noElement == true;
            break;
        }

        pair<int, int> top = pq.top();
        result[resultidx] = top.first;
        i = top.second;
        resultidx++;
        pq.pop();


        if (n2[i] < n[i])
        {
            pq.push(make_pair(arr[i][n2[i]], i));
        }else
        {
            pq.push(make_pair(INT_MAX, i));
            if (count[i]==0)
            {
                count[i]=1;
                count[5]++;
            }
        }
        n2[i]++;

    }

    int ans = 0;
    for (int i = 0; i < resultSize; )
    {
        if (result[i] == result[i+2])
        {
            ans++;
            i = i+2;
            while(result[i]==result[i+1])
            {
                i++;
            }
        }else
        {
          i++;
        }
    }

    cout << ans;

    return 0;
}




