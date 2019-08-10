#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int ia = m - 1;
    int ib = n - 1;
    int i = nums1Size - 1;
    for (; i >= 0; i--) {
        if (ia >= 0 && ib < 0) {
            break;
        }

        if (ia < 0 && ib >= 0) {
            nums1[i] = nums2[ib--];
            continue;
        }

        if (ia >= 0 && ib >= 0) {
            if (nums1[ia] > nums2[ib]) {
                nums1[i] = nums1[ia--];
            } else {
                nums1[i] = nums2[ib--];
            }
        }
    }
}

void printArray(int nums[], int n) {
    printf("{ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    printf("}\n");
}

int main() {
    int a[] = {1, 2, 3, 0, 0, 0};
    int b[] = {2, 5, 6};
    merge(a, 6, 3, b, 3, 3);
    printArray(a, sizeof(a) / sizeof(int));

    int a1[] = {2, 4, 6, 8, 10, 0, 0, 0};
    int b1[] = {1, 3, 5};
    merge(a1, 8, 5, b1, 3, 3);
    printArray(a1, sizeof(a1) / sizeof(int));

    int a2[] = {12, 14, 16, 18, 20, 0, 0, 0};
    int b2[] = {1, 3, 5};
    merge(a2, 8, 5, b2, 3, 3);
    printArray(a2, sizeof(a2) / sizeof(int));
    return 0;
}
