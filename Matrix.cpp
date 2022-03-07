#include "Matrix.h"

ostream& operator<<(ostream& output, const Matrix &rhs){
        for(int i=0; i<rhs.rowN*rhs.colN; i++){
                output<< rhs.data[i] << " ";
        }
        return output;
}


Matrix::Matrix(){
        rowN = 1;
        colN = 1;
        data = new float[1];
        data[0] = 0;
}


Matrix::Matrix(const int rN,const int cN ){
        rowN = rN;
        colN = cN;
        data = new float[rowN*colN];

        for(int i=0; i<rowN*colN; i++){
                data[i] = 0;
        }
}


Matrix::Matrix(const Matrix &srcMatrix ){
        rowN = srcMatrix.rowN;
        colN = srcMatrix.colN;

        data = new float[rowN*colN];

        for(int i=0; i<rowN*colN; i++){
                data[i] = srcMatrix.data[i];
        }
}


Matrix::Matrix(const int rN, const int cN, const float *srcPtr){
        rowN = rN;
        colN = cN;
        data = new float[rowN*colN];

        for(int i=0; i<rowN*colN; i++){
                data[i] = srcPtr[i];
        }
}


const float* Matrix::getData()const{
        int size = rowN*colN;
        float *temp = new float[size];
        for(int i=0; i<size; i++){
                temp[i] = data[i];
        }

        return temp;
}


int Matrix::getRowN()const{
        return rowN;
}


int Matrix::getColN()const{
        return colN;
} 

void Matrix::print()const{
        for(int i=0; i<rowN*colN; i++){
                cout<< data[i] << " ";
                if((i+1)%colN == 0){
                        cout<<endl;
                }
        }
} 


Matrix Matrix::transpose(){
        Matrix tpose(colN, rowN);
        int k = 0;

        for(int i=0; i<colN; i++){
                int index = i;
                for(int j=0; j<rowN; j++){
                        tpose.data[k] = data[index];
                        k++;
                        index += colN;
                }
        }

        return tpose;
} 
 

Matrix Matrix::operator+(const Matrix &rhsMatrix)const{
        Matrix temp(*this);
        for(int i=0; i<rowN*colN; i++){
                temp.data[i] += rhsMatrix.data[i];
        }

        return temp;
}


Matrix Matrix::operator-(const Matrix &rhsMatrix)const{
        Matrix temp(*this);
        for(int i=0; i<rowN*colN; i++){
                temp.data[i] -= rhsMatrix.data[i];
        }

        return temp;
}


Matrix Matrix::operator*(const Matrix &rhsMatrix)const{
        Matrix temp(*this);
        for(int i=0; i<rowN*colN; i++){
                temp.data[i] *= rhsMatrix.data[i];
        }

        return temp;
}


float Matrix::operator()(const int r,const int c)const{
        int index = (r*colN)+c; 
        return data[index];
}


float& Matrix::operator[](int ind){
        return data[ind];
} 

        
float Matrix::operator[](int ind) const{
        return data[ind];
} 


Matrix& Matrix::operator=(const Matrix &rhsMatrix){
        rowN = rhsMatrix.rowN;
        colN = rhsMatrix.colN;
        delete data;

        data = new float[rowN*colN];
        for(int i=0; i<rowN*colN; i++){
                data[i] = rhsMatrix.data[i];
        }

        return *this;
}

Matrix& Matrix::operator+=(const Matrix &rhsMatrix){
        for(int i=0; i<rowN*colN; i++){
                data[i] += rhsMatrix.data[i];
        }

        return *this;
}


Matrix& Matrix::operator-=(const Matrix &rhsMatrix){
        for(int i=0; i<rowN*colN; i++){
                data[i] -= rhsMatrix.data[i];
        }

        return *this;
}


Matrix Matrix::operator*=(const Matrix &rhsMatrix)const{
        for(int i=0; i<rowN*colN; i++){
                data[i] *= rhsMatrix.data[i];
        }

        return *this;
}
          

int Matrix::operator==(const Matrix &rhsMatrix)const{
        for(int i=0; i<rowN*colN; i++){
                if(data[i] != rhsMatrix.data[i]){
                        return 0;
                }
        }
        return 1;
}


int Matrix::operator!=(const Matrix &rhsMatrix)const{
        return !(*this == rhsMatrix);
}


Matrix::~Matrix(){
        delete data;
}
