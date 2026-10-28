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

const int MAX=100;

class queue{

    private:
    //f & r are indexes
    int f,r;  //front is where we delete & rare is where we add.
    // **************** f ia a sacrificed slot so the actually used places in the array = MAX-1 *****************************  
    int arr[MAX];
    
    public:
    queue()
    {   
        f=r=MAX-1; // the f and the r start from the last index in the array
//it's written in this way so when make (inqueue)  r is increased by 1 so it return to (index 0) so 1st element is put into 1st place in the array and when we make (dequeue) f is increased by 1 so it return to (index 0) so the 1st element is deleted from the queue. 
    }

/********** (r+1)%MAX OR (f+1)%MAX is the secret which make the queue CIRCULAR because when r or f reach the last index which 
 is here 99 , then (99+1)%100=0  soooo it return to the 1ST index again.*******************/  
 // THE % is what retirn us to index 0.

    /******************الار بتهرب بتبعد وهي بتملي الاماكن *****************/
    void inqueue(int num)
    {    //f is a forbidden area so r can't acces the place where r is standing
        if((r+1)%MAX==f) //prvent r from moviing to the next index(f) and overwriting the element in that index because the queue is full and we can't add new elements to the queue when it is full.
       {cout<<"the queue is full"<<endl;
        return;
        }
      r=(r+1)%MAX; // to make the r return to the beginning of the array when it reaches the end of the array and this is called circular queue
      arr[r]=num;  // we put the element in the place where r is standing because r is the rear of the queue and it is the place where we add new elements to the queue
    }
    /******************الاف بتطارد الار وهي بتفضي الاماكن ******************/
    





    /********************************************************************************************************** */
    /*   هل هذا معناه أننا نرجع القيمة بعد المحذوفة؟
    لا، الفكرة أن العنصر الموجود في الخانة التي يقف عليها f حالياً هو عنصر "محذوف منطقياً" (Logical Delete). لذلك عندما نريد حذف العنصر "التالي" عليه، يجب أن نحرك f أولاً لتقف عليه ثم نسحبه.
    الخلاصة في كودك: ا
    الخانة التي يقف عليها f دائماً تعتبر "فارغة" (أو تحتوي على عنصر قديم تم حذفه).
***----------------> أول عنصر حقيقي في الطابور موجود دائماً في الخانة (f + 1) % MAX.<----------------------------------------------------
    عشان كدة، إحنا بنحرك f خطوة الأول عشان تروح تقف على "أول عنصر حقيقي"، وبعدين نرجعه.
لو كان الكود مكتوب كدة:
return arr[f];
f = f + 1;
كان زمانه رجّع "فراغ" أو قيمة قديمة، لأن f في البداية كانت واقفة عند 99 (مكان فاضي)
    */
   /******************************************************************************************************************** */
    int dequeue() //when the f move to the next index that means we delete the element in place where f was standing and move f to the next index so it can point to the next element in the queue which will be deleted in the next (dequeue) operation.
    {             // the delete operation here is logical delete not physical delete because we are not actually deleting the element from the array but we are just moving the front to the next index so it can point to the next element in the queue which will be deleted in the next (dequeue) operation 
                  //and the element in the place where f was standing is considered as deleted(but actually it been ignored) because it is no longer part of the queue and it will be overwritten by r when we add new elements to the queue.
        if(f==r) // prevent f from moving to a new index that has no real data (garbage value) trying to delete an element from an empty queue which will cause an error because there is no element in the queue to delete.
        {cout<<"the queue is empty"<<endl;
        return -1; // return -1 to indicate that the queue is empty and there is no element to delete.
        }
/*******we move the front to the next index before returning the element because the front is the place where we delete elements from the queue and when we delete an element we move the front to the next index so it can point to the next element in the queue which will be deleted in the next (dequeue) operation.*******/
        f=(f+1)%MAX; // to make the f return to the beginning of the array when it reaches the end of the array and this is called circular queue
        return arr[f]; 
        // we return the element in the place where f is standing because f is the front of the queue and it is the place where we delete elements from the queue
    }
    /*ليه بنسيب مكان فاضي؟"
قوله: "عشان نفرق بين حالة الـ Full وحالة الـ Empty، لأن في الحالتين الـ Front بيبقى بيساوي الـ Rear (f == r)، rear فبنعتبر إن الطابور مليان لو الـ front قبل الـ بخطوة واحدة بس."*/
   /*************  لو الار لفت لفة كاملة وقربت تخبط في الاف من ضهرها يبقي الطابور اتملي ************/
    bool isfull()
    {   
                               // when the rear is one step behind the front in a circular manner, it means the queue is full
        return ((r+1)%MAX==f); //we sacrifice one place in the array where f stands as a "forbidden zone" to be able to differentiate between the full and empty states of the queue because in both cases the front will be equal to the rear (f == r) so we consider the queue full when the front is one step ahead of the rear in a circular manner, which means that the rear is one step behind the front in a circular manner.    
                              //we say r+1 because in case if r=99 and f=0.
    }
    /************** لو الاف حصلت الار يبقي الطابور فضي **************/
    bool isempty()
    {   //once the front catches up with the rear, it means the queue is empty
        return (f==r); //according to the constructor and the way we initialized f and r, when they are at the same position, it means the queue is empty. 
/************************when we inqueue an element, r will move to the next index and precedes f and when we dequeue an element, f will move to the next index untill it reaches r, so when they are equal again it means that all the elements in the queue have been dequeued and the queue is empty.**/
                       // when the front and rear are at the same position, it means the queue is empty
    }

};

class linkedqueue{
    
    private:
    node* r;
    node*f;

    public:
    linkedqueue()
    {
       f=r=NULL;   
    }
    void inqueue(int num)
    {
         // الار بيقف علي اخر عنصر تم اضافته 
         //الاف بيقف علي العنصر الجهز للمسح وكل اللي قبل الاف هو مهمل يمكن اعادة الكتابة عليه بواسطة الار

       node* location=new node;  // create a new node to hold the new element that we want to add to the queue and this node will be added to the rear of the queue because we add new elements to the rear of the queue.
       location->info=num;  
       location->next=NULL;  // لسه جديد مفيش حد وراه فمش بيشاور علي حاجه النكست بتاعه ب نالل
       if(r==NULL) //لو اول عنصر يدخل في الطابور
       {    //النود دي بتكون الاولي والاخيرة في نفس الوقت
         
            f=r=location; //الاف بقي يشاور علي اول عنصر في الطابور وكده خلاص مش هحتاج الاف في اي اضافات لعناصر جديدة لانهم مش اول عنصر في الطابور  
       }
       else{
        //بنروح لاخر عنصر واقف حاليا وبدل ما النكست بتاعه بنالل مش ماسك حاجه  بخليه يسمك عنوان النود الجديدة
        r->next=location; //اربط الشخص الجديد بظهر الطابور
        //بنقل لقب (الاخير) من الشخص القديم للشخص الجديد اللي لسه ضايفه عشان تفضل الار دايما علي ديل الطابور
        r=location;      //حرك الار وقفها عالشخص الجديد
       }
    }
    int dequeue()
    {
        if(isempty())
        {
            cout<<"Queue is empty"<<endl;
            return -1;
        }

        node*temp=f;  // a pointer temp holding the address of the node we want to delete
        int t=temp->info;  //same as: int t=f->info because the point to the same address.
                          //مهتمتش بالمؤشر النيكست بتاع المؤقتة دي لأني كده كده همسحها
       f=f->next;   //moving the front to the next node so we can delete temp without losing f which is the head of the queue
        if(f==NULL) // الاف وصلت انها بتشاور علي النال يعني الطابور فضي وبالتالي هخلي الار هي كمان بنالل عشان متبقاش بتشاور علي مكان غلط في الميموري اللي هو مكان اخر نود اتمسحت
        r=NULL;  // لو بعد ما حذفنا العنصر اللي في مقدمة الطابور لقينا إن الطابور بقى فاضي يبقي لازم نحدث مؤشر النهاية (r) ونخليه يشاور علي NULL عشان لما نيجي نضيف عنصر جديد في الطابور نعرف إن ده أول عنصر في الطابور ونخلي (f) و (r) يشاوروا عليه.
        delete temp;  // free the memory to prevent memory leak
        return t;

    }

    void display()
    {
        if(isempty())
        {
            cout<<"Queue is empty"<<endl;
            return;
        }
      node* temp=f;
      while (temp !=NULL)
      {
        cout<<temp->info<<" ";
        temp=temp->next;
      }
      
    }

    bool isfull()
 {
       
     try 
    { 
       node* temp=new node; 
       delete temp; 
       return false ; 
    } 
     catch(bad_alloc exception) 
    { 
         return true; 
    } 
 }

    bool isempty()
    {
        //it was enough to say return (f==NULL)........... because if the front is NULL that means there is no element in the queue and the queue is empty but I also check if r is NULL to make sure that both f and r are NULL because in the constructor we initialized both f and r to NULL and when we add the first element to the queue we make both f and r point to that element so if one of them is not NULL then the other one can't be NULL because they both point to the same element in the queue so if one of them is not NULL then it means that there is at least one element in the queue and the queue is not empty.
        return(f==NULL && r==NULL);
    }

    void copy(linkedqueue q1)
    {
        node* temp=q1.f;  //start copying from the f which is the 1st element in the queue.
        while(temp!=NULL)
        {
            inqueue(temp->info);
            temp=temp->next;
        }
    }



void replaceitem(int oldnum , int newnum)
{
     if(isempty())
        {
            cout<<"Queue is empty"<<endl;
            return;
        }

    node* temp=f;
    while (temp != NULL)
    {
        if(temp->info==oldnum)
        {
            temp->info=newnum;
        }
        temp=temp->next;
    }
    
}

};



int main()
{
   linkedqueue q;

   q.inqueue(10);
   q.inqueue(20);
   q.inqueue(30);

   q.display();
   
   cout<<"Dequeue "<<q.dequeue();

   q.display();

   q.dequeue();
   q.dequeue();
   
   q.display();
   q.inqueue(100);
   q.display();


}