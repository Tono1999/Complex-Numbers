/***************************************************************
Clase para los numeros complejos con la respectiva sobrecarga
de operadores

By
Angel Antonio Mendez Hernandez
***************************************************************/

#include <iostream>
using namespace std;

class complex{
private:
    double re;
    double im;
public:
    complex(double re, double im): re(re), im(im) {}
    complex operator+(const complex& obj){
        return complex(re+obj.re, im+obj.im);
    }
    complex operator-(const complex& obj){
        return complex(re-obj.re, im-obj.im);
    }
    complex operator*(const complex& obj){
        return complex(re*obj.re-im*obj.im, re*obj.im+im*obj.re);
    }
    complex operator/(const complex& obj){
        if(obj.re==0 && obj.im==0){
            cerr<<"División por cero"<<endl;
            exit(-1);
        }
        return complex((re*obj.re+im*obj.im)/(obj.re*obj.re+obj.im*obj.im), (im*obj.re-re*obj.im)/(obj.re*obj.re+obj.im*obj.im));
    }
    friend void mostrar(complex& obj);
};

void mostrar(complex& obj){
    if(obj.im+obj.im>0)
        cout<<obj.re<<"+"<<obj.im<<"i"<<endl;
    else
        cout<<obj.re<<obj.im<<"i"<<endl;
}


int main()
{
    complex a(0.5,0.3);
    complex b(2, 1.5);
    complex c(0,0);
    c=a+b;
    cout<<"La suma es: ";
    mostrar(c);
    c=a-b;
    cout<<"La resta es: ";
    mostrar(c);
    c=a*b;
    cout<<"La multiplicacion es: ";
    mostrar(c);
    c=a/b;
    cout<<"La division es: ";
    mostrar(c);

    return 0;
}
