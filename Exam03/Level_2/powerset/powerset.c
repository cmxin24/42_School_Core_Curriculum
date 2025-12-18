#include <stdio.h>
#include <stdlib.h>

/**
 * 打印子集函数
 * @param buffer 当前子集的元素数组
 * @param len 当前子集的长度
 */
void print_subset(int *buffer, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d", buffer[i]);
        if (i < len - 1)
            printf(" ");
    }
    printf("\n");
}

/**
 * 递归回溯求解
 * @param n 目标总和
 * @param values 原始输入数组 (集合)
 * @param count 集合的大小 (总元素个数)
 * @param idx 当前遍历到的 values 数组索引
 * @param buffer 存储当前路径选中的元素
 * @param buf_len buffer 中当前的元素个数
 * @param current_sum buffer 中当前元素的和
 */
void solve(int n, int *values, int count, int idx, int *buffer, int buf_len, int current_sum)
{
    // 基准情况：如果已经遍历完所有元素
    if (idx == count)
    {
        // 只有当和等于目标值 n 时，才打印
        if (current_sum == n)
            print_subset(buffer, buf_len);
        return;
    }

    // 分支 1：选中当前元素 values[idx]
    // 放入 buffer，长度+1，总和增加，继续递归下一个元素 (idx+1)
    buffer[buf_len] = values[idx];
    solve(n, values, count, idx + 1, buffer, buf_len + 1, current_sum + values[idx]);

    // 分支 2：不选中当前元素 values[idx]
    // buffer 不变，长度不变，总和不变，继续递归下一个元素 (idx+1)
    solve(n, values, count, idx + 1, buffer, buf_len, current_sum);
}

int main(int argc, char **argv)
{
    // 修复点：严格检查参数数量
    // 题目要求：程序名 + n + 集合s。
    // 如果没有提供 n (argc < 2)，直接退出，返回 0。
    // 注意：即使集合 s 为空 (argc == 2)，程序也应继续运行（此时找和为 n 的空集）。
    if (argc < 2)
	{
		return (1);
	}

    // 1. 解析目标和 n
    int n = atoi(argv[1]);

    // 2. 准备集合数据
    int set_size = argc - 2;
    int *values = NULL;
    int *buffer = NULL;

    // 如果有集合元素，才分配内存
    if (set_size > 0)
    {
        values = malloc(sizeof(int) * set_size);
        if (!values)
            return (1); // Malloc error 必须返回 1

        for (int i = 0; i < set_size; i++)
            values[i] = atoi(argv[i + 2]);

        buffer = malloc(sizeof(int) * set_size);
        if (!buffer)
        {
            free(values);
            return (1); // Malloc error 必须返回 1
        }
    }
    
    // 3. 执行递归
    // 即使 set_size 为 0，如果 n 为 0，solve 也能正确处理（输出空行）
    // 为了安全，只有在分配了 buffer 或 set_size 为 0 时才调用
    // (set_size 为 0 时传 NULL 进去是安全的，因为 idx==count 会立即触发返回)
    solve(n, values, set_size, 0, buffer, 0, 0);

    // 4. 清理内存
    if (values) free(values);
    if (buffer) free(buffer);

    return (0);
}