#include "Plotter.h"
#include <iostream>
#include "strlib.h"
#include <vector.h>
#include <string>
#include <cctype>
using namespace std;

void runPlotterScript(istream& input) {
    /* TODO: Delete this line and the one after it, then implement this function. */
    PenStyle style={1,"black"};
    drawLine(0,0,0,0,style); // 初始化
    double x0=0;
    double y0=0;
    int label=0; // 判断笔是否落下，1表示落下
    for(string line;getline(input,line);){
        // 因为测试用例中有小写的，所以先将其全部转换为小写
        string tmp="";
        for(char ch:line){
            if(ch>='A'&&ch<='Z'){
                ch=tolower(ch);
            }
            tmp+=ch;
        }
        line=tmp;
        if(startsWith(line,"penup")){
            label=0;
        }else if(startsWith(line,"pendown")){
            label=1;
        }else if(startsWith(line,"moveabs")){
            Vector<string> vec=stringSplit(line," ");
            double x1=stod(vec[1]);
            double y1=stod(vec[2]);
            if(label==1){
                drawLine(x0,y0,x1,y1,style);
            }
            x0=x1;
            y0=y1;
        }else if(startsWith(line,"moverel")){
            Vector<string> vec=stringSplit(line," ");
            double x1=stod(vec[1]);
            double y1=stod(vec[2]);
            if(label==1){
                drawLine(x0,y0,x0+x1,y0+y1,style);
            }
            x0+=x1;
            y0+=y1;
        }else if(startsWith(line,"pencolor")){
            Vector<string> vec=stringSplit(line," ");
            style.color=vec[1];
        }else if(startsWith(line,"penwidth")){
            Vector<string> vec=stringSplit(line," ");
            style.width=stod(vec[1]);
        }

    }
}
