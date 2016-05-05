/*************************************************************************
    > File Name: words.cpp
    > Author: jinlin
    > Mail: 898141731@qq.com 
    > Created Time: 2016年05月03日 星期二 22时19分35秒
 ************************************************************************/

#include <iostream>
#include "words.h"
//#include <curses.h>
#include <stdlib.h>
#include<time.h>
#include <fstream>
#include "constant.h"
#include<iomanip>
using namespace std;
Words::Words(){
	score=0;
	readfile();
	for(int i=0;i<4;i++)
		updateword(i);
}
int Words::addscore(){
	score++;
	return 1;
}
bool Words::updateword(int i){
	srand((unsigned)time(NULL));
	switch(i){
		case 0:
			word0[0]=sbuf[rand()%sbuf.size()];//抽出容器随机一个
			word0[1]=word0[0].substr(word0[0].find(" "),word0[0].length());
			word0[0]=word0[0].substr(0,word0[0].find(" "));
			sbuf.pop_back();
			randoms0=rand()%4+1;
			x0=word0[0].length();
			break;
		case 1:
			word1[0]=sbuf[rand()%sbuf.size()];//抽出容器随机一个
			word1[1]=word1[0].substr(word1[0].find(" "),word1[0].length());
			word1[0]=word1[0].substr(0,word1[0].find(" "));
			sbuf.pop_back();
			randoms1=rand()%4+1;
			x1=word1[0].length();
			break;
		case 2:
			word2[0]=sbuf[rand()%sbuf.size()];//抽出容器随机一个
			word2[1]=word2[0].substr(word2[0].find(" "),word2[0].length());
			word2[0]=word2[0].substr(0,word2[0].find(" "));
			sbuf.pop_back();
			randoms2=rand()%4+1;
			x2=word2[0].length();
			break;
		case 3:
			word3[0]=sbuf[rand()%sbuf.size()];//抽出容器随机一个
			word3[1]=word3[0].substr(word3[0].find(" "),word3[0].length());
			word3[0]=word3[0].substr(0,word3[0].find(" "));
			sbuf.pop_back();
			randoms3=rand()%4+1;
			x3=word3[0].length();
			break;
	}
	return 1;
}
bool Words::isfull(int i){
	int r=0;
	switch(i){
		case 0:
			if(x0 > MAXWIDTH)
			{
				descore();
				updateword(i);
				r=1;

			}
			break;
		case 1:
			if(x1 > MAXWIDTH)
			{
				descore();
				updateword(i);
				r=1;

			}
			break;
		case 2:
			if(x2 > MAXWIDTH)
			{
				descore();
				updateword(i);
				r=1;

			}
			break;
		case 3:
			if(x3 > MAXWIDTH)
			{
				descore();
				updateword(i);
				r=1;

			}
			break;
	}
	return r;
}
bool Words::resetx(int i){
	switch(i){
		case 0:
			x0=0;
			break;
		case 1:
			x1=0;
			break;
		case 2:
			x2=0;
			break;
		case 3:
			x3=0;
			break;
	}
	return 0;
}
bool Words::show(int i){
	system("clear");
		cout<<setw(x0)<<word0[0]<<endl;
		cout<<setw(x1)<<word1[0]<<endl;
		cout<<setw(x2)<<word2[0]<<endl;
		cout<<setw(x3)<<word3[0]<<endl;
		if(!(i%randoms0))
			x0+=1;
		if(!(i%randoms1))
			x1+=1;
		if(!(i%randoms2))
			x2+=1;
		if(!(i%randoms3))
			x3+=1;
		for(int k=0;k<4;k++)
			if(isfull(k))
				resetx(k);
		//	cout<<isfull(k);
		//		resetx(k);
		cout<<endl;
		cout<<"*******************************************************************"<<endl;
		cout<<"*******************************************************************"<<endl;
		cout<<"*******************************************************************"<<endl;
		cout<<"*****                                                         *****"<<endl;
		cout<<"*****                                                         *****"<<endl;
		cout<<" "<<setw(43)<<hitword<<setw(25)<<" "<<endl;
		cout<<"*****                                                         *****"<<endl;
		cout<<"*****                                                         *****"<<endl;
		cout<<"*******************************************************************"<<endl;
		cout<<"*******************************************************************"<<endl;
		cout<<"*******************************************************************"<<endl;
		cout<<setw(35)<<"你的分数："<<score<<endl;
		cout<<"*******************************************************************"<<endl;
		cout<<"*****                   输入1字符回车退出                     *****"<<endl;
		cout<<"*******************************************************************"<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
	return 1;
}
bool Words::init(){
	
}
int  Words::readfile(){//读取文件到sbuf
	char buf[80];
	ifstream fin("words.txt");
	while(fin.getline(buf,80))
	{
		string str=buf;
		sbuf.push_back(str);
	}
	fin.close();
}
int  Words::ishit(string str){
	int i=-1;
	if(str ==word0[0])
	{
		hitword=word0[1];
		i=0;
	}
	else if(str == word1[0])
	{
		hitword=word1[1];
		i=1;
	}
	else if(str == word2[0])
	{
		hitword=word2[1];
		i=2;
	}
	else if(str == word3[0]){
		hitword=word3[1];
		i=3;
	}
	return i;
}
int Words::descore(){
	if(score>0)
		score--;
	return 1;
}
