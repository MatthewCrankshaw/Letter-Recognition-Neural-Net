#ifndef BACKPROPAGATION_H
#define BACKPROPAGATION_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include <QDebug>

//-----------------------
//file manipulation
#include <QFile>
#include <QTextStream>
#include <QDataStream>
//-----------------------

#include "globalVariables.h"



class Backpropagation
{
public:
    Backpropagation();
    void initialise();
    void saveWeights(QString fileName);
    void loadWeights(QString fileName);
    void feedForward( );
    void backPropagate();
    double sigmoid( double val );
    double sigmoidDerivative( double val );
    void assignRandomWeights( void );
    double trainNetwork(int NUMBER_OF_DESIRED_EPOCHS);
    double getError_SSE();
    int action( double *vector );
    double* testNetwork(LetterStructure testPattern);

private:

    /* Weight Structures */

    /* Input to Hidden Weights (with Biases) */
    double wih[INPUT_NEURONS+1][HIDDEN_NEURONS];

    /* Hidden to Output Weights (with Biases) */
    double who[HIDDEN_NEURONS+1][OUTPUT_NEURONS];

    /* Activations */
    double inputs[INPUT_NEURONS];
    double hidden[HIDDEN_NEURONS];
    double target[OUTPUT_NEURONS];
    double actual[OUTPUT_NEURONS];

    /* Unit Errors */
    double erro[OUTPUT_NEURONS];
    double errh[HIDDEN_NEURONS];

    //-----------------------------------------
    double err;
    int i, sample, iterations;
    int sum;
};

#endif // BACKPROPAGATION_H