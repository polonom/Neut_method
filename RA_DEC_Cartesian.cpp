
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <fstream>
#include <math.h>
using namespace std;
//Код, который переводит RA и DEC в XYZ, с исправленным DEC
int main(int argc, const char * argv[]) {
    //Открываем файл для чтения
    ifstream filei;
    filei.open(argv[1]);
    if (!filei.is_open()){
        cout<<"Error\n";
    }
    else {
        cout<<"Ok1\n";
    }
    //Открываем файл для записи
    std::ofstream fileo;
        fileo.open(argv[2]);
        if (!fileo.is_open()){
            cout<<"Error\n";
        }
        else cout<<"Ok2\n";
   
    double i;
    double num[6];
    double X, Y, x3, y3, z3;
    int cnt=0;
    while(filei>>i){
        
        cnt=cnt+1;
        if (cnt%6!=0) {
			
			num[(cnt%6)-1]=i;
		}
		else num[5]=i;
        //cout<<"i="<<i<<" cnt="<<cnt<<endl;
        if (cnt%6==3){
            num[0]=num[0]*15;
            num[1]=num[1]*15/60;
            num[2]=num[2]*15/3600;
            /*if ((num[0]+num[1]+num[2])>180) {
                X=(num[0]+num[1]+num[2]-360);}
            else X=(num[0]+num[1]+num[2]); */
            X=(num[0]+num[1]+num[2]-180);
            if (X>180 or X<-180) {cout<<"Warning!"<<cnt;}}
        if (cnt%6==0){
            num[4]=num[4]/60;
            num[5]=num[5]/3600;
            if (num[3]>=0)
            {Y=(num[3]+num[4]+num[5]);}
            else Y=(num[3]-num[4]-num[5]);
            z3= sin(3.14*Y/180);
            y3= sin(3.14*X/180)*cos(3.14*Y/180);
            x3= cos(3.14*X/180)*cos(3.14*Y/180);
            //cout<<X<<"  "<<Y<<endl;
            fileo<<x3<<"   "<<y3<<"   "<<z3<<endl;
        }
       // cout<<X<<"  "<<Y<<endl;
        }
    return 0;
}
