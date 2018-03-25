/* Cliente sockect. Manda mensagem e imprime resposta! */
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

/*void error(char *msg)
{
  perror(msg);
  exit(0);
}*/

int main(int argc, char *argv[])
{
  
  int sockfd, portno, n;
  char buffer[1024];
  char server_reply[2000];
  
  struct sockaddr_in serv_addr;
  struct hostent *server;

  //sockfd = sockfd(AF_INET, SOCK_STREAM,0);

  /*if (argc < 3) {
    fprintf(stderr,"usage %s hostname port\n", argv[0]);
    exit(0);
  }*/
  
  portno = atoi(argv[2]);
  
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  
  /*if (sockfd == -1)
    perror("ERROR opening socket");
  server = gethostbyname(argv[1]);
  
  if (server == NULL) {
    fprintf(stderr,"ERROR, no such host\n");
    exit(0);
  }*/

  bzero((char*)&serv_addr,sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr,
        (char *)&serv_addr.sin_addr.s_addr,
        server->h_length);
  /*bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  */
  serv_addr.sin_port = htons(portno);
  
  connect(sockfd, (struct sockaddr *), &serv_addr, sizeof(serv_addr));
  /*if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
    perror("ERROR connecting");*/
    
  while(1) {
    printf("Digite a mensagem: ");
    scanf(" %[^\n]s", buffer);

    if (send(sockfd,buffer,strlen(buffer),0) < 0)
    {
      printf("ERROR\n");
      return 1;
    }
    
    if (recv(sockfd,server_reply,2000,0) < 0)
    {
      printf("ERROR\n");
      break;
    }

    printf("Server Reply: %s \n", server_reply);
  }

  close(sockfd);
    
    /*while (1) {
      bzero(buffer,1024);
      scanf(" %[^\n]s", buffer);
      n = write(sockfd,buffer,strlen(buffer));
      
      if (n < 0)
        perror("ERROR writing to socket");
      sleep(1);
      n = recv(sockfd,buffer,1024,0);
      printf("\n%d bytes read\n\n",n);
      printf("Mensagem recebida: %s\n",buffer);
      
      if (n < 0)
        perror("ERROR reading from socket");
      printf("\n");
    }*/
  return 0;
}
