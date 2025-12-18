#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

// 1. 匹配并消耗掉输入流中所有的空白字符
int match_space(FILE *f)
{
    int c;
    while ((c = fgetc(f)) != EOF && isspace(c))
        ; // 继续读取
    if (c != EOF)
        ungetc(c, f); // 把非空白字符放回流中
    return (0);
}

// 2. 匹配格式字符串中的普通字符
int match_char(FILE *f, char c)
{
    int ch = fgetc(f);
    if (ch == EOF)
        return (-1);
    if (ch == (unsigned char)c)
        return (1);
    ungetc(ch, f); // 不匹配则放回
    return (0);
}

// 3. 处理 %c：读取一个字符，不跳过开头的空白
int scan_char(FILE *f, va_list ap)
{
    char *p = va_arg(ap, char *);
    int c = fgetc(f);
    if (c == EOF)
        return (-1);
    *p = (char)c;
    return (1);
}

// 4. 处理 %d：读取带符号整数，跳过开头空白（由 match_conv 调用 match_space 处理）
int scan_int(FILE *f, va_list ap)
{
    int *p = va_arg(ap, int *);
    int c = fgetc(f);
    int sign = 1;
    int res = 0;
    int found = 0;

    if (c == EOF) return (-1);

    if (c == '-' || c == '+') {
        if (c == '-') sign = -1;
        c = fgetc(f);
        if (c == EOF || !isdigit(c)) { // 只有符号没有数字，匹配失败
            if (c != EOF) ungetc(c, f);
            return (0);
        }
    }

    if (!isdigit(c)) {
        ungetc(c, f);
        return (0);
    }

    while (c != EOF && isdigit(c)) {
        res = res * 10 + (c - '0');
        c = fgetc(f);
        found = 1;
    }
    
    if (c != EOF) ungetc(c, f);
    *p = res * sign;
    return (found);
}

// 5. 处理 %s：读取字符串，直到遇到空白，跳过开头空白
int scan_string(FILE *f, va_list ap)
{
    char *p = va_arg(ap, char *);
    int c = fgetc(f);
    int found = 0;

    if (c == EOF) return (-1);

    while (c != EOF && !isspace(c)) {
        *p++ = (char)c;
        found = 1;
        c = fgetc(f);
    }
    
    if (c != EOF) ungetc(c, f);
    *p = '\0'; // 必须以 NULL 结尾
    return (found);
}

int     match_conv(FILE *f, const char **format, va_list ap)
{
        switch (**format)
        {
                case 'c':
                        return scan_char(f, ap);
                case 'd':
                        match_space(f);
                        return scan_int(f, ap);
                case 's':
                        match_space(f);
                        return scan_string(f, ap);
                case EOF:
                        return -1;
                default:
                        return -1;
        }
}

int ft_vfscanf(FILE *f, const char *format, va_list ap)
{
        int nconv = 0;

        int c = fgetc(f);
        if (c == EOF)
                return EOF;
        ungetc(c, f);

        while (*format)
        {
                if (*format == '%')
                {
                        format++;
                        if (match_conv(f, &format, ap) != 1)
                                break;
                        else
                                nconv++;
                }
                else if (isspace(*format))
                {
                        if (match_space(f) == -1)
                                break;
                }
                else if (match_char(f, *format) != 1)
                        break;
                format++;
        }

        if (ferror(f))
                return EOF;
        return nconv;
}

int ft_scanf(const char *format, ...)
{
    va_list ap;
    va_start(ap, format);
    int ret = ft_vfscanf(stdin, format, ap);
    va_end(ap);
    return ret;
}
