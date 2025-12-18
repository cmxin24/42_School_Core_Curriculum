#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <unistd.h>

// 定义结构体存储城市坐标
typedef struct {
    float x;
    float y;
} City;

// 全局变量，方便递归函数访问
City cities[11];        // 最多11个城市
int visited[11];        // 标记是否访问过
int n = 0;              // 实际城市数量
float min_distance = FLT_MAX; // 存储找到的最短路径，初始化为最大浮点数

// 计算两个城市之间的欧几里得距离
float calculate_dist(City a, City b) {
    return sqrtf(powf(a.x - b.x, 2) + powf(a.y - b.y, 2));
}

/**
 * 递归回溯函数
 * @param current_idx 当前所在的城市索引
 * @param count 已经访问过的城市数量
 * @param current_dist 当前累积的路径长度
 */
void solve_tsp(int current_idx, int count, float current_dist) {
    // 剪枝优化：如果当前距离已经超过了已知的最短距离，直接放弃该路径
    if (current_dist >= min_distance) {
        return;
    }

    // 基准情况：所有城市都访问过了
    if (count == n) {
        // 计算从最后一个城市回到起点(索引0)的距离
        float return_dist = calculate_dist(cities[current_idx], cities[0]);
        float total_dist = current_dist + return_dist;

        // 更新全局最小值
        if (total_dist < min_distance) {
            min_distance = total_dist;
        }
        return;
    }

    // 尝试访问下一个未访问的城市
    // 从索引1开始，因为索引0是固定的起点
    for (int i = 1; i < n; i++) {
        if (!visited[i]) {
            visited[i] = 1; // 标记为已访问
            
            // 递归进入下一层
            float dist_to_next = calculate_dist(cities[current_idx], cities[i]);
            solve_tsp(i, count + 1, current_dist + dist_to_next);
            
            visited[i] = 0; // 回溯：取消标记，以便其他路径可以访问
        }
    }
}

int main(void) {
    float x, y;
    
    // 1. 读取输入
    // 题目格式为 "float, float\n"
    // fscanf 返回成功读取的参数个数，如果不是2则说明结束或出错
    while (fscanf(stdin, "%f, %f", &x, &y) == 2) {
        if (n >= 11) break; // 防止溢出，虽然题目承诺不超过11
        cities[n].x = x;
        cities[n].y = y;
        n++;
    }

    // 边界检查：如果城市少于2个，距离为0
    if (n < 2) {
        printf("0.00\n");
        return 0;
    }

    // 2. 初始化回溯
    // 假设从第0个城市出发
    // 初始化 visited 数组
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    
    // 标记起点已访问
    visited[0] = 1;
    
    // 开始递归：当前在城市0，已访问1个，当前距离0.0
    solve_tsp(0, 1, 0.0f);

    // 3. 输出结果，保留两位小数
    printf("%.2f\n", min_distance);

    return 0;
}
