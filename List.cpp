#include "List.h"

List::List(const string &file_name) : head(NULL), SIZE(0)
{
    std::ifstream f(file_name);
    
    if (f.is_open())
    {
        int N;
        f >> N;
        
        int cur_value;
        for (int i = 0; i < N; i++)
        {
            f >> cur_value;
            push_rise(cur_value);
        }
        
        f.close();
        return;
    }

    throw std::invalid_argument("File didnt open(" + file_name + ")");
}

List::List(const List& obj) : head(obj.head), SIZE(obj.SIZE) {}

List::~List()
{
    Node* tmp;

    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        delete tmp;
    }
}

List& List::operator=(List&& r_obj)
{
    if (this == &r_obj)
        return *this;
    
    head = r_obj.head;
    SIZE = r_obj.SIZE;

    r_obj.head = NULL;
    r_obj.SIZE = 0;

    return *this;
}

void List::push_rise(const int _data)
{
    if (empty())
    {
        Node* tmp = new Node();
        tmp->data = _data;

        head = tmp;
    }
    else
    {
        Node** pp = &head;

        while ((*pp != NULL) && ((**pp).data < _data))
            pp = &((**pp).next);
        
        Node* tmp = new Node();
        tmp->data = _data;
        tmp->next = *pp;

        *pp = tmp;
    }

    ++SIZE;    
}

List::iterator List::begin() const
{ 
    return iterator(head); 
}

List::iterator List::end() const
{
    Node* end = head;
    for (end; !empty() && (end->next) != NULL; end = end->next);
    return iterator(end);
}

string List::is_string() const 
{   
    std::stringstream ss;
    
    ss << "[ ";
    for (Node* tmp = head; tmp != NULL; tmp = tmp->next)
        ss << setw(4) << tmp->data << " ";
    ss << "]"; 

    return ss.str();
}

List::Node& List::iterator::operator++ ()
{
    p_value = p_value->next; 
    return *p_value;
}
