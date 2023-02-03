//by: SAGAR AGRAWAL
//21COB298
//GM6623-A2CO-41
//DATED:26/09/2022

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


//Saperate chaining functions
int hash[50][6];
void chainInsert(int element)
{
    int ind = element % 50;
    if (hash[ind][0] == -1)
    {
        hash[ind][0] = element;
    }
    else
    {
        for (int i = 0; i < 6; i++)
        {
            if (hash[ind][i] == -1)
            {
                hash[ind][i] = element;
                break;
            }
        }
    }
}
void chainDisplay()
{
    for (int j = 0; j < 50; j++)
    {
        printf("\n");
        if (hash[j][0] == -1)
            continue;
        else
        {
            for (int i = 0; i < 6; i++)
            {
                if (hash[j][i] == -1)
                {
                    break;
                }
                printf("-->%d", hash[j][i]);
                
            }
        }
    }
}
void chainSearch(int ele)
{
    int index = ele % 50;
    int flag = 0;
    if (hash[index][0] == -1)
    {
        printf("\n Element %d Not found in Hash TAble", ele);
        flag = 1;
    }
    else
    {
        for (int i = 0; i < 6; i++)
        {
            if (hash[index][i] == ele)
            {
                printf("Element %d found at Index=%d\n", ele, index);
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            printf("\n Element %d Not found in Hash TAble", ele);
        }
    }
}
void chaining(int arr[], int n)
{
    printf("______________________________________________");
    printf("\n\t\tSAPERATE CHAINING\n\n\n");
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            hash[i][j] = -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        chainInsert(arr[i]);
    }
    // Here all the data has been stored in the hash table
    printf("\nAll Elements in above array are added in the Hash table using Saperate Chaining Collision Methods \n");
    printf("Choose the Desired Operation \n");
    printf("\nPress    1. Insert New Element\n \t 2. Display Hash Table\n \t 3. Search Element\n \t 4. Quit\n");
    int ch, ele;

    while (true)
    {
        scanf("%d", &ch);
        if (ch == 1)
        {
            printf("\n Enter the element to insert: ");
            scanf("%d", &ele);
            chainInsert(ele);
            printf("\n Element Inserted in Hash table successfully\n ");
        }
        else if (ch == 2)
        {
            chainDisplay();
        }
        else if (ch == 3)
        {
            printf("\n Enter the element to Search Its Index in hash Table: ");
            scanf("%d", &ele);
            chainSearch(ele);
        }
        else if (ch == 4)
        {
            break;
        }
        else
        {
            printf("\n Invalid Input! Choose Again: ");
        }
        printf("\n------------------------------------------------------------------------------------------");
        printf("\nPress    1. Insert New Element\n \t 2. Display Hash Table\n \t 3. Search Element\n \t 4. Quit\n \t ");
    }
}


// LINEAR PROBING FUNCTIONS
void InsertLinear(int ele, int linearhash[])
{
    int ind;
    for (int i = 0; i < 50; i++)
    {
        ind = ((3 * ele) + 5 + i) % 50;
        if (linearhash[ind] != -1)
        {
            continue;
        }
        else
        {
            linearhash[ind] = ele;
            break;
        }
    }
}
void DisplayLinear(int linearhash[])
{
    for (int i = 0; i < 50; i++)
    {
        printf("\n");
        if (linearhash[i] == -1)
        {
            continue;
        }
        else
        {
            printf("%d ", linearhash[i]);
        }
    }
}
void LinearSearch(int ele, int linearhash[])
{
    int flag = 0;
    int j, i = 0;
    while (i < 50)
    {
        j = ((3 * ele) + 5 + i) % 50;
        if (linearhash[j] == ele)
        {
            printf("Element %d found at Index=%d\n", ele, j);
            flag = 1;
            break;
        }
        else
        {
            i++;
        }
    }

    if (flag == 0)
    {
        printf("\n%d do not found in the hash table", ele);
    }
}
void linearprob(int arr[], int n)
{
    printf("______________________________________________");
    printf("\n\t\tLINEAR PROBING\n\n\n");

    int linearhash[50];
    for (int i = 0; i < 50; i++)
    {
        linearhash[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        InsertLinear(arr[i], linearhash);
    }
    printf("\nAll Elements in above array are added in the Hash table using Linear Probing \n");
    printf("Choose the Desired Operation \n");
    printf("\nPress    1. Insert New Element\n \t 2. Display Hash Table\n \t 3. Search Element\n \t 4. Quit\n");
    int ch, ele;
    while (true)
    {
        scanf("%d", &ch);
        if (ch == 1)

        {
            printf("\n Enter the element to insert: ");
            scanf("%d", &ele);
            InsertLinear(ele, linearhash);
            printf("\n Element Inserted in Hash table successfully\n ");
        }
        else if (ch == 2)
        {
            DisplayLinear(linearhash);
        }
        else if (ch == 3)
        {
            printf("\n Enter the element to Search Its Index in hash Table: ");
            scanf("%d", &ele);
            LinearSearch(ele, linearhash);
        }
        else if (ch == 4)
        {
            break;
        }
        else
        {
            printf("\nInvalid Input! Choose Again: ");
            continue;
        }
        printf("\n------------------------------------------------------------------------------------------");
        printf("\nPress    1. Insert New Element\n \t 2. Display Hash Table\n \t 3. Search Element\n \t 4. Quit\n \t ");
    }
}

// QUADRATIC PROBING FUNCTIONS
void InsertQuadratic(int ele, int quadratichash[])
{
    int ind;
    for (int i = 0; i < 50; i++)
    {
        ind = ((3 * ele) + 5 + i ^ 2) % 50;
        if (quadratichash[ind] != -1)
        {
            continue;
        }
        else
        {
            quadratichash[ind] = ele;
            break;
        }
    }
}
void DisplayQuadratic(int quadratichash[])
{
    for (int i = 0; i < 50; i++)
    {
        printf("\n");
        if (quadratichash[i] == -1)
        {
            continue;
        }
        else
        {
            printf("%d ", quadratichash[i]);
        }
    }
}
void SearchQuadratic(int ele, int quadratichash[])
{
    int flag = 0;
    int j, i = 0;
    while (i < 50)
    {
        j = ((3 * ele) + 5 + i ^ 2) % 50;
        if (quadratichash[j] == ele)
        {
            printf("Element %d found at Index=%d\n", ele, j);
            flag = 1;
            break;
        }
        else
        {
            i++;
        }
    }

    if (flag != 1)
    {
        printf("\n%d do not found in the hash table", ele);
    }
}
void Quadraticprob(int arr[], int n)
{
    printf("_____________________________________________");
    printf("\n\t\tQUADRATIC PROBING\n\n\n");

    int quadratichash[50];
    for (int i = 0; i < 50; i++)
    {
        quadratichash[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        InsertQuadratic(arr[i], quadratichash);
    }
    printf("\nAll Elements in above array are added in the Hash table using Quadratic Probing\n");
    printf("Choose the Desired Operation \n");
    printf("\nPress    1. Insert New Element\n \t 2. Display Hash Table\n \t 3. Search Element\n \t 4. Quit\n");
    int ch, ele;
    while (true)
    {
        scanf("%d", &ch);
        if (ch == 1)

        {
            printf("\n Enter the element to insert: ");
            scanf("%d", &ele);
            InsertQuadratic(ele, quadratichash);
            printf("\n Element Inserted in Hash table successfully\n ");
        }
        else if (ch == 2)
        {
            DisplayQuadratic(quadratichash);
        }
        else if (ch == 3)
        {
            printf("\n Enter the element to Search Its Index in hash Table: ");
            scanf("%d", &ele);
            SearchQuadratic(ele, quadratichash);
        }
        else if (ch == 4)
        {
            break;
        }
        else
        {
            printf("\nInvalid Input! Choose Again: ");
            continue;
        }
        printf("\n------------------------------------------------------------------------------------------");
        printf("\nPress    1. Insert New Element\n \t 2. Display Hash Table\n \t 3. Search Element\n \t 4. Quit\n \t ");
    }
}

// DOUBLE HASHING METHODS
void InsertDouble(int ele, int doublehash[])
{
    int ind, h1, h2;
    ind = ele % 50; //****************************************************************
    if (doublehash[ind] == -1)
    {
        doublehash[ind] = ele;
    }
    else
    {
        for (int i = 0; i < 50; i++)
        {
            h1 = ele % 50;
            h2 = 13 - (ele % 13);

            ind = (h1 + (i * h2)) % 50; //*******************************
            if (doublehash[ind] == -1)
            {
                doublehash[ind] = ele;
                break;
            }
        }
    }
}
void DisplayDouble(int doublehash[])
{
    for (int i = 0; i < 50; i++)
    {
        printf("\n");
        if (doublehash[i] == -1)
        {
            continue;
        }
        else
        {
            printf("%d ", doublehash[i]);
        }
    }
}
void SearchDouble(int ele, int doublehash[])
{
    int flag = 0;
    int j, i = 0, h1, h2;
    h1 = ele % 50;
    h2 = 13 - (ele % 13);
    j = h1;
    if (doublehash[j] == ele)
    {
        printf("Element %d found at Index=%d\n", ele, j);
        flag = 1;
    }
    else
    {
        while (i < 50)
        {

            j = (h1 + (i * h2)) % 50;
            if (doublehash[j] == ele)
            {
                printf("Element %d found at Index=%d\n", ele, j);
                flag = 1;
                break;
            }
            else
            {
                i++;
            }
        }
    }

    if (flag != 1)
    {
        printf("\n%d do not found in the hash table", ele);
    }
}
void DoubleHash(int arr[], int n)
{
    printf("______________________________________________");
    printf("\n\t\tDOUBLE HASHING\n\n\n");

    int doublehash[50];
    for (int i = 0; i < 50; i++)
    {
        doublehash[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        InsertDouble(arr[i], doublehash);
    }
    printf("\nAll Elements in above array are added in the Hash table using Double Hashing \n");
    printf("Choose the Desired Operation \n");
    printf("\nPress    1. Insert New Element\n \t 2. Display Hash Table\n \t 3. Search Element\n \t 4. Quit\n ");
    int ch, ele;
    while (true)
    {
        scanf("%d", &ch);
        if (ch == 1)

        {
            printf("\n Enter the element to insert: ");
            scanf("%d", &ele);
            InsertDouble(ele, doublehash);
        }
        else if (ch == 2)
        {
            DisplayDouble(doublehash);
        }
        else if (ch == 3)
        {
            printf("\n Enter the element to Search Its Index in hash Table: ");
            scanf("%d", &ele);
            SearchDouble(ele, doublehash);
        }
        else if (ch == 4)
        {
            break;
        }
        else
        {
            printf("\nInvalid Input! Choose Again: ");
            continue;
        }
        printf("\n------------------------------------------------------------------------------------------");
        printf("\nPress    1. Insert New Element\n \t 2. Display Hash Table\n \t 3. Search Element\n \t 4. Quit\n \t ");
    }
}

int main()
{
    int n;
    printf("Enter the no of elements on array : ");
    scanf("%d", &n);

    int arr[n];
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (rand() % 1000) + 1;
    }

    printf("Array Elements: \n");

    for (int i = 0; i < n; i++)
    {
        printf("%d \t", arr[i]);
    }

    printf("\nNow These Elements are to be stored using Hashing Methods\n");
    printf("Choose the desired Method to impliment hashing on these array elements \n");

    printf("\n-----------------------------------------\n");
    printf("---------IMPLIMENTING HASHING------------");

    int choice;
    while (true)
    {
        printf("\n-----------------------------------------\n");
        printf("\nPress    1. Saperate Chaining\n \t 2. Linear Probing\n \t 3. Quadratic Probing\n \t 4. Double Hasing\n \t 5. Quit \n\n");

        scanf("%d", &choice);
        if (choice == 1)
        {
            // hash func k%50;
            chaining(arr, n);
        }

        else if (choice == 2)
        {
            // using hash function 3k+5+i)%50
            linearprob(arr, n);
        }

        else if (choice == 3)
        {
            // using hash function 3k+5+i^2)%50
            Quadraticprob(arr, n);
        }

        else if (choice == 4)
        {
            // using hash function k%50, 13-(k%13)
            DoubleHash(arr, n);
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            printf("Wrong entry! Choice dosen't match.\n Try Again");
            continue;
        }
    }

    return 0;
}