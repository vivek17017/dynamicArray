#include<iostream>
using namespace std;
class array
{
    private:
        int capacity;
        int last_index;
        int *arr;
    public:
        array(int size){
            arr=new int[size];
            last_index=-1;
            capacity=size-1;
        }
        bool check_underflow(){
            if(last_index<capacity)
                return true;
            else
                return false;
        }
        void append_element(int element)
        {
            if(check_underflow())
            {
                arr[last_index+1]=element;
                last_index++;
            }
            else
            cout<<"arry is full";
        }
        void insert_element(int element,int index)
        {
            if(check_underflow())
            {

                if(index<=last_index+1)
                {
                    if(index=last_index+1)
                    {
                        arr[index]=element;
                    }
                    else{
                    for(int i=last_index+1;i>index;i--)
                    {
                        arr[i]=arr[i-1];
                    }
                    arr[index]=element;
                }

                }
                else
                    cout<<"index is not valid";
            }
            else
            cout<<"array is full";
        }
        void edit_element(int element,int index)
        {
            if(index<=last_index)
            arr[index]=element;
            else
            cout<<"index is not valid";
        }
        void delete_element(int index){
            if(index<last_index)
            {
                for(int i=index;i<=last_index;i++){
                    arr[i]=arr[i+1];
                }
            
            last_index=last_index-1;
            }
            else
            cout<<"index is not valid";
        }
        bool overflow(){
            if(last_index==capacity)
            return true;
            else
            return false;
        }
        int get_element(int index){
            if(index<=last_index)
            return arr[index];
            else
            cout<<"index is not valid";

        }
        void count_element(){
            cout<<"number of element is "<<(last_index+1);
        }
        ~array(){
            free(arr);
        }
        int find_element(int element){
            for(int i=0;i<last_index;i++){
                if(arr[i]==element)
                return 1;
            }
            return -1;
        }


};
int main(){
    array a(4);
    a.append_element(1);
    a.count_element();
    cout<<endl;
    cout<<a.check_underflow();
    a.insert_element(3,9);

}