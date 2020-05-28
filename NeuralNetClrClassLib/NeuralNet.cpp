
#include <cmath>

#include "NeuralNet.h"

NeuralNet::NeuralNet()
{
    // Layer_1 - Layer_2   LIKE   Input_layer - Hidden_layer
    for (int i = 0; i < neurLayer_1; ++i) {
        weight1[i] = new double[neurLayer_2];
        delta1[i] = new double[neurLayer_2];
    }
    out1 = new double[neurLayer_1];

    // Layer_2 - Layer_3   LIKE   Hidden_layer - Output_layer
    for (int i = 0; i < neurLayer_2; ++i) {
        weight2[i] = new double[neurLayer_3];
        delta2[i] = new double[neurLayer_3];
    }
    out2 = new double[neurLayer_2];

    in2 = new double[neurLayer_2];
    theta2 = new double[neurLayer_2];

    // Layer 3 - Output layer
    in3 = new double[neurLayer_3];
    out3 = new double[neurLayer_3];
    theta3 = new double[neurLayer_3];
}

NeuralNet::~NeuralNet()
{
    for (int i = 0; i < neurLayer_1; ++i) {
        delete[] weight1[i];
        delete[] delta1[i];
    }
    delete[] out1;
    
    for (int i = 0; i < neurLayer_2; ++i) {
        delete[] weight2[i];
        delete[] delta2[i];
    }
    delete[] out2;

    delete[] in2;
    delete[] theta2;

    delete[] in3;
    delete[] out3;
    delete[] theta3;
}

int NeuralNet::Add(int a, int b)
{
    return a + b;
}

void NeuralNet::InitLearnArray()
{
    // Initialization for weights from Input layer to Hidden layer
    for (int i = 0; i < neurLayer_1; ++i) {
        for (int j = 0; j < neurLayer_2; ++j) {
            weight1[i][j] = ((rand() % 2 == 0) ? (1) : (-1)) * (double)(rand() % 6) / 10.0;
        }
    }

    // Initialization for weights from Hidden layer to Output layer
    for (int i = 0; i < neurLayer_2; ++i) {
        for (int j = 0; j < neurLayer_3; ++j) {
            weight2[i][j] = ((rand() % 2 == 0) ? (1) : (-1)) * (double)((rand() % 10) + 1.0) / (10.0 * neurLayer_3);
        }
    }
}

double NeuralNet::GetRandomValue()
{
    return ((rand() % 2 == 0) ? (1) : (-1)) * (double)(rand() % 6) / 10.0;
}

double NeuralNet::Sigmoid(double x)
{
    return 1.0 / (1.0 + exp(-x));
}

// Forward process
void  NeuralNet::Perceptron()
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

double NeuralNet::SquareError()
{
    double res = 0.0;
    for (int i = 0; i < neurLayer_3; ++i) {
        res += (out3[i] - expected[i]) * (out3[i] - expected[i]);
    }
    res *= 0.5;
    return res;
}

// Back Propagation Algorithm
void NeuralNet::BackPropagation() {
    double sum;

    for (int i = 0; i < neurLayer_3; ++i) {
        theta3[i] = out3[i] * (1 - out3[i]) * (expected[i] - out3[i]);
    }

    for (int i = 0; i < neurLayer_2; ++i) {
        sum = 0.0;
        for (int j = 0; j < neurLayer_3; ++j) {
            sum += weight2[i][j] * theta3[j];
        }
        theta2[i] = out2[i] * (1 - out2[i]) * sum;
    }

    for (int i = 0; i < neurLayer_2; ++i) {
        for (int j = 0; j < neurLayer_3; ++j) {
            delta2[i][j] = (learning_rate * theta3[j] * out2[i]) + (momentum * delta2[i][j]);
            weight2[i][j] += delta2[i][j];
        }
    }

    for (int i = 0; i < neurLayer_1; ++i) {
        for (int j = 0; j < neurLayer_2; j++) {
            delta1[i][j] = (learning_rate * theta2[j] * out1[i]) + (momentum * delta1[i][j]);
            weight1[i][j] += delta1[i][j];
        }
    }
}

// Learning process : Perceptron - Back propagation
int NeuralNet::LearningProcess()
{
    for (int i = 0; i < neurLayer_1; ++i) {
        for (int j = 1; j < neurLayer_2; ++j) {
            delta1[i][j] = 0.0;
        }
    }

    for (int i = 0; i < neurLayer_2; ++i) {
        for (int j = 0; j < neurLayer_3; ++j) {
            delta2[i][j] = 0.0;
        }
    }

    for (int i = 0; i < epochs; ++i) {
        Perceptron();
        BackPropagation();
        if (SquareError() < epsilon) {
            return i;
        }
    }
    return epochs;
}

// Reading input - gray scale image and the corresponding label
void NeuralNet::ReadInput()
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

    /*cout << "Image:" << endl;
    for (int j = 0; j < imageHeight; ++j) {
        for (int i = 0; i < imageWidth; ++i) {
            cout << currImg[i][j];
        }
        cout << endl;
    }/**/

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

    //cout << "Label: " << (int)(number) << endl;
}

// Saving weights to file
void NeuralNet::WriteMatrix(string fileName) {
    ofstream file(fileName.c_str(), ios::out);

    // Input layer - Hidden layer
    for (int i = 0; i < neurLayer_1; ++i) {
        for (int j = 0; j < neurLayer_2; ++j) {
            file << weight1[i][j] << " ";
        }
        file << endl;
    }

    // Hidden layer - Output layer
    for (int i = 0; i < neurLayer_2; ++i) {
        for (int j = 0; j < neurLayer_3; ++j) {
            file << weight2[i][j] << " ";
        }
        file << endl;
    }

    file.close();
}

int NeuralNet::DoTrainingProcess(int trainingSampleNumber) {
    report.open(trainingReportFileName.c_str(), ios::out);
    image.open(trainingImageFileName.c_str(), ios::in | ios::binary); // Binary image file
    label.open(trainingLabelFileName.c_str(), ios::in | ios::binary); // Binary label file

    // Reading file headers
    char number;
    for (int i = 0; i < 16; ++i) {
        image.read(&number, sizeof(char));
    }
    for (int i = 0; i < 8; ++i) {
        label.read(&number, sizeof(char));
    }

    // Neural Network Initialization
    InitLearnArray();

    trainingPercentage = 0.0;
    for (int sample = 0; sample < trainingSampleNumber; ++sample) {
        //cout << "Sample " << sample << endl;

        // Getting (image, label)
        ReadInput();

        // Learning process: Perceptron (Forward procedure) - Back propagation
        int nIterations = LearningProcess();

        // Write down the squared error
        //cout << "No. iterations: " << nIterations << endl;
        //printf("Error: %0.6lf\n\n", SquareError());
        report << "Sample " << sample << ": No. iterations = " << nIterations << ", Error = " << SquareError() << endl;

        // Save the current network (weights)
        if (sample % 100 == 0) {
            //cout << "Saving the network to " << modelFileName << " file." << endl;
            WriteMatrix(modelFileName);
        }

        if (sample % 20 == 0) {
            trainingPercentage = sample / trainingSampleNumber;
        }
    }

    // Save the final network
    WriteMatrix(modelFileName);

    report.close();
    image.close();
    label.close();

    return 41;
}
