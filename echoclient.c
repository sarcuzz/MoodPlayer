#include "csapp.h"                                                      
                                                                                    int main(int argc, char **argv)                                                    
{                                                                                                        
    int clientfd;                                                                                        
    char *host, *port, buf[MAXLINE];                                                                     
    rio_t rio;                                                                                           
    host = "api.themoviedb.org";                                                                         
    port = "80";                                                                                         
    buf[MAXLINE]  = "GET https://api.themoviedb.org/3/discover/movie?api_key=5896d89b88e4261a1d2413a2846e7728&lan\
guage=en-US&with_genres=18&with_cast=23659&sort_by=vote_average.desc\n";                                 
    clientfd = Open_clientfd(host, port);                                                                
    Rio_readinitb(&rio, clientfd);                                                                       
    /*the request*/                                                                     Rio_writen(clientfd, buf, strlen(buf));
    Rio_readlineb(&rio, buf, MAXLINE);                                                                   
      //writes it to the client fd, which is the network connection                              
    Rio_writen(clientfd, buf, strlen(buf));                                                          
    Rio_readlineb(&rio, buf, MAXLINE);                                                       
        //puts string to standard out                                                                    
     //6ce621bb5b187f8856ac2f015cff7fd4213258fe                                                 
      Fputs(buf, stdout);
      //}                                                                                                
    Close(clientfd); //line:netp:echoclient:close                                                        
    exit(0);
}
