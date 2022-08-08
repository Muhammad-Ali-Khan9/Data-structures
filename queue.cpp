#include<iostream>
#include<exception>

using namespace std;

template<class T>
class queue
{
    private:
    struct node{

        T value;
        node* next;

    };

    int size;
    node* head_ptr;

    public:

    queue()
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
            head_ptr = new_node;
            new_node -> next = NULL;
            size++;
        }

        else
        {
            node* temp = head_ptr;

            while(temp -> next != NULL)
            {
                temp = temp -> next;
            }

            node* new_node = new node();
            new_node -> value = key;
            temp -> next = new_node;
            new_node -> next = NULL;
            size++;
        }

    }

    void pop()
    {
        try
        {
            if(head_ptr ==NULL)
                throw head_ptr;
        }

            catch(node* ptr)
            {
                cerr<<"Queue Empty";
                return;
            }

        node* temp = head_ptr;
        head_ptr = head_ptr -> next;
        size--;
        delete temp;
        
    }

    T& front()
    {
        try
        {
            if(head_ptr == NULL)
                throw head_ptr;
        }
            catch(node* ptr)
            {
                cerr<<"Queue Empty";
                exit(EXIT_FAILURE);
            }

        return head_ptr -> value;
    }

    T& back()
    {
        try
        {
            if(head_ptr == NULL)
                throw head_ptr;
        }
            catch(node* ptr)
            {
                cerr<<"Queue Empty";
                exit(EXIT_FAILURE);
            }

        node* temp = head_ptr;
        
        while(temp -> next != NULL)
            temp = temp -> next;
        
        return temp -> value;
    }

    int get_size()
    {
        return size;
    }

    bool empty()
    {
        if(head_ptr == NULL)
            return false;
        
        else 
            return true;
    }

    void empty_queue()
    {
        node* prev = NULL;
        node* temp = head_ptr;

        while(temp != NULL)
        {
            prev = temp;
            temp = temp -> next;
            delete prev;
        }

        head_ptr = NULL;
        size = 0;
    }

    void display_queue()
    {
        node* temp = head_ptr;

        while(temp != NULL)
        {
            cout<<temp -> value <<" ";
            temp = temp -> next;
        }
    }

    void operator = (queue<T> new_queue)
    {

        if(this -> head_ptr == NULL)
        {
            node* temp = new_queue.head_ptr;

            while(temp != NULL)
            {
                this -> push(temp -> value);
                temp = temp -> next;
            }

            this -> size = new_queue.size;
            new_queue.head_ptr = NULL;
        }

        else
        {
            this -> empty_queue();

            node* temp = new_queue.head_ptr;

            while(temp != NULL)
            {
                this -> push(temp -> value);
                temp = temp -> next;
            }

            this -> size = new_queue.size;
            new_queue.head_ptr = NULL;

        }

    }

    ~queue()
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

int main()
{
    queue<string> st;
    st.push("Ghulam");
    st.push("Ishaq");
    st.push("Khan");
    st.push("Institute");

    st.display_queue();

    cout<<endl;
    st.pop();

    st.display_queue();

    return 0;      
}