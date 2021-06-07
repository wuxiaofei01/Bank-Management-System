#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include "fundment.h"
void out_all(struct Account* stu)// ***输出链表,将链表所有数据都输出
{
    struct Account* p, * end;
    // for (end = stu; end->next != NULL; end = end->next)//找到尾指针
     //stu=mysort(stu, end);
    printf("姓名     性别\t  卡号\t\t    密码     存款\t\t   身份证            利息            状态  类别\n");
    for (p = stu; p != NULL; p = p->next) {
        printf("%-9s %s %s   %-8s %-14.2lf %-25lld %-14.2lf  ", p->name, p->sex, p->id, p->password, p->amount, p->idcard, p->interest);
        if (p->state == 0) printf("冻结 ");
        else printf("可用 ");
        if (p->kind == 0)printf("信用卡\n");
        else printf("储蓄卡\n");
    }
}
void out_sex_nan(struct Account* stu)//输出男性，将链表中男性的数据输出
{
    struct Account* p;
    int sum = 0;
    printf("姓名     性别\t  卡号\t\t    密码     存款\t\t   身份证            利息            状态  类别\n");
    for (p = stu; p != NULL; p = p->next)
    {
        if (strcmp(p->sex, "男") == 0)
        {
            printf("%-9s %s %s   %-8s %-14.2lf %-25lld %-14.2lf  ", p->name, p->sex, p->id, p->password, p->amount, p->idcard, p->interest);
            if (p->state == 0) printf("冻结 ");
            else printf("可用 ");
            if (p->kind == 0)printf("信用卡\n");
            else printf("储蓄卡\n");
            sum++;
        }
    }
    if (sum == 0) printf("\t\t\t\t\t***不存在该类型用户\t\t\t\t\t\n\n\n\n");
}
void out_sex_nv(struct Account* stu)//输出女性
{
    struct Account* p;
    int sum = 0;
    printf("姓名     性别\t  卡号\t\t    密码     存款\t\t   身份证            利息            状态  类别\n");
    for (p = stu; p != NULL; p = p->next)
    {
        if (strcmp(p->sex, "女") == 0)
        {
            printf("%-9s %s %s   %-8s %-14.2lf %-25lld %-14.2lf  ", p->name, p->sex, p->id, p->password, p->amount, p->idcard, p->interest);
            if (p->state == 0) printf("冻结 ");
            else printf("可用 ");
            if (p->kind == 0)printf("信用卡\n");
            else printf("储蓄卡\n");
            sum++;
        }
    }
    if (sum == 0) printf("\t\t\t\t\t***不存在该类型用户\t\t\t\t\t\n\n\n\n");
}
void out_kind_0(struct Account* stu)//输出信用卡
{
    struct Account* p;
    int sum = 0;
    printf("姓名     性别\t  卡号\t\t    密码     存款\t\t   身份证            利息            状态  类别\n");
    for (p = stu; p != NULL; p = p->next)
    {
        if (p->kind == 0)
        {
            printf("%-9s %s %s   %-8s %-14.2lf %-25lld %-14.2lf  ", p->name, p->sex, p->id, p->password, p->amount, p->idcard, p->interest);
            if (p->state == 0) printf("冻结 ");
            else printf("可用 ");
            if (p->kind == 0)printf("信用卡\n");
            else printf("储蓄卡\n");
            sum++;
        }
    }
    if (sum == 0)  printf("\t\t\t\t\t***不存在该类型用户\t\t\t\t\t\n\n\n\n");
}
void out_kind_1(struct Account* stu)//储蓄卡
{
    struct Account* p;
    int sum = 0;
    printf("姓名     性别\t  卡号\t\t    密码     存款\t\t   身份证            利息            状态  类别\n");
    for (p = stu; p != NULL; p = p->next)
    {
        if (p->kind == 1)
        {
            printf("%-9s %s %s   %-8s %-14.2lf %-25lld %-14.2lf  ", p->name, p->sex, p->id, p->password, p->amount, p->idcard, p->interest);
            if (p->state == 0) printf("冻结 ");
            else printf("可用 ");
            if (p->kind == 0)printf("信用卡\n");
            else printf("储蓄卡\n");
            sum++;
        }
    }
    if (sum == 0)  printf("\t\t\t\t\t***不存在该类型用户\t\t\t\t\t\n\n\n\n");
}
//*******************************************************************************************************//整体是一个排序函数
struct Account* mysort(struct Account* head2)//传递头指针（节点）
{
    struct Account* head = (struct Account*)malloc(sizeof(struct Account)), * temp = head2;//统计有多少数据
    int i = 0;
    while (temp != NULL)//统计有多少个数据 复杂度n
    {
        i++;
        temp = temp->next;
    }
    head->next = head2;
    struct Account* pre, * cur, * next;
    while (i--)//冒泡排序
    {
        for (pre = head, cur = pre->next, next = cur->next; next != NULL; pre = pre->next, cur = cur->next, next = next->next)
        {
            if (cur->amount < next->amount)//节点交换，得用三个节点，前取后驱
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

/***************************************************************************************///管理员登录主页面
int Admin()
{
    char realpin[21], yourpin[210];//输入密码
    FILE* fp = fopen("Admin.txt", "r+");
    fscanf(fp, "%s", realpin);
    system("cls");
    printf("\n\n\n\n\n");
    printf("\t\t\t\t***请输入管理员密码,若想返回上一界面请输入0***\n");
    scanf("%s", yourpin);
    if (strcmp(realpin, yourpin) == 0)//代表密码正确
    {
        system("cls");
        return 1;
    }
    else if (strcmp(yourpin, "0") == 0)return 2;//回到上一界面
    else
    {
        printf("\t\t\t\t\t你的密码错误。\n");
        return 0;
    }//错误
}
/******************************************************************************************************//*菜单目录*/
int Admin_menu()//判断用户选择的是哪一个业务
{
    while (1)
    {
        printf("\t\t\t\t\t***************************\n");
        printf("\t\t\t\t\t***   办理业务请输入1   ***\n");
        printf("\t\t\t\t\t***   查询用户请输入2   ***\n");
        printf("\t\t\t\t\t*** 更改管理员密码输入3 ***\n");
        printf("\t\t\t\t\t***    文件备份输入4    ***\n");
        printf("\t\t\t\t\t**恢复上一次文件数据输入5**\n");
        printf("\t\t\t\t\t***  返回上一界面输入6  ***\n");
        printf("\t\t\t\t\t***     退出请输入0     ***\n");
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
        printf("\t\t\t\t\t***   请输入正确数字    ***\n\n");
    }
}
/*//****************************************************************************************************************//*登陆函数*/
void print_number(struct Account* head)
{
    long long total = 0, credit = 0, debit = 0;//总人数,信用卡人数，储蓄卡人数
    long long high = 0, mid = 0, low = 0;//高存款，中等，低
    struct Account* temp = head;
    while (temp != NULL)
    {
        total++;
        if (temp->kind == 0)credit++;//信用卡和储蓄卡
        else debit++;
        if (temp->amount >= 100000) high++;
        else if (temp->amount > 1000 && temp->amount < 100000) mid++;
        else if (temp->amount < 1000)low++;
        temp = temp->next;
    }
    printf("\t\t\t\t\t******************************************\n");
    printf("\t\t\t\t\t*** 当前银行用户有       ** %-10lld人**\n", total);
    printf("\t\t\t\t\t*** 信用卡用户有         ** %-10lld人**\n", credit);
    printf("\t\t\t\t\t*** 储蓄卡用户有         ** %-10lld人**\n", debit);
    printf("\t\t\t\t\t*** 存款金额100000以上有 ** %-10lld人**\n", high);
    printf("\t\t\t\t\t*** 存款金额1000-100000有** %-10lld人**\n", mid);
    printf("\t\t\t\t\t*** 存款金额 0-1000有    ** %-10lld人**\n", low);
    printf("\t\t\t\t\t******************************************\n");
    system("pause");
    system("cls");
}
void Admin_check_menu(struct Account *head)
{
    printf("\n\n\n\n\n\t\t\t\t************************************* \n");
    printf("\t\t\t\t***     打印所有成员名单输入1     *** \n");
    printf("\t\t\t\t***      若想查询卡号输入2        *** \n");
    printf("\t\t\t\t***      若想查询姓名输入3        *** \n");
    printf("\t\t\t\t***  若想打印所有男性账户请输入4  *** \n");
    printf("\t\t\t\t***  若想打印所有女性账户请输入5  *** \n");
    printf("\t\t\t\t***  若想打印所有信用卡账户输入6  *** \n");
    printf("\t\t\t\t***  若想打印所有储蓄卡用户输入7  *** \n");
    printf("\t\t\t\t***  若想返回到上一界面，请输入-1 *** \n");
    printf("\t\t\t\t************************************* \n");
}
int Admin_check(FILE* fp, struct Account* head)//得到文件头指针     查找函数的具体实现
{
    char k[201];
    while (1)
    {
        Admin_check_menu(head);//进入菜单
        scanf("%s", k);
        while (strcmp(k, "1") && strcmp(k, "2") && strcmp(k, "3") && strcmp(k, "4") && strcmp(k, "5") && strcmp(k, "6") && strcmp(k, "7") && strcmp(k, "-1"))
        {
            printf("\t\t\t\t*** 输入错误，请输入正确的数字   ***\n\n");//输入无效
            scanf("%s", k);
        }
        if (!strcmp(k, "-1"))return 1;//-1就是返回上一菜单
        struct Account* temp = 0;
        if (!strcmp(k, "1"))//退出界面
        {
            head = mysort(head);
            out_all(head);
            printf("\t\t\t\t\t***如果想退出程序请输入0***\n\t\t\t\t\t***返回上一界面输入非0值***\n");
            scanf("%s", k);
            system("cls");
            if (strcmp(k, "0") == 0) exit(0);
            continue;
        }//单行判断}

        if (!strcmp(k, "2"))//打印id
        {
            while (1)
            {
                printf("\t\t\t\t***           请输入卡号          ***\n");
                temp = head;//调用search函数，需要一个头指针
                char id[30];
                scanf("%s", id);
                struct Account* p;
                p = Search_id(temp, id);
                if (p != NULL) {//该函数找到了
                    printf("姓名     性别\t  卡号\t\t    密码     存款\t\t   身份证            利息            状态  类别\n");//格式
                    printf("%-9s %s %s   %-8s %-14.2lf %-25lld %-14.2lf  ", p->name, p->sex, p->id, p->password, p->amount, p->idcard, p->interest);
                    if (p->state == 0) printf("冻结 ");
                    else printf("可用 ");
                    if (p->kind == 0)printf("信用卡\n");
                    else printf("储蓄卡\n");
                }
                else printf("\t\t\t\t\t***查询不到该用户***\n");//查不到
                char key[201];//判断下一步操作
                printf("\t\t\t\t\t***若想退出程序请按0***\n\t\t\t\t\t***若想继续查询，请输入1***\n\t\t\t\t\t***若想返回上一界面输入2***\n");
                scanf("%s", key);
                system("cls");
                if (!strcmp(key, "1"))
                {
                    printf("\n\n\n\n\n");
                    continue;
                }
                if (!strcmp(key, "2")) break;//如上所示
                if (!strcmp(key, "0")) exit(0);
                while (1)//循环输入，用户的输入不对
                {

                    printf("\n\n\n\n\n\t\t\t\t\t输入无效，请输入0,1,2\n");
                    printf("\t\t\t\t\t***若想退出程序请按0***\n\t\t\t\t\t***若想继续查询，请输入1***\n\t\t\t\t\t***若想返回上一界面输入2***\n");
                    scanf("%s", key);
                    if (!strcmp(key, "1") || !strcmp(key, "0") || !strcmp(key, "2"))break;
                }
                system("cls");
                if (!strcmp(key, "1")) continue;//判断用户的接下来操作
                if (!strcmp(key, "2")) break;
                if (!strcmp(key, "0")) exit(0);
            }
        }
        if (!strcmp(k, "3"))//打印姓名
        {
            while (1)
            {
                printf("\t\t\t\t***           请输入姓名          ***\n");
                int sum = 0;//做一个变量，判断查询姓名找到没有,找到就加一，没找到就不加一
                temp = head;
                char name[30];
                scanf("%s", name);
                struct Account* p = head;//给赋个值，没什么意义，主要为了下面循环判断，多次查找              
                while (p != NULL)
                {
                    p = Search_name(p, name);
                    if (p != NULL) {
                        printf("姓名     性别\t  卡号\t\t    密码     存款\t\t   身份证            利息            状态  类别\n");//格式
                        printf("%-9s %s %s   %-8s %-14.2lf %-25lld %-14.2lf  ", p->name, p->sex, p->id, p->password, p->amount, p->idcard, p->interest);
                        if (p->state == 0) printf("冻结 ");
                        else printf("可用 ");
                        if (p->kind == 0)printf("信用卡\n");
                        else printf("储蓄卡\n");
                        p = p->next;//防止Search_name()函数无限循环
                        sum++;
                    }
                }
                if (sum == 0) printf("\t\t\t\t\t***没有该用户***\n");
                char key[50];//判断下一步操作
                printf("\t\t\t\t\t***若想退出请按0***\n\t\t\t\t\t***若想继续查询，请输入1***\n\t\t\t\t\t***若想返回上一界面输入2***\n");
                scanf("%s", key);
                system("cls");
                if (!strcmp(key, "1"))
                {
                    printf("\n\n\n\n\n");//调整格式
                    continue;
                }
                if (!strcmp(key, "2")) break;//如上所示
                if (!strcmp(key, "0")) exit(0);
                while (1)
                {
                    printf("\t\t\t\t\t输入无效，请输入0,1,2\n");
                    printf("\t\t\t\t\t***若想退出请按0***\n\t\t\t\t\t***若想继续查询，请输入1***\n\t\t\t\t\t***若想返回上一界面输入2***\n");
                    scanf("%s", key);
                    if (!strcmp(key, "1") || !strcmp(key, "0") || !strcmp(key, "2"))break;
                }
                system("cls");
                if (!strcmp(key, "1")) continue;
                if (!strcmp(key, "2")) break;
                if (!strcmp(key, "0")) exit(0);
            }
        }
        if (!strcmp(k, "4"))//打印男性
        {
            out_sex_nan(head);
            printf("\t\t\t\t***     返回上一界面，请输入1     *** \n");
            printf("\t\t\t\t***       若想退出程序请按0           ***\n");
            scanf("%s", k);
            while (strcmp(k, "0") != 0 && strcmp(k, "1") != 0)//k不等于0和1时
            {
                printf("\t\t\t\t\t***请输入1或0***\n");
                scanf("%s", k);
            }
            system("cls");
        }
        if (!strcmp(k, "5"))//打印信用卡 kind 0
        {
            out_sex_nv(head);
            printf("\t\t\t\t***     返回上一界面，请输入1     *** \n");
            printf("\t\t\t\t***       若想退出程序请按0           ***\n");
            scanf("%s", k);
            while (strcmp(k, "0") != 0 && strcmp(k, "1") != 0)//k不等于0和1时
            {
                printf("\t\t\t\t\t***请输入1或0***\n");
                scanf("%s", k);
            }
            system("cls");
        }
        if (!strcmp(k, "6"))//打印信用卡 kind 0
        {
            out_kind_0(head);
            printf("\t\t\t\t***     返回上一界面，请输入1     *** \n");
            printf("\t\t\t\t***       若想退出程序请按0           ***\n");
            scanf("%s", k);
            while (strcmp(k, "0") != 0 && strcmp(k, "1") != 0)//k不等于0和1时
            {
                printf("\t\t\t\t\t***请输入1或0***\n");
                scanf("%s", k);
            }
            system("cls");
        }
        if (!strcmp(k, "7"))//储蓄卡 kind 1
        {
            out_kind_1(head);
            printf("\t\t\t\t***     返回上一界面，请输入1     *** \n");
            printf("\t\t\t\t***       若想退出程序请按0           ***\n");
            scanf("%s", k);
            while (strcmp(k, "0") != 0 && strcmp(k, "1") != 0)//k不等于0和1时
            {
                printf("\t\t\t\t\t***请输入1或0***\n");
                scanf("%s", k);
            }
            system("cls");
        }
        if (!strcmp(k, "0")) exit(0);
    }

}
/***********************************************************************************/
int Admin_business_menu()//菜单打印函数，做一个借口，判断用户想进入哪一个窗口
{
    printf("\n\n\n\n\n\t\t\t\t***********************************\n");
    printf("\t\t\t\t***    定期存款,定期取款输入1   ***\n");
    printf("\t\t\t\t***        账号解冻请输入2      ***\n");
    printf("\t\t\t\t***        账号冻结请输入3      ***\n");
    printf("\t\t\t\t***        更改利率请输入4      ***\n");
    printf("\t\t\t\t***         开户请输入5         ***\n");
    printf("\t\t\t\t***         销户请输入6         ***\n");
    printf("\t\t\t\t***   查询账号定期存款输入7     ***\n");
    printf("\t\t\t\t***     返回上一界面请输入-1    ***\n");
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
        printf("\t\t\t\t***输入无效，请输入有效数字 ***\t\t\t\t\t\n");
    }
}
/**********************************************业务界面////**************//////////////////////////////////////////////////////////

int check_date(struct Date now, struct Date end)//1是到达时间 0是未达到
{
    int sum_now = now.year * 360 + now.month * 30 + now.day;//因为银行按照每月30天 每天360天算
    int sum_end = end.year * 360 + end.month * 30 + end.day;//统一为天 方便计算是否达到
    if (sum_now >= sum_end) return 1;
    else return 0;
}
int dif_date(struct Date begin, struct Date end)//返回的是存款类型的天数
{
    return (end.year - begin.year) * 360 + (end.month - begin.month) * 30 + end.day - begin.day;//返回存款的天数
}
int check_date_same(struct Date now_begin, struct Date begin, struct Date now_end, struct Date end)
{
    if (now_begin.year == begin.year && now_begin.month == begin.month && now_begin.day == begin.day)
        if (now_end.year == end.year && now_end.month == end.month && now_end.day == end.day) return 1;//满足两个查找
    return 0;
}
double get_realmoney(double realmoney, int cout, int real_cout)//原本的本金 存款类型 实际天数
{
    double interest_dea = Get_interest_dea(cout);//得到存款类型的利息
    double interest_ava = Get_interest_ava();
    int times = real_cout / cout;//得到存放了几个周期了
    for (int i = 1; i <= times; i++)
    {
        realmoney = realmoney * (1 + interest_dea);
        // double interest_dea = Get_interest_dea(cout);//得到存款类型的利息  利率的更新，
    }
    int sub = real_cout % cout;//得到出去完整的周期 还有多少天,这部分用活期计算
    for (int i = 1; i <= sub; i++)
    {
        realmoney = realmoney * (1 + interest_ava);
    }
    return realmoney;
}
void del_data(char* realid, struct Date real_begin, struct Date real_end)//删除存款记录
{
    FILE* fp = fopen("regular.txt", "r+");//打开原文件
    FILE* temp = fopen("regular2.txt", "w+");//打开备份文件
    char id[30];//将数据抽出 两部分 我们对id对照
    double money;
    struct Date begin, end;
    char a[2000];//存放数据 方便后续转移回来
    /*123 存款1.000000 时间1 1 1 到2 2 2*/
    while (fscanf(fp, "%s 存款%lf 时间%d %d %d 到%d %d %d", id, &money, &begin.year, &begin.month, &begin.day, &end.year, &end.month, &end.day) != EOF)//从目标文件 提取数据到备份文件
    {
        if (strcmp(id, realid) == 0 && check_date_same(real_begin, begin, real_end, end) == 1)//找到需要删除的数据行
        {
            continue;
        }
        fprintf(temp, "%s 存款%lf 时间%d %d %d 到%d %d %d\n", id, money, begin.year, begin.month, begin.day, end.year, end.month, end.day);//输入到备份文件
    }
    fclose(fp);
    rewind(temp);
    FILE* fp2 = fopen("regular.txt", "w+");
    while (fgets(a, 2000, temp) != NULL)//将备份输入目标
    {
        fputs(a, fp2);
    }
    fclose(fp2);
    fclose(temp);
    system("del regular2.txt");
}
int check_bank_save(struct Date begin, struct Date end)//返回1代表输入不对
{
    int sum_now = begin.year * 360 + begin.month * 30 + begin.day;//3 6月 1 2 3 5年
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
void deadline(struct Date begin, char* len, struct Date* end)//存期时间为标准 进行加月份，若到期当天的天数大于到期该月最大天数，那么就定为下一个月的第一天
{
    int temp[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };//对标年月日 1-12
    while (1)
    {
        if (!strcmp(len, "3月"))begin.month = begin.month + 3;////判断存款类型的时间
        else if (!strcmp(len, "6月"))begin.month = begin.month + 6;
        else if (!strcmp(len, "1年"))begin.year = begin.year + 1;
        else if (!strcmp(len, "2年"))begin.year = begin.year + 2;
        else if (!strcmp(len, "3年"))begin.year = begin.year + 3;
        else if (!strcmp(len, "5年"))begin.year = begin.year + 5;
        else
        {
            printf("\t\t\t\t  存款类型是3月，6月，1年，2年，3年，5年\n");
            printf("\t\t\t\t***      请重新输入存款类型          ***\n");
            scanf("%s", len);
            continue;
        }
        break;//运行到这一步代表输入合法了
    }
    if (begin.month > 12)//月份超出限额
    {
        begin.year = begin.year + begin.month / 12;//如果月份大于12,那么年份加1
        begin.month = begin.month % 12;//月份减12  eg:12月->6月 18%13-->5
    }
    if (begin.day > temp[begin.month])
    {
        begin.day = 1;
        begin.month++;
    } /////不需要第二次判断，因为12月有31天，31是begin.day的最大值 不会超过12月 所以可以不用再加
    *end = begin;//因为begin已经加过时间了，可以直接赋值

}
int Admin_save_withdraw_regular(struct Account* head)
{
    while (1)
    {
        printf("\t\t\t\t***         存款输入1           ***\n");
        printf("\t\t\t\t***         取款输入2           ***\n");
        printf("\t\t\t\t***     返回上一界面输入0       ***\n");
        char key[100];
        scanf("%s", key);//判断用户操作
        if (!strcmp(key, "1"))//存款操作   选择部分提前支取，那么提前支取部分按照活期利率和实际存款天数计息，未取出部分按照约定的定期存款利率计息。
        {
            FILE* fp = fopen("regular.txt", "r+");
            char id[30], password[50];
            double money;
            struct Date begin, end;
            system("cls");
            printf("\n\n\n\n\n\t\t\t\t***********************************\n");
            printf("\t\t\t\t***      输入卡号，密码         ***\n");
            printf("\t\t\t\t***         输入金额            ***\n");
            printf("\t\t\t\t***       输入存入时间          ***\n");
            printf("\t\t\t\t***       输入到期时间          ***\n\n\n");
            printf("\t\t\t\t***           例如              ***\n");
            printf("\t\t\t\t*** 6222600260001072121 123456  ***\n");
            printf("\t\t\t\t***          1000.21            ***\n");
            printf("\t\t\t\t***         2019 4 5            ***\n");
            printf("\t\t\t\t***         2029 4 5            ***\n");
            printf("\t\t\t***请注意只有3月，6月，1年，2年，3年，5年定期利息***\n");
            scanf("%s %s %lf ", id, password, &money);//输入账号 密码
            scanf("%d %d %d %d %d %d", &begin.year, &begin.month, &begin.day, &end.year, &end.month, &end.day);
            struct Account* myid = Search_id(head, id);
            while (myid == NULL)//对卡号判断是否存在
            {
                printf("\t\t\t\t***        卡号不存在           ***\n");
                printf("\t\t\t\t***    若想继续重新输入卡号     ***\n");
                printf("\t\t\t\t***      返回业务界面输入0      ***\n");
                scanf("%s", id);
                if (!strcmp(id, "0")) break;
                myid = Search_id(head, id);
            }
            //找到卡号了
            if (!strcmp(id, "0")) return 2;//当返回业务界面 就直接跳过
            while (strcmp(password, myid->password))//密码不对而且不返回业务界面
            {
                printf("\t\t\t\t***          密码错误           ***\n");
                printf("\t\t\t\t***    若想继续重新输入密码     ***\n");
                printf("\t\t\t\t***      返回业务界面输入0      ***\n");
                scanf("%s", password);
                if (!strcmp(password, "0")) break;
            }
            if (!strcmp(password, "0")) return 2;//当返回业务界面 就直接跳过
            fseek(fp, 0, SEEK_END);
            fprintf(fp, "%s 存款%lf 时间%d %d %d 到%d %d %d\n", id, money, begin.year, begin.month, begin.day, end.year, end.month, end.day);
            printf("\t\t\t\t***          存款成功           ***\n");
            printf("\t\t\t\t***       继续存取款输入1       ***\n");
            printf("\t\t\t\t***      返回业务界面输入2      ***\n");
            printf("\t\t\t\t***         退出输入0           ***\n");
            char key2[100];
            scanf("%s", key2);
            if (!strcmp(key2, "1")) continue;
            if (!strcmp(key2, "2")) return 2;
            if (!strcmp(key2, "0")) exit(0);
            fclose(fp);
        }
        /***************************************************************************************************/
        else if (!strcmp(key, "2"))//取款操作  若定期到期，按照同等级的存款周期延展
        {
            FILE* fp = fopen("regular.txt", "r+");//得到前一次存定期的时间 和金额
            char id[30], password[50];
            double money;
            char realid[30];
            double realmoney;
            struct Date now, begin, end;
            system("cls");
            printf("\n\n\n\n\n\t\t\t\t***********************************\n");
            printf("\t\t\t\t***      输入卡号，密码         ***\n");
            printf("\t\t\t\t***         输入时间            ***\n");
            printf("\t\t\t\t***           例如              ***\n");
            printf("\t\t\t\t*** 6222600260001072121 123456  ***\n");
            printf("\t\t\t\t***         2019 4 5            ***\n");
            scanf("%s %s ", id, password);//输入账号 密码
            scanf("%d %d %d", &now.year, &now.month, &now.day);//当前时间    接下来在文件查找数据
            while (1)//对账号查找的循环
            {
                int flag = 1;//判断接下来 是否找到账号
                rewind(fp);//对文件指针的重置
                while (fscanf(fp, "%s 存款%lf 时间%d %d %d 到%d %d %d\n", realid, &realmoney, &begin.year, &begin.month, &begin.day, &end.year, &end.month, &end.day) != EOF)
                {
                    if (!strcmp(id, realid))//文件中有该数据
                    {
                        flag = 0;//查到了
                        break;
                    }
                }
                if (flag == 0) break;//找到账户了
                else
                {
                    printf("\t\t\t\t***        不存在该账户         ***\n");
                    printf("\t\t\t\t***       若想继续，输入卡号    ***\n");
                    printf("\t\t\t\t***       返回业务界面输入0     ***\n");
                }
                scanf("%s", id);
                if (!strcmp(id, "0"))break;
            }
            if (!strcmp(id, "0"))return 2;//返回业务界面
            while (strcmp(password, Search_id(head, id)->password))//判断密码是否正确
            {
                printf("\t\t\t\t***           密码错误          ***\n");
                printf("\t\t\t\t***       若想继续，输入密码    ***\n");
                printf("\t\t\t\t***       返回业务界面输入0     ***\n");
                scanf("%s", password);
                if (!strcmp(password, "0"))break;
            }
            if (!strcmp(password, "0"))return 2;//返回业务界面
            /////////////////////接下来就是对取款金额的确认
            if (check_date(now, end))//判断是否达到存放时间   1到 0没到    这里是到
            {
                int cout = dif_date(begin, end);//记录存款类型，是多少天 这样分别获得利息比如30 90 180
                int real_cout = dif_date(begin, now);//返回实际的天数
                realmoney = get_realmoney(realmoney, cout, real_cout);
                printf("\t\t\t\t***         你的存款到期        ***\n");
                printf("\t\t\t\t          现有存款%.2lf          \n", realmoney);//加上利息的本金
                printf("\t\t\t\t***          请输入金额         ***\n");
                scanf("%lf", &money);//要取出的金额
                while (money > realmoney || money < 0)//取多了
                {
                    printf("\t\t\t\t***           余额不够          ***\n");
                    printf("\t\t\t\t***          请重新输入         ***\n");
                    printf("\t\t\t\t***      若返回上一界面输入0    ***\n");
                    printf("\t\t\t\t***          若退出输入-1       ***\n");
                    scanf("%lf", &money);
                    if (money == 0)break;
                    if (money == -1)exit(0);
                }
                printf("\t\t\t\t***           取款成功          ***\n");//定期取出成功，接下来将未完全取出的转为活期
                del_data(id, begin, end);/**********将数据转为另一个文件，还得更改regular文件该行的数据*********/
                printf("\t\t\t\t***       继续存取款输入1       ***\n");
                printf("\t\t\t\t***      返回业务界面输入2      ***\n");
                printf("\t\t\t\t***         退出输入0           ***\n");
                char key2[100];
                scanf("%s", key2);
                if (!strcmp(key2, "1")) continue;
                if (!strcmp(key2, "2")) return 2;
                if (!strcmp(key2, "0")) exit(0);
                if (money < realmoney)//将剩余的钱转入活期
                {
                    double money_in = realmoney - money;
                    FILE* fp = fopen("trade.txt", "r+");
                    fseek(fp, 0L, SEEK_END);
                    fprintf(fp, "%s %d %d %d 存款%lf元\n", id, now.year, now.month, now.day, money_in);
                    fclose(fp);
                }
            }
            else//存款没到期
            {
                printf("\t\t\t\t***            存款未到期       ***\n");
                printf("\t\t\t\t***        若想继续取款输入     ***\n");
                printf("\t\t\t\t***      若返回上一界面输入0    ***\n");
                printf("\t\t\t\t***          若退出输入-1       ***\n");
                char key2[100];
                scanf("%s", key2);
                while (strcmp(key2, "0") != 0 || strcmp(key2, "1") != 0 || strcmp(key2, "-1") != 0)
                {
                    // printf("")
                }
            }
            fclose(fp);
        }
        else if (!strcmp(key, "0")) return 2;//继续上一界面
        else printf("\t\t\t\t***          输入错误           ***\n\n");
    }
}
int check_money(char* money)//1正确 0不正确
{
    int point = 0;
    for (int i = 0; i < strlen(money); i++)
    {
        if (money[i] > '9' || money[i] < '0')//输入金额只能为数字和小数
        {
            if (money[i] == '.')point++;//有几个小数点
            if (money[i] != '.')return 0;//非法输入了
        }
    }
    if (point == 1||point==0)return 1;
    return 0;
}
int Admin_save_withdraw_regular_new()//存取，是按照身份证存期，与卡号无关 取款按照整取，就无需输入取出金额
{
    while (1)
    {
        system("cls");
        printf("\n\n\n\n\n\t\t\t\t***********************************\n");
        printf("\t\t\t\t***         存款输入1           ***\n");
        printf("\t\t\t\t***         取款输入2           ***\n");
        printf("\t\t\t\t***     返回上一界面输入0       ***\n");
        printf("\t\t\t\t***********************************\n");
        char key[100];
        scanf("%s", key);//判断用户操作
        if (!strcmp(key, "1"))//存款操作   选择部分提前支取，那么提前支取部分按照活期利率和实际存款天数计息，未取出部分按照约定的定期存款利率计息。
        {
            FILE* fp = fopen("regular.txt", "r+");
            char id[30], password[50];
            double money;
            struct Date begin, end;
            system("cls");
            printf("\n\n\n\n\n\t\t\t\t***************************************\n");
            printf("\t\t\t\t***          输入身份证             ***\n");
            printf("\t\t\t\t***           输入金额              ***\n");
            printf("\t\t\t\t***         输入存入时间            ***\n");
            printf("\t\t\t\t***         输入存款类型            ***\n");
            printf("\t\t\t\t***     若想返回上一界面输入0       ***\n");
            printf("\t\t\t\t***             例如                ***\n");
            printf("\t\t\t\t***       513598200104151875        ***\n");
            printf("\t\t\t\t***            1000.21              ***\n");
            printf("\t\t\t\t***           2024 4 5              ***\n");
            printf("\t\t\t\t***             5年                 ***\n");
            printf("\t\t\t***请注意只有3月，6月，1年，2年，3年，5年定期利息***\n");
            ///////////////////判断错误输入
            char money_scan[200];//接受金额，再转换
            scanf("%s", id);//输入账号
            if (!strcmp(id, "0")) return 2;
            //scanf("%s %d %d %d %d %d %d", money_scan, &begin.year, &begin.month, &begin.day, &end.year, &end.month, &end.day);//开始 结束时间
            while (check_integer(id) == 0 || strlen(id) != 18)//非法输入 身份证位数不对，前17位不是全数字
            {
                printf("\t\t\t\t***       身份证输入错误，请重新输入    ***\n");
                printf("\t\t\t\t***        注意，身份证为18位整数       ***\n");
                scanf("%s", id);
            }
            printf("\t\t\t\t***            身份证输入成功           ***\n");
            printf("\t\t\t\t***              请输入金额             ***\n");
            scanf("%s", money_scan);
            money = atof(money_scan);
            while (1)
            {
                if (money > 0&&check_money(money_scan)==1) break;//跳出,输入合法
                printf("\t\t\t\t*** 输入错误（同时注意金额不能为0） ***\n");
                printf("\t\t\t\t***         请重新输入金额          ***\n");
                scanf("%s", money_scan);//输入账号 密码
                money = atof(money_scan);
            }
            printf("\t\t\t\t*** 身份证和金额输入成功，请输入当前日期***\n");
            in_date(&begin);
            printf("\t\t\t\t***          输入存款类型           ***\n");//存款类型的输入
            char len[50];
            scanf("%s", len);
            deadline(begin, len, &end);//到期函数
            fseek(fp, 0, SEEK_END);
            fprintf(fp, "%s 存款%lf 时间%d %d %d 到%d %d %d\n", id, money, begin.year, begin.month, begin.day, end.year, end.month, end.day);
            fclose(fp);
            printf("\t\t\t\t***            存款成功             ***\n");
            printf("\t\t\t\t***         继续存取款输入1         ***\n");
            printf("\t\t\t\t***        返回业务界面输入2        ***\n");
            printf("\t\t\t\t***         结束程序输入0           ***\n");
            char key2[100];//判断接下来的操作
            while (1)
            {
                scanf("%s", key2);
                system("cls");
                if (!strcmp(key2, "1")) break;
                if (!strcmp(key2, "2")) break;
                if (!strcmp(key2, "0")) break;
                printf("\n\n\n\n\n\t\t\t\t***       输入错误，重新输入        ***\n");
                printf("\t\t\t\t***         继续存取款输入1         ***\n");
                printf("\t\t\t\t***        返回业务界面输入2        ***\n");
                printf("\t\t\t\t***         结束程序输入0           ***\n");
            }
            if (!strcmp(key2, "1")) continue;
            if (!strcmp(key2, "2")) return 2;
            if (!strcmp(key2, "0")) exit(0);
        }
        /***************************************************************************************************/
        else if (!strcmp(key, "2"))//取款操作  若定期到期，按照同等级的存款周期延展
        {
            FILE* fp = fopen("regular.txt", "r+");//得到前一次存定期的时间 和金额
            char id[30];//卡号 
            double money;
            char realid[30];
            double realmoney;
            struct Date now, now_begin, now_end, begin, end;
            system("cls");
            printf("\n\n\n\n\n\t\t\t\t***********************************\n");
            printf("\t\t\t\t***          输入身份证             ***\n");
            printf("\t\t\t\t***         输入当前时间            ***\n");
            printf("\t\t\t\t***        输入存款的时间           ***\n");
            printf("\t\t\t\t***         输入定期类型            ***\n");
            printf("\t\t\t\t***     若想返回上一界面输入0       ***\n");
            printf("\t\t\t\t***             例如                ***\n");
            printf("\t\t\t\t***       513920155840215874        ***\n");
            printf("\t\t\t\t***           2019 4 5              ***\n");
            printf("\t\t\t\t***           2018 4 5              ***\n");
            printf("\t\t\t\t***              3月                ***\n");
            scanf("%s", id);//输入账号
            if (!strcmp(id, "0")) return 2;
            printf("\t\t\t\t***          身份证输入成功         ***\n");
            printf("\t\t\t\t***          请输入当前日期         ***\n");
            /*scanf("%d %d %d", &now.year, &now.month, &now.day);//当前时间    接下来在文件查找数据
            scanf("%d %d %d", &now_begin.year, &now_begin.month, &now_begin.day);
            scanf("%d %d %d", &now_end.year, &now_end.month, &now_end.day);//因为一个身份证能存多个定期，需要对比时间*/
            in_date(&now);
            printf("\t\t\t\t***            输入起始时间         ***\n");
            in_date(&now_begin);
            printf("\t\t\t\t***            输入存款类型         ***\n");
            //in_date(&now_end);   更换为存款类型
            char len[50];
            scanf("%s", len);
            deadline(now_begin, len, &now_end);
            while (1)//对账号查找的循环,同时对比时间      真实的起始时间和截止时间
            {
                int flag = 0;//判断接下来 是否找到账号
                rewind(fp);//对文件指针的重置
                while (fscanf(fp, "%s 存款%lf 时间%d %d %d 到%d %d %d\n", realid, &realmoney, &begin.year, &begin.month, &begin.day, &end.year, &end.month, &end.day) != EOF)
                {
                    if (!strcmp(id, realid))//文件中有该数据
                    {
                        flag = check_date_same(now_begin, begin, now_end, end);//flag=1就是查到了
                        if (flag == 1) break;//若flag==0 这继续往后查
                    }
                }
                if (flag == 1) break;//找到账户了
                else
                {
                    printf("\t\t\t\t***          不存在对应信息         ***\n");
                    printf("\t\t\t\t***       若想继续，请重新输入      ***\n");
                    printf("\t\t\t\t***          输入身份证             ***\n");
                    printf("\t\t\t\t***        输入存款的时间           ***\n");
                    printf("\t\t\t\t***        输入定期截至时间         ***\n");
                    printf("\t\t\t\t***             例如                ***\n");
                    printf("\t\t\t\t***       513920155840215874        ***\n");
                    printf("\t\t\t\t***           2018 4 5              ***\n");
                    printf("\t\t\t\t***           2019 4 5              ***\n");
                    printf("\t\t\t\t***         返回业务界面输入0       ***\n");
                }
                scanf("%s", id);
                if (!strcmp(id, "0"))break;
                scanf("%d %d %d", &now_begin.year, &now_begin.month, &now_begin.day);
                scanf("%d %d %d", &now_end.year, &now_end.month, &now_end.day);//因为一个身份证能存多个定期，需要对比时间
                system("cls");
            }
            if (!strcmp(id, "0"))return 2;//返回业务界面
            /////////////////////接下来就是对取款金额的确认
            if (check_date(now, end))//判断是否达到存放时间   1到 0没到    这里是到
            {
                int cout = dif_date(begin, end);//记录存款类型，是多少天 这样分别获得利息比如30 90 180
                int real_cout = dif_date(begin, now);//返回实际的天数
                realmoney = get_realmoney(realmoney, cout, real_cout);//
                printf("\t\t\t\t***           你的存款到期          ***\n");
                printf("\t\t\t\t            现有存款%.2lf          \n", realmoney);//加上利息的本金
                printf("\t\t\t\t***            取款成功             ***\n");//定期取出成功，接下来将未完全取出的转为活期
                del_data(id, begin, end);/**********将数据转为另一个文件，还得删除regular文件该行的数据*********/
                printf("\t\t\t\t***         继续存取款输入1         ***\n");
                printf("\t\t\t\t***        返回业务界面输入2        ***\n");
                printf("\t\t\t\t***         结束程序输入0           ***\n");
                char key2[100];// 
                while (1)
                {
                    scanf("%s", key2);
                    system("cls");
                    if (!strcmp(key2, "1")) break;
                    if (!strcmp(key2, "2")) break;
                    if (!strcmp(key2, "0")) break;
                    printf("\n\n\n\n\n\t\t\t\t***       输入错误，重新输入        ***\n");
                    printf("\t\t\t\t***         继续存取款输入1         ***\n");
                    printf("\t\t\t\t***        返回业务界面输入2        ***\n");
                    printf("\t\t\t\t***         结束程序输入0           ***\n");
                }
                if (!strcmp(key2, "1")) continue;
                if (!strcmp(key2, "2")) return 2;
                if (!strcmp(key2, "0")) exit(0);
            }
            else//存款没到期
            {
                printf("\t\t\t\t***            存款未到期           ***\n");
                printf("\t\t\t\t***         若想继续取款输入1       ***\n");
                printf("\t\t\t\t***        若返回上一界面输入2      ***\n");
                printf("\t\t\t\t***         结束程序输入0           ***\n");
                char key[100];
                while (1)
                {
                    scanf("%s", key);
                    system("cls");
                    if (!strcmp(key, "1")) break;
                    if (!strcmp(key, "2")) break;
                    if (!strcmp(key, "0")) break;
                    printf("\n\n\n\n\n\t\t\t\t***       输入错误，重新输入        ***\n");
                    printf("\t\t\t\t***          继续取款输入1          ***\n");
                    printf("\t\t\t\t***        返回业务界面输入2        ***\n");
                    printf("\t\t\t\t***         结束程序输入0           ***\n");
                }
                if (!strcmp(key, "2")) return 2;
                if (!strcmp(key, "0")) exit(0);
                int real_cout = dif_date(begin, now);//返回实际的天数
                for (int i = 1; i <= real_cout; i++)
                {
                    realmoney = realmoney * (1 + Get_interest_ava());
                }
                printf("\t\t\t\t          现有存款%.2lf          \n", realmoney);//加上利息的本金
                printf("\t\t\t\t***            取款成功             ***\n");//定期取出成功，接下来将未完全取出的转为活期
                del_data(id, begin, end);/**********将数据转为另一个文件，还得删除regular文件该行的数据*********/
                printf("\t\t\t\t***         继续存取款输入1         ***\n");
                printf("\t\t\t\t***        返回业务界面输入2        ***\n");
                printf("\t\t\t\t***         结束程序输入0           ***\n");
                char key2[100];//判断接下来的操作
                while (1)
                {
                    scanf("%s", key2);
                    system("cls");
                    if (!strcmp(key2, "1")) break;
                    if (!strcmp(key2, "2")) break;
                    if (!strcmp(key2, "0")) break;
                    printf("\n\n\n\n\n\t\t\t\t***       输入错误，重新输入        ***\n");
                    printf("\t\t\t\t***         继续存取款输入1         ***\n");
                    printf("\t\t\t\t***        返回业务界面输入2        ***\n");
                    printf("\t\t\t\t***         结束程序输入0           ***\n");
                }
                if (!strcmp(key2, "1")) continue;
                if (!strcmp(key2, "2")) return 2;
                if (!strcmp(key2, "0")) exit(0);

            }
            fclose(fp);
        }
        else if (!strcmp(key, "0")) return 2;//继续上一界面
        else printf("\t\t\t\t***            输入错误             ***\n\n");
    }
}
void  change_state(char* id, int a)//a是要将state改成的值，该函数直接对于文件操作   第一个是卡号，第二个是要修改成的值，方便冻结解冻一起调用
{
    FILE* fp = fopen("Account.txt", "r+");
    struct Account* user = (struct Account*)malloc(sizeof(struct Account));
    while (fscanf(fp, "%s %s %s %s %lf %lld %lf %d %d\n", user->name, user->sex, user->id, user->password, &user->amount, &user->idcard, &user->interest, &user->state, &user->kind) != EOF)
    {
        if (!strcmp(user->id, id))
        {
            fseek(fp, -5, SEEK_CUR); //回滚指针至state前
            fprintf(fp, "%d", a);//在文件中，将state改变。 state，空格,kind,\,n 5个位置。
            break;
        }
    }
    fclose(fp);
}
int Admin_freeze(struct Account* head)//冻结函数,就利用search_id()查找，改变值，但是是链表里面的值。  0冻结 1正常
{
    //这里需要用search函数
    char id[200], key[200];
    while (1)
    {
        printf("\t\t\t\t***       返回上一界面输入0     *** \n");
        scanf("%s", id);
        if (!strcmp(id, "0")) return 2;
        struct Account* cout = Search_id(head, id);
        if (cout != NULL)
        {
            cout->state = 0;
            printf("\t\t\t\t***          冻结成功           ***\n\n");
            ///////接下来更改文件内的值
            change_state(id, 0);
        }//冻结
        else printf("\t\t\t\t***         不存在该用户        ***\n\n");
        while (1)
        {
            printf("\t\t\t\t***       若继续冻结，输入1     ***\n");
            printf("\t\t\t\t***     若继续其他业务，输入2   ***\n");
            printf("\t\t\t\t***         结束程序输入0       ***\n");
            scanf("%s", key);
            system("cls");
            if (!strcmp(key, "1"))
            {
                printf("\n\n\n\n\n\t\t\t\t***********************************\n");
                break;
            }
            if (!strcmp(key, "2")) return 2;
            if (!strcmp(key, "0")) exit(0);
            else printf("\t\t\t\t***     输入错误，请重新输入    ***\n\n");
        }
    }
}
int Admin_unfreeze(struct Account* head)//对账号解冻，就利用search_id()查找，改变值，改变的是链表里面的值。
{
    char id[200], key[200];//key判断用户接下来干什么，退出，继续，或返回上一界面
    while (1)
    {
        printf("\t\t\t\t***          请输入账号         *** \n");
        printf("\t\t\t\t***       返回上一界面输入0     *** \n");
        scanf("%s", id);
        if (!strcmp(id, "0")) return 2;
        struct Account* cout = Search_id(head, id);
        if (cout != NULL)
        {
            cout->state = 1;
            printf("\t\t\t\t***          解冻成功           ***\n\n");
            change_state(id, 1);
            FILE* fp = fopen("limit.txt", "r+");
            char realid[50];//卡号
            double limit_real, limit;//现在的额度,额度上限，
            if (cout->kind == 0)//信用卡额度复原
            {
                int r = 0;//判断数据是在第几行
                char temp_id[200];
                double temp_limit_real, temp_limit;//没什么意义只是 存放数据的地址
                while (fscanf(fp, "%s%lf%lf", realid, &limit_real, &limit) != EOF)//循环查找数据
                {
                    if (!strcmp(id, realid))//数据找到了
                    {
                        break;
                    }
                    r++;//每找一次 就加一
                }
                rewind(fp);
                for (int i = 0; i < r; i++)//r代表要循环多少次才能到目标数据
                {
                    fscanf(fp, "%s%lf%lf", temp_id, &temp_limit_real, &temp_limit);//利用文件指针自动后移
                }
                fprintf(fp, "%s %lf %lf", realid, limit, limit);//覆盖原数据
                fclose(fp);
            }
        }//解冻
        else printf("\t\t\t\t***         不存在该用户        ***\n\n"); \
            while (1)
            {
                printf("\t\t\t\t***       若继续解冻，输入1     ***\n");
                printf("\t\t\t\t***     若继续其他业务，输入2   ***\n");
                printf("\t\t\t\t***         结束程序输入0       ***\n");
                scanf("%s", key);
                system("cls");
                if (!strcmp(key, "1"))
                {
                    printf("\n\n\n\n\n\t\t\t\t***********************************\n");
                    break;
                }
                if (!strcmp(key, "2")) return 2;
                if (!strcmp(key, "0")) exit(0);
                else printf("\t\t\t\t***     输入错误，请重新输入    ***\n\n");
            }
    }

}
int Admin_change_interest()//更改利息,文件中修改
{
    char key[200];
    double ava, dea_3month, dea_6month, dea_1year, dea_2year, dea_3year, dea_5year;//活，定
    double nowinterest;
    while (1)
    {
        FILE* fp = fopen("Admin.txt", "r+");
        char* array;//动态内存分配
        array = (char*)malloc(100 * sizeof(char));
        printf("\t\t\t\t***       若更改活期利率输入1   *** \n");
        printf("\t\t\t\t***       若更改定期利率输入2   *** \n");
        printf("\t\t\t\t***        返回上一界面输入0    *** \n");
        scanf("%s", key);
        if (!strcmp(key, "0")) return 2;
        if (!strcmp(key, "1"))
        {
            printf("\t\t\t\t***       请输入现在的利息值   *** \n");//采用全部输入到内存，再输出到文件，覆盖
            scanf("%lf", &nowinterest);
            fscanf(fp, "%s\n%lf %lf", array, &ava, &dea_3month);
            rewind(fp);
            fprintf(fp, "%s\n%lf %lf", array, nowinterest, dea_3month);
            fclose(fp);
            free(array);//释放内存
            ////判断接下来的操作
            while (1)
            {
                printf("\t\t\t\t***       继续修改利率输入1    ***\n");
                printf("\t\t\t\t***       返回上一界面输入2    ***\n");//判断用户输入，不对就循环。主要针对非法输入
                printf("\t\t\t\t***         结束程序输入0       ***\n");
                scanf("%s", key);
                system("cls");
                if (!strcmp(key, "1"))
                {
                    printf("\n\n\n\n\n\t\t\t\t***********************************\n");
                    break;
                }
                if (!strcmp(key, "2")) return 2;
                if (!strcmp(key, "0")) exit(0);
                else printf("\t\t\t\t***     输入错误，请重新输入    ***\n\n");
            }
        }
        if (!strcmp(key, "2"))////////////////////////////都是通过覆盖文件的数据从而修改。又因为利息是按照最新的计算，所以不需要保存原数据
        {
            char* array;
            array = (char*)malloc(100 * sizeof(char));
            printf("\t\t\t\t*** 若想修改3个月的利息，输入1 *** \n");
            printf("\t\t\t\t*** 若想修改6个月的利息，输入2 *** \n");
            printf("\t\t\t\t***  若想修改1年的利息， 输入3  *** \n");
            printf("\t\t\t\t***  若想修改2年的利息， 输入4  *** \n");
            printf("\t\t\t\t***  若想修改3年的利息， 输入5  *** \n");
            printf("\t\t\t\t***  若想修改5年的利息， 输入6  *** \n");
            char key2[20];
            scanf("%s", key2);
            if (!strcmp(key2, "1"))//////////////修改三个月的利息
            {
                printf("\t\t\t\t***       请输入现在的利息值   *** \n");
                scanf("%lf", &nowinterest);
                fscanf(fp, "%s\n%lf %lf", array, &ava, &dea_3month);
                rewind(fp);
                fprintf(fp, "%s\n%lf %lf", array, ava, nowinterest);
                fclose(fp);
                free(array);
                while (1)
                {
                    printf("\t\t\t\t***       继续修改利率输入1    ***\n");
                    printf("\t\t\t\t***       返回上一界面输入2    ***\n");
                    printf("\t\t\t\t***         结束程序输入0       ***\n");
                    scanf("%s", key);
                    system("cls");
                    if (!strcmp(key, "1")) break;
                    if (!strcmp(key, "2")) return 2;
                    if (!strcmp(key, "0")) exit(0);
                    else printf("\t\t\t\t***     输入错误，请重新输入    ***\n\n");
                }
            }
            if (!strcmp(key2, "2"))//////////////修改6个月的利息
            {
                printf("\t\t\t\t***       请输入现在的利息值   *** \n");
                scanf("%lf", &nowinterest);
                fscanf(fp, "%s\n%lf %lf %lf", array, &ava, &dea_3month, &dea_6month);
                rewind(fp);
                fprintf(fp, "%s\n%lf %lf %lf", array, ava, dea_3month, nowinterest);
                fclose(fp);
                free(array);
                while (1)
                {
                    printf("\t\t\t\t***       继续修改利率输入1    ***\n");
                    printf("\t\t\t\t***       返回上一界面输入2    ***\n");
                    printf("\t\t\t\t***         结束程序输入0       ***\n");
                    scanf("%s", key);
                    system("cls");
                    if (!strcmp(key, "1")) break;
                    if (!strcmp(key, "2")) return 2;
                    if (!strcmp(key, "0")) exit(0);
                    else printf("\t\t\t\t***     输入错误，请重新输入    ***\n\n");
                }
            }
            if (!strcmp(key2, "3"))//////////////修改1年的利息
            {
                printf("\t\t\t\t***       请输入现在的利息值   *** \n");
                scanf("%lf", &nowinterest);
                fscanf(fp, "%s\n%lf %lf %lf %lf", array, &ava, &dea_3month, &dea_6month, &dea_1year);
                rewind(fp);
                fprintf(fp, "%s\n%lf %lf %lf %lf", array, ava, dea_3month, dea_6month, nowinterest);
                fclose(fp);
                free(array);
                while (1)
                {
                    printf("\t\t\t\t***       继续修改利率输入1    ***\n");
                    printf("\t\t\t\t***       返回上一界面输入2    ***\n");
                    printf("\t\t\t\t***         结束程序输入0       ***\n");
                    scanf("%s", key);
                    system("cls");
                    if (!strcmp(key, "1")) break;
                    if (!strcmp(key, "2")) return 2;
                    if (!strcmp(key, "0")) exit(0);
                    else printf("\t\t\t\t***     输入错误，请重新输入    ***\n\n");
                }
            }
            if (!strcmp(key2, "4"))//////////////修改2年的利息
            {
                printf("\t\t\t\t***       请输入现在的利息值   *** \n");
                scanf("%lf", &nowinterest);
                fscanf(fp, "%s\n%lf %lf %lf %lf %lf ", array, &ava, &dea_3month, &dea_6month, &dea_1year, &dea_2year);
                rewind(fp);
                fprintf(fp, "%s\n%lf %lf %lf %lf %lf ", array, ava, dea_3month, dea_6month, dea_1year, nowinterest);
                fclose(fp);
                free(array);
                while (1)
                {
                    printf("\t\t\t\t***       继续修改利率输入1    ***\n");
                    printf("\t\t\t\t***       返回上一界面输入2    ***\n");
                    printf("\t\t\t\t***         结束程序输入0       ***\n");
                    scanf("%s", key);
                    system("cls");
                    if (!strcmp(key, "1")) break;
                    if (!strcmp(key, "2")) return 2;
                    if (!strcmp(key, "0")) exit(0);
                    else printf("\t\t\t\t***     输入错误，请重新输入    ***\n\n");
                }
            }
            if (!strcmp(key2, "5"))//////////////修改3年的利息
            {
                printf("\t\t\t\t***       请输入现在的利息值   *** \n");
                scanf("%lf", &nowinterest);
                fscanf(fp, "%s\n%lf %lf %lf %lf %lf ", array, &ava, &dea_3month, &dea_6month, &dea_1year, &dea_2year, &dea_3year);
                rewind(fp);
                fprintf(fp, "%s\n%lf %lf %lf %lf %lf", array, ava, dea_3month, dea_6month, dea_1year, dea_2year, nowinterest);
                fclose(fp);
                free(array);
                while (1)
                {
                    printf("\t\t\t\t***       继续修改利率输入1    ***\n");
                    printf("\t\t\t\t***       返回上一界面输入2    ***\n");
                    printf("\t\t\t\t***         结束程序输入0       ***\n");
                    scanf("%s", key);
                    system("cls");
                    if (!strcmp(key, "1")) break;
                    if (!strcmp(key, "2")) return 2;
                    if (!strcmp(key, "0")) exit(0);
                    else printf("\t\t\t\t***     输入错误，请重新输入    ***\n\n");
                }
            }
            if (!strcmp(key2, "6"))//////////////修改5年的利息
            {
                printf("\t\t\t\t***       请输入现在的利息值   *** \n");
                scanf("%lf", &nowinterest);
                fscanf(fp, "%s\n%lf %lf %lf %lf %lf %lf %lf", array, &ava, &dea_3month, &dea_6month, &dea_1year, &dea_2year, &dea_3year, &dea_5year);
                rewind(fp);
                fprintf(fp, "%s\n%lf %lf %lf %lf %lf %lf %lf", array, ava, dea_3month, dea_6month, dea_1year, dea_2year, dea_3year, nowinterest);
                fclose(fp);
                free(array);
                while (1)
                {
                    printf("\t\t\t\t***       继续修改利率输入1    ***\n");
                    printf("\t\t\t\t***       返回上一界面输入2    ***\n");
                    printf("\t\t\t\t***         结束程序输入0       ***\n");
                    scanf("%s", key);
                    system("cls");
                    if (!strcmp(key, "1")) break;
                    if (!strcmp(key, "2")) return 2;
                    if (!strcmp(key, "0")) exit(0);
                    else printf("\t\t\t\t***     输入错误，请重新输入    ***\n\n");
                }
            }
        }
    }
}
int Admin_creat_account(struct Account* head)//开户函数，创建一个新的卡号
{
    while (1)
    {
        printf("\t\t\t***请输入姓名，性别，密码，开卡类型 以及身份证 ***\n\n");
        printf("\t\t\t\t***     请注意密码为6位整数       ***\n");
        printf("\t\t\t***    例如：张三 男 123456 信用卡  513125200104151875***\n");
        printf("\t\t\t***    例如：李美 女 123456 储蓄卡  513987500145875120***\n\n");
        printf("\t\t\t\t***      若想返回输入0            ***\n");
        char* name = (char*)malloc(20 * sizeof(char));/////进行赋予空间，便于后续存放数据
        char* sex = (char*)malloc(20 * sizeof(char));
        char* pin = (char*)malloc(20 * sizeof(char));
        char* kind = (char*)malloc(20 * sizeof(char));
        char* id = (char*)malloc(21 * sizeof(char));
        char* idcard = (char*)malloc(20 * sizeof(char));
        double amount = 0, interest = 0;
        int realkind = -1, state = 1;//默认可用，非冻结
        scanf("%s", name);
        if (!strcmp(name, "0")) return 2;
        scanf("%s %s %s %s", sex, pin, kind, idcard);
        if (!strcmp(kind, "信用卡")) realkind = 0;
        if (!strcmp(kind, "储蓄卡")) realkind = 1;
        while (strcmp(sex, "男") && strcmp(sex, "女"))//当性别不为男，而且不为女
        {
            printf("\t\t\t\t***    性别输入错误，请重新输入性别 ***\n");
            scanf("%s", sex);
        }
        while (strlen(pin) != 6 || check_integer(pin) != 1)//当密码位数不为6，或者不是整数    1是整数 0不是整数
        {
            printf("\t\t\t\t***    密码输入错误，请重新输入密码 ***\n");
            printf("\t\t\t\t***     请注意，密码为6为整数       ***\n");
            scanf("%s", pin);
        }
        while (strcmp(kind, "信用卡") && strcmp(kind, "储蓄卡"))//当卡类不是信用卡，而且不为储蓄卡
        {
            printf("\t\t\t\t***    卡类输入错误，请重新输入卡类 ***\n");
            scanf("%s", kind);
            if (!strcmp(kind, "信用卡")) realkind = 0;
            if (!strcmp(kind, "储蓄卡")) realkind = 1;
        }
        while (check_integer(idcard) == 0 || strlen(idcard) != 18)//非法输入 身份证位数不对，前17位不是全数字
        {
            printf("\t\t\t\t***     身份证输入错误，请重新输入  ***\n");
            printf("\t\t\t\t***      注意，身份证为18位整数     ***\n");
            scanf("%s", idcard);
        }
        printf("\t\t\t\t***         你的详细信息如下        ***\n");
        printf("\t\t\t***    %s %s %s %s  %s    ***\n", name, sex, pin, kind, idcard);
        printf("\t\t\t\t***         确认无误，输入1         ***\n");
        printf("\t\t\t\t***         否则输入非1的值         ***\n");
        char key[100];
        scanf("%s", key);
        if (!strcmp(key, "1"))//随机产生银行卡号
        {
            strcpy(id, "6221");//银行卡号
            srand((unsigned)time(NULL));//播种 产生随机种子
            for (int i = 4; i < 19; i++)
            {
                int x = rand() % 9;
                id[i] = x + '0';/*产生9以内的随机整数*/
            }
            id[19] = '\0';
        }
        else continue;//有误
        system("cls");////////////////////清屏
        printf("\n\n\n\n\n\t\t\t\t***************************************\n");
        printf("\t\t\t\t***************************************\n");
        printf("\t\t\t\t***         银行卡创建成功          ***\n");
        printf("\t\t\t\t***       你的银行卡信息如下：          \n");
        long long real_idcard = atoll(idcard);;
        printf("姓名     性别\t  卡号\t\t    密码     存款\t\t   身份证            利息            状态  类别\n");//格式//调整格式,输出让用户确定
        printf("%-9s %s %s   %-8s %-14.2lf %-25lld %-14.2lf  ", name, sex, id, pin, amount, real_idcard, interest);
        //printf("%-9s %s %s   %-8s %-14.2lf %-25lld %-14.2lf  ", p->name, p->sex, p->id, p->password, p->amount, p->idcard, p->interest);
        if (state == 0) printf("冻结 ");//套用之前的输出格式，这里可以免去判断
        else printf("可用 ");
        if (realkind == 0)  printf("信用卡\n\n\n\n");
        else printf("储蓄卡\n\n\n\n");
        FILE* fp = fopen("Account.txt", "r+");//调用文件指针，准备将新开户的账户输入到文件
        fseek(fp, 0, SEEK_END);//找到文件末尾
        state = 1;
        fprintf(fp, "%s %s %s %s %lf %lld %lf %d %d\n", name, sex, id, pin, amount, real_idcard, interest, state, realkind);//输入文件
        if (realkind == 0)//若为信用卡 额度付为1000
        {
            double limit = 1000;
            FILE* temp = fopen("limit.txt", "a+");//输入额度文件
            fprintf(temp, "%s %lf %lf\n", id, limit, limit);//初始额度1000块钱
            fclose(temp);
        }
        struct Account* temp = (struct Account*)malloc(sizeof(struct Account)), * cout = head;//准备插入链表
        temp->next = NULL;//链表尾变成null
        if (head == NULL)head = temp;
        strcpy(temp->name, name), strcpy(temp->sex, sex), strcpy(temp->id, id), strcpy(temp->password, pin), temp->amount = amount;
        temp->idcard = real_idcard, temp->interest = interest, temp->state = state, temp->kind = realkind;
        while (cout != NULL && cout->next != NULL && (cout->kind == 1 || cout->kind == 0))
        {
            cout = cout->next;//链表移动
        }
        if (cout != NULL)cout->next = temp;//链表插入
        free(name), free(sex), free(pin), free(kind), free(id), free(idcard);///////////释放数据
        while (1)//判断后续操作
        {
            char key2[100];
            printf("\t\t\t\t***          继续开户，输入1        ***\n");
            printf("\t\t\t\t***        返回上一界面，输入2      ***\n");
            printf("\t\t\t\t***           结束程序输入0         ***\n");
            scanf("%s", key);
            system("cls");
            if (!strcmp(key, "1"))
            {
                printf("\n\n\n\n\n");
                break;
            }
            if (!strcmp(key, "2"))return 2;
            if (!strcmp(key, "0"))exit(0);
            printf("\t\t\t\t***        输入错误,重新输入        ***\n");
        }
    }

}
int Admin_closs_account(struct Account* head)//销户，从文件里面直接消除
{
    while (1)
    {
        printf("\t\t\t\t***           请输入卡号            ***\n");
        printf("\t\t\t\t***       返回上一界面输入-1        ***\n");
        char* id = (char*)malloc(25 * sizeof(char));//动态分配
        scanf("%s", id);
        if (!strcmp(id, "-1"))return 2;
        printf("\t\t\t\t***            请确认               ***\n");
        printf("\t\t\t\t***         若无误，输入1           ***\n");
        printf("\t\t\t\t***           否则输入0             ***\n");
        char key[100];
        scanf("%s", key);
        system("cls");
        while (strcmp(key, "1") && strcmp(key, "0"))
        {
            printf("\n\n\n\n\n\t\t\t\t***       输入错误，重新输入    ***\n");
            printf("\t\t\t\t***         若无误，输入1           ***\n");
            printf("\t\t\t\t***           否则输入0             ***\n");
            scanf("%s", key);
        }
        if (!strcmp(key, "1"))//销毁过程
        {
            struct Account* p = Search_id(head, id);//查找指针 
            if (p == NULL)
            {
                printf("\n\n\n\n\n\t\t\t\t***          卡号不存在             ***\n");
                printf("\t\t\t\t***         请重新输入卡号          ***\n\n"); \
                    continue;
            }
            delete_account(head, p);//链表删除p节点,在fundment头文件 直接形成结果的链表     由更改链表节点，再重新输入文件，从而修改
            printout_new(head);//输入文件
            free(id);
            printf("\n\n\n\n\n\t\t\t\t***           销毁成功              ***\n");
            printf("\t\t\t\t***      即将返回上一界面           ***\n");
            system("pause");
            return 2;
        }
        if (!strcmp(key, "0"))
        {
            free(id);
            printf("\n\n\n\n\n\t\t\t\t***        继续销毁，输入1          ***\n");
            printf("\t\t\t\t***      返回上一界面，输入2        ***\n");
            printf("\t\t\t\t***           结束程序输入0         ***\n");
            scanf("%s", key);
            system("cls");
            while (strcmp(key, "1") && strcmp(key, "0") && strcmp(key, "2"))
            {
                printf("\t\t\t\t***        输入错误，重新输入       ***\n");
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
int Admin_find_account(head)//查询身份证 得从文件中查询
{
    FILE* fp = fopen("regular.txt","r+" );//打开文件
    printf("\t\t\t\t***         请输入身份证            ***\n");
    printf("\t\t\t\t***         若想返回输入0           ***\n");
    char idcard[30];
    scanf("%s", idcard);//输入查询的身份证
    if(!strcmp(idcard,"0"))return 2;//返回上一界面
    while (check_integer(idcard) == 0 || strlen(idcard) != 18)//非法输入 身份证位数不对，前17位不是全数字
    {
        printf("\t\t\t\t***     身份证输入错误，请重新输入  ***\n");
        printf("\t\t\t\t***      注意，身份证为18位整数     ***\n");
        scanf("%s", idcard);
    }
    char temp[130];//存放在文件中找到的信息（idcard）
    char ans[200];//存放后续的时间等信息 等待输出
    int sum = 0;//计时器 观察找到没有
    printf("\t\t\t\t***      注意，身份证为18位整数     ***\n");
    printf("\t\t\t\t***        以下是该身份证存款信息   ***\n");
    while (fscanf(fp, "%s", temp) != EOF)
    {
        fgets(ans, 100, fp);//将后续数据读入ans数组
        if (!strcmp(idcard, temp))
        {
            printf("\t\t\t\t%s\n", ans);
            sum++;
        }
    }
    if (sum == 0) printf("\t\t\t\t***           该身份证暂无存款      ***\n");//当没找到账户时
    printf("\t\t\t\t***        程序将返回上一界面       ***\n");
    system("pause");
    return 2;
}
int Admin_business(FILE* fp, struct Account* head)//用户文件，和链表
{

    int key, key2 = 2;//key界面进入值，和判断用户执行完一个操作接下来干什么  key2给子页面返回值存放空间，判断是否退出
    while (key2 == 2)
    {
        key = Admin_business_menu();
        if (key == -1)return 1;//返回上一界面
        if (key == 1) Admin_save_withdraw_regular_new();//////存取款
        if (key == 2) key2 = Admin_unfreeze(head);//解冻
        if (key == 3) key2 = Admin_freeze(head);//冻结
        if (key == 4) key2 = Admin_change_interest();//key2==0 退出程序（全部程序） key2==2 继续业务 
        if (key == 5) key2 = Admin_creat_account(head);//开户
        if (key == 6) key2 = Admin_closs_account(head);//销户
        if (key == 7)key2 = Admin_find_account(head);
        if (key2 == 0) return 3;
        system("cls");
    }
}
int change_admin_pin()//改变管理员密码
{
    FILE* fp = fopen("Admin.txt", "r+");
    while (1)
    {
        printf("\t\t\t\t\t***    输入新密码       ***\n");
        printf("\t\t\t\t\t** 请注意密码不得超过20位**\n");
        printf("\t\t\t\t\t***    返回输入0        ***\n");
        char pin[200], check[200];
        scanf("%s", pin);
        if (!strcmp(pin, "0"))
        {
            fclose(fp);
            return 1;//返回上一界面 key==1
        }
        while (strlen(pin) > 20)//位数超过20
        {
            printf("\t\t\t\t\t** 请注意密码不得超过20位**\n");
            printf("\t\t\t\t\t**         请重新输入    **\n");
            scanf("%s", pin);
        }
        printf("\t\t\t\t\t    你的新密码是%s \n", pin);
        printf("\t\t\t\t\t*** 确认无误输入  yes   ***\n");
        printf("\t\t\t\t\t***   否则输入任意值\n");
        scanf("%s", check);
        if (!strcmp(check, "yes"))//确认无误
        {
            fprintf(fp, "%-20s", pin);//输入到文件
            printf("\t\t\t\t\t***     更改成功    ***\n");
            printf("\t\t\t\t\t输入任意值返回上一界面 \n");
            system("pause");
            fclose(fp);
            return 1;//返回上一界面
        }
        else
        {
            system("cls");

        }
    }
}