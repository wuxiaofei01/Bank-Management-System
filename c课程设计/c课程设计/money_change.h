#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#include "fundment.h"
#include "interest.h"
void saving(struct Account** user_id, int year, int month, int day) {//������
    printf("\t\t\t\t***�����������Ľ�������0������һ����***\n");
    char money_in[100];
    scanf("%s", &money_in);//�û�����
    int money_ture;
    money_ture = right(money_in);//�ж��Ƿ�Ϊ�Ϸ�����
    if (money_ture == 0) {
        printf("\t\t\t\t\t***��������һ����***\n");//���������
        system("pause");
        return;
    }
    if (money_ture != -1) {
        (*user_id)->amount += money_ture;
        printf("\t\t\t\t\t***�����ɽ�������һ����***\n");//���������
        system("pause");
        FILE* fp = fopen("trade.txt", "r+");
        fseek(fp, 0L, SEEK_END);
        fprintf(fp, "\n%s %d %d %d ���%dԪ", (*user_id)->id, year, month, day, money_ture);//���н��׼�¼�Ĵ���
        fclose(fp);
    }
    else {//�Ƿ��������
        printf("\t\t\t\t\t***͹(ܳ��ܳ )����Ȼ����***\n");
        system("pause");
    }
}
void withdrawal(struct Account** user_id, int year, int month, int day) {//ȡ���
    printf("\t\t\t\t\t***��������ȡ���Ľ�������0������һ����***\n");
    char money_in[100];
    scanf("%s", &money_in);//�õ��û�����
    int money_ture;
    money_ture = right(money_in);//�жϺϷ�����
    if (money_ture == 0) {
        printf("\t\t\t\t\t***��������һ����***\n");//���������
        system("pause");
        return;
    }
    if (money_ture != -1) {
        if (money_ture > (*user_id)->amount) {
            printf("\t\t\t\t\t***ȡ��ʧ�ܣ����㽫������һ����***\n");
            system("pause");
        }
        else {
            (*user_id)->amount -= money_ture;//ȡ�����
            printf("\t\t\t\t\t***ȡ����ɽ�������һ����***\n");
            FILE* fp = fopen("trade.txt", "r+");
            fseek(fp, 0L, SEEK_END);
            fprintf(fp, "\n%s %d %d %d ȡ��%dԪ", (*user_id)->id, year, month, day, money_ture);//���н��׼�¼�Ĵ���
            fclose(fp);
            system("pause");
        }
    }
    else {//�Ƿ���������
        printf("\t\t\t\t\t***͹(ܳ��ܳ )����Ȼ����***\n");
        system("pause");
    }
}
void withdrawal_2(struct Account** user_id, int year, int month, int day, double* ava) {//ȡ���
    printf("\t\t\t\t\t***��������ȡ���Ľ�������0������һ����***\n");
    char money_in[100];
    scanf("%s", &money_in);//�õ��û�����
    int money_ture;
    money_ture = right(money_in);//�жϺϷ�����
    if (money_ture == 0) {
        printf("\t\t\t\t\t***��������һ����***\n");//���������
        system("pause");
        return;
    }
    if (money_ture != -1) {
        if (money_ture > (*user_id)->amount + (*ava / 2)) {
            printf("\t\t\t\t***ȡ��ʧ�ܣ����㽫������һ����***\n");
            system("pause");
        }
        else {
            if (money_ture <= (*user_id)->amount) {
                (*user_id)->amount -= money_ture;//ȡ�����
                printf("\t\t\t\t\t***ȡ����ɽ�������һ����***\n");
                FILE* fp = fopen("trade.txt", "r+");
                fseek(fp, 0L, SEEK_END);
                fprintf(fp, "\n%s %d %d %d ȡ��%dԪ", (*user_id)->id, year, month, day, money_ture);//���н��׼�¼�Ĵ���
                fclose(fp);
                system("pause");
                system("cls");
            }
            else {
                printf("\t\t\t\t\t***ȡ����ɽ�������һ����***\n");
                FILE* fp = fopen("trade.txt", "r+");
                fseek(fp, 0L, SEEK_END);
                fprintf(fp, "\n%s %d %d %d ȡ��%dԪ", (*user_id)->id, year, month, day, money_ture);//���н��׼�¼�Ĵ���
                fclose(fp);
                money_ture -= (*user_id)->amount;
                (*user_id)->amount = 0;
                *ava -= money_ture;
                system("pause");
                system("cls");
            }
        }
    }
    else {//�Ƿ���������
        printf("\t\t\t\t\t***͹(ܳ��ܳ )����Ȼ����***\n");
        system("pause");
    }
}