/*
 * echoclient.c - An echo client
 */
/* $begin echoclientmain */
#include "csapp.h"

int main(int argc, char **argv) 
{
    int clientfd;
    char *host, *port, buf[MAXLINE];
    rio_t rio;
    str host = "https://api.themoviedb.org/3/discover/movie?api_key=5896d89b88e4261a1d2413a2846e7728&language=en-US&with_genres=18&with_cast=23659&sort_by=vote_average.desc";
    str port = 3;
    str request =
      
    if (argc != 3) {
	fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);
	exit(0);
    }
    host = argv[1];
    port = argv[2];

    clientfd = Open_clientfd(host, port);
    Rio_readinitb(&rio, clientfd);

    while (Fgets(buf, MAXLINE, stdin) != NULL) {
      //writes it to the client fd, which is the network connection
      
	Rio_writen(clientfd, buf, strlen(buf));
	Rio_readlineb(&rio, buf, MAXLINE);
	//puts string to standard out
	Fputs(buf, stdout);
    }
    Close(clientfd); //line:netp:echoclient:close
    exit(0);
}

/* $end echoclientmain */
