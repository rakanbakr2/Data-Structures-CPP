#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

struct node {
    int info;
    node *next;    // NULLكل نود فيها مؤشر من نوع نود عشان يشاور علي نود تانيه او يشاور علي 
};

class circular {
  
    private:
    node* listdata;
    public:
    circular() //default constructor
    {
     listdata=NULL;  //بنخلي المؤشر مش بيشاور علي حاجة لأن الليست لسه فاضيه
    }
    circular(circular & s)
    {
        listdata=NULL;   //start the new list from NULL
        node* temp=s.listdata->next; //temp is a pointer to node
        do
        {
            insert(temp->info); //  ليستthis   بنضيف القيمة اللي واقف عندها التيمب  في 
            temp=temp->next;
        } while (temp!=s.listdata->next); //بنفضل نلف لحد ما نرجع لنفس نقطة البداية اللي بدأنا من عندها التيمب
        //اول ما يبقي التيمب شايل عنوان اول عنصر تاني كده خلاص خلصنا
        
        /*     //*************using while*****************
         listdata=NULL;  
         node* temp=s.listdata->next; 
                                         //نفذنا العملية يدويا اول مرة فقط عشان اقدر انفذ شرط  الوايل لوب
         insert(temp->info);
         temp=temp->next;

         while(temp != listdata->next)
         {
            insert(temp->info);
            temp=temp->next;
         }
        */
    }

    void copytome(circular & s)
    {
        node* temp=s.listdata->next;

        do
        {
          insert(temp->info);
          temp=temp->next;
        } while (temp != s.listdata->next);
        
    }

    void copytopara(circular & s)
    {
        node* temp=listdata->next;

        do
        {
            s.insert(temp->info);
            temp=temp->next;
        } while (temp != listdata->next);
    }
     
    void insert(int num)
    {
        node* location=new node;
        location->info=num;
        if(listdata==NULL)  //if it's empty
        {
            listdata=location;
            location->next=location;
        }
        else{
            node* temp=listdata->next; //temp is intialized to be equal to the 1st element in the list
            node* pre=listdata;
//if we insert an element greater than all elements the do-while loop will be excuted but..in this case... it will be useless 
        do
        {
            if(num<temp->info)
            break;

            pre=temp;         //much better than pre=pre->next
            temp=temp->next;
            
        } while (temp != listdata->next);
//if we insert an element greater than all elements the next two lines are responsible for both ( insert)and ( make the insertion at the end of the list )
        pre->next=location;
        location->next=temp;

        if(num>listdata->info) //if its the greatest so it's the new listdata
        listdata=location;
        
       }

    }

    void display()
    {
        if(listdata != NULL)
     {
        node* temp=listdata->next;
        do
        {
            cout<<temp->info<<" ";
            temp=temp->next;

        } while ( temp != listdata->next);
     }
        else
        cout<<"The list is empty"<<endl;
        
    }

    void search(int num, bool & found)
    {
       found=false;
       if(listdata != NULL)
     {
         node* temp=listdata->next;

       do
       {
        if(num==temp->info)
        {
            found=true;
            break;
        }
        temp=temp->next;
       } while (temp != listdata->next);
     }
    }

    void del(int num)
    {
        if(listdata != NULL)
   {
      node* temp=listdata->next; 
      node* pre=listdata;
      bool found=false;

      do
      {
        if(num==temp->info)
        {
            found =true;
            break;
        }
        pre=temp;
        temp=temp->next;
      } while (temp != listdata->next);
      
      if(found)
      {
        //حالة كان عنصر واحد فقط
        if(listdata->next==listdata) //same as  if(pre==temp)
        { 
            delete temp;
          listdata=NULL;
        }

        else{
            pre->next=temp->next;
            if(listdata==temp)    //في الحالة دي السطر اللي قبلها هيوصل ال بريفيوس ب نالل عادي
            {
                listdata=pre;
            }
            delete temp;
           }
       }
       else{
        cout<<"Element not found"<<endl;
       }
     }
    }

    int getlen()
    {
        int count=0;
        if(listdata !=NULL)
        {
        node*temp=listdata->next;
        do
        {
            count++;
            temp=temp->next;

        } while (temp != listdata->next);
       } 
    return count;
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

    void makeempty()
{
    if(listdata != NULL)
    {
        node* temp = listdata->next;
        listdata->next = NULL;
        while(temp != NULL)
        {
            node* pre = temp;
            temp = temp->next;
            delete pre;
        }
        listdata = NULL;
    }
}



};


struct nodetype
{
    int info;
    nodetype* next;
    nodetype* back;
};


class doubly{

    private:
    nodetype* listdata;

    public:
    doubly()
    {
        listdata=NULL;
    }

    void insert(int num)
    {
        nodetype* location=new nodetype;
        location->info=num;
        if(listdata==NULL)
        {
            listdata=location;
            location->next=location->back=NULL;
        }
        else{
            nodetype*temp=listdata;
            nodetype*pre=NULL;
            while (temp != NULL)
            {
                if(num<temp->info)
                { break;}
                pre=temp;
                temp=temp->next;
            }

            if(pre==NULL)
            {
                location->back=NULL;
                location->next=temp;
            //  pre->next=location;  Wrong Because the pre is NULL so it doesn't have naext
                if(temp != NULL)
                temp->back=location;
                
                listdata=location;
            }
            else{
                pre->next=location;
                 location->back=pre;
                location->next=temp;
                if(temp != NULL) //if we don't insert at the end then there is an element after location 
                temp->back=location;
            }
        }

    }

    void display()
    {
        nodetype *temp=listdata;
        while (temp !=NULL)
        {
            cout<<temp->info<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void search(int num , bool & found)
    {
        found=false;
       nodetype *temp=listdata;
       while (temp != NULL)
       {
        if(temp->info==num)
         {
            found=true;
            break;
         }
         temp=temp->next;
       }
       
    }

    void del(int num)
    {
        nodetype* temp=listdata;
        nodetype* pre=NULL;

        while(temp!=NULL)
        {
            if(temp->info==num)
            break;

            pre=temp;
            temp=temp->next;
        }
        if(temp==NULL) //في حالة الرقم مش موجود اخرج
        return;

        if(temp==listdata)
        {
            listdata=listdata->next;
           // pre->next=temp->next; Wrong Because the pre is NULL
            if(temp->next != NULL) //امان في حالة ان التيمب بقي واقف علي نالل يعني عندي عنصر واحد بس في الليست   
           listdata->back=NULL; // same as listdata->back=pre;
            delete temp;
        }
        else{
             pre->next=temp->next;
             if(temp->next != NULL)  //امان في حالة اني بمسح اخر عنصر
             temp->next->back=pre;
             delete temp;
        }

    }


    bool isfull()
    {
        try
        {
            nodetype* temp=new nodetype;
            delete temp;
            return false;
        }
        catch(bad_alloc exception)
        {
            return true;
        }
    }

    int getlen()
    {
        nodetype* temp=listdata;
        int count=0;
        while(temp != NULL)
        {
            count++;
            temp=temp->next;
        }
        return count;
    }
    bool isempty()
    {
        return(listdata==NULL);
    }
    void makeempty()
    {
        nodetype* temp=listdata;
        while(temp != NULL)
        {
            nodetype* pre=temp;
            temp=temp->next;
            delete pre;
        }
        listdata=NULL;
    }


};










int main(){

    doubly list;
    list.insert(5);
}