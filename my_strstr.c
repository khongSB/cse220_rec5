#include <stdio.h>

char *my_strstr(const char *haystack, const char *needle) {
    if (*needle == '\0') return (char *)haystack; 
					// Empty needle is always found

    while (*haystack != '\0') {
        const char *h = haystack;
        const char *n = needle;
        
        while (*n != '\0' && *h == *n) {
            h++;
            n++;
        }
        
        if (*n == '\0') 
             return (char *)haystack; // Needle found
        haystack++;
    }
    
    return NULL; // Needle not found
}

int main() {
    char string1[] = "Hello world";
    char *substring = my_strstr(string1, "world");
    printf("substring addr: %p\n", substring);
    if (substring != NULL) {
        printf("substring: %s", substring);
    }
}