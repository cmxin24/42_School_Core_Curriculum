#define _GNU_SOURCE
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define BUF_SIZE 4096

// 辅助函数：向 stderr 打印错误并返回 1
int error_exit(void)
{
    perror("Error");
    return (1);
}

int main(int argc, char **argv)
{
    // 参数检查：必须只有1个参数，且参数不为空
    if (argc != 2 || argv[1][0] == '\0')
        return (1);

    char    *needle = argv[1];
    size_t  needle_len = strlen(needle);
    
    // 预先生成用于替换的星号字符串
    char    *stars = malloc(needle_len);
    if (!stars)
        return (error_exit());
    memset(stars, '*', needle_len);

    char    *acc = NULL;
    size_t  acc_len = 0;
    char    read_buf[BUF_SIZE];
    ssize_t ret;

    // 循环读取标准输入
    while ((ret = read(STDIN_FILENO, read_buf, BUF_SIZE)) > 0)
    {
        // 1. 扩容累加器 (acc)
        char *temp = realloc(acc, acc_len + ret + 1);
        if (!temp)
        {
            free(acc);
            free(stars);
            return (error_exit());
        }
        acc = temp;

        // 2. 将新读取的数据拼接到 acc 末尾
        memcpy(acc + acc_len, read_buf, ret);
        acc_len += ret;
        acc[acc_len] = '\0'; // 确保 memmem 安全（虽然 memmem 依赖长度参数）

        // 3. 处理所有完整的匹配项
        char *match;
        // 在当前 acc 中查找 needle
        while ((match = memmem(acc, acc_len, needle, needle_len)) != NULL)
        {
            // 计算匹配位置之前的长度
            size_t prefix_len = match - acc;

            // 输出匹配前的内容
            if (write(STDOUT_FILENO, acc, prefix_len) == -1)
            {
                free(acc);
                free(stars);
                return (error_exit());
            }

            // 输出星号
            if (write(STDOUT_FILENO, stars, needle_len) == -1)
            {
                free(acc);
                free(stars);
                return (error_exit());
            }

            // 计算处理后的剩余长度
            size_t remaining = acc_len - (prefix_len + needle_len);

            // 将剩余部分移动到 acc 的开头
            memmove(acc, match + needle_len, remaining);
            acc_len = remaining;
            acc[acc_len] = '\0';
        }

        // 4. 处理部分保留 (Partial Buffering)
        // 如果 acc 中剩余的内容比 (needle_len - 1) 还长，说明前面的部分绝对安全，可以打印。
        // 我们必须保留最后的 (needle_len - 1) 个字节，防止它们是下一个匹配项的开头。
        if (acc_len >= needle_len)
        {
            size_t safe_len = acc_len - (needle_len - 1);
            if (write(STDOUT_FILENO, acc, safe_len) == -1)
            {
                free(acc);
                free(stars);
                return (error_exit());
            }
            memmove(acc, acc + safe_len, acc_len - safe_len);
            acc_len -= safe_len;
        }
    }

    // 读取错误检查
    if (ret == -1)
    {
        free(acc);
        free(stars);
        return (error_exit());
    }

    // 5. EOF 到达，打印剩余的所有内容
    if (acc_len > 0)
    {
        if (write(STDOUT_FILENO, acc, acc_len) == -1)
        {
            free(acc);
            free(stars);
            return (error_exit());
        }
    }

    free(acc);
    free(stars);
    return (0);
}
