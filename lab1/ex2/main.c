#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_LEN 100

typedef struct {
    int id;
    long int register_number;
    char surname[31];
    char name[31];
    int mark;
} Student;

void read_record(char *file, int n) {
    int fd = open(file, O_RDONLY);
    Student s;
    lseek(fd, (n-1)*sizeof(Student), SEEK_SET);
    read(fd, &s, sizeof(Student));
    printf("%d %ld %s %s %d\n", s.id, s.register_number, s.surname, s.name, s.mark);
    close(fd);
}

void write_record(char *file, int n) {
    int fd = open(file, O_RDWR);
    Student s;
    printf("Enter data: ");
    scanf("%d %ld %s %s %d", &s.id, &s.register_number, s.surname, s.name, &s.mark);
    lseek(fd, (n-1)*sizeof(Student), SEEK_SET);
    write(fd, &s, sizeof(Student));
    close(fd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s file\n", argv[0]);
        return 1;
    }

    char option;
    int n;
    while (1) {
        printf("> ");
        scanf(" %c", &option);
        if (option == 'E') {
            break;
        }
        scanf("%d", &n);
        if (option == 'R') {
            read_record(argv[1], n);
        } else if (option == 'W') {
            write_record(argv[1], n);
        }
    }

    return 0;
}