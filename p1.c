#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(void){
  /* Buffers to store messages */
  char server_message[256] = "You have reached the server!";
  char send_peer[256];
  char client_response[256];
  
  /* A value of 3 indicates a socket was sucessfully created */
  int s;
  /* A value of 4 indicates a connection have been established */
  int client_socket;
  
  /* Create a socket */
  s = socket(AF_INET, SOCK_STREAM, 0);
  
  /* Initialize server information */
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(9002);
  server_address.sin_addr.s_addr = INADDR_ANY;
  
  /* Bind the socket to the server information */
  bind(s, (struct sockaddr *) &server_address, sizeof(server_address));
  
  /* Listen to any Incomming connections */
  listen(s, 5);
  
  /* Accept a Incomming connection from the client */
  client_socket = accept(s, NULL, NULL);
  
  /* Connection established */
  if(client_socket == 4){
    printf("[+] A connection has been established!\n");
  }
  
  /* */
  while(1){
    printf(">>");
    fgets(send_peer, 256, stdin);  
    send(client_socket, send_peer, sizeof(send_peer), 0);
    recv(client_socket, &client_response, sizeof(client_response), 0);
    printf("%s",client_response);
  }
  
  shutdown(s, SHUT_RDWR);

  return 0;
}







