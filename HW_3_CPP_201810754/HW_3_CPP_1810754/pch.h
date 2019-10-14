#ifndef PCH_H
#define PCH_H

#include <iostream> //기본 출력함수
#include <cstdio>//c언어 라이브러리함수 c언어의 printf문등을 위해
#include <conio.h> //getch, 등의 함수를 위해 포함
#include <string>	  //string 문자열 을 사용하기위해
#include <cstdlib> //rand함수 사용을 위해
#include <time.h> //rand함수의 시드를 시간에서 받아오기위해
#include "console_cont.h" //console컨트롤 윈도우api가져와서 함수 정의부
#include "Cell.h"  //cell클래스
using namespace std;

//방향키 방향키는 실제로 키입력이 두번됨 224+방향 
#define ARROWKEY 224 
#define LEFT 75 
#define RIGHT 77
#define UP 72
#define DOWN 80
//엔터키
#define ENTER 13

#endif //PCH_H
