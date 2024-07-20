#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

uint32_t read_number_at_file_and_ntohl(char *filename) {
    uint32_t buffer;

    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("%s can not be open!\n", filename);
        return -1;
    }
    fread(&buffer, sizeof(buffer), 1, file);

    fclose(file);

    return ntohl(buffer);
}

int main(int argc, char* argv[]) {
    uint32_t f1, f2;

    if (argc != 3) {
        printf("syntax : add-nbo <file1> <file2>\n");
        return -1;
    }

    f1 = read_number_at_file_and_ntohl(argv[1]);

    f2 = read_number_at_file_and_ntohl(argv[2]);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", f1, f1, f2, f2, f1+f2, f1+f2);

    return 0;
}