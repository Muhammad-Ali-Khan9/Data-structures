#include<iostream>
#include<exception>

using namespace std;

template< class T >
class stack
{
    private:

    struct node
    {
        T value;
        node* next;
    };

    int size;
    node* head_ptr;

    public:

    stack()
    {
        size = 0;
        head_ptr = NULL;
    }

    void push(T key)
    {
        if(head_ptr == NULL)
        {
            node* new_node = new node();
            new_node -> value = key;
            new_node -> next = NULL;
            head_ptr = new_node;
            size++;
        }

        else
        {
            node* new_node = new node();
            new_node -> value = key;
            new_node -> next = head_ptr;
            head_ptr = new_node;
            size++;
        }

    }

    void pop()
    {
        try
        {
            if(head_ptr == NULL)
                throw head_ptr;
        }

            catch(node* ptr)
            {
                cerr<<"Empty stack";
                return;
            }
        
        node* temp = head_ptr;
        head_ptr = head_ptr -> next;
        size--;
        delete temp; 
    }

    T& top()
    {
        try
        {
            if(head_ptr == NULL)
                throw head_ptr;
        }

            catch(node* ptr)
            {
                cerr<<"Stack Empty";
                exit(EXIT_FAILURE);
            }

        return head_ptr -> value;
    }

    int get_size()
    {
        return size;
    }

    bool empty()
    {
        if(head_ptr == NULL)
            return true;
        
        else
            return false;
    }

    void display_stack()
    {
        node* temp = head_ptr;

        while(temp != NULL)
        {
            cout<< temp -> value<<" | ";
            temp = temp -> next;
        }
    }

    void clear_stack()
    {
        node* prev = NULL;

        while(head_ptr != NULL)
        {
            prev = head_ptr;
            head_ptr = head_ptr -> next;
            delete prev;
        }

        head_ptr = NULL;
        
    }

    ~stack()
    {
        node* prev = NULL;

        while(head_ptr != NULL)
        {
            prev = head_ptr;
            head_ptr = head_ptr -> next;
            delete prev;
        }
    }

};

// int main()
// {
//     stack<int> st;

//     st.push(1);
//     st.push(2);
//     st.push(3);
//     st.push(4);

//     st.display_stack();

//     cout<<endl<<st.get_size()<<endl;

//     st.pop();
//     st.display_stack();
//     cout<<endl<<st.get_size()<<endl;

//     return 0;
// }