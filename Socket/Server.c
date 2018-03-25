/* Servidor socket em C escutando na porta 3141 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <pthread.h>

const int PORT=3141;

void *server_handler(void* fd_pointer)
{
  printf("Hello...\n");
  int sock = *(int *)fd_pointer;
  int read_size, write_size;
  char *menssge;
  static char client_message[2000];

  static int send_once = 0;
  if (send_once < 1)
  {
    send_once++;
  }
  
  while((read_size = recv(sock, client_message,2000,0)) > 0){
    printf("read_size %d\n", read_size);
    write(sock, client_message, strlen(client_message));
  }

  if (read_size == 0)
    fflush(stdout);

  else if (read_size == -1)
  {
    perror("failed");
  }
  free(fd_pointer);

  return 0;
}

/*void error(char *msg){
  perror(msg);
  exit(1);
}*/

int main(){
  
  int sockfd, *newsockfd, connfd;
  socklen_t clilen;
  struct sockaddr_in serv_addr, cli_addr;
  //char buffer[1024];
  //int n;
  
  //sockfd == listenfd;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  
  if (sockfd == -1)
    perror("Erro na criação do socket\n");
  
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(PORT);
  
  if (bind(sockfd, (struct sockaddr *) &serv_addr,
           sizeof(serv_addr)) < 0)
    perror("ERRO ao tentar fazer binding");
  
  listen(sockfd,5);
  clilen = sizeof(cli_addr);
  
  while((connfd = accept(sockfd, (struct sockaddr*)&cli_addr)&clilen)){
    
    pthread_t server_thread;
    newsockfd = malloc(1);
    *newsockfd = connfd;
    pthread_create(&server_thread, NULL, server_handler,(void*)newsockfd);

    /*newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    
    if (newsockfd < 0)
      error("ERRO ao tentar aceitar uma coneção");
    
    while(1){
      bzero(buffer,1024);
      n = read(newsockfd,buffer,1024);
      
      if (n < 0)
        error("ERROR Ao tentar ler do socket");
      printf("Mensagem recebida: %s\n",buffer);
      scanf(" %[^\n]s", buffer);
      n = write(newsockfd,buffer,strlen(buffer));
      
      if (n < 0)
        error("ERROR ao tentar escrever no socket");
      }*/ 
  }

  if (connfd < 0)
  {
    perror("Acesso failed");
    return 1;
  }
  return 0;
}

