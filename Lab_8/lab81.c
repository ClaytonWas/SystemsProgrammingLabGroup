#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// file to string function
void fileToString(char fileName[], char buffer[], int bufferSize) {
    FILE *file = fopen(fileName, "r");

    // read first line and discard it and then read the second line
    fgets(buffer, bufferSize, file);
    fgets(buffer, bufferSize, file);

    buffer[strcspn(buffer, "\n")] = '\0';

    printf("%s\n", buffer);

    fclose(file);
}


// count the word canada
int countString(const char *buffer) {
    int count = 0;
    const char *word = "Canada";
    int wordLength = strlen(word);
    const char *ptr = buffer;

    //hay stack needle function
    while ((ptr = strstr(ptr, word)) != NULL) {
        count++;
        ptr += wordLength;
    }
    
    return count;
}

int main() {
    // Update fileName with your file name and path
    char fileName[] = "File_National_Anthem_of_Canada.txt";
    char buffer[1024];

    printf("\nReading the Second line from the file...\n");
    printf("*******************************************\n");
    fileToString(fileName, buffer, 1024);
    printf("\nNumber of times Canada appeared in the Second line: %d\n\n", countString(buffer));

    return 0;
}
