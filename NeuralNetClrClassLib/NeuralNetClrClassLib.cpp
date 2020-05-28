#include "pch.h"
#include "NeuralNet.h"
#include "NeuralNetClrClassLib.h"

namespace NeuralNetClrClassLib {

	NeuralNet neuralNetwork;

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

	void NeuralClassLib::Init()
	{
		neuralNetwork.InitLearnArray();
	}

	int NeuralClassLib::DoProcess()
	{
		return neuralNetwork.DoTrainingProcess();
	}

	double NeuralClassLib::GetArray()
	{
		return neuralNetwork.GetArray();
	}
}