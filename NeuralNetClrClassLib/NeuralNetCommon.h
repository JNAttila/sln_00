#pragma once

using namespace std;


/***************
	Common
***************/
static const int imageWidth = 28;
static const int imageHeight = 28;

static const int neurLayer_1 = imageWidth * imageHeight;
static const int neurLayer_2 = 128;
static const int neurLayer_3 = 10;

// Weights file name
const string modelFileName = "model-neural-network.dat";

const string trainingReportFileName = "training-report.dat";

const string testingReportFileName = "testing-report.dat";


/***************
	Training
***************/
// Training image file name
const string trainingImageFileName = "mnist/train-images.idx3-ubyte";
// Training label file name
const string trainingLabelFileName = "mnist/train-labels.idx1-ubyte";

const int epochs = 512;
const double learning_rate = 1e-3;
const double momentum = 0.9;
const double epsilon = 1e-3;


/***************
	Testing
***************/
// Testing image file name
const string testingImageFileName = "mnist/t10k-images.idx3-ubyte";
// Testing label file name
const string testingLabelFileName = "mnist/t10k-labels.idx1-ubyte";
