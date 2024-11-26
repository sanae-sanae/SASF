#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// hado li fihom # machi comments makaytmashox rah homa li kaydefiniw l9yas dyal les tables dyalna bla bihom ayb9a yw93lk error kima 9tlk
// hado n9dar nbadal lvaleur dyalhim kima bghit

// variable n7sbo  bih bach nb9aw n testiw
#define MAX_TASKS 100
#define TITLE_LEN 50
#define DESC_LEN 200
typedef struct {
    char title[TITLE_LEN]; // tarikh dyal task
    char description[DESC_LEN]; // description
    char dueDate[11]; // tarikh
    char priority[10]; // High or Low
    char status[15];   // Complete or Incomplete
} Task;
Task tasks[MAX_TASKS]; // wa7d tableau anb9aw nkhb3o fih les task dyalna
int taskCount = 0; 
void displayMenu() { //  hadi bayna mn smiya
    printf("\nTask Management Application\n");
    printf("1. Add Task\n");
    printf("2. View Tasks\n");
    printf("3. Modify Task\n");
    printf("4. Delete Task\n");
    printf("5. Filter Tasks by Priority\n");
    printf("6. Filter Tasks by Status\n");
    printf("7. Sort Tasks by Due Date\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
}
void addTask() { // function lwla matreturni walo mais tzid f table li 3ndi dyal task
    if (taskCount >= MAX_TASKS) {  // bach mayzidch ktar mn 100 fdak table 7it c chiya mrid fraso ayb9a yzid ta ytpolonta lk b error
        printf("Task limit reached. Cannot add more tasks.\n");
        return;
    }

    Task t; // case mn dak table wkan3mroha bles info li kaydkhl user
    printf("Enter title: ");
    scanf(" %[^\n]", t.title);
    printf("Enter description: ");
    scanf(" %[^\n]", t.description);
    printf("Enter due date (YYYY-MM-DD): ");
    scanf(" %s", t.dueDate);
    printf("Enter priority (High/Low): ");
    scanf(" %s", t.priority);
    strcpy(t.status, "Incomplete"); // ofc fin ayzidha bla matswlih 7it deja atkon mazal ma complete

    tasks[taskCount++] = t; // kanzido hadchi li 3mrna f table li 3ndna 3la bra
    printf("Task added successfully!\n"); // kan9oloha l user bach yfra7
}


int main() {
    
 int choice;

    do { 
         displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();
                break;
                }
    } while (choice != 8);

    return 0;
}

