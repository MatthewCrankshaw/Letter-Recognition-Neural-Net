#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "globalVariables.h"


//--------------------------------------

LetterStructure letters[20001];
LetterStructure testPattern;

bool patternsLoadedFromFile;
int MAX_EPOCHS;
double LEARNING_RATE;
//int NUMBER_OF_PATTERNS;

///////////////////////////////////////////////////////

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //---------------------------------------
    //initialisation of global variables
    //

    //NUMBER_OF_PATTERNS = 20000;

    LEARNING_RATE=0.2;
    patternsLoadedFromFile = false;
    MAX_EPOCHS = 50;

    bp = new Backpropagation;

    //---------------------------------------
    //initialise widgets

    ui->spinBox_training_Epochs->setValue(MAX_EPOCHS);
    ui->horizScrollBar_LearningRate->setValue(int(LEARNING_RATE*100));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Read_File_clicked()
{
    qDebug() << "\nReading file...";
    QFile file("complete_data_set.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    if(!file.exists()){
        patternsLoadedFromFile=false;

        qDebug() << "Data file does not exist!";
        return;
    }

    QTextStream in(&file);



    char t;
    char characterSymbol;
    QString line;

    int counterForLetter[26];
    for(int i = 0; i < 26; i ++) counterForLetter[i] = 0;
    QString lineOfData;
    QString msg;
    int i=0;
    //while(i < NUMBER_OF_TRAINING_PATTERNS){
    while(i < NUMBER_OF_PATTERNS){

        //e.g. T,2,8,3,5,1,8,13,0,6,6,10,8,0,8,0,8
        in >> characterSymbol >> t >> letters[i].f[0] >> t >>  letters[i].f[1] >> t >>  letters[i].f[2] >> t >>  letters[i].f[3] >> t >>  letters[i].f[4] >> t >>  letters[i].f[5] >> t >>  letters[i].f[6] >> t >>  letters[i].f[7] >> t >>  letters[i].f[8] >> t >>  letters[i].f[9] >> t >>  letters[i].f[10] >> t >>  letters[i].f[11] >> t >> letters[i].f[12] >> t >> letters[i].f[13] >> t >> letters[i].f[14] >> t >> letters[i].f[15];
        line = in.readLine();

        if(characterSymbol == 'A'){

            letters[i].symbol = LETTER_A;
            for(int ltr = 0; ltr < 26; ltr++){
                letters[i].outputs[ltr] = 0;
            }
            letters[i].outputs[LETTER_A] = 1;
            counterForLetter[LETTER_A]++;

        } else if(characterSymbol == 'B'){

            letters[i].symbol = LETTER_B;
            for(int ltr = 0; ltr < 26; ltr++){
                letters[i].outputs[ltr] = 0;
            }
            letters[i].outputs[LETTER_B] = 1;
            counterForLetter[LETTER_B]++;

        } else if(characterSymbol == 'C'){

            letters[i].symbol = LETTER_C;
            for(int ltr = 0; ltr < 26; ltr++){
                letters[i].outputs[ltr] = 0;
            }
            letters[i].outputs[LETTER_C] = 1;
            counterForLetter[LETTER_C]++;

        }else if(characterSymbol == 'D'){

            letters[i].symbol = LETTER_D;
            for(int ltr = 0; ltr < 26; ltr++){
                letters[i].outputs[ltr] = 0;
            }
            letters[i].outputs[LETTER_D] = 1;
            counterForLetter[LETTER_D]++;

        }else if(characterSymbol == 'E'){

            letters[i].symbol = LETTER_E;
            for(int ltr = 0; ltr < 26; ltr++){
                letters[i].outputs[ltr] = 0;
            }
            letters[i].outputs[LETTER_E] = 1;
            counterForLetter[LETTER_E]++;

        }else if(characterSymbol == 'F'){

            letters[i].symbol = LETTER_F;
            for(int ltr = 0; ltr < 26; ltr++){
                letters[i].outputs[ltr] = 0;
            }
            letters[i].outputs[LETTER_F] = 1;
            counterForLetter[LETTER_F]++;

        }else if(characterSymbol == 'G'){

            letters[i].symbol = LETTER_G;
            for(int ltr = 0; ltr < 26; ltr++){
                letters[i].outputs[ltr] = 0;
            }
            letters[i].outputs[LETTER_G] = 1;
            counterForLetter[LETTER_G]++;

        }else if(characterSymbol == 'H'){

            letters[i].symbol = LETTER_H;
            for(int ltr = 0; ltr < 26; ltr++){
                letters[i].outputs[ltr] = 0;
            }
            letters[i].outputs[LETTER_H] = 1;
            counterForLetter[LETTER_H]++;

        }else if(characterSymbol == 'I'){

            letters[i].symbol = LETTER_I;
            for(int ltr = 0; ltr < 26; ltr++){
                letters[i].outputs[ltr] = 0;
            }
            letters[i].outputs[LETTER_I] = 1;
            counterForLetter[LETTER_I]++;

        }else if(characterSymbol == 'J'){

            letters[i].symbol = LETTER_J;
            for(int ltr = 0; ltr < 26; ltr++){
                letters[i].outputs[ltr] = 0;
            }
            letters[i].outputs[LETTER_J] = 1;
            counterForLetter[LETTER_J]++;

        }else if(characterSymbol == 'K'){

            letters[i].symbol = LETTER_K;
            for(int ltr = 0; ltr < 26; ltr++){
                letters[i].outputs[ltr] = 0;
            }
            letters[i].outputs[LETTER_K] = 1;
            counterForLetter[LETTER_K]++;

        }else if(characterSymbol == 'L'){

            letters[i].symbol = LETTER_L;
            for(int ltr = 0; ltr < 26; ltr++){
                letters[i].outputs[ltr] = 0;
            }
            letters[i].outputs[LETTER_L] = 1;
            counterForLetter[LETTER_L]++;

        }else if(characterSymbol == 'M'){

            letters[i].symbol = LETTER_M;
            for(int ltr = 0; ltr < 26; ltr++){
                letters[i].outputs[ltr] = 0;
            }
            letters[i].outputs[LETTER_M] = 1;
            counterForLetter[LETTER_M]++;

        }else if(characterSymbol == 'N'){

            letters[i].symbol = LETTER_N;
            for(int ltr = 0; ltr < 26; ltr++){
                letters[i].outputs[ltr] = 0;
            }
            letters[i].outputs[LETTER_N] = 1;
            counterForLetter[LETTER_N]++;

        }else if(characterSymbol == 'O'){

            letters[i].symbol = LETTER_O;
            for(int ltr = 0; ltr < 26; ltr++){
                letters[i].outputs[ltr] = 0;
            }
            letters[i].outputs[LETTER_O] = 1;
            counterForLetter[LETTER_O]++;

        }else if(characterSymbol == 'P'){

            letters[i].symbol = LETTER_P;
            for(int ltr = 0; ltr < 26; ltr++){
                letters[i].outputs[ltr] = 0;
            }
            letters[i].outputs[LETTER_P] = 1;
            counterForLetter[LETTER_P]++;

        }else if(characterSymbol == 'Q'){

            letters[i].symbol = LETTER_Q;
            for(int ltr = 0; ltr < 26; ltr++){
                letters[i].outputs[ltr] = 0;
            }
            letters[i].outputs[LETTER_Q] = 1;
            counterForLetter[LETTER_Q]++;

        }else if(characterSymbol == 'R'){

            letters[i].symbol = LETTER_R;
            for(int ltr = 0; ltr < 26; ltr++){
                letters[i].outputs[ltr] = 0;
            }
            letters[i].outputs[LETTER_R] = 1;
            counterForLetter[LETTER_R]++;

        }else if(characterSymbol == 'S'){

            letters[i].symbol = LETTER_S;
            for(int ltr = 0; ltr < 26; ltr++){
                letters[i].outputs[ltr] = 0;
            }
            letters[i].outputs[LETTER_S] = 1;
            counterForLetter[LETTER_S]++;

        }else if(characterSymbol == 'T'){

            letters[i].symbol = LETTER_T;
            for(int ltr = 0; ltr < 26; ltr++){
                letters[i].outputs[ltr] = 0;
            }
            letters[i].outputs[LETTER_T] = 1;
            counterForLetter[LETTER_T]++;

        }else if(characterSymbol == 'U'){

            letters[i].symbol = LETTER_U;
            for(int ltr = 0; ltr < 26; ltr++){
                letters[i].outputs[ltr] = 0;
            }
            letters[i].outputs[LETTER_U] = 1;
            counterForLetter[LETTER_U]++;

        }else if(characterSymbol == 'V'){

            letters[i].symbol = LETTER_V;
            for(int ltr = 0; ltr < 26; ltr++){
                letters[i].outputs[ltr] = 0;
            }
            letters[i].outputs[LETTER_V] = 1;
            counterForLetter[LETTER_V]++;

        }else if(characterSymbol == 'W'){

            letters[i].symbol = LETTER_W;
            for(int ltr = 0; ltr < 26; ltr++){
                letters[i].outputs[ltr] = 0;
            }
            letters[i].outputs[LETTER_W] = 1;
            counterForLetter[LETTER_W]++;

        }else if(characterSymbol == 'X'){

            letters[i].symbol = LETTER_X;
            for(int ltr = 0; ltr < 26; ltr++){
                letters[i].outputs[ltr] = 0;
            }
            letters[i].outputs[LETTER_X] = 1;
            counterForLetter[LETTER_X]++;

        }else if(characterSymbol == 'Y'){

            letters[i].symbol = LETTER_Y;
            for(int ltr = 0; ltr < 26; ltr++){
                letters[i].outputs[ltr] = 0;
            }
            letters[i].outputs[LETTER_Y] = 1;
            counterForLetter[LETTER_Y]++;

        }else if(characterSymbol == 'Z'){

            letters[i].symbol = LETTER_Z;
            for(int ltr = 0; ltr < 26; ltr++){
                letters[i].outputs[ltr] = 0;
            }
            letters[i].outputs[LETTER_Z] = 1;
            counterForLetter[LETTER_Z]++;
        }

        if((i % 50==0) || (i == NUMBER_OF_PATTERNS-1)){
            msg.clear();
            lineOfData.sprintf("number of patterns for Letter A = %d\n", counterForLetter[LETTER_A]);
            msg.append(lineOfData);
            lineOfData.sprintf("number of patterns for Letter B = %d\n", counterForLetter[LETTER_B]);
            msg.append(lineOfData);
            lineOfData.sprintf("number of patterns for Letter C = %d\n", counterForLetter[LETTER_C]);
            msg.append(lineOfData);
            lineOfData.sprintf("number of patterns for Letter D = %d\n", counterForLetter[LETTER_D]);
            msg.append(lineOfData);
            lineOfData.sprintf("number of patterns for Letter E = %d\n", counterForLetter[LETTER_E]);
            msg.append(lineOfData);
            lineOfData.sprintf("number of patterns for Letter F = %d\n", counterForLetter[LETTER_F]);
            msg.append(lineOfData);
            lineOfData.sprintf("number of patterns for Letter G = %d\n", counterForLetter[LETTER_G]);
            msg.append(lineOfData);
            lineOfData.sprintf("number of patterns for Letter H = %d\n", counterForLetter[LETTER_H]);
            msg.append(lineOfData);
            lineOfData.sprintf("number of patterns for Letter I = %d\n", counterForLetter[LETTER_I]);
            msg.append(lineOfData);
            lineOfData.sprintf("number of patterns for Letter J = %d\n", counterForLetter[LETTER_J]);
            msg.append(lineOfData);
            lineOfData.sprintf("number of patterns for Letter K = %d\n", counterForLetter[LETTER_K]);
            msg.append(lineOfData);
            lineOfData.sprintf("number of patterns for Letter L = %d\n", counterForLetter[LETTER_L]);
            msg.append(lineOfData);
            lineOfData.sprintf("number of patterns for Letter M = %d\n", counterForLetter[LETTER_M]);
            msg.append(lineOfData);
            lineOfData.sprintf("number of patterns for Letter N = %d\n", counterForLetter[LETTER_N]);
            msg.append(lineOfData);
            lineOfData.sprintf("number of patterns for Letter O = %d\n", counterForLetter[LETTER_O]);
            msg.append(lineOfData);
            lineOfData.sprintf("number of patterns for Letter P = %d\n", counterForLetter[LETTER_P]);
            msg.append(lineOfData);
            lineOfData.sprintf("number of patterns for Letter Q = %d\n", counterForLetter[LETTER_Q]);
            msg.append(lineOfData);
            lineOfData.sprintf("number of patterns for Letter R = %d\n", counterForLetter[LETTER_R]);
            msg.append(lineOfData);
            lineOfData.sprintf("number of patterns for Letter S = %d\n", counterForLetter[LETTER_S]);
            msg.append(lineOfData);
            lineOfData.sprintf("number of patterns for Letter T = %d\n", counterForLetter[LETTER_T]);
            msg.append(lineOfData);
            lineOfData.sprintf("number of patterns for Letter U = %d\n", counterForLetter[LETTER_U]);
            msg.append(lineOfData);
            lineOfData.sprintf("number of patterns for Letter V = %d\n", counterForLetter[LETTER_V]);
            msg.append(lineOfData);
            lineOfData.sprintf("number of patterns for Letter W = %d\n", counterForLetter[LETTER_W]);
            msg.append(lineOfData);
            lineOfData.sprintf("number of patterns for Letter X = %d\n", counterForLetter[LETTER_X]);
            msg.append(lineOfData);
            lineOfData.sprintf("number of patterns for Letter Y = %d\n", counterForLetter[LETTER_Y]);
            msg.append(lineOfData);
            lineOfData.sprintf("number of patterns for Letter Z = %d\n", counterForLetter[LETTER_Z]);
            msg.append(lineOfData);

            ui->plainTextEdit_results->setPlainText(msg);
            qApp->processEvents();
        }

        i++;
    }

    msg.append("done.");

    ui->plainTextEdit_results->setPlainText(msg);
    qApp->processEvents();

    patternsLoadedFromFile=true;

}

void MainWindow::on_horizScrollBar_LearningRate_valueChanged(int value)
{
    ui->lcdNumber_LearningRate->setSegmentStyle(QLCDNumber::Filled);
    ui->lcdNumber_LearningRate->display(value/1000.0);
    LEARNING_RATE = value/1000.0;
}

//void MainWindow::on_pushButton_Train_Network_clicked()
//{

//}

void MainWindow::on_pushButton_Classify_Test_Pattern_clicked()
{

    char characterSymbol, t;
    QString *q;
    double* classificationResults;

    double* outputs;
    outputs = new double[OUTPUT_NEURONS];

//    delete q;
//    delete classificationResults;



    classificationResults = new double[OUTPUT_NEURONS];

    //QTextStream line;
    q = new QString(ui->plainTextEdit_Input_Pattern->toPlainText());

    QTextStream line(q);

    line >> characterSymbol >> t >> testPattern.f[0] >> t >>  testPattern.f[1] >> t >>  testPattern.f[2] >> t >>  testPattern.f[3] >> t >>  testPattern.f[4] >> t >>  testPattern.f[5] >> t >>  testPattern.f[6] >> t >>  testPattern.f[7] >> t >>  testPattern.f[8] >> t >>  testPattern.f[9] >> t >>  testPattern.f[10] >> t >>  testPattern.f[11] >> t >> testPattern.f[12] >> t >> testPattern.f[13] >> t >> testPattern.f[14] >> t >> testPattern.f[15];



    if(characterSymbol == 'A'){
        testPattern.symbol = LETTER_A;
        testPattern.outputs[0] = 1;
        testPattern.outputs[1] = 0;
        testPattern.outputs[2] = 0;

    } else if(characterSymbol == 'B'){
        testPattern.symbol = LETTER_B;
        testPattern.outputs[0] = 0;
        testPattern.outputs[1] = 1;
        testPattern.outputs[2] = 0;

    } else {
        testPattern.symbol = LETTER_C;
        testPattern.outputs[0] = 0;
        testPattern.outputs[1] = 0;
        testPattern.outputs[2] = 1;

    }


    //---------------------------------
    classificationResults = bp->testNetwork(testPattern);

    ui->lcdNumber_A->display(classificationResults[0]);
    ui->lcdNumber_B->display(classificationResults[1]);
    ui->lcdNumber_unknown->display(classificationResults[2]);


    //-----------------------------------------------------------
    for(int k=0; k < OUTPUT_NEURONS; k++){
       outputs[k] = testPattern.outputs[k];
    }
    //-----------------------------------------------------------
     QString textClassification;
     switch(bp->action(outputs)){
        case 0:
            textClassification = "letter A";
            break;
        case 1:
            textClassification = "letter B";
            break;
        case 2:
            textClassification = "unknown";
            break;
     };

    if (bp->action(classificationResults) == bp->action(outputs)) {
        qDebug() << "correct classification.";
        ui->label_Classification->setText(textClassification + ", - Correct classification!");
    } else {
        qDebug() << "incorrect classification.";
        ui->label_Classification->setText(textClassification + ", -XXX- Incorrect classification.");
    }

}

void MainWindow::on_pushButton_Train_Network_Max_Epochs_clicked()
{
    double SSE = 0.0;
    QString msg;

    if(!patternsLoadedFromFile) {
        msg.clear();
        msg.append("\nMissing training patterns.  Load data set first.\n");
        ui->plainTextEdit_results->setPlainText(msg);
        return;
    }

    MAX_EPOCHS = ui->spinBox_training_Epochs->value();
    QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));

    for(int i=0; i < MAX_EPOCHS; i++){
      msg.clear();
      msg.append("\nTraining in progress...\n");
      msg.append("\nEpoch=");
      msg.append(QString::number(i));
      ui->plainTextEdit_results->setPlainText(msg);
      qApp->processEvents();

      SSE = bp->trainNetwork(1);
      ui->lcdNumber_SSE->display(bp->getError_SSE());
      qApp->processEvents();

      update();
      qDebug() << "epoch: " << i << ", SSE = " << bp->getError_SSE();

      if(i % 5 ==0){
         bp->saveWeights(ui->plainTextEdit_saveWeightsAs->toPlainText());

         ui->plainTextEdit_results->setPlainText("Weights saved into file.");
         qApp->processEvents();
      }

    }
    QApplication::restoreOverrideCursor();

}

void MainWindow::on_pushButton_Initialise_Network_clicked()
{
    bp->initialise();
}

void MainWindow::on_pushButton_Test_All_Patterns_clicked()
{
    char characterSymbol, t;
    QString *q;
    double* classificationResults;
    double* outputs;
    int correctClassifications=0;

    classificationResults = new double[OUTPUT_NEURONS];
    outputs = new double[OUTPUT_NEURONS];

    for(int i=NUMBER_OF_TRAINING_PATTERNS; i < NUMBER_OF_PATTERNS; i++){

            characterSymbol = letters[i].symbol;
            for(int j=0; j < INPUT_NEURONS; j++){
                testPattern.f[j] = letters[i].f[j];
            }

            if(characterSymbol == 'A'){
                testPattern.symbol = LETTER_A;
                testPattern.outputs[0] = 1;
                testPattern.outputs[1] = 0;
                testPattern.outputs[2] = 0;

            } else if(characterSymbol == 'B'){
                testPattern.symbol = LETTER_B;
                testPattern.outputs[0] = 0;
                testPattern.outputs[1] = 1;
                testPattern.outputs[2] = 0;

            } else {
                testPattern.symbol = LETTER_C;
                testPattern.outputs[0] = 0;
                testPattern.outputs[1] = 0;
                testPattern.outputs[2] = 1;

            }


            //---------------------------------
            classificationResults = bp->testNetwork(testPattern);

            for(int k=0; k < OUTPUT_NEURONS; k++){
               outputs[k] = testPattern.outputs[k];
            }

            if (bp->action(classificationResults) == bp->action(outputs)) {
                 correctClassifications++;

            }


        }


      qDebug() << "TEST SET: correctClassifications = " << correctClassifications;

}

void MainWindow::on_pushButton_Save_Weights_clicked()
{
    bp->saveWeights(ui->plainTextEdit_saveWeightsAs->toPlainText());

    QString msg;
    QString lineOfText;

    lineOfText = "weights saved to file: " + ui->plainTextEdit_saveWeightsAs->toPlainText();

    msg.append(lineOfText);

    ui->plainTextEdit_results->setPlainText(msg);

}

void MainWindow::on_pushButton_Load_Weights_clicked()
{
   bp->loadWeights(ui->plainTextEdit_fileNameLoadWeights->toPlainText());

   QString msg;

   msg.append("weights loaded.\n");

   ui->plainTextEdit_results->setPlainText(msg);


}

void MainWindow::on_pushButton_testNetOnTrainingSet_clicked()
{
    char characterSymbol, t;
    QString *q;
    double* classificationResults;
    double* outputs;
    int correctClassifications=0;

    classificationResults = new double[OUTPUT_NEURONS];
    outputs = new double[OUTPUT_NEURONS];

    for(int i=0; i < NUMBER_OF_TRAINING_PATTERNS; i++){

            characterSymbol = letters[i].symbol;
            for(int j=0; j < INPUT_NEURONS; j++){
                testPattern.f[j] = letters[i].f[j];
            }

            if(characterSymbol == 'A'){
                testPattern.symbol = LETTER_A;
                testPattern.outputs[0] = 1;
                testPattern.outputs[1] = 0;
                testPattern.outputs[2] = 0;

            } else if(characterSymbol == 'B'){
                testPattern.symbol = LETTER_B;
                testPattern.outputs[0] = 0;
                testPattern.outputs[1] = 1;
                testPattern.outputs[2] = 0;

            } else {
                testPattern.symbol = LETTER_C;
                testPattern.outputs[0] = 0;
                testPattern.outputs[1] = 0;
                testPattern.outputs[2] = 1;

            }

            //---------------------------------
            classificationResults = bp->testNetwork(testPattern);

            for(int k=0; k < OUTPUT_NEURONS; k++){
               outputs[k] = testPattern.outputs[k];
            }

            if (bp->action(classificationResults) == bp->action(outputs)) {
                 correctClassifications++;
            }

        }
      qDebug() << "TRAINING SET: correctClassifications = " << correctClassifications;
}

void MainWindow::on_horizScrollBar_LearningRate_actionTriggered(int action)
{

}