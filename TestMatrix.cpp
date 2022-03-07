#include "Matrix.h"

int main()
{
    float data[] = {1, 2, 3, 4, 5, 6};
    Matrix M1(2,3,data);

    cout<<"M1:\n";
    M1.print();
    cout<< endl;

    cout<<"Transpose of M1:\n";
    M1.transpose().print();
    cout<< endl;

    float data1[] = {7, 3, 0, 1, 6, 2};
    Matrix M2(2,3,data1);

    cout<<"M2:\n";
    M2.print();
    cout<< endl;


    cout<< "M1+M2:\n" << M1+M2 << endl
            << "\nM1-M2:\n" << M1-M2 << endl
            << "\nM1*M2:\n" << M1*M2 <<endl;

    Matrix temp(M1);        

    M1 += M2;
    cout<< "\nAfter M1+=M2, M1:\n" << M1 << endl;

    M1 = temp; //restoring older values

    M1 -= M2;
    cout<< "\nAfter M1-=M2, M1:\n" << M1 << endl;

    M1 = temp; //restoring older values

    M1 *= M2;
    cout<< "\nAfter M1*=M2, M1:\n" << M1 << endl;

    M1 = temp; //restoring older values

    if(M1 == temp){
        cout<<"\nM1 is equal to temp" << endl;
    }

    if(M1 != M2){
        cout<<"M1 not equal to M2" << endl;
    }

    const float *values = M2.getData();
    int r = M2.getRowN();
    int c = M2.getColN();

    cout<<"\nValues in M2.data[]:\n";
    for(int i=0; i<r*c; i++){
            cout<<values[i]<<" ";
    }

    delete values;

    cout<<"\n\nValue at 0,2 in M1: "<< M1(0,2) << endl;

    return 0;
}
