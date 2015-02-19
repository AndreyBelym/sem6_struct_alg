#include "muParser.h"
#include <iostream>
#include <string>
#include <cstdlib>
mu::Parser parser;
double x_parser;
double f(double x){
    x_parser=x;
    double res;
    try{
        res=parser.Eval();
    }catch(mu::Parser::exception_type &e){
        exit(1);
    }
    return res;
}

double Root(double (*f)(double x), //f - анализируемая функция;
                const double a, //a,b - границы отрезка поиска корня;
                const double b,
                const double  eps  //eps - точность вычислений;
                    ){
  double c;
    c=(a+b)/2;
    if (b-a>eps)
        if ((*f)(c)*(*f)(a)<=0)
            return Root(f,a,c,eps);
        else
            return Root(f,c,b,eps);
    else
        return c;
}
using namespace std;
int main(){
    cout<<"Программа ищет корень функции f(x)"<<endl
        <<"на интервале [a,b] с точностью eps."<<endl;
    string expr;
    cout<<"Введите функцию f(x)."<<endl<<"f(x)="<<flush;
    cin>>expr;
    try{
        parser.SetExpr(expr);
        parser.DefineVar("x",&x_parser);
    }catch(mu::Parser::exception_type &e){
        return 1;
    }
    double a,b,eps;
    cout<<"Введите a."<<endl;
    cin>>a;
    cout<<"Введите b."<<endl;
    cin>>b;
    if(b<=a)
        return 2;
    cout<<"Введите eps."<<endl;
    cin>>eps;
    if(eps<=0)
        return 3;
    cout<<"f(x)=0 при x=";
    cout<<Root(&f,a,b,eps);
    cout<<endl;
    return 0;
}
