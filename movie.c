
#include "csapp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

  int *actorid;
  int genreid;
  char *actorname;
  char *genre;
  char *buf, *p;
  char arg1[MAXLINE], arg2[MAXLINE], content[MAXLINE];
  char *host, request[100000], save[1000000],end[1000000], *port;
  int clientfd;
  
  
  // Extract the two arguments 
    if ((buf = getenv("QUERY_STRING")) != NULL) {
        p = strchr(buf, '&');
        *p = '\0';
        strcpy(arg1, buf);
        strcpy(arg2, p+1);
        actorname = (char *) arg1;
        genre =  (char *) arg2;
    }

    // gets the genre */
    //    genreid = getGenre(genre, genreid);
   
    // getting genre id 
    if(strcmp(genre,"genre=action")==0){
    genreid = 28;
    }else if(strcmp(genre,"genre=adventure")==0){
    genreid = 12;
    }else if(strcmp(genre,"genre=animation")==0){
    genreid = 16;
    }else if(strcmp(genre,"genre=comedy")==0){
    genreid = 35;
    }else if(strcmp(genre,"genre=crime")==0){
    genreid = 80;
  }else if(strcmp(genre,"genre=documentary")==0){
    genreid = 99;
      }else if(strcmp(genre,"genre=drama")==0){
    genreid = 18;
      }else if(strcmp(genre,"genre=family")==0){
    genreid = 10751;
      }else if(strcmp(genre,"genre=fantasy")==0){
    genreid = 14;
      }else if(strcmp(genre,"genre=history")==0){
    genreid = 36;
      }else if(strcmp(genre,"genre=horror")==0){
    genreid = 27;
      }else if(strcmp(genre,"genre=music")==0){
    genreid = 10402;
      }else if(strcmp(genre,"genre=mystery")==0){
    genreid = 9648;
      }else if(strcmp(genre,"genre=romance")==0){
    genreid = 10749;
      }else if(strcmp(genre,"genre=science+fiction")==0){
    genreid = 878;
      }else if(strcmp(genre,"genre=tv+movie")==0){
    genreid = 10770;
      }else if(strcmp(genre,"genre=thriller")==0){
    genreid = 53;
      }else if(strcmp(genre,"genre=war")==0){
    genreid = 10752;
      }else if(strcmp(genre,"genre=western")==0){
    genreid = 37;
      }
    
int new_string_length = 0;
for (char *c = actorname; *c != '\0'; c++) {
    if (*c == '+') new_string_length += 2;
    new_string_length++;
}
char *actornew = malloc((new_string_length + 1) * sizeof actornew[0]);
char *c1, *c2;
for (c1 = actorname, c2 = actornew; *c1 != '\0'; c1++) {
    if (*c1 == '+') {
        c2[0] = '%';
        c2[1] = '2';
        c2[2] = '0';
        c2 += 3;
    }else{
        *c2 = *c1;
        c2++;
    }
}
*c2 = '\0';

 sprintf(request, "GET /3/search/person?api_key=5896d89b88e4261a1d2413a2846e7728&language=en-US&query=%s&page=1&include_adult=false",actornew);

 rio_t rio;
 host = "https:https://api.themoviedb.org";
 port = "80";

 clientfd = Open_clientfd(host,port);
 Rio_readinitb(&rio,clientfd);

 if (clientfd == -1){
   printf("Failed connection");
 }

 Rio_readlineb(&rio, save, MAXLINE);
 sprintf(content,"%s%s\n",content,save);
  
	  

 

  /* use search API request to get json that has actor id                                                                                                      
https://api.themoviedb.org/3/search/person?api_key=5896d89b88e4261a1d2413a2846e7728&language=en\
-US&query=firstName%20lastName&page=1&include_adult=false                                       
  char url[200];
  /*  strcpy(url,"https://api.themoviedb.org/3/search/person?api_key=5896d89b88e4261a1d2413a2846e77 \
28&language=en-US&query=");
  strcat(url, actorname);
  strcat(url, "&page=1&include_adult=false");
  strcat(url, '\0');

  */
  sprintf(content, "Welcome to our Movie Application! Please choose a genre and tell us who you'd like to see in a film!");

  /* gets the user input */
  /*scanf("%s", actorName);
    scanf("%s", genre);*/
  sprintf(content, "%s The actor that you are in the mood for is: %s ",content, actornew);
  sprintf(content, "%s The genre you are in the mood for is: %d", content,genreid);

  sprintf(content, "%s /n  Actorname: %s, Genre: %s, Genreid: %d", content, actornew, genre, genreid);
  
  printf("Connection: close\r\n");
  printf("Content-length: %d\r\n", (int)strlen(content));
  printf("Content-type: text/html\r\n\r\n");
  printf("%s", content);
  fflush(stdout);
  /*
	Replace spaces with %20
	Plug name into search request
	If valid request:
		-invalid if “total_results”: 0,
		find the first ID using regex

concatinate actor id and genreid into new API request 

https://api.themoviedb.org/3/discover/movie?api_key=5896d89b88e4261a1d2413a2846e7728&language=en-US&with_genres=GENREID&with_cast=ACTORID&sort_by=vote_average.desc
  */

  exit(0);

}
