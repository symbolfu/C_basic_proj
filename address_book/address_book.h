#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <conio.h>
#include <string.h>


/*
	ͨѶ¼����ϵͳ��
		1��ͨѶ¼¼�룻
		2��ͨѶ¼��ѯ��
		3��ͨѶ¼ɾ����
		4��ͨѶ¼�б���ʾ��
		5��ͨѶ¼���ݱ��棻
		6��ͨѶ¼���ݼ��أ�
		7���˳�ϵͳ��

*/

struct Info
{
	char name[15];
	char city[10];
	char province[10];
	char state[10];
	char tel[15];
};

// ����
typedef struct node
{
	struct Info data;
	struct node* next;
} Node, * link;



void stringinput(char* t, int lens, char* notice);

// input records
void enter(link l);

// delete record
void del(link l);

// node display info
void display(Node* p);

// search
void search(link l);


// link display info
void list(link l);

// save
void save(link l);


// load file
void load(link l);

// menu
int menu_select();







