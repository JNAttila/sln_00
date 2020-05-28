#pragma once

using namespace System;

namespace NeuralNetClrClassLib {

	public ref class NeuralClassLib
	{
	public:
		static int Add(int a, int b);

		NeuralClassLib();
		~NeuralClassLib();

		int DoTrainingProcess(int limit);
		int DoTestingProcess(int limit);

		double GetTrainingPercent();
		double GetTestingPercent();
		
		double GetRandomValue();
	};

}
