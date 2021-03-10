#include<bits/stdc++.h>
using namespace std;

// making the class of the stack
class Stack {
    queue<int> first_queue;
    queue<int> second_queue;

    int curr_size;

public:
    Stack(){
        curr_size = 0;
    }

    int size(){
        return curr_size;
    }

    void push(int data){
        curr_size++;

        second_queue.push(data);

        while(!first_queue.empty()){
            second_queue.push(first_queue.front());
            first_queue.pop();
        }

        queue<int> temp = first_queue;
        first_queue = second_queue;
        second_queue = temp;
    }

    int pop(){
        if(first_queue.empty())
            return -1;
        first_queue.pop();
        curr_size--;
    }

    int top(){
        if(first_queue.empty()){
            return -1;
        }
        return first_queue.front();
    }
};
int main(){
    Stack st;
    printf("The Stack is made using two queues\n");
    int choice, t, s;
    while(1){
        printf("press 1 for push\npress 2 for pop\npress 3 for top\npress 4 for the current size of this stack\npress 0 to exit");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            int data;
            printf("Enter a number to push in the stack\n");
            scanf("%d", &data);
            st.push(data);
            break;
        case 2:
            st.pop();
            break;
        case 3:
            t = st.top();
            printf("%d is the top element of the stack\n", t);
            break;
        case 4:
            s = st.size();
            printf("%d is the current size of the stack\n", s);
            break;
        case 0:
            break;
        default:
            printf("invaild choice\n");
        }
    }
}
