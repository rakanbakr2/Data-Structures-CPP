#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <new>
using namespace std;

struct node {
    int info;
    node *next;
};

class Ulinkedlist{

    private:
    node *listdata;    //not a node it's just apointer to the head node

    public:
    Ulinkedlist()
    {
      listdata=NULL;
    }

    void insert(int num)
    {
       node* location=new node;
       location->info=num;
       location->next=listdata;   //  بخلي كل نود جديدة بعملها تشاور علي راس القطار  راس القطار اللي هي بعد النود الجديدة هتبقي تاني عربية بعد الراس اللي هي اول عربيه
       listdata=location;         //بخلي الليست داتا تشاور علي راس القطار اللي هي اول عربيه
    }

    void search(int num,bool &found)
    {
        found=false;
        node* temp=listdata;
        while(temp!=NULL)
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
    if(listdata==NULL) //في حالة الليست فاضية
    return;
    node* temp=listdata;
    node* prev;

    while(temp!=NULL)
    {
        if(num==temp->info)
        break;

        prev=temp;
        temp=temp->next;
    }
    if(temp==listdata)
    {
        listdata=listdata->next;
        delete temp;
    }
    else
    {
      if(temp!=NULL)    //لأن معني ان المؤقت يساوي  نال هو انك لفيت عالليست كلها وملقيتش الرقم اللي المفروض تمسحه
      {
        prev->next=temp->next;
        delete temp;
      }
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
    
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

void display()
{
    node* temp=listdata;
    if(temp==NULL)return;
    while(temp!=NULL)
    {
        cout<<temp->info<<" ";
        temp=temp->next;
    }
}

bool isfull()
{
    
    try
    {
        node* temp = new node;
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


 // السطر ده هو "التصريح" إن الدالة دي صديقة وليها صلاحيات خاصة
friend double calculateavg(Ulinkedlist &list);
/* 
friend: دي "كلمة محجوزة" في لغة C++. وظيفتها إنها بتقول للكلاس: "يا كلاس، الدالة اللي جاية دي مش من عيلتك (يعني مش Member)، بس هي صديقة وفية، اسمحلها تدخل تشوف الحاجات الـ private بتاعتك".
double: ده نوع القيمة اللي الدالة هترجعها (المتوسط الحسابي)، واختارنا double عشان المتوسط غالباً بيكون فيه كسر (مثلاً 5.5).
(Ulinkedlist &list): ده "الباراميتر". بما إن الدالة دي "خارجية"، فهي متعرفش هي هتحسب متوسط لمين، فلازم نبعت لها الكائن (Object) اللي هو mylist عشان تفتحه وتشوف اللي جواه. وعلامة & (Reference) بنحطها عشان نبعت الكائن الأصلي بدل ما نعمل نسخة تانية منه في الميموري (توفيراً للوقت والمساحة).
*/
};




double calculateavg(Ulinkedlist &list)
{
    long long sum=0,counter=0;

        //node* temp = list.gethead(); // الوصول لرأس القائمة عبر الدالة العامة
        // لاحظ إننا هنا مقدرناش نكتب list.listdata إلا بسبب كلمة friend اللي فوق
        node*temp=list.listdata; // هنا بنوصل للـ private مباشرة
        if(temp == NULL) return 0;
   while(temp != NULL)
   {
       sum+=temp->info;
       counter++;
     temp=temp->next;
   }
   return (double)sum/counter;

}

int getmax(Ulinkedlist &list)
{
    node* temp=list.gethead();
     // 1. التأكد أن القائمة ليست فارغة
    if (temp == NULL) {
        cout << "List is empty!" << endl;
        return -1; // أو أي قيمة تدل على الخطأ
    }
    int MAX=temp->info; // Initialize MAX with the value of the first node
    temp=temp->next; // Start from the second node
      while(temp != NULL)
   {
      if(temp->info>MAX) 
     {
         MAX=temp->info;  
     }
     temp=temp->next;
     
   }
   
   return MAX;
}


int getmin(Ulinkedlist &list)
{
    node*temp=list.gethead();
    if(temp==NULL)
    {
         cout << "List is empty!" << endl;
        return -1; // أو أي قيمة تدل على الخطأ
    }
    int MIN=INT_MAX;
       while(temp != NULL)
   {
      if(temp->info<MIN) 
     {
         MIN=temp->info;  
     }
     temp=temp->next;
     
   }
   return MIN;

}


int main()
{
    srand(time(0));

    Ulinkedlist mylist;
    
    for(int i=0;i<10;i++)
    {
        int randomnum=rand()%10000;
        mylist.insert(randomnum);
    }

   mylist.display();

     cout << "Average: " << calculateavg(mylist) << endl;






}