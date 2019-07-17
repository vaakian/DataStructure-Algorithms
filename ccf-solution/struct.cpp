#include <bits/stdc++.h>
using namespace std;
struct PERSON
{
    PERSON(int _age)
    {
        age = _age;
        left = right = NULL;
    };
    int age;
    PERSON *left;
    PERSON *right;
};
int main()
{
    PERSON *p = new PERSON(15); // equal to malloc
    cout << p->age << endl;
    return 0;
}