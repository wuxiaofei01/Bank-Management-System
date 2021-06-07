#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#include "fundment.h"
#pragma once
void cumclate(int year, int month, int day, struct Account** user_id) {
	FILE* fp = fopen("Date.txt", "r");
	FILE* fpnew = fopen("date_annex.txt", "w");
	FILE* fptrade = fopen("trade.txt", "r+");
	struct Date trash_date;
	char trash_id[21];
	long long probit = 0;
	int key = 0, key1 = 0;
	while (!feof(fp)) {
		fscanf(fp, "%s %d %d %d", trash_id, &trash_date.year, &trash_date.month, &trash_date.day);//�õ��ϴν�Ϣ������
		if (!strcmp((*user_id)->id, trash_id)) {//���õ���ȷ��Ŀ��ʱ����
			key1 = 1;
			break;
		}
	}
	if (key1 == 0) {
		rewind(fp);
		char trash[21];
		int y, m, d;
		while (!feof(fp)) {
			fscanf(fp, "%s %d %d %d", trash, &y, &m, &d);//�����ļ�����ȡ
			fprintf(fpnew, "\n%s %d %d %d", trash, y, m, d);//���಻��
		}
		fprintf(fpnew, "\n%s %d %d %d", (*user_id)->id, year, month, day);//���಻��
		fclose(fpnew);
		fclose(fp);
		fclose(fptrade);
		remove("Date.txt");//�����������滻
		rename("date_annex.txt", "Date.txt");
		return;
	}
	if (year >= trash_date.year) {//�������ڵļ���
		probit += (year - trash_date.year) * 360;
	}
	if (month >= trash_date.month) {
		probit += (month - trash_date.month) * 30;
	}
	if (day >= trash_date.day) {
		probit += day - trash_date.day;
	}
	if (probit < 30) {
		(*user_id)->interest += (*user_id)->amount * Get_interest_ava() * probit;
	}
	if ((*user_id)->interest >= (*user_id)->amount * Get_interest_ava() * 30) {
		fseek(fptrade, 0L, SEEK_END);
		fprintf(fptrade, "\n%s %d %d %d ��Ϣ����%.2lfԪ", (*user_id)->id, trash_date.year, trash_date.month, day, (*user_id)->interest);//���׼�¼�Ĵ���
		trash_date.month++;
		(*user_id)->amount += (*user_id)->amount * Get_interest_ava() * 30;
		(*user_id)->interest -= (*user_id)->amount * Get_interest_ava() * 30;
		if (trash_date.month > 12) {//��֤�����ĺϷ�
			trash_date.month -= 12;
			trash_date.year++;
		}
	}
	while (probit >= 30) {//�����Խ�Ϣʱ�Ĳ���
		fseek(fptrade, 0L, SEEK_END);
		key = 1;//��¼���Խ�Ϣ
		probit -= 30;
		trash_date.month++;
		double trash;
		trash = (*user_id)->amount * 30 * Get_interest_ava();//������Ϣ
		if (trash_date.month > 12) {//��֤�����ĺϷ�
			trash_date.month -= 12;
			trash_date.year++;
		}
		(*user_id)->amount += trash;//��Ϣ
		fprintf(fptrade, "\n%s %d %d %d ��Ϣ����%.2lfԪ", (*user_id)->id, trash_date.year, trash_date.month, trash_date.day, trash);//���׼�¼�Ĵ���
	}
	trash_date.day += probit;//����ʣ�������
	if (trash_date.month == 1 || trash_date.month == 3 || trash_date.month == 5 || trash_date.month == 7 || trash_date.month == 8 || trash_date.month == 10 || trash_date.month == 12) {//�ж�������ж�����
		while (trash_date.day > 31) {//31�����ȥ31
			trash_date.day -= 31;
			trash_date.month++;
		}
	}
	else {//30������
		while (trash_date.day > 30) {//��ȥ30��
			trash_date.day -= 30;
			trash_date.month++;
		}
	}
	while (trash_date.month > 12) {//���·ݳ���ʱ���������
		trash_date.month -= 12;
		trash_date.year++;
	}
	rewind(fp);
	char trash[21];
	int y, m, d;
	while (!feof(fp)) {
		fscanf(fp, "%s %d %d %d", trash, &y, &m, &d);//�����ļ�����ȡ
		if (!strcmp(trash, (*user_id)->id)) {
			fprintf(fpnew, "\n%s %d %d %d", trash, year, month, day);//ָ�����ݵĸ���
		}
		else {
			fprintf(fpnew, "\n%s %d %d %d", trash, y, m, d);//���಻��
		}
	}
	fclose(fpnew);
	fclose(fp);
	fclose(fptrade);
	remove("Date.txt");//�����������滻
	rename("date_annex.txt", "Date.txt");

}
