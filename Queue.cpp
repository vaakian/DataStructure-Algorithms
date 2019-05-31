// C++迭代器，Iterator

#include<iostream>
using namespace std;

int main()
{
    int a[] = {214,4,34,5,34,5,435,34,5};
    cout<<"hello, C++!\n"<<endl;

    for(auto &t_a: a)
        cout<<(t_a*=t_a)<< endl;
    return 0;
}