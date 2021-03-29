/*
g++ drill14.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include <iostream>
#include <string>

using std::cout;
using std::string;

struct B1 {
    virtual void vf() { cout << "B1::vf()\n"; }
    void f() { cout << "B1::f()\n"; }
    virtual void pvf() =0;
};

struct D1 : B1 {
    void vf() override { cout << "D1::vf()\n"; }
    void f() { cout << "D1::f()\n"; }
};

struct D2 : D1 {
    void pvf() override { cout << "D2::pvf()\n"; }
};

struct B2 {
    virtual void pvf() =0;
};

struct D21 : B2 {
    string s = "teszt";
    void pvf() override { cout << s << '\n'; }
};

struct D22 : B2 {
    int i = 37;
    void pvf() override { cout << i << '\n'; }
};

void f (B2& b)
{
    b.pvf();
}

int main()
{
    D21 huszonegy;
    D22 huszonketto;

    f(huszonegy);
    f(huszonketto);
}