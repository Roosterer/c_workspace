/*
 * arrayList.c
 *
 *  Created on: 2017年10月24日
 *      Author: gaokuo
 */
#include "arrayList.h"


/**
 *打印集合
 */
void printList(ArrayList *list){
	if(list->length == 0){
		printf("集合为空\n");
	}
	printf("集合元素：{ ");
	for(int i = 0;i < list->length;i++){
		printf("%d ",list->data[i]);
	}
	printf("}\n");
}

/**
 *初始化集合，给list中的data数组赋默认值
 */
boolean init(ArrayList *list){
	for(int i=0;i<MAXSIZE;i++){
		list->data[i]=0;
	}
	list->length=0;
	return true;
}

/**
 *获取线性表长度，即已经使用了的数组长度
 */
int getLength(ArrayList *list){
	return list->length;
}

/**
 *判断线性表是否为空，返回布尔值（1,0）
 */
boolean isEmpty(ArrayList *list){
	if(list->length == 0){
		return true;
	}
	return true;
}

/**
 * 清空list，data数组赋默认值，length赋0
 */
boolean clear(ArrayList *list){
	for(int i=0;i<MAXSIZE;i++){
		list->data[i]=0;
	}
	list->length=0;
	return true;;
}

/**
 *list末端增加元素e
 */
boolean add(ArrayList *list,Element e){
	//判断是否超出界限
	if(list->length >= MAXSIZE-1){
		printf("###集合已满，add失败###\n");
		return false;
	}
	list->data[list->length] = e;
	list->length++;
	return true;
}

/**
 *list指定位置插入元素，如果有元素则进行修改操作
 */
boolean set(ArrayList *list,int index,Element e){
	if(!rangeCheck(list,index)){
			return false;
		}
	list->data[index] = e;
	return true;
}

/**
 *删除集合指定位置元素
 */
boolean removeOne(ArrayList *list,int index,Element e){
	if(!rangeCheck(list,index)){
		return false;
	}
	Element oldValue;
	if(getOne(list,index,&oldValue)){
		//index位置之后的所有元素向前移动一位
		Element temp;
		for(;index < list->length;index++){
			temp = list->data[index+1];
			list->data[index]=temp;
		}
		list->length--;
		return true;
	}else{
		return false;
	}
}

/**
 * 获取集合指定位置元素
 */
boolean getOne(ArrayList *list,int index,Element *e){
	if(!rangeCheck(list,index)){
		return false;
	}
	*e = list->data[index];
	return true;
}

/**
 *校验给定的下标是否查出集合限制
 */
boolean rangeCheck(ArrayList *list,int index){
	if(index < 0 || index > (list->length-1)){
		printf("###集合size：%d，错误的下标位置：%d###\n",list->length,index);
		return false;
	}
	return true;
}



int main(int argc, char **argv) {

	printf("===run start===\n");
	printf("\n");

	//创建list
	ArrayList list;
	//获取list指针
	ArrayList *pList = &list;
	//初始化list
	init(pList);
	//输出list长度
	printf("list size：%d\n",getLength(pList));
	//判断list是否为空
	printf("list isEmpty：%d\n",isEmpty(pList));
	//添加元素到集合
	add(pList,11);
	add(pList,22);
	add(pList,33);
	add(pList,44);
	add(pList,55);
	printList(pList);
	//修改元素值
	set(pList,0,888);
	printList(pList);
	//获取元素
	Element e ;
	Element *pe = &e;
	getOne(pList,0,pe);
	printf("getOne：%d\n",e);
	//删除元素
	removeOne(pList,0,e);
	printf("removeOne：%d\n",e);
	printList(pList);

	printf("\n");
	printf("===run over===\n");
	return 1;
}


