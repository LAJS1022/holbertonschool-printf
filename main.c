#include <stdio.h>
#include "main.h"

int main(void)
{
    int len, len2;
    char c = 'L';
    char *str = "Soy Luis";

    len = _printf("Hello World!\n");
    len2 = printf("Hello, World!\n");
    printf("Lengths: _printf=%d, printf=%d\n\n", len, len2);

_printf("Character:[%c]\n", c);
printf("Character:[%c]\n\n", c);

_printf("String:[%s]\n", str);
printf("String:[%s]\n\n", str);

_printf("Percent:[%%]\n");
printf("Percent:[%%]\n\n");

_printf("Mix: char=%c, str=%s, percent=%%\n", c, str);
printf("Mix: char=%c, str=%s, percent=%%\n", c, str);

return (0);
}
