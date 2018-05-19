//
//  main.c
//  testing_sorting
//
//  Created by biplop hossain on 14/5/18.
//  Copyright © 2018 biplop hossain. All rights reserved.
//

//
//  main.c
//  sorting
//
//  Created by biplop hossain on 9/5/18.
//  Copyright © 2018 biplop hossain. All rights reserved.
//  merge sort

#include <stdio.h>
#include <stdlib.h>

void MergeSort(int *a,int length);
void Merge(int *a,int *L,int *R,int length);

int main(){
    int a[7] ={99,36,55,2,1,27,92};
    int i =0;
    MergeSort(a,7);
    for(i = 0;i<7;i++){
        printf("%d\t",a[i]);
    }
    printf("\n\n\n");
    return 0;
}
void MergeSort(int *a,int length){
    int mid=0;
    int *L,*R,i,j;
    mid = length/2;
    if(length < 2){
        return;
    }else{
        L = (int*)malloc(sizeof(int)*mid);
        R = (int*)malloc(sizeof(int)*(length-mid));
        for(i=0;i<mid;i++){
            L[i] = a[i];
        }
        
        for(j=mid;j<length;j++){
            R[j-mid] =a[j];
        }
        
        MergeSort(L,mid);
        MergeSort(R,length-mid);
        Merge(a,L,R,length);
    }
}
void Merge(int *a,int *L,int *R,int length){
    int i=0,j=0,k=0;
    int mL,mR;
    mL = length/2;
    mR = length -mL;
    while(i<mL && j<mR){
        if(L[i] < R[j]){
            a[k] = L[i];
            i++;
        }else{
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<mL){
        a[k] = L[i];
        i++;
        k++;
    }
    while(j<mR){
        a[k] = R[j];
        j++;
        k++;
    }
    
}

