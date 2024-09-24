#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char *my_strtok(char *str, const char *delim) {
    static char *next_token = NULL;
    char *token_start;
    bool found_delim = false;

    if (str != NULL) {
        next_token = str;
    } else if (next_token == NULL) {
        return NULL; // No more tokens
    }

    // Skip leading delimiters
    while (*next_token != '\0' && strchr(delim, *next_token) != NULL)    
    {
        next_token++;
    }

    if (*next_token == '\0') {
        return NULL; // No more tokens
    }

    token_start = next_token;

    // Find the end of the token
    while (*next_token != '\0' && strchr(delim, *next_token) == NULL) 
    {
        next_token++;
    }

    if (*next_token != '\0') {
        *next_token = '\0'; // Null-terminate the token
        next_token++; // Move to the next character after the 
					// delimiter
    }

    return token_start;
}

int main() {
    char str[] = "Hello, World! This is a sample string.";
    const char delim[] = " ,.!"; // Delimiters are space, comma, 
							// period, and exclamation mark
    char *token;

    // Get the first token
    token = my_strtok(str, delim);

    // Continue to get tokens until no more tokens are available
    while (token != NULL) {
        printf("Token: %s\n", token);

        // Get the next token
        token = my_strtok(NULL, delim);
    }

    return 0;
}
