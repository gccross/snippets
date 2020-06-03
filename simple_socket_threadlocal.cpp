int sockfd;
pthread_key_t key_to_sockfd;

void error(const char *msg)
{
   perror(msg);
   exit(0);
}


void set_connection(char *argv[])
{

   int portno;
   struct sockaddr_in serv_addr;
   struct hostent *server;

   char buffer[256];
   portno = atoi(argv[2]);
   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   if (sockfd < 0) 
       error("ERROR opening socket");
   server = gethostbyname(argv[1]);
   if (server == NULL) {
       fprintf(stderr,"ERROR, no such host\n");
       exit(0);
 }
bzero((char *) &serv_addr, sizeof(serv_addr));
serv_addr.sin_family = AF_INET;
bcopy((char *)server->h_addr, 
(char *)&serv_addr.sin_addr.s_addr,server->h_length);
serv_addr.sin_port = htons(portno);
if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
    error("ERROR connecting");
return;
}

void send_message()
{
    char buffer[256];
    int i=0,n;
    do{
      printf("Please enter the message: ");
      bzero(buffer,256);
      fgets(buffer,255,stdin);
       n = write(sockfd,buffer,strlen(buffer));
      if (n < 0) 
        error("ERROR writing to socket");
    i++;
 }while(i<3);
bzero(buffer,256);
n = read(sockfd,buffer,255);
if (n < 0) 
     error("ERROR reading from socket");
printf("%s\n",buffer);
return;
}

void disconnect()
{
   close(sockfd);
   return;
}

void client_thrd(char *argv[])
{
  set_connection(argv);
  send_message();
  disconnect();
}
int main(int argc, char *argv[])
{

pthread_t thid[2];  
int i;  
void *status;
if (argc < 3) {
   fprintf(stderr,"usage %s hostname port\n", argv[0]);
   exit(0);
}
for(i=0;i<1;i++)
    pthread_create(&thid[i],NULL,(void*)&client_thrd,(void*)argv);
for(i=0;i<1;i++)
    pthread_join(thid[i],&status);


return 0;
}
