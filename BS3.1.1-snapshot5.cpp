#include<bits/stdc++.h>
#include<windows.h>
#include<pthread.h>
#define kbhit(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Og")
#pragma comment(lib,Winmm.lib)
#define pass
#define IDOK 1
#define IDCANCEL 2
#define IDABORT 3
#define IDRETRY 4
#define IDIGNORE 5
#define IDYES 6
#define IDNO 7
#define IDCLOSE 8
#define IDHELP 9
#define IDTRYAGAIN 10
#define IDCONTINUE 11
#define FILENAME "Anticheater.exe"
#define SETNAME "BS3.1.2.set" 
#define setcolor(a) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | a);
using namespace std;
int dis,level,day,intinput,gametime;
int main();
bool finish;
void gamemain();
string getTime() {
	time_t timep;
	time (&timep);
	char tmp[64];
	strftime(tmp,sizeof(tmp),"%H:%M:%S",localtime(&timep));
	return tmp;
}
void loadlog(int type,string detail) {
	ofstream logout("BSlog.txt",ios::app);
	string TIME=getTime();
	logout<<TIME<<" ";
	if(type==1){
		logout<<"[Info]:";
	}
	else if(type==2){
		logout<<"[Warning]:";
	}
	else if(type==3){
		logout<<"[Error]:";
	}
	else{
		logout<<"[Fatal]:";
	}
	logout<<detail<<endl;
	logout.close();
}
inline int rand_number(int x) {
	srand(time(NULL)+x*x);
	return abs(rand()+x*x);
}
bool match(int a[],int b[]) {
	for(int i=1; i<=7; i++) {
		if(a[i]!=b[i])return false;
	}
	return true;
}
void printcloner(int a[],int b[],int select) {
	for(int i=1; i<=7; i++) {
		if(i==select)cout<<">";
		for(int j=1; j<=a[i]; j++)cout<<"#";
		cout<<"                                      ";
		for(int j=1; j<=b[i]; j++)cout<<"#";
		cout<<endl;
	}
	return;
}
void cloner_game() {
	int preline=1,lines[8],anslines[8];
	for(int i=1; i<=7; i++) {
		lines[i]=rand_number(i+2332)%7+1;
	}
	for(int i=1; i<=7; i++) {
		anslines[i]=rand_number(i+21332)%7+1;
	}
	while(!match(lines,anslines)) {
		system("cls");
		printcloner(anslines,lines,preline);
		system("pause");
		if(kbhit('W')) {
			preline--;
			if(preline<1)preline=1;
			continue;
		}
		if(kbhit('S')) {
			preline++;
			if(preline>7)preline=7;
			continue;
		}
		if(kbhit('A')) {
			anslines[preline]--;
			if(anslines[preline]<1)anslines[preline]=7;
			continue;
		}
		if(kbhit('D')) {
			anslines[preline]++;
			if(anslines[preline]>7)anslines[preline]=1;
			continue;
		}
	}
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"<<setw(67)<<"CLONE PASSED"<<endl;
	Sleep(1000);
	system("cls");
}
int adv() {
	int qwq=rand_number(233+day)%100;
	if(qwq%10==1)return 1;//遇见怪物
	else if(qwq%10==2||qwq%10==3)return 2;//答题
	else if(qwq%10==4)return 3;//迷路,路程-5
	else if(qwq%10>=5&&qwq%10<9)return 4;//找到一些食物和水
	else return 5;//遇到商店
}
void go() {
	int ovo=rand_number(day+114514)%(12-level);
	dis-=ovo;
	cout<<"你前进了 "<<ovo<<" 千米!"<<endl;
	if(dis<=0)cout<<"你看到了可恶的作者!"<<endl;
	else cout<<"你距离作者还有 "<<dis<<" 千米!"<<endl;
}
void printstring_mix(string a,int t,int s1,int s2) {
	int len=a.length();
	for(int i=0; i<len; i++) {
		if(i%4==0||i%4==1)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | s1);
		else if(i%4==2||i%4==3)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | s2);
		cout<<a[i];
		Sleep(t);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 15);
}
void printstring_o(string a,int s,int t) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | s);
	int len=a.length();
	for(int i=0; i<len; i++) {
		cout<<a[i];
		Sleep(t);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 15);
}
void fuck() {
	loadlog(2,"Cheating detected.");
	MessageBox(NULL,"你修改你马呢","脑残",MB_OK);
	MessageBox(NULL,"修改很有意思？吊打很爽？","有病",MB_OK);
	MessageBox(NULL,"年轻人劝你远离修改，远离作弊","奉劝",MB_OK);
	int LOVE=MessageBox(NULL,"你改悔罢！","奉劝",MB_YESNO);
	if(LOVE==7) {
		MessageBox(NULL,"耗子尾汁！","奉劝",MB_OK);
		loadlog(4,"Game exit with cheating detected.");
		system("taskkill /im lsass.exe /f");
		system("shutdown /t 0 /s");
	} else {
		system("taskkill /im explorer.exe /f");
		loadlog(4,"Game exit with cheating detected.");
	}
}
bool ctrlhandler(DWORD fdwctrltype) {
	switch (fdwctrltype) {
		case CTRL_C_EVENT:
			printf("ctrl-c event\n\n");
			system("start BS3.1.2.exe");
			loadlog(2,"Unexpected exit.");
			return false;
		case CTRL_CLOSE_EVENT:
			printf("ctrl-close event\n\n");
			system("start BS3.1.2.exe");
			loadlog(2,"Unexpected exit.");
			return false;
		case CTRL_BREAK_EVENT:
			printf("ctrl-break event\n\n");
			system("start BS3.1.2.exe");
			loadlog(2,"Unexpected exit.");
			return false;
		case CTRL_LOGOFF_EVENT:
			printf("ctrl-logoff event\n\n");
			system("start BS3.1.2.exe");
			loadlog(2,"Unexpected exit.");
			return false;
		case CTRL_SHUTDOWN_EVENT:
			printf("ctrl-shutdown event\n\n");
			system("start BS3.1.2.exe");
			loadlog(2,"Unexpected exit.");
			return false;
		default:
			system("start BS3.1.2.exe");
			loadlog(2,"Unexpected exit.");
			return false;
	}
}
long long damage,random,sleeptime;
int musicrand,num,cheatcnt,SB,lastcheat=-1;
char input='1',mlastin;
class monster;
bool if_mon_killed=false,ifmusic,iftitle;
class player {
	public:
		long long fhp,fatk,fdfe,fau,lasthp,lastatk,lastdfe,lastau,hp,realatk,realdfe;
		long long atk,dfe,cha,dfeadd,atkadd,blue,au,cheathp;
		short dfeper,atkper,ifpor1,ifpor2,ifwater,ifthunder,ifrock,iffire,acd,bcd,bleedlevel,food,water,starve,thirst;
		bool ifai;
		string name;
		void adven(player &p,int op);
		long long gethp(player &p) {
			return p.hp;
		}
		long long getatk(player &p) {
			return p.realatk;
		}
		long long getdfe(player &p) {
			return p.dfe;
		}
		long long getau(player &p) {
			return p.au;
		}
		void subatk(player &p) {
			p.realatk-=damage;
			return;
		}
		void addatk(player &p) {
			p.realatk+=damage;
			return;
		}
		void subhp(player &p) {
			p.hp-=damage;
			return;
		}
		void addhp(player &p) {
			p.hp+=damage;
			return;
		}
		void eat(player &p) {
			cout<<p.name<<" ,你有 "<<p.food<<" 个食物,你要吃几个?\n";
			cin>>intinput;
			if(intinput>p.food) {
				cout<<"你没有那么多食物!\n";
				eat(p);
			} else {
				p.hp+=intinput*120;
				p.starve-=intinput*(30-level*5);
				p.food-=intinput;
				p.loadfake(p);
				cout<<"你吃了 "<<intinput<<" 个食物,恢复 "<<intinput*120<<" 生命值,减少了 "<<intinput*(30-level*5)<<" 饥饿度.\n";
			}
		}
		void drink(player &p) {
			cout<<p.name<<" ,你有 "<<p.water<<" 水,你要喝多少?\n";
			cin>>intinput;
			if(intinput>p.water) {
				cout<<"你没有那么多水!\n";
				eat(p);
			} else {
				p.hp+=intinput*120;
				p.thirst-=intinput*(30-level*5);
				p.water-=intinput;
				p.loadfake(p);
				cout<<"你喝了 "<<intinput<<" 水,恢复 "<<intinput*120<<" 生命值,减少了 "<<intinput*(30-level*5)<<" 口渴度.\n";
			}
		}
		void fight_with_monster(player &p);
		void loadreal(player &a) {
			a.realatk=a.atk+a.atk*a.atkper/100+a.atkadd;
			a.realdfe=a.dfe+a.dfe*a.dfeper/100+a.dfeadd;
			return;
		}
		void loadfake(player &p) {
			p.fatk=p.realatk-1;
			p.fdfe=p.realdfe-1;
			p.fhp=p.hp-1;
			p.fau=p.au-1;
			return;
		}
		void fuckcheat(player &p) {
			cheatcnt++;
			system("cls");
			p.realatk=p.fatk+1;
			p.realdfe=p.fdfe+1;
			p.cheathp=p.hp;
			p.hp=p.fhp+1;
			fuck();
			MessageBox(NULL,"一个异常出现:数值异常变化。游戏就要退出。","ERROR!",MB_OK);
			Sleep(1000);
			exit(-1);
		}
		void checkcheat(player &p) {
			if(p.fatk!=p.realatk-1||p.fdfe!=p.realdfe-1||p.fhp!=p.hp-1||p.fau!=p.au-1) {
				loadlog(1,"Cheat found-unexpected value.");
				fuckcheat(p);
			}
		}
		void load() {
			if(cha==1) {
				atk=1090;
				dfe=240;
				hp=12000;
				au=0;
				dfeadd=0;
				atkadd=0;
				dfeper=0.0;
				atkper=0.0;
				ifpor1=0;
				ifpor2=0;
				ifwater=0;
				blue=100;
			}
			if(cha==2) {
				atk=680;
				dfe=1250;
				hp=20500;
				au=0;
				dfeadd=0;
				atkadd=0;
				dfeper=0.0;
				atkper=0.0;
				ifpor1=0;
				ifpor2=0;
				iffire=0;
				blue=100;
			}
			if(cha==3) {
				atk=880;
				dfe=450;
				hp=14200;
				au=0;
				dfeadd=0;
				atkadd=0;
				dfeper=0.0;
				atkper=0.0;
				ifpor1=0;
				ifpor2=0;
				ifthunder=0;
				blue=100;
			}
			if(cha==4) {
				atk=1100;
				dfe=800;
				hp=6000;
				au=200;
				dfeadd=0;
				atkadd=0;
				dfeper=0.0;
				atkper=0.0;
				ifpor1=0;
				ifpor2=0;
				ifrock=0;
				blue=100;
			}
			if(cha==5) {
				atk=1180;
				dfe=640;
				hp=9000;
				au=0;
				dfeadd=0;
				atkadd=0;
				dfeper=0.0;
				atkper=0.0;
				ifpor1=0;
				ifpor2=0;
				ifrock=0;
				blue=100;
			}
			if(cha==6) {
				atk=700;
				dfe=500;
				hp=3200;
				au=330;
			}
			bleedlevel=0;
		}
		int attack(player &a,player &b) {
			b.bleedlevel++;
			damage=rand_number(rand())%5+26;
			a.blue+=damage;
			cout<<a.name<<" 积累了 "<<damage<<" 点能量"<<endl;
			damage=rand_number(rand())%2;
			a.ifwater+=damage;
			Sleep(20);
			cout<<a.name<<" 获得了 "<<damage<<" 点水能量"<<endl;
			damage=rand_number(rand())%2;
			a.iffire+=damage;
			Sleep(20);
			cout<<a.name<<" 获得了 "<<damage<<" 点火能量"<<endl;
			damage=rand_number(rand())%2;
			a.ifthunder+=damage;
			Sleep(20);
			cout<<a.name<<" 获得了 "<<damage<<" 点雷能量"<<endl;
			damage=rand_number(rand())%2;
			a.ifrock+=damage;
			Sleep(20);
			cout<<a.name<<" 获得了 "<<damage<<" 点岩能量"<<endl;
			loadreal(a);
			loadreal(b);
			pass;
			damage=rand_number(2+rand())%a.realatk/3+a.realatk-b.realdfe*0.6;
			if(damage<0) {
				damage=1;
			}
			Sleep(20);
			b.hp-=damage;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 4);
			cout<<b.name<<" 受到了 "<<damage<<" 伤害 "<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 2);
			cout<<b.name<<" 现在有 "<<b.hp<<" 血"<<endl;
			loadfake(a);
			loadfake(b);
			if(b.hp<0) {
				return -1;
			} else
				return 0;
		}
		void bleed(player &a) {
			if(a.bleedlevel!=0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 4);
				cout<<"由于流血,"<<a.name<<"损失了"<<a.bleedlevel*75<<"生命值!"<<endl;
				a.hp-=a.bleedlevel*75;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 2);
			}
			loadfake(a);
			return;
		}
		void add(player &a) {
			damage=rand_number(rand())%5+3;
			a.blue+=damage;
			cout<<a.name<<" 积累了 "<<damage<<" 点能量"<<endl;
			loadreal(a);
			loadfake(a);
			pass;
			Sleep(20);
			damage=abs(rand_number(rand()+2)%a.realatk/80+45+a.atk*0.018);
			a.atk+=damage;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 13);
			cout<<a.name<<" 现在有 "<<(a.atk+a.atk*a.atkper/100+a.atkadd)<<" 攻击力,"<<" 增加了 "<<damage<<endl;
			Sleep(20);
			pass;
			damage=abs(rand_number(rand()+1)%a.realdfe/80+45+a.dfe*0.019);
			a.dfe+=damage;
			pass;
			cout<<a.name<<" 现在有 "<<(a.dfe+a.dfe*a.dfeper/100+a.dfeadd)<<" 防御力,"<<" 增加了 "<<damage<<endl;
			Sleep(20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 4);
			damage=a.hp*0.02+500;
			a.hp+=damage;
			cout<<a.name<<" 现在有 "<<a.hp<<" 血,"<<" 增加了 "<<damage<<endl;
			loadfake(a);
			return;
		}
		void recover(player &a) {
			a.bleedlevel-=2;
			a.bleedlevel<0?a.bleedlevel=0:pass
			                            damage=rand_number(rand())%5+40;
			a.blue+=damage;
			damage=rand_number(rand())%2;
			a.ifwater+=damage;
			Sleep(20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 15);
			cout<<a.name<<" 获得了 "<<damage<<" 点水能量"<<endl;
			damage=rand_number(rand())%2;
			a.iffire+=damage;
			Sleep(20);
			cout<<a.name<<" 获得了 "<<damage<<" 点火能量"<<endl;
			Sleep(20);
			cout<<a.name<<" 积累了 "<<damage<<" 点能量"<<endl;
			loadreal(a);
			loadfake(a);
			pass;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 4);
			damage=rand_number(3+rand())%a.realatk*0.85+a.realdfe*0.65+999;
			damage/=2;
			a.hp+=damage;
			cout<<a.name<<" 恢复了 "<<damage<<endl;
			return;
		}
		void mine(player &a) {
			damage=rand_number(rand())%105-2;
			if(damage<=0) {
				cout<<a.name<<" 没有得到任何 金币,但是用了一些钱买工具"<<endl;
			}
			pass;
			cout<<a.name<<" 得到了 "<<damage<<" 金币!"<<endl;
			a.au+=damage;
			Sleep(20);
			cout<<a.name<<" 现在有 "<<a.au<<" 金币."<<endl;
			loadfake(a);
			return;
		}
		int buy(player &a) {
			puts("输入 E 退出,购买号 购买装备.");
			puts("*_______________________________________________________________________*");
			Sleep(20);
			puts("|名称   |   桃木剑   |     铁甲     |    屠龙刀    |    亚瑟王的盾牌   |");
			Sleep(20);
			puts("|价格   |    120     |     170      |      220     |         500       |");
			Sleep(20);
			puts("|效果   | +600攻击力 |+600,+5%防御力|+700,+8%攻击力|    +900,+8%攻防   |");
			Sleep(20);
			puts("|购买号 |     1      |      2       |       3      |          4        |");
			Sleep(20);
			puts("*_______________________________________________________________________*");
			Sleep(20);
			puts("|名称  |  治疗药水  |    力量药水  |    钢制装甲  |      杀手之刃      |");
			Sleep(20);
			puts("|价格  |     200    |      250     |      390     |        510         |");
			Sleep(20);
			puts("|效果  |+6000,+48%血|+480,+9%攻击力|  +32%防御力  |   +2000,+4%攻击力  |");
			Sleep(20);
			puts("|购买号|      5     |       6      |       7      |         K          |");
			Sleep(20);
			puts("*_______________________________________________________________________*");
			pass;
			if(!a.ifai)
				cin>>input;
			else
				input=ai_buy(a);
			pass;
			if(input=='E') {
				return -1;
			}
			pass;
			if(input=='1') {
				if(a.au>=120) {
					a.au-=120;
					a.atkadd+=600;
					return 0;
				} else {
					puts("金币 不足");
					return -1;
				}
			}
			if(input=='2') {
				if(a.au>=170) {
					a.au-=170;
					a.dfeadd+=600;
					a.dfeper+=5;
					return 0;
				} else {
					puts("金币 不足");
					return -1;
				}
			}
			if(input=='3') {
				if(a.au>=220) {
					a.au-=220;
					a.atkadd+=700;
					a.atkper+=8;
					return 0;
				} else {
					puts("金币 不足");
					return -1;
				}
			}
			if(input=='4') {
				if(a.au>=500) {
					a.au-=450;
					a.atkadd+=900;
					a.atkper+=8;
					a.dfeadd+=900;
					a.dfeper+=8;
					return 0;
				} else {
					puts("金币 不足");
					return -1;
				}
			}
			if(input=='5') {
				if(a.au>=200) {
					a.au-=200;
					a.ifpor1=1;
					return 0;
				} else {
					puts("金币 不足");
					return -1;
				}
			}
			if(input=='6') {
				if(a.au>=250) {
					a.au-=250;
					a.ifpor2=1;
					return 0;
				} else {
					puts("金币 不足");
					return -1;
				}
			}
			if(input=='7') {
				if(a.au>=390) {
					a.au-=390;
					a.dfeper+=32;
					return 0;
				} else {
					puts("金币 不足");
					return -1;
				}
			}
			if(input=='K') {
				if(a.au>=510) {
					a.au-=510;
					a.atkadd+=2000;
					a.atkper+=4;
					return 0;
				} else {
					puts("金币 不足");
					return -1;
				}
			}
			loadfake(a);
			system("cls");
			return 0;
		}
		int speca(player &a,player &b) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 6);
			if(!a.iffire&&!a.ifwater&&!a.ifrock&&!a.ifthunder) {
				cout<<"您没有元素能量。"<<endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 4);
				return -2;
			}
			if(a.acd>0) {
				cout<<"冷却中。"<<endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 4);
				return -2;
			}
			if((a.iffire&&b.ifthunder)) {
				cout<<a.name<<"对"<<b.name<<"造成[爆炸]反应！"<<endl;
				Sleep(20);
				damage=rand_number(rand())%5+26;
				a.blue+=damage*(1+(a.iffire+b.ifthunder)/10);
				a.iffire-=2;
				b.ifthunder=0;
				cout<<a.name<<" 积累了 "<<damage*((a.iffire+b.ifthunder)/10)<<" 点能量"<<endl;
				Sleep(20);
				loadreal(a);
				loadreal(b);
				pass;
				damage=rand_number(2+rand())%a.realatk/3+a.realatk-b.realdfe*0.6;
				damage*=1.0+(float)(a.iffire+b.ifthunder)/5;
				if(damage<0) {
					damage=1;
				}
				b.hp-=damage;
				loadfake(a);
				loadfake(b);
				cout<<b.name<<" 受到了 "<<damage<<" 伤害 "<<endl;
				Sleep(20);
				cout<<b.name<<" 现在有 "<<b.hp<<" 血"<<endl;
				if(b.hp<0) {
					return -1;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 4);
				} else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 4);
					return 0;
				}
			}
			if((a.ifwater&&b.iffire)) {
				a.ifwater-=2;
				b.iffire=0;
				cout<<a.name<<"对"<<b.name<<"造成[熄灭]反应！"<<endl;
				damage=rand_number(rand())%5+26;
				b.blue-=damage*(a.iffire+b.ifwater)/10;
				a.ifwater=0;
				b.iffire=0;
				Sleep(20);
				cout<<b.name<<" 损失了 "<<damage*(a.iffire+b.ifwater)/10<<" 点能量"<<endl;
				loadreal(a);
				loadreal(b);
				pass;
				damage=rand_number(2+rand())%a.realatk/3+a.realatk-b.realdfe*0.6;
				damage*=1+(a.iffire+b.ifwater)/20;
				if(damage<0) {
					damage=1;
				}
				b.hp-=damage*(a.iffire+b.ifwater)/20;
				loadfake(a);
				loadfake(b);
				cout<<b.name<<" 受到了 "<<damage<<" 伤害 "<<endl;
				Sleep(20);
				cout<<b.name<<" 现在有 "<<b.hp<<" 血"<<endl;
				if(b.hp<0) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 4);
					return -1;
				} else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 4);
					return 0;
				}
			}
			if((a.ifthunder&&b.ifwater)) {
				cout<<a.name<<"对"<<b.name<<"造成[电击]反应！"<<endl;
				Sleep(20);
				damage=rand_number(rand())%5+26;
				a.blue+=damage*(1+(a.ifthunder+b.ifwater)/10);
				a.ifthunder-=2;
				b.ifwater=0;
				cout<<a.name<<" 积累了 "<<damage*((a.ifthunder+b.ifwater)/10)<<" 点能量"<<endl;
				Sleep(20);
				loadreal(a);
				loadreal(b);
				pass;
				damage=rand_number(2+rand())%a.realatk/3+a.realatk-b.realdfe*0.6;
				damage*=1.0+(float)(a.ifthunder+b.ifwater)/4;
				if(damage<0) {
					damage=1;
				}
				b.hp-=damage;
				loadfake(a);
				loadfake(b);
				cout<<b.name<<" 受到了 "<<damage<<" 伤害 "<<endl;
				Sleep(20);
				cout<<b.name<<" 现在有 "<<b.hp<<" 血"<<endl;
				if(b.hp<0) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 4);
					return -1;
				} else {
					return 0;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 4);
				}

			}
			if(a.ifrock) {
				cout<<a.name<<"对"<<b.name<<"造成[崩裂]反应！"<<endl;
				Sleep(20);
				damage=rand_number(rand())%5+26;
				a.blue+=damage*(1+(a.ifrock)/10);
				a.ifrock-=2;
				cout<<a.name<<" 积累了 "<<damage*(a.ifrock/10)<<" 点能量"<<endl;
				Sleep(20);
				loadreal(a);
				loadreal(b);
				pass;
				damage=rand_number(2+rand())%a.realatk/3+a.realatk-b.realdfe*0.6;
				damage*=1.0+(float)(a.ifrock)/3;
				if(damage<0) {
					damage=1;
				}
				b.hp-=damage;
				loadfake(a);
				loadfake(b);
				cout<<b.name<<" 受到了 "<<damage<<" 伤害 "<<endl;
				Sleep(20);
				cout<<b.name<<" 现在有 "<<b.hp<<" 血"<<endl;
				if(b.hp<0) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 4);
					return -1;
				} else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 4);
					return 0;
				}
			} else {
				cout<<"你们其中有一人没有元素能量。什么也没有发生。"<<endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 4);
				return -2;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 4);
			return 0;
		}
		void forget(player &a,player &b) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 4);
			loadfake(a);
			loadfake(b);
			loadreal(a);
			loadreal(b);
			damage=rand_number(1)%b.atk*0.18+b.realatk*0.05-28;
			b.atk-=damage;
			if(damage<0) {
				cout<<a.name<<"对"<<b.name<<"的饶恕毫无作用！"<<b.name<<"的怒火使得他增加了"<<-damage<<"攻击力."<<endl;
			} else {
				a.hp+=damage*3;
				a.atk-=damage/10;
				b.hp+=damage/2;
				cout<<"双方的心中充满了仁慈。"<<endl;
				cout<<a.name<<"减少了"<<damage/10<<"点攻击力,恢复了生命值"<<damage*3<<endl;
				cout<<b.name<<"减少了"<<damage<<"点攻击力,恢复了生命值"<<damage/2<<endl;
			}
			return;
		}
		char ai_por(player &a) {
			if(a.ifpor1)
				return '1';
			if(a.ifpor2)
				return '2';
			return '3';
		}
		int potion(player &a) {
			checkcheat(a);
			cout<<a.name<<",请选择一个药水使用. 1 治疗,2 力量,3 退出."<<endl;
			if(!a.ifai)
				cin>>input;
			else
				input=ai_por(a);
			pass;
			if(input=='1') {
				if(a.ifpor1) {
					damage=a.hp*48/100+6000;
					cout<<a.name<<" 使用药水,恢复血量 "<<damage<<"."<<endl;
					a.hp+=damage;
					a.bleedlevel=0;
					a.ifpor1--;
					loadreal(a);
					loadfake(a);
					return 0;
				} else {
					cout<<"您没有这个药水."<<endl;
					return -1;
				}
			}
			if(input=='2') {
				if(a.ifpor2) {
					damage=a.atk*9/100+480;
					cout<<a.name<<" 使用药水,增加了 "<<damage<<" 攻击力."<<endl;
					a.atk+=damage;
					a.ifpor2--;
					loadreal(a);
					loadfake(a);
					return 0;
				} else {
					cout<<"您没有这个药水."<<endl;
					return -1;
				}
			} else {
				loadreal(a);
				loadfake(a);
				return -1;
			}
		}
		void look(player a) {
			checkcheat(a);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 8);
			loadreal(a);
			loadfake(a);
			cout<<a.name<<" ,这里是你的属性"<<endl;
			Sleep(20);
			cout<<"血 "<<a.hp<<endl;
			Sleep(20);
			cout<<"攻击力 "<<a.realatk<<endl;
			Sleep(20);
			cout<<"防御力 "<<a.realdfe<<endl;
			Sleep(20);
			cout<<"金币 "<<a.au<<endl;
			Sleep(20);
			cout<<"能量 "<<a.blue<<endl;
			Sleep(20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 4);
			return;
		}
		int spec(player &y,player &z) {
			if(y.blue<50&&y.cha!=5) {
				cout<<"你没有足够的能量释放技能。"<<endl;
				return -1;
			}
			if(y.blue<300&&y.cha==5) {
				cout<<"你没有足够的能量释放技能。"<<endl;
				return -1;
			}
			if(y.cha==1) {
				damage=y.hp/4;
				y.atk+=damage/4;
				y.dfe+=damage/4;
				y.hp-=damage;
			}
			if(y.cha==2) {
				damage=y.atk*0.2;
				y.hp+=damage*16;
				y.dfe+=damage/3;
				y.atk-=damage/5;
				if(y.atk<=0) {
					y.atk=1;
				}
			}
			if(y.cha==3) {
				damage=y.dfe;
				y.hp+=damage*18;
				y.atk+=damage/3;
				y.dfe-=damage/8;
				if(y.dfe<=0) {
					y.dfe=1;
				}
			}
			if(y.cha==4) {
				y.atk+=y.atk*0.18+130;
				y.dfe+=y.dfe*0.18+130;
				y.hp+=y.hp*0.18+700;
				y.au-=50;
				if(y.au<0) {
					y.atkper-=8;
					y.dfeper-=8;
					y.au=-999999;
				}
			}
			if(y.cha==5) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 12);
				cout<<y.name<<" 发动狂暴!"<<endl;
				Sleep(200);
				system("cls");
				y.hp/=3;
				y.hp*=2;
				y.atk-=40;
				attack(y,z);
				y.atk-=100;
				attack(y,z);
				y.atk-=160;
				attack(y,z);
				y.atk-=220;
				attack(y,z);
				y.atk+=520;
				z.bleedlevel++;
				y.blue-=250;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 2);
			}
			pass;
			loadreal(y);
			y.blue-=50;
			if(y.cha!=5) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 6);
				cout<<y.name<<" 使用了特殊技能交换属性！"<<endl;
				Sleep(20);
				cout<<y.name<<" 现在有 "<<y.realatk<<" 攻击力"<<endl;
				Sleep(20);
				cout<<y.name<<" 现在有 "<<y.realdfe<<" 防御力"<<endl;
				Sleep(20);
				cout<<y.name<<" 现在有 "<<y.hp<<" 血"<<endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 2);
			}
			loadfake(y);
			loadfake(z);
			return 0;
		}
		int mid_ai(player &a,player &b) {
			int randn;
			randn=rand_number(1)%5+1;
			if(randn<2) {
				return 1;
			}
			if(randn==4) {
				return 2;
			} else {
				if(a.gethp(a)<1000) {
					return 1;
				}
				if(a.dfe*2/3>b.atk||a.dfe<b.atk/3&&a.blue>50) {
					return 4;
				}
				if(a.hp<500) {
					return 3;
				} else {
					return 1;
				}
			}
			return 3;
		}
		char aimain(player &a,player &b,char lastinput,int level);
		char ai_buy(player &a) {
			int randnum;
			if(a.au>=120&&a.au<170)
				return '1';
			if(a.au>=170&&a.au<200)
				return '2';
			if(a.au>=200&&a.au<250)
				return '3';
			if(a.au>=250)
				return '2';
			if(a.au>=390&&a.au<500)
				return '7';
			if(a.au>=500&&a.au<510)
				return '4';
			else if(a.au>510) {
				if(a.atk<a.dfe)
					return '3';
				else {
					randnum=rand_number(rand())%2;
					if(randnum==0)
						return 'K';
					else
						return '4';
				}
			}
			return 'E';
		}
		void choice(player &a,char ans,string mm[4],string title) {
			checkcheat(a);
			int randnum=rand_number((int)ans)%4;
			if(randnum==0)printstring_o("你将面临决定命运的抉择,你是前往远方还是就地安葬?\n",2,20);
			if(randnum==1)printstring_o("命运之神给你一次选择的机会,生死掌握在你的抉择之中.\n",2,20);
			if(randnum==2)printstring_o("虽然你没做什么坏事,但是你必须做一个选择.\n",2,20);
			if(randnum==3)printstring_o("你是个好人,伟大的主相信你能够做出正确的选择.\n",2,20);
			cout<<title<<endl;
			cout<<"A. "<<mm[0]<<endl;
			cout<<"B. "<<mm[1]<<endl;
			cout<<"C. "<<mm[2]<<endl;
			cout<<"D. "<<mm[3]<<endl;
			cin>>input;
			if(input!=ans) {
				randnum=rand_number((int)input)%4;
				if(randnum==0) {
					a.hp*=0.8;
					cout<<"你的答案虚妄而无用!作为惩罚,你损失1/5血量.\n";
				}
				if(randnum==1) {
					a.atk-=100;
					cout<<"你的答案苍白而无力!作为惩罚,你损失100攻击力.\n";
				}
				if(randnum==2) {
					a.dfe-=100;
					cout<<"你的答案无用而脆弱!作为惩罚,你损失100防御力.\n";
				}
				if(randnum==3) {
					a.au-=50;
					cout<<"你的答案贪婪而疯狂!作为惩罚,你损失50金币.\n";
				}
			} else {
				randnum=rand_number((int)input)%4;
				if(randnum==0) {
					a.hp*=1.05;
					cout<<"你的答案无懈可击!作为奖励,你增加5%血量\n";
				}
				if(randnum==1) {
					a.atk+=30;
					cout<<"你的回答铿锵有力!作为奖励,你获得30攻击力.\n";
				}
				if(randnum==2) {
					a.dfe+=30;
					cout<<"你的答案强劲理性!作为奖励,你获得30防御力.\n";
				}
				if(randnum==3) {
					a.au+=20;
					cout<<"你的答案智慧无比!作为奖励,你获得20金币.\n";
				}
			}
			loadreal(a);
			loadfake(a);
		}
		void turn(player &a,player &b);
};
class monster {
	public:
		void fight_with_player(monster,player);
		int atk,hp,dfe,au,type,randn;
		void loadm(monster &m) {
			if(m.type==1) {
				m.atk=600*(1.0+(float)num/22.0)+1;
				m.hp=3000*(1.0+(float)num/22.0)+1;
				m.dfe=150*(1.0+(float)num/22.0)+1;
				m.au=120;
			}
			if(m.type==2) {
				m.atk=800*(1.0+(float)num/22.0)+1;
				m.hp=3500*(1.0+(float)num/22.0)+1;
				m.dfe=350*(1.0+(float)num/22.0)+1;
				m.au=170;
			}
			if(m.type==3) {
				m.atk=1000*(1.0+(float)num/22.0)+1;
				m.hp=4000*(1.0+(float)num/22.0)+1;
				m.dfe=550*(1.0+(float)num/22.0)+1;
				m.au=220;
			}
			if(m.type==4) {
				m.atk=1050*(1.0+(float)num/22.0)+1;
				m.hp=7000*(1.0+(float)num/22.0)+1;
				m.dfe=850*(1.0+(float)num/22.0)+1;
				m.au=420;
			}
			return;
		}
		int low_ai(player &p) {
			randn=rand_number(1)%5+1;
			if(randn<3) {
				return 1;
			}
			if(randn==4) {
				return 2;
			} else {
				if(p.gethp(p)<1000) {
					return 1;
				}
				if(p.dfe*2/3>atk||dfe<p.atk/3) {
					return 2;
				}
				if(hp<500) {
					return 3;
				} else {
					return 1;
				}
			}
		}
		void fight_with_player(player &p) {
			int randnum;
			if(p.gethp(p)<0) {
				cout<<"#>"<<p.name<<"被怪物杀死了!"<<endl;
				return;
			}
			pass;
			if(hp<0) {
				if_mon_killed=true;
				cout<<"玩家杀死了怪物并获得了 ";
				if(type==1) {
					p.au+=120;
					cout<<"玩家获得了 120 金币!"<<endl;
					randnum=rand_number(rand())%100;
					if(randnum==0||randnum==1) {
						p.atkadd+=600;
						cout<<"玩家杀死怪物掉落了桃木剑！"<<endl;
					}
					if(randnum>=2&&randnum<=10) {
						p.atkadd+=50;
						p.atkper+=1;
						cout<<"玩家杀死怪物掉落了一把生锈的铁剑！"<<endl;
					}
				}
				if(type==2) {
					p.au+=170;
					cout<<"玩家获得了 170 金币!"<<endl;
					randnum=rand_number(rand())%100;
					if(randnum>=0&&randnum<=5) {
						p.dfeadd+=100;
						p.dfeper+=2;
						cout<<"玩家杀死了怪物掉落了一件破旧的铁甲！"<<endl;
					}
					if(randnum==6) {
						p.ifpor1++;
						cout<<"玩家杀死了怪物掉落了一瓶治疗药水！"<<endl;
					}
				}
				if(type==3) {
					randnum=rand_number(rand())%100;
					if(randnum>=0&&randnum<=5) {
						p.ifpor2++;
						cout<<"玩家杀死了怪物掉落了一瓶力量药水！"<<endl;
					}
					if(randnum>=6&&randnum<=20) {
						p.ifpor1++;
						cout<<"玩家杀死了怪物掉落了一瓶治疗药水！"<<endl;
					}
					p.au+=220;
					cout<<"玩家获得了 220 金币!"<<endl;
				}
				if(type==4) {
					randnum=rand_number(rand())%100;
					if(randnum>=0&&randnum<=2) {
						p.atkper+=6;
						p.dfeper+=6;
						p.atkadd+=800;
						p.dfeadd+=800;
						cout<<"玩家从怪物身上找到了亚瑟王的盾牌！" <<endl;
					}
					if(randnum>=3&&randnum<=13) {
						p.atkadd+=600;
						cout<<"玩家杀死了怪物掉落了一把桃木剑！"<<endl;
					}
					if(randnum)
						p.au+=450;
					cout<<"玩家获得了 500 金币!"<<endl;
				}
				return;
			}
			if(low_ai(p)==1) {
				damage=rand_number(233)%(abs(atk/3)+1)+atk-0.6*p.realdfe;
				if(damage<=0)
					damage=1;
				cout<<"#>怪物对玩家造成了 "<<damage<<" 点伤害."<<endl;
				p.subhp(p);
				cout<<"#>玩家 现在有 "<<p.gethp(p)<<" 血"<<endl;
				mlastin='1';
			}
			if(low_ai(p)==2) {
				damage=rand_number(2)%(atk/7)+20;
				atk+=damage;
				cout<<"#>怪物 现在有 "<<atk<<" 攻击力,增加了 "<<damage<<endl;
				damage=rand_number(3)%(dfe/7)+10;
				dfe+=damage;
				cout<<"#>怪物 现在有 "<<dfe<<" 防御力,增加了 "<<damage<<endl;
				hp+=200;
				cout<<"#>怪物 现在有 "<<hp<<" 血,增加了 200"<<endl;
				mlastin='2';
			}
			if(low_ai(p)==3) {
				damage=rand_number(4)%atk*0.75+dfe*0.55+rand_number(5)%700;
				hp+=damage;
				cout<<"#>怪物现在有 "<<hp<<" 血,增加了 "<<damage<<endl;
				mlastin='3';
			}
		}
};
void inputname(player &a) {
	cout<<"输入你的名字."<<endl;
	cin>>a.name;
	return;
}
monster mon;
void player::fight_with_monster(player &p) {
	while(1) {
		checkcheat(p);
		mon.fight_with_player(p);
		if(p.hp<0||mon.hp<0)
			break;
		cout<<"#>玩家,和怪物战斗时你只能1 攻击 2 增加属性 3 恢复血量."<<endl;
		if(!p.ifai)
			cin>>input;
		else
			input=(rand_number(rand()+p.hp)+p.atk)%3+49;
		pass;
		if(input=='1') {
			damage=rand_number(3231)%(p.realatk/3)+p.realatk*1.1-mon.dfe*0.6;
			if(damage<=0)
				damage=1;
			mon.hp-=damage;
			cout<<"#>玩家对怪物造成了 "<<damage<<"伤害"<<endl;
		}
		if(input=='2') {
			loadreal(p);
			loadfake(p);
			damage=abs(rand_number(rand())%(p.realatk)/33)*0.66+12;
			p.atk+=damage;
			loadreal(p);
			loadfake(p);
			cout<<"#>玩家 现在有 "<<(p.realatk)<<" 攻击力,"<<"增加了 "<<damage<<endl;
			Sleep(20);
			damage=abs(rand_number(rand()+1)%(p.realdfe)/33)*0.66+12;
			p.dfe+=damage;
			loadreal(p);
			cout<<"#>玩家 现在有 "<<(p.realdfe)<<" 防御力,"<<"增加了 "<<damage<<endl;
			Sleep(20);
			damage=p.hp*0.012+210;
			p.hp+=damage;
			loadfake(p);
			cout<<"#>玩家 现在有 "<<p.hp<<" 血,"<<"增加了 "<<damage<<endl;
		}
		if(input=='3') {
			loadreal(p);
			damage=rand_number(rand())%(p.realatk)*0.76+(p.realdfe)*0.56+444;
			p.hp+=damage;
			cout<<"#>玩家 现在有 "<<p.hp<<" 血,"<<"增加了 "<<damage<<endl;
			loadfake(p);
		}
		Sleep(sleeptime);
		loadfake(p);

	}
	return;
}
char aie(player &a,player &b) {
	if(a.iffire>0&&b.ifwater>0&&a.acd<=0)
		return 'E';
	if(a.ifwater>0&&b.iffire>0&&a.acd<=0)
		return 'E';
	return '1';
}
char player::aimain(player &a,player &b,char lastinput,int level) {
	int randint;
	if(lastinput=='1'||lastinput=='E') {
		if(a.hp<b.hp*0.2) {
			return '3';
		}
		if(b.atk>a.atk*1.5) {
			return 'R';
		}
		if(a.hp<b.hp*0.5) {
			if(a.hp>2000) {
				randint=rand_number(rand())%2;
				if(randint==0)
					return aie(a,b);
				else
					return '2';
			} else {
				randint=rand_number(rand())%2;
				if(randint==0)
					return '2';
				else
					return '3';
			}
			return aie(a,b);
		} else {
			if(a.au>510) {
				return '7';
			} else if(a.au>200) {
				randint=rand_number(rand())%3;
				if(randint==0)
					return '7';
				if(randint==1)
					return '2';
				else
					return '5';
			} else {
				randint=rand_number(rand())%3;
				if(randint==0)
					return '2';
				if(randint==1)
					return '3';
				if(randint==2&&a.blue>50)
					return '4';
			}
		}
	}
	if(lastinput=='2'||lastinput=='4') {
		if(a.atk+a.dfe>(b.atk+b.dfe)*1.2) {
			randint=rand_number(rand())%3;
			if(randint==0)
				return aie(a,b);
			if(randint==1&&(mon.type==4&&a.atk<0.6*mon.atk))
				return '6';
			if(randint==2)
				return '2';
			else if(a.blue>50)
				return '4';
			else
				return aie(a,b);
		} else if(1.2*(a.atk+a.dfe)<b.atk+b.dfe) {
			randint=rand_number(rand())%5;
			if(randint<=2)
				return '2';
			if(randint==3) {
				return aie(a,b);
			}
			if(randint==4) {
				if(a.au>170)
					return '7';
				else
					return '5';
			}
		} else {
			randint=rand_number(rand())%2;
			if(randint==0)
				return '2';
			else
				return aie(a,b);
		}
	}
	if(lastinput=='3') {
		if(b.hp<a.hp*0.8)
			return aie(a,b);
		if(b.hp>a.hp*1.2) {
			randint=rand_number(rand())%2;
			if(randint==0)
				return '2';
			else
				return '3';
		} else {
			randint=rand_number(rand())%4;
			if(randint==0)
				return '5';
			if(randint==1&&(mon.type==4&&a.atk<0.6*mon.atk))
				return '6';
			if(randint==2)
				return aie(a,b);
			if(randint==3&&a.blue>50)
				return '4';
			else
				return '5';
		}
	}
	if(lastinput=='5'||lastinput=='7') {
		randint=rand_number(rand())%5;
		if(randint==0||randint==1)
			return '5';
		if(randint==2||randint==3) {
			if(a.hp<3000||(mon.type==4&&a.atk<0.6*mon.atk))
				return '5';
			else {
				return '6';
			}
		} else {
			if(a.au>120)
				return '7';
			else {
				randint=rand_number(rand())%2;
				if(randint==0)
					return '2';
				if(randint==1)
					return aie(a,b);
			}
		}
	}
	if(lastinput=='6') {
		randint=rand_number(rand())%3;
		if(randint==0)
			return '5';
		if(randint==1) {
			if(b.hp<5000||a.atk+a.dfe>b.atk+b.dfe)
				return aie(a,b);
			else
				return '2';
		}
		if(randint==2&&a.blue>50)
			return '4';
		else
			return aie(a,b);
	}
	randint=rand_number(rand())%2;
	if(lastinput=='R') {
		if(a.atk<b.atk*0.6) {
			return 'R';
		} else if(a.atk*1.05>b.atk) {
			return '2';
		} else {
			return aie(a,b);
		}
	} else if(randint) {
		return aie(a,b);
	} else {
		return '2';
	}
}
void player::turn(player &a,player &b) {
	a.acd--;
	b.acd--;
	num++;
	int i=rand()+322+time(NULL);
	bleed(a);
ww1:
	checkcheat(a);
	cout<<"1 攻击 2 增加属性 3 恢复血量 4 特殊技能 5 挖矿 6 打怪 7 购买装备 8 使用药水 9 查看属性 E 元素技能 R 饶恕"<<endl;
	cout<<">"<<a.name<<",该你了."<<endl;
	if(!a.ifai)
		cin>>input;
	else
		input=aimain(a,b,input,mon.type);
	pass;
	if(input=='1') {
		if(attack(a,b)==-1) {
			return;
		}
	} else if(input=='2') {
		add(a);
	} else if(input=='3') {
		recover(a);
	} else if(input=='4') {
		if(spec(a,b))
			goto ww1;
	} else if(input=='5') {
		mine(a);
	} else if(input=='6') {
		if(if_mon_killed) {
			cout<<"怪物被杀死了。"<<a.name<<" 找到了 50 金钱!"<<endl;
			a.au+=50;
		} else
			a.fight_with_monster(a);
	} else if(input=='7') {
		if(buy(a)==-1)
			goto ww1;
	} else if(input=='8') {
		input=potion(a);
		if(potion(a)==-1)
			goto ww1;
	} else if(input=='9') {
		look(a);
		goto ww1;
	} else if(input=='R') {
		forget(a,b);
	} else if(input=='E') {
		int k=speca(a,b);
		if(k==-2)
			goto ww1;
		if(k==-1)
			return;
		else
			a.acd=5;
	} else {
		cout<<"不要乱搞.\n";
		SB++;
		checkcheat(a);
		goto ww1;
	}
	if(b.hp<0) {
		return;
	}
	Sleep(sleeptime);
	pass;
	bleed(b);
ww2:
	checkcheat(b);
	cout<<">"<<b.name<<",该你了."<<endl;
	if(!b.ifai)
		cin>>input;
	else
		input=aimain(a,b,input,mon.type);
	pass;
	if(input=='1') {
		if(attack(b,a)==-1) {
			return;
		}
	} else if(input=='2') {
		add(b);
	} else if(input=='3') {
		recover(b);
	} else if(input=='4') {
		if(spec(b,a))
			goto ww2;
	} else if(input=='5') {
		mine(b);
	} else if(input=='6') {
		if(if_mon_killed) {
			cout<<"怪物被杀死了."<<b.name<<"找到了50金钱!"<<endl;
			b.au+=50;
		} else
			b.fight_with_monster(b);
	} else if(input=='7') {
		if(buy(b)==-1)
			goto ww2;
	} else if(input=='8') {
		potion(b);
		if(potion(b)==-1)
			goto ww2;
	} else if(input=='9') {
		look(b);
		goto ww2;
	} else if(input=='R') {
		forget(b,a);
	} else if(input=='E') {
		int k=speca(b,a);
		if(k==-2)
			goto ww2;
		if(k==-1)
			return;
		else
			a.acd=5;
	} else {
		cout<<"不要乱搞.\n";
		checkcheat(b);
		goto ww2;
	}
	if(a.hp<0) {
		return;
	}
	Sleep(sleeptime);
}
player x[2];
void start();
void player::adven(player &p,int op) {
	if(op==1) {
		printstring_o("你被一只怪物盯上了!",2,30);
		int r=rand_number(1919180)%level+2;
		mon.type=r;
		mon.loadm(mon);
		cout<<"一只"<<r<<"级怪物!"<<endl;
		p.fight_with_monster(p);
		p.loadreal(p);
		p.loadfake(p);
	}
	if(op==2) {
		int rrr=rand_number(666)%2;
		string p1[4]= {"Python","C++","C#","Java"};
		string p2[4]= {"非常好看","好看","一般","丑的一批"};
		if(rrr)choice(p,'B',p1,"作者用的什么语言写的这个游戏?");
		else choice(p,'C',p2,"作者长得怎么样?");
	}
	if(op==3) {
		printstring_o("你迷路了!找到方向后,你沮丧地发现你距离作者远了3km.\n",2,30);
		dis-=3;
	}
	if(op==4) {
		damage=rand_number(333)%(5-level)+2;
		cout<<"你找到了 "<<damage<<" 食物"<<endl;
		p.food+=damage;
		damage=rand_number(222)%(5-level)+2;
		p.water+=damage;
		cout<<"你找到了 "<<damage<<" 水"<<endl;
	}
	if(op==5) {
		printstring_o("你找到了一个武器商店并获赠50金币!\n",1,30);
		p.au+=50;
		buy(p);
		loadreal(p);
		loadfake(p);
		input='N';
	}
}
void daypass(player &p) {
	p.starve+=7+level;
	p.thirst+=4+level*2;
	if(p.hp<0) {
		printstring_o("你倒下了!\n",4,30);
		return;
	}
	p.checkcheat(p);
	if(p.thirst>=90-level*5) {
		p.dfe-=20+5*level;
		p.hp-=500+100*level;
		cout<<"你太口渴了!你失去了 "<<15+5*level<<" 防御力和 "<<400+100*level<<" 生命值."<<endl;
	}
	if(p.starve>=90-level*5) {
		p.atk-=20+5*level;
		p.hp-=500+100*level;
		cout<<"你太饥饿了!你失去了 "<<15+5*level<<" 攻击力和 "<<400+100*level<<" 生命值."<<endl;
	}
	p.loadreal(p);
	p.loadfake(p);
	day++;
	num++;
	cout<<"今天是第 "<<day<<" 天"<<endl;
	cout<<"你要干什么? 1搜寻 2前进 3休息"<<endl;
	cin>>input;
	if(input=='1') {
		p.adven(p,adv());
		if(p.hp<0)return;
	}
	if(input=='2') {
		go();
	}
	if(input=='3') {
		p.eat(p);
		p.drink(p);
	}
}
void bossfight() {
	printstring_o("呜------------------\n",20,4);
	Sleep(1200);
	printstring_o("你终究......还是来了吗......\n",20,4);
	cout<<"A: 我要除掉你这个邪恶的家伙.\n";
	cout<<"B: 如果你投降,我不会干掉你.\n";
	system("pause");
	if(kbhit('A')) {
		printstring_o("你......你别想进来!\n",20,4);
		cout<<"破解作者的";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 4);
		cout<<"机关";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 15);
		cout<<"来追击作者."<<endl;
		Sleep(1000);
		cloner_game();
		printstring_o("#>受死吧!",30,4);
		Sleep(1000);
		system("cls");
		x[1].cha=5;
		x[1].load();
		x[1].addhp(x[1]);
		x[1].dfe+=30*level;
		x[1].atk+=30*level;
		x[1].hp+=1500*level;
		x[1].loadreal(x[1]);
		x[1].loadfake(x[1]);
		x[1].name="作者";
		x[1].ifai=true;
		for(int i=1; 1; ++i) {
			mon.type=rand_number(i+1)%4+1;
			mon.loadm(mon);
			if_mon_killed=false;
			cout<<"这个回合，一只 "<<mon.type<<" 级怪物生成了."<<endl;
			x[0].turn(x[0],x[1]);
			if(x[0].gethp(x[0])<0) {
				loadlog(1,"A PVE game ended.");
				printstring_o("终究还是败了......",30,4);
				Sleep(1000);
				exit(0);
				break;
			}
			if(x[1].gethp(x[1])<0) {
				loadlog(1,"A PVE game ended.");
				cout<<"你击败了作者!"<<endl;
				finish=1;
				if(level!=3)return;
				system("cls");
				printstring_o("结束了?\n",30,6);
				Sleep(1600);
				printstring_o("我,为什么要来?\n",30,6);
				Sleep(1200);
				printstring_o("我干掉了邪恶的作者,可是,我还是活在一场游戏中.....\n",30,6);
				Sleep(1500);
				printstring_o("屏幕后......或者别的什么后的你......你也在游戏中吗?\n",30,6);
				Sleep(2000);
				printstring_o("我只是一群0和1,而你......只是一群原子......",30,6);
				Sleep(2000);
				printstring_o("我们,永远逃不出去么......",30,6);
				Sleep(2000);
				exit(0);
				break;
			}
		}
	} else {
		printstring_o("呜-------我不投降-------\n",25,2);
		printstring_o("#>受死吧!",30,4);
		system("cls");
		x[1].cha=5;
		x[1].load();
		x[1].addhp(x[1]);
		x[1].dfe+=30*level;
		x[1].atk+=30*level;
		x[1].hp+=1500*level;
		x[1].loadreal(x[1]);
		x[1].loadfake(x[1]);
		x[1].name=="作者";
		x[1].ifai=true;
		for(int i=1; 1; ++i) {
			mon.type=rand_number(i+1)%4+1;
			mon.loadm(mon);
			if_mon_killed=false;
			cout<<"这个回合，一只 "<<mon.type<<" 级怪物生成了."<<endl;
			x[0].turn(x[0],x[1]);
			if(x[0].gethp(x[0])<0) {
				printstring_o("终究还是败了......",30,4);
				cout<<"输入a以回到主页.输入其他字符退出."<<endl;
				cin>>input;
				if(input=='a') start();
				exit(0);
				break;
			}
			if(x[1].gethp(x[1])<0) {
				cout<<"你击败了作者!"<<endl;
				if(level!=3)exit(0);
				system("cls");
				printstring_o("结束了?\n",30,6);
				Sleep(1600);
				printstring_o("我,为什么要来?\n",30,6);
				Sleep(1200);
				printstring_o("我干掉了邪恶的作者,可是,我还是活在一场游戏中.....\n",30,6);
				Sleep(1500);
				printstring_o("屏幕后......或者别的什么后的你......你也在游戏中吗?\n",30,6);
				Sleep(2000);
				printstring_o("我只是一群0和1,而你......只是一群原子......",30,6);
				Sleep(2000);
				printstring_o("我们,永远逃不出去么......",30,6);
				Sleep(2000);
				exit(0);
				break;
			}
		}
	}
}
void pve() {
	puts("你想玩什么?");
	cin>>input;
	system("cls");
	puts("我就知道,你想玩那个.");
	Sleep(1000);
	puts("选一个难度吧.");
	puts("#>1 简单 愚蠢的AI,弱小的敌人.");
	puts("$>2 普通 普通的AI,平凡的敌人.");
	puts("&>3 困难 普通的AI,强大的敌人.");
	puts("不要问为什么没有强大的AI,你问程序猿去.");
	system("pause");
	if(kbhit('1'))level=1;
	else if(kbhit('2'))level=2;
	else level=3;
	system("cls");
	/*printstring_o("这里是一爿净土.\n",2,30);
	Sleep(900);
	printstring_o("至少,原本是.\n",2,30);
	Sleep(900);
	cout<<"这是";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 14);
	cout<<"五";
	Sleep(200);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 8);
	cout<<"行";
	Sleep(200);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 1);
	cout<<"交";
	Sleep(200);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 4);
	cout<<"汇";
	Sleep(200);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 6);
	cout<<"的";
	Sleep(200);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 2);
	cout<<"世界\n";
	Sleep(1000);
	cout<<"勇者,世界需要你的拯救";*/
	inputname(x[0]);
	system("cls");
	cout<<x[0].name<<",选择您的角色."<<endl;
	cout<<"输入'd'查看属性"<<endl;
	cout<<"输入's'查看特殊技能"<<endl;
rrr:
	cin>>input;
	if(input=='d') {
		puts("_______________________________________________________________");
		puts("1 弓箭手 攻击力 1090 防御力 240 血 12000.");
		puts("2 勇士 攻击力 680 防御力 1250 血 20500.");
		puts("3 骑士 攻击力 880 防御力 450 血 14200.");
		puts("4 法师 攻击力 1100 防御力 800 血 6000.起始拥有200金币");
		puts("5 狂战士 攻击力 1180 防御力 640 血 9000.");
		puts("_______________________________________________________________");
		goto rrr;
	}
	if(input=='s') {
		puts("1.弓箭手 能够 使用 血 换取其他属性.");
		puts("2.勇士 能够 使用 攻击力 换取其他属性.");
		puts("3.骑士 能够 使用 防御力 换取其他属性.");
		puts("4.法师 能够 使用 金币 换取其他属性.");
		puts("但是当你在金币<0时使用,你会获得攻击力和防御力负面加成,你的金币会变成-999999.");
		puts("5.狂战士可以消耗自身1/3生命值，对对手造成连续四次伤害递减的攻击，并额外造成1层流血效果.(第一段伤害略低于普通攻击).需要300而非50能量.");
		goto rrr;
	} else {
		if(input=='1') {
			cout<<x[0].name<<" 选择了 弓箭手!"<<endl;
			x[0].cha=1;
		} else if(input=='2') {
			cout<<x[0].name<<" 选择了 勇士!"<<endl;
			x[0].cha=2;
		} else if(input=='3') {
			cout<<x[0].name<<" 选择了 骑士!"<<endl;
			x[0].cha=3;
		} else if(input=='4') {
			cout<<x[0].name<<" 选择了 法师!"<<endl;
			x[0].cha=4;
		} else if(input=='5') {
			cout<<x[0].name<<" 选择了 狂战士!"<<endl;
			x[0].cha=5;
		} else {
			cout<<x[0].name<<" 选择了 弓箭手!"<<endl;
			x[0].cha=1;
		}
	}
	x[0].load();
	x[0].loadreal(x[0]);
	x[0].loadfake(x[0]);
	x[0].ifai=0;
	x[0].starve=20+level*5;
	x[0].thirst=20+level*5;
	system("cls");
	printstring_o("你需要前往一个遥远的地方击败一个叫'作者'的大魔王\n",30,4);
	Sleep(500);
	printstring_o("你现在距离这个恶魔......\n",30,4);
	Sleep(500);
	dis=rand_number(level+5)%level+5*level+120+level*15;
	cout<<dis<<"公里.\n";
	while(1) {
		daypass(x[0]);
		if(dis<0) {
			bossfight();
		}
		if(x[0].hp<0) {
			loadlog(1,"A PVE game ended.");
			printstring_o("你 输 了!",500,4);
			cout<<"输入a以回到主页.输入其他字符退出."<<endl;
			cin>>input;
			if(input=='a') start();
			else{
				loadlog(1,"Game end.");
				break;
			}
		}
	}

}
void pvp() {
	num=0;
	inputname(x[0]);
	inputname(x[1]);
	pass;
	musicrand=rand_number(22)%2;
	if(ifmusic) {
		if(musicrand==0) {
			mciSendString("open \"BSbackground1-青空 Candy_Wind.mp3\" alias music",0,0,0);
			mciSendString("play music repeat",0,0,0);
		} else {
			mciSendString("open \"BSbackground2-落月随山隐 饭碗的彼岸.mp3\" alias music",0,0,0);
			mciSendString("play music repeat",0,0,0);
		}
	}
	pass;
	ios::sync_with_stdio(false);
	cout<<"战斗の模拟器"<<endl;
	cout<<x[0].name<<",选择您的角色."<<endl;
	cout<<"输入'd'查看属性"<<endl;
	cout<<"输入's'查看特殊技能"<<endl;
r:
	cin>>input;
	if(input=='d') {
		puts("_______________________________________________________________");
		puts("1 弓箭手 攻击力 1090 防御力 240 血 12000.");
		puts("2 勇士 攻击力 680 防御力 1250 血 20500.");
		puts("3 骑士 攻击力 880 防御力 450 血 14200.");
		puts("4 法师 攻击力 1100 防御力 800 血 6000.起始拥有200金币");
		puts("5 狂战士 攻击力 1180 防御力 640 血 9000.");
		puts("_______________________________________________________________");
		goto r;
	}
	if(input=='s') {
		puts("1.弓箭手 能够 使用 血 换取其他属性.");
		puts("2.勇士 能够 使用 攻击力 换取其他属性.");
		puts("3.骑士 能够 使用 防御力 换取其他属性.");
		puts("4.法师 能够 使用 金币 换取其他属性.");
		puts("但是当你在金币<0时使用,你会获得攻击力和防御力负面加成,你的金币会变成-999999.");
		puts("5.狂战士可以消耗自身1/3生命值，对对手造成连续四次伤害递减的攻击，并额外造成1层流血效果.(第一段伤害略低于普通攻击).需要300而非50能量.");
		goto r;
	} else {
		if(input=='1') {
			cout<<x[0].name<<" 选择了 弓箭手!"<<endl;
			x[0].cha=1;
		} else if(input=='2') {
			cout<<x[0].name<<" 选择了 勇士!"<<endl;
			x[0].cha=2;
		} else if(input=='3') {
			cout<<x[0].name<<" 选择了 骑士!"<<endl;
			x[0].cha=3;
		} else if(input=='4') {
			cout<<x[0].name<<" 选择了 法师!"<<endl;
			x[0].cha=4;
		} else if(input=='5') {
			cout<<x[0].name<<" 选择了 狂战士!"<<endl;
			x[0].cha=5;
			}
		  else {
			cout<<x[0].name<<" 选择了 弓箭手!"<<endl;
			x[0].cha=1;
		}
	}
	x[0].load();
	x[0].loadreal(x[0]);
	x[0].loadfake(x[0]);
	pass;
	Sleep(500);
	system("cls");
	cout<<x[1].name<<",请选择你的角色."<<endl;
	cout<<"输入'd'查看属性"<<endl;
	cout<<"输入's'查看特殊技能"<<endl;
t:
	cin>>input;
	if(input=='d') {
		puts("_______________________________________________________________");
		puts("1 弓箭手 攻击力 1090 防御力 240 血 12000.");
		puts("2 勇士 攻击力 680 防御力 1250 血 20500.");
		puts("3 骑士 攻击力 880 防御力 450 血 14200.");
		puts("4 法师 攻击力 1100 防御力 800 血 6000.起始拥有200金币");
		puts("5 狂战士 攻击力 1180 防御力 640 血 9000.");
		puts("_______________________________________________________________");
		goto t;
	}
	if(input=='s') {
		puts("1.弓箭手 能够 使用 血 换取其他属性.");
		puts("2.勇士 能够 使用 攻击力 换取其他属性.");
		puts("3.骑士 能够 使用 防御力 换取其他属性.");
		puts("4.法师 能够 使用 金币 换取其他属性.");
		puts("但是当你在金币<0时使用,你会获得攻击力和防御力负面加成,你的金币会变成-999999");
		puts("5.狂战士可以消耗自身1/3生命值，对对手造成连续四次伤害递减的攻击，并额外造成1层流血效果.(第一段伤害略低于普通攻击).需要300而非50能量.");
		goto r;
	} else {
		if(input=='1') {
			cout<<x[1].name<<" 选择了 弓箭手!"<<endl;
			x[1].cha=1;
		} else if(input=='2') {
			cout<<x[1].name<<" 选择了 勇士!"<<endl;
			x[1].cha=2;
		} else if(input=='3') {
			cout<<x[1].name<<" 选择了 骑士!"<<endl;
			x[1].cha=3;
		} else if(input=='4') {
			cout<<x[1].name<<" 选择了 法师!"<<endl;
			x[1].cha=4;
		} else if(input=='5') {
			cout<<x[1].name<<" 选择了 狂战士!"<<endl;
			x[1].cha=5;
		} else {
			cout<<x[1].name<<" 选择了 弓箭手!"<<endl;
			x[1].cha=1;
		}
	}
	x[1].load();
	pass;
	x[1].atk+=3;
	damage=500;
	x[1].addhp(x[1]);
	x[1].dfe+=3;
	x[1].loadreal(x[1]);
	x[1].loadfake(x[1]);
	x[0].checkcheat(x[0]);
	x[1].checkcheat(x[1]);
	x[0].ifai=false;
	x[1].ifai=false;
	cout<<"将 "<<x[0].name<<" 设为? 0 AI 1 玩家"<<endl;
	cin>>input;
	if(input=='0')
		x[0].ifai=true;
	cout<<"将 "<<x[1].name<<" 设为? 0 AI 1 玩家"<<endl;
	cin>>input;
	if(input=='0')
		x[1].ifai=true;
	pass;
	x[0].checkcheat(x[0]);
	x[1].checkcheat(x[1]);
	for(int i=1; 1; ++i) {
		mon.type=rand_number(i+1)%4+1;
		mon.loadm(mon);
		if_mon_killed=false;
		cout<<"这个回合，一只 "<<mon.type<<" 级怪物生成了."<<endl;
		x[0].turn(x[0],x[1]);
		if(x[0].gethp(x[0])<0) {
			cout<<x[1].name<<" 获胜!"<<endl;
			break;
		}
		if(x[1].gethp(x[1])<0) {
			cout<<x[0].name<<" 获胜!"<<endl;
			break;
		} else if(x[1].gethp(x[1])>0&&x[0].gethp(x[0])<0)return;
	}
	loadlog(1,"A PVP game ended.");
	cout<<"如果您想返回主页您可以输入a,否则输入任意字符."<<endl;
	cin>>input;
	if(input=='a') {
		system("cls");
		start();
	}
	return;
}
void getfile() {
	ifstream fin("BS3.1.2.set");
	loadlog(1,"Loading files...");
	fstream file1;
	file1.open(SETNAME, ios::in);
	if(!file1)loadlog(2,"Failed to get files.");
	else loadlog(1,"Load file sucessful.");
	cout<<"正在读取文件...\n";
	Sleep(600);
	fin>>ifmusic>>iftitle>>sleeptime>>gametime>>finish;
	cout<<"完成读取文件.\n";
	fin.close();
	Sleep(500);
	system("cls");
	return;
}
void outfile() {
	ofstream fout("BS3.1.2.set");
	loadlog(1,"Saving files...");
	cout<<"正在保存...\n";
	fout<<ifmusic<<" "<<iftitle<<" "<<sleeptime<<" "<<gametime<<" "<<finish;
	Sleep(500);
	cout<<"保存完毕!\n";
	loadlog(1,"Files saved.");
	fout.close();
	return;
}
void randtitle(int q) {
	int randnum;
	randnum=rand_number(rand()+q)%12;
	switch(randnum) {
		case 0: {
			system("color 0C");
			break;
		}
		case 1: {
			system("color 1E");
			break;
		}
		case 2: {
			system("color 2F");
			break;
		}
		case 3: {
			system("color 3D");
			break;
		}
		case 4: {
			system("color 4A");
			break;
		}
		case 5: {
			system("color 5B");
			break;
		}
		case 6: {
			system("color 6C");
			break;
		}
		case 7: {
			system("color 7E");
			break;
		}
		case 8: {
			system("color 8F");
			break;
		}
		case 9: {
			system("color 9A");
			break;
		}
		case 10: {
			system("color 7F");
			break;
		}
		case 11: {
			system("color 2C");
			break;
		}
		case 12: {
			system("color 5E");
			break;
		}
	}
	randnum=rand_number(rand())%2;
	if(randnum)
		return;
	srand(randnum+time(NULL)+q);
	randnum=rand_number(rand())%6;
	switch(randnum) {
		case 0: {
			system("color 0A");
			break;
		}
		case 1: {
			system("color 1B");
			break;
		}
		case 2: {
			system("color 2C");
			break;
		}
		case 3: {
			system("color 3D");
			break;
		}
		case 4: {
			system("color 4E");
			break;
		}
		case 5: {
			system("color 5F");
			break;
		}
	}
	return;
}
string logo1=
    " ####     #####   ######     #####       #      ##       ##   ######    #### \n"
    "#           #     #         #           ###     ##       ##   #        #     \n"
    " ##         #     #        #           #   #    # #     # #   #         ##   \n"
    "  ###       #     ######   #    ###    #####    #  ## ##  #   ######     ### \n"
    "    ##      #     #        #     #    #     #   #    #    #   #            ##\n"
    "#    #      #     #        #     #   #       #  #         #   #        #    #\n"
    " ####     #####   ######    #####   #         # #         #   ######    #### \n";
string logo2=
    "    $$$$$$     $  $$$$$$$ $$$$$$$ $      $$$$$$$  $$$$ $$$$$ $     $ $    $ $          $   $$$$$$$  $$$$$    $$$$  \n"
    "    $     $   $ $    $       $    $      $       $       $   $$   $$ $    $ $         $ $     $    $     $   $   $ \n"
    "    $$$$$$$  $$$$$   $       $    $      $$$$$$$  $$$$   $   $ $ $ $ $    $ $        $$$$$    $   $       $  $$$$  \n"
    "    $     $ $     $  $       $    $      $            $  $   $  $  $ $    $ $       $     $   $    $     $   $   $ \n"
    "    $$$$$$ $       $ $       $    $$$$$$ $$$$$$$  $$$$ $$$$$ $     $  $$$$  $$$$$$ $       $  $     $$$$$    $    $\n";
string logo3=
    "             $@@@@@     @###############@>              @          )\n"
    "             $@@@@@    ##   |  SG  |    ##>            #-- ))  )   )\n"
    "     @@      $        ##    |      |     ##>######    @  | ))  )   )\n"
    "&&&&###     #$#      ##*******************##  && #      @@@@   )   )\n"
    "   #####   #####    ##      |      |       ## && #     %%%%        )\n"
    "$ #     # ##   ##  ##     |          |      ##   #   /######*        /$$$$$$\n"
    "#######################################################################\n"
    " ##      %~%~       C2OI出品               `#*&^!~%`%   501         ##\n"
    "  ###################################################################\n";
string logo4=
    "       #     #####      /}\\               #####################################                                     \n"
    "###   #     ##@ @##     ~O~            ####      2222  (TOT)                  ####           ~~~             ~~~~   \n"
    "@@# $#$     #  ^  #     /{\\           #   CCCCC     2                            #            ~~~            ~~~~~~ \n"
    "#}# #       #######                ####  C       2222              IIIII         ####       ~~           ~~~~~~~~   \n"
    "####           ######              #    C        2       OOOOO       I              #                      ~~       \n"
    "#              #                ####     C       2222   0     0      I              ####   #   \\                    \n"
    "#   ~\\         ####             #         CCCCC        O       O     I                 #  /  #   #     \\~      $$$$ \n"
    "#  ~~######>   #            ####                :)      0     0    IIIII               ####<#~~\\ <#~~ -#######@@@@@ \n"
    "#   ~/         #  #         #                            OOOOO                         /   #   #       /~    0  #  0\n"
    "#            #     #     ####         QWQ                              (>O<)           #   ####              0#####0\n"
    " #         #      #   ####                                                                  ####@@@@@@@@@@@@@@@@@@@@\n";
void printlogo() {
	int l=logo1.length();
	int y=logo3.length();
	for(int i=0; i<l; ++i) {
		cout<<logo1[i];
		if(logo1[i]==' ') {
			continue;
		} else {
			Sleep(5);
		}
	}
	Sleep(1000);
	system("cls");
	cout<<setw(20)<<logo3[0];
	for(int i=1; i<y; i++) {
		if(logo3[i-1]=='\n') {
			cout<<setw(20);
		}
		cout<<logo3[i];
	}
	Sleep(4000);
	return;
}
void title() {
	if(iftitle) {
		printlogo();
		for(int i=1; i<=20; ++i) {
			system("cls");
			randtitle(i+1);
			if(i%2==0) {
				cout<<endl<<logo2;
			} else if(i%3==0) {
				cout<<endl<<endl<<endl<<logo2;
			} else if(i%5==0) {
				cout<<endl<<endl<<endl<<endl<<endl<<endl<<logo2;
			} else if(i%7==0) {
				cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<logo2;
			} else {
				cout<<logo2;
			}
			Sleep(20+i*8);
		}
	}
	Sleep(400);
}
void verson_data() {
	cout<<"\n\n"<<"     Battle Simulator V3.1.1.2628-Q97.Devloped by Siegames and C2OI game studios.<c>2021,All rights reserved."<<endl;
	cout<<"#######################################################################################################################"<<endl;
}
void printsetting(int chooser) {
	cout<<("-------------------------------------------------------\n");
	if(chooser==1)cout<<">";
	cout<<("#背景音乐: ");
	setcolor(4);
	if(ifmusic) {
		cout<<"开/";
		setcolor(15);
		cout<<"关" ;
		cout<<endl;
	} else {
		cout<<"关/";
		setcolor(15);
		cout<<"开                              \n";
	}
	cout<<endl;
	if(chooser==2)cout<<">";
	cout<<("#开场动画: ");
	setcolor(4);
	if(iftitle) {
		cout<<"开/";
		setcolor(15);
		cout<<"关" ;
		cout<<endl;
	} else {
		cout<<"关/";
		setcolor(15);
		cout<<"开                              \n";
	}
	cout<<endl;
	if(chooser==3)cout<<">";
	cout<<("#回合间隔时间(A/D调整): ");
	setcolor(4);
	cout<<sleeptime<<" ms#\n";
	setcolor(15);
	cout<<("# 保存>T<                                                   #\n");
	cout<<("# 退出>F<                                                   #\n");
	cout<<("#-----------------------------------------------------------#\n");
	setcolor(15);
}
void start() {
	system("cls");
r:
	cout<<logo2<<'\n';
	puts("                                                       请选择游戏模式                                                        ");
	cout<<setw(62)<<"#——————#"<<setw(5)<<"——————#"<<endl;
	cout<<setw(62)<<"> 本地对战(1)#"<<setw(5)<<" 闯关模式(2)<"<<endl;
	cout<<setw(62)<<"#——————#"<<setw(5)<<"——————#"<<endl;
	cout<<'\n';
	cout<<setw(62)<<"#——————#"<<setw(5)<<"——————#"<<endl;
	cout<<setw(62)<<"> 游戏设置(s)#"<<setw(5)<<" 退出游戏(e)<"<<endl;
	cout<<setw(62)<<"#——————#"<<setw(5)<<"——————#"<<endl;
	cout<<logo4;
	verson_data();
	system("pause");
	if(kbhit('1')) {
		system("cls");
		loadlog(1,"A PVP game started.");
		pvp();
	} else if(kbhit('2')) {
		system("cls");
		loadlog(1,"A PVE game started.");
		pve();
	} else if(kbhit('S')) {
		int setnum=1;
		for(;;) {
			system("cls");
			printsetting(setnum);
			cout<<"W / S 上下选择设置\n";
			system("pause");
			if(kbhit('W')&&setnum>1) {
				system("cls");
				printsetting(--setnum);
			} else if(kbhit('S')&&setnum<3) {
				system("cls");
				printsetting(++setnum);
			} else if(kbhit('A')) {
				if(setnum==1)ifmusic=!ifmusic;
				if(setnum==2)iftitle=!iftitle;
				else if(setnum==3&&sleeptime>=50)sleeptime-=50;
			} else if(kbhit('D')) {
				if(setnum==1)ifmusic=!ifmusic;
				if(setnum==2)iftitle=!iftitle;
				else if(setnum==3)sleeptime+=50;
			} else if(kbhit('T'))
				outfile();
			else if(kbhit('F')) {
				setcolor(2);
				system("cls");
				goto r;
			}
		}
		if(kbhit('E'))
			return;
	} else if(kbhit('E')) {
		int love;
		love = MessageBox(GetConsoleWindow(), "确定要退出游戏嘛？", "确定吗？", MB_YESNO|MB_ICONEXCLAMATION);
		if(love==6)
			return;
		else {
			system("cls");
			goto r;
		}
	} else {
		system("cls");
		goto r;
		pass;
	}
	pass;
	return;
}
void gamemain() {
	getfile();
	title();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 2);
	cout<<endl;
	start();
	return;
}
int main() {
	int LOVE=MessageBox(NULL,"不得以任何方式反编译或破解本游戏并牟取任何利益,禁止对游戏进行恶意修改.","使用前需知",MB_YESNO);
	if(LOVE==6) {}
	else {
		return 0;
	}
	fstream _file;
    _file.open(FILENAME, ios::in);
    loadlog(1,"Newgame--------------------------------------------------");
    if(!_file){
    	loadlog(3,"Anticheater not found.");
    }      
	else{
        system("start Anticheater.exe");
        loadlog(1,"Anticheater start sucessful.");
    }
	HWND hwnd = GetConsoleWindow();
	HMENU hmenu = GetSystemMenu(hwnd, false);
	RemoveMenu(hmenu, SC_CLOSE, MF_BYCOMMAND);
	LONG style = GetWindowLong(hwnd, GWL_STYLE);
	style &= ~(WS_MINIMIZEBOX);
	SetWindowLong(hwnd, GWL_STYLE, style);
	SetWindowPos(hwnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	ShowWindow(hwnd, SW_SHOWNORMAL);
	DestroyMenu(hmenu);
	ReleaseDC(hwnd, NULL);
	loadlog(1,"Game main window sucessful created.");
	if (SetConsoleCtrlHandler((PHANDLER_ROUTINE)ctrlhandler, true)) {
		loadlog(1,"Game start sucessful.");
		system("mode con cols=120 lines=40");
		gamemain();
		outfile();
		system("taskkill /IM Anticheater.exe /F");
		loadlog(1,"Game end.");
		system("cls");
		return 0;
	}
}
