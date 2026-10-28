#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const int MAX_SIZE=100;

class Ulist{

    private :
              int arr[MAX_SIZE];
              int len;

public:

Ulist(){
   len=0;
}

void insert(int num)
{
    arr[len]=num;
    len++;
}
void search(int num  , bool &found)
{
    found=false;
    for(int i=0;i<len;i++)
     if(num==arr[i])
     found=true;
    
}
void del(int num)
{
    for(int i=0;i<len;i++)
    {
     if(num==arr[i])
     {
        //بما انها كده كده  انسورتد ف انا هاخد اخر عنصر واخليه يتكتب مكان العنصر اللي عايز امسحه وانقص الطول بواحد 
        arr[i]=arr[len-1];
        len--;
     }

    }
}

void makeempty()
{
    len=0;
}

int getlen()
{
   return len;
}

bool isfull()
{
    return len==MAX_SIZE;
}

void display()
{
    cout<<"List is :"<<endl;
    for(int i=0;i<len;i++)
    cout<<arr[i]<<endl;
}


};


int main(){

    Ulist mylist;
    
    bool flag;

    mylist.insert(5);
    mylist.insert(10);
    mylist.insert(15);
    mylist.insert(20);

    mylist.display();

    mylist.del(20);

    mylist.display();

    mylist.search(15,flag);
    mylist.search(20,flag);

    cout<<"is the list full? "<<(mylist.isfull() ? "Yes" : "No" )<<endl;

    cout<<mylist.getlen()<<endl;
    
    mylist.makeempty();
    mylist.display();

}