#include <iostream>
#include <stdexcept>
#include "List.h"

template <typename T>
class ListArray : public List<T>{
	private:
		T*  arr;
		int max;
		int n;
		static const int MINSIZE=2;
		void resize(int new_size){
		        T* arr2= new  T[new_size];
       			 for(int i=0;i<new_size;i++){
                		arr2[i]=arr[i];
                		if(n>new_size){
                        		for(i;i<n;i++){
                               			 arr[i]=arr[i+1];}
               			 }}
		}


	public:
		void insert(int pos, T e){
			if(pos<0||pos>n-1)
                	std::out_of_range("Fuera de rango");
        		resize(n+1);
        		for(int i=pos;i<n;i++){
                		arr[i+1]=arr[i];}
        		arr[pos]=e;
		}

		ListArray():max(MINSIZE),n(0){
			arr=new T[MINSIZE];
			n=0;
		}
		~ListArray(){//libera memoria dinámicca reservada
       			delete[] arr;
		}

		T operator[](int pos){
			return arr[pos];
		}
		friend std::ostream& operator<<(std::ostream& out, const ListArray<T>& list){
			out<<"[";
        		for(int i=0;i<list.max;i++){
                		out<<list[i]<<" ";
			}
        		out<<"]";
        		return out;

		}

		T remove(int pos) override{
        		if(pos<0||pos>n-1)
               			 std::out_of_range("Fuera de rango");
        		T aux =arr[pos];
        		for(int i=pos;i<=n;i++){
               			arr[i]=arr[i+1];}
        		return aux;
		}
		T get(int pos) override{
		        if(pos<0||pos>n-1)
               			 std::out_of_range("Fuera de rango");
       			 return arr[pos];
		}
		int search(T e) override{
		        for(int i=0;i<n;i++){
               			if(arr[i]==e){
                        		return i;}
                		else{
                        		return -1;}
			}
		}
		bool empty(){
		        for(int i=0; i<n;i++){
               			 if(arr[i]!=NULL){
                       			 return false;
               		 	}else{
                        		return true;
                		}
        		}
		}
		int size() override{
        		int i=0;
        		while(arr[i]!=NULL){
                		i++;}
        		return i;
		}

};
