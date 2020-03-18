#include<iostream>  
#define max_input 20
using namespace std; 

int input[max_input] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1}; 
int error = 0;
struct page{ 
    int num; 
    int mark; 
} frame[3];

void first_three(){ //处理前三个引用 
    for(int i = 0; i < 3; i++){ 
        frame[i].num = input[i]; 
        error++; 
        cout<<frame[i].num<<" | "; 
        for(int j = 0; j <= i; j++) 
            cout << frame[j].num << ' '; 
        cout<<endl; 
    } 
}

void FIFO(){ 
    cout<<"------FIFO-----------"<<endl; 
    error = 0; 
    first_three();

    for(int i = 3; i < max_input; i++) { 
        int j; 
        for(j = 0 ;j < 3; j++) 
            if(input[i] == frame[j].num) { 
                cout<<input[i]<<endl; 
                break; 
            } 

        if(j == 3) { 
            error++; 
            frame[((error - 1)%3)].num = input[i];//换掉最旧的页  
            cout<<input[i]<<" | "; 
            for(int k = 0; k < 3; k++) 
                cout<<frame[k].num<<' '; 
            cout<<endl; 
        } 
    } 
    cout<<"Frame Error:"<<error<<endl<<endl; 
} 

void OPT(){ 
    cout<<"------OPT------------"<<endl; 
    error=0; 
    
    first_three();

    for(int i = 3; i < max_input; i++) { 
        int j; 
        for(j = 0; j < 3; j++) 
            if(input[i] == frame[j].num) { 
                cout<<input[i]<<endl; 
                break; 
            } 

        if(j == 3) { 
            error++; 
            for(j = 0; j < 3; j++) { 
                frame[j].mark = max_input + 1; 
                for(int k = max_input; k >= i; k--){//向后遍历，找到最长时间不用的页  
                    if(frame[j].num == input[k]) 
                        frame[j].mark = k; 
                } 
            } 

            if(frame[0].mark > frame[1].mark && frame[0].mark > frame[2].mark) 
                frame[0].num = input[i]; 
            else if(frame[1].mark > frame[0].mark && frame[1].mark > frame[2].mark) 
                frame[1].num = input[i]; 
            else 
                frame[2].num = input[i]; 

            cout<<input[i]<<" | "; 
            for(int k = 0; k < 3; k++) 
                cout<<frame[k].num<<' '; 
            cout<<endl; 
        } 
    } 
    cout<<"Frame Error:"<<error<<endl<<endl; 
} 

void LRU() { 
    cout<<"------LRU------------"<<endl; 
    error=0; 
    
    first_three();

    for(int i = 3; i < max_input; i++) { 
        int j; 
        for(j = 0; j < 3; j++) 
            if(input[i] == frame[j].num) { 
                cout<<input[i]<<endl; 
                break; 
            } 

        if(j==3) { 
            error++; 

            for(j = 0; j < 3; j++) { 
                frame[j].mark = 0; 
                for(int k = 0; k <= i; k++){//向前遍历，找到最近最少使用的  
                    if(frame[j].num == input[k]) 
                        frame[j].mark = k; 
                } 
            } 

            if(frame[0].mark < frame[1].mark && frame[0].mark < frame[2].mark) 
                frame[0].num = input[i]; 
            else if(frame[1].mark < frame[0].mark && frame[1].mark < frame[2].mark) 
                frame[1].num = input[i]; 
            else 
                frame[2].num = input[i]; 
            cout<<input[i]<<" | "; 

            for(int k = 0; k < 3; k++) 
                cout<<frame[k].num<<' '; 
            cout<<endl; 
        } 
    } 
    cout<<"Frame Error:"<<error<<endl<<endl; 
} 

int main() { 
    FIFO(); 
    OPT(); 
    LRU(); 
} 