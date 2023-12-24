#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_UNDERGRADUATES 350  //Replacing directly in the code during preprocessing

struct Learners {

   int studentId;
   char name[40];
   int age;
   char address[100];
   char contact_no[15];
   char course[20];
   float marks;

   };

struct Learners learners[MAX_UNDERGRADUATES];//Array to store student records
int nubLearners = 0;//To keep track of the number of students

//Function to Login
void login() {
    char u1[5] = "abcd"; // Increase array size to accommodate the null terminator '\0'
    char p1[5] = "1234"; // Increase array size to accommodate the null terminator '\0'
    char u2[10], p2[10]; // Define arrays to store user input
    printf("Enter User Name: ");
    scanf("%9s", u2); // Use %9s to prevent buffer overflow and store user input in u2
    printf("Enter Password: ");
    scanf("%9s", p2); // Use %9s to prevent buffer overflow and store user input in p2

    // Compare strings using strcmp function from string.h
    if (strcmp(u1, u2) == 0 && strcmp(p1, p2) == 0) {
        printf("Login Successful!");
    } else {
        printf("Check Your Password!\n");
        login();
    }
}

//To add new students
void addLearnears() {

if (nubLearners < MAX_UNDERGRADUATES){

    struct Learners newLearners;
    printf("Enter Student ID:\t");
    scanf("%i", &newLearners.studentId);
    printf("\nEnter Name:\t");
    scanf("%39s", &newLearners.name);
    printf("\nEnter Age:\t");
    scanf("%i", &newLearners.age);
    printf("\nEnter Address:\t");
    scanf("%s", &newLearners.address);
    printf("\nEnter Contact Number:\t");
    scanf("%s", &newLearners.contact_no);
    printf("\nEnter Course:\t");
    scanf("%s", &newLearners.course);
    printf("\nEnter Marks:\t");
    scanf("%f", &newLearners.marks);
if(newLearners.marks>=80){
    printf("A+ \n");

}else if(newLearners.marks>60) {
printf("B+ \n");
}else{
printf("D \n");
}
    learners[nubLearners] = newLearners;
    nubLearners++;
    printf("Student added successfully!\n");

}else{
printf("Maximum number of student reached!");
}

}

//Function to Display Learners
void displayLearners(){
if (nubLearners == 0){

    printf("No Learners to Display");
}else{

printf("Student Records\n");
printf("Student ID\tName\t\tAge\t\tAddress\t\tContact Number\t\tCourse\t\tMarks\n");//fix it
for (int i = 0;i <nubLearners;i++){

printf("%i\t\t%5s\t\t%2i\t\t%5s\t\t%5s\t\t%2s\t\t%5f\n",learners[i].studentId, learners[i].name, learners[i].age, learners[i].address,
       learners[i].contact_no, learners[i].course, learners[i].marks);

}

}
}

//To search learners
void searchLearners(){

int ID;
printf("Enter Student ID to search:");
scanf("%d",&ID);

int found = 0;
for (int i = 0;i < nubLearners;i++){

  if (learners[i].studentId == ID){

    printf("Student Found!\n");
    printf("Student Id: %i\nName: %s\nAge: %i\nAddress: %s\nContact Number: %s\nCourse: %s\nMarks: %2f",
           learners[i].studentId, learners[i].name, learners[i].age, learners[i].address,
       learners[i].contact_no, learners[i].course, learners[i].marks);
    found = 1;
    break;

  }

}

if (!found){

 printf("Student with Roll Number %i not found.\n",ID);

}

}

int main(){
    login();
int choice;
do{
    printf("\nSTUDENT INFORMATION MANAGEMENT SYSTEM\n");
    printf("\n1. Add Learners\n");
    printf("\n2. Display All Learners\n");
    printf("\n3. Search Learners\n");
    printf("\n4. Exit\n");
    printf("\nEnter Your Choice\n");
    scanf("%d",&choice);

    switch(choice){
    case 1:
        addLearnears();
        break;
    case 2:
        displayLearners();
        break;
         case 3:
        searchLearners();
        break;
         case 4:
        printf("Exiting............\n");
        break;
    default:
        printf("Invalid choice.Please enter 1 or 2.\n");
    }
}while (choice != 4);
return 0;
}
