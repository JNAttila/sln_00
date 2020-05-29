#pragma once

using namespace System;

namespace NeuralNetClrClassLib {

	public ref class NeuralClassLib
	{
	public:
		static int Add(int a, int b);

		NeuralClassLib();
		~NeuralClassLib();

		double DoTrainingProcess(int limit);
		int DoTestingProcess();

		double GetTrainingPercent();
		double GetTestingPercent();
		
		double GetRandomValue();
	};

}
