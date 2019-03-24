#include "Foo.h"
using namespace std;

Foo::Foo()
{
    cout<<"I am a happy constructor that calls myMethod\n";
}

Foo::~Foo()
{
printf("I am a happy destructor that would do cleanup here.\n");
}

void Foo::myMethod1()
{
    cout << "In myMethod1!\n";
}

int main(int argc, char** argv) {
    cout << "Program started!\n";
    Foo* foo = new Foo();
    foo->myMethod1();
    delete foo;

    //references
    int foo3 = 10;
    int& bar = foo3;//bar is a reference of foo3, so changing either bar or foo3, will change the other one as well.

    bar += 20;
    printf("foo3 is: %d\n", foo3);
    printf("bar is: %d\n", bar);

    foo3 = 15;
    printf("foo3 is: %d\n", foo3);
    printf("bar is: %d\n", bar);

    Foo* fooArray = new Foo[4];
    delete[] fooArray;//remember to delete the array: [], not just the variable!

    cout << "Program finished!\n";
}