/**
 * Demo program for ADT exercise.
 *
 * Author: Evgeny Hershkovitch Neiterman
 * Since : 2023-02
 */

#include "AdptArray.h"
#include "book.h"
#include "Person.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int main() {
    // Overwrite another element (person in this case)
    pperson pp1 = creat_person("Yonatan","Amosi", 111);
    pperson pp2 = creat_person("Evgeny","Neiterman", 222);
    pperson pp3 = creat_person("Herut","Benjamin", 333);
    PAdptArray Session_caracters = CreateAdptArray(copy_person,delete_person,print_person);
    SetAdptArrayAt(Session_caracters,1,pp1);
    SetAdptArrayAt(Session_caracters,10,pp2);
    SetAdptArrayAt(Session_caracters,10,pp3);
    printf("the size is %d\n",GetAdptArraySize(Session_caracters)); // prints 11
    PrintDB(Session_caracters); // prints:
    //first name: Yonatan last name: Amosi id: 111
    //first name: Herut last name: Benjamin id: 333
    DeleteAdptArray(Session_caracters);
    delete_person(pp1);
    delete_person(pp2);
    delete_person(pp3);


    // Access to NULL element in array
    pbook bb1 = creat_book("How to get good grades",1222) ;
    pbook bb2= creat_book("How not to die and get good grades", 3222) ;
    PAdptArray myGreatBooks = CreateAdptArray(copy_book,delete_book,print_book);
    SetAdptArrayAt(myGreatBooks,4,bb1);
    SetAdptArrayAt(myGreatBooks,7,bb2);
    pbook b_ = GetAdptArrayAt(myGreatBooks,5); // should return null;
    assert(b_==NULL); // doesn't fail
    b_ = GetAdptArrayAt(myGreatBooks,10);
    DeleteAdptArray(myGreatBooks);
    delete_book(bb1);
    delete_book(bb2);

    // Use DeleteAdptArray on empty array
    PAdptArray myBooksForReal = CreateAdptArray(copy_book,delete_book,print_book);
    DeleteAdptArray(myBooksForReal);// doesn't fail (return;)

    // Access to non-exist element in array
    pbook b1 = creat_book("harry Potter",12345) ;
    pbook b2= creat_book("C intro", 45678) ;
    PAdptArray mybooks = CreateAdptArray(copy_book,delete_book,print_book);
    SetAdptArrayAt(mybooks,3,b1);
    SetAdptArrayAt(mybooks,5,b2);
    printf("the size is %d\n",GetAdptArraySize(mybooks));  //should print 6
    pbook b = GetAdptArrayAt(mybooks,4); // should return null;
    assert(b==NULL); // doesn't fail
    b = GetAdptArrayAt(mybooks,7); // should also return null
    assert(b==NULL); // doesn't fail
    b = GetAdptArrayAt(mybooks,3);
    DeleteAdptArray(mybooks);
    delete_book(b1);
    delete_book(b2);
    delete_book(b);

    // Use SetAdptArrayAt with negative index (should FAIL)
    pperson mom = creat_person("my","mom", 212);
    pperson dad = creat_person("my","dad", 313);
    PAdptArray my_fam = CreateAdptArray(copy_person,delete_person,print_person);
    SetAdptArrayAt(my_fam,1,dad);
    assert(SetAdptArrayAt(my_fam,1,dad)==SUCCESS);// doesn't fail
    assert(SetAdptArrayAt(my_fam,-1,mom)==FAIL);// doesn't fail
    /// Given Demo

//    printf("the book is %s\n",b->name); //should print "Harry Potter"
//    PrintDB(mybooks);
//
//    pperson p1 = creat_person("Harry","Potter", 934);
//    pperson p2 = creat_person("Ron","Weasley", 789);
//    PAdptArray HP_caracters = CreateAdptArray(copy_person,delete_person,print_person);
//    SetAdptArrayAt(HP_caracters,2,p1);
//    SetAdptArrayAt(HP_caracters,8,p2);
//    printf("the size is %d\n",GetAdptArraySize(HP_caracters)); // prints 9
//    PrintDB(HP_caracters); // prints:
//    //first name: Harry last name: Potter id: 934
//    //first name: Ron last name: Weasley id: 789
//
//    DeleteAdptArray(mybooks);
//    DeleteAdptArray(HP_caracters);
//    delete_book(b1);
//    delete_book(b2);
//    delete_book(b);
//    delete_person(p1);
//    delete_person(p2);
    return 0;
}