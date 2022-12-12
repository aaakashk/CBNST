#include <stdio.h>

int main() {
    int frames[10], pages[50], n, fs, time[10], pageFault = 0;
    printf("Enter Number of Pages ");
    scanf("%d", &n);
    printf("Enter Number of Frames ");
    scanf("%d", &fs);
    printf("Enter Ref Str : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }
    for (int i = 0; i < fs; i++) {
        frames[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        int empty = 0, found = 0, index;
        for (int j = 0; j < fs; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                time[j] = i;
                break;
            }
            if (frames[j] == -1) {
                empty = 1;
                index = j;
            }
        }
        if (found == 0) {
            if (empty == 0) {
                int t = -1;
                for (int j = 0; j < fs; j++) {
                    if (t < time[j]) {
                        index = j;
                        t = time[j];
                    }
                }
            }
            pageFault++;
            frames[index] = pages[i];
            time[index] = i;
        }

        printf("%d \t", pages[i]);
        for (int j = 0; j < fs; j++)
            printf("%d \t", frames[j]);
        printf("\n");
    }
    printf("Pagefault : %d\n", pageFault);
    return 0;
}