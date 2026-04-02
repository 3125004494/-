#include<stdio.h>

// 主函数：程序入口
int main()
{
    // 声明变量：n为用户输入的数值，t为当前杨辉三角中的数值，count为计数器
    int n, t = 0, count = 0;

    // 提示用户输入n的值
    printf("enter the value of n:");
    scanf("%d", &n);

    // 生成杨辉三角并查找第一个等于n的位置
    // 外层循环：遍历杨辉三角的行（从第0行开始）
    for (int i = 0; i < 1000000000; i++)
    {
        // 内层循环：遍历当前行的每个位置（从第0列到第i列）
        for (int j = 0; j <= i; j++)
        {
            // 计算杨辉三角中的数值
            if (j == 0 || j == i)
            {
                // 每行的第一个和最后一个元素都是1
                t = 1;
            }
            else
            {
                // 计算组合数 C(i, j)
                int a = 1, b = 1;
                // 计算分子：i! / (i-j)!
                for (int k = 1; k <= j; k++)
                {
                    a = a * (i - k + 1);
                    b = b * k;
                }
                // 计算组合数
                t = a / b;
            }

            // 计数器递增，表示当前是第count个位置
            count++;

            // 如果当前数值等于n，输出位置并退出
            if (t == n)
            {
                printf("%d\n", count);
                return 0;
            }
        }
    }

    // 如果没有找到，返回0
    return 0;
}