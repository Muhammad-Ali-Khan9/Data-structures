#include<iostream>

using namespace std;

template< class T >
class double_linked_list{

    private:

    struct node{

        T value;
        node* next;
        node* prev;

    };

    int size;
    node* head_ptr;

    void Swap(node* p1,node* p2)
    {
        T temp = p1 -> value;
        p1 -> value = p2 -> value;
        p2 -> value = temp;
    }

    public:

    double_linked_list()
    {
        size = 0;
        head_ptr = NULL;
    }

    void push_at_head(T key)
    {
        if(head_ptr == NULL)
        {
            node* new_node = new node();
            new_node -> value = key;
            head_ptr = new_node;
            new_node -> next = NULL;
            new_node -> prev = NULL;
            size++;
        }

        else
        {
            node* new_node = new node();
            new_node -> value = key;
            new_node -> next = head_ptr;
            head_ptr -> prev = new_node;
            head_ptr = new_node;
            size++;

        }
    }

    void push_at_tail(T key)
    {
        if(head_ptr == NULL)
        {
            node* new_node = new node();
            new_node -> value = key;
            head_ptr = new_node;
            new_node -> next = NULL;
            new_node -> prev = NULL;
            size++;
        }

        else
        {
            node* new_node = new node();
            new_node -> value = key;

            node* temp = head_ptr;

            while(temp -> next != NULL)
                temp = temp -> next;

            new_node -> next = NULL;
            temp -> next = new_node;
            new_node -> prev = temp;
            size++;            
        }
    }

    void add_before_node(T node_key,T key)
    {
        try
        {
            if(head_ptr == NULL)
                throw head_ptr;
        }

            catch(node* ptr)
            {
                cerr<<"List Empty";
                return;
            }

        node* temp = head_ptr;
        node* prev = NULL;

        if(temp -> value == node_key)
        {
            node* new_node = new node();
            new_node -> value = key;
            new_node -> next = head_ptr;
            new_node -> prev = NULL;
            head_ptr = new_node;
            size++;
            return;
        }

        while(temp != NULL && temp -> value != node_key)
        {
            prev = temp;
            temp = temp -> next;
        }
        
        if(temp == NULL)
        {
            cout<<"Node not found";
            return;
        }
        
            node* new_node = new node();
            new_node -> value = key;

            prev -> next = new_node;
            new_node -> next = temp;

            new_node -> prev = prev;
            temp -> prev = new_node;

            size++;
        
    }

    void add_after_node(T node_key,T key)
    {
        try
        {
            if(head_ptr == NULL)
                throw head_ptr;
        }

            catch(node* ptr)
            {
                cerr<<"List Empty";
                return;
            }

        node* prev = head_ptr;
        node* temp = head_ptr -> next;

        if(temp -> value == node_key)
        {
            prev = temp;
            temp = temp -> next;

            node* new_node = new node();
            new_node -> value = key;

            prev -> next = new_node;
            new_node -> prev = prev;

            new_node -> next = temp;
            temp -> prev = new_node;

            size++;

            return;
        }

        while(prev != NULL && prev -> value != node_key)
        {
            prev = prev -> next;

            if(temp != NULL)
                temp = temp -> next;
        }

        try
        {
            if(prev == NULL)
                throw prev;
        }
            catch(node* ptr)
            {
                cerr<<"Node not found";
                return;
            }

        if(prev -> next == NULL && temp == NULL)
        {
            node* new_node = new node();
            new_node -> value = key;

            prev -> next = new_node;
            new_node -> next = NULL;

            new_node -> prev = prev;
            size++;
            return;
        }

        node* new_node = new node();
        new_node -> value = key;

        prev -> next = new_node;
        new_node -> prev = prev;

        new_node -> next = temp;
        temp -> prev = new_node;

        size++;

    }

    bool is_Palindrome()
    {
        try
        {
            if(size == 1)
                throw size;
        }

            catch(int size)
            {
                return true;
            }

        node* end = head_ptr;
        node* start = head_ptr;

        while(end -> next != NULL)
            end = end -> next;
        
        for(int i = 0 ; i < size/2 ; i++)
        {
            if(end -> value != start -> value)
                return false;
            
            end = end -> prev;
            start = start -> next; 
        }
        
        return true;
    }

    void display_list_forward()
    {
        node* temp = head_ptr;

        while(temp != NULL)
        {
            cout<<temp -> value <<" <-> ";
            temp = temp -> next;
        }
        cout<<"NULL";
    }

    void display_list_backwards()
    {
        node* temp = head_ptr;

        while(temp -> next != NULL)
            temp = temp -> next;
        
        while(temp != NULL)
        {
            cout<<temp -> value <<" <-> ";
            temp = temp -> prev;
        }
        cout<<"NULL";
    }

    void delete_specific_node(T key)
    {
        try
        {
            if(head_ptr == NULL)
                throw head_ptr;
        }

            catch(node* ptr)
            {
                cerr<<"List Empty";
                return;
            }

        node* prev = NULL;
        node* temp = head_ptr;
        node* temp_next = head_ptr -> next;

        if(temp -> value == key)
        {
            head_ptr = head_ptr -> next;
            head_ptr -> prev = NULL;

            delete temp;
            size--;
            return;
        }

        while(temp -> value != key && temp != NULL)
        {
            prev = temp;
            temp = temp -> next;

            if(temp_next != NULL)
                temp_next = temp_next -> next;
        }
        
        if(temp == NULL)
        {
            cout<<"Node not found";
            return;
        }
        
        if(temp -> next == NULL)
        {
            prev -> next = NULL;
            delete temp;
            size--;
            return;
        }

        prev -> next = temp -> next;
        temp_next -> prev = prev;
        size--;
        delete temp;

    }

    void sort_acending()
    {
        node* h;
        bool swapped = false;

        for(int i=0 ; i<size ; i++ )
        {
            h = head_ptr;
            swapped = false;

            for(int j=0 ; j < size - i -1 ; j++ )
            {
                node* p1 = h;
                node* p2 = p1 -> next;

                if(p2 == NULL)
                    break;

                if(p1 -> value < p2 -> value)
                {
                    Swap(p1,p2);
                    swapped = true;
                }

                h = h -> next;
            }

            if(swapped == false)
                break;
        }

    }

    void sort_decending()
    {
        node* h,temp_next;
        bool swapped = false;

        for(int i=0;i<size;i++)
        {
            node* h;
            bool swapped = false;

            for(int i=0 ; i<size ; i++ )
            {
                h = head_ptr;
                swapped = false;

                for(int j=0 ; j < size - i -1 ; j++ )
                {
                    node* p1 = h;
                    node* p2 = p1 -> next;

                    if(p2 == NULL)
                        break;

                    if(p1 -> value > p2 -> value)
                    {
                        Swap(p1,p2);
                        swapped = true;
                    }

                    h = h -> next;
                }

                if(swapped == false)
                    break;
            }

        } 
    }   

    int get_size()
    {
        return size;
    }

    void pop_front()
    {
        try
        {
            if(head_ptr == NULL)
                throw head_ptr;
        }

            catch(node* ptr)
            {
                cerr<<"List Empty";
                return;
            }

        node* temp = head_ptr;
        head_ptr = head_ptr -> next;
        head_ptr -> prev = NULL;
        delete temp;
        size--;
    }
    

    void pop_back()
    {
        try
        {
            if(head_ptr == NULL)
                throw head_ptr;
        }

            catch(node* ptr)
            {
                cerr<<"List Empty";
                return;
            }
            
        node* prev = NULL;
        node* temp = head_ptr;

        while(temp -> next != NULL)
        {
            prev = temp;
            temp = temp -> next;
        }

        prev -> next = NULL;
        delete temp;
        size--;
    }

    bool is_empty()
    {
        if(head_ptr == NULL)
            return true;

        else
            return false;
    }

    void clear_list()
    {
        if(head_ptr == NULL)
            return;

       node* prev = NULL;

        while(head_ptr != NULL)
        {
            prev = head_ptr;
            head_ptr = head_ptr -> next;
            delete prev;
        }

        head_ptr = NULL;
        size = 0; 
    }

    ~double_linked_list()
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

};

int main()
{
    double_linked_list<int> list1;

    list1.push_at_head(10);
    list1.push_at_tail(20);
    list1.push_at_tail(40);
    list1.push_at_tail(35);
    list1.push_at_head(60);

    list1.sort_decending();

     list1.display_list_forward();
     cout<<"  Size: "<<list1.get_size()<<endl;
     list1.display_list_backwards();
    //  cout<<" "<<list1.get_size()<<endl;

    // if(list1.is_Palindrome())
    //     cout<<"List is palindrome";
    
    // else
    //     cout<<"List is not palindrome";

    // list1.push_at_head(10);
    // list1.push_at_tail(20);
    // list1.push_at_head(30);
    // list1.push_at_tail(40);
    
    // list1.display_list_forward();
    // cout<<endl;
    // list1.display_list_backwards();

    // cout<<endl;

    // list1.pop_back();
    // list1.display_list_forward();
    // cout<<endl;
    // list1.display_list_backwards();

    // cout<<endl;

    // list1.pop_front();
    // list1.display_list_forward();
    // cout<<endl;
    // list1.display_list_backwards();

    return 0;
}