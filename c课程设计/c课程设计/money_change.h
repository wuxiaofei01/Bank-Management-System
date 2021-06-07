#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#include "fundment.h"
#include "interest.h"
void saving(struct Account** user_id, int year, int month, int day) {//存款操作
    printf("\t\t\t\t***请输入您存款的金额或输入0返回上一界面***\n");
    char money_in[100];
    scanf("%s", &money_in);//用户输入
    int money_ture;
    money_ture = right(money_in);//判断是否为合法输入
    if (money_ture == 0) {
        printf("\t\t\t\t\t***将返回上一界面***\n");//存款操作完成
        system("pause");
        return;
    }
    if (money_ture != -1) {
        (*user_id)->amount += money_ture;
        printf("\t\t\t\t\t***存款完成将返回上一界面***\n");//存款操作完成
        system("pause");
        FILE* fp = fopen("trade.txt", "r+");
        fseek(fp, 0L, SEEK_END);
        fprintf(fp, "\n%s %d %d %d 存款%d元", (*user_id)->id, year, month, day, money_ture);//进行交易记录的储存
        fclose(fp);
    }
    else {//非法输入情况
        printf("\t\t\t\t\t***凸(艹皿艹 )，居然乱输***\n");
        system("pause");
    }
}
void withdrawal(struct Account** user_id, int year, int month, int day) {//取款函数
    printf("\t\t\t\t\t***请输入您取出的金额或输入0返回上一界面***\n");
    char money_in[100];
    scanf("%s", &money_in);//得到用户输入
    int money_ture;
    money_ture = right(money_in);//判断合法输入
    if (money_ture == 0) {
        printf("\t\t\t\t\t***将返回上一界面***\n");//存款操作完成
        system("pause");
        return;
    }
    if (money_ture != -1) {
        if (money_ture > (*user_id)->amount) {
            printf("\t\t\t\t\t***取款失败，余额不足将返回上一界面***\n");
            system("pause");
        }
        else {
            (*user_id)->amount -= money_ture;//取款操作
            printf("\t\t\t\t\t***取款完成将返回上一界面***\n");
            FILE* fp = fopen("trade.txt", "r+");
            fseek(fp, 0L, SEEK_END);
            fprintf(fp, "\n%s %d %d %d 取款%d元", (*user_id)->id, year, month, day, money_ture);//进行交易记录的储存
            fclose(fp);
            system("pause");
        }
    }
    else {//非法输入的情况
        printf("\t\t\t\t\t***凸(艹皿艹 )，居然乱输***\n");
        system("pause");
    }
}
void withdrawal_2(struct Account** user_id, int year, int month, int day, double* ava) {//取款函数
    printf("\t\t\t\t\t***请输入您取出的金额或输入0返回上一界面***\n");
    char money_in[100];
    scanf("%s", &money_in);//得到用户输入
    int money_ture;
    money_ture = right(money_in);//判断合法输入
    if (money_ture == 0) {
        printf("\t\t\t\t\t***将返回上一界面***\n");//存款操作完成
        system("pause");
        return;
    }
    if (money_ture != -1) {
        if (money_ture > (*user_id)->amount + (*ava / 2)) {
            printf("\t\t\t\t***取款失败，余额不足将返回上一界面***\n");
            system("pause");
        }
        else {
            if (money_ture <= (*user_id)->amount) {
                (*user_id)->amount -= money_ture;//取款操作
                printf("\t\t\t\t\t***取款完成将返回上一界面***\n");
                FILE* fp = fopen("trade.txt", "r+");
                fseek(fp, 0L, SEEK_END);
                fprintf(fp, "\n%s %d %d %d 取款%d元", (*user_id)->id, year, month, day, money_ture);//进行交易记录的储存
                fclose(fp);
                system("pause");
                system("cls");
            }
            else {
                printf("\t\t\t\t\t***取款完成将返回上一界面***\n");
                FILE* fp = fopen("trade.txt", "r+");
                fseek(fp, 0L, SEEK_END);
                fprintf(fp, "\n%s %d %d %d 取款%d元", (*user_id)->id, year, month, day, money_ture);//进行交易记录的储存
                fclose(fp);
                money_ture -= (*user_id)->amount;
                (*user_id)->amount = 0;
                *ava -= money_ture;
                system("pause");
                system("cls");
            }
        }
    }
    else {//非法输入的情况
        printf("\t\t\t\t\t***凸(艹皿艹 )，居然乱输***\n");
        system("pause");
    }
}