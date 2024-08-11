#include <iostream>

using namespace std;

class Queue{

private:
    int front;
    int rear;
    int arr[5];
    int itemCount;

public:
    Queue(){
        front=-1;
        rear=-1;
        itemCount=0;

        for(int i=0;i<5;i++){
            arr[i]=0;
        }
    }

    bool isEmpty(){
        if(front==-1 && rear==-1){
            return true;
        }else{
            return false;
        }
    }

    bool isFull(){
        if((rear+1)){
             return true;
        }else{
            return false;
        }
    }

    void enqueue(int val){
        if(isFull()){
            cout << "Queue is Full" << endl;
            return;
        }else if (isEmpty()){
            rear = 0;
            front = 0;
            arr[rear]=val;
        }else{
            rear++;
            arr[rear]=val;
        }
    }

    int dequeue(){
        int x=0;

        if(isEmpty()){
            cout << "Queue is Empty" << endl;
            return x;
        }else if(rear==front){
            x=arr[rear];
            rear=-1;
            front=-1;
            return x;
        }else{
            x=arr[front];
            arr[front]=0;
            front=(front+1)%5;

            itemCount--;
            return x;
        }
    }

    int count(){
        return (itemCount);
    }

    void display(){
        cout << "All values in the Queue are" << endl;

        for(int i=0;i<5;i++){
            cout << arr[i] << " ";
        }
    }

};

int main()
{
    Queue q1;
    int value, option;

    do{
        cout << "\n What operation do you want to perform? Select option number. enter 0 to exit." << endl;
        cout << "1. Enqueue()" << endl;
        cout << "2. Dequeue()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. Count()" << endl;
        cout << "6. Display()" << endl;
        cout << "7. Clear Screen \n\n" << endl;

        cin >> option;

        switch (option){
            case 0:
                break;
            case 1:
                cout << "Enqueue Operation \n Enter an item to enqueue to the queue" << endl;
                cin >> value;
                q1.enqueue(value);
                break;
            case 2:
                cout << "Dequeue Operation \n Dequeue value: " << q1.dequeue() << endl;
                break;
            case 3:
                if(q1.isEmpty()){
                    cout << "Queue is empty";
                }else{
                    cout << "Queue is not empty";
                }
                break;
            case 4:
                if(q1.isFull()){
                    cout << "Queue is full";
                }else{
                    cout << "Queue is not full";
                }
                break;
            case 5:
                cout << "Count Operation \n Count of items in the Queue" << q1.count();
                break;
            case 6:
                cout << "Display Operation" << endl;
                q1.display();
                break;
            case 7:
                system("cls");
                break;
            default:
                cout << "Enter Proper Option Number" << endl;
        }
    }while(option!=0);

    return 0;
}
