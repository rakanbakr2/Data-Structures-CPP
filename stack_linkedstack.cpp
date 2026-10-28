#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>
using namespace std;


const int MAX=100;

class mystack {

    private:
    int arr[MAX]; //The last (index) available for push is 99 because the size is 100.
    int top;   // refers to the empty place which is ready to receive a push.
    
    public:
    mystack() //when making an instance of the mystack the top is always refering to the empty place which is ready to do a push in it
    {
        top=0;
    }
    
    void push(int num)
    {
        arr[top++]=num;
        /*same as
        arr[top]=num;
        top++
        */
    }
    //Logical delete not physical delete
    int pop() //  وظيفتها حاجتين هما استخراج اخر البيانات المدخلة علي الوش عشان المستخدم يقدر يستخدمها والتانية هي انها بتغير الحالة يعني العنصر اللي واقف عليه التوب هو منطقيا اتمسح ومنطقيا لو طبعت المصفوفة فهو مش معايا وبقول منطقيا لأنه فيزيائيا موجود لكنه منطقيا وبرمجيا ممسوح
    {
        return arr[--top]; //The next push will overwrite on the index because in the implementation of push we don't move to next index we write in the current one
        /*same as
        top--;
        return arr[top];
        */
    }
    bool isfull()
    {
        return (top==MAX);  //when top=100 then we are out of the boundary of the array
    }
    bool isempty()
    {
        return (top==0); //the zero-index is ready to receive a push.
    }
    
    //***************IMPORTANT COMMENT*************** */           
    void display()  //the index where top is standing is exclusive from the stack we don't consider it as an element of our stack
    {
        for(int i=0;i<top;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
};



struct node {
    int info;
    node *next;    // NULLكل نود فيها مؤشر من نوع نود عشان يشاور علي نود تانيه او يشاور علي 
};
class linkedstack{
    
    private:
    // الاتنين مؤشر من نوع نود nextمن نفس نوع top 
    node* top;  //Points to NULL if the stack is empty ,otherwise points to the first node(top-most node which is last pushed element)
    //in other words Head pointer that maintains the address of the current stack top
    //الخيط اللي ماسك السلسلة كلها ولو اتقطع (يعني اتغير مكانه بالغلط ) السلسلة كلها هتضيع في الذاكرة
    public:
    linkedstack()
    {
        top=NULL;  //Initially the stack is empty so the top points to nothing (NULL)
    }
    void push(int num)
    {               //the last node (in the bottom node) of the stack its next pointer = Null.
        node *location =new node; //Dynamically allocate a new node in the heap ,storing its address in pointer 'location'
                                // to access the node members( info, next ) via pointer 'location' derefrencing(->). 
        location->info=num;
        location->next=top;
        top=location; //strictly make them equal because both of them are a pointer to node.                           
    }
    int pop()     //retrieve the top element's value ,update the top pointer ,and free the memory to prevent leak
    {
       if (isempty()) return -1; // مجرد حماية ضد الـ  Empty stack

        node* temp=  top;  // a pointer temp holding the address of the node we want to delete 
        int t=temp->info;  //same as: int t=top->info because the point to the same address.
        top=top->next;   //moving the top to the below node so we can delete temp without losing top which is the head of the stack
        delete temp;   //Physically deleting the node from the memory and free up the heap to prevent memory leak.
        return t;
    }

    void display()
    {
        if(isempty())
        {
            cout<<"Stack is empty"<<endl;
            return;
        }
        node* temp=top; // we can use temp to walk on the whole stack without losing the top pointer because we will change temp but we won't change top because we will use temp to walk on the whole stack and we will change it until it becomes NULL but the top will remain unchanged and pointing to the top of the stack.
        while(temp!=NULL)
        {
            cout<<temp->info<<" ";
            temp=temp->next;
        }
        cout<<endl;
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
       return (top==NULL); 
        // (top->next==NULL); //this means the satck has 1 element once a (next) pointer appeared that means there is an element in our stack
        //  top->next!= NULL means there are ( 2 or more elements) in our stack.
    }

         /***** s1 is the original stack that we want to copy ********/
    void copy(linkedstack s1) //we can pass the stack by reference but we will pass it by value to make sure that we don't change the original stack because if we pass it by reference and we use pop() to reverse it we will change the original stack and we don't want that because we want to make a copy of the original stack without changing it.
    {         //we can pass s1 by refrence because we aren't going to change it and we won't use pop on it...... we just use temp to walk on thw whole stack.
        
    
    // خطوة زياده عن تطبيق الدكتور
    // 1. تنظيف الستاك الحالي أولاً
    while(!this->isempty())
     {
        this->pop();
     }

        node*temp=s1.top;  // وبالتالي نحافظ علي الستاك الاصلية زي ما هي بدون ما نلمسا pop() عشان نعكسها بدون ما نستخدم  s1 مؤشر خارجي بيشاور علي اول 
        linkedstack s3;    //temporary stack used as an intermediate buffer to handle the LIFO reversal.
                           //ده ستاك وسيط  فاضي بنشيل فيه الارقام مؤقتا  
        // first pass: reverse s1 into s3.
        while(temp!=NULL) //copying to s3 will reverse our original stack(s1) that we want to copy
        {
            s3.push(temp->info); // s3 خد نسخة من الرقم وارميها    
            temp=temp->next;    // s1حرك السهم للنود اللي بعدها في الستاك الاصلي      
        }
      
        //second pass: reverse s3 back into "this" stack.so this stack be a copy of s1. 
        
        /**********************************VERY IMPORTANT COMMENT***********************************************/
/********************Here I can't say  while(s3.top != NULL)  because the top is PRIVATE access *********************************/
        while(!s3.isempty()) //طول ما s3 مش فاضية
        {  
              // by popping from the inverted s3 we restore the original order in our new stack.
            push(s3.pop()); //pushing into the current object (this).
 /*same as: this->push(s3.pop()) */  // since push is written without s1. or s3. that means we are in (this) means we work in our stack which i am building now 
                           // we push into the bottom of (this) stack( the top element in s3 by (s3.pop) ) then we push the one below it and by this way we get a copy of s1
        }
    

}

node* gethead()
{
    return top;
}

};


double calculateavg(linkedstack &s)
{
   node* temp=s.gethead();
   if(temp==NULL)return 0;
   double sum=0,counter=0;
   while(temp != NULL)
   {
    sum+=temp->info;
    counter++;
    temp=temp->next;
   }
   return sum/counter;
}

int getmax(linkedstack &s)
{
   node* temp=s.gethead();
   if(temp==NULL)return -1;
   
   int MAX=INT_MIN;
   while(temp != NULL)
   {
    if(temp->info>MAX)
    MAX=temp->info;

    temp=temp->next;
   }
   return MAX;
}







int main()
{
 
 linkedstack s1;

    cout << "--- Test 1: Initial State ---" << endl;
    cout << "Is empty? " << (s1.isempty() ? "Yes" : "No") << endl;

    cout << "\n--- Test 2: Pushing Elements (10, 20, 30) ---" << endl;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.display();

    cout << "\n--- Test 3: Checking isFull and isEmpty ---" << endl;
    cout << "Is full? " << (s1.isfull() ? "Yes" : "No") << endl;
    cout << "Is empty? " << (s1.isempty() ? "Yes" : "No") << endl;

    cout << "\n--- Test 4: Copying s1 into s2 ---" << endl;
    linkedstack s2;
    s2.copy(s1);
    cout << "Original s1: "; s1.display();
    cout << "Copied   s2: "; s2.display();

    cout << "\n--- Test 5: Popping from s1 ---" << endl;
    cout << "Popped from s1: " << s1.pop() << endl; // يجب أن يخرج 30
    cout << "Popped from s1: " << s1.pop() << endl; // يجب أن يخرج 20
    cout << "s1 after 2 pops: "; s1.display();
    cout << "Check s2 (should remain unchanged): "; s2.display();

    cout << "\n--- Test 6: Popping until empty and Underflow check ---" << endl;
    s1.pop(); // يمسح الـ 10
    cout << "Attempting to pop from empty s1..." << endl;
    s1.pop(); // سيظهر رسالة الخطأ التي وضعناها

    cout << "\n--- Test 7: Final check on s2 ---" << endl;
    s2.display();

    srand(time(0));
    linkedstack s3;
    for(int i=0;i<10;i++)
    {
        s3.push(rand()%10000);
    }
    cout << "Random stack s3: "; s3.display();


}