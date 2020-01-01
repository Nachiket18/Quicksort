#include <stdio.h>
#include <stdlib.h>

int calculateComparisons = 0;
int calculateSwaps = 0;

void generateDataset(int a[])
{
 int uniQueValues = 100;
 int datasetSize = 10000;

 int j = 1;
 int k = 0;
    for (int i=1 ; i <= uniQueValues ; i++ )
    {
        j = 0;

        while(j < datasetSize/uniQueValues )
        {
            a[k] = i;
            k++;
            j++;
        }
    }


}

void randomize ( int arr[], int n )
{
    // Use a different seed value so that we don't get same
    // result each time we run this program
    srand ( time(NULL) );

    // Start from the last element and swap one by one. We don't
    // need to run for the first element that's why i > 0
    for (int i = n-1; i > 0; i--)
    {
        // Pick a random index from 0 to i
        int j = rand() % (i+1);

        // Swap arr[i] with the element at random index
        swap(&arr[i], &arr[j]);
    }
}



void swap(int *a, int *b)
{
    int temp;

    temp = *a;

    *a = *b;

    *b = temp;
}


/* partition function */
void partition(int a[], int low, int high)
{
    //printf("Partitioning");
    int pivot = low;
    int i, j,l;
    int pivotCounter;

    if(low < high)
    {

        i = j = low + 1;
        l = low;
        pivotCounter = l;

        while (i < high + 1)
        {

            if (a[i] < a[pivot])
            {
                swap(&a[i], &a[j]);
                i++;
                j++;
                calculateSwaps=calculateSwaps+1;
                calculateComparisons=calculateComparisons+1;
            }
            else if (a[i] > a[pivot])
            {
               i++;
               calculateComparisons = calculateComparisons+2;
            }
            else
            {


                swap(&a[i],&a[j]);
                swap(&a[j],&a[pivotCounter+1]);
                j++;
                i++;
                pivotCounter++;
                calculateSwaps = calculateSwaps+2;
                calculateComparisons=calculateComparisons+2;
            }

            //calculateComparisons++;
        }


        int k = j-1;
        int num = 0;



            for(int i = l; i <= pivotCounter; i++)
            {
                swap(&a[k],&a[i]);
                k--;
                num++;
                calculateSwaps++;
            }
              pivot = (j-1) - num+1 ;
              pivotCounter = (j-1);


/* Recursive Calls to partition entire array */
   partition(a, low, pivot - 1);
   partition(a, pivotCounter + 1, high);

    }
    else
        return;
}


int main()
{
    int a[] = {4 ,1 ,2 ,3 ,3 ,5 ,4 ,2 ,3 ,5 ,1 ,1 ,1 ,4 ,2 ,2 ,6 ,1 ,2 ,6 ,6 ,2 ,5 ,6 ,4 ,2 ,5 ,6 ,3 ,4 ,5 ,3 ,5 ,5 ,4 ,5 ,2 ,4 ,3 ,1 ,5 ,6 ,3 ,6 ,4 ,6 ,4 ,3 ,1 ,3 ,2 ,4 ,1 ,4 ,6 ,3 ,2 ,5 ,1 ,6};
    int b[] = {1, 1, 2, 3, 2, 5, 4, 2, 5, 2, 5, 3, 5, 4, 3, 2, 2, 6, 5, 6, 3, 1, 4, 3, 4, 1, 2, 6, 1, 6, 3, 6, 1, 3, 3, 5, 3, 4, 2, 4, 1, 5, 6, 2, 3, 4, 5, 5, 2, 1, 6, 4, 6, 1, 5, 6, 4, 6, 1, 4};
    int c[] = {6,6,5,5,5,5,5,4,4,3,3,3,2,2,2,2,2,2,1,1};

    int dataset[10000];
    generateDataset(dataset);
    randomize(dataset,10000);

    printf("\n");
    // Function call to partition the array
    partition(dataset,0,9999);
    printf("Returned after partitioning Three- Way Modified");


    for(int i = 0 ; i < 10000 ; i++ )
    {
        printf("%d ",dataset[i]);

    }
    printf("\n");
    printf("Comparisons:%d",calculateComparisons);
    printf("\n");
    printf("Swaps:%d",calculateSwaps);

}
