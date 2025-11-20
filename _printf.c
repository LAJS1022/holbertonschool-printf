#include "main.h"

/**
 * _printf - custom printf function
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;
    char c;
    char *s;
    int n;
    unsigned int num;

    if (!format)
        return (-1);

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%' && format[i + 1] == '\0')
        {
            va_end(args);
            return (-1);
        }

        if (format[i] == '%')
        {
            i++;
            if (format[i] == 'c')
            {
                c = va_arg(args, int);
                write(1, &c, 1);
                count++;
            }
            else if (format[i] == 's')
            {
                s = va_arg(args, char *);
                if (!s)
                    s = "(null)";
                while (*s)
                {
                    write(1, s, 1);
                    s++;
                    count++;
                }
            }
            else if (format[i] == 'd' || format[i] == 'i')
            {
                n = va_arg(args, int);
                if (n < 0)
                {
                    write(1, "-", 1);
                    count++;
                    num = -n;
                }
                else
                {
                    num = n;
                }
                if (num / 10)
                {
                    char buffer[10];
                    int j = 0;

                    while (num)
                    {
                        buffer[j++] = (num % 10) + '0';
                        num /= 10;
                    }
                    while (j--)
                    {
                        write(1, &buffer[j], 1);
                        count++;
                    }
                }
                else
                {
                    c = num + '0';
                    write(1, &c, 1);
                    count++;
                }
            }
            else if (format[i] == '%')
            {
                write(1, "%", 1);
                count++;
            }
            else
            {
                write(1, "%", 1);
                write(1, &format[i], 1);
                count += 2;
            }
        }
        else
        {
            write(1, &format[i], 1);
            count++;
        }
        i++;
    }

    va_end(args);
    return (count);
}
