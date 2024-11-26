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

void viewTasks() {
    if (taskCount == 0) {
        printf("No tasks available.\n"); // bach maykonch error y9ad ybghi ychof whowa ma3ndo walo kandiro test sghir drif
        return;
    }

    printf("\nList of Tasks:\n");
    for (int i = 0; i < taskCount; i++) { // ila kan 3ndo kandiro loop for bach twrina ga3 dakchi li 3ndo w7da bw7da
        printf("\nTask %d:\n", i + 1);
        printf("Title: %s\n", tasks[i].title);
        printf("Description: %s\n", tasks[i].description);
        printf("Due Date: %s\n", tasks[i].dueDate);
        printf("Priority: %s\n", tasks[i].priority);
        printf("Status: %s\n", tasks[i].status);
    }
}
void modifyTask() {
    int index;
    viewTasks();
    if (taskCount == 0) return;

    printf("Enter the task number to modify: ");
    scanf("%d", &index); // dak & raha kat3tina adress fl memoire li haza index

    if (index < 1 || index > taskCount) {
        printf("Invalid task number.\n");
        return;
    }

    index--; // c katbda l7sab mn 0 alors l user mklkh maghay3rfch hadchi howa aybda l7sab mn 1 donc 7na chno ma dkhal kan9so mno 1 bach njiboha 3bar
    printf("Modifying Task %d:\n", index + 1);
    printf("Enter new description: ");
    scanf(" %[^\n]", tasks[index].description);
    printf("Enter new due date (YYYY-MM-DD): ");
    scanf(" %s", tasks[index].dueDate);
    printf("Enter new priority (High/Low): ");
    scanf(" %s", tasks[index].priority);
    printf("Enter new status (Complete/Incomplete): ");
    scanf(" %s", tasks[index].status);

    printf("Task updated successfully!\n");
}

void deleteTask() {
    int index;
    viewTasks();
    if (taskCount == 0) return;

    printf("Enter the task number to delete: ");
    scanf("%d", &index);

    if (index < 1 || index > taskCount) {
        printf("Invalid task number.\n");
        return;
    }

    index--; // nfs concept dyal modify kfr9 gna anms7o wsf
    for (int i = index; i < taskCount - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    taskCount--; // hna an9as  mn l7sab dyal tasks 7it rah ms7 w7da
    printf("Task deleted successfully!\n");
}
void filterTasksByStatus() {  // hadi copy coller lokhra mbdal ghi argument wsf
    char status[15];
    printf("Enter status to filter (Complete/Incomplete): ");
    scanf(" %s", status);

    printf("\nFiltered Tasks by Status (%s):\n", status);
    int found = 0;
    for (int i = 0; i < taskCount; i++) {
        if (strcmp(tasks[i].status, status) == 0) { //The strcmp() compares two strings character by character
        //If the strings are equal, the function returns 0.


            printf("\nTask %d:\n", i + 1);
            printf("Title: %s\n", tasks[i].title);
            printf("Description: %s\n", tasks[i].description);
            printf("Due Date: %s\n", tasks[i].dueDate);
            printf("Priority: %s\n", tasks[i].priority);
            printf("Status: %s\n", tasks[i].status);
            found = 1;
        }
    }
    if (!found) {
        printf("No tasks found with the given status.\n");
    }
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
                 case 2:
                viewTasks();
                break;
                 case 3:
                modifyTask();
                break;
                 case 4:
                deleteTask();
                break;
                 case 5:
                filterTasksByPriority();
                break;
                }
    } while (choice != 8);

    return 0;
}

