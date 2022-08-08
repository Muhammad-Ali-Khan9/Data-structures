#include<iostream>
#include<exception>
#include"stack.cpp"

using namespace std;

template<class T>
class list
{
    private:

    struct node{

        T value;
        node* next;

    };

    int size;
    node* head_ptr;

    void Swap(node *n1,node *n2)
    {
        T temp = n1 -> value;
        n1 -> value = n2 -> value;
        n2 -> value = temp; 
    }

    
    public:

    //constructors
    list()
    {
        head_ptr = NULL;
        size = 0;    
    }

    //overloaded constructor
    list(int size_parameter)
    {
        size = size_parameter;

        node* new_node = new node();
        head_ptr = new_node;

        node* ptr = head_ptr;

        for(int i=0 ; i < size - 1 ; i++)
        {
            node* new_node = new node();
            ptr -> next = new_node;
            ptr = new_node;
        }

        ptr -> next = NULL;
    }

    //copy constructor
    list(const list<T> &list)
    {
        this -> head_ptr = NULL;
        node* temp = list.head_ptr;

        while(temp != NULL)
        {
            this -> push_at_tail(temp -> value);
            temp = temp -> next;
        }
        this -> size = list.size;
    }

    void push_at_head(T val)
    {
        node* new_node = new node;
        new_node -> value = val;
        new_node -> next = head_ptr;
        head_ptr = new_node;
        size++;
    }

    void push_at_tail(T val)
    {
        node* new_node = new node, *temp = head_ptr;
        new_node -> value = val;
        new_node -> next = NULL;

        if(head_ptr == NULL)
        {
            head_ptr = new_node;
            size++;
            return;
        }

        while(temp -> next != NULL)
            temp = temp -> next;

            temp -> next = new_node;
            size++;
    }

    void display_list()
    {
        node* temp = head_ptr;

        while(temp != NULL)
        {
            cout<< temp ->value <<"->";
            temp = temp -> next;
        }
        cout<<"NULL"<<endl;
    }

    T& at(int index)
    {
        try
        {
            if(index > size - 1)
                throw index;
        }
        catch(int i)
        {
            cerr <<"Segemntation Fault";
            exit(EXIT_FAILURE);
        }
        

        node* temp = head_ptr;

        for(int num=0 ; num != index ; num++)
            temp = temp -> next;

        return temp -> value;

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
                cerr<<"List empty";
                return;
            }
        
        node* temp = head_ptr;
        node* prev = NULL;

        if(temp -> value == node_key)
        {
            node* new_node = new node();
            new_node -> value = key;

            new_node -> next = head_ptr;
            head_ptr = new_node;
            size++;

            return;
        }

        else
        {
            while(temp -> value != node_key)
            {
                prev = temp;
                temp = temp -> next;

                try{
                    if(temp == NULL)
                        throw temp;
                }
                catch(node* temp)
                {
                    cerr<<"Node not found";
                    return;
                }
            }

            node* new_node = new node();
            new_node -> value = key;

            prev -> next = new_node;
            new_node -> next = temp;
            size++;

            return;

        }

    }

    void swap_first_and_last_node_elements()
    {
        try
        {
                if(head_ptr == NULL)
                    throw head_ptr;

                if(size == 1)
                    throw size;
        }

            catch(node* ptr)
            {
                cerr<<"List empty";
                return;
            }

            catch(int s)
            {
                cerr<<"List has only one node";
                return;
            }

            node* temp1 = head_ptr, *temp2 = head_ptr;

            while(temp2 -> next != NULL)
            {
                temp2 = temp2 -> next; 
            }

        Swap(temp1,temp2);

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
                cerr<<"List empty";
                return;
            }

        node* prev = head_ptr;
        node* temp = prev -> next;

        while(prev -> value != node_key && prev != NULL)
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
            catch(node* prev)
            {
                cerr<<"Node not found"<<endl;
                return;
            }
        

        if(temp == NULL && prev -> next == NULL)
        {
            node* new_node = new node();
            new_node -> value = key;

            new_node -> next = NULL;
            prev -> next = new_node;
            size++;
        }

        else
        {
            node* new_node = new node();
            new_node -> value = key;

            prev -> next = new_node;
            new_node -> next = temp;
            size++;
        }

    }

    void delete_specific_node(T key)
    {
        node* temp = head_ptr,*pre_ptr = NULL;

        while(temp != NULL && temp -> value != key)
        {
            pre_ptr = temp;
            temp = temp -> next;
        }

        if(temp == NULL)
        {
            cerr<<"Node to delete is not found";
            return;
        }

        if(temp == head_ptr)
        {
            head_ptr = head_ptr -> next;
        }

        else
            pre_ptr -> next = temp -> next; 

        size--;

        delete temp;

    }

    void pop_back()
    {
        if(head_ptr == NULL)
        {
            cerr<<"List is empty"<<endl;
            return;
        }

        node* prev_temp = head_ptr;
        node* temp = prev_temp -> next;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
            prev_temp = prev_temp -> next;
        }

        delete temp;
        prev_temp -> next = NULL;
        size--;
    }

    void pop_front()
    {
        if(head_ptr == NULL)
        {
            cerr<<"List is empty"<<endl;
            return;
        }

        node* temp = head_ptr;
        head_ptr = head_ptr -> next;

        delete temp;
        size--;
    }

    void reverse_list()
    {
        try{

            if(head_ptr == NULL || size == 0)
                throw head_ptr;
        }

            catch(node* ptr)
            {
                cerr<<"List empty";
                return;
            }

        node* temp_prev = NULL, *temp_next = NULL,*temp_curr = head_ptr;

        while(temp_curr != NULL)
        {
            temp_next = temp_curr -> next;
            temp_curr -> next = temp_prev;
            temp_prev = temp_curr;
            temp_curr = temp_next;
        } 

        head_ptr = temp_prev; 

    }

    void add_node_at_middle(T new_num)
    {
        try
        {
            if(size == 1)
                throw size;
        }

            catch(int s)
            {
                cerr<<"List has only one node it has no middle position";
                return;
            }
            

        if(head_ptr == NULL)
        {
            node* new_node = new node();
            head_ptr = new_node;
            new_node -> value = new_num;
            new_node -> next = NULL;
            size++;
            return;
        }

        else
        {
            node* prev = NULL;
            node* temp = head_ptr;

            int position = size/2;

            for(int i=0 ; i != position ; i++)
            {
                prev = temp;
                temp = temp -> next;
            }

            node* new_node = new node();
            new_node -> value = new_num;
            prev -> next = new_node;
            new_node -> next = temp;
            size++;
            return;
        }

    }

    void delete_node_from_middle()
    {
        try
        {
            if(head_ptr == NULL)
                throw head_ptr;

            if(size == 1)
                throw size;
        }
            catch(node* ptr)
            {
                cerr<<"List is empty";
                return;
            }

            catch(int s)
            {
                cerr<<"There is only one node no middle found";
                return;
            }

        node* prev = NULL;
        node* temp = head_ptr;

        int position = size/2;

        for(int i=0 ; i != position ; i++)
        {
            prev = temp;
            temp = temp -> next;
        }    

        prev -> next = temp -> next;
        size--;
        delete temp;

    }

    T& front()
    {
        try
        {
            if(size == 0)
                throw size;
            
            if(head_ptr == NULL)
                throw head_ptr;
        }
            catch(int size)
            {
                cerr << "Empty list / Segmentation fault";
                exit(EXIT_FAILURE);
            }
            catch(node* ptr)
            {
                cerr<<"Empty list / Segementation Fault";
                exit(EXIT_FAILURE);
            }

        return head_ptr -> value;    

    }

    T& middle()
    {
        try
        {
            if(size == 0)
                throw size;
            
            if(head_ptr == NULL)
                throw head_ptr;

            if(size <= 2)
                throw;
        }
            catch(int size)
            {
                cerr << "Empty list / Segmentation fault";
                exit(EXIT_FAILURE);
            }

            catch(node* ptr)
            {
                cerr<<"Empty list / Segementation Fault";
                exit(EXIT_FAILURE);
            }

            catch(...)
            {
                cerr<<"There are few values / Segmentation Fault";
                exit(EXIT_FAILURE);
            }


        node* temp = head_ptr;

        for(int i=0 ; i< size/2 ; i++)
        {
            temp = temp -> next;
        }

        return temp -> value;
    }

    T& end()
    {
        try
        {
            if(size == 0)
                throw size;
            
            if(head_ptr == NULL)
                throw head_ptr;
        }
            catch(int size)
            {
                cerr << "Segementation Fault";
                exit(EXIT_FAILURE);
            }
            catch(node* ptr)
            {
                cerr<<"Segementation Fault";
                exit(EXIT_FAILURE);
            }

        node* temp = head_ptr;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }

        return temp -> value;    
    }

    void fill(T value)
    {
        try
        {
            if(head_ptr == NULL)
                throw head_ptr;
        }

        catch(node* ptr)
        {
            cerr<<"List is empty";
            return;
        }

        node* temp = head_ptr;

        while(temp != NULL)
        {
            temp -> value = value;
            temp = temp -> next;
        }

    }

    bool Check_for_intersection_of_lists(const list<T> &list)
    {
        try
        {
            if(head_ptr == NULL || list.head_ptr == NULL)
                throw head_ptr;    

        }

            catch(node* ptr)
            {
                cerr<<"Either one of the list is empty";
                return false;
            }


        node* temp1 = this -> head_ptr;
        node* temp2 = list.head_ptr;

        while(temp1 != NULL || temp2 != NULL)
        {
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;

            if(temp1 == temp2)
                {
                    cout<<"Both lists meet at address "<<temp1<<endl;
                    list.head_ptr = NULL;
                    return true;
                }
        }

        list.head_ptr = NULL;
        return false;
    }

    void Combine_two_lists(list list)
    {
        try
        {
            if(head_ptr == NULL || list.head_ptr == NULL)
                throw head_ptr; 
        }

            catch(node* ptr)
            {
                cerr<<"Either one of the lists is empty";
                return;
            }

        node* temp = head_ptr;

        while(temp -> next != NULL)
            temp = temp -> next;

        temp -> next = list.head_ptr;

        this -> size = this -> size + list.size; 

        list.head_ptr = NULL; 
    }

    void display_specific_node(T key)
    {
        node* temp = head_ptr;

        while(temp != NULL && temp -> value != key)
            temp = temp -> next;

        if(temp == NULL)
            cout<<"Node is not found";

        else
            cout<<"data of node is: "<<temp -> value<<endl<<"Stored at memory: "<<temp;    
    }

    void sort_decending()
    {
        try
        {
            if(size == 1)
                throw size;

            if(head_ptr == NULL)
                throw head_ptr;
        }
            catch(node* ptr)
            {
                cerr<<"List Empty";
                return;
            }

            catch(int s)
            {
                cerr<<"List has only one node";
                return;
            }

        bool swapped = false;
        node* h = head_ptr;

        for(int i=0; i< size; i++)
        {
            h = head_ptr;
            swapped = false;

            for(int j=0; j< size - i -1 ; j++ )
            {
                node* p1 = h;
                node* p2 = p1 -> next;

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

    int Element_present_count(T num)
    {
        int count = 0;
        node* temp = head_ptr;

        while(temp != NULL)
        {
            if(temp -> value == num)
                count++;

            temp = temp -> next;
        }

        return count;
    }

    bool is_palindrome()
    {
        try
        {
            if(head_ptr == NULL)
                throw head_ptr;
            
            if(size == 1)
                throw size;
        }

            catch(node* ptr)
            {
                cerr<<"List empty";
                return false;
            }
            catch(int s)
            {
                return true;                                 
            }

        stack<T> st;

        node* temp = head_ptr;

        while(temp != NULL)
        {
            st.push(temp -> value);
            temp = temp -> next;
        }

        temp = head_ptr;

        while(st.get_size() != 0)
        {
            if(st.top() != temp -> value)
                return false;

            st.pop();
        }

        return true;
    }

    bool Is_Element_present(T num)
    {
        try
        {
            if(head_ptr == NULL)
                throw head_ptr;
        }
            catch(node* ptr)
            {
                cerr<<"List empty";
                return false;
            }

        bool is_present = false;
        node* temp = head_ptr;

        while (temp != NULL)
        {
            if(temp -> value == num)
                return true;
        }

        return false; 
    }

    void Remove_duplicate_elements(T num)
    {

        try
        {
            if(head_ptr == NULL)
                throw head_ptr;
            
            if(size == 1)
                throw size;
        }

            catch(int s)
            {
                cerr<<"List has only one element";
                return;
            }

            catch(node* ptr)
            {
                cerr<<"List is empty";
                return;
            }

        node* prev = NULL;
        node* temp = head_ptr;
        int count = 0;

        while(temp != NULL)
        {
            if(temp -> value == num)
                count++;

            if(temp -> value == num && count > 1)
            {
                prev -> next = temp -> next;
                delete temp;
                size--;
                temp = prev -> next;
                continue;
            }

            prev = temp;
            temp = temp -> next;

        }

    }

    void sort_acending()
    {
        bool swapped = false;
        node *h;

        for(int i=0 ;i< size; i++)
        {
            h = head_ptr;
            swapped = false;

            for(int j=0 ; j < size - i ; j++)
            {
                node *p1 = h;
                node *p2 = p1 -> next;

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

    int get_size()
    {
        return size;
    }

    void empty_list()
    {
        try
        {
            if(size == 0)
                throw size;

            if(head_ptr == NULL)
                throw head_ptr;
        }
            catch(int size)
            {
                cerr <<"List already empty";
            }
            catch(node* ptr)
            {
                cerr<<"List already empty";
            }
        
        node* temp_ptr = head_ptr;
        node* prev_ptr = NULL;

        while(temp_ptr != NULL)
        {
            prev_ptr = temp_ptr;
            temp_ptr = temp_ptr -> next;
            delete prev_ptr;
        }

        size = 0;
        head_ptr = NULL;
    }

    bool is_empty()
    {
        if(size == 0 || head_ptr == NULL)
            return true;
        
        else
            return false;
    }

    void add_number_to_elements (T num)
    {
        try
        {
            if(head_ptr == NULL)
                throw head_ptr;
        }

        catch(node* ptr)
        {
            cerr<<"List empty";
            return;
        }

        node* temp = head_ptr;

        while(temp != NULL)
        {
            temp -> value = temp -> value + num;
            temp = temp -> next;
        }

    }

    list<T> Substitute_list(T node_key,int length)
    {
        list<T> new_list;

        try{

            if(this -> head_ptr == NULL)
                throw head_ptr;

            if(length > this -> size)
                throw length;
        }

        catch(node* ptr)
        {
            cerr<<"List Empty";
            exit(EXIT_FAILURE);
        }
        catch(int l)
        {
            cerr<<"Out of bound";
            exit(EXIT_FAILURE);
        }

        node* temp = head_ptr;
        
        while(temp != NULL && temp -> value != node_key)
        {
            temp = temp -> next;
        }

        if(temp == NULL)
        {
            cerr<<"Node not found";
            exit(EXIT_FAILURE);
        }

        for(int i = 0 ; i <= length ; i++)
        {
            new_list.push_at_tail(temp -> value);
            temp = temp -> next;

            if(temp == NULL && i < length)
            {
                cerr<<"List length after node is too short to substitute";
                exit(EXIT_FAILURE);
            }

        }

        return new_list;

    }

    list<T> Get_Odd_Index_Nodes()
    {
        try{

            if(head_ptr == NULL || size == 0)
                throw head_ptr;
            
            if(size < 2)
                throw size;
        }

            catch(node* ptr)
            {
                cerr<<"List empty";
                exit(EXIT_FAILURE);
            }

            catch(int s)
            {
                cerr<<"Not enough nodes in list";
                exit(EXIT_FAILURE);
            }

        list<T> new_list;
        node* temp = head_ptr -> next;

            while(temp != NULL)
            {
                new_list.push_at_tail(temp -> value);

                temp = temp -> next;
                if(temp != NULL)
                    temp = temp -> next; 
            }

        return new_list;

    }

    list<T> Get_Even_Index_nodes()
    {
        try{

            if(head_ptr == NULL || size == 0)
                throw head_ptr;
            
            if(size < 2)
                throw size;
        }

            catch(node* ptr)
            {
                cerr<<"List empty";
                exit(EXIT_FAILURE);
            }

            catch(int s)
            {
                cerr<<"Not enough nodes in list";
                exit(EXIT_FAILURE);
            }

        list<T> new_list;
        node* temp = head_ptr;

        while(temp != NULL)
        {
            new_list.push_at_tail(temp -> value);

            temp = temp -> next;
                if(temp != NULL)
                    temp = temp -> next;
        }

        return new_list;

    }

    void add_list_after_node(T key,list<T> list1)
    {
        try
        {
            if(head_ptr == NULL)
                throw head_ptr;
        }

        catch(node* ptr)
        {
            cerr<<"List empty";
            return;
        }

        node* temp = head_ptr, *temp_next = head_ptr -> next, *temp2 = list1.head_ptr;

        if(temp -> value == key)
        {

            while(temp2 -> next != NULL)
                {
                    temp2 = temp2 -> next;
                }

                temp2 -> next = this -> head_ptr;
                head_ptr = list1.head_ptr;
                this -> size += list1.size;
                list1.head_ptr = NULL;
                return;

        }
        
        while(temp != NULL && temp -> value != key)
        {
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
            temp -> next = list1.head_ptr;
            this -> size += list1.size;
            return;
        }

        temp -> next = list1.head_ptr;

        while(temp2 -> next != NULL)
        {
            temp2 = temp2 -> next;
        }

        temp2 -> next = temp_next;
        list1.head_ptr = NULL;

        this -> size += list1.size;
        
    }

    void operator += (T num)
    {
        try
        {
            if(head_ptr == NULL)
                throw head_ptr;

            if(size == 0)
                throw size;

        }
            catch(node* ptr)
            {
                cerr<<"List empty";
                return;
            }
            catch(int s)
            {
                cerr<<"List empty";
                return;
            }


        node* temp = head_ptr;

        while(temp != NULL)
        {
            temp -> value = temp -> value + num;
            temp = temp -> next;
        }
    }

    void operator -= (T num)
    {
        try
        {
            if(head_ptr == NULL)
                throw head_ptr;

            if(size == 0)
                throw size;

        }
            catch(node* ptr)
            {
                cerr<<"List empty";
                return;
            }
            catch(int s)
            {
                cerr<<"List empty";
                return;
            }

        node* temp = head_ptr;

        while(temp != NULL)
        {
            temp -> value = temp -> value - num;
            temp = temp -> next;
        }

    }

    void operator *= (T num)
    {
        try
        {
            if(head_ptr == NULL)
                throw head_ptr;

            if(size == 0)
                throw size;
        }
            catch(node* ptr)
            {
                cerr<<"List empty";
                return;
            }
            catch(int s)
            {
                cerr<<"List empty";
                return;
            }

        node* temp = head_ptr;

        while(temp != NULL)
        {
            temp -> value = temp -> value * num;
            temp = temp -> next;
        }

    }

    void operator /= (T num)
    {
        try
        {
            if(head_ptr == NULL)
                throw head_ptr;

            if(size == 0)
                throw size;

        }
            catch(node* ptr)
            {
                cerr<<"List empty";
                return;
            }
            catch(int s)
            {
                cerr<<"List empty";
                return;
            }

        node* temp = head_ptr;

        while(temp != NULL)
        {
            temp -> value = temp -> value / num;
            temp = temp -> next;
        }

    }

    void operator %= (T num)
    {
        try
        {
            if(head_ptr == NULL)
                throw head_ptr;

            if(size == 0)
                throw size;

        }
            catch(node* ptr)
            {
                cerr<<"List empty";
                return;
            }
            catch(int s)
            {
                cerr<<"List empty";
                return;
            }

        node* temp = head_ptr;

        while(temp != NULL)
        {
            temp -> value = temp -> value % num;
            temp = temp -> next;
        }

    }

    void operator = (list list)
    {
        if(this -> head_ptr == NULL)
        {
            node* temp = list.head_ptr;
            int num;
            while(temp != NULL)
            {
                num = temp -> value;
                this -> push_at_tail(num);
                temp = temp -> next;
            }

               this -> size = list.size;
                
        }

        else
        {
            this -> empty_list();

            node* temp = list.head_ptr;
            int num;
            for(int i = 0 ; i < list.size; i++)
            {
                num = temp -> value;
                this -> push_at_tail(num);
                temp = temp -> next;
            }

               this -> size = list.size;
        }

    }

    T& operator [] (int index)
    {
        try
        {
            if(index > size - 1)
                throw index;
        }
            catch(int i)
            {
                cerr <<"Segementation Fault";
                exit(EXIT_FAILURE);
            }
        

        node* temp = head_ptr;

        for(int num=0 ; num != index ; num++)
            temp = temp -> next;

        return temp -> value;

    }

    bool operator == (list list1)
    {
        if(this -> size != list1.size)
        {
            list1.head_ptr = NULL;
            return false;
        }

        node* temp1 = this -> head_ptr, *temp2 = list1.head_ptr;

        while(temp1 != NULL || temp2 != NULL)
        {
            if(temp1 -> value != temp2 -> value)
                return false;
            
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }

        list1.head_ptr = NULL;
        return true;
    }

    bool operator != (list list1)
    {
        if(this -> size != list1.size)
        {
            list1.head_ptr = NULL;
            return true;
        }

        node* temp1 = this -> head_ptr, *temp2 = list1.head_ptr;

        while(temp1 != NULL || temp2 != NULL)
        {
            if(temp1 -> value != temp2 -> value)
                return true;
            
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }

        list1.head_ptr = NULL;
        return false;
    }

    list<T> operator << (int times)
    {
        try{

            if(head_ptr == NULL)
                throw head_ptr;

            if(times > size)
                throw size;

        }
        catch(int s)
        {
            cerr<<"Size is less then nodes requested to shift";
            exit(EXIT_FAILURE);
        }
        catch(node* ptr)
        {
            cerr<<"List empty";
            exit(EXIT_FAILURE);
        }

        list<T> new_list;
        node* temp = head_ptr;
        stack<T> st;

        while(temp != NULL)
        {
            st.push(temp -> value);
            temp = temp -> next;
        }

        for(int i = 0 ; i < times ; i++)
        {
            new_list.push_at_tail(st.top());
            st.pop();
        }

        st.clear_stack();

        return new_list;
    }

    list<T> operator >> (int times)
    {
        try{

            if(head_ptr == NULL)
                throw head_ptr;

            if(times > size)
                throw size;

        }
        catch(int s)
        {
            cerr<<"Size of list is less then the number of nodes requested to shift";
            exit(EXIT_FAILURE);
        }
        catch(node* ptr)
        {
            cerr<<"List empty";
            exit(EXIT_FAILURE);
        }

        list<T> new_list;
        node* temp = this -> head_ptr;

        for(int i=0 ; i<size ; i++)
        {
            new_list.push_at_tail(temp -> value);
            temp = temp -> next;
        }

        return new_list;
    }

    list<T> operator + (list<T> list1)
    {
        list<T> new_list;

        if(this -> head_ptr == NULL)
        {
            node* temp = list1.head_ptr;

            while(temp != NULL)
            {
                new_list.push_at_tail(temp -> value);
                temp = temp -> next;
            }

            return new_list;
        }

        else if(list1.head_ptr == NULL)
        {
            node* temp = this -> head_ptr;

            while(temp != NULL)
            {
                new_list.push_at_tail(temp -> value);
                temp = temp -> next;
            }

            return new_list;
        }

        else if(this -> head_ptr == NULL && list1.head_ptr == NULL)
            return new_list;
        
            node* temp1 = this -> head_ptr;
            node* temp2 = list1.head_ptr;

            while(temp1 != NULL)
            {
                new_list.push_at_tail(temp1 -> value);
                temp1 = temp1 -> next;
            }

            while(temp2 != NULL)
            {
                new_list.push_at_tail(temp2 -> value);
                temp2 = temp2 -> next;
            }

            return new_list;
                    
    }


    ~list()
    {
        node* prev_ptr = NULL;

        while(head_ptr != NULL)
        {
            prev_ptr = head_ptr;
            head_ptr = head_ptr -> next;
            delete prev_ptr;
        }
    }

};

int main()
{
    list<char> list1,list2;

    list1.push_at_head('a');
    list1.push_at_tail('b');
    list1.push_at_head('c');
    list1.push_at_tail('d');
    list1.push_at_tail('g');
    list1.push_at_tail('h');
    list1.push_at_head('i');
    //list1.reverse_list();

    list2.push_at_tail('1');
    list2.push_at_head('2');
    list2.push_at_tail('3');

    //list1.add_before_node('c','e');
    //list1.add_after_node('c','f');

    //list2 = list1.Substitute_list('c',1);
    

    //list2.add_list_after_node('1',list1);

    //list1.display_list();
    //cout<<list1.get_size()<<endl;
    list2.display_list();
    cout<<list2.get_size()<<endl;

    // list1.swap_first_and_last_node_elements();

    // list1.display_list();
    // cout<<"  "<<list1.get_size()<<endl;

    // list1.delete_node_from_middle();
    // //list1.add_number(133);
    // list2 = list1;

    // if(list1 != list2)
    //     cout<<"Not Equal"<<endl;
    // else
    //     cout<<"Equal"<<endl;
    
    // list2.display_list();
    // cout<<"  "<<list2.get_size()<<endl;

    // list1.display_list();
    // cout<<"  "<<list1.get_size()<<endl;

    // cout<<"List created is"<<endl;
    // list1.display_list();
    // cout<<endl;

    // cout<<"After deleting 20"<<endl;
    // list1.delete_specific_node(20);
    // list1.display_list();
    // cout<<endl;

    // cout<<"After-acending-sorting list"<<endl;
    // list1.sort_acending();
    // list1.display_list();
    // cout<<endl;

    // cout<<"After-decending-sorting list"<<endl;
    // list1.sort_decending();
    // list1.display_list();
    // cout<<endl;

    // list1.add_after_node(40,50);
    // list1.add_after_node(10,20);
    // list1.add_before_node(10,5);
    // list1.add_before_node(50,45);
    // list1.display_list();

    return 0;
}