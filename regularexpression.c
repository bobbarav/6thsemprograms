#include <stdlib.h> 
#include <string.h>
#include <regex.h>
#include <stdio.h>
 
int main () 
{
    char string1[] = "12.2323"; 
    char string2[] = "zip.non_matching_name"; 
    int rc1,rc; 
    regex_t * myregex = calloc(1, sizeof(regex_t));
    regex_t * myregex1 = calloc(1, sizeof(regex_t)); 
 
    if (NULL == myregex)

    {
        return 1;
    }
     
    // Compile the regular expression 
    rc = regcomp( myregex, "[0-9]?[0-9]?(.[0-9][0-9]?)?", REG_EXTENDED | REG_NOSUB ); 
    /* this should compile, but doesn't!
    rc = regcomp( myregex, "^.*\.zip$", REG_EXTENDED | REG_NOSUB ); 
        */
    rc1 = regcomp( myregex1, "^-?[0-9]*$", REG_EXTENDED | REG_NOSUB );
    printf("RC from regcomp() = &#37;d\n", rc); 
     
    // Compare the entered value to the regex 
    if (0 == regexec(myregex, string1, 0 , 0 , 0 ) ) 
    {
        printf("String %s matches.\n", string1 ) ; 
    }
    else
    { 
        printf("String %s does not match.\n", string1 ); 
    }
    if (0 == regexec(myregex1, string1, 0 , 0 , 0 ) ) 
    {
        printf("String %s matches.\n", string1 ) ; 
    }
    else
    { 
        printf("String %s does not match.\n", string1 ); 
    }
 
    free(myregex);
    return 0;
}
