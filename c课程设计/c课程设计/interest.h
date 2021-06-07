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
		fscanf(fp, "%s %d %d %d", trash_id, &trash_date.year, &trash_date.month, &trash_date.day);//得到上次结息的日期
		if (!strcmp((*user_id)->id, trash_id)) {//当得到正确的目标时结束
			key1 = 1;
			break;
		}
	}
	if (key1 == 0) {
		rewind(fp);
		char trash[21];
		int y, m, d;
		while (!feof(fp)) {
			fscanf(fp, "%s %d %d %d", trash, &y, &m, &d);//进行文件的提取
			fprintf(fpnew, "\n%s %d %d %d", trash, y, m, d);//其余不变
		}
		fprintf(fpnew, "\n%s %d %d %d", (*user_id)->id, year, month, day);//其余不变
		fclose(fpnew);
		fclose(fp);
		fclose(fptrade);
		remove("Date.txt");//将副本进行替换
		rename("date_annex.txt", "Date.txt");
		return;
	}
	if (year >= trash_date.year) {//进行日期的计算
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
		fprintf(fptrade, "\n%s %d %d %d 利息结算%.2lf元", (*user_id)->id, trash_date.year, trash_date.month, day, (*user_id)->interest);//交易记录的储存
		trash_date.month++;
		(*user_id)->amount += (*user_id)->amount * Get_interest_ava() * 30;
		(*user_id)->interest -= (*user_id)->amount * Get_interest_ava() * 30;
		if (trash_date.month > 12) {//保证月数的合法
			trash_date.month -= 12;
			trash_date.year++;
		}
	}
	while (probit >= 30) {//当可以结息时的操作
		fseek(fptrade, 0L, SEEK_END);
		key = 1;//记录可以结息
		probit -= 30;
		trash_date.month++;
		double trash;
		trash = (*user_id)->amount * 30 * Get_interest_ava();//计算利息
		if (trash_date.month > 12) {//保证月数的合法
			trash_date.month -= 12;
			trash_date.year++;
		}
		(*user_id)->amount += trash;//结息
		fprintf(fptrade, "\n%s %d %d %d 利息结算%.2lf元", (*user_id)->id, trash_date.year, trash_date.month, trash_date.day, trash);//交易记录的储存
	}
	trash_date.day += probit;//增加剩余的天数
	if (trash_date.month == 1 || trash_date.month == 3 || trash_date.month == 5 || trash_date.month == 7 || trash_date.month == 8 || trash_date.month == 10 || trash_date.month == 12) {//判断这个月有多少天
		while (trash_date.day > 31) {//31天则减去31
			trash_date.day -= 31;
			trash_date.month++;
		}
	}
	else {//30天的情况
		while (trash_date.day > 30) {//减去30天
			trash_date.day -= 30;
			trash_date.month++;
		}
	}
	while (trash_date.month > 12) {//当月份超过时，增加年份
		trash_date.month -= 12;
		trash_date.year++;
	}
	rewind(fp);
	char trash[21];
	int y, m, d;
	while (!feof(fp)) {
		fscanf(fp, "%s %d %d %d", trash, &y, &m, &d);//进行文件的提取
		if (!strcmp(trash, (*user_id)->id)) {
			fprintf(fpnew, "\n%s %d %d %d", trash, year, month, day);//指定内容的更改
		}
		else {
			fprintf(fpnew, "\n%s %d %d %d", trash, y, m, d);//其余不变
		}
	}
	fclose(fpnew);
	fclose(fp);
	fclose(fptrade);
	remove("Date.txt");//将副本进行替换
	rename("date_annex.txt", "Date.txt");

}
