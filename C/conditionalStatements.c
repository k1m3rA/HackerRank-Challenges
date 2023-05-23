#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();



int main()
{
    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    if (n > 9) {printf("Greater than 9");}
    else if (n == 1) {printf("one");}
    else if (n == 2) {printf("two");}
    else if (n == 3) {printf("three");}
    else if (n == 4) {printf("four");}
    else if (n == 5) {printf("five");}
    else if (n == 6) {printf("six");}
    else if (n == 7) {printf("seven");}
    else if (n == 8) {printf("eight");}
    else if (n == 9) {printf("nine");}


    return 0;
}

char* readline() {
    
    /* Initializes the length of the memory allocated and the current length of the data read. */
    size_t alloc_length = 1024; 
    size_t data_length = 0;

    /* Dynamic memory is allocated using malloc() to store the line read. Alloc_length bytes of memory are reserved and the starting address is stored in the data pointer. */
    char* data = malloc(alloc_length);

    /* printf("%p\n", (void *) &data); /* This will print data pointer address: https://stackoverflow.com/questions/9053658/correct-format-specifier-to-print-pointer-or-address */

    /* Infinite loop */
    while (true) {

        /* The cursor pointer is set to the current position within the data string, where the next line read will be stored. */
        char* cursor = data + data_length;

        /* The fgets() function is used to read an input line from the console (stdin) and store it in cursor. fgets() reads at most alloc_length - data_length characters or until a line break ('\n') is found. The read line is stored in line. */
        char* line = fgets(cursor, alloc_length - data_length, stdin);
        
        /* If line is NULL, no more lines could be read. */
        if (!line) { break; }
        
        /* The length of the line read is added to data_length, which reflects the current length of the string read. */
        data_length += strlen(cursor);

        /* It checks whether the current allocated memory limit (alloc_length - 1) has been reached or whether the last character read was a line break ('\n'). If either of these conditions is met, the loop is broken. */
        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        /* The alloc_length is duplicated using the left shift operator (<<), which means multiplying it by 2. 1 << 1 == 1 * 2^1 == 2, 1 << 2 == 1 * 2^2 == 4, */
        size_t new_length = alloc_length << 2; /* bits concept https://www.geeksforgeeks.org/left-shift-right-shift-operators-c-cpp/ */

        /* realloc() is used to resize the memory block pointed to by data to new_length bytes. This increases the size of the memory allocated to store the line read. */
        data = realloc(data, new_length);

        /* If data is NULL, exit loop. */
        if (!data) { break; }

        /* update alloc_length */
        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        /*  establish the last char of the string as null ('\0') */
        data[data_length - 1] = '\0';
    }

    /* reasigns memory */
    data = realloc(data, data_length);

    return data;
}

/* readline() Function advantages:
1. Line length flexibility: The function can handle lines of any length, as it dynamically allocates and reallocates memory as needed. This avoids errors or input truncation if a predefined length is exceeded.

2. Memory saving: The function initially allocates a moderate amount of memory (1024 bytes in this case) to store the line read. If the line exceeds this size, a dynamic reallocation is performed to increase the allocated space. This allows to use only the memory needed to store the line, avoiding memory waste.

3. Adaptability: The function can handle inputs of different sizes without requiring a modification in the code. This makes it more versatile and reusable in different contexts where input lines need to be read interactively.

4. Error handling: The function checks for errors during line reading, such as reaching the end of the file or a memory allocation failure. In case of error, the function exits the loop and returns the data read so far. */
