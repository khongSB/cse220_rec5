#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello, World! This is a sample string.";
    const char delim[] = " ,.!"; // Delimiters are space, comma, 
							// period, and exclamation mark
    char *token;

    // Get the first token
    token = strtok(str, delim);

    // Continue to get tokens until no more tokens are available
    while (token != NULL) {
        printf("Token: %s\n", token);

        // Get the next token
        token = strtok(NULL, delim);
    }

    return 0;
}
