
using NeuralNetClrClassLib;
using System;
using System.Threading;
using System.Windows.Forms;

namespace NeuronNet
{
    class NeuronManager
    {
        readonly NeuralNetClrClassLib.NeuralClassLib ncl;
        public const int defaultLimit = 50;

        public NeuronManager()
        {
            ncl = new NeuralClassLib();
        }

        public void GetTestingPercentage(Label lbl)
        {
            lbl.Text = (ncl.GetTestingPercent() * 100).ToString();
        }

        public double DoTrainingProcess(int limit)
        {
            return ncl.DoTrainingProcess(limit);
        }

        public void GetTrainingPercentage(Label lbl)
        {
            lbl.Text = (ncl.GetTrainingPercent() * 100).ToString();
        }

        public double DoTestingProcess()
        {
            return ncl.DoTestingProcess();
        }
    }
}
