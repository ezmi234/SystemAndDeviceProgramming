#include <stdio.h>

#define MAX_LEN 100

typedef struct {
    int id;
    long int register_number;
    char surname[31];
    char name[31];
    int mark;
} Student;

void write_binary_file(char *file_1, char *file_2) {
    FILE *f1, *f2;
    Student s;
    char line[MAX_LEN];

    f1 = fopen(file_1, "r");
    f2 = fopen(file_2, "wb");

    while(fgets(line, MAX_LEN, f1) != NULL) {
        sscanf(line,"%d %ld %s %s %d", &s.id, &s.register_number, s.surname, s.name, &s.mark);
        fwrite(&s, sizeof(Student), 1, f2);
    }

    fclose(f1);
    fclose(f2);
}

void read_binary_file(char *file_2, char *file_3) {
    FILE *f2, *f3;
    Student s;

    f2 = fopen(file_2, "rb");
    f3 = fopen(file_3, "w");

    while (fread(&s, sizeof(s), 1, f2) == 1){
        fprintf(f3, "%d %ld %s %s %d\n", s.id, s.register_number, s.surname, s.name, s.mark);
    }

    fclose(f2);
    fclose(f3);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s file_1 file_2 file_3\n", argv[0]);
    }
    write_binary_file(argv[1], argv[2]);
    read_binary_file(argv[2], argv[3]);
    return 0;
}
