#include <ostream>
#include "List.h"
#include "Node.h"


template <typename T>
class ListLinked : public List<T>{
	private:
		Node<T>* first;
		int n;

	public:
		virtual void insert(int pos, T e){
		       	if(pos<0||pos>(n-1)){
				std::out_of_range("Error de rango");}
			Node<T>* aux=first;//next?
 			if(pos==0){
                		first= new Node<T>(e,first);}
			for(int i=0;i<pos;i++){
                        	aux=aux->next;}
                	aux->next=new Node<T>(e,aux->next);
		}

		ListLinked(){
			first=nullptr;
			n=1;}
		~ListLinked(){
			while(n!=0){
				Node<T>* aux=first->next;
				delete first;
				first=aux;
				n--;}
		}

		T operator[](int pos){
			if(pos<0||pos>n){
				std::out_of_range("Error de rango");}
			Node<T>* aux=first;
			for(int i=0;i<pos;i++){
				aux=aux->next;}
			return aux;
		}
		friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
			Node<T>* aux=list.first;
			for(int i=0;aux->next!=nullptr;i++){
				std:out << aux->data <<"\n";
				aux=aux->next;}
			return out;}
		T remove(int pos){
			Node<T>* aux=first;//next??
        		for(int i=0; i<pos;i++){
                		aux=aux->next;}//next?
        			//aux->first=nullptr;
        		n--;
			delete[] aux;
		}
	
		T get(int pos){
       			Node<T>* aux=first;//next?
       			for(int i=0;i<pos;i++){
               			aux=aux->next;}//next?
       			return aux;
		}

		int search(T e){
		        Node<T>* aux=first;
        		for(int i=0;aux->next!=nullptr;i++){
                		if(aux.data==e.data){return i;}
                		aux=aux->next;}
        		return -1;
		}

		bool empty(){
        		if(n==0){
                		return 1;}
        		else{ return 0;}

		}

		int size(){//esto no es n?
        		Node<T>* aux=first;
			int i=0;
       			 for(i=0; aux->next!=nullptr;i++){
                		aux=aux->next;}
       			 return i;

		}

};
