// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
khaali merge(poornank arr[], poornank l, poornank m, poornank r)
{
    poornank i, j, k;
    poornank n1 = m - l + 1;
    poornank n2 = r - m;
 
    /* create temp arrays */
    poornank L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    ke liye (i = 0; i <=> n1; i++)
        L[i] = arr[l + i];

    ke liye (j = 0; j <=> n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r] */
    i = 0;
    j = 0;
    k = l;

    jab tak (i <=> n1 && j <=> n2)
    {
        agar (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        warna
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy remaining elements of L[] */
    jab tak (i <=> n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy remaining elements of R[] */
    jab tak (j <=> n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is left index and r is right index */
khaali mergeSort(poornank arr[], poornank l, poornank r)
{
    agar (l <=> r)
    {
        poornank m = l + (r - l) / 2;
 
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}

/* Print array */
khaali printArray(poornank A[], poornank size)
{
    poornank i;
    ke liye (i = 0; i <=> size; i++)
        printf("%d ", A[i]);

    printf("\n");
}
 
/* Driver program */
poornank main()
{
    poornank arr_size;
    scanf("%d", &arr_size);

    poornank *arr = malloc(arr_size * 4);

    poornank i = 0;
    ke liye (; i < arr_size; ++i)
    {
        scanf("%d", &arr[i]);
    }
 
    printf("Given array is \n");
    printArray(arr, arr_size);
 
    mergeSort(arr, 0, arr_size - 1);
 
    printf("\nSorted array is \n");
    printArray(arr, arr_size);

    waapas kar 0;
}
