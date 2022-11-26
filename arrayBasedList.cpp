#include <iostream>

using namespace std;
#define MAX_SIZE 10
class arrayList{
    int *Elements;
    int capacity;
    int n;
    public:
    arrayList(int capacity = MAX_SIZE){
        this->capacity = capacity;
        Elements = new int[capacity];
        n=0;
    }
    void resize(){
        int newcapacity;
        if(capacity>0){
            newcapacity = capacity*2;
        }
        else{
            newcapacity = 1;
        }
        int *Temp = new int[newcapacity];
        for(int i=0; i<n; i++){
            Temp[i] = Elements[i];
        }
        delete[] Elements;
        Elements = Temp;
        capacity = newcapacity;
    }
    void add(int data){
        if(n == capacity){
            resize();
        }
        Elements[n] = data;
        n++;
    }
    int get(int pos){
        if(pos>n || pos < 0){
            throw exception();
        }
        else{
            return Elements[pos];
        }
    }
    void remove(int pos){
        if(pos>n || pos < 0) throw exception();
        n--;
        for(int i = pos; i<n; i++){
            Elements[i] = Elements[i+1];
        }
    }
    int length(){
        return n;
    }
    void clear(){
        delete[] Elements;
    }
    void insert(int data, int pos){
        n++;
        if(n==capacity){
            resize();
        }
        for(int i=n-1;i>=pos; i--){
            Elements[i+1] = Elements[i]; 
        }
        Elements[pos]=data;
    }
    ~arrayList(){//destructor
		delete[] Elements;
	}
    void print(){
        for(int i=0; i<n;i++)
        cout<<Elements[i]<<"  ";
    }
};

int main(){
    arrayList array1;
    array1.add(5);
    array1.add(6);
    array1.add(7);
    array1.add(45);
    array1.add(89);
    array1.insert(15,2);
    array1.print();
    array1.remove(1);
    cout<<endl;
    array1.print();
}