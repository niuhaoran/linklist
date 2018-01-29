//
//  main.c
//  linklist
//
//  Created by haoran niu on 2018/1/29.
//  Copyright © 2018年 haoran niu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


//定义节点的结构
typedef struct node {
    int data;
    struct node *next;
}NODE;

//初始化一个节点
NODE* initNode(int data) {
    NODE* pnode = (NODE *)malloc(sizeof(NODE));
    pnode->data = data;
    pnode->next = NULL;
    return pnode;
}

//头插一个新节点
NODE* createHeadNode(NODE* phead, int data) {
    NODE* newNode = initNode(data);
    NODE* ptemp = phead;
    if(phead){
        phead = newNode; //把新节点作为头部
        newNode->next = ptemp;
    }else{
        return newNode;
    }
    return phead;
}

//尾插创建一个新节点
NODE* createLastNode(NODE* phead, int data) {
    NODE* newNode = initNode(data);
    if(phead){
        NODE* ptemp = phead;
        while(ptemp && ptemp->next){
            ptemp = ptemp->next; //找到最后一个节点
        }
        ptemp->next = newNode;
    }else{
        return newNode;
    }
    return phead;
}

//按值查找
NODE* searchNode(NODE* phead,int key) {
    NODE* ptemp = phead;
    
    if(ptemp){
        while(ptemp){
            if(ptemp->data && ptemp->data == key){
                return ptemp;
            }
            ptemp = ptemp->next;
        }
    }else{
        return NULL;
    }
    return NULL;
}

//向前插入
NODE* insertNodePre(NODE* phead,int key,int data) {
    NODE *newNode = initNode(data);
    if(phead){
        NODE* ptemp = phead;
        if(ptemp->data && ptemp->data == key){ //只有一个节点
            phead = newNode;
            newNode->next = ptemp;
        }else{
            while(ptemp && ptemp->next){ 
                NODE* backNode = ptemp->next;
                if(backNode->data && backNode->data == key){ //找到下一个节点
                    newNode->next = backNode;
                    ptemp->next = newNode;
                    return phead;
                }
                ptemp = ptemp->next;
            }
        }
    }else{
        return newNode;
    }
    return phead;
}

//向后插入
NODE* insertNodeBack(NODE* phead,int key,int data) {
    NODE* newNode = initNode(data);
    if(phead){
        NODE* ptemp = phead;
        if(ptemp->data && ptemp->data == key){//只有一个节点
            ptemp->next = newNode;
        }else{
            while(ptemp){
                if(ptemp->data && ptemp->data == key){
                    newNode->next = ptemp->next;
                    ptemp->next = newNode;
                    return phead;
                }
                ptemp = ptemp->next;
            }
        }
    }else{
        return newNode;
    }
    return phead;
}

//统计节点个数
int linkLength(NODE* phead){
    int n = 0;
    if(phead){
        NODE* temp = phead;
        while(temp){
            n = n+1;
            temp = temp->next;
        }
    }
    return n;
}

//删除一个节点
NODE* deleteOneNode(NODE* phead,int key) {
    if(phead){
        NODE* temp = phead;
        if(temp->data && temp->data == key) { //删除第一个节点
            free(temp);
            temp = NULL;
        }else{
            while(temp && temp->next){
                NODE* backNode = temp->next;
                if(backNode->data && backNode->data == key) {
                    temp->next = backNode->next;
                    free(backNode);
                    backNode = NULL;
                    return phead;
                }
                temp = temp->next;
            }
        }
    }else{
        printf("sorry, your linkList is NULL");
        return NULL;
    }
    return phead;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    NODE* p0 = initNode(1);
    printf("phead:%d\n",p0->data);

    p0 = createLastNode(p0,2);
    p0 = createHeadNode(p0,3);

    NODE* pTemp = p0;
    while(pTemp){
        printf("p0:%d\n",pTemp->data);
        pTemp=pTemp->next;
    }
    
    pTemp = p0;
    NODE* sNode = searchNode(pTemp,2);
    if (sNode && sNode->data) {
        printf("searchNode:%p  %d\n",sNode,sNode->data);
    }
    pTemp = p0;
    printf("linkLength:%d\n",linkLength(pTemp));
    
    p0 = insertNodeBack(p0,2,4);
    pTemp = p0;
    printf("linkLength01:%d\n",linkLength(pTemp));
    
    p0 = insertNodePre(p0,4,5);
    pTemp = p0;
    printf("linkLength02:%d\n",linkLength(pTemp));

    p0 = deleteOneNode(p0,1);
    pTemp = p0;
    printf("linkLength03:%d\n",linkLength(pTemp));

    pTemp = p0;
    while(pTemp){
        printf("p00000:%d\n",pTemp->data);
        pTemp=pTemp->next;
    }

    return 0;
}
