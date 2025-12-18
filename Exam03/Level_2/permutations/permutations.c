#include <stdio.h>  // 用于 puts
#include <stdlib.h> // 用于 malloc, calloc, free
#include <unistd.h> // 用于 write

/*
 * 计算字符串长度的辅助函数
 * 因为题目限制只允许特定函数，strlen 不在列表中，需手动实现。
 */
int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

/*
 * 冒泡排序 (Bubble Sort)
 * 在生成全排列之前，必须先将字符串排序，
 * 这样随后的深度优先搜索（DFS）自然会按字母顺序生成结果。
 */
void ft_sort_string(char *str, int len)
{
    int i = 0;
    int j;
    char temp;

    while (i < len - 1)
    {
        j = 0;
        while (j < len - 1 - i)
        {
            if (str[j] > str[j + 1])
            {
                temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}

/*
 * 递归回溯函数
 * src:    排序后的源字符串
 * res:    当前构建的排列字符串 buffer
 * used:   标记数组，记录 src 中哪些下标的字符已被使用
 * depth:  当前递归深度（即当前正在填 res 的第几位）
 * len:    字符串总长度
 */
void recursive_solve(char *src, char *res, int *used, int depth, int len)
{
    int i = 0;

    // 基本情况：如果深度等于长度，说明 buffer 已填满，打印结果
    if (depth == len)
    {
        puts(res);
        return;
    }

    // 遍历源字符串的每一个字符
    while (i < len)
    {
        // 如果这个字符在当前路径没被用过
        if (used[i] == 0)
        {
            used[i] = 1;        // 标记为已使用
            res[depth] = src[i]; // 将该字符填入结果 buffer
            
            // 递归填写下一位
            recursive_solve(src, res, used, depth + 1, len);
            
            // 回溯 (Backtrack)：递归返回后，将标记清除，
            // 以便让该字符在循环的后续步骤或其他分支中再次被使用
            used[i] = 0;
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    int len;
    int *used;
    char *res;

    // 如果参数数量不对，直接返回
    if (argc != 2)
        return (0);

    len = ft_strlen(argv[1]);
    
    // 步骤 1: 对输入字符串进行排序
    ft_sort_string(argv[1], len);

    // 步骤 2: 分配内存
    // used 数组用来标记字符是否已用 (int 数组)
    // calloc 会自动将内存初始化为 0
    used = calloc(len, sizeof(int));
    if (!used)
        return (1);

    // res 数组用来存放当前的排列结果 (+1 是为了存放末尾的 '\0')
    res = calloc(len + 1, sizeof(char));
    if (!res)
    {
        free(used);
        return (1);
    }

    // 步骤 3: 开始递归求解
    recursive_solve(argv[1], res, used, 0, len);

    // 步骤 4: 释放内存
    free(used);
    free(res);

    return (0);
}
