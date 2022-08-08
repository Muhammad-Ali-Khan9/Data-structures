#include<iostream>
#include<exception>

using namespace std;

template<class T>
class circular_Singly_linked_list
{
    private:
    struct node{

        T value;
        node* next;
    };

    node* head_ptr;
    size_t size;

    public:

    circular_Singly_linked_list()
    {
        head_ptr = NULL;
        size = 0;
    }

    void push_at_head(T key)
    {
        if(head_ptr == NULL)
        {
            node* new_node = new node();
            new_node -> value = key;
            head_ptr = new_node;
            new_node -> next = head_ptr;
            size++;
            return;
        }
        
            node* new_node = new node();
            new_node -> value = key;
            new_node -> next = head_ptr;
            head_ptr = new_node;
            size++;
        
    }

    void add_node_before_node(T node_key,T key)
    {

        node* new_node = new node();
        new_node -> value = key;

        node* temp = head_ptr;
        node* prev = NULL;

        if(temp -> value == node_key)
        {
            new_node -> next = head_ptr;
            head_ptr = new_node;
        }


        if(this ->if_list_has_circular_link())
        {
            do{
                prev = temp;
                temp = temp -> next;

            }while(temp != head_ptr  && temp -> value != node_key);

            if(temp == head_ptr)
            {
                cerr<<"node not found";
                delete new_node;
                return;
            }

            prev -> next = new_node;
            new_node -> next = temp;
            size++; 
        }

        else
        {
           while(temp != NULL && temp -> value != node_key)
           {
                prev = temp;
                temp = temp -> next;
           }

           if(temp == NULL)
           {
                cerr<<"Node not found";
                delete new_node;
                return;
           }

           prev -> next = new_node;
           new_node -> next = temp;
           size++;        
        }

    }

    void delete_Specific_node(T node_key)
    {
        try{
            if(head_ptr == NULL)
                throw head_ptr;
        }

        catch(node* ptr)
        {
            cerr<<"List empty";
            return;
        }

        node* prev = NULL;
        node* temp = head_ptr;


        if(this ->if_list_has_circular_link())
        {
            do{
                prev = temp;
                temp = temp -> next;

            }while(temp != head_ptr);

            if(temp == head_ptr)
            {
                cerr<<"Node not found";
                return;
            }

            prev -> next = temp -> next;
            delete temp;
            size--;

        }

        else
        {
            while(temp != NULL && temp -> value != node_key)
            {
                prev = temp;
                temp = temp -> next;
            }    

            if(temp == NULL)
            {
                cerr<<"Node not found";
                return;
            }

            prev -> next = temp -> next;
            delete temp;
            size--;

        }
    }

    void clear_list()
    {
        try{
            if(head_ptr == NULL)
                throw head_ptr;
        }

        catch(node* ptr)
        {
            cerr<<"List empty";
            return;
        }

        if(this -> if_list_has_circular_link())
        {
            node* temp = head_ptr , *prev = NULL;

            do{
                prev = head_ptr;
                temp = temp -> next;
                delete prev;

            }while(temp != head_ptr);

            size = 0;
        }

        else
        {
            node* temp = head_ptr , *prev = NULL;

            while(temp != NULL)
            {
                prev = temp;
                temp = temp -> next;
                delete prev;
            }

            size = 0;
        }

    }

    void push_at_tail(T key)
    {
        if(head_ptr == NULL)
        {
            node* new_node = new node();
            new_node -> value = key;
            head_ptr = new_node;
            new_node -> next = head_ptr;
            size++;
            return;
        }

        node* new_node = new node();
        new_node -> value = key;

        node* temp = head_ptr;

        do
        {
            temp = temp -> next;

        }while (temp -> next != head_ptr);
        
        temp -> next = new_node;
        new_node -> next = head_ptr;
        size++;

    }

    void pop_front()
    {
        try{

            if(head_ptr == NULL)
                throw head_ptr;
        }

        catch(node* ptr)
        {
            cerr<<"List empty";
            return;
        }

        node* temp1 = head_ptr, *temp2 = head_ptr;

        do{
            temp2 = temp2 -> next;

        }while(temp2 -> next != head_ptr);
        
        head_ptr = head_ptr -> next;
        delete temp1;
        temp2 -> next = head_ptr;
        size--; 

    }

    void pop_back()
    {
        try{

            if(head_ptr == NULL)
                throw head_ptr;
        }

        catch(node* ptr)
        {
            cerr<<"List empty";
            return;
        }

        node* prev = NULL;
        node* temp = head_ptr;

        if(temp -> next == head_ptr)
        {
            delete temp;
            head_ptr = NULL;
            size--;
            return;
        }

        do{
            prev = temp;
            temp = temp -> next;

        }while(temp -> next != head_ptr);

        delete temp;
        prev -> next = head_ptr;
        size--;

    }

    size_t get_size()
    {
        return size;
    }

    void break_circular_link()
    {   
        try{

            if(head_ptr == NULL)
                throw head_ptr;
        }

        catch(node* ptr)
        {
            cerr<<"List empty";
            return;
        }

        node* temp = head_ptr;

        do{
            temp = temp -> next;

            if(temp -> next == NULL)
            {
                cerr<<"List already has no loop";
                return;
            }

        }while(temp -> next != head_ptr);

        temp -> next = NULL;

    }

    void remake_circular_link()
    {
        try{

            if(head_ptr == NULL)
                throw head_ptr;
        }

        catch(node* ptr)
        {
            cerr<<"List empty";
            return;
        }

        node* temp = head_ptr;

        do{
            temp = temp -> next;

            if(temp -> next == head_ptr)
            {
                cerr<<"List already has a circular link";
                return;
            }

        }while(temp -> next != NULL);

        temp -> next = head_ptr;

    }

    bool if_list_has_circular_link()
    {
        try{

            if(head_ptr == NULL)
                throw head_ptr;
        }

        catch(node* ptr)
        {
            return false;
        }

        node* temp = head_ptr;

        do{
            temp = temp -> next;

            if(temp -> next == NULL)
                return false;

        }while(temp -> next != head_ptr);

        return true;

    }    

    void print_list()
    {
        try{

            if(head_ptr == NULL)
                throw head_ptr;
        }

        catch(node* ptr)
        {
            cerr<<"List empty";
            return;
        }

        node* temp = head_ptr;

        do{
            cout<<temp -> value<<"->";
            temp = temp -> next;

        }while(temp != head_ptr);

        cout<<"head pointer";
    }

    ~circular_Singly_linked_list()
    {
        if(this ->if_list_has_circular_link())
        {
            node* prev = NULL;

            do{
                prev = head_ptr;
                head_ptr = head_ptr -> next;
                delete prev;

            }while(head_ptr -> next != head_ptr);

        }
        else
        {
            node* prev = NULL;

            while(head_ptr != NULL)
            {
                prev = head_ptr;
                head_ptr = head_ptr -> next;
                delete prev;
            }
            
        }

    }

};

int main()
{
    circular_Singly_linked_list<int> list1;
    list1.push_at_head(1);
    list1.push_at_tail(2);
    list1.push_at_tail(3);
    list1.push_at_tail(4);

    cout<<endl;

    list1.add_node_before_node(3,5);
    list1.print_list();

    return 0;
}