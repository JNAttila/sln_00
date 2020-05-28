using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using System.IO;

using NeuralNetClrClassLib;

namespace NeuronNet
{
    public partial class MainForm : Form
    {
        NeuralNetClrClassLib.NeuralClassLib ncl;

        public MainForm()
        {
            InitializeComponent();
            ncl = new NeuralClassLib();
        }

        private void buttonAdd_Click(object sender, EventArgs e)
        {
            int a = 42;
            int b = 17;
            MessageBox.Show(String.Format("{0} + {1} = {2}", a, b, NeuralClassLib.Add(a, b)));
        }

        private void buttonNetInit_Click(object sender, EventArgs e)
        {
            ncl.Init();
            buttonNetInit.Text = "OK " + ncl.GetArray();
        }

        private void buttonProcess_Click(object sender, EventArgs e)
        {
            buttonProcess.Text = "OK " + ncl.DoProcess();
        }

    }
}
