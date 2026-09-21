// main.c — local sandbox, do NOT submit

#include <stdio.h>

// prototypes from code.c
void   clear_string(char s[], int n);
int    my_isdigit(char c);
int    my_islower(char c);
int    my_isupper(char c);
int    my_isalpha(char c);
int    my_isalnum(char c);
int    my_strcmp(char a[], char b[]);
int    my_strchr(char s[], char c);
int    my_pow(int a, int b);
double my_pow_double(double a, int b);
char * format_my_isupper(char dest[], char c, int r);
char * format_my_isalpha(char dest[], char c, int r);
char * format_my_isalnum(char dest[], char c, int r);
char * format_my_strcmp(char dest[], int r);
char * format_my_strchr(char dest[], int r);
char * format_my_pow(char dest[], int r);
char * format_my_pow_double(char dest[], double r);

int main(void)
{
    char buf[64]; 
       
// printf("%d\n", my_isupper('A'));
// printf("%d\n", my_isalpha('1'));
// printf("%d\n", my_isalnum('a'));
// printf("%d\n", my_strcmp("abd", "abc"));
// printf("%d\n", my_strchr("hello", 'b'));
// printf("%d\n", my_pow(2, 2));
// printf("%f\n",my_pow_double(3.0, 0));


   char *result = format_my_isupper(buf, 'A', 1);

    printf("Result: [%s]\n", result);
    printf("Length: %zu\n", strlen(result));

    for (int i = 0; result[i] != '\0'; i++)
    {
        printf("result[%d] = %d ('%c')\n",
               i, (unsigned char)result[i], result[i]);
        }
    // test your functions here:
    // my_isdigit('5');
    // printf("%d\n", my_pow(2, 8));
    // printf("%s\n", format_my_pow(buf, my_pow(2, 8)));

    return 0;
}