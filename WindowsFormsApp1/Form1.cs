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

namespace NeuronNet
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }

        private void buttonAdd_Click(object sender, EventArgs e)
        {
            int a = 42;
            int b = 17;
            MessageBox.Show(String.Format("{0} + {1} = {2}", a, b, NeuralNetClrClassLib.NeuralClassLib.Add(a, b)));
        }
    }
}
