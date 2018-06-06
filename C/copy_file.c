/*
 JTSK-320111
 a6_p10.c
 Steven Abreu
 s.abreu@jacobs-university.de
 */

#include <stdio.h>
#include <string.h>

int main() {
    //this is like a9_p8
    FILE *fptr_orig, *fptr_copy;
    char line[200];
    int line_count = 0;

    fptr_orig = fopen("text.txt", "r");
    if (fptr_orig == NULL) {
        printf("could not open text.txt\n");
        return 1;
    }

    fptr_copy = fopen("text_copy.txt", "w");
    if (fptr_copy == NULL) {
        printf("could not open text_copy.txt\n");
        return 1;
    }

    //the statement is true as long as there is a line
    //->statement is false at the very end of the document, when there is no next line
    while (fgets(line, sizeof(line), fptr_orig)) {
        line_count++;
        //you dont really need to keep track of all the lines you're copying but
        //I put it here to illustrate to you what the program does
        //(I found it kind of boring if the command line doesn't say anything while
        //copying all those lines)
        printf("copying line #%d\n", line_count);

        fprintf(fptr_copy, "%s", line);
    }

    fclose(fptr_orig);
    fclose(fptr_copy);

    printf("success!\n");

    return 0;
}
