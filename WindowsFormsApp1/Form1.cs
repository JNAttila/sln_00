using System;
using System.Threading;
using System.Windows.Forms;


namespace NeuronNet
{
    public partial class MainForm : Form
    {
        readonly NeuronManager manager;

        public MainForm()
        {
            manager = new NeuronManager();
            InitializeComponent();
        }

        private void buttonTrainProcess_Click(object sender, EventArgs e)
        {
            timer1.Start();
            manager.DoTrainingProcess((Button)sender, cbTrainingSampleSize);
        }

        private void btnPauseTraining_Click(object sender, EventArgs e)
        {
            // TODO: implement
        }

        private void btnDoTesting_Click(object sender, EventArgs e)
        {
            manager.DoTestingProcess((Button)sender);
        }

        private void btnPauseTesting_Click(object sender, EventArgs e)
        {
            // TODO: implement
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            manager.GetTrainingPercentage(lblTrainingPercValue);
        }

    }
}
