#include<iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int MAX_SIZE=100;

class Slist{


    private:
    int arr[MAX_SIZE];
    int len;

    public:

    Slist()
    {
        len=0;
    }

    void insert(int num)
    {
        int i;
        for( i=0;i<len;i++)
        {
            if(num<arr[i])
            break;
        }


        for(int j=len;j>i;j--)
        {
            arr[j]=arr[j-1];
        }

        arr[i]=num;
        len++;


        /*   another solution in one loop
        if(len>=MAX_SIZE)return;

        int i=len-1;
        while( i>=0 && arr[i] > num)
        {
          arr[i+1]=arr[i];
          i--;
        }
        arr[i+1]=num;
        len++;
        */
    }

    void search(int num, bool &found)
    {
        found=false;
       int f=0;
       int l=len-1;
       int m;
       while(f<=l)
       {
        m=(f+l)/2;

        if(num<arr[m])
        l=m-1;
        if(num>arr[m])
        f=m+1;
        if(num==arr[m])
        {
            found=true;
            break;
        }

        }
    }

    void del(int num)
    {    
        // delete by overwriting
        for(int i=0;i<len;i++)
        if(arr[i]==num)
        {
            for(int j=i;j<len-1;j++)  // if j<len WROOOONG because arr[len-1]=arr[len] <-- this is out of bond because the place len in the array is empty(garbage)
         { 
              arr[j]=arr[j+1];
         }
         len--;
                 //السطر الجاي لو عايز تمسح كل العناصر اللي لها نفس القيمة اللي عايز امسحها في الليست مش بس اول عنصر لقيته
        // i--; //Prevents skipping consecutive duplicate elements that we want to delete after shifting....in other words... to check the new element that we just moved to the current index because it might be the same as the number we want to delete and we want to delete all occurrences of that number in the list.
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
        cout<<"List is : "<<endl;
		for(int i=0;i<len;i++)
		cout<<arr[i]<<endl;
    }

};



int main(){

    Slist mylist;
    
    bool flag;

    mylist.insert(5);
    mylist.insert(10);
    mylist.insert(15);
    mylist.insert(20);
    mylist.insert(7);

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
