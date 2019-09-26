#include<stdlib.h>
#include<stdio.h>

int main(int argc, char * * argv) {
  int n;//num if vertices
  int m;//num of edges
  int b;
  int SV;
  int a;

  //printf("Please enter the number of vertices n and the number of edges m and the weight w\n");

  a = scanf("%d%d", &n, &m);

  if( a == 2)
  {
    int graph[n*n];

    for(int i = 0; i < n*n ; i++)
      {
          graph[i]= 0;
      }

    for(int i = 0; i < m; i++)
    {
      int err = readGraphWeighted(n, m, graph);

      if(err == 1)
      {
        printf("Invalid input.\n");
      }
    }

    //printf("please enter the source vertex SV.\n");

    a = scanf("%d", &b);
    if ( a == 1)
    {
      SV = b;
    }
    else
    {
      printf("Invalid input.\n");
      return EXIT_FAILURE;
    }


    int queue[n];
    int D[n];
    int P[n];
    int front = 0;
    int size = 0;
    int thisindex = -1;


    for (int i = 0; i < n; i++)
    {
      D[i]= 9999999; //initialize to large number
      P[i]= -1; // initialize to -1
      D[SV] = 0;
      queue[(front+size)%n] = SV;
      P[SV] = SV;
      size ++;
  //    printf("D is %d\n",D[i] );
    }

      while(size !=0)
      {

        int val = queue[front];
        front  = (front + 1)%n;
        size--;
        for(int i = SV; i < n ; i++ )
        {

          for(int j = SV ; j < n; j++)
          {

            if(graph[i*n+j] != 0)
            {

              if(D[j] > (D[i] + graph[i*n+j]) )
              {
            //    printf("SDJKHFSF\n" );
                D[j] = D[i] + graph[i*n+j];
                P[j] = i;

            //          printf("D at i is %d\n",D[i] );

              //  D[n] = D[i] + graph[i*n+j];
            //    P[n] = i;

                for(int k = 0; k < size; k++)
                {
                  if(queue[k] == j)
                  {
                    thisindex = 1;
                  }
                }
                if(thisindex < 0)
                {
                  queue[(front+size)%n] = j;
                  size++;
                }

              }
            }
          }
        }
      }

    printf("source vertex: %d\n", SV);

    printf("P: ");

    for(int i = 0; i < n; i++)
    {
      printf("%d ", P[i]);

    }
    printf("\nD: ");

    for(int i = 0; i < n; i++)
    {
      printf("%d ", D[i]);
    }

  }
  else
  {
    printf("Invalid input.\n");
    return EXIT_FAILURE;
  }











}//end of main


int readGraphWeighted(int n, int m, int graph[])
{
    int a;

    int b;

    int c;

    int err = scanf("%d%d%d", &a, &b, &c);

    if(err == 3)
    {
        graph[a*n+b] = c;
        return 0;
    }
    else
    {
        return 1;
    }


}
