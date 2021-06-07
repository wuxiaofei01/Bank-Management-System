#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#include "fundment.h"
#include "money_change.h"
int user_cird(struct Account** user_id, struct Account* head) {
    int user_return = 1;//�˺����ķ���ֵ��1Ϊ�˿�����
    struct Date mydate;
    char id[21];//�˻�od
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
    printf("\t\t\t\t\t***�������¼ʱ����2011 1 1***\n");
    in_date_user(&mydate, (*user_id)->id);
    if (mydate.year >= year + 1 || mydate.month >= month + 1) {
        if (ava < limit) {
            printf("\t\t\t\t***��δ��ʱ������ÿ��ѱ���������ϵ����Ա***\n");
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
        fscanf(fpdate, "%s %d %d %d", trashid, &y, &m, &d);//�����ļ�����ȡ
        if (!strcmp(trashid, (*user_id)->id)) {
            fprintf(fpnew, "\n%s %d %d %d", trashid, mydate.year, mydate.month, mydate.day);//ָ�����ݵĸ���
            key = 1;
        }
        else {
            fprintf(fpnew, "\n%s %d %d %d", trashid, y, m, d);//���಻��
        }
    }
    if (key == 0) {
        fprintf(fpnew, "\n%s %d %d %d", (*user_id)->id, mydate.year, mydate.month, mydate.day);//���಻��
    }
    fclose(fpnew);
    fclose(fpdate);
    remove("Date.txt");//�����������滻
    rename("date_annex.txt", "Date.txt");
    system("pause");
    system("cls");
    while (1) {
        printf("\t\t\t\t\t**************************\n");
        printf("\t\t\t\t\t***��ѡ����Ҫ���еĲ���***\n");//չʾ������Ŀ
        printf("\t\t\t\t\t**********1.���**********\n");
        printf("\t\t\t\t\t**********2.ȡ��**********\n");
        printf("\t\t\t\t\t********3.��ѯ���********\n");
        printf("\t\t\t\t\t**********4.ת��**********\n");
        printf("\t\t\t\t\t******5.��ѯ���׼�¼******\n");
        printf("\t\t\t\t\t**********6.����**********\n");
        printf("\t\t\t\t\t********7.�޸�����********\n");
        printf("\t\t\t\t\t**********8.�˿�**********\n");
        char user_in[10];
        scanf("%s", user_in);//�õ��û�����
        if (!strcmp(user_in, "8")) {//�˿�����
            system("cls");//����
            while (!feof(fp)) {
                double y, m;
                fscanf(fp, "%s %lf %lf", trashid, &y, &m);//�����ļ�����ȡ
                if (!strcmp(trashid, (*user_id)->id)) {
                    fprintf(fpan, "\n%s %lf %lf", trashid, ava, limit);//ָ�����ݵĸ���
                }
                else {
                    fprintf(fpan, "\n%s %lf %lf", trashid, y, m);//���಻��
                }
            }
            fclose(fp);
            fclose(fpan);
            remove("limit.txt");//�����������滻
            rename("limit_annex.txt", "limit.txt");
            return 1;//�������õ�����ֵ��1������ѭ��
        }
        else if (!strcmp(user_in, "1")) {//������
            saving(user_id, mydate.year, mydate.month, mydate.day);//����
            system("cls");//����
            continue;
        }
        else if (!strcmp(user_in, "2")) {//ȡ�����
            ava_use = &ava;
            withdrawal_2(user_id, mydate.year, mydate.month, mydate.day, ava_use);//ȡ���
            system("cls");
            continue;
        }
        else if (!strcmp(user_in, "3")) {//��ѯ����ʣ����ö��
            printf("\t\t\t\t\t***���������Ϊ: %.2lf\n", (*user_id)->amount);//���û���������
            printf("\t\t\t\t\t***�����ڿ��ö��Ϊ: %.2lf\n", ava);
            printf("\t\t\t\t\t***��ѯ��������������һ����***\n");
            system("pause");
            system("cls");
            continue;
        }
        else if (!strcmp(user_in, "4")) {//ת�˲���
            printf("\t\t\t\t\t***��������Ҫת����˻���0������һ����***\n");//��������
            char transfer[21];
            int set = 0;
            struct Account* goal = NULL;
            while (goal == NULL) {
                scanf("%s", transfer);//�û�����Ĳ���
                if (!strcmp(transfer, "0")) {//�����0���˳��ý���
                    set = 1;//��¼�Ƴ�����
                    break;//��Ϊ�Ƴ�����ֱ���뿪ѭ��
                }
                goal = Search_id(head, transfer);//�ҵ���Ӧ�˻�
                if (goal == NULL)//δ�ҵ�ָ���˻�
                    printf("\t\t\t\t\t***δ�ҵ���Ӧ�˻��������������0������һ����***\n");
            }
            if (set == 1) {//������һ����
                system("cls");
                continue;
            }
            char money_in[100];
            printf("\t\t\t\t***��������ҪΪ,����Ϊ%s,�˻�Ϊ%s,���û�ת�˵Ľ����˻����������0��***\n", goal->name, goal->id);//���û��ٴ�ȷ��
            scanf("%s", &money_in);//�õ��û�������
            double money_ture;
            money_ture = (double)right_dou(money_in);//�ж������Ƿ�Ϊ�Ϸ�����
            if (money_ture != -1) {//�Ϸ��������
                money_ture = atof(money_in);
                if (money_ture <= (*user_id)->amount) {//�ж�ת������Ƿ����
                    (*user_id)->amount -= money_ture;//����ת�˲���
                    goal->amount += money_ture;
                    printf("\t\t\t\t\t***ת����ɽ�������һ����***\n");
                    FILE* fp = fopen("trade.txt", "r+");//�򿪽��׼�¼�ļ�
                    fseek(fp, 0L, SEEK_END);
                    fprintf(fp, "\n%s %d %d %d ���˻�Ϊ%s���˻�ת��%.2lfԪ", (*user_id)->id, mydate.year, mydate.month, mydate.day, transfer, money_ture);//���н��׼�¼��¼��
                    fprintf(fp, "\n%s %d %d %d ���˻�Ϊ%s���˻�ת��%.2lfԪ", transfer, mydate.year, mydate.month, mydate.day, (*user_id)->id, money_ture);
                    fclose(fp);
                    system("pause");
                    system("cls");
                    continue;
                }
                else {//��������
                    printf("\t\t\t\t\t***����ת��ʧ�ܽ�������һ����***\n");
                    system("pause");
                    system("cls");
                    continue;
                }
            }
            else {//�Ƿ��������
                printf("\t\t\t\t\t***͹(ܳ��ܳ )����Ȼ����***\n");
                system("pause");
                system("cls");
            }
        }
        else if (!strcmp(user_in, "5")) {//��ѯ�Լ��Ľ��׼�¼
            char trash_id[21], messege[100], userin[100];
            struct Date mydate;
            int year, key = 0;
            printf("\t\t\t\t\t***����0��ѯȫ�����׼�¼������ָ����ݿɲ�ѯ�����¼***\n");
            scanf("%s", userin);//�õ��û�������
            year = right(userin);//�жϺϷ�����
            if (year != -1 && year != 0) {//��ָ�����
                FILE* fp = fopen("trade.txt", "r");//�򿪽��׼�¼���ļ�
                while (!feof(fp)) {
                    fscanf(fp, "%s %d %d %d %s", trash_id, &mydate.year, &mydate.month, &mydate.day, messege);//��ȡ��Ϣ
                    if (!strcmp(trash_id, (*user_id)->id) && mydate.year == year) {//�ж��˺ź�����Ƿ�һ��
                        printf("%d��%d��%d�� ����:%s\n", mydate.year, mydate.month, mydate.day, messege);//������׼�¼
                        key = 1;//�н��׼�¼
                    }
                }
                if (key == 0) {//�޽��׼�¼
                    printf("\t\t\t\t\t***δ�ҵ�������ݵĽ��׼�¼����������һ����***\n");
                }
                fclose(fp);
                system("pause");
                system("cls");
            }
            else if (year != -1 && year == 0) {//�Ϸ����벢�Ҳ�ѯ���н��׼�¼
                FILE* fp = fopen("trade.txt", "r");
                while (!feof(fp)) {
                    fscanf(fp, "%s %d %d %d %s", trash_id, &mydate.year, &mydate.month, &mydate.day, messege);//��ȡ��Ϣ
                    if (!strcmp(trash_id, (*user_id)->id)) {//�ж��˺��Ƿ�һ��
                        printf("%d��%d��%d�� ����:%s\n", mydate.year, mydate.month, mydate.day, messege);//���������Ϣ
                        key = 1;
                    }
                }
                if (key == 0) {//�޽��׼�¼
                    printf("\t\t\t\t\t***�޽��׼�¼***\n");
                }
                fclose(fp);
                system("pause");
                system("cls");
            }
            else {//�Ƿ��������
                printf("\t\t\t\t\t***͹(ܳ��ܳ )����Ȼ����***\n");
                system("pause");
                system("cls");
            }
        }
        else if (!strcmp(user_in, "6")) {//����
            while (1) {
                double own = limit - ava;
                if (own == 0) {
                    printf("\t\t\t\t\t***���軹�������һ����***\n");
                    system("pause");
                    system("cls");
                    break;
                }
                printf("\t\t\t\t\t***�����뻹�����0������һ����***\n");
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
                        printf("\t\t\t\t\t***���軹����ô�ֻ࣬��Ҫ%.2lf����Ϊ���Զ��ۿ�***\n", own);
                        fprintf(fp, "\n%s %d %d %d ����%.2lf", (*user_id)->id, mydate.year, mydate.month, mydate.day, own);
                        own = 0;
                        ava = limit;
                    }
                    else {
                        fprintf(fp, "\n%s %d %d %d ����%.2lf", (*user_id)->id, mydate.year, mydate.month, mydate.day, money_ture);
                        own -= money_ture;
                        ava += money_ture;
                    }
                    fclose(fp);
                    printf("\t\t\t\t\t***����ɹ���������һ����***\n");
                    system("pause");
                    system("cls");//����
                    break;
                }
                else {
                    printf("\t\t\t\t\t***͹(ܳ��ܳ )����Ȼ����***\n");
                    system("pause");
                    system("cls");
                }
            }
        }
        else if (!strcmp(user_in, "7")) {
            printf("\t\t\t\t\t***�����������������0������һ����***\n");
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
                    printf("\t\t\t\t\t ***���볤��(6λ)���������������0������һ����***\n");
                    continue;
                }
                if (key == 1) {
                    printf("\t\t\t\t\t ***�����ʽ���������������0������һ����***\n");
                    continue;
                }
                if (key == 0) {
                    while (1) {
                        printf("\t\t\t\t\t***���ٴ������������0������һ����***\n");
                        char trash[200];
                        scanf("%s", trash);
                        if (!strcmp(trash, "0")) {
                            key = 2;
                            break;
                        }
                        if (strcmp(trash, user_key)) {
                            printf("\t\t\t\t\t***�������벻һ��***\n");
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
                            printf("\t\t\t\t\t***�����޸ĳɹ���������һ����***\n");
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
        else {//��������ķǷ�����
            printf("\t\t\t\t\t ***͹(ܳ��ܳ )����Ȼ����***\n");
            system("pause");
            system("cls");
        }

    }
}
