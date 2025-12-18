#include <unistd.h>
#include <stdio.h> // allowed for puts

// 计算字符串长度
int ft_strlen(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return (i);
}

// 递归函数
// s: 原始字符串
// idx: 当前处理到的索引
// rem_l: 还需要移除多少个左括号
// rem_r: 还需要移除多少个右括号
// balance: 当前的括号平衡值 (左括号+1, 右括号-1)
// buffer: 用于构建最终输出的字符串
void solve(char *s, int idx, int rem_l, int rem_r, int balance, char *buffer)
{
    // --- 基本情况 (Base Case) ---
    // 如果遍历到了字符串末尾
    if (s[idx] == '\0')
    {
        // 如果所有该移除的都移除了，且最后平衡值为0，则是一个有效解
        if (rem_l == 0 && rem_r == 0 && balance == 0)
        {
            buffer[idx] = '\0'; // 加上字符串结束符
            puts(buffer);       // 打印结果
        }
        return;
    }

    char c = s[idx];

    // --- 选项 1: 保留当前字符 ---
    // 默认将字符写入 buffer
    buffer[idx] = c;
    
    if (c == '(')
    {
        // 如果保留左括号，balance + 1
        solve(s, idx + 1, rem_l, rem_r, balance + 1, buffer);
    }
    else if (c == ')')
    {
        // 如果保留右括号，只有在当前 balance > 0 时才合法（不能闭合不存在的左括号）
        if (balance > 0)
            solve(s, idx + 1, rem_l, rem_r, balance - 1, buffer);
    }
    else
    {
        // 如果不是括号（虽然题目说只有括号，但为了健壮性），直接保留
        solve(s, idx + 1, rem_l, rem_r, balance, buffer);
    }

    // --- 选项 2: 移除当前字符 (替换为空格) ---
    // 只有当我们需要移除对应类型的括号时才尝试这一步
    
    if ((c == '(' && rem_l > 0) || (c == ')' && rem_r > 0))
    {
        buffer[idx] = ' '; // 替换为空格
        
        if (c == '(')
            solve(s, idx + 1, rem_l - 1, rem_r, balance, buffer);
        else if (c == ')')
            solve(s, idx + 1, rem_l, rem_r - 1, balance, buffer);
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);

    char *str = argv[1];
    int i = 0;
    int rem_l = 0;
    int rem_r = 0;

    // --- 步骤 1: 预计算需要移除的数量 ---
    // 贪心算法计算最少需要移除多少个 '(' 和 ')'
    while (str[i])
    {
        if (str[i] == '(')
        {
            rem_l++;
        }
        else if (str[i] == ')')
        {
            if (rem_l > 0)
                rem_l--; // 匹配了一个之前的左括号
            else
                rem_r++; // 这是一个多余的右括号
        }
        i++;
    }

    // --- 步骤 2: 准备 buffer 并开始递归 ---
    // 我们需要在栈上或堆上分配一个 buffer 来存储当前的路径
    // C99 允许变长数组 (VLA)，但在严格的 C89/90 中不行。
    // 为了安全起见，我们定义一个足够大的 buffer 或者根据长度定义 VLA。
    // 这里假设字符串长度合理，使用 VLA。
    char buffer[ft_strlen(str) + 1];

    solve(str, 0, rem_l, rem_r, 0, buffer);

    return (0);
}