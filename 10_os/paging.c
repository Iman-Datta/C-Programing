
#include <stdio.h>

int main() {
    int total_memory, page_size;
    int frames, n;

    int pages[10];
    int page_table[10][20];

    int process, page, offset;
    int frame, physical_address;

    printf("Enter total physical memory size: ");
    scanf("%d", &total_memory);

    printf("Enter page size: ");
    scanf("%d", &page_size);

    if (total_memory <= 0 || page_size <= 0 ||
        total_memory % page_size != 0) {
        printf("Invalid memory or page size.\n");
        return 1;
    }

    frames = total_memory / page_size;

    printf("Total frames available: %d\n", frames);

    printf("Enter number of processes: ");
    scanf("%d", &n);

    if (n < 1 || n > 10) {
        printf("Invalid number of processes.\n");
        return 1;
    }

    // Input page tables
    for (int i = 0; i < n; i++) {

        printf("\nEnter number of pages for P%d: ", i + 1);
        scanf("%d", &pages[i]);

        if (pages[i] < 1 || pages[i] > 20) {
            printf("Invalid number of pages.\n");
            return 1;
        }

        printf("Enter frame numbers for P%d:\n", i + 1);

        for (int j = 0; j < pages[i]; j++) {
            scanf("%d", &page_table[i][j]);

            if (page_table[i][j] < 0 ||
                page_table[i][j] >= frames) {
                printf("Invalid frame number.\n");
                return 1;
            }
        }
    }

    // Logical address input
    printf("\nEnter process number: ");
    scanf("%d", &process);

    printf("Enter logical page number: ");
    scanf("%d", &page);

    printf("Enter offset: ");
    scanf("%d", &offset);

    if (process < 1 || process > n) {
        printf("Invalid process number.\n");
        return 1;
    }

    if (page < 0 || page >= pages[process - 1]) {
        printf("Invalid page number.\n");
        return 1;
    }

    if (offset < 0 || offset >= page_size) {
        printf("Invalid offset.\n");
        return 1;
    }

    frame = page_table[process - 1][page];

    physical_address = (frame * page_size) + offset;

    printf("\nFrame Number: %d\n", frame);
    printf("Physical Address: %d\n", physical_address);

    return 0;
}
