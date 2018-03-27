#ifndef __PONY__
# define __PONY__

class Pony
{
  public:
    static int ponyInstanceNb;
    
    void run(int distance);
    void flapTail(int spinNb);
    Pony();
    ~Pony();
};

void ponyOnTheHeap(void);
void ponyOnTheStack(void);

#endif