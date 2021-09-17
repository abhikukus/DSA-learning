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


/*

QUESTION

Voting in Siruseri
Zonal Computing Olympiad 2010

Elections are on for the Siruseri Town Council. Elections in Siruseri work in a rather odd manner. Each candidate is assigned a unique identification number. The town is divided into five zones and each zone proposes a list of candidates, in some arbitrary order, that it would like to nominate to the Council. Any candidate who is proposed by three or more zones is elected. There is no lower limit or upper limit on the size of the Council.

Your task is to to calculate how many candidates are elected to the Council, given the lists proposed by the five zones.

For example, suppose the candidates proposed by the five zones are as follows:

Zone 1: [12,387,15,162,5]

Zone 2: [14,162,92,387,7,748]

Zone 3: [14,5,12,387]

Zone 4: [17,952,12,92,398,849]

Zone 5: [14,5,92,12,387]

In this example, 5 candidates are elected: these are [12,387,5,14,92].

Solution hint
Sort each list and then do a 5-way merge.

Input format
The first line of the input contains five integers N1, N2 N3, N4 and N5, where Nj is the number of candidates proposed by zone j, 1 ≤ j ≤ 5. This is followed by five lines of space separated integers. For 1 ≤ j ≤ 5, line j+1 of the input has Nj integers representing the list of candidates proposed by zone j.

Output format
Your output should be a single line consisting of one integer, the total number of candidates elected to the Town Council.

*/




