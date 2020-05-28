#pragma once

using namespace System;

namespace NeuralNetClrClassLib {

	public ref class NeuralClassLib
	{
	public:
		static int Add(int a, int b);

		NeuralClassLib();
		~NeuralClassLib();

		void Init();

		int DoProcess();
		
		double GetArray();
	};

}
