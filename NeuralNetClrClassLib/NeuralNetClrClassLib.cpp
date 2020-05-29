#include "pch.h"
#include "NeuralNet.h"
#include "NeuralNetTester.h"
#include "NeuralNetClrClassLib.h"

namespace NeuralNetClrClassLib {

	NeuralNet neuralNetwork;
	NeuralNetTester neuralNetworkTester;

	int NeuralClassLib::Add(int a, int b)
	{
		return NeuralNet::Add(a, b);
	}

	NeuralClassLib::NeuralClassLib()
	{
	}

	NeuralClassLib::~NeuralClassLib()
	{
	}

	double NeuralClassLib::DoTrainingProcess(int limit)
	{
		return neuralNetwork.DoTrainingProcess(limit);
	}

	int NeuralClassLib::DoTestingProcess()
	{
		return neuralNetworkTester.DoTestingProcess();
	}

	double NeuralClassLib::GetTrainingPercent()
	{
		return neuralNetwork.GetTrainingPercentage();
	}

	double NeuralClassLib::GetTestingPercent()
	{
		return neuralNetworkTester.GetTestingPercentage();
	}

	double NeuralClassLib::GetRandomValue()
	{
		return neuralNetwork.GetRandomValue();
	}

}