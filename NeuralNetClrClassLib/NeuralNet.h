#pragma once

#include <iostream>
#include <fstream>

#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>

#include "NeuralNetCommon.h"

class NeuralNet
{
public:
	NeuralNet();
	~NeuralNet();

	int DoTrainingProcess(int limit);

	double GetTrainingPercentage() { return trainingPercentage; }

	double GetRandomValue();

	static int Add(int a, int b);

private:
	// From layer_1 to layer_2.
	double* weight1[neurLayer_1], * delta1[neurLayer_1], * out1;
	// From layer_2 to layer_3.
	double* weight2[neurLayer_2], * delta2[neurLayer_2], * out2, * in2, * theta2;
	// Layer 3
	double* in3, * out3, * theta3;
	double expected[neurLayer_3];

	double trainingPercentage;

	// The current MNIST image: 28x28 gray scale image
	int currImg[imageWidth][imageHeight];

	ifstream image;
	ifstream label;
	ofstream report;

	void InitLearnArray();
	void Perceptron();
	void BackPropagation();
	void ReadInput();
	void WriteMatrix(string fileName);
	int LearningProcess();

	double Sigmoid(double x);
	double SquareError();
};

