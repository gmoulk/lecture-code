///////////////////////////////////////////////////////////////////////
//
// Υλοποίηση του ADT Stack μέσω του ADT List (dependent data structure)
//
///////////////////////////////////////////////////////////////////////

#include "stdlib.h"
#include "assert.h"

#include "ADTList.h"
#include "ADTStack.h"


// Μια στοίβα είναι απλά μια λίστα, αλλά το Stack (pointer σε struct stack) είναι διαφορετικός pointer
// από το List (pointer σε struct list). Εχουμε 2 επιλογές:
//
// 1. (Η πιο "καθαρή") Να φτιάξουμε το struct stack ως εξής
//		struct stack {
//			List list;
//		};
//    και στο πεδίο "list" να αποθηκεύσουμε τη λίστα.
//
// 2. (Η πιο "άμεση"). Να χρησιμοποιούμε απευθείας ένα List ως Stack, κάνοντας cast τον pointer.
//    Το cast δεν αλλάζει την τιμή του pointer
//
// Στον παρακάτω κώδικα επιλέγουμε τη δεύτερη λύση (δες το ADTQueue.c για την πρώτη).



Stack stack_create() {
	// Η list_create επιστρέφει ένα List. Εμείς λέμε στον compiler να θεωρήσει τον pointer αυτόν ως Stack
	List list = list_create();
	return (Stack)list;
}

int stack_size(Stack stack) {
	List list = (List)stack;			// το stack είναι στην πραγματικότητα ένα List, αφού ο μόνος τρόπος δημιουργίας είναι με την start_create()
	return list_size(list);
}

Pointer stack_top(Stack stack) {
	List list = (List)stack;
	return list_get(list, list_first(list));
}

void stack_insert(Stack stack, Pointer value) {
	List list = (List)stack;
	list_insert_after(list, NULL, value);
}

Pointer stack_remove(Stack stack) {
	List list = (List)stack;

	Pointer result = stack_top(stack);	// Αποθήκευση πριν κάνουμε remove
	list_remove_after(list, NULL);

	return result;
}

void stack_destroy(Stack stack) {
	List list = (List)stack;
	list_destroy(list);
}