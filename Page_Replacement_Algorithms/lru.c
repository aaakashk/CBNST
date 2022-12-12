#include <stdio.h>

int isPagePresent(char *, char, int);
void printCurrentPages(char *, int);

int main() {
    int pageFaults = 0, hits = 0, frameCapacity, size;
    printf("Enter the size of referenced string: ");
    scanf("%d", &size);
    char referenceString[size];
    printf("Enter the reference string: ");
    scanf("%s", referenceString);
    printf("Enter the frame capacity: ");
    scanf("%d", &frameCapacity);
    char frame[frameCapacity];
    for (int i = 0; i < frameCapacity; ++i) frame[i] = '-';

    for (int i = 0; i < size; ++i) {
        if (isPagePresent(frame, referenceString[i], frameCapacity))
            ++hits;
        else if (i < frameCapacity) {
            ++pageFaults;
            frame[i] = referenceString[i];
        } else {
            ++pageFaults;
            frame[(i - frameCapacity) % frameCapacity] = referenceString[i];
        }
        printCurrentPages(frame, frameCapacity);
    }

    printf("Page Faults = %d\nPage Hits = %d\n", pageFaults, hits);
    return 0;
}

int isPagePresent(char *frame, char page, int frameCapacity) {
    for (int i = 0; i < frameCapacity; ++i)
        if (frame[i] == page) return 1;
    return 0;
}

void printCurrentPages(char *frame, int frameCapacity) {
    printf("Pages in Frame:\t");
    for (int i = 0; i < frameCapacity; ++i)
        printf("%c\t", frame[i]);
    printf("\n");
}