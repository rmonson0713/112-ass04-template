//char *AUTHOR_NAME        = (char *) "Your Name";
//char *AUTHOR_AUTHORSHIP  = (char *) "I acknowledge that I have worked on this
// assignment independently, except where explicitly noted and referenced.
// Any collaboration or use of external resources has been properly cited.
// I am fully aware of the consequences of academic dishonesty and agree to
// abide by the university's academic integrity policy.";

// code.c — student implementation only

#include <stdio.h>

// ============================================================
// CSCI 232 – Lab: Standard Library Functions II
//
// RULES:
//   - Use ONLY: if, switch, goto, putchar(), getchar(), sprintf()
//   - Do NOT use: while, for, do-while
//   - Do NOT use any standard library functions
//   - my_isalnum() MUST use switch() and call
//     your own my_isalpha() and my_isdigit()
//   - my_isalpha() MUST call my_islower() and my_isupper()
//
// Iteration pattern:
//
//   int i = 0;
//   loop:
//       if (i >= n)
//           goto done;
//       // body
//       i++;
//       goto loop;
//   done:
//
// CONVENTION — format functions:
//
//   Every format function:
//     1. Accepts dest[] as first parameter
//     2. Calls clear_string(dest, 64) as its FIRST statement
//     3. Writes into dest using sprintf()
//     4. Returns dest
//
//   Same pattern as my_strcpy():
//     char * my_strcpy(char dest[], char src[])
// ============================================================


// ============================================================
// clear_string
//
// Sets the first n characters of s to '\0'.
// MUST use goto for iteration.
//
// Example:
//   char buf[64];
//   clear_string(buf, 64);  →  all 64 bytes are '\0'
// ============================================================

void clear_string(char s[], int n)
{
  char empty = '\0';
  int i = 0;
  loop:
      if (i < n)
      {
        s[i] = empty;
        i++;
        goto loop;
      }
}


// ============================================================
// my_isdigit
//
// Returns 1 if c is a digit character ('0' through '9').
// Returns 0 otherwise.
// ============================================================

int my_isdigit(char c)
{

    if (c >= 48 && c <= 57)
        return 1;
    else
        return 0;
}

// ============================================================
// my_islower
//
// Returns 1 if c is a lowercase letter ('a' through 'z').
// Returns 0 otherwise.
// ============================================================

int my_islower(char c)
{
    if (c >= 97 && c <= 122)
        return 1;
    else
        return 0;
}

// ============================================================
// my_isupper
//
// Returns 1 if c is an uppercase letter ('A' through 'Z').
// Returns 0 otherwise.
//
// Example:
//   my_isupper('A')  →  1
//   my_isupper('a')  →  0
//   my_isupper('1')  →  0
// ============================================================

int my_isupper(char c)
{
    if(c >= 65 && c <= 90)
        return 1;
    else
        return 0;
}


// ============================================================
// my_isalpha
//
// Returns 1 if c is a letter ('a'-'z' or 'A'-'Z').
// Returns 0 otherwise.
//
// MUST call my_islower() and my_isupper().
//
// Example:
//   my_isalpha('a')  →  1
//   my_isalpha('Z')  →  1
//   my_isalpha('1')  →  0
// ============================================================

int my_isalpha(char c)
{
    if (my_islower(c) || my_isupper(c))
        return 1;
    else
        return 0;
}


// ============================================================
// my_isalnum
//
// Returns 1 if c is a letter or a digit.
// Returns 0 otherwise.
//
// MUST use switch() and call my_isalpha() and my_isdigit().
//
// Example:
//   my_isalnum('a')  →  1
//   my_isalnum('5')  →  1
//   my_isalnum('!')  →  0
// ============================================================

int my_isalnum(char c)
{
    int is_alpha = my_isalpha(c);
    int is_digit = my_isdigit(c);

    int result = is_alpha + is_digit;

    switch(result)
    {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 1;
    }
}


// ============================================================
// my_strcmp
//
// Compares strings a and b character by character.
// Returns -1 if a < b
// Returns  0 if a == b
// Returns  1 if a > b
//
// Example:
//   my_strcmp("abc", "abd")  →  -1
//   my_strcmp("abc", "abc")  →   0
//   my_strcmp("abd", "abc")  →   1
// ============================================================

int my_strcmp(char a[], char b[])
{
    int i = 0;
loop:
    {
    if (a[i] == '\0' && b[i] == '\0')
        return 0;
    if (a[i] > b[i])
        return 1;
    if (a[i] < b[i])
        return -1;
    i++;
goto loop;
    }

}


// ============================================================
// my_strchr
//
// Searches string s for character c.
// Returns the index of the first occurrence.
// Returns -1 if not found.
//
// Example:
//   my_strchr("hello", 'l')  →  2
//   my_strchr("hello", 'z')  →  -1
// ============================================================

int my_strchr(char s[], char c)
{
    int i = 0;
loop:
    if(s[i] == '\0')
        return -1;    
    if(s[i] == c)
        return i;
    i++;
    goto loop;

}


// ============================================================
// my_pow
//
// Returns a raised to the power of b (integers only).
// Assume b >= 0.
//
// Example:
//   my_pow(2, 8)  →  256
//   my_pow(3, 0)  →    1
// ============================================================

int my_pow(int a, int b)
{
 int i = 1;

loop:
    if (b == 0)
        return i;
    i = i * a;
    b--;

    goto loop;
}


// ============================================================
// my_pow_double
//
// Returns a raised to the power of b.
// a is a double, b is a non-negative integer.
//
// Example:
//   my_pow_double(2.5, 3)  →  15.625
//   my_pow_double(3.0, 0)  →   1.0
// ============================================================

double my_pow_double(double a, int b)
{
double i = 1.0;

loop:
    if (b == 0)
        return i;

    i = i * a;
    b--;

    goto loop;
}


// ============================================================
// FORMAT FUNCTIONS
// ============================================================


// ============================================================
// format_my_isupper
//
// Returns dest containing:
//   "isupper('A') = true"
//   "isupper('a') = false"
//
// Uses: %c for the character, %s for "true" / "false"
// ============================================================

char * format_my_isupper(char dest[], char c, int r)
{
    clear_string(dest, 64);
    if (r == 1)
        sprintf(dest, "isupper('%c') = %s", c, "true");
    else
        sprintf(dest, "isupper('%c') = %s", c, "false");
    return dest;
}


// ============================================================
// format_my_isalpha
//
// Returns dest containing:
//   "isalpha('a') = true"
//   "isalpha('3') = false"
//
// Uses: %c, %s
// ============================================================

char * format_my_isalpha(char dest[], char c, int r)
{
    clear_string(dest, 64);
    if (r == 1)
        sprintf(dest, "isalpha('%c') = %s", c, "true");
    else
        sprintf(dest, "isalpha('%c') = %s", c, "false");
    return dest;
}


// ============================================================
// format_my_isalnum
//
// Returns dest containing:
//   "isalnum('a') = true"
//   "isalnum('!') = false"
//
// Uses: %c, %s
// ============================================================

char * format_my_isalnum(char dest[], char c, int r)
{
    clear_string(dest, 64);
    if (r == 1)
        sprintf(dest, "isalnum('%c') = %s", c, "true");
    else
        sprintf(dest, "isalnum('%c') = %s", c, "false");
    return dest;
}


// ============================================================
// format_my_strcmp
//
// Returns dest containing:
//   "comparison: less"
//   "comparison: equal"
//   "comparison: greater"
//
// MUST use switch() to select the word.
// Uses: %s
// ============================================================

char * format_my_strcmp(char dest[], int r)
{
    clear_string(dest, 64);
    char *word;
    switch (r)
    {
        case -1:
            word = "less";
            break;
        case 0:
            word = "equal";
            break;
        case 1:
            word = "greater";
            break;
    }

    sprintf(dest, "comparison: %s", word);
    return dest;
}


// ============================================================
// format_my_strchr
//
// Returns dest containing:
//   "found at: 3"    when r >= 0
//   "not found"      when r == -1
//
// Uses: %d for the index
// ============================================================

char * format_my_strchr(char dest[], int r)
{
    clear_string(dest, 64);
    if (r >= 0)
        sprintf(dest, "found at: %d", r);
    else
        sprintf(dest, "not found");
    return dest;
}


// ============================================================
// format_my_pow
//
// Returns dest containing the result left-justified
// in a field of width 12:
//   "pow = 256         "
//   "pow = -1024       "
//
// Uses: %-12d
// ============================================================

char * format_my_pow(char dest[], int r)
{
    clear_string(dest, 64);
    sprintf(dest, "pow = %-12d", r);
    return dest;
}


// ============================================================
// format_my_pow_double
//
// Returns the result as a fixed-width string of total
// width 12, zero-padded on the left.
//
// Precision adapts to keep total width constant:
//
//   |r| < 10      →  %012.9f  →  "02.500000000"
//   |r| < 100     →  %012.8f  →  "015.62500000"
//   |r| < 1000    →  %012.7f  →  "0100.0000000"
//   |r| < 10000   →  %012.6f  →  "01234.500000"
//   |r| >= 10000  →  %012.5f  →  "012345.00000"
//
// Uses: 0 flag, width, precision
// ============================================================

char * format_my_pow_double(char dest[], double r)
{
    clear_string(dest, 64);
    if (r < 10 && r > -10)
        sprintf(dest, "%012.9f", r);
    else if (r < 100 && r > -100)
        sprintf(dest, "%012.8f", r);
    else if (r < 1000 && r > -1000)
        sprintf(dest, "%012.7f", r);
    else if (r < 10000 && r > -10000)
        sprintf(dest, "%012.6f", r);
    else
        sprintf(dest, "%012.5f", r);
    return dest;
}


// Rex Monson
// CSCI 112 Fall 2026
// Programming Assignment #4
// I declare that I am the author of this work, take full responsibility for it, and have disclosed any material external assistance.