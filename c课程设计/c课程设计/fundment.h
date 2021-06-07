#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
struct Account

{
    char id[21];//����
    char password[7];//����
    char name[20];//����
    char sex[5];//�Ա�
    double amount;//���
    long long idcard;//���֤
    double interest;//��Ϣ
    int state;//״̬ 0�����ã�1����
    int kind;//0�����ÿ���1�Ǵ��
    struct Account* next;//����ָ����һ��

};
struct Date
{
    int year;
    int month;
    int day;
};
struct Account* Search_id(struct Account* head, char* id) {
    struct Account* run;//��ͣ�ƶ���ָ��
    run = head;//ָ���ʼ��
    while (run!= NULL) {//������ĩβʱ����ѭ��
        if (!strcmp(run->id, id)) {
            return run;
        }
        run = run->next;
    }
    return NULL;
}
struct Account* Search_name(struct Account* head, char* name) {
    struct Account* run;//��ͣ�ƶ���ָ��
    run = head;//ָ���ʼ��
    while (run != NULL) {//������ĩβʱ����ѭ��
        if (strstr(run->name, name)!=NULL) {
            return run;
        }
        run = run->next;
    }
    return NULL;
}
struct Account* Get_file(FILE* fp)//���ļ��������ݣ���������                         �����ļ�ͷָ�룬��������ͷָ��
{
    struct Account* user = (struct Account*)malloc(sizeof(struct Account)), * before = user, * p = (struct Account*)malloc(sizeof(struct Account));//*********************�ռ���Լ�����
    if (feof(fp)!=0)
    {
        user = NULL;
        return user;
    }
    fscanf(fp, "%s %s %s %s %lf %lld %lf %d %d\n", user->name, user->sex, user->id, user->password, &user->amount, &user->idcard, &user->interest, &user->state, &user->kind);
    user->next = p;
    while (fscanf(fp, "%s %s %s %s %lf %lld %lf %d %d\n", p->name, p->sex, p->id, p->password, &p->amount, &p->idcard, &p->interest, &p->state, &p->kind) != EOF)//���ݵ�������ȡ
    {
        before->next = p;
        before = p;
        before->next = NULL;
         p = (struct Account*)malloc(sizeof(struct Account));
    }
    return user;
}

void printout(struct Account* head) {
    FILE* fp = fopen("Account.txt", "r+");
    struct Account* run;
    run = head;
    while (run!= NULL) {
        fprintf(fp, "%s %s %s %s %lf %lld %lf %d %d\n", run->name, run->sex, run->id, run->password, run->amount, run->idcard, run->interest, run->state, run->kind);
        run = run->next;
    }
    fclose(fp);
}
void printout_new(struct Account* head) {
    FILE* fp = fopen("Account.txt", "w+");
    struct Account* run;
    run = head;
    while (run!=NULL) {
        fprintf(fp, "%s %s %s %s %lf %lld %lf %d %d\n", run->name, run->sex, run->id, run->password, run->amount, run->idcard, run->interest, run->state, run->kind);
        run = run->next;
    }
    fclose(fp);
}
void delete_account(struct Account* head,struct Account *p)//ɾ��Ŀ��ڵ�
{
    struct Account* run = head;
    if (p == head)//�������������ͷָ��
    {
        head = p->next;//ֱ�ӽ�ͷָ��ĵ�ַ�任Ϊ��һ��
        return;
    }
    while (run->next!=p)
    {
        run = run->next;
    }
    run->next = p->next;
    return;
}
double Get_interest_ava()
{
    FILE* p = fopen ("Admin.txt", "r+");
    char a[100];
    double interest_ava,c;
    fscanf(p, "%s %lf %lf",a,&interest_ava,&c );
    fclose(p);
    return interest_ava;
}
double Get_interest_dea(int n)//n�������� ��Ϊ����ÿ����30�� ÿ��360�� ͨ������ ֱ�Ӽ���Ӧ�÷��ض�õ���Ϣ
{
    FILE* p = fopen("Admin.txt", "r+");
    char a[100];
    double c;//���ڱ��� ռλ
    double dea_3month,dea_6month,dea_1year,dea_2year,dea_3year,dea_5year;
    fscanf(p, "%s %lf %lf %lf %lf %lf %lf %lf", a , &c,&dea_3month,&dea_6month,&dea_1year,&dea_2year,&dea_3year,&dea_5year);
    fclose(p);
    switch (n)//90 180 360 720 1080 1800����
    {
        case 90 : return dea_3month; break;
        case 180: return dea_6month; break;
        case 360: return dea_1year;  break;
        case 720: return dea_2year;  break;
        case 1080:return dea_3year;  break;
        case 1800:return dea_5year;  break;
        default:return Get_interest_ava(); break;
    }
}
int right_dou(char* unknow) {
    int key = 0, i;
    int ture;
    for (i = 0; i >= 0; i++) {
        if (unknow[i] == '\0')
            return 1;
        if (unknow[i] == '.' && key == 0)
            key = 1;
        else if (unknow[i] == '.' && key == 1)
            return -1;
        else if (unknow[i] < '0' || unknow[i]>'9')
            return -1;
    }
}
int right(char* unknow) {//�ж��Ƿ�ʱ�Ϸ�����
    int i;
    int ture = 0;
    for (i = 0; i >= 0; i++) {
        if (unknow[i] == '\0')//�������βʱ����ѭ��
            break;
        if (unknow[i] >= '0' && unknow[i] <= '9') {//���м���
            if (i == 0)
                ture = unknow[i] - '0';
            else {
                ture = ture * 10 + unknow[i] - '0';
            }
        }
        else { return -1; }//�Ƿ����뷵��-1
    }
    return ture;
}
int check_integer(char* pin)//����1������ 0��������
{

    for (int i = 0; i < strlen(pin); i++)
    {
        if (i == 17)//���֤���һλ����Ϊx
        {
            if (pin[i] == 'x') return 1;
        }
        if (pin[i] > '9' || pin[i] < '0')  return 0;
    }
    return 1;
}
void in_date(struct Date* date)
{
    char year[50], month[50], day[50];//�ַ�������������
    int temp[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };//�Ա������� 1-12
    scanf("%s %s %s", year, month, day);
    while (check_integer(year) == 0 || (int)atof(year) != atof(year))//�ַ���ת�� ������� 2.���������
    {
        printf("\t\t\t\t***     ��Ǹ����ݴ����������������  ***\n");
        scanf("%s", year);
    }
    date->year = atoi(year);//�������
    //////����
    if (date->year % 400 == 0)temp[2] = 29;
    if (date->year % 4 == 0 && date->year % 100 != 0)temp[2] = 29;
    while (check_integer(month) == 0 || atoi(month) > 12 || atoi(month) <= 0 || (int)atof(month) != atof(month))//�·ݷǷ����� ���� �·ݴ���12,С��0  ������
    {
        printf("\t\t\t\t***     ��Ǹ���·ݴ��������������·�  ***\n");
        scanf("%s", month);
    }
    date->month = atoi(month);
    while (check_integer(day) == 0 || atoi(day) > temp[date->month] || atoi(day) <= 0 || (int)atof(day) != atof(day))//�����Ƿ����� ���� �������ڵ������ֵ ������
    {
        printf("\t\t\t\t***     ��Ǹ������������������������  ***\n");
        scanf("%s", day);
    }
    date->day = atoi(day);
    printf("\t\t\t\t***             ��������ɹ�        ***\n");
    printf("\t\t\t\t***         ������������Ĳ���      ***\n\n");
}
void in_date_user(struct Date* date, char* id)
{
    char year[50], month[50], day[50];//�ַ�������������
    int temp[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };//�Ա������� 1-12
    int year1, month1, day1;
    int key = 0;
    FILE* fp = fopen("Date.txt", "r");
    while (!feof(fp)) {
        char trash[21];
        fscanf(fp, "%s %d %d %d", trash, &year1, &month1, &day1);
        if (!strcmp(id, trash)) {
            key = 1;
            break;
        }
    }
    if (key == 0) {
        year1 = 0;
        month1 = 0;
        day1 = 0;
        printf("\t\t\t\t\t***���������״ε�¼��ʱ��***\n");
    }
    scanf("%s %s %s", year, month, day);
    while (check_integer(year) == 0 || (int)atof(year) != atof(year) || atof(year) < year1)//�ַ���ת�� ������� 2.���������
    {
        printf("\t\t\t\t***     ��Ǹ����ݴ����������������  ***\n");
        scanf("%s", year);
    }
    date->year = atoi(year);//�������
    //////����
    if (date->year % 400 == 0)temp[2] = 29;
    if (date->year % 4 == 0 && date->year % 100 != 0)temp[2] = 29;
    while (check_integer(month) == 0 || atoi(month) > 12 || atoi(month) <= 0 || (int)atof(month) != atof(month) || (atof(year) == year1 && atof(month) < month1))//�·ݷǷ����� ���� �·ݴ���12,С��0  ������
    {
        printf("\t\t\t\t***     ��Ǹ���·ݴ��������������·�  ***\n");
        scanf("%s", month);
    }
    date->month = atoi(month);
    while (check_integer(day) == 0 || atoi(day) > temp[date->month] || atoi(day) <= 0 || (int)atof(day) != atof(day) || (atof(year) == year1 && atof(month) == month1 && atof(day) < day1))//�����Ƿ����� ���� �������ڵ������ֵ ������
    {
        printf("\t\t\t\t***     ��Ǹ������������������������  ***\n");
        scanf("%s", day);
    }
    date->day = atoi(day);
    printf("\t\t\t\t***             ��������ɹ�        ***\n");
    printf("\t\t\t\t***         ������������Ĳ���      ***\n\n");
    fclose(fp);
}
void backup() {//���ݺ���
    FILE* fp_account = fopen("Account.txt", "r");//��ACCount�ļ����б���
    FILE* fp_account_an = fopen("Account1.txt", "w");
    while (!feof(fp_account)) {
        struct Account a1;
        fscanf(fp_account, "%s %s %s %s %lf %lld %lf %d %d\n", a1.name, a1.sex, a1.id, a1.password, &a1.amount, &a1.idcard, &a1.interest, &a1.state, &a1.kind);
        fprintf(fp_account_an, "\n%s %s %s %s %lf %lld %lf %d %d", a1.name, a1.sex, a1.id, a1.password, a1.amount, a1.idcard, a1.interest, a1.state, a1.kind);
    }
    fclose(fp_account);
    fclose(fp_account_an);
    FILE* fp_date = fopen("Date.txt", "r");//��date�ļ����б���
    FILE* fp_date_an = fopen("Date1.txt", "w");
    while (!feof(fp_date)) {
        char* id = (char*)malloc(21);
        int year, month, day;
        fscanf(fp_date, "%s %d %d %d\n", id, &year, &month, &day);
        fprintf(fp_date_an, "\n%s %d %d %d", id, year, month, day);
        free(id);
    }
    fclose(fp_date);
    fclose(fp_date_an);
    FILE* fp_admin = fopen("Admin.txt", "r");//��admin�ļ����б���
    FILE* fp_admin_an = fopen("Admin1.txt", "w");
    char password[100];
    double a1, a2, a3, a4, a5, a6, a7;
    fscanf(fp_admin, "%s %lf %lf %lf %lf %lf %lf %lf", password, &a1, &a2, &a3, &a4, &a5, &a6, &a7);
    fprintf(fp_admin_an, "%-20s\n%lf %lf %lf %lf %lf %lf %lf", password, a1, a2, a3, a4, a5, a6, a7);
    fclose(fp_admin);
    fclose(fp_admin_an);
    FILE* fp_limit = fopen("limit.txt", "r");//��limit�ļ����б���
    FILE* fp_limit_an = fopen("limit1.txt", "w");
    while (!feof(fp_limit)) {
        char* id = (char*)malloc(21);
        double ava, limit;
        fscanf(fp_limit, "%s %lf %lf\n", id, &ava, &limit);
        fprintf(fp_limit_an, "\n%s %lf %lf", id, ava, limit);
        free(id);
    }
    fclose(fp_limit);
    fclose(fp_limit_an);
    FILE* fp_regular = fopen("regular.txt", "r");//��regular�ļ����б���
    FILE* fp_regular_an = fopen("regular1.txt", "w");
    while (!feof(fp_regular)) {
        char* id = (char*)malloc(21);
        int money;
        struct Date d1, d2;
        fscanf(fp_regular, "%s ���%d ʱ��%d %d %d ��%d %d %d\n", id, &money, &d1.year, &d1.month, &d1.day, &d2.year, &d2.month, &d2.day);
        fprintf(fp_regular_an, "\n%s ���%d ʱ��%d %d %d ��%d %d %d", id, money, d1.year, d1.month, d1.day, d2.year, d2.month, d2.day);
        free(id);
    }
    fclose(fp_regular);
    fclose(fp_limit_an);
    FILE* fp_trade = fopen("trade.txt", "r");//��trade�ļ����б���
    FILE* fp_trade_an = fopen("trade1.txt", "w");
    while (!feof(fp_trade)) {
        char* id = (char*)malloc(21);
        char* messege = (char*)malloc(100);
        struct Date d;
        fscanf(fp_trade, "%s %d %d %d %s\n", id, &d.year, &d.month, &d.day, messege);
        fprintf(fp_trade_an, "\n%s %d %d %d %s", id, d.year, d.month, d.day, messege);
        free(id);
        free(messege);
    }
    fclose(fp_trade);
    fclose(fp_trade_an);
}
void update() {//�ļ��ָ�����
    rename("Account.txt", "Account2.txt");
    rename("Account1.txt", "Account.txt");
    rename("Account2.txt", "Account1.txt");
    rename("Admin.txt", "Admin2.txt");
    rename("Admin1.txt", "Admin.txt");
    rename("Admin2.txt", "Admin1.txt");
    rename("limit.txt", "limit2.txt");
    rename("limit1.txt", "limit.txt");
    rename("limit2.txt", "limit1.txt");
    rename("regular.txt", "regular2.txt");
    rename("regular1.txt", "regular.txt");
    rename("regular2.txt", "regular1.txt");
    rename("trade.txt", "trade2.txt");
    rename("trade1.txt", "trade.txt");
    rename("trade2.txt", "trade1.txt");
    rename("Date.txt", "Date2.txt");
    rename("Date1.txt", "Date.txt");
    rename("Date2.txt", "Date1.txt");
    printf("\t\t\t\t\t***�ļ��ָ���Ͻ�ǿ���˳�***\n");
    system("pause");
    exit(0);
}

//FILE *Search(char* a) {
//    FILE* fp;
//    fp = fopen( "Account.txt","r");
//    struct Account myAccount;
//    rewind(fp);
//    int key;
//    while (1) {
//        key = feof(fp);
//        if (key) {
//            printf("δ�ҵ���������Ŀ���һ�µ��˻�����ȷ�Ϻ��ٴ�����");
//            fclose(fp);
//            break;
//        }
//        fscanf(fp, "%s %s %s %f %d %f %d %d", myAccount.id, myAccount.password, myAccount.name, &myAccount.amount, &myAccount.limit, &myAccount.interest, &myAccount.state, &myAccount.kind);
//        if (!strcmp(a, myAccount.id)) {
//            return fp;
//        }
//        else {
//            continue;
//        }
//    }
//}