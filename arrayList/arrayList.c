/*
 * arrayList.c
 *
 *  Created on: 2017��10��24��
 *      Author: gaokuo
 */
#include "arrayList.h"


/**
 *��ӡ����
 */
void printList(ArrayList *list){
	if(list->length == 0){
		printf("����Ϊ��\n");
	}
	printf("����Ԫ�أ�{ ");
	for(int i = 0;i < list->length;i++){
		printf("%d ",list->data[i]);
	}
	printf("}\n");
}

/**
 *��ʼ�����ϣ���list�е�data���鸳Ĭ��ֵ
 */
boolean init(ArrayList *list){
	for(int i=0;i<MAXSIZE;i++){
		list->data[i]=0;
	}
	list->length=0;
	return true;
}

/**
 *��ȡ���Ա��ȣ����Ѿ�ʹ���˵����鳤��
 */
int getLength(ArrayList *list){
	return list->length;
}

/**
 *�ж����Ա��Ƿ�Ϊ�գ����ز���ֵ��1,0��
 */
boolean isEmpty(ArrayList *list){
	if(list->length == 0){
		return true;
	}
	return true;
}

/**
 * ���list��data���鸳Ĭ��ֵ��length��0
 */
boolean clear(ArrayList *list){
	for(int i=0;i<MAXSIZE;i++){
		list->data[i]=0;
	}
	list->length=0;
	return true;;
}

/**
 *listĩ������Ԫ��e
 */
boolean add(ArrayList *list,Element e){
	//�ж��Ƿ񳬳�����
	if(list->length >= MAXSIZE-1){
		printf("###����������addʧ��###\n");
		return false;
	}
	list->data[list->length] = e;
	list->length++;
	return true;
}

/**
 *listָ��λ�ò���Ԫ�أ������Ԫ��������޸Ĳ���
 */
boolean set(ArrayList *list,int index,Element e){
	if(!rangeCheck(list,index)){
			return false;
		}
	list->data[index] = e;
	return true;
}

/**
 *ɾ������ָ��λ��Ԫ��
 */
boolean removeOne(ArrayList *list,int index,Element e){
	if(!rangeCheck(list,index)){
		return false;
	}
	Element oldValue;
	if(getOne(list,index,&oldValue)){
		//indexλ��֮�������Ԫ����ǰ�ƶ�һλ
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
 * ��ȡ����ָ��λ��Ԫ��
 */
boolean getOne(ArrayList *list,int index,Element *e){
	if(!rangeCheck(list,index)){
		return false;
	}
	*e = list->data[index];
	return true;
}

/**
 *У��������±��Ƿ�����������
 */
boolean rangeCheck(ArrayList *list,int index){
	if(index < 0 || index > (list->length-1)){
		printf("###����size��%d��������±�λ�ã�%d###\n",list->length,index);
		return false;
	}
	return true;
}



int main(int argc, char **argv) {

	printf("===run start===\n");
	printf("\n");

	//����list
	ArrayList list;
	//��ȡlistָ��
	ArrayList *pList = &list;
	//��ʼ��list
	init(pList);
	//���list����
	printf("list size��%d\n",getLength(pList));
	//�ж�list�Ƿ�Ϊ��
	printf("list isEmpty��%d\n",isEmpty(pList));
	//���Ԫ�ص�����
	add(pList,11);
	add(pList,22);
	add(pList,33);
	add(pList,44);
	add(pList,55);
	printList(pList);
	//�޸�Ԫ��ֵ
	set(pList,0,888);
	printList(pList);
	//��ȡԪ��
	Element e ;
	Element *pe = &e;
	getOne(pList,0,pe);
	printf("getOne��%d\n",e);
	//ɾ��Ԫ��
	removeOne(pList,0,e);
	printf("removeOne��%d\n",e);
	printList(pList);

	printf("\n");
	printf("===run over===\n");
	return 1;
}


