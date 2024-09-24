#include <stdio.h>

int my_strncmp(const char *s1, const char *s2, size_t n) {
    while (n > 0 && *s1 && *s2) {
        if (*s1 != *s2) {
            return (*s1 - *s2);
        }
        s1++;
        s2++;
        n--;
    }
    if (n == 0) {
        return 0; // Strings are equal up to n characters
    } else {
        return (*s1 - *s2); // Strings differ before reaching n 
                            // characters
    }
}

int main() {
    const char *str1 = "Hello";
    const char *str2 = "Hell";
    size_t n = 4;
    
    int result = my_strncmp(str1, str2, n);
    if (result == 0) {
        printf("Strings are equal up to %zu characters\n", n);
    } else if (result < 0) {
        printf("'%s' is less than '%s' up to %zu characters\n", str1, 
               str2, n);
    } else {
        printf("'%s' is greater than '%s' up to %zu characters\n", 
			str1, str2, n);
    }
    
    return 0;
}
