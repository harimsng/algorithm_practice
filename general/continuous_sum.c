#include <stdio.h>

#define max_len (100000)

int main(void)
{
    int len;
    int nums[max_len] = {0,};
    int max = 0x80000000;
    
    scanf("%d", &len);
    for (int i = 0; i < len; ++i) {
        int num;
        
        scanf("%d", &num);
        nums[i] = num;
    }
    for (int i = 1; i < len; ++i) {
        int prev = nums[i - 1];

        nums[i] += prev > 0 ? prev : 0;
    }
    for (int i = 0; i < len; ++i) {
        printf("%d ", nums[i]);
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    printf("\n%d", max);
}
