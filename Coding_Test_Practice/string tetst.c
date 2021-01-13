//
//  string tetst.c
//  Coding_Test_Practice
//
//  Created by 김난영 on 2020/06/12.
//  Copyright © 2020 KimNanyoung. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int size = 0;
char newMsg[100];
char* userName[2] = {"john", "kevin"};
char* fn[100];
int main(){
    
    
    for(int i = 0; i<100; i++){
        newMsg[i] = '\0';
    }
    char newMsg[100] = "hi i'm kevin";
    char *f_n = "@jhn";
    f_n++;
    
    int chkLen = 0;
    int check = 0;
    
    char *copyf_n = f_n;
    char *copyuserName = userName[0];
    
    
    if(*f_n == *userName[0]){
        printf("correct");
    }
    
    
    
    for(int i = 0; i<10; i++){
        if(copyf_n[i] == copyuserName[i]){
            chkLen++;
        }
    }
    
    printf("%d", chkLen);
    
    
    
    
    
    
    //char *resMsg[100];
    
    
    
    
//   sprintf(resMsg, "%s %s", userName[0], newMsg);
//
//    printf("%s",resMsg);
//
    
    
    
    
//    char msg[100] = "@john hi i'm kevin\n";
//    char friend_name[100];
//    strcpy(friend_name, msg);
//
//    char *f_n = strtok(friend_name, " ");
//
//    printf("%s\d", f_n);
//
//
//    for(int i = 0; i<100; i++){
//
//        if(f_n[i] != NULL){
//            size++;
//        }
//        else{
//            break;
//        }
//    }
//
//
//    printf("%d\n", size-1);
//
//    for(int i = 0; i<50; i++){
//        newMsg[i] = msg[size+1+i];
//    }
//
//    printf("%s", newMsg);
//
    
    
    
    return 0;
}
