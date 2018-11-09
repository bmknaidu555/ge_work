int scani()
 {
     char *temp = NULL;
     temp = (char *) malloc(sizeof(char) * 100);
     __fpurge(stdin);
     fgets(temp,BUFFER, stdin);
     if(!is_Digit(temp)){
         printf("Invalid Input");
         exit(EXIT_FAILURE);
     }   
     return a_to_i(temp);
} 
