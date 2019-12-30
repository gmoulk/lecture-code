///////////////////////////////////////////////////////////////////
//
// ADT Queue
//
// Abstract ουρά. Λειτουργία "First In First Out", δηλαδή σε κάθε
// remove επιστρέφεται το παλιότερο στοιχείο που έγινε insert.
//
///////////////////////////////////////////////////////////////////

#pragma once // #include το πολύ μία φορά

#include "common_types.h"


// Μία ουρά αναπαριστάται από τον τύπο Queue. Ο χρήστης δε χρειάζεται να γνωρίζει το περιεχόμενο
// του τύπου αυτού, απλά χρησιμοποιεί τις συναρτήσεις queue_<foo> που δέχονται και επιστρέφουν Queue.
//
// Ο τύπος Queue ορίζεται ως pointer στο "struct queue" του οποίου το περιεχόμενο είναι άγνωστο
// (incomplete struct), και εξαρτάται από την υλοποίηση του ADT Queue.
//
typedef struct queue* Queue;


// Δημιουργεί και επιστρέφει μια νέα ουρά.

Queue queue_create();

// Επιστρέψει τον αριθμό στοιχείων που περιέχει η ουρά queue

int queue_size(Queue queue);

// Επιστρέφει το στοιχείο στην κορυφή της ουράς (μη ορισμένο αποτέλεσμα αν η ουρά είναι κενή)

Pointer queue_top(Queue queue);

// Προσθέτει την τιμή value στo τέλος της ουράς queue.

void queue_insert(Queue queue, Pointer value);

// Αφαιρεί και επιστρέψει την τιμή στην κορυφή της ουράς (μη ορισμένο αποτέλεσμα αν η ουρά είναι κενή)

Pointer queue_remove(Queue queue);

// Ελευθερώνει όλη τη μνήμη που δεσμεύει η ουρά queue.
// Οποιαδήποτε λειτουργία πάνω στη ουρά μετά το destroy είναι μη ορισμένη.

void queue_destroy(Queue queue);