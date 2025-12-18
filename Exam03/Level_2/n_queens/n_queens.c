#include <stdlib.h>
#include <stdio.h>

/*
** 检查在 (col, row) 放置皇后是否安全
** board: 存储当前棋盘状态的数组
** current_col: 当前正在尝试放置的列
** row_to_check: 当前正在尝试放置的行
*/
int is_safe(int *board, int current_col, int row_to_check)
{
    int i;
    int previous_row;
    int row_diff;
    int col_diff;

    // 遍历之前所有的列 (0 到 current_col - 1)
    for (i = 0; i < current_col; i++)
    {
        previous_row = board[i];

        // 1. 检查同一行
        if (previous_row == row_to_check)
            return (0);

        // 2. 检查对角线
        // 对角线冲突意味着: |行差| == |列差|
        // 由于不允许使用 abs() 函数，我们需要手动计算绝对值或直接判断
        
        row_diff = previous_row - row_to_check;
        col_diff = i - current_col; // 因为 i 总是小于 current_col，这个结果是负数

        // 简单的绝对值逻辑
        if (row_diff < 0) row_diff = -row_diff;
        if (col_diff < 0) col_diff = -col_diff;

        if (row_diff == col_diff)
            return (0);
    }
    return (1);
}

/*
** 递归回溯函数
*/
void solve_n_queens(int n, int col, int *board)
{
    int row;
    int i;

    // 基准情况：如果 col 等于 n，说明所有列都成功放置了皇后，打印结果
    if (col == n)
    {
        for (i = 0; i < n; i++)
        {
            fprintf(stdout, "%d", board[i]);
            if (i < n - 1)
                fprintf(stdout, " ");
        }
        fprintf(stdout, "\n");
        return;
    }

    // 尝试当前列的每一行
    for (row = 0; row < n; row++)
    {
        // 如果放在该行是安全的
        if (is_safe(board, col, row))
        {
            board[col] = row;       // 放置皇后
            solve_n_queens(n, col + 1, board); // 递归去放下一列
            // 此处不需要显式的 "撤销" 操作，因为下一次循环会覆盖 board[col]
        }
    }
}

int main(int argc, char **argv)
{
    int n;
    int *board;

    // 检查参数数量
    if (argc != 2)
        return (1);

    // 将参数转换为整数
    n = atoi(argv[1]);

    // 处理 N < 1 的情况（虽然题目说不测试负数，但处理 0 是好习惯）
    if (n <= 0)
        return (0);

    // 分配内存来存储每一列皇后的行号
    board = (int *)calloc(n, sizeof(int));
    if (!board)
        return (0);

    // 开始递归求解
    solve_n_queens(n, 0, board);

    // 释放内存
    free(board);

    return (0);
}
