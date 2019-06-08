#include<iostream>
using namespace std;

class Trie {
private:
    string name;
    char age;
public:
    Trie(string _name, char _age) {
        name = _name;
        age = _age;
        Log("Trie inited");
    };
    void Log(string msg) {
        cout<<"system: "<<msg<<endl;
    };
    int SayHello() {
        cout<<"I'm "<<name<<", and i am "<<(int)age<<" years.\n"<<endl;
        return 0;
    };
    string *GetNameAddr() {
        return &name;
    }
};

int main()
{
    Trie t = Trie("Marry", 15);
    t.SayHello();

    printf("%s", t.GetNameAddr());
    return 0;
}
/*
    PS D:\c++> gcc .\trieOOP.cpp -lstdc++;./a.exe
    system: Trie inited
    I'm Marry, and i am 15 years.
    瘙b
    PS D:\c++>
*/