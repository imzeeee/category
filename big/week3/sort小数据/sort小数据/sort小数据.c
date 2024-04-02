#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100
#define REPEAT 100000

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
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
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
    int* output = (int*)malloc(n + 1 * sizeof(int));
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    int*  count= (int*)malloc((max + 1) * sizeof(int));
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
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countSortForRadix(int arr[], int n, int exp) {
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
        countSortForRadix(arr, n, exp);
}

int main() {
    int arr[SIZE];
    // 生成随机数组
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++)
        arr[i] = rand() % 1000;
    clock_t start, end;
    double cpu_time_used;
    // 测试插入排序
    start = clock();
    for (int i = 0; i < REPEAT; i++) {
        insertionSort(arr, SIZE);
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("插入排序用时： %f seconds\n", cpu_time_used);

    // 重新生成随机数组
    for (int i = 0; i < SIZE; i++)
        arr[i] = rand() % 1000;

    // 测试归并排序
    start = clock();
    for (int i = 0; i < REPEAT; i++) {
        mergeSort(arr, 0, SIZE - 1);
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("归并排序用时： %f seconds\n", cpu_time_used);

    // 重新生成随机数组
    for (int i = 0; i < SIZE; i++)
        arr[i] = rand() % 1000;

    // 测试快速排序
    start = clock();
    for (int i = 0; i < REPEAT; i++) {
        quickSort(arr, 0, SIZE - 1);
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("快速排序用时： %f seconds\n", cpu_time_used);

    // 重新生成随机数组
    for (int i = 0; i < SIZE; i++)
        arr[i] = rand() % 1000;

    // 测试计数排序
    start = clock();
    for (int i = 0; i < REPEAT; i++) {
        countSort(arr, SIZE);
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("计数排序用时： %f seconds\n", cpu_time_used);

    // 重新生成随机数组
    for (int i = 0; i < SIZE; i++)
        arr[i] = rand() % 1000;

    // 测试基数计数排序
    start = clock();
    for (int i = 0; i < REPEAT; i++) {
        radixSort(arr, SIZE);
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("基数计数排序用时： %f seconds\n", cpu_time_used);

    return 0;
}