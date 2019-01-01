
#include "csapp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

void getGenre(char genre, int genreid)
{
  if(genre == "action"){
    genreid = 28
      }else if(genre == "adventure"){
    genreid = 12
      }else if(genre == "animation"){
    genreid = 16
      }else if(genre == "comedy"){
    genreid = 35
      }else if(genre == "crime"){
    genreid = 80      
      }else if(genre == "documentary"){
    genreid = 99      
      }else if(genre == "drama"){
    genreid = 18      
      }else if(genre == "family"){
    genreid = 10751      
      }else if(genre == "fantasy"){
    genreid = 14      
      }else if(genre == "history"){
    genreid = 36      
      }else if(genre == "horror"){
    genreid = 27      
      }else if(genre == "music"){
    genreid = 10402      
      }else if(genre == "mystery"){
    genreid = 9648      
      }else if(genre == "romance"){
    genreid = 10749      
      }else if(genre == "science fiction"){
    genreid = 878      
      }else if(genre == "tv movie"){
    genreid = 10770      
      }else if(genre == "thriller"){
    genreid = 53      
      }else if(genre == "war"){
    genreid = 10752      
      }else if(genre == "western"){
    genreid = 37
      }
}

int main()
{

  int actorid;
  int genreid;
  char genre;
  char actorname;

  printf("Welcome to our Movie Application! Please choose a genre and tell us who you'd like to see in a film!");

  /* gets the user input */
  scanf("%s", actorName);
  scanf("%s", genre);
  printf("The actor that you are in the mood for is:", actorName, "The genre you are in the mood for is:", genre);
   
  /* gets the genre */
  getGenre(genre, genreid);
  
  
  /* use search API request to get json that has actor id


https://api.themoviedb.org/3/search/person?api_key=5896d89b88e4261a1d2413a2846e7728&language=en-US&query=firstName%20lastName&page=1&include_adult=false
/*make a local copy of the string that we can manipulate*/
  char *const copy = strdup(actorName);
  char *space = copy;
  /*find the next space in the string, and replace it with a %20*/
  while (space = strchr(space, '')) *space = %20;
  str name = copy;
  url = "https://api.themoviedb.org/3/search/person?api_key=5896d89b88e4261a1d2413a2846e7728&language=en-US&query\
=" + name + "&page=1&include_adult=false";
  
  /*
	Replace spaces with %20
	Plug name into search request
	If valid request:
		-invalid if “total_results”: 0,
		find the first ID using regex

concatinate actor id and genreid into new API request 

https://api.themoviedb.org/3/discover/movie?api_key=5896d89b88e4261a1d2413a2846e7728&language=en-US&with_genres=GENREID&with_cast=ACTORID&sort_by=vote_average.desc



}
