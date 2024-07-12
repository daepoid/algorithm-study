#include <cstring>
#include <iostream>
using namespace std;

struct Student_Info {
  long long int age = 0;
  char name[21];
};

Student_Info student[3];  // 임시, 어림 , 늙음

void copy_info(int i, int j) {
  student[i].age = student[j].age;
  strcpy(student[i].name, student[j].name);
}

int main() {
  int number_of_student = 0;
  scanf("%d", &number_of_student);
  for (int i = 0; i < number_of_student; i++) {
    int day, month, year;
    scanf("%s %d %d %d", student[0].name, &day, &month, &year);
    student[0].age = year * 10000 + month * 100 + day;

    if (i == 0) {
      copy_info(1, 0);
      copy_info(2, 0);
      continue;
    }
    if (student[1].age < student[0].age) {
      copy_info(1, 0);
    } else if (student[2].age > student[0].age) {
      copy_info(2, 0);
    }
  }
  printf("%s\n%s", student[1].name, student[2].name);
}