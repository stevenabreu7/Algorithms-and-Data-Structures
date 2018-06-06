//at least 8 characters, at least 3 digits

#include <stdio.h>
#include <string.h>

//int checkPassword(char str[]);
int main() {
  char password[40];
  int i, countDigits;
  while (1) {
    printf("enter password: ");
    fgets(password, sizeof(password), stdin);

    if (strcmp(password,"\n") <= 0) {
      return 0;
    }

    countDigits = 0;
    for (i=0;i<strlen(password);i++) {
      if ((password[i] > 47) && (password[i] < 58)) {
        //this is a digit!
        countDigits++;
      }
    }

    //last character is \0 or \n!!!!!!!
    if ((strlen(password) > 8) && (countDigits >= 3)) {
      printf("PASSWORD IS GOOD\n");
    } else {
      printf("PASSWORD IS BAD\n");
    }
  }
  return 0;
}
