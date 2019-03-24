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

    //making a local variable from a pointer
    Foo myFooInstance;//create a local variable instance of foo
    Foo* myFooPointer;//declare a pointer to Foo class
    myFooPointer = &myFooInstance;//set the value of the pointer to the address of myFooInstance. "&" means to get the address of a variable
    //this is also the key to remember!!!!
    printf("&myFooInstance: %p\n", &myFooInstance);
    printf("&myFooPointer: %p\n", &myFooPointer);

    printf("myFooInstance.m_variable1: %d\n", myFooInstance.m_variable1);
    printf("myFooPointer->m_variable1 %d\n", myFooPointer->m_variable1);

    // changing either bar or foo3, will change the other one as well.
    myFooInstance.m_variable1 = 123;
    printf("after changing myFooInstance.m_variable1 value:\n");
    printf("myFooInstance.m_variable1: %d\n", myFooInstance.m_variable1);
    printf("myFooPointer->m_variable1 %d\n", myFooPointer->m_variable1);

    // changing either bar or foo3, will change the other one as well.
    myFooPointer->m_variable1 = 456;
    printf("after changing myFooPointer->m_variable1 value:\n");
    printf("myFooInstance.m_variable1: %d\n", myFooInstance.m_variable1);
    printf("myFooPointer->m_variable1 %d\n", myFooPointer->m_variable1);


    printf("\n\nThe other way: making a pointer from a local variable:\n");
    //the other way: making a pointer from a local variable
    Foo* fooPointer = new Foo();//create a pointer to Foo
    Foo myFooInstance2 = *fooPointer;//"*" means to dereference the pointer and then assign it to myFooInstance2; copy is made!
    //at this moment, myFooInstance2 is actually different from fooPointer! They are two different copies!
    //this is key!!!!!!!!! remmeber this! It dereferences the pointer and assigns it to myFooInstance2!!!
    printf("&fooPointer: %p\n", &fooPointer);
    printf("&myFooInstance2: %p\n", &myFooInstance2);

    printf("fooPointer->m_variable2: %d\n", fooPointer->m_variable2);
    printf("myFooInstance2.m_variable2: %d\n", myFooInstance2.m_variable2);

    // They are two different copies! chaging one will not change the other one!
    fooPointer->m_variable2 = 987;
    printf("\n\nafter changing fooPointer->m_variable2 value:\n");
    printf("fooPointer->m_variable2: %d\n", fooPointer->m_variable2);
    printf("myFooInstance2.m_variable2: %d\n", myFooInstance2.m_variable2);

    // They are two different copies! chaging one will not change the other one!
    myFooInstance2.m_variable2 = 654;
    printf("\n\nafter changing myFooInstance2.m_variable2 value:\n");
    printf("fooPointer->m_variable2: %d\n", fooPointer->m_variable2);
    printf("myFooInstance2.m_variable2: %d\n", myFooInstance2.m_variable2);


    cout << "Program finished!\n";
}