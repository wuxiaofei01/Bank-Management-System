// c课程设计.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <stdlib.h>
#include "fundment.h"
#include "patr1 user.h"
#include "part2 user.h"
#include "Admin.h"
#define _CRT_SECURE_NO_WARNINGS
int main() {
    system("color 70");
    FILE* fp = fopen("Account.txt", "r");
    char user_key[20];
    struct Account* head = Get_file(fp);
    struct Account* allhead = head;
    while (1) {
        printf("\t\t\t\t\t**************************\n");
        printf("\t\t\t\t\t***请选择你要进行的操作***\n");//打印界面
        printf("\t\t\t\t\t*********1.用户登录*******\n");
        printf("\t\t\t\t\t********2.管理员登录******\n");
        printf("\t\t\t\t\t**********3.退出**********\n");
        printf("\t\t\t\t\t**************************\n");
       // system("login.vbs");
        scanf("\t\t\t\t\t\t           %s", user_key);//得到用户的要求//得到用户想要进入的界面
        if (!strcmp(user_key, "1")) {//进入用户界面
            struct Account* user_id = NULL;
            int key;//得到User的返回值
            while (1) {
                key = User(head, &user_id);//必须输入正确的账户密码才能进行下一步
                head = allhead;
                if (key == 1)//正常进行下一步操作
                    break;
                if (key == 0)//出现异常，重新循环
                    continue;
                if (key == 2)//用户退出到上一界面
                    break;
            }
            if (key == 2)
                continue;
            if (user_id->kind == 1) {
                int part1;
                part1 = user_money(&user_id, head);//得到在用户账号所进行操作结束后的返回值，1为退卡后的操作（即重新回到用户界面）
                head = allhead;
                if (part1 == 1)
                    continue;
            }
            else {
                int part1;
                part1 = user_cird(&user_id, head);//得到在用户账号所进行操作结束后的返回值，1为退卡后的操作（即重新回到用户界面）
                head = allhead;
                if (part1 == 1)
                    continue;
            }
        }
        else if (!strcmp(user_key, "2")) {
            int key;
            while (1)
            {
                key = Admin();
                if (key == 1)//正常进行下一步操作
                    break;
                if (key == 0)//出现异常，重新循环
                    continue;
                if (key == 2)//用户退出到上一界面
                    break;
            }
            while (key == 1)///////////////////
            {
                int key2 = Admin_menu(head);//1办理业务 2查询用户 3退出
                if (key2 == 0)
                    return 0;
                if (key2 == 1)
                {
                    system("cls");
                    key = Admin_business(fp, head);
                    system("cls");
                    printf("\n\n\n\n\n");
                }
                else if (key2 == 2)
                {
                    system("cls");
                    print_number(head);
                    system("cls");
                    key = Admin_check(fp, head);
                    system("cls");
                    printf("\n\n\n\n\n");
                }
                else if (key2 == 3)
                {
                    system("cls");
                    key = change_admin_pin();
                    system("cls");
                    printf("\n\n\n\n\n");
                }
                else if (key2 == 4)
                {
                    system("cls");
                    printf("\n\n\n\n\n");
                    printf("\t\t\t\t\t***************************\n");
                    printf("\t\t\t\t\t***     文件备份成功    ***\n");
                    printf("\t\t\t\t\t***************************\n");
                    backup();
                    system("pause");
                    system("cls");
                }
                else if (key2 == 5)
                {
                    fclose(fp);
                    system("cls");
                    printf("\n\n\n\n\n");
                    printf("\t\t\t\t\t***************************\n");
                    printf("\t\t\t\t\t***     文件复原成功    ***\n");
                    printf("\t\t\t\t\t***************************\n");
                    update();
                }
                else if (key2 == 6)
                {
                    system("cls");
                    break;
                }
            }
        }
        else if (!strcmp(user_key, "3")) {
            printout(head);
            exit(0);
        }
        else {
            printf("\t\t\t\t\t***凸(艹皿艹 )，居然乱输***\n");
            system("pause");
            system("cls");
        }
    }
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
