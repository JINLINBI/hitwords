/*************************************************************************
    > File Name: words.h 
    > Author: jinlin
    > Mail: 898141731@qq.com 
    > Created Time: 2016年05月03日 星期二 22时10分16秒
 ************************************************************************/

#include<string>
#include<vector>
#include<fstream>
using namespace std;
class Words{
public:
	Words();
	bool init();
	bool show(int);//显示需要打印的数据
	int ishit(string);//判断传入的string是否与words的其中一个相同。
	bool isfull(int);
	bool updateword(int);//刷新单词
	bool resetx(int);
	int readfile();
	int addscore();
	int descore();
private:
	vector<string> sbuf;
	int speed;
	string word0[2];
	string word1[2];
	string word2[2];
	string word3[2];
	int x0;
	int x1;
	int x2;
	int x3;
	short randoms0;
	short randoms1;
	short randoms2;
	short randoms3;
	string hitword;
	int score;
};
