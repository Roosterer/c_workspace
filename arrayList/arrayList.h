/*
 * arrayList.h
 *
 *  Created on: 2017Äê10ÔÂ24ÈÕ
 *      Author: gaokuo
 */
#include <stdio.h>

#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

#define MAXSIZE 20
#define true 1
#define false 0
//#define OK 1
//#define ERROR -1

typedef int boolean;
typedef int Element;

typedef struct{
	Element data[MAXSIZE];
	int length;
}ArrayList;

void printList(ArrayList *list);

boolean init(ArrayList *list);

int getLength(ArrayList *list);

boolean isEmpty(ArrayList *list);

boolean clear(ArrayList *list);

boolean add(ArrayList *list,Element e);

boolean set(ArrayList *list,int index,Element e);

boolean removeOne(ArrayList *list,int index,Element e);

boolean getOne(ArrayList *list,int index,Element *e);

boolean rangeCheck(ArrayList *list,int index);







#endif /* ARRAYLIST_H_ */
