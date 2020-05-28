
using NeuralNetClrClassLib;
using System;
using System.Windows.Forms;

namespace NeuronNet
{
    class NeuronManager
    {
        readonly NeuralNetClrClassLib.NeuralClassLib ncl;
        const int defaultLimit = 100;

        public NeuronManager()
        {
            ncl = new NeuralClassLib();
        }

        public double GetRandomValue()
        {
            return ncl.GetRandomValue();
        }

        public void DoTrainingProcess(Button btn, ComboBox cb)
        {
            btn.Enabled = false;
            Int32.TryParse(cb.SelectedText, out int limit);
            Application.DoEvents();

            ncl.DoTrainingProcess((limit > 0) ? (limit) : (defaultLimit));

            btn.Enabled = true;
            Application.DoEvents();
        }

        public void GetTrainingPercentage(Label label)
        {
            label.Text = ncl.GetTrainingPercent().ToString();
        }

        public void DoTestingProcess(Button btn, ComboBox cb)
        {
            btn.Enabled = false;
            Int32.TryParse(cb.SelectedText, out int limit);
            Application.DoEvents();

            ncl.DoTestingProcess((limit > 0) ? (limit) : (defaultLimit));

            btn.Enabled = true;
            Application.DoEvents();
        }
    }
}
