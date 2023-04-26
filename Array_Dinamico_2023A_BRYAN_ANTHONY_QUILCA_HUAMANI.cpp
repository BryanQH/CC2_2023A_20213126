#include <iostream>
using namespace std;
class DynamicIntegerArray{
private:

    int *data;
    int size;

public:

    DynamicIntegerArray(){
        this->size=0;
        this->data = new int[0];
    }


    DynamicIntegerArray(int arr[], int tam){
        this->size=tam;//
        this->data = new int[size];
        for(int i=0; i<size;i++){
            data[i]=arr[i];
        }
    }


    DynamicIntegerArray(const DynamicIntegerArray &o){
        this->size=o.size;
        this->data = new int[size];
        for(int i=0; i<size; i++){
            data[i]=o.data[i];
        }
    }


    void setSize(int size){
        this->size=size;
    }


    int getSize()const{return size;}

    ~DynamicIntegerArray(){
        delete[] data;
    }
    void insert(int value , int ubi){
        int respaldo[size];
        for(int i=0; i<size; i++){
            respaldo[i]= data[i];
        }
        this->size = size+1;
        this->data = new int[size];

        for(int i=0; i<size; i++){
            if(i<ubi){
                data[i]= respaldo[i];
            }
            else if(i==ubi){
                data[i] = value;
            }
            else{
                data[i] = respaldo[i-1];
            }
        }

    }
    void pushback(int value){
        int respaldo[size];
        for(int i=0; i<size; i++){
            respaldo[i]= data[i];
        }     
        this->size = size+1;
        this-> data = new int[size];
        for(int i=0; i<size; i++){
            if(i<size-1){
                data[i] = respaldo[i];
            }
            else {
                data[size-1]= value;
            }
        }
    }
    void remove (int ubi){
        int respaldo[size];
        for(int i=0; i<size; i++){
            respaldo[i]= data[i];
        }     
        this->size = size-1;
        this->data = new int[size];

        for(int i=0; i<size; i++){
            if(i<ubi){
                data[i]= respaldo[i];
            }
            else {
                data[i]= respaldo[i+1];
            }
        }   
    }
    void imprimir(){
        for(int i = 0;i<size; i++){
            cout<<data[i]<<" ";
        }

    }
};
    int main(){
    int lista[]={1,5,2,6,2,4};
    DynamicIntegerArray da(lista,6);
    da.remove(3);
    da.imprimir();
    return 0;
    }
