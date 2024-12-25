#include <iostream>
using namespace std;
class Q_node
{
    friend class  Queue ;
    int data;
    Q_node *next;
};
class Queue
{
    Q_node* front;
    Q_node* rear;
    public:
    Queue();
    ~Queue();
    void EnQueue(int x);
    int DeQueue();
    int Retrieve();
    bool IsEmpty();
};
Queue::Queue()
{
    front=nullptr;
    rear=nullptr;
}
Queue::~Queue()
{
    Q_node* temp;
    while(front!=nullptr)
    {
        temp=front;
        delete temp;
        front=front->next;
    }
}
bool Queue::IsEmpty()
{
    if(front==nullptr) return true;
    else return false;
}
void Queue::EnQueue(int x)
{
    Q_node * qnew= new Q_node;
    qnew->data=x;
    if(IsEmpty())
    {
        front=rear=qnew;        // if queue is empty front and rear point to a same node.
    }
    else
    {
        rear->next=qnew;
        rear=qnew;
        rear->next=nullptr;
    }
}
int Queue::DeQueue()
{
    
    if (IsEmpty())
    {
        cout<<"Queue Underflow! \n";
        return -1;
    }
    else
    {
        Q_node* temp;
        int t;
        temp=front;
        t=temp->data;
        front=front->next;
        if(front==nullptr)    // if front became nullptr, rear also nullptr.
        {
            rear=nullptr;
        }
        delete temp;
        return t;
    }
}
int Queue::Retrieve()
{
    if (IsEmpty())
    {
        cout<<"Queue Underflow! \n";
        return -1;
    }
    else
    {
        return front->data;
    }
}
int main()
{
    Queue que;
    int c,x;
    bool con=true;
    char m;
    cout<<"+++++Guide+++++\n";
    cout<<"1 for Enqueue\n";
    cout<<"2 for Dequeue\n";
    cout<<"3 for Retrieve\n";
    cout<<"4 This queue is empty?\n";
    while (con)
    {
        cout<<"Please enter your choice: ";
        cin>>c;
        switch (c)
        {
        case 1:
            cout<<"Enter your number: ";
            cin>>x;
            que.EnQueue(x);
            cout<<"Enqueue done.\n";
            break;
        case 2:
            cout<<"The front member "<<que.DeQueue()<<" has been removed from the queue.\n";
            break;
        case 3:
            cout<<"The front member is "<<que.Retrieve()<<endl;
            break;
        case 4:
            if (que.IsEmpty()) cout<<"This queue is empty.\n";
            else cout<<"This queue is not empty.\n";
            break;
        default:
            cout<<"Undefined choice, please try again.\n";
            break;
        }
        cout<<"Do you want continue? (y/n) ";
        cin>>m;
        con=(m=='y' || m=='Y');
    }
    
}