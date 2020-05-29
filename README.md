# Neural Network

## Overview
This application builds a neural network, it is possible to train and test it.

## The project
Application structure:
* NeuronNetForm (C# - WinForms)
* NeuralNetClrClassLib (C++/CLI - LIB)
  * managed bridge class 
  * native core classes

### What can it do?
The application is almost ready, naturally. BUT, it is possible:
* to build and to run it
* to read MNIST training and testing data
* to setup the training item size and testing item size on UI
* to training the network on images
  * to store training values during the training
* to read trained model and classifiing test images
  * to save test result into report file


### How to use?
1. Clone this
1. Open the solution
1. Build the `NeuralNetClrClassLib` project
1. Build the `NeuronNetForm` project
1. Go to the `WindowsFormsApp1\bin\Debug` or `WindowsFormsApp1\bin\Release` folder (based on Your config selection)
1. Create here the `mnist` folder and copy all MNIST files into this new folder
1. Start the application with the `NeuronNetForm.exe` or from the VisualStudio
1. Train the netrok:
   1. Select the training sample size with the comboBox (default: 100)
   1. Press the `Do Training` button
   1. Please wait, until the process is finished (in case of 100 sample it needs ~60sec on my laptop)
1. You can check the result files:
   1. `model-neural-network.dat`: calculated values at the neural network
   1. `training-report.dat`: report of the trainin process
1. Test the network:
   1. Select the testing sample size with the comboBox (default: 100)
   1. Press the `Do Testing` button
   1. Please wait, until the process is finished (in case of 10000 sample it needs ~8sec on my laptop)

29-MAY-2020, Budapest
