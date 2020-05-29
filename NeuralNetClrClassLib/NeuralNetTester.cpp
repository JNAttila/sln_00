
#include "NeuralNetTester.h"

NeuralNetTester::NeuralNetTester()
{
    // Layer_1 - Layer_2   LIKE   Input_layer - Hidden_layer
    for (int i = 0; i < neurLayer_1; ++i) {
        weight1[i] = new double[neurLayer_2];
    }
    out1 = new double[neurLayer_1];

    // Layer_2 - Layer_3   LIKE   Hidden_layer - Output_layer
    for (int i = 0; i < neurLayer_2; ++i) {
        weight2[i] = new double[neurLayer_3];
    }
    out2 = new double[neurLayer_2];

    in2 = new double[neurLayer_2];

    // Layer 3 - Output layer
    in3 = new double[neurLayer_3];
    out3 = new double[neurLayer_3];
}

NeuralNetTester::~NeuralNetTester()
{
    for (int i = 0; i < neurLayer_1; ++i) {
        delete[] weight1[i];
    }
    delete[] out1;

    for (int i = 0; i < neurLayer_2; ++i) {
        delete[] weight2[i];
    }
    delete[] out2;

    delete[] in2;

    delete[] in3;
    delete[] out3;
}

void NeuralNetTester::LoadModel(string fileName)
{
    ifstream file(fileName.c_str(), ios::in);

    // Input layer - Hidden layer
    for (int i = 0; i < neurLayer_1; ++i) {
        for (int j = 0; j < neurLayer_2; ++j) {
            file >> weight1[i][j];
        }
    }

    // Hidden layer - Output layer
    for (int i = 0; i < neurLayer_2; ++i) {
        for (int j = 0; j < neurLayer_3; ++j) {
            file >> weight2[i][j];
        }
    }

    file.close();
}

double NeuralNetTester::Sigmoid(double x)
{
    return 1.0 / (1.0 + exp(-x));
}

// Forward process
void  NeuralNetTester::Perceptron()
{
    for (int i = 0; i < neurLayer_2; ++i) {
        in2[i] = 0.0;
    }

    for (int i = 0; i < neurLayer_3; ++i) {
        in3[i] = 0.0;
    }

    for (int i = 0; i < neurLayer_1; ++i) {
        for (int j = 0; j < neurLayer_2; ++j) {
            in2[j] += out1[i] * weight1[i][j];
        }
    }

    for (int i = 0; i < neurLayer_2; ++i) {
        out2[i] = Sigmoid(in2[i]);
    }

    for (int i = 0; i < neurLayer_2; ++i) {
        for (int j = 0; j < neurLayer_3; ++j) {
            in3[j] += out2[i] * weight2[i][j];
        }
    }

    for (int i = 0; i < neurLayer_3; ++i) {
        out3[i] = Sigmoid(in3[i]);
    }
}

double NeuralNetTester::SquareError()
{
    double res = 0.0;
    for (int i = 0; i < neurLayer_3; ++i) {
        res += (out3[i] - expected[i]) * (out3[i] - expected[i]);
    }
    res *= 0.5;
    return res;
}

// Reading input - gray scale image and the corresponding label
int NeuralNetTester::ReadInput()
{
    // Reading image
    char number;
    for (int j = 0; j < imageHeight; ++j) {
        for (int i = 0; i < imageWidth; ++i) {
            image.read(&number, sizeof(char));
            if (number == 0) {
                currImg[i][j] = 0;
            }
            else {
                currImg[i][j] = 1;
            }
        }
    }

    for (int j = 0; j < imageHeight; ++j) {
        for (int i = 0; i < imageWidth; ++i) {
            int pos = i + j * imageWidth;
            out1[pos] = currImg[i][j];
        }
    }

    // Reading label
    label.read(&number, sizeof(char));
    for (int i = 0; i < neurLayer_3; ++i) {
        expected[i] = 0.0;
    }
    expected[number] = 1.0;

    return (int)(number);
}

double NeuralNetTester::DoTestingProcess()
{
    report.open(testingReportFileName.c_str(), ios::out);
    image.open(testingImageFileName.c_str(), ios::in | ios::binary);
    label.open(testingLabelFileName.c_str(), ios::in | ios::binary);

    // Reading file headers
    char number;
    for (int i = 0; i < 16; ++i) {
        image.read(&number, sizeof(char));
    }
    for (int i = 0; i < 8; ++i) {
        label.read(&number, sizeof(char));
    }

    // Neural Network Initialization
    LoadModel(modelFileName);

    int nCorrect = 0;
    testingPercentage = 0.0;
    for (int sample = 0; sample < testingSampleSize; ++sample) {

        // Getting (image, label)
        int label = ReadInput();

        // Classification - Perceptron procedure
        Perceptron();

        // Prediction
        int predict = 1;
        for (int i = 1; i < neurLayer_3; ++i) {
            if (out3[i] > out3[predict]) {
                predict = i;
            }
        }

        // Write down the classification result and the squared error
        double error = SquareError();

        nCorrect += ((label == predict) ? (1) : (0));

        testingPercentage = 1.0 * sample / testingSampleSize;
    }

    // Summary
    double accuracy = (double)(nCorrect) / testingSampleSize * 100.0;

    report << "Number of correct samples: " << nCorrect << " / " << testingSampleSize << endl;
    report << "Accuracy: " << accuracy << endl;

    report.close();
    image.close();
    label.close();

    return accuracy;
}