#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE1 10000
#define SIZE2 50000
#define SIZE3 200000

// 插入排序
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// 归并排序
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// 快速排序
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// 计数排序
void countSort(int arr[], int n) {
    int* output = (int*)malloc(n * sizeof(int));
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    int* count = (int*)malloc((max + 1) * sizeof(int));
    for (int i = 0; i <= max; ++i)
        count[i] = 0;
    for (int i = 0; i < n; i++)
        count[arr[i]]++;
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
    free(output);
    free(count);
}

// 基数计数排序
int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSortRadix(int arr[], int n, int exp) {
    int* output = (int*)malloc(n * sizeof(int));
    int i, count[10] = { 0 };

    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
    free(output);
}

void radixSort(int arr[], int n) {
    int m = getMax(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10)
        countSortRadix(arr, n, exp);
}

int main() {
    clock_t start, end;
    double cpu_time_used;
    int arr1[SIZE1], arr2[SIZE2], arr3[SIZE3];
    // 生成随机数组
    srand(time(NULL));
    for (int i = 0; i < SIZE1; i++)
        arr1[i] = rand() % 10000;
    for (int i = 0; i < SIZE2; i++)
        arr2[i] = rand() % 10000;
    for (int i = 0; i < SIZE3; i++)
        arr3[i] = rand() % 10000;
    // 测试插入排序
    start = clock();
    insertionSort(arr1, SIZE1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("插入排序(10000): %f seconds\n", cpu_time_used);
    start = clock();
    insertionSort(arr2, SIZE2);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("插入排序(50000): %f seconds\n", cpu_time_used);
    start = clock();
    insertionSort(arr3, SIZE3);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("插入排序(200000): %f seconds\n", cpu_time_used);
    // 测试归并排序
    start = clock();
    mergeSort(arr1, 0, SIZE1 - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("归并排序(10000): %f seconds\n", cpu_time_used);

    start = clock();
    mergeSort(arr2, 0, SIZE2 - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("归并排序(50000): %f seconds\n", cpu_time_used);

    start = clock();
    mergeSort(arr3, 0, SIZE3 - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("归并排序(200000): %f seconds\n", cpu_time_used);

    // 测试快速排序
    start = clock();
    quickSort(arr1, 0, SIZE1 - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("快速排序(10000): %f seconds\n", cpu_time_used);

    start = clock();
    quickSort(arr2, 0, SIZE2 - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("快速排序(50000): %f seconds\n", cpu_time_used);

    start = clock();
    quickSort(arr3, 0, SIZE3 - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("快速排序(200000): %f seconds\n", cpu_time_used);

    // 测试计数排序
    start = clock();
    countSort(arr1, SIZE1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("计数排序(10000): %f seconds\n", cpu_time_used);

    start = clock();
    countSort(arr2, SIZE2);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("计数排序(50000): %f seconds\n", cpu_time_used);

    start = clock();
    countSort(arr3, SIZE3);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("计数排序(200000): %f seconds\n", cpu_time_used);

    // 测试基数计数排序
    start = clock();
    radixSort(arr1, SIZE1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("基数计数排序(10000): %f seconds\n", cpu_time_used);

    start = clock();
    radixSort(arr2, SIZE2);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("基数计数排序(50000): %f seconds\n", cpu_time_used);

    start = clock();
    radixSort(arr3, SIZE3);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("基数计数排序(200000): %f seconds\n", cpu_time_used);

    return 0;
}
