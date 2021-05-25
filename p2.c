#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <string.h>
int main(void){
  char server_response[256];
  char client_message[256] = "You did a great job!";
  char send_peer[256];
  int s;
  
  /* Create a socket */
  s = socket(AF_INET, SOCK_STREAM, 0);
  
  /* Initialize server information */
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(9002);
  server_address.sin_addr.s_addr = INADDR_ANY;
  
  /* Connect to address and port number defined in 'server_address' */
  int connection_status = connect(s, (struct sockaddr *) &server_address, sizeof(server_address));
  
  if(connection_status == -1){
    printf("Error: Connection could not be established.\n");
  }
  else {
    printf("[+] A connection has been established!\n");
  }

  while(1){
    recv(s, &server_response, sizeof(server_response), 0);
    printf("%s", server_response);
    printf(">>");
    fgets(send_peer, 256, stdin);
    send(s, send_peer, sizeof(send_peer), 0);
  }
  
  shutdown(s, SHUT_RDWR);
  
  return 0;
}
