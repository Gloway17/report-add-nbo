#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

int main(int argc, char* argv[]) {
    uint32_t f1, f2, result;

    if (argc != 3) {
        printf("syntax : add-nbo <file1> <file2>\n");
        return -1;
    }

    FILE *file1 = fopen(argv[1], "rb");
    if (!file1) {
        printf("%s can not be open!\n", argv[1]);
        return -1;
    }
    fread(&f1, sizeof(f1), 1, file1);
    f1 = ntohl(f1);

    fclose(file1);

    FILE *file2 = fopen(argv[2], "rb");
    if (!file2) {
        printf("%s can not be open!\n", argv[2]);
        return -1;
    }
    fread(&f2, sizeof(f1), 1, file2);
    f2 = ntohl(f2);

    fclose(file2);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", f1, f1, f2, f2, f1+f2, f1+f2);

    return 0;
}