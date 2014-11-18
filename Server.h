#ifndef SERVER_H
#define SERVER_H

#include <string>
#include "types.h"
#include "Book.h"
#include "BookArray.h"

class Server
{
  public:
    Server();
    ~Server();
    void retrieve(BookArray&);
  private:
    Book* books[MAX_COLL_SIZE];
    int   maxIndex;
};

#endif

