namespace NeuronNet
{
    partial class MainForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.btnDoTraining = new System.Windows.Forms.Button();
            this.gbTraining = new System.Windows.Forms.GroupBox();
            this.lblTrainingPercValue = new System.Windows.Forms.Label();
            this.lblTrainingPerc = new System.Windows.Forms.Label();
            this.lblTrainingSampleSize = new System.Windows.Forms.Label();
            this.cbTrainingSampleSize = new System.Windows.Forms.ComboBox();
            this.btnPauseTraining = new System.Windows.Forms.Button();
            this.bgTesting = new System.Windows.Forms.GroupBox();
            this.lblAccuracyValue = new System.Windows.Forms.Label();
            this.lblAccuracy = new System.Windows.Forms.Label();
            this.lblTestingPercValue = new System.Windows.Forms.Label();
            this.lblTestingPerc = new System.Windows.Forms.Label();
            this.lblTestingSampleSize = new System.Windows.Forms.Label();
            this.btnDoTesting = new System.Windows.Forms.Button();
            this.generalTimer = new System.Windows.Forms.Timer(this.components);
            this.timerTesting = new System.Windows.Forms.Timer(this.components);
            this.gbTraining.SuspendLayout();
            this.bgTesting.SuspendLayout();
            this.SuspendLayout();
            // 
            // btnDoTraining
            // 
            this.btnDoTraining.Location = new System.Drawing.Point(6, 19);
            this.btnDoTraining.Name = "btnDoTraining";
            this.btnDoTraining.Size = new System.Drawing.Size(75, 23);
            this.btnDoTraining.TabIndex = 3;
            this.btnDoTraining.Text = "Do Training";
            this.btnDoTraining.UseVisualStyleBackColor = true;
            this.btnDoTraining.Click += new System.EventHandler(this.btnDoTraining_Click);
            // 
            // gbTraining
            // 
            this.gbTraining.Controls.Add(this.lblTrainingPercValue);
            this.gbTraining.Controls.Add(this.lblTrainingPerc);
            this.gbTraining.Controls.Add(this.lblTrainingSampleSize);
            this.gbTraining.Controls.Add(this.cbTrainingSampleSize);
            this.gbTraining.Controls.Add(this.btnPauseTraining);
            this.gbTraining.Controls.Add(this.btnDoTraining);
            this.gbTraining.Location = new System.Drawing.Point(12, 12);
            this.gbTraining.Name = "gbTraining";
            this.gbTraining.Size = new System.Drawing.Size(301, 158);
            this.gbTraining.TabIndex = 4;
            this.gbTraining.TabStop = false;
            this.gbTraining.Text = "Training the Network";
            // 
            // lblTrainingPercValue
            // 
            this.lblTrainingPercValue.BackColor = System.Drawing.Color.LightYellow;
            this.lblTrainingPercValue.Location = new System.Drawing.Point(117, 87);
            this.lblTrainingPercValue.Name = "lblTrainingPercValue";
            this.lblTrainingPercValue.Size = new System.Drawing.Size(47, 13);
            this.lblTrainingPercValue.TabIndex = 9;
            // 
            // lblTrainingPerc
            // 
            this.lblTrainingPerc.AutoSize = true;
            this.lblTrainingPerc.Location = new System.Drawing.Point(6, 87);
            this.lblTrainingPerc.Name = "lblTrainingPerc";
            this.lblTrainingPerc.Size = new System.Drawing.Size(105, 13);
            this.lblTrainingPerc.TabIndex = 8;
            this.lblTrainingPerc.Text = "Training process (%):";
            // 
            // lblTrainingSampleSize
            // 
            this.lblTrainingSampleSize.AutoSize = true;
            this.lblTrainingSampleSize.Location = new System.Drawing.Point(121, 24);
            this.lblTrainingSampleSize.Name = "lblTrainingSampleSize";
            this.lblTrainingSampleSize.Size = new System.Drawing.Size(102, 13);
            this.lblTrainingSampleSize.TabIndex = 7;
            this.lblTrainingSampleSize.Text = "Training sample size";
            // 
            // cbTrainingSampleSize
            // 
            this.cbTrainingSampleSize.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbTrainingSampleSize.FormattingEnabled = true;
            this.cbTrainingSampleSize.Items.AddRange(new object[] {
            "100",
            "200",
            "500",
            "1000",
            "2000",
            "5000",
            "10000",
            "20000",
            "60000"});
            this.cbTrainingSampleSize.Location = new System.Drawing.Point(120, 48);
            this.cbTrainingSampleSize.Name = "cbTrainingSampleSize";
            this.cbTrainingSampleSize.Size = new System.Drawing.Size(121, 21);
            this.cbTrainingSampleSize.TabIndex = 7;
            // 
            // btnPauseTraining
            // 
            this.btnPauseTraining.Enabled = false;
            this.btnPauseTraining.Location = new System.Drawing.Point(6, 48);
            this.btnPauseTraining.Name = "btnPauseTraining";
            this.btnPauseTraining.Size = new System.Drawing.Size(75, 23);
            this.btnPauseTraining.TabIndex = 4;
            this.btnPauseTraining.Text = "Pause";
            this.btnPauseTraining.UseVisualStyleBackColor = true;
            this.btnPauseTraining.Click += new System.EventHandler(this.btnPauseTraining_ClickAsync);
            // 
            // bgTesting
            // 
            this.bgTesting.Controls.Add(this.lblAccuracyValue);
            this.bgTesting.Controls.Add(this.lblAccuracy);
            this.bgTesting.Controls.Add(this.lblTestingPercValue);
            this.bgTesting.Controls.Add(this.lblTestingPerc);
            this.bgTesting.Controls.Add(this.lblTestingSampleSize);
            this.bgTesting.Controls.Add(this.btnDoTesting);
            this.bgTesting.Location = new System.Drawing.Point(319, 12);
            this.bgTesting.Name = "bgTesting";
            this.bgTesting.Size = new System.Drawing.Size(293, 158);
            this.bgTesting.TabIndex = 5;
            this.bgTesting.TabStop = false;
            this.bgTesting.Text = "Testing the Network";
            // 
            // lblAccuracyValue
            // 
            this.lblAccuracyValue.BackColor = System.Drawing.Color.LightYellow;
            this.lblAccuracyValue.Location = new System.Drawing.Point(114, 58);
            this.lblAccuracyValue.Name = "lblAccuracyValue";
            this.lblAccuracyValue.Size = new System.Drawing.Size(47, 13);
            this.lblAccuracyValue.TabIndex = 13;
            // 
            // lblAccuracy
            // 
            this.lblAccuracy.AutoSize = true;
            this.lblAccuracy.Location = new System.Drawing.Point(36, 58);
            this.lblAccuracy.Name = "lblAccuracy";
            this.lblAccuracy.Size = new System.Drawing.Size(72, 13);
            this.lblAccuracy.TabIndex = 12;
            this.lblAccuracy.Text = "Accuracy (%):";
            // 
            // lblTestingPercValue
            // 
            this.lblTestingPercValue.BackColor = System.Drawing.Color.LightYellow;
            this.lblTestingPercValue.Location = new System.Drawing.Point(114, 87);
            this.lblTestingPercValue.Name = "lblTestingPercValue";
            this.lblTestingPercValue.Size = new System.Drawing.Size(47, 13);
            this.lblTestingPercValue.TabIndex = 11;
            // 
            // lblTestingPerc
            // 
            this.lblTestingPerc.AutoSize = true;
            this.lblTestingPerc.Location = new System.Drawing.Point(6, 87);
            this.lblTestingPerc.Name = "lblTestingPerc";
            this.lblTestingPerc.Size = new System.Drawing.Size(102, 13);
            this.lblTestingPerc.TabIndex = 10;
            this.lblTestingPerc.Text = "Testing process (%):";
            // 
            // lblTestingSampleSize
            // 
            this.lblTestingSampleSize.AutoSize = true;
            this.lblTestingSampleSize.Location = new System.Drawing.Point(104, 24);
            this.lblTestingSampleSize.Name = "lblTestingSampleSize";
            this.lblTestingSampleSize.Size = new System.Drawing.Size(135, 13);
            this.lblTestingSampleSize.TabIndex = 8;
            this.lblTestingSampleSize.Text = "Testing sample size: 10000";
            // 
            // btnDoTesting
            // 
            this.btnDoTesting.Location = new System.Drawing.Point(6, 19);
            this.btnDoTesting.Name = "btnDoTesting";
            this.btnDoTesting.Size = new System.Drawing.Size(75, 23);
            this.btnDoTesting.TabIndex = 3;
            this.btnDoTesting.Text = "Do Testing";
            this.btnDoTesting.UseVisualStyleBackColor = true;
            this.btnDoTesting.Click += new System.EventHandler(this.btnDoTesting_Click);
            // 
            // generalTimer
            // 
            this.generalTimer.Interval = 1000;
            this.generalTimer.Tick += new System.EventHandler(this.generalTimer_Tick);
            // 
            // timerTesting
            // 
            this.timerTesting.Interval = 300;
            this.timerTesting.Tick += new System.EventHandler(this.timerTesting_Tick);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(624, 221);
            this.Controls.Add(this.bgTesting);
            this.Controls.Add(this.gbTraining);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Name = "MainForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "NeuralNet for GE HC";
            this.gbTraining.ResumeLayout(false);
            this.gbTraining.PerformLayout();
            this.bgTesting.ResumeLayout(false);
            this.bgTesting.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.Button btnDoTraining;
        private System.Windows.Forms.GroupBox gbTraining;
        private System.Windows.Forms.GroupBox bgTesting;
        private System.Windows.Forms.Button btnDoTesting;
        private System.Windows.Forms.Button btnPauseTraining;
        private System.Windows.Forms.Label lblTrainingSampleSize;
        private System.Windows.Forms.ComboBox cbTrainingSampleSize;
        private System.Windows.Forms.Label lblTestingSampleSize;
        private System.Windows.Forms.Label lblTrainingPercValue;
        private System.Windows.Forms.Label lblTrainingPerc;
        private System.Windows.Forms.Timer generalTimer;
        private System.Windows.Forms.Label lblTestingPercValue;
        private System.Windows.Forms.Label lblTestingPerc;
        private System.Windows.Forms.Timer timerTesting;
        private System.Windows.Forms.Label lblAccuracyValue;
        private System.Windows.Forms.Label lblAccuracy;
    }
}

