#include <cstdio>
#include <iostream>

#define max_work 9
#define max_length 1024

using namespace std;

struct{
	int name;
	int start;
	int length;
	int finsh;
	bool state;
} work_list[max_work * 2];

struct{
	int length;
	int time;	
} works[max_work];

bool flag = false;
int t = 0;

void init(){
	for(int i = 0; i < (max_work + 1); i++){
		works[i].length = 0;
		works[i].time = 0;
	}
	for (int i = 0; i <= max_work * 2; i++){
		work_list[i].start = max_length;
		work_list[i].length = 0;
		work_list[i].state = false;
		work_list[i].finsh = 0;
	}
	work_list[0].length = max_length;
	work_list[0].start = 0;
}

void show(){
	for(int i = 0; i < (max_work * 2) - 1; i++){
		if(work_list[i].length != 0){
			cout<<work_list[i].start<<"KB"<<endl;
			if(work_list[i].state == true) cout<<"作业"<<work_list[i].name<<endl;
			else  cout<<"空闲区"<<endl;
		}
	}

	cout<<max_length<<"KB"<<endl;
	cout<<"此时单位时间"<<t<<endl;
	cout<<endl;
	t++;
}


void first_fit(){
	for(int i = 0; i < max_work + 1; i++){
		flag = false;
		if(works[i].length == 0) flag = true;
		for(int j = 0; j < (max_work * 2) - 1; j++){
			if(works[i].length < work_list[j].length && works[i].length != 0){
				work_list[j].length = works[i].length;
				work_list[j].finsh = works[i].time;
				work_list[j].state = true;
				work_list[j].name = i;
				for (int k = (max_work * 2) - 1; k > j; k--)
					work_list[k + 1] = work_list[k];
				work_list[j + 1].start = work_list[j].start + work_list[j].length;
				work_list[j + 1].length = work_list[j + 2].start - work_list[j + 1].start;
				flag = true;
				break;
			}
		}
		if(flag == false){
			show();
			for(int j = 0; j < (max_work * 2) - 1; j++){
				if(work_list[j].finsh != 0) work_list[j].finsh--;
				if(work_list[j].finsh == 0 && work_list[j].state == true){
					work_list[j].state = false;
					if(work_list[j + 1].state == false){
						work_list[j].length = work_list[j].length + work_list[j + 1].length;
						for(int k = j + 1; j <  (max_work * 2) - 2; j++)
							work_list[k] = work_list[k + 1];
					}
					if(work_list[j - 1].state == false){
						work_list[j - 1].length = work_list[j - 1].length + work_list[j].length;
						for(int k = j; j <  (max_work * 2) - 2; j++)
							work_list[k] = work_list[k + 1];
					}
				}
			}
		}
	}
}


void menu(){
	cout<<"欢迎进入模拟内存动态分区分配与回收"<<endl;
	init();

	int i;
	cout<<"请输入需要分配的作业 按格式(作业号(0~9) 作业长度(1~1024) 作业运行时间)输入，-1输入结束"<<endl;
	while(1){
		cin>>i;
		if (i == -1) break;
		else if (i >= 0 && i <= 9){	
			cin>>works[i].length;
			if(works[i].length <= 0 || works[i].length > max_length){
				cout<<"请按格式输入";
				cin>>i;
			}
			else cin>>works[i].time;
		}
		else{
			cout<<"请按格式输入";
			cin>>i;
			cin>>i;
		}
	}

//	for(int i = 0; i < max_work + 1; i++){
//		cout<<works[i].length<<endl;
//		cout<<works[i].time<<endl;
//	}

	cout<<endl;
	show();
	first_fit();
	

	cout<<"是否需要再次模拟？(y/n)";
	char n;
	cin>>n;
	if(n == 'n') return;
	else if (n == 'y') menu();
	else cout<<"请按格式输入！";


}

int main(int argc, char const *argv[]){
	menu();
	return 0;
}


