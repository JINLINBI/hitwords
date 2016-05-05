/*************************************************************************
  > File Name: main.cpp
  > Author: jinlin
  > Mail: 898141731@qq.com 
  > Created Time: 2016年05月03日 星期二 22时30分59秒
 ************************************************************************/

#include<iostream>
#include<unistd.h>
#include<string>
#include<sys/ioctl.h>//ioctl.h引入ioctl函数。
#include"words.cpp"
using namespace std;
int kbhit();
int main(){
	char c;
	system("stty -echo");
	string str;
	int i=3;
	Words words;
	while(1){
		system("clear");
		words.show(i++);
		//sleep(1);
		usleep(200000);//睡眠5毫秒
		if(kbhit()){
			cin>>str;
			if(str.length()==1)
				break;
			if(words.ishit(str)>-1)//判断是否相同)
				//cout<<str<<endl;
			{
				words.updateword(words.ishit(str));
				words.addscore();
			}
			else{
				//cout<<"error"<<endl;
				words.descore();
			}
		}
	}
	system("stty echo");
	return 0;
}
int kbhit(){
	int i;
	ioctl(0,FIONREAD,&i);
	return i;
}
