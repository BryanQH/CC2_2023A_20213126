#include <iostream>
using namespace std;

template <typename T>

class DynamicArray{
    private:
        T *array;
        int size;
    public:
        DynamicArray(){
            this->size=0;
            this->array=new T [0];
        }
        DynamicArray(int size){
            this->size=size;
            array=new T [size];
        }
        ~DynamicArray(){
            delete[] array;
        }
        void getData()const{
            cout<<"Tamanio : "<<this->size<<endl;
            cout<<"Contenido del Array : ";
            for (int i=0;i<this->size;i++){
                cout<<this->array[i]<<" ";
            }
            cout<<endl;
        }
        //---------------- pushBack ------------------
        void pushBack(T value){
            T aux[size];
            for (int i=0;i<this->size;i++){
                aux[i]=array[i];
            }
            delete[] array;
            this->size++;
            array=new T[size];
            for (int i=0;i<this->size;i++){
                if (i!=this->size-1){
                    array[i]=aux[i];
                } else {
                    array[i]=value;
                }
            }
        }
        //--------------- insert ---------------------
        void insert(T value, int pos){
            T aux[size];
            for (int i=0;i<this->size;i++){
                aux[i]=array[i];
            }
            delete[] array;
            this->size++;
            array=new T[size];
            int numAux=0;
            for (int i=0;i<this->size;i++){
                if (i==pos){
                    array[i]=value;
                } else {
                    array[i]=aux[numAux];
                    numAux++;
                }
            }
        }
        //-----------------remove-----------------
        void remove(int pos){
            T aux[size-1];
            int numAux=0;
            for (int i=0;i<this->size;i++){
                if (i!=pos){
                    aux[numAux]=array[i];
                    numAux++;
                }
            }
            delete[] array;
            this->size--;
            array=new T[size];
            for (int i=0;i<this->size;i++){
                array[i]=aux[i];
            }
        }
};

int main(){
    DynamicArray<string> o;
    o.pushBack("bryan");
    o.pushBack("Mario");
    o.getData();
    o.insert("Selena",0);
    o.getData();
    o.remove(1);
    o.getData();
}
