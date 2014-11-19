#ifndef SERVER_H
#define SERVER_H

#include <string>
#include "Book.h"
#include "BookArray.h"

class Server
{
  public:
    Server();
    ~Server();
    void retrieve(BookArray&);
  private:
    Book* books[1024];
    int   maxIndex;
};

#endif

