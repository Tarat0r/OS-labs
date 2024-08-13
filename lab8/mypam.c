#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <security/pam_appl.h>
#include <security/pam_modules.h>
#include <time.h>

#define FILENAME "/var/lib/pam/words"

/* expected hook */
PAM_EXTERN int pam_sm_setcred( pam_handle_t *pamh, int flags, int argc, const char **argv ) {
    return PAM_SUCCESS;
}



PAM_EXTERN int pam_sm_acct_mgmt(pam_handle_t *pamh, int flags, int argc, const char **argv) {
    printf("ACCEPT\n");
    return PAM_SUCCESS;
}

PAM_EXTERN int pam_sm_authenticate( pam_handle_t *pamh, int flags,int argc, const char **argv ) {

    int retval;
    const char* pUsername;
    retval = pam_get_user(pamh, &pUsername, "Username: ");

    printf("Welcome %s\n", pUsername);

    if (retval != PAM_SUCCESS) {
   	 return retval;
    }

    if (strcmp(pUsername, "test2") == 0) {
   	 printf("test2 is not allowed\n\n");
   	 return PAM_PERM_DENIED;
    }

    
     time_t t;
     int r;

  	 srand((unsigned) time(&t));

     char *line_buf = NULL;
     size_t line_buf_size = 0;
     int line_count = 0;
     ssize_t line_size;
     FILE *fp = fopen(FILENAME, "r");
     if (!fp){
   	 fprintf(stderr, "Error opening file '%s'\n", FILENAME);
   	 return EXIT_FAILURE;
     }

    r = rand() % 200;
    for (size_t i = 0; i < r + 1; i++){
   	 line_count++;
   	 line_size = getline(&line_buf, &line_buf_size, fp);
    }
    //printf("N:%d %s",line_count, line_buf);
    fclose(fp);

    line_size--;
    char str1[line_size];

    strcpy(str1, line_buf);
    printf("\nOrder the word!\n");
    for (size_t i = 0; i < line_size; i++) {
   	 r = rand() % line_size;

   	 if (str1[r] != '1') {
   		 printf("%c", str1[r]);
   		 str1[r] = '1';
   	 }
   	 else i--;
    }
    printf("\nWrite the answer: ");
    fgets(str1, line_size+2,stdin);
    sscanf(str1,"%s",str1);
    strcat(str1, "\n");
    if (strcmp(str1, line_buf) == 0) {
   	 printf("Correct!\n");
   	 free(line_buf);
   	 line_buf = NULL;
   	 return PAM_SUCCESS;
    }
    else{
    printf("Incorrect!\n");
    free(line_buf);
    line_buf = NULL;
    return PAM_PERM_DENIED;
    }
}