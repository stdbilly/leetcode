#include <stdio.h>

int mySqrt(int num) {
    int l = 1;
    int r = num;
    int mid = 0;
    while (l <= r) {
        mid = l + ((r - l) >> 1);

        if (mid > num / mid) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return l - 1;
}

int main() {
    int num = 0;
    scanf("%d", &num);
    printf("\rsqrt(%d) = %d\n", num, mySqrt(num));
    return 0;
}