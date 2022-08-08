#include<iostream>

using namespace std;

    class node
    {
        public:
        int data;
        node* next;
    };

    void printList(node *head)
    {
        while(head != NULL)
        {
            cout<<head -> data<<"->";
            head = head -> next;
        }
        cout<<"NULL";
    }

    void Push_at_head(node **head_ref,int new_data)
    {
        node* new_node = new node();
        new_node -> data = new_data;
        new_node -> next = (*head_ref);
        (*head_ref) = new_node; 
    }

    void Push_at_prev_node(node* prev_node,int new_data)
    {
        if(prev_node == NULL)
        {
            cout<<"Previous node cannot be null";
            return;
        }

        node* new_node = new node();
        new_node -> data = new_data;
        new_node -> next = prev_node -> next;
        prev_node -> next = new_node;
    }

    void append(node** head_ref,int new_data)
    {
        node* new_node = new node();
        node *last = *head_ref;
        new_node -> data = new_data;
        new_node -> next = NULL;

        if(*head_ref == NULL)
        {
            *head_ref = new_node;
            return;
        }

        while(last -> next != NULL)
        {
           last = last -> next;
        }

        last -> next = new_node;
    }

    void delete_node(node** head_ref,int key)
    {
        node* temp = *head_ref;
        node* prev = NULL;

        if(temp != NULL && temp ->data == key)
        {
            *head_ref = temp -> next;
            delete temp;

            return;
        }

        else
        {
            while( temp != NULL && temp ->data != key)
            {
                prev = temp;
                temp = temp -> next;
            }

            if(temp == NULL)
                return;
            
            prev -> next = temp -> next;

            delete temp;
        }
    }

    void sort_acending(node** head_ref)
    {
        node *current = *head_ref, *index = NULL;
        int temp;

        if(head_ref == NULL)
            return;
        
        else
        {
            while(current != NULL)
            {
                index = current -> next;

                while(index != NULL)
                {
                    if(current -> data > index -> data)
                    {
                        temp = current -> data;
                        current -> data = index -> data;
                        index -> data = temp;
                    }
                    index = index -> next;
                }

                current = current -> next;
            }
        }
    }

    void delete_list(node* head_ref)
    {
        node* temp = head_ref;

        while(head_ref != NULL)
        {
            head_ref = temp -> next;
            delete temp;
        }
        head_ref = NULL;
    }


int main()
{
    node *head = NULL;
    append(&head,6);
    append(&head,7);
    Push_at_head(&head,9);
    Push_at_prev_node(head -> next , 4);

    cout<<"list before deletion: ";
    printList(head);
    cout<<endl;

    cout<<"List after deletion: ";
    delete_list(head);
    head = NULL;
    printList(head);
    cout<<endl;

    return 0;
}