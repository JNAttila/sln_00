using System;
using System.Threading;
using System.Threading.Tasks;
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

        private async void btnDoTraining_Click(object sender, EventArgs e)
        {
            generalTimer.Start();
            changeState();
            Application.DoEvents();
            String selectedItem = (cbTrainingSampleSize.SelectedItem != null) ? (cbTrainingSampleSize.SelectedItem.ToString()) : ("");
            Int32.TryParse(selectedItem, out int limit);

            await Task.Run(() => manager.DoTrainingProcess((limit > 0) ? (limit) : (NeuronManager.defaultLimit)));

            changeState();
            generalTimer.Stop();
            Application.DoEvents();
        }

        private void btnPauseTraining_ClickAsync(object sender, EventArgs e)
        {
            // TODO: implement
        }

        private void btnDoTesting_Click(object sender, EventArgs e)
        {
            manager.DoTestingProcess((Button)sender);
        }

        private void generalTimer_Tick(object sender, EventArgs e)
        {
            manager.GetTrainingPercentage(lblTrainingPercValue);
        }

        private void changeState()
        {
            lblTrainingPercValue.Text = "";
            btnDoTesting.Enabled = !btnDoTesting.Enabled;
            btnDoTraining.Enabled = !btnDoTraining.Enabled;
            btnPauseTraining.Enabled = !btnPauseTraining.Enabled;
            cbTrainingSampleSize.Enabled = !cbTrainingSampleSize.Enabled;
        }
    }
}
