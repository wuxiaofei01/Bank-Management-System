#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fundment.h"
#include "money_change.h"
#include "interest.h"
#define _CRT_SECURE_NO_WARNINGS

int User(struct Account* head, struct Account** user_id) {
    struct Account* goal = NULL;//�����û������˻���λ��
    char userid[100];//����û�������˺�
    int nstate = 0;//���������������Ĵ���
    int key = 1;//���浱ǰuser������״̬��1Ϊ����������һ����0Ϊ�����쳣�����»ص���һ��user,2Ϊ�ص���һ����
    while (goal == NULL) {
        printf("\t\t\t\t\t***���������Ŀ��Ż�����1�ص���һ����***\n");
        scanf("%s", userid);//�õ�����Ŀ��Ż�1
        if (!strcmp(userid, "1")) {
            system("cls");
            key = 2;//�û�����1����ص���һ����
            return key;
        }
        goal = Search_id(head, userid);//�õ��û����˺�λ�ã����û������������
        if (goal == NULL)
            printf("\t\t\t\t\t***δ�ҵ���Ӧ�˺ţ���ȷ�Ϻ��ٴ�����***\n");
        else break;//�ɹ��ҵ��û���������˻����뿪ѭ��
    }
    char user_password[70];
    if (goal->state) {//�жϴ˿��Ƿ����
        printf("\t\t\t\t\t***���������������0������һ����***\n");
        while (1) {
            if (goal->state == 1) {//�жϴ˿��Ƿ����
                scanf("%s", user_password);//�õ����������
                if (!strcmp(user_password, "0")) {
                    system("cls");
                    return 0;
                }
                if (strcmp(goal->password, user_password)) {//�������������󽫻ص�ѭ��
                    printf("\t\t\t\t\t***������������������0������һ����***\n");
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
                }//������ȷ���뿪ѭ��
            }
            if (goal->state == 0) {
                printf("\t\t\t\t\t***�������п��ѱ����ᣬ����ϵ������Ա***\n");//�����п�������
                system("pause");
                system("cls");
                return 0;//��Ϊ�˻������ᣬ���Իص�user
            }
        }
    }
    if (goal->state == 0) {
        printf("\t\t\t\t\t***�������п��ѱ����ᣬ����ϵ������Ա***\n");//�����п�������
        system("pause");
        system("cls");
        return 0;//��Ϊ�˻������ᣬ���Իص�user
    }
}
int user_money(struct Account** user_id, struct Account* head) {
    int user_return = 1;//�˺����ķ���ֵ��1Ϊ�˿�����
    struct Date mydate, end, begin;//���ڴ���ʱ��
    char id[21];//�˻�od
    double money;
    printf("\t\t\t\t\t***�������¼ʱ����2011 1 1***\n");
    in_date_user(&mydate, (*user_id)->id);
    system("pause");
    system("cls");
    cumclate(mydate.year, mydate.month, mydate.day, user_id);
    FILE* fp_re = fopen("regular.txt", "r");//�򿪶��ڴ����ļ�
    while (!feof(fp_re)) {
        fscanf(fp_re, "%s ���%lf ʱ��%d %d %d ��%d %d %d", id, &money, &begin.year, &begin.month, &begin.day, &end.year, &end.month, &end.day);//�����ڴ���������ȡ����
        if (!strcmp(id, (*user_id)->id)) {//�ж��Ƿ�ΪĿ������
            if (mydate.year > end.year) {//ֻҪ��һ�����ڣ��Ϳ���ǰ����̨�����������
                system("color 74");
                printf("\a\t\t\t\t\t***���ж��ڴ���ѵ���***\n");
                system("pause");
                system("color 70");
                system("cls");
                break;
            }
            if (mydate.year == end.year && mydate.month > end.month) {//ֻҪ��һ�����ڣ��Ϳ���ǰ����̨�����������
                system("color 74");
                printf("\a\t\t\t\t\t***���ж��ڴ���ѵ���***\n");
                system("pause");
                system("color 70");
                system("cls");
                break;
            }
            if (mydate.year == end.year && mydate.month == end.month && mydate.day >= end.day) {//ֻҪ��һ�����ڣ��Ϳ���ǰ����̨�����������
                system("color 74");
                printf("\a\t\t\t\t\t***���ж��ڴ���ѵ���***\n");
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
        printf("\t\t\t\t\t***��ѡ����Ҫ���еĲ���***\n");//չʾ������Ŀ
        printf("\t\t\t\t\t**********1.���**********\n");
        printf("\t\t\t\t\t**********2.ȡ��**********\n");
        printf("\t\t\t\t\t********3.��ѯ���********\n");
        printf("\t\t\t\t\t**********4.ת��**********\n");
        printf("\t\t\t\t\t******5.��ѯ���׼�¼******\n");
        printf("\t\t\t\t\t******6.����ת����********\n");
        printf("\t\t\t\t\t********7.�޸�����********\n");
        printf("\t\t\t\t\t**********8.�˿�**********\n");
        char user_in[100];
        scanf("%s", user_in);//�õ��û�����
        if (!strcmp(user_in, "8")) {//�˿�����
            system("cls");//����
            return 1;//�������õ�����ֵ��1������ѭ��
        }
        else if (!strcmp(user_in, "1")) {//������
            saving(user_id, mydate.year, mydate.month, mydate.day);//����
            system("cls");//����
            continue;
        }
        else if (!strcmp(user_in, "2")) {//ȡ�����
            withdrawal(user_id, mydate.year, mydate.month, mydate.day);//ȡ���
            system("cls");
            continue;
        }
        else if (!strcmp(user_in, "3")) {//��ѯ���
            printf("\t\t\t\t\t***���������Ϊ: %.2lf\n", (*user_id)->amount);//���û���������
            printf("\t\t\t\t***��ѯ��������������һ����***\n");
            system("pause");
            system("cls");
        }
        else if (!strcmp(user_in, "4")) {//ת�˲���
            printf("\t\t\t\t\t***��������Ҫת����˻���0������һ����***\n");//��������
            char transfer[210];
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
            printf("\t***��������ҪΪ,����Ϊ%s,�˻�Ϊ%s,���û�ת�˵Ľ����˻����������0�����ж�λС����ֻȡ����λ��***\n", goal->name, goal->id);//���û��ٴ�ȷ��
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
            char trash_id[21], messege[100], userin[10];
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
        else if (!strcmp(user_in, "6")) {//���ڸĶ��ڲ���
            printf("\t\t***��������Ҫ��Ϊ���ڵĽ��û�����ֻ֧��һ�궨�ڣ�����������ǰ����̨������0������һ����***\n");
            char death_money[100], death_year[50];
            scanf("%s", death_money);//�õ��û�����
            int dea_money, dea_year;
            dea_money = right(death_money);//�жϷǷ��������
            if (dea_money != -1) {//�Ϸ�����
                if (dea_money == 0) {
                    system("cls");
                    continue;
                }
                if ((*user_id)->amount < dea_money) {//�ж�����Ƿ����
                    printf("\t\t\t\t\t***����***\t");
                    system("pause");
                    system("cls");
                    continue;
                }
                else {
                    (*user_id)->amount -= dea_money;//�۳����
                    FILE* fpdeath = fopen("regular.txt", "r+");
                    fseek(fpdeath, 0L, SEEK_END);//��ָ�����ĩβ
                    fprintf(fpdeath, "\n%s ���%d ʱ��%d %d %d ��%d %d 1", (*user_id)->id, dea_money, mydate.year, mydate.month, mydate.day, (mydate.year) + 1, mydate.month + 1);//���ж��ڵĴ��
                    printf("\t\t\t\t\t���ɹ���������һ����***\n");
                    fclose(fpdeath);
                    system("pause");
                    system("cls");
                }
            }
            else {
                printf("\t\t\t\t\t***͹(ܳ��ܳ )����Ȼ����***\n");
                system("pause");
                system("cls");
            }
        }
        else if (!strcmp(user_in, "7")) {
            printf("\t\t\t\t\t***�����������������0������һ����***\n");
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
                    printf("\t\t\t\t\t ***���볤�ȣ�6λ�����������������0������һ����***\n");
                    continue;
                }
                if (key == 1) {
                    printf("\t\t\t\t\t ***�����ʽ���������������0������һ����***\n");
                    continue;
                }
                if (key == 0) {
                    while (1) {
                        printf("\t\t\t\t\t***���ٴ������������0������һ����***\n");
                        char trash[10];
                        scanf("%s", trash);
                        if (!strcmp(trash, "0")) {
                            key = 2;
                            break;
                        }
                        if (strcmp(trash, user_key)) {
                            printf("\t\t\t\t\t***�������벻һ��***\n");
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