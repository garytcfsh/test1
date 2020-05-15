#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <assert.h>

using namespace std;

class List 
{
    friend istream & operator << (istream&, List);
    public:
    List()
    { 
        head = temp = next = last = NULL;
        cout << "List constructor" << endl;
    }
    ~List()
    {
        cout << "List destructor" << endl;
    }

//    List& operator[](int);
    float& operator[](int);
    List *head, *temp, *next, *last;
    List& append(float);

    float n1, n2;
};

float& List::operator[](int n)
{
    this->temp = this->head;
    for (int i=0; i<n; i++)
    {
        this->temp = this->temp->next;
    }

    return this->temp->n1;
}

// istream& operator<<(istream& a, List& b)
// {
//     b.n1 = a;
// }


List& List::append(float f)
{
    if (this->head == NULL)
    {
        this->next = new List;
        this->temp = this->next;
        this->last = this->temp;
        this->head = this->temp;
        this->temp->n1 = f;
    }
    else
    {
        this->last->next = new List;
        this->temp = this->last->next;
        this->last = this->temp;
        this->temp->n1 = f;
    }
    

    return *(this->temp);
}

// List& List::operator[](int n)
// {
//     this->temp = this->head;
//     for (int i=0; i<n; i++)
//     {
//         this->temp = this->temp->next;
//     }

//     return *(this->temp);
// }

class Array : public List
{

    friend istream & operator>> (istream & in, Array & a)
    {
        cout << ">>" << endl;
        in >> a.ptr[a.ii];
        a.ii++;
        return in;
    }

    public:
    Array(int i)
    {
        ii = 0;
        size = i;
        ptr = new int[size];
        for (int n=0; n<size; n++)
        {
            ptr[n] = 0;
        }
        cout << "Array constructor" << endl;
    }
    ~Array()
    {
        cout << "Array destructor" << endl;
    }
    int & operator[] (int i)
    {
        assert( 0 <= i && i < size);
        cout << "operator [] 1" << endl;
        return ptr[i];
    }
    const int & operator[] (int i) const//const function which means the members in the class can`t be modified 
    { 
        assert( 0 <= i && i < size); 
        cout << "operator [] 2" << endl; 
        ptr[i] = 100;
        //becouse ptr[i] is not a member of class, it can be modified
        return ptr[i]; 
    } 
    void show() const
    {
        for (int i=0; i<size; i++)
        {
            cout << ptr[i] << " ";
        }
        cout << endl;
    }

    void setTest(int i)
    {
        test = i;
    }
    
    private:
    int size;
    int *ptr;
    int ii;
    int test;

};



int main()
{
    // Array class operation overlodaing
    Array ary(5);
    const Array cary(5);// can`t change class member
    ary.show();
    // cin >> ary >> ary;//there still are some problems
    int x = 15, y = 25;
    x = ary[2];
    ary[0] = 5;
    y = cary[2];
    // cary[0] = 15;
    ary.show();
    cary.show();

    // Constant argument testing



    // Linked list operation overloading
    // List list
    // for (int i=5; i<10; i++)
    // {
    // }
// cout << list[1] << " " << list[2] << endl;
    // list[1] = 1;
    // float x = list[2];

    // cout << list[1] << " " << x;
    // for (int i=0; i<5; i++)
    // {
    //     cout << list[i].n1 << endl;
    // }


    return 0;
}