#include<iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct node
{
   int info;
   node *next;
};

class Slinkedlist{

    private:
    node *listdata;      //=node*  listdata   =node * listdata

    public:
    Slinkedlist()
    {
        listdata=NULL;
    }

    void insert(int num)
    { 
        node* temp=listdata;
        node* prev=NULL;           //node* prev فقط مش احسن حاجة
        while(temp!=NULL)
        {
            if(num<temp->info)
            break;
            prev=temp;
            temp=temp->next;
        }
        node* location = new node;
        location->info=num;
        //الاضافة في الاول
        if(temp==listdata)  // if(prev==NULL) هي نفسها
        {
            location->next=listdata;      //خلي النود الجديدة اللي هي هتبقي الاولي في القطار  تشبك في النود رقم اتنين في القطار
            listdata=location;
        }
        else //الاضافة في النص او في الاخر
        {
            prev->next=location;
            location->next=temp;
        }

    }

    void search(int num,bool & found)
    { 
        found=false;
        node* temp=listdata;
        while(temp != NULL)
        {
            if(num==temp->info)
            {   
                found=true;
                break;
            }
            temp=temp->next;
        }

    }

    void del(int num)
    {
          if (listdata == NULL) return; // القائمة فارغة
       
          node* temp=listdata;
          node* prev;

       while(temp != NULL)
       {
        if(num==temp->info)
        break;
        prev=temp;
        temp=temp->next;
       }
        if (temp == NULL) return; // الرقم غير موجود
      
        if(temp==listdata)
       {
        listdata=listdata->next;
        delete temp;
       }
       else
       {
          prev->next=temp->next;
          delete temp;  
       }

    }

    void makeempty()
    {
        node* temp;
        while(listdata!=NULL)
        {
            temp=listdata;
            listdata=listdata->next;
            delete temp;
        }
    }

    int getlength()
    {
        node* temp=listdata;
        int count=0;
        while(temp!= NULL)
        {
            count++;
            temp=temp->next;
        }
        return count;
    }

    void display()
    {
       node* temp=listdata;
       while(temp!=NULL)
       {
        cout<<temp->info<<endl;
        temp=temp->next;
       }
    }

    bool isfull()
    {
        try
        {
           node* temp=new node;
           delete temp;
           return false;
        }
        catch(bad_alloc exception)
        {
            return true;
        }
    }

    bool isempty()
    {
        return listdata==NULL;
    }

    node* gethead()
    {
        return listdata;
    }

    void splitlist(int num , Slinkedlist &list1 , Slinkedlist &list2)
    {
         node* temp=listdata;
        if(temp==NULL)
       {
        cout<<"List is empty"<<endl;
        return ;
       } 
       while(temp != NULL && temp->info <= num) //in case all list less than num
       {
        list1.insert(temp->info);
        temp=temp->next;
    }
    while(temp != NULL)
      {
        list2.insert(temp->info);
        temp=temp->next;
       }
    }

};


double calculateavg(Slinkedlist &list)
{
   double sum=0,counter=0;

   node* temp=list.gethead();
   if(temp==NULL) return 0;
   
   while(temp != NULL)
   {
    sum+=temp->info;
    counter++;
    temp=temp->next;
   }
   return sum/counter;

}


int getmax(Slinkedlist &list)
{
  node*temp=list.gethead();
  if(temp==NULL)
   {
    cout<<"List is empty"<<endl;
    return 0;
   }  
   int MAX=INT_MIN;
   while(temp != NULL)
   {
    if(temp->info>MAX)
    {MAX=temp->info;}
    temp=temp->next;
   }
   return MAX;

   /* //بما انها قائمة مرتبة اذا اخر عنصر هو اكبر عنصر
    // امشي لحد ما توصل لآخر نود
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // آخر نود هي اللي فيها أكبر قيمة
    return temp->info; */

}

int getmin(Slinkedlist &list)
{
    node*temp=list.gethead();
    if(temp==NULL)
   {
    cout<<"List is empty"<<endl;
    return 0;
   }  

  return temp->info;
   

}






int main()
{
    srand(time(0));

    Slinkedlist mylist;
    
    for(int i=0;i<10;i++)
    {
      mylist.insert(rand()%10000);
    }

    mylist.display();

     cout << "Average: " << calculateavg(mylist) << endl;
}