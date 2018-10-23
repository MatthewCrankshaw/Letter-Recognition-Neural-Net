#include "backpropagation.h"


#define sqr(x)	((x) * (x))

//FILE *out;

//#define LEARN_RATE		0.2

#define RAND_WEIGHT	( ((float)rand() / (float)RAND_MAX) - 0.5)

#define getSRand()	((float)rand() / (float)RAND_MAX)
#define getRand(x)      (int)((float)(x)*rand()/(RAND_MAX+1.0))


///////////////////////////////////////////////////////////////////

Backpropagation::Backpropagation()
{
   initialise();
}

void Backpropagation::initialise()
{
    sse=0;
    rmse=0;
    mse=0;
    mae=0;
    pgood=0;
    sample=0;
    iterations=0;
    sum = 0;


    /* Seed the random number generator */
    srand( time(NULL) );

    assignRandomWeights();
}

double Backpropagation::getError_SSE(){
    return sse;
}

double Backpropagation::getError_RMSE(){
    return rmse;
}

double Backpropagation::getError_MSE(){
    return mse;
}

double Backpropagation::getError_PG(){
    return pgood;
}


////for debugging - very good
//void Backpropagation::saveWeights(){
//    int out, hid, inp;

//    QFile file3("weights.txt");
//    file3.open(QIODevice::WriteOnly | QIODevice::Text);

//    QTextStream out3(&file3);

//    char tempBuffer3[80];
//    QByteArray temp3;

//    //----------------------------------------------
//    // weights
//    //

//    qDebug() << "updating weights...";
//    qDebug() << "OUTPUT_NEURONS = " << OUTPUT_NEURONS;
//    qDebug() << "HIDDEN_NEURONS = " << HIDDEN_NEURONS;
//    qDebug() << "INPUT_NEURONS = " << INPUT_NEURONS;

//    // Update the weights for the output layer (step 4 for output cell)
//    for (out = 0 ; out < OUTPUT_NEURONS ; out++) {
//      temp3.clear();
//      for (hid = 0 ; hid < HIDDEN_NEURONS ; hid++) {
//          //---save------------------------------------


//            ::sprintf(tempBuffer3,"who[%d][%d]=%f , ",hid,out,who[hid][out]);
//            temp3.append(tempBuffer3);

//          //---------------------------------------
//      }

//      // Update the Bias
//      //---save------------------------------------
//        ::sprintf(tempBuffer3,"who[%d][%d]=%f",HIDDEN_NEURONS,out,who[HIDDEN_NEURONS][out]);
//        temp3.append(tempBuffer3);
//        temp3.append("\n");
//        out3 << temp3;

//      //---------------------------------------

//    }

//    // Update the weights for the hidden layer (step 4 for hidden cell)
//    for (hid = 0 ; hid < HIDDEN_NEURONS ; hid++) {
//      temp3.clear();
//      for (inp = 0 ; inp < INPUT_NEURONS ; inp++) {

//        //---save------------------------------------


//          ::sprintf(tempBuffer3,"wih[%d][%d]=%f , ",inp,hid,wih[inp][hid]);
//          temp3.append(tempBuffer3);

//        //---------------------------------------
//      }

//      // Update the Bias
//      //---save------------------------------------
//        ::sprintf(tempBuffer3,"wih[%d][%d]=%f",INPUT_NEURONS,hid,wih[INPUT_NEURONS][hid]);
//        temp3.append(tempBuffer3);
//        temp3.append("\n");
//        out3 << temp3;

//      //---------------------------------------

//    }

//    //----------------------------------------------


//    file3.close();
//    qDebug() << "Weights saved to file.";
//}



void Backpropagation::saveWeights(QString fileName){
    int out, hid, inp;

    QFile file3(fileName);
    file3.open(QIODevice::WriteOnly | QIODevice::Text);

    QTextStream out3(&file3);

    char tempBuffer3[80];
    QByteArray temp3;

    //----------------------------------------------
    // weights
    //

    qDebug() << "updating weights...";
    qDebug() << "OUTPUT_NEURONS = " << OUTPUT_NEURONS;
    qDebug() << "HIDDEN_NEURONS = " << HIDDEN_NEURONS;
    qDebug() << "INPUT_NEURONS = " << INPUT_NEURONS;

    // Update the weights for the output layer (step 4 for output cell)
    for (out = 0 ; out < OUTPUT_NEURONS ; out++) {
      temp3.clear();
      for (hid = 0 ; hid < HIDDEN_NEURONS ; hid++) {
          //---save------------------------------------


            ::sprintf(tempBuffer3,"%f,",who[hid][out]);
            temp3.append(tempBuffer3);

          //---------------------------------------
      }

      // Update the Bias
      //---save------------------------------------
        ::sprintf(tempBuffer3,"%f",who[HIDDEN_NEURONS][out]);
        temp3.append(tempBuffer3);
        temp3.append("\n");
        out3 << temp3;

      //---------------------------------------

    }

    // Update the weights for the hidden layer (step 4 for hidden cell)
    for (hid = 0 ; hid < HIDDEN_NEURONS ; hid++) {
      temp3.clear();
      for (inp = 0 ; inp < INPUT_NEURONS ; inp++) {

        //---save------------------------------------


          ::sprintf(tempBuffer3,"%f,",wih[inp][hid]);
          temp3.append(tempBuffer3);

        //---------------------------------------
      }

      // Update the Bias
      //---save------------------------------------
        ::sprintf(tempBuffer3,"%f",wih[INPUT_NEURONS][hid]);
        temp3.append(tempBuffer3);
        temp3.append("\n");
        out3 << temp3;

      //---------------------------------------

    }

    //----------------------------------------------


    file3.close();
    qDebug() << "Weights saved to file.";
}


void Backpropagation::loadWeights(QString fileName){
    int out, hid, inp;

    QFile file3(fileName);
    file3.open(QIODevice::ReadOnly | QIODevice::Text);

    if(!file3.exists()){
        qDebug() << "Backpropagation::loadWeights-file does not exist!";
        return;
    }

    QTextStream in(&file3);

    char tChar;
    char tempBuffer3[80];
    QByteArray temp3;

    //----------------------------------------------
    // weights
    //

    QString strLine;
    //QTextStream streamLine;



    qDebug() << "loading weights...";
    qDebug() << "OUTPUT_NEURONS = " << OUTPUT_NEURONS;
    qDebug() << "HIDDEN_NEURONS = " << HIDDEN_NEURONS;
    qDebug() << "INPUT_NEURONS = " << INPUT_NEURONS;

    // Update the weights for the output layer (step 4 for output cell)
    for (out = 0 ; out < OUTPUT_NEURONS ; out++) {
      strLine = in.readLine();
      QTextStream streamLine(&strLine);

      for (hid = 0 ; hid <= HIDDEN_NEURONS ; hid++) {
          //---load------------------------------------

            if(hid != HIDDEN_NEURONS-1){
               streamLine >> who[hid][out] >> tChar;
            } else {
               streamLine >> who[hid][out];
            }


          //---------------------------------------
      }

      // Update the Bias
      //---load------------------------------------

        streamLine >> who[HIDDEN_NEURONS][out];// >> tChar;


      //---------------------------------------

    }

    /* Update the weights for the hidden layer (step 4 for hidden cell) */
    for (hid = 0 ; hid < HIDDEN_NEURONS ; hid++) {

      for (inp = 0 ; inp < INPUT_NEURONS ; inp++) {

        //---load------------------------------------
          if(hid != INPUT_NEURONS-1){
             in >> wih[inp][hid] >> tChar;
          } else {
             in >> wih[inp][hid];
          }

        //---------------------------------------
      }

      // Update the Bias
      //---load------------------------------------
        in >> wih[INPUT_NEURONS][hid] >> tChar;

      //---------------------------------------

    }

    //----------------------------------------------


    file3.close();
    qDebug() << "Weights loaded.";
}

int Backpropagation::action( double *vector )
{
  int index, sel;
  double max;

  sel = 0;
  max = vector[sel];

  for (index = 1 ; index < OUTPUT_NEURONS ; index++) {
    if (vector[index] > max) {
      max = vector[index]; sel = index;
    }
  }
  return( sel );
}

double* Backpropagation::testNetwork(LetterStructure testPattern){
    //retrieve input patterns
    for(int j=0; j < INPUT_NEURONS; j++){
       inputs[j] = testPattern.f[j];
//       qDebug() << "f[" << j << "] = " << inputs[j];
    }

    for(int i=0; i < OUTPUT_NEURONS; i++){
        target[i] = testPattern.outputs[i];
//        qDebug() << "desired_output[" << i << "] = " << target[i];
    }

    feedForward();


//    for (int out = 0 ; out < OUTPUT_NEURONS ; out++) {

//       qDebug() << "Output[" << out << "] = " << actual[out];

//    }

    return actual;


}


double Backpropagation::trainNetwork(int NUMBER_OF_DESIRED_EPOCHS)
{
    if(!patternsLoadedFromFile) {
        qDebug() << "unable to train network, no training patterns loaded.";
        return -999.99;
    }
    double accumulatedSSE=0.0;
    iterations=0;
    int epochs=0;

    //initialise error counters
    sse = 0.0;
    mse = 0.0;

    while (1) {
        if (++sample == NUMBER_OF_TRAINING_PATTERNS) {
            sample = 0;
            sse = 0.0;
            epochs++;
        }

        //retrieve input patterns
        for(int j=0; j < INPUT_NEURONS; j++){
           inputs[j] = letters[sample].f[j];
        }

        for(int i=0; i < OUTPUT_NEURONS; i++){
            target[i] = letters[sample].outputs[i];
        }

        feedForward();

        /* need to iterate through all ... */


        for (int k = 0 ; k < OUTPUT_NEURONS ; k++) {
            sse += sqr( (letters[sample].outputs[k] - actual[k]));
            mse += (letters[sample].outputs[k] - actual[k]) * (letters[sample].outputs[k] - actual[k]);
        }

        sse = 0.5 * sse;
        mse = (1/(sample+1)) * mse;


        accumulatedSSE = accumulatedSSE + sse;


        if(epochs > NUMBER_OF_DESIRED_EPOCHS) {

            break;
        }

        backPropagate();

      }
      qDebug() << "training complete.";
      return accumulatedSSE;
}




/*
 *  assignRandomWeights()
 *
 *  Assign a set of random weights to the network.
 *
 */

void Backpropagation::assignRandomWeights( void )
{
  int hid, inp, out;

  for (inp = 0 ; inp < INPUT_NEURONS+1 ; inp++) {
    for (hid = 0 ; hid < HIDDEN_NEURONS ; hid++) {
      wih[inp][hid] = RAND_WEIGHT;
    }
  }

  for (hid = 0 ; hid < HIDDEN_NEURONS+1 ; hid++) {
    for (out = 0 ; out < OUTPUT_NEURONS ; out++) {
      who[hid][out] = RAND_WEIGHT;
    }
  }

}


/*
 *  sigmoid()
 *
 *  Calculate and return the sigmoid of the val argument.
 *
 */

double Backpropagation::sigmoid( double val )
{
  return (1.0 / (1.0 + exp(-val)));
}

double Backpropagation::softmax(double val, double total)
{
    return (exp(val)/total);
}


/*
 *  sigmoidDerivative()
 *
 *  Calculate and return the derivative of the sigmoid for the val argument.
 *
 */

double Backpropagation::sigmoidDerivative( double val )
{
  return ( val * (1.0 - val) );
}




/*
 *  feedForward()
 *
 *  Feedforward the inputs of the neural network to the outputs.
 *
 */

void Backpropagation::feedForward( )
{
  int inp, hid, out;
  double sum;

  /* Calculate input to hidden layer */
  for (hid = 0 ; hid < HIDDEN_NEURONS ; hid++) {

    sum = 0.0;
    for (inp = 0 ; inp < INPUT_NEURONS ; inp++) {
      sum += inputs[inp] * wih[inp][hid];
    }

    /* Add in Bias */
    sum += wih[INPUT_NEURONS][hid];

    hidden[hid] = sigmoid( sum );

  }
  float total = 0;
  float sums[OUTPUT_NEURONS];
  /* Calculate the hidden to output layer */
  for (out = 0 ; out < OUTPUT_NEURONS ; out++) {

    sum = 0.0;
    for (hid = 0 ; hid < HIDDEN_NEURONS ; hid++) {
      sum += hidden[hid] * who[hid][out];
    }

    /* Add in Bias */
    sum += who[HIDDEN_NEURONS][out];

    total += exp(sum);
    sums[out] = sum;
    //actual[out] = sigmoid( sum );

  }
  for(int i = 0; i < OUTPUT_NEURONS; i++){
      actual[i] = softmax(sums[i],total);
  }
}


/*
 *  backPropagate()
 *
 *  Backpropagate the error through the network.
 *
 */

void Backpropagation::backPropagate( void )
{
  int inp, hid, out;

  /* Calculate the output layer error (step 3 for output cell) */
  for (out = 0 ; out < OUTPUT_NEURONS ; out++) {
    erro[out] = (target[out] - actual[out]) * sigmoidDerivative( actual[out] );
  }

  /* Calculate the hidden layer error (step 3 for hidden cell) */
  for (hid = 0 ; hid < HIDDEN_NEURONS ; hid++) {

    errh[hid] = 0.0;
    for (out = 0 ; out < OUTPUT_NEURONS ; out++) {
      errh[hid] += erro[out] * who[hid][out];
    }

    errh[hid] *= sigmoidDerivative( hidden[hid] );

  }

  /* Update the weights for the output layer (step 4 for output cell) */
  for (out = 0 ; out < OUTPUT_NEURONS ; out++) {

    for (hid = 0 ; hid < HIDDEN_NEURONS ; hid++) {
      who[hid][out] += (LEARNING_RATE * erro[out] * hidden[hid]);
    }

    /* Update the Bias */
    who[HIDDEN_NEURONS][out] += (LEARNING_RATE * erro[out]);

  }

  /* Update the weights for the hidden layer (step 4 for hidden cell) */
  for (hid = 0 ; hid < HIDDEN_NEURONS ; hid++) {

    for (inp = 0 ; inp < INPUT_NEURONS ; inp++) {
      wih[inp][hid] += (LEARNING_RATE * errh[hid] * inputs[inp]);
    }

    /* Update the Bias */
    wih[INPUT_NEURONS][hid] += (LEARNING_RATE * errh[hid]);

  }

}
