
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

        public double GetRandomValue()
        {
            return ncl.GetRandomValue();
        }

        public double DoTrainingProcess(int limit)
        {
            return ncl.DoTrainingProcess(limit);
        }

        public void GetTrainingPercentage(Label lbl)
        {
            lbl.Text = (ncl.GetTrainingPercent() * 100).ToString();
        }

        public void DoTestingProcess(Button btn)
        {
            btn.Enabled = false;
            Application.DoEvents();

            ncl.DoTestingProcess();

            btn.Enabled = true;
            Application.DoEvents();
        }
    }
}
