#pragma once

#include <iostream>
#include <fstream>

#include "NeuralNetCommon.h"

class NeuralNetTester
{
public:
	NeuralNetTester();
	~NeuralNetTester();

	int DoTestingProcess();

	double GetTestingPercentage() { return testingPercentage; }

private:
	// From layer_1 to layer_2.
	double* weight1[neurLayer_1], * out1;
	// From layer_2 to layer_3.
	double* weight2[neurLayer_2], * out2, * in2;
	// Layer 3
	double* in3, * out3;
	double expected[neurLayer_3];

	double testingPercentage;

	// The current MNIST image: 28x28 gray scale image
	int currImg[imageWidth][imageHeight];

	ifstream image;
	ifstream label;
	ofstream report;
	double Sigmoid(double x);
	double SquareError();

	void Perceptron();
	void LoadModel(string fileName);

	int ReadInput();
};

