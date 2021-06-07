#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fundment.h"
#include "money_change.h"
#include "interest.h"
#define _CRT_SECURE_NO_WARNINGS

int User(struct Account* head, struct Account** user_id) {
    struct Account* goal = NULL;//锁定用户输入账户的位置
    char userid[100];//存放用户输入的账号
    int nstate = 0;//计算密码输入错误的次数
    int key = 1;//储存当前user函数的状态，1为正常进行下一步，0为出现异常，重新回到下一个user,2为回到上一界面
    while (goal == NULL) {
        printf("\t\t\t\t\t***请输入您的卡号或输入1回到上一界面***\n");
        scanf("%s", userid);//得到输入的卡号或1
        if (!strcmp(userid, "1")) {
            system("cls");
            key = 2;//用户输入1，则回到上一界面
            return key;
        }
        goal = Search_id(head, userid);//得到用户的账号位置，如果没有则重新输入
        if (goal == NULL)
            printf("\t\t\t\t\t***未找到相应账号，请确认后再次输入***\n");
        else break;//成功找到用户所输入的账户，离开循环
    }
    char user_password[70];
    if (goal->state) {//判断此卡是否可用
        printf("\t\t\t\t\t***请输入您的密码或0返回上一界面***\n");
        while (1) {
            if (goal->state == 1) {//判断此卡是否可用
                scanf("%s", user_password);//得到输入的密码
                if (!strcmp(user_password, "0")) {
                    system("cls");
                    return 0;
                }
                if (strcmp(goal->password, user_password)) {//如果密码输入错误将回到循环
                    printf("\t\t\t\t\t***密码错误，请重新输入或0返回上一界面***\n");
                    nstate++;
                    if (nstate == 3) {
                        goal->state = 0;
                    }
                }
                else {
                    key = 1;
                    *user_id = goal;
                    system("cls");
                    return key;
                }//输入正确，离开循环
            }
            if (goal->state == 0) {
                printf("\t\t\t\t\t***您的银行卡已被冻结，请联系管理人员***\n");//当银行卡被冻结
                system("pause");
                system("cls");
                return 0;//因为账户被冻结，所以回到user
            }
        }
    }
    if (goal->state == 0) {
        printf("\t\t\t\t\t***您的银行卡已被冻结，请联系管理人员***\n");//当银行卡被冻结
        system("pause");
        system("cls");
        return 0;//因为账户被冻结，所以回到user
    }
}
int user_money(struct Account** user_id, struct Account* head) {
    int user_return = 1;//此函数的返回值，1为退卡操作
    struct Date mydate, end, begin;//定期存款的时间
    char id[21];//账户od
    double money;
    printf("\t\t\t\t\t***请输入登录时间如2011 1 1***\n");
    in_date_user(&mydate, (*user_id)->id);
    system("pause");
    system("cls");
    cumclate(mydate.year, mydate.month, mydate.day, user_id);
    FILE* fp_re = fopen("regular.txt", "r");//打开定期存款的文件
    while (!feof(fp_re)) {
        fscanf(fp_re, "%s 存款%lf 时间%d %d %d 到%d %d %d", id, &money, &begin.year, &begin.month, &begin.day, &end.year, &end.month, &end.day);//将定期存款的内容提取出来
        if (!strcmp(id, (*user_id)->id)) {//判断是否为目标人物
            if (mydate.year > end.year) {//只要有一个存款到期，就可以前往柜台办理后续手续
                system("color 74");
                printf("\a\t\t\t\t\t***您有定期存款已到期***\n");
                system("pause");
                system("color 70");
                system("cls");
                break;
            }
            if (mydate.year == end.year && mydate.month > end.month) {//只要有一个存款到期，就可以前往柜台办理后续手续
                system("color 74");
                printf("\a\t\t\t\t\t***您有定期存款已到期***\n");
                system("pause");
                system("color 70");
                system("cls");
                break;
            }
            if (mydate.year == end.year && mydate.month == end.month && mydate.day >= end.day) {//只要有一个存款到期，就可以前往柜台办理后续手续
                system("color 74");
                printf("\a\t\t\t\t\t***您有定期存款已到期***\n");
                system("pause");
                system("color 70");
                system("cls");
                break;
            }

        }
    }
    fclose(fp_re);
    while (1) {
        printf("\t\t\t\t\t**************************\n");
        printf("\t\t\t\t\t***请选择您要进行的操作***\n");//展示操作项目
        printf("\t\t\t\t\t**********1.存款**********\n");
        printf("\t\t\t\t\t**********2.取款**********\n");
        printf("\t\t\t\t\t********3.查询余额********\n");
        printf("\t\t\t\t\t**********4.转账**********\n");
        printf("\t\t\t\t\t******5.查询交易记录******\n");
        printf("\t\t\t\t\t******6.活期转定期********\n");
        printf("\t\t\t\t\t********7.修改密码********\n");
        printf("\t\t\t\t\t**********8.退卡**********\n");
        char user_in[100];
        scanf("%s", user_in);//得到用户需求
        if (!strcmp(user_in, "8")) {//退卡操作
            system("cls");//清屏
            return 1;//主函数得到返回值是1则重新循环
        }
        else if (!strcmp(user_in, "1")) {//存款操作
            saving(user_id, mydate.year, mydate.month, mydate.day);//存款函数
            system("cls");//清屏
            continue;
        }
        else if (!strcmp(user_in, "2")) {//取款操作
            withdrawal(user_id, mydate.year, mydate.month, mydate.day);//取款函数
            system("cls");
            continue;
        }
        else if (!strcmp(user_in, "3")) {//查询余额
            printf("\t\t\t\t\t***您卡内余额为: %.2lf\n", (*user_id)->amount);//将用户的余额输出
            printf("\t\t\t\t***查询结束，将返回上一界面***\n");
            system("pause");
            system("cls");
        }
        else if (!strcmp(user_in, "4")) {//转账操作
            printf("\t\t\t\t\t***请输入您要转入的账户或0返回上一界面***\n");//操作介绍
            char transfer[210];
            int set = 0;
            struct Account* goal = NULL;
            while (goal == NULL) {
                scanf("%s", transfer);//用户输入的操作
                if (!strcmp(transfer, "0")) {//如果是0则退出该界面
                    set = 1;//记录推出操作
                    break;//因为推出所以直接离开循环
                }
                goal = Search_id(head, transfer);//找到对应账户
                if (goal == NULL)//未找到指定账户
                    printf("\t\t\t\t\t***未找到相应账户，请重新输入或0返回上一界面***\n");
            }
            if (set == 1) {//返回上一界面
                system("cls");
                continue;
            }
            char money_in[100];
            printf("\t***请输入您要为,姓名为%s,账户为%s,的用户转账的金额（如账户错误可输入0，如有多位小数则只取到两位）***\n", goal->name, goal->id);//让用户再次确定
            scanf("%s", &money_in);//得到用户的输入
            double money_ture;
            money_ture = (double)right_dou(money_in);//判断输入是否为合法输入
            if (money_ture != -1) {//合法输入情况
                money_ture = atof(money_in);
                if (money_ture <= (*user_id)->amount) {//判断转账余额是否充足
                    (*user_id)->amount -= money_ture;//进行转账操作
                    goal->amount += money_ture;
                    printf("\t\t\t\t\t***转账完成将返回上一界面***\n");
                    FILE* fp = fopen("trade.txt", "r+");//打开交易记录文件
                    fseek(fp, 0L, SEEK_END);
                    fprintf(fp, "\n%s %d %d %d 向账户为%s的账户转出%.2lf元", (*user_id)->id, mydate.year, mydate.month, mydate.day, transfer, money_ture);//进行交易记录的录入
                    fprintf(fp, "\n%s %d %d %d 从账户为%s的账户转出%.2lf元", transfer, mydate.year, mydate.month, mydate.day, (*user_id)->id, money_ture);
                    fclose(fp);
                    system("pause");
                    system("cls");
                    continue;
                }
                else {//余额不足的情况
                    printf("\t\t\t\t\t***余额不足转账失败将返回上一界面***\n");
                    system("pause");
                    system("cls");
                    continue;
                }
            }
            else {//非法输入情况
                printf("\t\t\t\t\t***凸(艹皿艹 )，居然乱输***\n");
                system("pause");
                system("cls");
            }
        }
        else if (!strcmp(user_in, "5")) {//查询自己的交易记录
            char trash_id[21], messege[100], userin[10];
            struct Date mydate;
            int year, key = 0;
            printf("\t\t\t\t\t***输入0查询全部交易记录，输入指定年份可查询当年记录***\n");
            scanf("%s", userin);//得到用户的输入
            year = right(userin);//判断合法输入
            if (year != -1 && year != 0) {//有指定年份
                FILE* fp = fopen("trade.txt", "r");//打开交易记录的文件
                while (!feof(fp)) {
                    fscanf(fp, "%s %d %d %d %s", trash_id, &mydate.year, &mydate.month, &mydate.day, messege);//提取信息
                    if (!strcmp(trash_id, (*user_id)->id) && mydate.year == year) {//判断账号和年份是否一致
                        printf("%d年%d月%d日 操作:%s\n", mydate.year, mydate.month, mydate.day, messege);//输出交易记录
                        key = 1;//有交易记录
                    }
                }
                if (key == 0) {//无交易记录
                    printf("\t\t\t\t\t***未找到输入年份的交易记录，将返回上一界面***\n");
                }
                fclose(fp);
                system("pause");
                system("cls");
            }
            else if (year != -1 && year == 0) {//合法输入并且查询所有交易记录
                FILE* fp = fopen("trade.txt", "r");
                while (!feof(fp)) {
                    fscanf(fp, "%s %d %d %d %s", trash_id, &mydate.year, &mydate.month, &mydate.day, messege);//提取信息
                    if (!strcmp(trash_id, (*user_id)->id)) {//判断账号是否一致
                        printf("%d年%d月%d日 操作:%s\n", mydate.year, mydate.month, mydate.day, messege);//输出交易信息
                        key = 1;
                    }
                }
                if (key == 0) {//无交易记录
                    printf("\t\t\t\t\t***无交易记录***\n");
                }
                fclose(fp);
                system("pause");
                system("cls");
            }
            else {//非法输入情况
                printf("\t\t\t\t\t***凸(艹皿艹 )，居然乱输***\n");
                system("pause");
                system("cls");
            }
        }
        else if (!strcmp(user_in, "6")) {//活期改定期操作
            printf("\t\t***请输入您要改为定期的金额（用户界面只支持一年定期，如需其他请前往柜台办理）或0返回上一界面***\n");
            char death_money[100], death_year[50];
            scanf("%s", death_money);//得到用户输入
            int dea_money, dea_year;
            dea_money = right(death_money);//判断非法输入与否
            if (dea_money != -1) {//合法输入
                if (dea_money == 0) {
                    system("cls");
                    continue;
                }
                if ((*user_id)->amount < dea_money) {//判断余额是否充足
                    printf("\t\t\t\t\t***余额不足***\t");
                    system("pause");
                    system("cls");
                    continue;
                }
                else {
                    (*user_id)->amount -= dea_money;//扣除金额
                    FILE* fpdeath = fopen("regular.txt", "r+");
                    fseek(fpdeath, 0L, SEEK_END);//将指针放在末尾
                    fprintf(fpdeath, "\n%s 存款%d 时间%d %d %d 到%d %d 1", (*user_id)->id, dea_money, mydate.year, mydate.month, mydate.day, (mydate.year) + 1, mydate.month + 1);//进行定期的存款
                    printf("\t\t\t\t\t存款成功将返回上一界面***\n");
                    fclose(fpdeath);
                    system("pause");
                    system("cls");
                }
            }
            else {
                printf("\t\t\t\t\t***凸(艹皿艹 )，居然乱输***\n");
                system("pause");
                system("cls");
            }
        }
        else if (!strcmp(user_in, "7")) {
            printf("\t\t\t\t\t***请输入您的新密码或0返回上一界面***\n");
            char user_key[10];
            int key = 0, i = 0;
            while (1) {
                key = 0;
                i = 0;
                scanf("%s", user_key);
                if (!strcmp(user_key, "0")) {
                    system("cls");
                    break;
                }
                while (user_key[i] != '\0') {
                    if (user_key[i] < '0' || user_key[i]>'9') {
                        key = 1;
                        break;
                    }
                    i++;
                }
                if (i < 6 || i>7) {
                    printf("\t\t\t\t\t ***密码长度（6位）错误请重新输入或0返回上一界面***\n");
                    continue;
                }
                if (key == 1) {
                    printf("\t\t\t\t\t ***密码格式错误请重新输入或0返回上一界面***\n");
                    continue;
                }
                if (key == 0) {
                    while (1) {
                        printf("\t\t\t\t\t***请再次输入新密码或0返回上一界面***\n");
                        char trash[10];
                        scanf("%s", trash);
                        if (!strcmp(trash, "0")) {
                            key = 2;
                            break;
                        }
                        if (strcmp(trash, user_key)) {
                            printf("\t\t\t\t\t***两次密码不一致***\n");
                        }
                        else {
                            char newpass[7];
                            i = 0;
                            while (user_key[i] != '\0') {
                                newpass[i] = user_key[i];
                                i++;
                            }
                            newpass[i] = '\0';
                            strcpy((*user_id)->password, newpass);
                            printf("\t\t\t\t\t***密码修改成功将返回上一界面***\n");
                            system("pause");
                            key = 2;
                            break;
                        }
                    }
                    if (key == 2) {
                        system("cls");
                        break;
                    }
                }
            }
        }
        else {//整体操作的非法输入
            printf("\t\t\t\t\t ***凸(艹皿艹 )，居然乱输***\n");
            system("pause");
            system("cls");
        }

    }

}