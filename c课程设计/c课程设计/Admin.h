#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include "fundment.h"
void out_all(struct Account* stu)// ***�������,�������������ݶ����
{
    struct Account* p, * end;
    // for (end = stu; end->next != NULL; end = end->next)//�ҵ�βָ��
     //stu=mysort(stu, end);
    printf("����     �Ա�\t  ����\t\t    ����     ���\t\t   ���֤            ��Ϣ            ״̬  ���\n");
    for (p = stu; p != NULL; p = p->next) {
        printf("%-9s %s %s   %-8s %-14.2lf %-25lld %-14.2lf  ", p->name, p->sex, p->id, p->password, p->amount, p->idcard, p->interest);
        if (p->state == 0) printf("���� ");
        else printf("���� ");
        if (p->kind == 0)printf("���ÿ�\n");
        else printf("���\n");
    }
}
void out_sex_nan(struct Account* stu)//������ԣ������������Ե��������
{
    struct Account* p;
    int sum = 0;
    printf("����     �Ա�\t  ����\t\t    ����     ���\t\t   ���֤            ��Ϣ            ״̬  ���\n");
    for (p = stu; p != NULL; p = p->next)
    {
        if (strcmp(p->sex, "��") == 0)
        {
            printf("%-9s %s %s   %-8s %-14.2lf %-25lld %-14.2lf  ", p->name, p->sex, p->id, p->password, p->amount, p->idcard, p->interest);
            if (p->state == 0) printf("���� ");
            else printf("���� ");
            if (p->kind == 0)printf("���ÿ�\n");
            else printf("���\n");
            sum++;
        }
    }
    if (sum == 0) printf("\t\t\t\t\t***�����ڸ������û�\t\t\t\t\t\n\n\n\n");
}
void out_sex_nv(struct Account* stu)//���Ů��
{
    struct Account* p;
    int sum = 0;
    printf("����     �Ա�\t  ����\t\t    ����     ���\t\t   ���֤            ��Ϣ            ״̬  ���\n");
    for (p = stu; p != NULL; p = p->next)
    {
        if (strcmp(p->sex, "Ů") == 0)
        {
            printf("%-9s %s %s   %-8s %-14.2lf %-25lld %-14.2lf  ", p->name, p->sex, p->id, p->password, p->amount, p->idcard, p->interest);
            if (p->state == 0) printf("���� ");
            else printf("���� ");
            if (p->kind == 0)printf("���ÿ�\n");
            else printf("���\n");
            sum++;
        }
    }
    if (sum == 0) printf("\t\t\t\t\t***�����ڸ������û�\t\t\t\t\t\n\n\n\n");
}
void out_kind_0(struct Account* stu)//������ÿ�
{
    struct Account* p;
    int sum = 0;
    printf("����     �Ա�\t  ����\t\t    ����     ���\t\t   ���֤            ��Ϣ            ״̬  ���\n");
    for (p = stu; p != NULL; p = p->next)
    {
        if (p->kind == 0)
        {
            printf("%-9s %s %s   %-8s %-14.2lf %-25lld %-14.2lf  ", p->name, p->sex, p->id, p->password, p->amount, p->idcard, p->interest);
            if (p->state == 0) printf("���� ");
            else printf("���� ");
            if (p->kind == 0)printf("���ÿ�\n");
            else printf("���\n");
            sum++;
        }
    }
    if (sum == 0)  printf("\t\t\t\t\t***�����ڸ������û�\t\t\t\t\t\n\n\n\n");
}
void out_kind_1(struct Account* stu)//���
{
    struct Account* p;
    int sum = 0;
    printf("����     �Ա�\t  ����\t\t    ����     ���\t\t   ���֤            ��Ϣ            ״̬  ���\n");
    for (p = stu; p != NULL; p = p->next)
    {
        if (p->kind == 1)
        {
            printf("%-9s %s %s   %-8s %-14.2lf %-25lld %-14.2lf  ", p->name, p->sex, p->id, p->password, p->amount, p->idcard, p->interest);
            if (p->state == 0) printf("���� ");
            else printf("���� ");
            if (p->kind == 0)printf("���ÿ�\n");
            else printf("���\n");
            sum++;
        }
    }
    if (sum == 0)  printf("\t\t\t\t\t***�����ڸ������û�\t\t\t\t\t\n\n\n\n");
}
//*******************************************************************************************************//������һ��������
struct Account* mysort(struct Account* head2)//����ͷָ�루�ڵ㣩
{
    struct Account* head = (struct Account*)malloc(sizeof(struct Account)), * temp = head2;//ͳ���ж�������
    int i = 0;
    while (temp != NULL)//ͳ���ж��ٸ����� ���Ӷ�n
    {
        i++;
        temp = temp->next;
    }
    head->next = head2;
    struct Account* pre, * cur, * next;
    while (i--)//ð������
    {
        for (pre = head, cur = pre->next, next = cur->next; next != NULL; pre = pre->next, cur = cur->next, next = next->next)
        {
            if (cur->amount < next->amount)//�ڵ㽻�������������ڵ㣬ǰȡ����
            {
                pre->next = next;
                cur->next = next->next;
                next->next = cur;
                struct Account* temp;
                temp = cur;
                cur = next;
                next = temp;
            }

        }
    }
    return head->next;
}
/***********************************************************************************/

/***************************************************************************************///����Ա��¼��ҳ��
int Admin()
{
    char realpin[21], yourpin[210];//��������
    FILE* fp = fopen("Admin.txt", "r+");
    fscanf(fp, "%s", realpin);
    system("cls");
    printf("\n\n\n\n\n");
    printf("\t\t\t\t***���������Ա����,���뷵����һ����������0***\n");
    scanf("%s", yourpin);
    if (strcmp(realpin, yourpin) == 0)//����������ȷ
    {
        system("cls");
        return 1;
    }
    else if (strcmp(yourpin, "0") == 0)return 2;//�ص���һ����
    else
    {
        printf("\t\t\t\t\t����������\n");
        return 0;
    }//����
}
/******************************************************************************************************//*�˵�Ŀ¼*/
int Admin_menu()//�ж��û�ѡ�������һ��ҵ��
{
    while (1)
    {
        printf("\t\t\t\t\t***************************\n");
        printf("\t\t\t\t\t***   ����ҵ��������1   ***\n");
        printf("\t\t\t\t\t***   ��ѯ�û�������2   ***\n");
        printf("\t\t\t\t\t*** ���Ĺ���Ա��������3 ***\n");
        printf("\t\t\t\t\t***    �ļ���������4    ***\n");
        printf("\t\t\t\t\t**�ָ���һ���ļ���������5**\n");
        printf("\t\t\t\t\t***  ������һ��������6  ***\n");
        printf("\t\t\t\t\t***     �˳�������0     ***\n");
        printf("\t\t\t\t\t***************************\n");
        char a[200];
        scanf("%s", a);
        /*if (a == 1 || a == 2 || a == 3)
            return a;*/
        if (!strcmp(a, "1")) return 1;
        else if (!strcmp(a, "2")) return 2;
        else if (!strcmp(a, "3")) return 3;
        else if (!strcmp(a, "4")) return 4;
        else if (!strcmp(a, "5")) return 5;
        else if (!strcmp(a, "6")) return 6;
        else if (!strcmp(a, "0")) return 0;
        printf("\t\t\t\t\t***   ��������ȷ����    ***\n\n");
    }
}
/*//****************************************************************************************************************//*��½����*/
void print_number(struct Account* head)
{
    long long total = 0, credit = 0, debit = 0;//������,���ÿ��������������
    long long high = 0, mid = 0, low = 0;//�ߴ��еȣ���
    struct Account* temp = head;
    while (temp != NULL)
    {
        total++;
        if (temp->kind == 0)credit++;//���ÿ��ʹ��
        else debit++;
        if (temp->amount >= 100000) high++;
        else if (temp->amount > 1000 && temp->amount < 100000) mid++;
        else if (temp->amount < 1000)low++;
        temp = temp->next;
    }
    printf("\t\t\t\t\t******************************************\n");
    printf("\t\t\t\t\t*** ��ǰ�����û���       ** %-10lld��**\n", total);
    printf("\t\t\t\t\t*** ���ÿ��û���         ** %-10lld��**\n", credit);
    printf("\t\t\t\t\t*** ����û���         ** %-10lld��**\n", debit);
    printf("\t\t\t\t\t*** �����100000������ ** %-10lld��**\n", high);
    printf("\t\t\t\t\t*** �����1000-100000��** %-10lld��**\n", mid);
    printf("\t\t\t\t\t*** ����� 0-1000��    ** %-10lld��**\n", low);
    printf("\t\t\t\t\t******************************************\n");
    system("pause");
    system("cls");
}
void Admin_check_menu(struct Account *head)
{
    printf("\n\n\n\n\n\t\t\t\t************************************* \n");
    printf("\t\t\t\t***     ��ӡ���г�Ա��������1     *** \n");
    printf("\t\t\t\t***      �����ѯ��������2        *** \n");
    printf("\t\t\t\t***      �����ѯ��������3        *** \n");
    printf("\t\t\t\t***  �����ӡ���������˻�������4  *** \n");
    printf("\t\t\t\t***  �����ӡ����Ů���˻�������5  *** \n");
    printf("\t\t\t\t***  �����ӡ�������ÿ��˻�����6  *** \n");
    printf("\t\t\t\t***  �����ӡ���д���û�����7  *** \n");
    printf("\t\t\t\t***  ���뷵�ص���һ���棬������-1 *** \n");
    printf("\t\t\t\t************************************* \n");
}
int Admin_check(FILE* fp, struct Account* head)//�õ��ļ�ͷָ��     ���Һ����ľ���ʵ��
{
    char k[201];
    while (1)
    {
        Admin_check_menu(head);//����˵�
        scanf("%s", k);
        while (strcmp(k, "1") && strcmp(k, "2") && strcmp(k, "3") && strcmp(k, "4") && strcmp(k, "5") && strcmp(k, "6") && strcmp(k, "7") && strcmp(k, "-1"))
        {
            printf("\t\t\t\t*** ���������������ȷ������   ***\n\n");//������Ч
            scanf("%s", k);
        }
        if (!strcmp(k, "-1"))return 1;//-1���Ƿ�����һ�˵�
        struct Account* temp = 0;
        if (!strcmp(k, "1"))//�˳�����
        {
            head = mysort(head);
            out_all(head);
            printf("\t\t\t\t\t***������˳�����������0***\n\t\t\t\t\t***������һ���������0ֵ***\n");
            scanf("%s", k);
            system("cls");
            if (strcmp(k, "0") == 0) exit(0);
            continue;
        }//�����ж�}

        if (!strcmp(k, "2"))//��ӡid
        {
            while (1)
            {
                printf("\t\t\t\t***           �����뿨��          ***\n");
                temp = head;//����search��������Ҫһ��ͷָ��
                char id[30];
                scanf("%s", id);
                struct Account* p;
                p = Search_id(temp, id);
                if (p != NULL) {//�ú����ҵ���
                    printf("����     �Ա�\t  ����\t\t    ����     ���\t\t   ���֤            ��Ϣ            ״̬  ���\n");//��ʽ
                    printf("%-9s %s %s   %-8s %-14.2lf %-25lld %-14.2lf  ", p->name, p->sex, p->id, p->password, p->amount, p->idcard, p->interest);
                    if (p->state == 0) printf("���� ");
                    else printf("���� ");
                    if (p->kind == 0)printf("���ÿ�\n");
                    else printf("���\n");
                }
                else printf("\t\t\t\t\t***��ѯ�������û�***\n");//�鲻��
                char key[201];//�ж���һ������
                printf("\t\t\t\t\t***�����˳������밴0***\n\t\t\t\t\t***���������ѯ��������1***\n\t\t\t\t\t***���뷵����һ��������2***\n");
                scanf("%s", key);
                system("cls");
                if (!strcmp(key, "1"))
                {
                    printf("\n\n\n\n\n");
                    continue;
                }
                if (!strcmp(key, "2")) break;//������ʾ
                if (!strcmp(key, "0")) exit(0);
                while (1)//ѭ�����룬�û������벻��
                {

                    printf("\n\n\n\n\n\t\t\t\t\t������Ч��������0,1,2\n");
                    printf("\t\t\t\t\t***�����˳������밴0***\n\t\t\t\t\t***���������ѯ��������1***\n\t\t\t\t\t***���뷵����һ��������2***\n");
                    scanf("%s", key);
                    if (!strcmp(key, "1") || !strcmp(key, "0") || !strcmp(key, "2"))break;
                }
                system("cls");
                if (!strcmp(key, "1")) continue;//�ж��û��Ľ���������
                if (!strcmp(key, "2")) break;
                if (!strcmp(key, "0")) exit(0);
            }
        }
        if (!strcmp(k, "3"))//��ӡ����
        {
            while (1)
            {
                printf("\t\t\t\t***           ����������          ***\n");
                int sum = 0;//��һ���������жϲ�ѯ�����ҵ�û��,�ҵ��ͼ�һ��û�ҵ��Ͳ���һ
                temp = head;
                char name[30];
                scanf("%s", name);
                struct Account* p = head;//������ֵ��ûʲô���壬��ҪΪ������ѭ���жϣ���β���              
                while (p != NULL)
                {
                    p = Search_name(p, name);
                    if (p != NULL) {
                        printf("����     �Ա�\t  ����\t\t    ����     ���\t\t   ���֤            ��Ϣ            ״̬  ���\n");//��ʽ
                        printf("%-9s %s %s   %-8s %-14.2lf %-25lld %-14.2lf  ", p->name, p->sex, p->id, p->password, p->amount, p->idcard, p->interest);
                        if (p->state == 0) printf("���� ");
                        else printf("���� ");
                        if (p->kind == 0)printf("���ÿ�\n");
                        else printf("���\n");
                        p = p->next;//��ֹSearch_name()��������ѭ��
                        sum++;
                    }
                }
                if (sum == 0) printf("\t\t\t\t\t***û�и��û�***\n");
                char key[50];//�ж���һ������
                printf("\t\t\t\t\t***�����˳��밴0***\n\t\t\t\t\t***���������ѯ��������1***\n\t\t\t\t\t***���뷵����һ��������2***\n");
                scanf("%s", key);
                system("cls");
                if (!strcmp(key, "1"))
                {
                    printf("\n\n\n\n\n");//������ʽ
                    continue;
                }
                if (!strcmp(key, "2")) break;//������ʾ
                if (!strcmp(key, "0")) exit(0);
                while (1)
                {
                    printf("\t\t\t\t\t������Ч��������0,1,2\n");
                    printf("\t\t\t\t\t***�����˳��밴0***\n\t\t\t\t\t***���������ѯ��������1***\n\t\t\t\t\t***���뷵����һ��������2***\n");
                    scanf("%s", key);
                    if (!strcmp(key, "1") || !strcmp(key, "0") || !strcmp(key, "2"))break;
                }
                system("cls");
                if (!strcmp(key, "1")) continue;
                if (!strcmp(key, "2")) break;
                if (!strcmp(key, "0")) exit(0);
            }
        }
        if (!strcmp(k, "4"))//��ӡ����
        {
            out_sex_nan(head);
            printf("\t\t\t\t***     ������һ���棬������1     *** \n");
            printf("\t\t\t\t***       �����˳������밴0           ***\n");
            scanf("%s", k);
            while (strcmp(k, "0") != 0 && strcmp(k, "1") != 0)//k������0��1ʱ
            {
                printf("\t\t\t\t\t***������1��0***\n");
                scanf("%s", k);
            }
            system("cls");
        }
        if (!strcmp(k, "5"))//��ӡ���ÿ� kind 0
        {
            out_sex_nv(head);
            printf("\t\t\t\t***     ������һ���棬������1     *** \n");
            printf("\t\t\t\t***       �����˳������밴0           ***\n");
            scanf("%s", k);
            while (strcmp(k, "0") != 0 && strcmp(k, "1") != 0)//k������0��1ʱ
            {
                printf("\t\t\t\t\t***������1��0***\n");
                scanf("%s", k);
            }
            system("cls");
        }
        if (!strcmp(k, "6"))//��ӡ���ÿ� kind 0
        {
            out_kind_0(head);
            printf("\t\t\t\t***     ������һ���棬������1     *** \n");
            printf("\t\t\t\t***       �����˳������밴0           ***\n");
            scanf("%s", k);
            while (strcmp(k, "0") != 0 && strcmp(k, "1") != 0)//k������0��1ʱ
            {
                printf("\t\t\t\t\t***������1��0***\n");
                scanf("%s", k);
            }
            system("cls");
        }
        if (!strcmp(k, "7"))//��� kind 1
        {
            out_kind_1(head);
            printf("\t\t\t\t***     ������һ���棬������1     *** \n");
            printf("\t\t\t\t***       �����˳������밴0           ***\n");
            scanf("%s", k);
            while (strcmp(k, "0") != 0 && strcmp(k, "1") != 0)//k������0��1ʱ
            {
                printf("\t\t\t\t\t***������1��0***\n");
                scanf("%s", k);
            }
            system("cls");
        }
        if (!strcmp(k, "0")) exit(0);
    }

}
/***********************************************************************************/
int Admin_business_menu()//�˵���ӡ��������һ����ڣ��ж��û��������һ������
{
    printf("\n\n\n\n\n\t\t\t\t***********************************\n");
    printf("\t\t\t\t***    ���ڴ��,����ȡ������1   ***\n");
    printf("\t\t\t\t***        �˺Žⶳ������2      ***\n");
    printf("\t\t\t\t***        �˺Ŷ���������3      ***\n");
    printf("\t\t\t\t***        ��������������4      ***\n");
    printf("\t\t\t\t***         ����������5         ***\n");
    printf("\t\t\t\t***         ����������6         ***\n");
    printf("\t\t\t\t***   ��ѯ�˺Ŷ��ڴ������7     ***\n");
    printf("\t\t\t\t***     ������һ����������-1    ***\n");
    printf("\t\t\t\t***********************************\n");
    while (1)
    {
        char key[200];
        scanf("%s", key);
        if (!strcmp(key, "1")) return 1;
        if (!strcmp(key, "2")) return 2;
        if (!strcmp(key, "3")) return 3;
        if (!strcmp(key, "4")) return 4;
        if (!strcmp(key, "5")) return 5;
        if (!strcmp(key, "6")) return 6;
        if (!strcmp(key, "7")) return 7;
        if (!strcmp(key, "-1")) return -1;
        printf("\t\t\t\t***������Ч����������Ч���� ***\t\t\t\t\t\n");
    }
}
/**********************************************ҵ�����////**************//////////////////////////////////////////////////////////

int check_date(struct Date now, struct Date end)//1�ǵ���ʱ�� 0��δ�ﵽ
{
    int sum_now = now.year * 360 + now.month * 30 + now.day;//��Ϊ���а���ÿ��30�� ÿ��360����
    int sum_end = end.year * 360 + end.month * 30 + end.day;//ͳһΪ�� ��������Ƿ�ﵽ
    if (sum_now >= sum_end) return 1;
    else return 0;
}
int dif_date(struct Date begin, struct Date end)//���ص��Ǵ�����͵�����
{
    return (end.year - begin.year) * 360 + (end.month - begin.month) * 30 + end.day - begin.day;//���ش�������
}
int check_date_same(struct Date now_begin, struct Date begin, struct Date now_end, struct Date end)
{
    if (now_begin.year == begin.year && now_begin.month == begin.month && now_begin.day == begin.day)
        if (now_end.year == end.year && now_end.month == end.month && now_end.day == end.day) return 1;//������������
    return 0;
}
double get_realmoney(double realmoney, int cout, int real_cout)//ԭ���ı��� ������� ʵ������
{
    double interest_dea = Get_interest_dea(cout);//�õ�������͵���Ϣ
    double interest_ava = Get_interest_ava();
    int times = real_cout / cout;//�õ�����˼���������
    for (int i = 1; i <= times; i++)
    {
        realmoney = realmoney * (1 + interest_dea);
        // double interest_dea = Get_interest_dea(cout);//�õ�������͵���Ϣ  ���ʵĸ��£�
    }
    int sub = real_cout % cout;//�õ���ȥ���������� ���ж�����,�ⲿ���û��ڼ���
    for (int i = 1; i <= sub; i++)
    {
        realmoney = realmoney * (1 + interest_ava);
    }
    return realmoney;
}
void del_data(char* realid, struct Date real_begin, struct Date real_end)//ɾ������¼
{
    FILE* fp = fopen("regular.txt", "r+");//��ԭ�ļ�
    FILE* temp = fopen("regular2.txt", "w+");//�򿪱����ļ�
    char id[30];//�����ݳ�� ������ ���Ƕ�id����
    double money;
    struct Date begin, end;
    char a[2000];//������� �������ת�ƻ���
    /*123 ���1.000000 ʱ��1 1 1 ��2 2 2*/
    while (fscanf(fp, "%s ���%lf ʱ��%d %d %d ��%d %d %d", id, &money, &begin.year, &begin.month, &begin.day, &end.year, &end.month, &end.day) != EOF)//��Ŀ���ļ� ��ȡ���ݵ������ļ�
    {
        if (strcmp(id, realid) == 0 && check_date_same(real_begin, begin, real_end, end) == 1)//�ҵ���Ҫɾ����������
        {
            continue;
        }
        fprintf(temp, "%s ���%lf ʱ��%d %d %d ��%d %d %d\n", id, money, begin.year, begin.month, begin.day, end.year, end.month, end.day);//���뵽�����ļ�
    }
    fclose(fp);
    rewind(temp);
    FILE* fp2 = fopen("regular.txt", "w+");
    while (fgets(a, 2000, temp) != NULL)//����������Ŀ��
    {
        fputs(a, fp2);
    }
    fclose(fp2);
    fclose(temp);
    system("del regular2.txt");
}
int check_bank_save(struct Date begin, struct Date end)//����1�������벻��
{
    int sum_now = begin.year * 360 + begin.month * 30 + begin.day;//3 6�� 1 2 3 5��
    int sum_end = end.year * 360 + end.month * 30 + end.day;
    int count = sum_end - sum_now;
    if (count == 90) return 0;
    else if (count == 180) return 0;
    else if (count == 360) return 0;
    else if (count == 720) return 0;
    else if (count == 1080) return 0;
    else if (count == 1800) return 0;
    return 1;
}
void deadline(struct Date begin, char* len, struct Date* end)//����ʱ��Ϊ��׼ ���м��·ݣ������ڵ�����������ڵ��ڸ��������������ô�Ͷ�Ϊ��һ���µĵ�һ��
{
    int temp[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };//�Ա������� 1-12
    while (1)
    {
        if (!strcmp(len, "3��"))begin.month = begin.month + 3;////�жϴ�����͵�ʱ��
        else if (!strcmp(len, "6��"))begin.month = begin.month + 6;
        else if (!strcmp(len, "1��"))begin.year = begin.year + 1;
        else if (!strcmp(len, "2��"))begin.year = begin.year + 2;
        else if (!strcmp(len, "3��"))begin.year = begin.year + 3;
        else if (!strcmp(len, "5��"))begin.year = begin.year + 5;
        else
        {
            printf("\t\t\t\t  ���������3�£�6�£�1�꣬2�꣬3�꣬5��\n");
            printf("\t\t\t\t***      ����������������          ***\n");
            scanf("%s", len);
            continue;
        }
        break;//���е���һ����������Ϸ���
    }
    if (begin.month > 12)//�·ݳ����޶�
    {
        begin.year = begin.year + begin.month / 12;//����·ݴ���12,��ô��ݼ�1
        begin.month = begin.month % 12;//�·ݼ�12  eg:12��->6�� 18%13-->5
    }
    if (begin.day > temp[begin.month])
    {
        begin.day = 1;
        begin.month++;
    } /////����Ҫ�ڶ����жϣ���Ϊ12����31�죬31��begin.day�����ֵ ���ᳬ��12�� ���Կ��Բ����ټ�
    *end = begin;//��Ϊbegin�Ѿ��ӹ�ʱ���ˣ�����ֱ�Ӹ�ֵ

}
int Admin_save_withdraw_regular(struct Account* head)
{
    while (1)
    {
        printf("\t\t\t\t***         �������1           ***\n");
        printf("\t\t\t\t***         ȡ������2           ***\n");
        printf("\t\t\t\t***     ������һ��������0       ***\n");
        char key[100];
        scanf("%s", key);//�ж��û�����
        if (!strcmp(key, "1"))//������   ѡ�񲿷���ǰ֧ȡ����ô��ǰ֧ȡ���ְ��ջ������ʺ�ʵ�ʴ��������Ϣ��δȡ�����ְ���Լ���Ķ��ڴ�����ʼ�Ϣ��
        {
            FILE* fp = fopen("regular.txt", "r+");
            char id[30], password[50];
            double money;
            struct Date begin, end;
            system("cls");
            printf("\n\n\n\n\n\t\t\t\t***********************************\n");
            printf("\t\t\t\t***      ���뿨�ţ�����         ***\n");
            printf("\t\t\t\t***         ������            ***\n");
            printf("\t\t\t\t***       �������ʱ��          ***\n");
            printf("\t\t\t\t***       ���뵽��ʱ��          ***\n\n\n");
            printf("\t\t\t\t***           ����              ***\n");
            printf("\t\t\t\t*** 6222600260001072121 123456  ***\n");
            printf("\t\t\t\t***          1000.21            ***\n");
            printf("\t\t\t\t***         2019 4 5            ***\n");
            printf("\t\t\t\t***         2029 4 5            ***\n");
            printf("\t\t\t***��ע��ֻ��3�£�6�£�1�꣬2�꣬3�꣬5�궨����Ϣ***\n");
            scanf("%s %s %lf ", id, password, &money);//�����˺� ����
            scanf("%d %d %d %d %d %d", &begin.year, &begin.month, &begin.day, &end.year, &end.month, &end.day);
            struct Account* myid = Search_id(head, id);
            while (myid == NULL)//�Կ����ж��Ƿ����
            {
                printf("\t\t\t\t***        ���Ų�����           ***\n");
                printf("\t\t\t\t***    ��������������뿨��     ***\n");
                printf("\t\t\t\t***      ����ҵ���������0      ***\n");
                scanf("%s", id);
                if (!strcmp(id, "0")) break;
                myid = Search_id(head, id);
            }
            //�ҵ�������
            if (!strcmp(id, "0")) return 2;//������ҵ����� ��ֱ������
            while (strcmp(password, myid->password))//���벻�Զ��Ҳ�����ҵ�����
            {
                printf("\t\t\t\t***          �������           ***\n");
                printf("\t\t\t\t***    �������������������     ***\n");
                printf("\t\t\t\t***      ����ҵ���������0      ***\n");
                scanf("%s", password);
                if (!strcmp(password, "0")) break;
            }
            if (!strcmp(password, "0")) return 2;//������ҵ����� ��ֱ������
            fseek(fp, 0, SEEK_END);
            fprintf(fp, "%s ���%lf ʱ��%d %d %d ��%d %d %d\n", id, money, begin.year, begin.month, begin.day, end.year, end.month, end.day);
            printf("\t\t\t\t***          ���ɹ�           ***\n");
            printf("\t\t\t\t***       ������ȡ������1       ***\n");
            printf("\t\t\t\t***      ����ҵ���������2      ***\n");
            printf("\t\t\t\t***         �˳�����0           ***\n");
            char key2[100];
            scanf("%s", key2);
            if (!strcmp(key2, "1")) continue;
            if (!strcmp(key2, "2")) return 2;
            if (!strcmp(key2, "0")) exit(0);
            fclose(fp);
        }
        /***************************************************************************************************/
        else if (!strcmp(key, "2"))//ȡ�����  �����ڵ��ڣ�����ͬ�ȼ��Ĵ��������չ
        {
            FILE* fp = fopen("regular.txt", "r+");//�õ�ǰһ�δ涨�ڵ�ʱ�� �ͽ��
            char id[30], password[50];
            double money;
            char realid[30];
            double realmoney;
            struct Date now, begin, end;
            system("cls");
            printf("\n\n\n\n\n\t\t\t\t***********************************\n");
            printf("\t\t\t\t***      ���뿨�ţ�����         ***\n");
            printf("\t\t\t\t***         ����ʱ��            ***\n");
            printf("\t\t\t\t***           ����              ***\n");
            printf("\t\t\t\t*** 6222600260001072121 123456  ***\n");
            printf("\t\t\t\t***         2019 4 5            ***\n");
            scanf("%s %s ", id, password);//�����˺� ����
            scanf("%d %d %d", &now.year, &now.month, &now.day);//��ǰʱ��    ���������ļ���������
            while (1)//���˺Ų��ҵ�ѭ��
            {
                int flag = 1;//�жϽ����� �Ƿ��ҵ��˺�
                rewind(fp);//���ļ�ָ�������
                while (fscanf(fp, "%s ���%lf ʱ��%d %d %d ��%d %d %d\n", realid, &realmoney, &begin.year, &begin.month, &begin.day, &end.year, &end.month, &end.day) != EOF)
                {
                    if (!strcmp(id, realid))//�ļ����и�����
                    {
                        flag = 0;//�鵽��
                        break;
                    }
                }
                if (flag == 0) break;//�ҵ��˻���
                else
                {
                    printf("\t\t\t\t***        �����ڸ��˻�         ***\n");
                    printf("\t\t\t\t***       ������������뿨��    ***\n");
                    printf("\t\t\t\t***       ����ҵ���������0     ***\n");
                }
                scanf("%s", id);
                if (!strcmp(id, "0"))break;
            }
            if (!strcmp(id, "0"))return 2;//����ҵ�����
            while (strcmp(password, Search_id(head, id)->password))//�ж������Ƿ���ȷ
            {
                printf("\t\t\t\t***           �������          ***\n");
                printf("\t\t\t\t***       �����������������    ***\n");
                printf("\t\t\t\t***       ����ҵ���������0     ***\n");
                scanf("%s", password);
                if (!strcmp(password, "0"))break;
            }
            if (!strcmp(password, "0"))return 2;//����ҵ�����
            /////////////////////���������Ƕ�ȡ�����ȷ��
            if (check_date(now, end))//�ж��Ƿ�ﵽ���ʱ��   1�� 0û��    �����ǵ�
            {
                int cout = dif_date(begin, end);//��¼������ͣ��Ƕ����� �����ֱ�����Ϣ����30 90 180
                int real_cout = dif_date(begin, now);//����ʵ�ʵ�����
                realmoney = get_realmoney(realmoney, cout, real_cout);
                printf("\t\t\t\t***         ��Ĵ���        ***\n");
                printf("\t\t\t\t          ���д��%.2lf          \n", realmoney);//������Ϣ�ı���
                printf("\t\t\t\t***          ��������         ***\n");
                scanf("%lf", &money);//Ҫȡ���Ľ��
                while (money > realmoney || money < 0)//ȡ����
                {
                    printf("\t\t\t\t***           ����          ***\n");
                    printf("\t\t\t\t***          ����������         ***\n");
                    printf("\t\t\t\t***      ��������һ��������0    ***\n");
                    printf("\t\t\t\t***          ���˳�����-1       ***\n");
                    scanf("%lf", &money);
                    if (money == 0)break;
                    if (money == -1)exit(0);
                }
                printf("\t\t\t\t***           ȡ��ɹ�          ***\n");//����ȡ���ɹ�����������δ��ȫȡ����תΪ����
                del_data(id, begin, end);/**********������תΪ��һ���ļ������ø���regular�ļ����е�����*********/
                printf("\t\t\t\t***       ������ȡ������1       ***\n");
                printf("\t\t\t\t***      ����ҵ���������2      ***\n");
                printf("\t\t\t\t***         �˳�����0           ***\n");
                char key2[100];
                scanf("%s", key2);
                if (!strcmp(key2, "1")) continue;
                if (!strcmp(key2, "2")) return 2;
                if (!strcmp(key2, "0")) exit(0);
                if (money < realmoney)//��ʣ���Ǯת�����
                {
                    double money_in = realmoney - money;
                    FILE* fp = fopen("trade.txt", "r+");
                    fseek(fp, 0L, SEEK_END);
                    fprintf(fp, "%s %d %d %d ���%lfԪ\n", id, now.year, now.month, now.day, money_in);
                    fclose(fp);
                }
            }
            else//���û����
            {
                printf("\t\t\t\t***            ���δ����       ***\n");
                printf("\t\t\t\t***        �������ȡ������     ***\n");
                printf("\t\t\t\t***      ��������һ��������0    ***\n");
                printf("\t\t\t\t***          ���˳�����-1       ***\n");
                char key2[100];
                scanf("%s", key2);
                while (strcmp(key2, "0") != 0 || strcmp(key2, "1") != 0 || strcmp(key2, "-1") != 0)
                {
                    // printf("")
                }
            }
            fclose(fp);
        }
        else if (!strcmp(key, "0")) return 2;//������һ����
        else printf("\t\t\t\t***          �������           ***\n\n");
    }
}
int check_money(char* money)//1��ȷ 0����ȷ
{
    int point = 0;
    for (int i = 0; i < strlen(money); i++)
    {
        if (money[i] > '9' || money[i] < '0')//������ֻ��Ϊ���ֺ�С��
        {
            if (money[i] == '.')point++;//�м���С����
            if (money[i] != '.')return 0;//�Ƿ�������
        }
    }
    if (point == 1||point==0)return 1;
    return 0;
}
int Admin_save_withdraw_regular_new()//��ȡ���ǰ������֤���ڣ��뿨���޹� ȡ�����ȡ������������ȡ�����
{
    while (1)
    {
        system("cls");
        printf("\n\n\n\n\n\t\t\t\t***********************************\n");
        printf("\t\t\t\t***         �������1           ***\n");
        printf("\t\t\t\t***         ȡ������2           ***\n");
        printf("\t\t\t\t***     ������һ��������0       ***\n");
        printf("\t\t\t\t***********************************\n");
        char key[100];
        scanf("%s", key);//�ж��û�����
        if (!strcmp(key, "1"))//������   ѡ�񲿷���ǰ֧ȡ����ô��ǰ֧ȡ���ְ��ջ������ʺ�ʵ�ʴ��������Ϣ��δȡ�����ְ���Լ���Ķ��ڴ�����ʼ�Ϣ��
        {
            FILE* fp = fopen("regular.txt", "r+");
            char id[30], password[50];
            double money;
            struct Date begin, end;
            system("cls");
            printf("\n\n\n\n\n\t\t\t\t***************************************\n");
            printf("\t\t\t\t***          �������֤             ***\n");
            printf("\t\t\t\t***           ������              ***\n");
            printf("\t\t\t\t***         �������ʱ��            ***\n");
            printf("\t\t\t\t***         ����������            ***\n");
            printf("\t\t\t\t***     ���뷵����һ��������0       ***\n");
            printf("\t\t\t\t***             ����                ***\n");
            printf("\t\t\t\t***       513598200104151875        ***\n");
            printf("\t\t\t\t***            1000.21              ***\n");
            printf("\t\t\t\t***           2024 4 5              ***\n");
            printf("\t\t\t\t***             5��                 ***\n");
            printf("\t\t\t***��ע��ֻ��3�£�6�£�1�꣬2�꣬3�꣬5�궨����Ϣ***\n");
            ///////////////////�жϴ�������
            char money_scan[200];//���ܽ���ת��
            scanf("%s", id);//�����˺�
            if (!strcmp(id, "0")) return 2;
            //scanf("%s %d %d %d %d %d %d", money_scan, &begin.year, &begin.month, &begin.day, &end.year, &end.month, &end.day);//��ʼ ����ʱ��
            while (check_integer(id) == 0 || strlen(id) != 18)//�Ƿ����� ���֤λ�����ԣ�ǰ17λ����ȫ����
            {
                printf("\t\t\t\t***       ���֤�����������������    ***\n");
                printf("\t\t\t\t***        ע�⣬���֤Ϊ18λ����       ***\n");
                scanf("%s", id);
            }
            printf("\t\t\t\t***            ���֤����ɹ�           ***\n");
            printf("\t\t\t\t***              ��������             ***\n");
            scanf("%s", money_scan);
            money = atof(money_scan);
            while (1)
            {
                if (money > 0&&check_money(money_scan)==1) break;//����,����Ϸ�
                printf("\t\t\t\t*** �������ͬʱע�����Ϊ0�� ***\n");
                printf("\t\t\t\t***         ������������          ***\n");
                scanf("%s", money_scan);//�����˺� ����
                money = atof(money_scan);
            }
            printf("\t\t\t\t*** ���֤�ͽ������ɹ��������뵱ǰ����***\n");
            in_date(&begin);
            printf("\t\t\t\t***          ����������           ***\n");//������͵�����
            char len[50];
            scanf("%s", len);
            deadline(begin, len, &end);//���ں���
            fseek(fp, 0, SEEK_END);
            fprintf(fp, "%s ���%lf ʱ��%d %d %d ��%d %d %d\n", id, money, begin.year, begin.month, begin.day, end.year, end.month, end.day);
            fclose(fp);
            printf("\t\t\t\t***            ���ɹ�             ***\n");
            printf("\t\t\t\t***         ������ȡ������1         ***\n");
            printf("\t\t\t\t***        ����ҵ���������2        ***\n");
            printf("\t\t\t\t***         ������������0           ***\n");
            char key2[100];//�жϽ������Ĳ���
            while (1)
            {
                scanf("%s", key2);
                system("cls");
                if (!strcmp(key2, "1")) break;
                if (!strcmp(key2, "2")) break;
                if (!strcmp(key2, "0")) break;
                printf("\n\n\n\n\n\t\t\t\t***       ���������������        ***\n");
                printf("\t\t\t\t***         ������ȡ������1         ***\n");
                printf("\t\t\t\t***        ����ҵ���������2        ***\n");
                printf("\t\t\t\t***         ������������0           ***\n");
            }
            if (!strcmp(key2, "1")) continue;
            if (!strcmp(key2, "2")) return 2;
            if (!strcmp(key2, "0")) exit(0);
        }
        /***************************************************************************************************/
        else if (!strcmp(key, "2"))//ȡ�����  �����ڵ��ڣ�����ͬ�ȼ��Ĵ��������չ
        {
            FILE* fp = fopen("regular.txt", "r+");//�õ�ǰһ�δ涨�ڵ�ʱ�� �ͽ��
            char id[30];//���� 
            double money;
            char realid[30];
            double realmoney;
            struct Date now, now_begin, now_end, begin, end;
            system("cls");
            printf("\n\n\n\n\n\t\t\t\t***********************************\n");
            printf("\t\t\t\t***          �������֤             ***\n");
            printf("\t\t\t\t***         ���뵱ǰʱ��            ***\n");
            printf("\t\t\t\t***        �������ʱ��           ***\n");
            printf("\t\t\t\t***         ���붨������            ***\n");
            printf("\t\t\t\t***     ���뷵����һ��������0       ***\n");
            printf("\t\t\t\t***             ����                ***\n");
            printf("\t\t\t\t***       513920155840215874        ***\n");
            printf("\t\t\t\t***           2019 4 5              ***\n");
            printf("\t\t\t\t***           2018 4 5              ***\n");
            printf("\t\t\t\t***              3��                ***\n");
            scanf("%s", id);//�����˺�
            if (!strcmp(id, "0")) return 2;
            printf("\t\t\t\t***          ���֤����ɹ�         ***\n");
            printf("\t\t\t\t***          �����뵱ǰ����         ***\n");
            /*scanf("%d %d %d", &now.year, &now.month, &now.day);//��ǰʱ��    ���������ļ���������
            scanf("%d %d %d", &now_begin.year, &now_begin.month, &now_begin.day);
            scanf("%d %d %d", &now_end.year, &now_end.month, &now_end.day);//��Ϊһ�����֤�ܴ������ڣ���Ҫ�Ա�ʱ��*/
            in_date(&now);
            printf("\t\t\t\t***            ������ʼʱ��         ***\n");
            in_date(&now_begin);
            printf("\t\t\t\t***            ����������         ***\n");
            //in_date(&now_end);   ����Ϊ�������
            char len[50];
            scanf("%s", len);
            deadline(now_begin, len, &now_end);
            while (1)//���˺Ų��ҵ�ѭ��,ͬʱ�Ա�ʱ��      ��ʵ����ʼʱ��ͽ�ֹʱ��
            {
                int flag = 0;//�жϽ����� �Ƿ��ҵ��˺�
                rewind(fp);//���ļ�ָ�������
                while (fscanf(fp, "%s ���%lf ʱ��%d %d %d ��%d %d %d\n", realid, &realmoney, &begin.year, &begin.month, &begin.day, &end.year, &end.month, &end.day) != EOF)
                {
                    if (!strcmp(id, realid))//�ļ����и�����
                    {
                        flag = check_date_same(now_begin, begin, now_end, end);//flag=1���ǲ鵽��
                        if (flag == 1) break;//��flag==0 ����������
                    }
                }
                if (flag == 1) break;//�ҵ��˻���
                else
                {
                    printf("\t\t\t\t***          �����ڶ�Ӧ��Ϣ         ***\n");
                    printf("\t\t\t\t***       �������������������      ***\n");
                    printf("\t\t\t\t***          �������֤             ***\n");
                    printf("\t\t\t\t***        �������ʱ��           ***\n");
                    printf("\t\t\t\t***        ���붨�ڽ���ʱ��         ***\n");
                    printf("\t\t\t\t***             ����                ***\n");
                    printf("\t\t\t\t***       513920155840215874        ***\n");
                    printf("\t\t\t\t***           2018 4 5              ***\n");
                    printf("\t\t\t\t***           2019 4 5              ***\n");
                    printf("\t\t\t\t***         ����ҵ���������0       ***\n");
                }
                scanf("%s", id);
                if (!strcmp(id, "0"))break;
                scanf("%d %d %d", &now_begin.year, &now_begin.month, &now_begin.day);
                scanf("%d %d %d", &now_end.year, &now_end.month, &now_end.day);//��Ϊһ�����֤�ܴ������ڣ���Ҫ�Ա�ʱ��
                system("cls");
            }
            if (!strcmp(id, "0"))return 2;//����ҵ�����
            /////////////////////���������Ƕ�ȡ�����ȷ��
            if (check_date(now, end))//�ж��Ƿ�ﵽ���ʱ��   1�� 0û��    �����ǵ�
            {
                int cout = dif_date(begin, end);//��¼������ͣ��Ƕ����� �����ֱ�����Ϣ����30 90 180
                int real_cout = dif_date(begin, now);//����ʵ�ʵ�����
                realmoney = get_realmoney(realmoney, cout, real_cout);//
                printf("\t\t\t\t***           ��Ĵ���          ***\n");
                printf("\t\t\t\t            ���д��%.2lf          \n", realmoney);//������Ϣ�ı���
                printf("\t\t\t\t***            ȡ��ɹ�             ***\n");//����ȡ���ɹ�����������δ��ȫȡ����תΪ����
                del_data(id, begin, end);/**********������תΪ��һ���ļ�������ɾ��regular�ļ����е�����*********/
                printf("\t\t\t\t***         ������ȡ������1         ***\n");
                printf("\t\t\t\t***        ����ҵ���������2        ***\n");
                printf("\t\t\t\t***         ������������0           ***\n");
                char key2[100];// 
                while (1)
                {
                    scanf("%s", key2);
                    system("cls");
                    if (!strcmp(key2, "1")) break;
                    if (!strcmp(key2, "2")) break;
                    if (!strcmp(key2, "0")) break;
                    printf("\n\n\n\n\n\t\t\t\t***       ���������������        ***\n");
                    printf("\t\t\t\t***         ������ȡ������1         ***\n");
                    printf("\t\t\t\t***        ����ҵ���������2        ***\n");
                    printf("\t\t\t\t***         ������������0           ***\n");
                }
                if (!strcmp(key2, "1")) continue;
                if (!strcmp(key2, "2")) return 2;
                if (!strcmp(key2, "0")) exit(0);
            }
            else//���û����
            {
                printf("\t\t\t\t***            ���δ����           ***\n");
                printf("\t\t\t\t***         �������ȡ������1       ***\n");
                printf("\t\t\t\t***        ��������һ��������2      ***\n");
                printf("\t\t\t\t***         ������������0           ***\n");
                char key[100];
                while (1)
                {
                    scanf("%s", key);
                    system("cls");
                    if (!strcmp(key, "1")) break;
                    if (!strcmp(key, "2")) break;
                    if (!strcmp(key, "0")) break;
                    printf("\n\n\n\n\n\t\t\t\t***       ���������������        ***\n");
                    printf("\t\t\t\t***          ����ȡ������1          ***\n");
                    printf("\t\t\t\t***        ����ҵ���������2        ***\n");
                    printf("\t\t\t\t***         ������������0           ***\n");
                }
                if (!strcmp(key, "2")) return 2;
                if (!strcmp(key, "0")) exit(0);
                int real_cout = dif_date(begin, now);//����ʵ�ʵ�����
                for (int i = 1; i <= real_cout; i++)
                {
                    realmoney = realmoney * (1 + Get_interest_ava());
                }
                printf("\t\t\t\t          ���д��%.2lf          \n", realmoney);//������Ϣ�ı���
                printf("\t\t\t\t***            ȡ��ɹ�             ***\n");//����ȡ���ɹ�����������δ��ȫȡ����תΪ����
                del_data(id, begin, end);/**********������תΪ��һ���ļ�������ɾ��regular�ļ����е�����*********/
                printf("\t\t\t\t***         ������ȡ������1         ***\n");
                printf("\t\t\t\t***        ����ҵ���������2        ***\n");
                printf("\t\t\t\t***         ������������0           ***\n");
                char key2[100];//�жϽ������Ĳ���
                while (1)
                {
                    scanf("%s", key2);
                    system("cls");
                    if (!strcmp(key2, "1")) break;
                    if (!strcmp(key2, "2")) break;
                    if (!strcmp(key2, "0")) break;
                    printf("\n\n\n\n\n\t\t\t\t***       ���������������        ***\n");
                    printf("\t\t\t\t***         ������ȡ������1         ***\n");
                    printf("\t\t\t\t***        ����ҵ���������2        ***\n");
                    printf("\t\t\t\t***         ������������0           ***\n");
                }
                if (!strcmp(key2, "1")) continue;
                if (!strcmp(key2, "2")) return 2;
                if (!strcmp(key2, "0")) exit(0);

            }
            fclose(fp);
        }
        else if (!strcmp(key, "0")) return 2;//������һ����
        else printf("\t\t\t\t***            �������             ***\n\n");
    }
}
void  change_state(char* id, int a)//a��Ҫ��state�ĳɵ�ֵ���ú���ֱ�Ӷ����ļ�����   ��һ���ǿ��ţ��ڶ�����Ҫ�޸ĳɵ�ֵ�����㶳��ⶳһ�����
{
    FILE* fp = fopen("Account.txt", "r+");
    struct Account* user = (struct Account*)malloc(sizeof(struct Account));
    while (fscanf(fp, "%s %s %s %s %lf %lld %lf %d %d\n", user->name, user->sex, user->id, user->password, &user->amount, &user->idcard, &user->interest, &user->state, &user->kind) != EOF)
    {
        if (!strcmp(user->id, id))
        {
            fseek(fp, -5, SEEK_CUR); //�ع�ָ����stateǰ
            fprintf(fp, "%d", a);//���ļ��У���state�ı䡣 state���ո�,kind,\,n 5��λ�á�
            break;
        }
    }
    fclose(fp);
}
int Admin_freeze(struct Account* head)//���ắ��,������search_id()���ң��ı�ֵ�����������������ֵ��  0���� 1����
{
    //������Ҫ��search����
    char id[200], key[200];
    while (1)
    {
        printf("\t\t\t\t***       ������һ��������0     *** \n");
        scanf("%s", id);
        if (!strcmp(id, "0")) return 2;
        struct Account* cout = Search_id(head, id);
        if (cout != NULL)
        {
            cout->state = 0;
            printf("\t\t\t\t***          ����ɹ�           ***\n\n");
            ///////�����������ļ��ڵ�ֵ
            change_state(id, 0);
        }//����
        else printf("\t\t\t\t***         �����ڸ��û�        ***\n\n");
        while (1)
        {
            printf("\t\t\t\t***       ���������ᣬ����1     ***\n");
            printf("\t\t\t\t***     ����������ҵ������2   ***\n");
            printf("\t\t\t\t***         ������������0       ***\n");
            scanf("%s", key);
            system("cls");
            if (!strcmp(key, "1"))
            {
                printf("\n\n\n\n\n\t\t\t\t***********************************\n");
                break;
            }
            if (!strcmp(key, "2")) return 2;
            if (!strcmp(key, "0")) exit(0);
            else printf("\t\t\t\t***     �����������������    ***\n\n");
        }
    }
}
int Admin_unfreeze(struct Account* head)//���˺Žⶳ��������search_id()���ң��ı�ֵ���ı�������������ֵ��
{
    char id[200], key[200];//key�ж��û���������ʲô���˳����������򷵻���һ����
    while (1)
    {
        printf("\t\t\t\t***          �������˺�         *** \n");
        printf("\t\t\t\t***       ������һ��������0     *** \n");
        scanf("%s", id);
        if (!strcmp(id, "0")) return 2;
        struct Account* cout = Search_id(head, id);
        if (cout != NULL)
        {
            cout->state = 1;
            printf("\t\t\t\t***          �ⶳ�ɹ�           ***\n\n");
            change_state(id, 1);
            FILE* fp = fopen("limit.txt", "r+");
            char realid[50];//����
            double limit_real, limit;//���ڵĶ��,������ޣ�
            if (cout->kind == 0)//���ÿ���ȸ�ԭ
            {
                int r = 0;//�ж��������ڵڼ���
                char temp_id[200];
                double temp_limit_real, temp_limit;//ûʲô����ֻ�� ������ݵĵ�ַ
                while (fscanf(fp, "%s%lf%lf", realid, &limit_real, &limit) != EOF)//ѭ����������
                {
                    if (!strcmp(id, realid))//�����ҵ���
                    {
                        break;
                    }
                    r++;//ÿ��һ�� �ͼ�һ
                }
                rewind(fp);
                for (int i = 0; i < r; i++)//r����Ҫѭ�����ٴβ��ܵ�Ŀ������
                {
                    fscanf(fp, "%s%lf%lf", temp_id, &temp_limit_real, &temp_limit);//�����ļ�ָ���Զ�����
                }
                fprintf(fp, "%s %lf %lf", realid, limit, limit);//����ԭ����
                fclose(fp);
            }
        }//�ⶳ
        else printf("\t\t\t\t***         �����ڸ��û�        ***\n\n"); \
            while (1)
            {
                printf("\t\t\t\t***       �������ⶳ������1     ***\n");
                printf("\t\t\t\t***     ����������ҵ������2   ***\n");
                printf("\t\t\t\t***         ������������0       ***\n");
                scanf("%s", key);
                system("cls");
                if (!strcmp(key, "1"))
                {
                    printf("\n\n\n\n\n\t\t\t\t***********************************\n");
                    break;
                }
                if (!strcmp(key, "2")) return 2;
                if (!strcmp(key, "0")) exit(0);
                else printf("\t\t\t\t***     �����������������    ***\n\n");
            }
    }

}
int Admin_change_interest()//������Ϣ,�ļ����޸�
{
    char key[200];
    double ava, dea_3month, dea_6month, dea_1year, dea_2year, dea_3year, dea_5year;//���
    double nowinterest;
    while (1)
    {
        FILE* fp = fopen("Admin.txt", "r+");
        char* array;//��̬�ڴ����
        array = (char*)malloc(100 * sizeof(char));
        printf("\t\t\t\t***       �����Ļ�����������1   *** \n");
        printf("\t\t\t\t***       �����Ķ�����������2   *** \n");
        printf("\t\t\t\t***        ������һ��������0    *** \n");
        scanf("%s", key);
        if (!strcmp(key, "0")) return 2;
        if (!strcmp(key, "1"))
        {
            printf("\t\t\t\t***       ���������ڵ���Ϣֵ   *** \n");//����ȫ�����뵽�ڴ棬��������ļ�������
            scanf("%lf", &nowinterest);
            fscanf(fp, "%s\n%lf %lf", array, &ava, &dea_3month);
            rewind(fp);
            fprintf(fp, "%s\n%lf %lf", array, nowinterest, dea_3month);
            fclose(fp);
            free(array);//�ͷ��ڴ�
            ////�жϽ������Ĳ���
            while (1)
            {
                printf("\t\t\t\t***       �����޸���������1    ***\n");
                printf("\t\t\t\t***       ������һ��������2    ***\n");//�ж��û����룬���Ծ�ѭ������Ҫ��ԷǷ�����
                printf("\t\t\t\t***         ������������0       ***\n");
                scanf("%s", key);
                system("cls");
                if (!strcmp(key, "1"))
                {
                    printf("\n\n\n\n\n\t\t\t\t***********************************\n");
                    break;
                }
                if (!strcmp(key, "2")) return 2;
                if (!strcmp(key, "0")) exit(0);
                else printf("\t\t\t\t***     �����������������    ***\n\n");
            }
        }
        if (!strcmp(key, "2"))////////////////////////////����ͨ�������ļ������ݴӶ��޸ġ�����Ϊ��Ϣ�ǰ������µļ��㣬���Բ���Ҫ����ԭ����
        {
            char* array;
            array = (char*)malloc(100 * sizeof(char));
            printf("\t\t\t\t*** �����޸�3���µ���Ϣ������1 *** \n");
            printf("\t\t\t\t*** �����޸�6���µ���Ϣ������2 *** \n");
            printf("\t\t\t\t***  �����޸�1�����Ϣ�� ����3  *** \n");
            printf("\t\t\t\t***  �����޸�2�����Ϣ�� ����4  *** \n");
            printf("\t\t\t\t***  �����޸�3�����Ϣ�� ����5  *** \n");
            printf("\t\t\t\t***  �����޸�5�����Ϣ�� ����6  *** \n");
            char key2[20];
            scanf("%s", key2);
            if (!strcmp(key2, "1"))//////////////�޸������µ���Ϣ
            {
                printf("\t\t\t\t***       ���������ڵ���Ϣֵ   *** \n");
                scanf("%lf", &nowinterest);
                fscanf(fp, "%s\n%lf %lf", array, &ava, &dea_3month);
                rewind(fp);
                fprintf(fp, "%s\n%lf %lf", array, ava, nowinterest);
                fclose(fp);
                free(array);
                while (1)
                {
                    printf("\t\t\t\t***       �����޸���������1    ***\n");
                    printf("\t\t\t\t***       ������һ��������2    ***\n");
                    printf("\t\t\t\t***         ������������0       ***\n");
                    scanf("%s", key);
                    system("cls");
                    if (!strcmp(key, "1")) break;
                    if (!strcmp(key, "2")) return 2;
                    if (!strcmp(key, "0")) exit(0);
                    else printf("\t\t\t\t***     �����������������    ***\n\n");
                }
            }
            if (!strcmp(key2, "2"))//////////////�޸�6���µ���Ϣ
            {
                printf("\t\t\t\t***       ���������ڵ���Ϣֵ   *** \n");
                scanf("%lf", &nowinterest);
                fscanf(fp, "%s\n%lf %lf %lf", array, &ava, &dea_3month, &dea_6month);
                rewind(fp);
                fprintf(fp, "%s\n%lf %lf %lf", array, ava, dea_3month, nowinterest);
                fclose(fp);
                free(array);
                while (1)
                {
                    printf("\t\t\t\t***       �����޸���������1    ***\n");
                    printf("\t\t\t\t***       ������һ��������2    ***\n");
                    printf("\t\t\t\t***         ������������0       ***\n");
                    scanf("%s", key);
                    system("cls");
                    if (!strcmp(key, "1")) break;
                    if (!strcmp(key, "2")) return 2;
                    if (!strcmp(key, "0")) exit(0);
                    else printf("\t\t\t\t***     �����������������    ***\n\n");
                }
            }
            if (!strcmp(key2, "3"))//////////////�޸�1�����Ϣ
            {
                printf("\t\t\t\t***       ���������ڵ���Ϣֵ   *** \n");
                scanf("%lf", &nowinterest);
                fscanf(fp, "%s\n%lf %lf %lf %lf", array, &ava, &dea_3month, &dea_6month, &dea_1year);
                rewind(fp);
                fprintf(fp, "%s\n%lf %lf %lf %lf", array, ava, dea_3month, dea_6month, nowinterest);
                fclose(fp);
                free(array);
                while (1)
                {
                    printf("\t\t\t\t***       �����޸���������1    ***\n");
                    printf("\t\t\t\t***       ������һ��������2    ***\n");
                    printf("\t\t\t\t***         ������������0       ***\n");
                    scanf("%s", key);
                    system("cls");
                    if (!strcmp(key, "1")) break;
                    if (!strcmp(key, "2")) return 2;
                    if (!strcmp(key, "0")) exit(0);
                    else printf("\t\t\t\t***     �����������������    ***\n\n");
                }
            }
            if (!strcmp(key2, "4"))//////////////�޸�2�����Ϣ
            {
                printf("\t\t\t\t***       ���������ڵ���Ϣֵ   *** \n");
                scanf("%lf", &nowinterest);
                fscanf(fp, "%s\n%lf %lf %lf %lf %lf ", array, &ava, &dea_3month, &dea_6month, &dea_1year, &dea_2year);
                rewind(fp);
                fprintf(fp, "%s\n%lf %lf %lf %lf %lf ", array, ava, dea_3month, dea_6month, dea_1year, nowinterest);
                fclose(fp);
                free(array);
                while (1)
                {
                    printf("\t\t\t\t***       �����޸���������1    ***\n");
                    printf("\t\t\t\t***       ������һ��������2    ***\n");
                    printf("\t\t\t\t***         ������������0       ***\n");
                    scanf("%s", key);
                    system("cls");
                    if (!strcmp(key, "1")) break;
                    if (!strcmp(key, "2")) return 2;
                    if (!strcmp(key, "0")) exit(0);
                    else printf("\t\t\t\t***     �����������������    ***\n\n");
                }
            }
            if (!strcmp(key2, "5"))//////////////�޸�3�����Ϣ
            {
                printf("\t\t\t\t***       ���������ڵ���Ϣֵ   *** \n");
                scanf("%lf", &nowinterest);
                fscanf(fp, "%s\n%lf %lf %lf %lf %lf ", array, &ava, &dea_3month, &dea_6month, &dea_1year, &dea_2year, &dea_3year);
                rewind(fp);
                fprintf(fp, "%s\n%lf %lf %lf %lf %lf", array, ava, dea_3month, dea_6month, dea_1year, dea_2year, nowinterest);
                fclose(fp);
                free(array);
                while (1)
                {
                    printf("\t\t\t\t***       �����޸���������1    ***\n");
                    printf("\t\t\t\t***       ������һ��������2    ***\n");
                    printf("\t\t\t\t***         ������������0       ***\n");
                    scanf("%s", key);
                    system("cls");
                    if (!strcmp(key, "1")) break;
                    if (!strcmp(key, "2")) return 2;
                    if (!strcmp(key, "0")) exit(0);
                    else printf("\t\t\t\t***     �����������������    ***\n\n");
                }
            }
            if (!strcmp(key2, "6"))//////////////�޸�5�����Ϣ
            {
                printf("\t\t\t\t***       ���������ڵ���Ϣֵ   *** \n");
                scanf("%lf", &nowinterest);
                fscanf(fp, "%s\n%lf %lf %lf %lf %lf %lf %lf", array, &ava, &dea_3month, &dea_6month, &dea_1year, &dea_2year, &dea_3year, &dea_5year);
                rewind(fp);
                fprintf(fp, "%s\n%lf %lf %lf %lf %lf %lf %lf", array, ava, dea_3month, dea_6month, dea_1year, dea_2year, dea_3year, nowinterest);
                fclose(fp);
                free(array);
                while (1)
                {
                    printf("\t\t\t\t***       �����޸���������1    ***\n");
                    printf("\t\t\t\t***       ������һ��������2    ***\n");
                    printf("\t\t\t\t***         ������������0       ***\n");
                    scanf("%s", key);
                    system("cls");
                    if (!strcmp(key, "1")) break;
                    if (!strcmp(key, "2")) return 2;
                    if (!strcmp(key, "0")) exit(0);
                    else printf("\t\t\t\t***     �����������������    ***\n\n");
                }
            }
        }
    }
}
int Admin_creat_account(struct Account* head)//��������������һ���µĿ���
{
    while (1)
    {
        printf("\t\t\t***�������������Ա����룬�������� �Լ����֤ ***\n\n");
        printf("\t\t\t\t***     ��ע������Ϊ6λ����       ***\n");
        printf("\t\t\t***    ���磺���� �� 123456 ���ÿ�  513125200104151875***\n");
        printf("\t\t\t***    ���磺���� Ů 123456 ���  513987500145875120***\n\n");
        printf("\t\t\t\t***      ���뷵������0            ***\n");
        char* name = (char*)malloc(20 * sizeof(char));/////���и���ռ䣬���ں����������
        char* sex = (char*)malloc(20 * sizeof(char));
        char* pin = (char*)malloc(20 * sizeof(char));
        char* kind = (char*)malloc(20 * sizeof(char));
        char* id = (char*)malloc(21 * sizeof(char));
        char* idcard = (char*)malloc(20 * sizeof(char));
        double amount = 0, interest = 0;
        int realkind = -1, state = 1;//Ĭ�Ͽ��ã��Ƕ���
        scanf("%s", name);
        if (!strcmp(name, "0")) return 2;
        scanf("%s %s %s %s", sex, pin, kind, idcard);
        if (!strcmp(kind, "���ÿ�")) realkind = 0;
        if (!strcmp(kind, "���")) realkind = 1;
        while (strcmp(sex, "��") && strcmp(sex, "Ů"))//���Ա�Ϊ�У����Ҳ�ΪŮ
        {
            printf("\t\t\t\t***    �Ա�������������������Ա� ***\n");
            scanf("%s", sex);
        }
        while (strlen(pin) != 6 || check_integer(pin) != 1)//������λ����Ϊ6�����߲�������    1������ 0��������
        {
            printf("\t\t\t\t***    ������������������������� ***\n");
            printf("\t\t\t\t***     ��ע�⣬����Ϊ6Ϊ����       ***\n");
            scanf("%s", pin);
        }
        while (strcmp(kind, "���ÿ�") && strcmp(kind, "���"))//�����಻�����ÿ������Ҳ�Ϊ���
        {
            printf("\t\t\t\t***    ��������������������뿨�� ***\n");
            scanf("%s", kind);
            if (!strcmp(kind, "���ÿ�")) realkind = 0;
            if (!strcmp(kind, "���")) realkind = 1;
        }
        while (check_integer(idcard) == 0 || strlen(idcard) != 18)//�Ƿ����� ���֤λ�����ԣ�ǰ17λ����ȫ����
        {
            printf("\t\t\t\t***     ���֤�����������������  ***\n");
            printf("\t\t\t\t***      ע�⣬���֤Ϊ18λ����     ***\n");
            scanf("%s", idcard);
        }
        printf("\t\t\t\t***         �����ϸ��Ϣ����        ***\n");
        printf("\t\t\t***    %s %s %s %s  %s    ***\n", name, sex, pin, kind, idcard);
        printf("\t\t\t\t***         ȷ����������1         ***\n");
        printf("\t\t\t\t***         ���������1��ֵ         ***\n");
        char key[100];
        scanf("%s", key);
        if (!strcmp(key, "1"))//����������п���
        {
            strcpy(id, "6221");//���п���
            srand((unsigned)time(NULL));//���� �����������
            for (int i = 4; i < 19; i++)
            {
                int x = rand() % 9;
                id[i] = x + '0';/*����9���ڵ��������*/
            }
            id[19] = '\0';
        }
        else continue;//����
        system("cls");////////////////////����
        printf("\n\n\n\n\n\t\t\t\t***************************************\n");
        printf("\t\t\t\t***************************************\n");
        printf("\t\t\t\t***         ���п������ɹ�          ***\n");
        printf("\t\t\t\t***       ������п���Ϣ���£�          \n");
        long long real_idcard = atoll(idcard);;
        printf("����     �Ա�\t  ����\t\t    ����     ���\t\t   ���֤            ��Ϣ            ״̬  ���\n");//��ʽ//������ʽ,������û�ȷ��
        printf("%-9s %s %s   %-8s %-14.2lf %-25lld %-14.2lf  ", name, sex, id, pin, amount, real_idcard, interest);
        //printf("%-9s %s %s   %-8s %-14.2lf %-25lld %-14.2lf  ", p->name, p->sex, p->id, p->password, p->amount, p->idcard, p->interest);
        if (state == 0) printf("���� ");//����֮ǰ�������ʽ�����������ȥ�ж�
        else printf("���� ");
        if (realkind == 0)  printf("���ÿ�\n\n\n\n");
        else printf("���\n\n\n\n");
        FILE* fp = fopen("Account.txt", "r+");//�����ļ�ָ�룬׼�����¿������˻����뵽�ļ�
        fseek(fp, 0, SEEK_END);//�ҵ��ļ�ĩβ
        state = 1;
        fprintf(fp, "%s %s %s %s %lf %lld %lf %d %d\n", name, sex, id, pin, amount, real_idcard, interest, state, realkind);//�����ļ�
        if (realkind == 0)//��Ϊ���ÿ� ��ȸ�Ϊ1000
        {
            double limit = 1000;
            FILE* temp = fopen("limit.txt", "a+");//�������ļ�
            fprintf(temp, "%s %lf %lf\n", id, limit, limit);//��ʼ���1000��Ǯ
            fclose(temp);
        }
        struct Account* temp = (struct Account*)malloc(sizeof(struct Account)), * cout = head;//׼����������
        temp->next = NULL;//����β���null
        if (head == NULL)head = temp;
        strcpy(temp->name, name), strcpy(temp->sex, sex), strcpy(temp->id, id), strcpy(temp->password, pin), temp->amount = amount;
        temp->idcard = real_idcard, temp->interest = interest, temp->state = state, temp->kind = realkind;
        while (cout != NULL && cout->next != NULL && (cout->kind == 1 || cout->kind == 0))
        {
            cout = cout->next;//�����ƶ�
        }
        if (cout != NULL)cout->next = temp;//�������
        free(name), free(sex), free(pin), free(kind), free(id), free(idcard);///////////�ͷ�����
        while (1)//�жϺ�������
        {
            char key2[100];
            printf("\t\t\t\t***          ��������������1        ***\n");
            printf("\t\t\t\t***        ������һ���棬����2      ***\n");
            printf("\t\t\t\t***           ������������0         ***\n");
            scanf("%s", key);
            system("cls");
            if (!strcmp(key, "1"))
            {
                printf("\n\n\n\n\n");
                break;
            }
            if (!strcmp(key, "2"))return 2;
            if (!strcmp(key, "0"))exit(0);
            printf("\t\t\t\t***        �������,��������        ***\n");
        }
    }

}
int Admin_closs_account(struct Account* head)//���������ļ�����ֱ������
{
    while (1)
    {
        printf("\t\t\t\t***           �����뿨��            ***\n");
        printf("\t\t\t\t***       ������һ��������-1        ***\n");
        char* id = (char*)malloc(25 * sizeof(char));//��̬����
        scanf("%s", id);
        if (!strcmp(id, "-1"))return 2;
        printf("\t\t\t\t***            ��ȷ��               ***\n");
        printf("\t\t\t\t***         ����������1           ***\n");
        printf("\t\t\t\t***           ��������0             ***\n");
        char key[100];
        scanf("%s", key);
        system("cls");
        while (strcmp(key, "1") && strcmp(key, "0"))
        {
            printf("\n\n\n\n\n\t\t\t\t***       ���������������    ***\n");
            printf("\t\t\t\t***         ����������1           ***\n");
            printf("\t\t\t\t***           ��������0             ***\n");
            scanf("%s", key);
        }
        if (!strcmp(key, "1"))//���ٹ���
        {
            struct Account* p = Search_id(head, id);//����ָ�� 
            if (p == NULL)
            {
                printf("\n\n\n\n\n\t\t\t\t***          ���Ų�����             ***\n");
                printf("\t\t\t\t***         ���������뿨��          ***\n\n"); \
                    continue;
            }
            delete_account(head, p);//����ɾ��p�ڵ�,��fundmentͷ�ļ� ֱ���γɽ��������     �ɸ�������ڵ㣬�����������ļ����Ӷ��޸�
            printout_new(head);//�����ļ�
            free(id);
            printf("\n\n\n\n\n\t\t\t\t***           ���ٳɹ�              ***\n");
            printf("\t\t\t\t***      ����������һ����           ***\n");
            system("pause");
            return 2;
        }
        if (!strcmp(key, "0"))
        {
            free(id);
            printf("\n\n\n\n\n\t\t\t\t***        �������٣�����1          ***\n");
            printf("\t\t\t\t***      ������һ���棬����2        ***\n");
            printf("\t\t\t\t***           ������������0         ***\n");
            scanf("%s", key);
            system("cls");
            while (strcmp(key, "1") && strcmp(key, "0") && strcmp(key, "2"))
            {
                printf("\t\t\t\t***        ���������������       ***\n");
                scanf("%s", key);
            }
            if (!strcmp(key, "1"))
            {
                printf("\n\n\n\n\n");
                continue;
            }
            if (!strcmp(key, "2")) return 2;
            if (!strcmp(key, "0")) exit(0);
        }
    }
}
int Admin_find_account(head)//��ѯ���֤ �ô��ļ��в�ѯ
{
    FILE* fp = fopen("regular.txt","r+" );//���ļ�
    printf("\t\t\t\t***         ���������֤            ***\n");
    printf("\t\t\t\t***         ���뷵������0           ***\n");
    char idcard[30];
    scanf("%s", idcard);//�����ѯ�����֤
    if(!strcmp(idcard,"0"))return 2;//������һ����
    while (check_integer(idcard) == 0 || strlen(idcard) != 18)//�Ƿ����� ���֤λ�����ԣ�ǰ17λ����ȫ����
    {
        printf("\t\t\t\t***     ���֤�����������������  ***\n");
        printf("\t\t\t\t***      ע�⣬���֤Ϊ18λ����     ***\n");
        scanf("%s", idcard);
    }
    char temp[130];//������ļ����ҵ�����Ϣ��idcard��
    char ans[200];//��ź�����ʱ�����Ϣ �ȴ����
    int sum = 0;//��ʱ�� �۲��ҵ�û��
    printf("\t\t\t\t***      ע�⣬���֤Ϊ18λ����     ***\n");
    printf("\t\t\t\t***        �����Ǹ����֤�����Ϣ   ***\n");
    while (fscanf(fp, "%s", temp) != EOF)
    {
        fgets(ans, 100, fp);//���������ݶ���ans����
        if (!strcmp(idcard, temp))
        {
            printf("\t\t\t\t%s\n", ans);
            sum++;
        }
    }
    if (sum == 0) printf("\t\t\t\t***           �����֤���޴��      ***\n");//��û�ҵ��˻�ʱ
    printf("\t\t\t\t***        ���򽫷�����һ����       ***\n");
    system("pause");
    return 2;
}
int Admin_business(FILE* fp, struct Account* head)//�û��ļ���������
{

    int key, key2 = 2;//key�������ֵ�����ж��û�ִ����һ��������������ʲô  key2����ҳ�淵��ֵ��ſռ䣬�ж��Ƿ��˳�
    while (key2 == 2)
    {
        key = Admin_business_menu();
        if (key == -1)return 1;//������һ����
        if (key == 1) Admin_save_withdraw_regular_new();//////��ȡ��
        if (key == 2) key2 = Admin_unfreeze(head);//�ⶳ
        if (key == 3) key2 = Admin_freeze(head);//����
        if (key == 4) key2 = Admin_change_interest();//key2==0 �˳�����ȫ������ key2==2 ����ҵ�� 
        if (key == 5) key2 = Admin_creat_account(head);//����
        if (key == 6) key2 = Admin_closs_account(head);//����
        if (key == 7)key2 = Admin_find_account(head);
        if (key2 == 0) return 3;
        system("cls");
    }
}
int change_admin_pin()//�ı����Ա����
{
    FILE* fp = fopen("Admin.txt", "r+");
    while (1)
    {
        printf("\t\t\t\t\t***    ����������       ***\n");
        printf("\t\t\t\t\t** ��ע�����벻�ó���20λ**\n");
        printf("\t\t\t\t\t***    ��������0        ***\n");
        char pin[200], check[200];
        scanf("%s", pin);
        if (!strcmp(pin, "0"))
        {
            fclose(fp);
            return 1;//������һ���� key==1
        }
        while (strlen(pin) > 20)//λ������20
        {
            printf("\t\t\t\t\t** ��ע�����벻�ó���20λ**\n");
            printf("\t\t\t\t\t**         ����������    **\n");
            scanf("%s", pin);
        }
        printf("\t\t\t\t\t    �����������%s \n", pin);
        printf("\t\t\t\t\t*** ȷ����������  yes   ***\n");
        printf("\t\t\t\t\t***   ������������ֵ\n");
        scanf("%s", check);
        if (!strcmp(check, "yes"))//ȷ������
        {
            fprintf(fp, "%-20s", pin);//���뵽�ļ�
            printf("\t\t\t\t\t***     ���ĳɹ�    ***\n");
            printf("\t\t\t\t\t��������ֵ������һ���� \n");
            system("pause");
            fclose(fp);
            return 1;//������һ����
        }
        else
        {
            system("cls");

        }
    }
}