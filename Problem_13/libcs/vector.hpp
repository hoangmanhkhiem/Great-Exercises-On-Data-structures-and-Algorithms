//
// Created by admin on 04/11/2023.
//

#ifndef BTLCTDL_VECTOR_HPP
#define BTLCTDL_VECTOR_HPP

#include<iostream>
using namespace std;

template <typename data>
class dynamicArray
{
private:
    int capacity; //this holds the max size of the array
    data* cur_user_array;
    int sizeIs; //this holds the total amount of elements that is inside the array
public:
    bool operator<(dynamicArray<data>& input);
    bool operator>(dynamicArray<data>& input);
    bool operator>=(dynamicArray<data>& input);
    bool operator<=(dynamicArray<data>& input);
    bool operator==(dynamicArray<data>& input);
    dynamicArray<data> operator+(dynamicArray<data>& input1);
    data& operator[](int index);
    data& operator->();
    dynamicArray();
    ~dynamicArray();
    bool is_empty(); //Check if the vector is empty
    void auto_resize(); // Resize the vector when it is full
    void clear(); //Clear the vector
    void push_back(data push_data_to_back_vector); //Push data to the back of the vector
    void remove_data(data lookFor); //Erase the data that is equal to the data that is passed in
    void remove(int index); // Remove the data at the index
    int get_size(); //size of the array currently
    void debugAry(); //debug the array
};

template<typename data>
dynamicArray<data>::dynamicArray()
{
    capacity = 1; //default 1?
    cur_user_array = new data[capacity]; //this value has to modify on the heap
    sizeIs = 0;
}

template<typename data>
dynamicArray<data>::~dynamicArray()
{
    delete[] cur_user_array;
}

template<typename data>
bool dynamicArray<data>::is_empty()
{
    if (sizeIs == 0)
        return true;
    return false;
}

template<typename data>
void dynamicArray<data>::auto_resize()
{
    if (capacity == 0)
        capacity++;
    else if (capacity == sizeIs)
    {
        capacity *= 2;
        //cout << "size has been doubled" << endl;
        //cout << "capacity: " << capacity << "|sizeIs: " << sizeIs << endl;

        data* temp_arr = new data[capacity];
        for (int i = 0; i < capacity / 2; i++)
        {
            temp_arr[i] = cur_user_array[i];
        }
        delete[] cur_user_array;
        cur_user_array = temp_arr;
    }
}

template<typename data>
void dynamicArray<data>::clear()
{
    sizeIs = 0;
}

template<typename data>
void dynamicArray<data>::push_back(data push_data_to_back_vector/*user_input*/)
{
    sizeIs++;
    auto_resize();
    //cout << "push_back called" << endl;
    cur_user_array[sizeIs - 1] = push_data_to_back_vector;
}

template<typename data>
int dynamicArray<data>::get_size() //size of the array currently
{
    return sizeIs;
}

template<typename data>
void dynamicArray<data>::remove_data(data lookFor)
{
    int sizeIsnew = sizeIs;
    for (int i = 0; i < sizeIs; i++)
    {
        if (cur_user_array[i] == lookFor)
        {
            for (int j = i; j < sizeIs; j++)
            {
                cur_user_array[j] = cur_user_array[j + 1];
            }
            sizeIs--;
        }
    }
    if (sizeIsnew == sizeIs) cout << "No data found" << endl;
}

template<typename data>
void dynamicArray<data>::remove(int index)
{
    if (!is_empty())
    {
        for (int i = index; i < sizeIs; i++)
        {
            cur_user_array[i] = cur_user_array[i + 1];
        }
        sizeIs--;
    }
}


//operator overloading
template<typename data>
ostream& operator<<(ostream& COUT, dynamicArray<data>& veccy)
{
    COUT << "[";
    for (int i = 0; i < veccy.get_size() - 1; i++)
    {
        COUT << veccy.cur_user_array[i] << ", ";
    }
    COUT << veccy.cur_user_array[veccy.get_size() - 1];
    cout << "]" << endl;
    return COUT;
}

template<typename data>
bool dynamicArray<data>::operator<(dynamicArray<data>& input)
{
    if (sizeIs != input.sizeIs)
        return (sizeIs < input.sizeIs);

    if (sizeIs == input.sizeIs)
    {
        for (int i = 0; i < sizeIs; i++)
        {
            if (cur_user_array[i]/*or you can use "this[i]"*/ < input[i])
                return true;
            else if (cur_user_array[i] > input[i])
                return false;
        }
        return false;
    }
}

template<typename data>
bool dynamicArray<data>::operator>(dynamicArray<data>& input)
{
    if (sizeIs != input.sizeIs)
        return(sizeIs > input.sizeIs);

    if (sizeIs == input.sizeIs)
    {
        for (int i = 0; i < sizeIs; i++)
        {
            if (cur_user_array[i] > input[i])
                return true;
            else if (cur_user_array[i] > input[i])
                return false;
        }
        return false;
    }
}

template<typename data>
bool dynamicArray<data>::operator>=(dynamicArray<data>& input)
{
    if (sizeIs != input.sizeIs)
        return(sizeIs > input.sizeIs);

    if (sizeIs == input.sizeIs)
    {
        for (int i = 0; i < sizeIs; i++)
        {
            if (cur_user_array[i] > input[i])
                return true;
            else if (cur_user_array[i] > input[i])
                return false;
        }
        return false;
    }
}

template<typename data>
bool dynamicArray<data>::operator<=(dynamicArray<data>& input)
{
    if (sizeIs != input.sizeIs)
        return (sizeIs < input.sizeIs);

    if (sizeIs == input.sizeIs)
    {
        for (int i = 0; i < sizeIs; i++)
        {
            if (cur_user_array[i]/*or you can use "this[i]"*/ < input[i])
                return true;
            else if (cur_user_array[i] > input[i])
                return false;
        }
        return false;
    }
}

template<typename data>
dynamicArray<data> dynamicArray<data>::operator+(dynamicArray<data>& input1)
{
    dynamicArray<data> temp;
    for (int i = 0; i < sizeIs; i++)
    {
        temp.push_back(cur_user_array[i] + input1[i]);
    }
    return temp;
}


//left off here:::
template<typename data>
bool dynamicArray<data>::operator==(dynamicArray<data>& input)
{
    if (/*cur_user_array*/this->sizeIs != input.sizeIs)
        return false;

    for (int i = 0; i < sizeIs; i++)
    {
        if (cur_user_array[i] != input[i])
            return false;
    }

    return true;
}


template<typename data>
data& dynamicArray<data>::operator[](int index)
{
    return cur_user_array[index];
}

template<typename data>
data& dynamicArray<data>::operator->()
{
    return cur_user_array;
}


//Debug Functions:
template<typename data>
void dynamicArray<data>::debugAry()
{
    //cout << endl;
    cout << "[";
    for (int i = 0; i < sizeIs; i++)
    {
        cout << "Element " << i << ": ";
        cout << cur_user_array[i] << endl;//", ";
    }
    //cout << cur_user_array[sizeIs];
    cout << "]";
    cout << endl;
}


#endif //BTLCTDL_VECTOR_HPP
