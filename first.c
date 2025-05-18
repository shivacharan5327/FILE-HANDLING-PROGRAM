#include <stdlib.h>
#include<stdio.h>
#include<string.h>

void createFile(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error in  creating file.\n");
        return;
    }
    printf("File '%s' has been created successfully.\n", filename);
    fclose(fp);
}// create file uses 'w' mode to create a new file or clear an existing file.


void appendtoFile(const char *filename) {
    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error in opening file for appending.\n");
        return;
    }

    char data[10000];
    printf("Enter the data to append to the file (end with a single line 'END'):\n");

    while (1) {
        fgets(data, sizeof(data), stdin);
        if (strncmp(data, "END", 3) == 0)
            break;
        fputs(data, fp);
    }

    fclose(fp);
    printf("Data has been successfully appended to '%s'file.\n", filename);
}//Append to file uses 'a' mode to add content to the end of the file.

void readFile(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error in opening file for reading.\n");
        return;
    }

    char ch;
    printf("Contents of '%s':\n", filename);
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }

    fclose(fp);
}//Read file uses 'r' mode to read the file and print the file character by character. 
void writetoFile(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    char data[10000];
    printf("Enter data to write to the file (end with a single line 'END'):\n");

    while (1) {
        fgets(data, sizeof(data), stdin);
        if (strncmp(data, "END", 3) == 0)
            break;
        fputs(data, fp);
    }

    fclose(fp);
    printf("Data has been successfully written to '%s' file.\n", filename);
}//write to file uses 'w' to write new content, overwriting new content.

int main() {
    int choice;
    char filename[100];

    printf("Enter the filename: ");
    scanf("%s", filename);
    getchar();  

    do {
        printf("\nMenu:\n");
        printf("1. Create File\n");
        printf("2. Write to File\n");
        printf("3. Read File\n");
        printf("4.Append to File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                createFile(filename);
                break;
            case 2:
                writetoFile(filename);
                break;
            case 3:
                readFile(filename);
                break;
            case 4:
                appendtoFile(filename);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 5);

    return 0;
}
