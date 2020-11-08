#ifndef LIST_H 
#define LIST_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::setw;

//отсортированный список по возрастанию
class List
{
private:
    //ячейка
    struct Node
    {
        int data; 
        Node* next; 
        Node(int _data=int(), Node* _next=NULL) : data(_data), next(_next) {}
        ~Node() {}
    };

    Node* head; 
    int SIZE;    

public:
    List() : head(NULL), SIZE(0) {}
    List(const string &file_name);
    List(const List& obj);
    ~List();

    List& operator=(List&& r_obj);
    //-------------------------------------------------
    class iterator; 
    void push_rise(const int _data);
    iterator begin() const;
    iterator end() const;   //*
    //------------------------------------------------
    bool empty() const { return SIZE == 0; }
    int  size() const { return SIZE; }
    string is_string() const;
    //--------------------------------------------
};

class List::iterator
{
private:
    Node* p_value;

public:
    iterator(Node* first) : p_value(first) {}

    Node& operator++ ();

    bool operator!= (const iterator& it) { return p_value != it.p_value; }
    bool operator== (const iterator& it) { return p_value == it.p_value; }

    int operator* () { return p_value->data; }
};


#endif