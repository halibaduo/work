#include <stdio.h>
#include <iostream>
using namespace std;
char token; 
char str[20]="\0"; 
char* p;


void E();
void E1();  
void T();
void T1();
void F();
void match(char);  



void match(char ch){
	if(token == ch) {
		p++; token = *p;
	}else {
		;  
	}
}

void E(){ 
	//printf("coming1");
	switch(token) {
		case '(': 
		case 'i': T(); E1(); break;
		default: break; 
	}
}

void E1() { 
	switch(token) {
		case '+': match('+'); T(); E1(); break;
		case ')': 
		case '$': break;
		default: break;
	}
}

void T() { 
	switch(token) {
		case '(':
		case 'i': F(); T1(); break;
		default: break; 	
	}
}

void T1() {  
	switch(token) {
		case '*': match('*'); F(); T1(); break;
		case ')': 
		case '$':
		case '+':break;
		default: break;	
	}
}

void F() { 
	switch(token) {
		case '(': match('('); E(); match(')'); break;
		case 'i': match('i'); break;
		default: break;
	}
}

int main(void)
{
	scanf("%s",&str);
	p = str;
	token = *p; 
	E(); 
	if(token == '$') {
		printf("success,此字符串能被接受");
	}else {
		printf("fail,此字符串不能被接受");
	}
    return 0;
}