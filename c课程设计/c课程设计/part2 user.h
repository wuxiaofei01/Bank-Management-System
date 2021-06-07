#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#include "fundment.h"
#include "money_change.h"
int user_cird(struct Account** user_id, struct Account* head) {
    int user_return = 1;//此函数的返回值，1为退卡操作
    struct Date mydate;
    char id[21];//账户od
    double money, ava, limit;
    double* ava_use;
    char trashid[21];
    int year, month, day;
    int y, m, d;
    FILE* fpnew = fopen("date_annex.txt", "w");
    FILE* fp = fopen("limit.txt", "r+");
    FILE* fpdate = fopen("Date.txt", "r+");
    FILE* fpan = fopen("limit_annex.txt", "w");
    while (!feof(fpdate)) {
        fscanf(fpdate, "%s %d %d %d", trashid, &year, &month, &day);
        if (!strcmp(trashid, (*user_id)->id))
            break;
    }
    rewind(fpdate);
    while (!feof(fp)) {
        fscanf(fp, "%s %lf %lf", trashid, &ava, &limit);
        if (!strcmp(trashid, (*user_id)->id))
            break;
    }
    rewind(fp);
    printf("\t\t\t\t\t***请输入登录时间如2011 1 1***\n");
    in_date_user(&mydate, (*user_id)->id);
    if (mydate.year >= year + 1 || mydate.month >= month + 1) {
        if (ava < limit) {
            printf("\t\t\t\t***您未按时还款，信用卡已被冻结请联系管理员***\n");
            (*user_id)->state = 0;
            system("pause");
            system("cls");
            fclose(fpnew);
            fclose(fpdate);
            fclose(fp);
            fclose(fpan);
            remove("date_annex.txt");
            remove("limit_annex.txt");
            return 1;
        }
    }
    int key = 0;
    while (!feof(fpdate)) {
        fscanf(fpdate, "%s %d %d %d", trashid, &y, &m, &d);//进行文件的提取
        if (!strcmp(trashid, (*user_id)->id)) {
            fprintf(fpnew, "\n%s %d %d %d", trashid, mydate.year, mydate.month, mydate.day);//指定内容的更改
            key = 1;
        }
        else {
            fprintf(fpnew, "\n%s %d %d %d", trashid, y, m, d);//其余不变
        }
    }
    if (key == 0) {
        fprintf(fpnew, "\n%s %d %d %d", (*user_id)->id, mydate.year, mydate.month, mydate.day);//其余不变
    }
    fclose(fpnew);
    fclose(fpdate);
    remove("Date.txt");//将副本进行替换
    rename("date_annex.txt", "Date.txt");
    system("pause");
    system("cls");
    while (1) {
        printf("\t\t\t\t\t**************************\n");
        printf("\t\t\t\t\t***请选择您要进行的操作***\n");//展示操作项目
        printf("\t\t\t\t\t**********1.存款**********\n");
        printf("\t\t\t\t\t**********2.取款**********\n");
        printf("\t\t\t\t\t********3.查询余额********\n");
        printf("\t\t\t\t\t**********4.转账**********\n");
        printf("\t\t\t\t\t******5.查询交易记录******\n");
        printf("\t\t\t\t\t**********6.还款**********\n");
        printf("\t\t\t\t\t********7.修改密码********\n");
        printf("\t\t\t\t\t**********8.退卡**********\n");
        char user_in[10];
        scanf("%s", user_in);//得到用户需求
        if (!strcmp(user_in, "8")) {//退卡操作
            system("cls");//清屏
            while (!feof(fp)) {
                double y, m;
                fscanf(fp, "%s %lf %lf", trashid, &y, &m);//进行文件的提取
                if (!strcmp(trashid, (*user_id)->id)) {
                    fprintf(fpan, "\n%s %lf %lf", trashid, ava, limit);//指定内容的更改
                }
                else {
                    fprintf(fpan, "\n%s %lf %lf", trashid, y, m);//其余不变
                }
            }
            fclose(fp);
            fclose(fpan);
            remove("limit.txt");//将副本进行替换
            rename("limit_annex.txt", "limit.txt");
            return 1;//主函数得到返回值是1则重新循环
        }
        else if (!strcmp(user_in, "1")) {//存款操作
            saving(user_id, mydate.year, mydate.month, mydate.day);//存款函数
            system("cls");//清屏
            continue;
        }
        else if (!strcmp(user_in, "2")) {//取款操作
            ava_use = &ava;
            withdrawal_2(user_id, mydate.year, mydate.month, mydate.day, ava_use);//取款函数
            system("cls");
            continue;
        }
        else if (!strcmp(user_in, "3")) {//查询余额和剩余可用额度
            printf("\t\t\t\t\t***您卡内余额为: %.2lf\n", (*user_id)->amount);//将用户的余额输出
            printf("\t\t\t\t\t***您卡内可用额度为: %.2lf\n", ava);
            printf("\t\t\t\t\t***查询结束，将返回上一界面***\n");
            system("pause");
            system("cls");
            continue;
        }
        else if (!strcmp(user_in, "4")) {//转账操作
            printf("\t\t\t\t\t***请输入您要转入的账户或0返回上一界面***\n");//操作介绍
            char transfer[21];
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
            printf("\t\t\t\t***请输入您要为,姓名为%s,账户为%s,的用户转账的金额（如账户错误可输入0）***\n", goal->name, goal->id);//让用户再次确定
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
            char trash_id[21], messege[100], userin[100];
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
        else if (!strcmp(user_in, "6")) {//还款
            while (1) {
                double own = limit - ava;
                if (own == 0) {
                    printf("\t\t\t\t\t***无需还款将返回上一界面***\n");
                    system("pause");
                    system("cls");
                    break;
                }
                printf("\t\t\t\t\t***请输入还款金额或0返回上一界面***\n");
                char moneytrash[100];
                double money_ture;
                scanf("%s", moneytrash);
                money_ture = right_dou(moneytrash);
                if (money_ture == 1) {
                    FILE* fp = fopen("trade.txt", "r+");
                    fseek(fp, 0L, SEEK_END);
                    money_ture = atof(moneytrash);
                    if (money_ture == 0)
                        break;
                    if (own < money_ture) {
                        printf("\t\t\t\t\t***无需还款这么多，只需要%.2lf，已为您自动扣款***\n", own);
                        fprintf(fp, "\n%s %d %d %d 还款%.2lf", (*user_id)->id, mydate.year, mydate.month, mydate.day, own);
                        own = 0;
                        ava = limit;
                    }
                    else {
                        fprintf(fp, "\n%s %d %d %d 还款%.2lf", (*user_id)->id, mydate.year, mydate.month, mydate.day, money_ture);
                        own -= money_ture;
                        ava += money_ture;
                    }
                    fclose(fp);
                    printf("\t\t\t\t\t***还款成功将返回上一界面***\n");
                    system("pause");
                    system("cls");//清屏
                    break;
                }
                else {
                    printf("\t\t\t\t\t***凸(艹皿艹 )，居然乱输***\n");
                    system("pause");
                    system("cls");
                }
            }
        }
        else if (!strcmp(user_in, "7")) {
            printf("\t\t\t\t\t***请输入您的新密码或0返回上一界面***\n");
            char user_key[100];
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
                    printf("\t\t\t\t\t ***密码长度(6位)错误请重新输入或0返回上一界面***\n");
                    continue;
                }
                if (key == 1) {
                    printf("\t\t\t\t\t ***密码格式错误请重新输入或0返回上一界面***\n");
                    continue;
                }
                if (key == 0) {
                    while (1) {
                        printf("\t\t\t\t\t***请再次输入新密码或0返回上一界面***\n");
                        char trash[200];
                        scanf("%s", trash);
                        if (!strcmp(trash, "0")) {
                            key = 2;
                            break;
                        }
                        if (strcmp(trash, user_key)) {
                            printf("\t\t\t\t\t***两次密码不一致***\n");
                        }
                        else {
                            char newpass[70];
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
