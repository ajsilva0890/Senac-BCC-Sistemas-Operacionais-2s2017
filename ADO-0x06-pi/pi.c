#include <semaphore.h>
#include <unistd.h>
#include <iomanip>
#include <cmath>
#include <pthread.h>
#include <iostream>
#include <stdlib.h>

const size_t N = 4;

struct Info
{
	Info() : pi(0) {}

	unsigned pi;
};

void* func(void* param)
{
	double pi, pointsIn = 0,
			   xValue,
			   yValue,
			   totalpoints=1000000,
			   distance;
			   srand(time(NULL));

			   if (Info* info = static_cast<Info*>(param))
	{


		   // Forma par calcular o valor de PI
		   for(int info=0; info<totalpoints; info++)
		   {
		      xValue = (double) rand()/RAND_MAX; //Random ponto: x
		      yValue = (double) rand()/RAND_MAX; //Random ponto: y
		      distance = (xValue * xValue) + (yValue * yValue);
		      if(distance <= 1.0)
		         ++pointsIn;
		   }
		   pi = 4.0 * pointsInTotal/(4 * totalpoints);
	}

	return param;
}

int main()
{
	srand(time(NULL));

	pthread_t handles[N];
	Info info[N];

	// comecar a threads
	for (size_t i = 0; i != 4; ++i)
		pthread_create(&handles[i], NULL, func, &info[i]);

	// aguardando a thread finalizar
	for (size_t i = 0; i != 4; ++i)
		pthread_join(handles[i], NULL);

	// repetindo o processo..
	for (size_t i = 0; i != 4; ++i)
		std::cout << "value[" << i << "] = " << info[i].pi << std::endl;

	return 0;
}
