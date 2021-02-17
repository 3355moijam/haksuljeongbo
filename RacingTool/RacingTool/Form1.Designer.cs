using System.Collections.Generic;
namespace RacingTool
{
	partial class Form1
	{
		/// <summary>
		///  Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;
		private List<KeyValuePair<string, int>> guyData = new List<KeyValuePair<string, int>>();
		private Greyhound[] greyhounds = new Greyhound[4];
		/// <summary>
		///  Clean up any resources being used.
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
		///  Required method for Designer support - do not modify
		///  the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
			this.TrackGroup = new System.Windows.Forms.GroupBox();
			this.NumberOfDog = new System.Windows.Forms.TextBox();
			this.TrackLength = new System.Windows.Forms.TextBox();
			this.label2 = new System.Windows.Forms.Label();
			this.label1 = new System.Windows.Forms.Label();
			this.groupBox2 = new System.Windows.Forms.GroupBox();
			this.DogMaxSpeed = new System.Windows.Forms.TextBox();
			this.DogMinSpeed = new System.Windows.Forms.TextBox();
			this.label4 = new System.Windows.Forms.Label();
			this.label3 = new System.Windows.Forms.Label();
			this.ChooseName = new System.Windows.Forms.ComboBox();
			this.groupBox3 = new System.Windows.Forms.GroupBox();
			this.ChangeGuy = new System.Windows.Forms.Button();
			this.InitBuck = new System.Windows.Forms.TextBox();
			this.label5 = new System.Windows.Forms.Label();
			this.GuyName = new System.Windows.Forms.TextBox();
			this.label6 = new System.Windows.Forms.Label();
			this.label7 = new System.Windows.Forms.Label();
			this.groupBox4 = new System.Windows.Forms.GroupBox();
			this.MaxBettingBuck = new System.Windows.Forms.TextBox();
			this.label8 = new System.Windows.Forms.Label();
			this.MinBettingBuck = new System.Windows.Forms.TextBox();
			this.label9 = new System.Windows.Forms.Label();
			this.SaveForm = new System.Windows.Forms.Button();
			this.TrackImage = new System.Windows.Forms.PictureBox();
			this.pictureBox1 = new System.Windows.Forms.PictureBox();
			this.pictureBox2 = new System.Windows.Forms.PictureBox();
			this.pictureBox3 = new System.Windows.Forms.PictureBox();
			this.pictureBox4 = new System.Windows.Forms.PictureBox();
			this.SelectGuy = new System.Windows.Forms.ComboBox();
			this.BettingBucks = new System.Windows.Forms.TextBox();
			this.label10 = new System.Windows.Forms.Label();
			this.label11 = new System.Windows.Forms.Label();
			this.label12 = new System.Windows.Forms.Label();
			this.BetButton = new System.Windows.Forms.Button();
			this.RaceStart = new System.Windows.Forms.Button();
			this.label13 = new System.Windows.Forms.Label();
			this.label14 = new System.Windows.Forms.Label();
			this.JoeBucks = new System.Windows.Forms.Label();
			this.BobBucks = new System.Windows.Forms.Label();
			this.AlBucks = new System.Windows.Forms.Label();
			this.label15 = new System.Windows.Forms.Label();
			this.TargetDog = new System.Windows.Forms.ComboBox();
			this.TrackGroup.SuspendLayout();
			this.groupBox2.SuspendLayout();
			this.groupBox3.SuspendLayout();
			this.groupBox4.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.TrackImage)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.pictureBox3)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.pictureBox4)).BeginInit();
			this.SuspendLayout();

			guyData.Add(new KeyValuePair<string, int>("Joe", 50));
			guyData.Add(new KeyValuePair<string, int>("Bob", 75));
			guyData.Add(new KeyValuePair<string, int>("Al", 45));

			// 
			// TrackGroup
			// 
			this.TrackGroup.Controls.Add(this.NumberOfDog);
			this.TrackGroup.Controls.Add(this.TrackLength);
			this.TrackGroup.Controls.Add(this.label2);
			this.TrackGroup.Controls.Add(this.label1);
			this.TrackGroup.Location = new System.Drawing.Point(40, 353);
			this.TrackGroup.Name = "TrackGroup";
			this.TrackGroup.Size = new System.Drawing.Size(333, 111);
			this.TrackGroup.TabIndex = 0;
			this.TrackGroup.TabStop = false;
			this.TrackGroup.Text = "Track";
			this.TrackGroup.Enter += new System.EventHandler(this.groupBox1_Enter);
			// 
			// NumberOfDog
			// 
			this.NumberOfDog.Location = new System.Drawing.Point(126, 65);
			this.NumberOfDog.Name = "NumberOfDog";
			this.NumberOfDog.Size = new System.Drawing.Size(100, 23);
			this.NumberOfDog.TabIndex = 3;
			this.NumberOfDog.Text = "4";
			this.NumberOfDog.TextChanged += new System.EventHandler(this.NumberOfDog_TextChanged);
			// 
			// TrackLength
			// 
			this.TrackLength.Location = new System.Drawing.Point(126, 31);
			this.TrackLength.Name = "TrackLength";
			this.TrackLength.Size = new System.Drawing.Size(100, 23);
			this.TrackLength.TabIndex = 2;
			this.TrackLength.Text = "10";
			this.TrackLength.TextChanged += new System.EventHandler(this.TrackLength_TextChanged);
			// 
			// label2
			// 
			this.label2.AutoSize = true;
			this.label2.Location = new System.Drawing.Point(10, 68);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(71, 15);
			this.label2.TabIndex = 1;
			this.label2.Text = "경주견 숫자";
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Location = new System.Drawing.Point(10, 34);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(31, 15);
			this.label1.TabIndex = 0;
			this.label1.Text = "길이";
			// 
			// groupBox2
			// 
			this.groupBox2.Controls.Add(this.DogMaxSpeed);
			this.groupBox2.Controls.Add(this.DogMinSpeed);
			this.groupBox2.Controls.Add(this.label4);
			this.groupBox2.Controls.Add(this.label3);
			this.groupBox2.Location = new System.Drawing.Point(40, 480);
			this.groupBox2.Name = "groupBox2";
			this.groupBox2.Size = new System.Drawing.Size(332, 121);
			this.groupBox2.TabIndex = 1;
			this.groupBox2.TabStop = false;
			this.groupBox2.Text = "Greyhound";
			// 
			// DogMaxSpeed
			// 
			this.DogMaxSpeed.Location = new System.Drawing.Point(126, 70);
			this.DogMaxSpeed.Name = "DogMaxSpeed";
			this.DogMaxSpeed.Size = new System.Drawing.Size(100, 23);
			this.DogMaxSpeed.TabIndex = 7;
			this.DogMaxSpeed.Text = "10";
			this.DogMaxSpeed.TextChanged += new System.EventHandler(this.DogMaxSpeed_TextChanged);
			// 
			// DogMinSpeed
			// 
			this.DogMinSpeed.Location = new System.Drawing.Point(126, 36);
			this.DogMinSpeed.Name = "DogMinSpeed";
			this.DogMinSpeed.Size = new System.Drawing.Size(100, 23);
			this.DogMinSpeed.TabIndex = 6;
			this.DogMinSpeed.Text = "1";
			this.DogMinSpeed.TextChanged += new System.EventHandler(this.DogMinSpeed_TextChanged);
			// 
			// label4
			// 
			this.label4.AutoSize = true;
			this.label4.Location = new System.Drawing.Point(10, 39);
			this.label4.Name = "label4";
			this.label4.Size = new System.Drawing.Size(55, 15);
			this.label4.TabIndex = 4;
			this.label4.Text = "최소속도";
			// 
			// label3
			// 
			this.label3.AutoSize = true;
			this.label3.Location = new System.Drawing.Point(10, 73);
			this.label3.Name = "label3";
			this.label3.Size = new System.Drawing.Size(55, 15);
			this.label3.TabIndex = 5;
			this.label3.Text = "최대속도";
			// 
			// ChooseName
			// 
			this.ChooseName.FormattingEnabled = true;
			this.ChooseName.Items.AddRange(new object[] {
            "Joe",
            "Bob",
            "Al"});
			this.ChooseName.Location = new System.Drawing.Point(96, 38);
			this.ChooseName.Name = "ChooseName";
			this.ChooseName.Size = new System.Drawing.Size(121, 23);
			this.ChooseName.TabIndex = 2;
			this.ChooseName.SelectedIndexChanged += new System.EventHandler(this.ChooseName_SelectedIndexChanged);
			// 
			// groupBox3
			// 
			this.groupBox3.Controls.Add(this.ChangeGuy);
			this.groupBox3.Controls.Add(this.InitBuck);
			this.groupBox3.Controls.Add(this.label5);
			this.groupBox3.Controls.Add(this.GuyName);
			this.groupBox3.Controls.Add(this.label6);
			this.groupBox3.Controls.Add(this.ChooseName);
			this.groupBox3.Controls.Add(this.label7);
			this.groupBox3.Location = new System.Drawing.Point(687, 345);
			this.groupBox3.Name = "groupBox3";
			this.groupBox3.Size = new System.Drawing.Size(428, 256);
			this.groupBox3.TabIndex = 3;
			this.groupBox3.TabStop = false;
			this.groupBox3.Text = "Guy";
			// 
			// ChangeGuy
			// 
			this.ChangeGuy.Location = new System.Drawing.Point(324, 200);
			this.ChangeGuy.Name = "ChangeGuy";
			this.ChangeGuy.Size = new System.Drawing.Size(80, 28);
			this.ChangeGuy.TabIndex = 8;
			this.ChangeGuy.Text = "수정";
			this.ChangeGuy.UseVisualStyleBackColor = true;
			this.ChangeGuy.Click += new System.EventHandler(this.ChangeGuy_Click);
			// 
			// InitBuck
			// 
			this.InitBuck.Location = new System.Drawing.Point(137, 137);
			this.InitBuck.Name = "InitBuck";
			this.InitBuck.Size = new System.Drawing.Size(100, 23);
			this.InitBuck.TabIndex = 7;
			this.InitBuck.Text = "0";
			this.InitBuck.TextChanged += new System.EventHandler(this.InitBuck_TextChanged);
			// 
			// label5
			// 
			this.label5.AutoSize = true;
			this.label5.Location = new System.Drawing.Point(22, 41);
			this.label5.Name = "label5";
			this.label5.Size = new System.Drawing.Size(31, 15);
			this.label5.TabIndex = 3;
			this.label5.Text = "선택";
			// 
			// GuyName
			// 
			this.GuyName.Location = new System.Drawing.Point(137, 103);
			this.GuyName.Name = "GuyName";
			this.GuyName.Size = new System.Drawing.Size(100, 23);
			this.GuyName.TabIndex = 6;
			this.GuyName.TextChanged += new System.EventHandler(this.GuyName_TextChanged);
			// 
			// label6
			// 
			this.label6.AutoSize = true;
			this.label6.Location = new System.Drawing.Point(21, 140);
			this.label6.Name = "label6";
			this.label6.Size = new System.Drawing.Size(59, 15);
			this.label6.TabIndex = 5;
			this.label6.Text = "초기 자금";
			// 
			// label7
			// 
			this.label7.AutoSize = true;
			this.label7.Location = new System.Drawing.Point(21, 106);
			this.label7.Name = "label7";
			this.label7.Size = new System.Drawing.Size(31, 15);
			this.label7.TabIndex = 4;
			this.label7.Text = "이름";
			// 
			// groupBox4
			// 
			this.groupBox4.Controls.Add(this.MaxBettingBuck);
			this.groupBox4.Controls.Add(this.label8);
			this.groupBox4.Controls.Add(this.MinBettingBuck);
			this.groupBox4.Controls.Add(this.label9);
			this.groupBox4.Location = new System.Drawing.Point(399, 484);
			this.groupBox4.Name = "groupBox4";
			this.groupBox4.Size = new System.Drawing.Size(258, 117);
			this.groupBox4.TabIndex = 4;
			this.groupBox4.TabStop = false;
			this.groupBox4.Text = "Betting";
			// 
			// MaxBettingBuck
			// 
			this.MaxBettingBuck.Location = new System.Drawing.Point(139, 68);
			this.MaxBettingBuck.Name = "MaxBettingBuck";
			this.MaxBettingBuck.Size = new System.Drawing.Size(100, 23);
			this.MaxBettingBuck.TabIndex = 3;
			this.MaxBettingBuck.Text = "15";
			this.MaxBettingBuck.TextChanged += new System.EventHandler(this.MaxBettingBuck_TextChanged);
			// 
			// label8
			// 
			this.label8.AutoSize = true;
			this.label8.Location = new System.Drawing.Point(23, 37);
			this.label8.Name = "label8";
			this.label8.Size = new System.Drawing.Size(55, 15);
			this.label8.TabIndex = 0;
			this.label8.Text = "최소금액";
			// 
			// MinBettingBuck
			// 
			this.MinBettingBuck.Location = new System.Drawing.Point(139, 34);
			this.MinBettingBuck.Name = "MinBettingBuck";
			this.MinBettingBuck.Size = new System.Drawing.Size(100, 23);
			this.MinBettingBuck.TabIndex = 2;
			this.MinBettingBuck.Text = "5";
			this.MinBettingBuck.TextChanged += new System.EventHandler(this.MinBettingBuck_TextChanged);
			// 
			// label9
			// 
			this.label9.AutoSize = true;
			this.label9.Location = new System.Drawing.Point(23, 71);
			this.label9.Name = "label9";
			this.label9.Size = new System.Drawing.Size(55, 15);
			this.label9.TabIndex = 1;
			this.label9.Text = "최대금액";
			// 
			// SaveForm
			// 
			this.SaveForm.Location = new System.Drawing.Point(1111, 621);
			this.SaveForm.Name = "SaveForm";
			this.SaveForm.Size = new System.Drawing.Size(75, 23);
			this.SaveForm.TabIndex = 5;
			this.SaveForm.Text = "저장";
			this.SaveForm.UseVisualStyleBackColor = true;
			this.SaveForm.Click += new System.EventHandler(this.SaveForm_Click);
			// 
			// TrackImage
			// 
			this.TrackImage.Image = ((System.Drawing.Image)(resources.GetObject("TrackImage.Image")));
			this.TrackImage.Location = new System.Drawing.Point(40, 36);
			this.TrackImage.Name = "TrackImage";
			this.TrackImage.Size = new System.Drawing.Size(600, 200);
			this.TrackImage.TabIndex = 6;
			this.TrackImage.TabStop = false;
			this.TrackImage.Click += new System.EventHandler(this.TrackImage_Click);
			// 
			// pictureBox1
			// 
			this.pictureBox1.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox1.Image")));
			this.pictureBox1.Location = new System.Drawing.Point(50, 50);
			this.pictureBox1.Name = "pictureBox1";
			this.pictureBox1.Size = new System.Drawing.Size(75, 20);
			this.pictureBox1.TabIndex = 7;
			this.pictureBox1.TabStop = false;
			this.pictureBox1.Click += new System.EventHandler(this.pictureBox1_Click);
			// 
			// pictureBox2
			// 
			this.pictureBox2.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox2.Image")));
			this.pictureBox2.Location = new System.Drawing.Point(50, 100);
			this.pictureBox2.Name = "pictureBox2";
			this.pictureBox2.Size = new System.Drawing.Size(75, 20);
			this.pictureBox2.TabIndex = 7;
			this.pictureBox2.TabStop = false;
			this.pictureBox2.Click += new System.EventHandler(this.pictureBox1_Click);
			// 
			// pictureBox3
			// 
			this.pictureBox3.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox3.Image")));
			this.pictureBox3.Location = new System.Drawing.Point(50, 150);
			this.pictureBox3.Name = "pictureBox3";
			this.pictureBox3.Size = new System.Drawing.Size(75, 20);
			this.pictureBox3.TabIndex = 7;
			this.pictureBox3.TabStop = false;
			this.pictureBox3.Click += new System.EventHandler(this.pictureBox1_Click);
			// 
			// pictureBox4
			// 
			this.pictureBox4.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox4.Image")));
			this.pictureBox4.Location = new System.Drawing.Point(50, 200);
			this.pictureBox4.Name = "pictureBox4";
			this.pictureBox4.Size = new System.Drawing.Size(75, 20);
			this.pictureBox4.TabIndex = 7;
			this.pictureBox4.TabStop = false;
			this.pictureBox4.Click += new System.EventHandler(this.pictureBox1_Click);
			// 
			// SelectGuy
			// 
			this.SelectGuy.FormattingEnabled = true;
			this.SelectGuy.Items.AddRange(new object[] {
            "Joe",
            "Bob",
            "Al"});
			this.SelectGuy.Location = new System.Drawing.Point(96, 280);
			this.SelectGuy.Name = "SelectGuy";
			this.SelectGuy.Size = new System.Drawing.Size(121, 23);
			this.SelectGuy.TabIndex = 9;
			// 
			// BettingBucks
			// 
			this.BettingBucks.Location = new System.Drawing.Point(439, 280);
			this.BettingBucks.Name = "BettingBucks";
			this.BettingBucks.Size = new System.Drawing.Size(77, 23);
			this.BettingBucks.TabIndex = 8;
			// 
			// label10
			// 
			this.label10.AutoSize = true;
			this.label10.Location = new System.Drawing.Point(724, 50);
			this.label10.Name = "label10";
			this.label10.Size = new System.Drawing.Size(31, 15);
			this.label10.TabIndex = 10;
			this.label10.Text = "Joe :";
			// 
			// label11
			// 
			this.label11.AutoSize = true;
			this.label11.Location = new System.Drawing.Point(238, 283);
			this.label11.Name = "label11";
			this.label11.Size = new System.Drawing.Size(30, 15);
			this.label11.TabIndex = 10;
			this.label11.Text = "Dog";
			// 
			// label12
			// 
			this.label12.AutoSize = true;
			this.label12.Location = new System.Drawing.Point(388, 283);
			this.label12.Name = "label12";
			this.label12.Size = new System.Drawing.Size(45, 15);
			this.label12.TabIndex = 10;
			this.label12.Text = "Betting";
			// 
			// BetButton
			// 
			this.BetButton.Location = new System.Drawing.Point(577, 275);
			this.BetButton.Name = "BetButton";
			this.BetButton.Size = new System.Drawing.Size(80, 28);
			this.BetButton.TabIndex = 8;
			this.BetButton.Text = "베팅";
			this.BetButton.UseVisualStyleBackColor = true;
			this.BetButton.Click += new System.EventHandler(this.ChangeGuy_Click);
			// 
			// RaceStart
			// 
			this.RaceStart.Location = new System.Drawing.Point(687, 275);
			this.RaceStart.Name = "RaceStart";
			this.RaceStart.Size = new System.Drawing.Size(80, 28);
			this.RaceStart.TabIndex = 8;
			this.RaceStart.Text = "출발";
			this.RaceStart.UseVisualStyleBackColor = true;
			this.RaceStart.Click += new System.EventHandler(this.RaceStart_Click);
			// 
			// label13
			// 
			this.label13.AutoSize = true;
			this.label13.Location = new System.Drawing.Point(724, 90);
			this.label13.Name = "label13";
			this.label13.Size = new System.Drawing.Size(35, 15);
			this.label13.TabIndex = 10;
			this.label13.Text = "Bob :";
			// 
			// label14
			// 
			this.label14.AutoSize = true;
			this.label14.Location = new System.Drawing.Point(724, 132);
			this.label14.Name = "label14";
			this.label14.Size = new System.Drawing.Size(25, 15);
			this.label14.TabIndex = 10;
			this.label14.Text = "Al :";
			// 
			// JoeBucks
			// 
			this.JoeBucks.AutoSize = true;
			this.JoeBucks.Location = new System.Drawing.Point(774, 50);
			this.JoeBucks.Name = "JoeBucks";
			this.JoeBucks.Size = new System.Drawing.Size(21, 15);
			this.JoeBucks.TabIndex = 10;
			this.JoeBucks.Text = "0$";
			// 
			// BobBucks
			// 
			this.BobBucks.AutoSize = true;
			this.BobBucks.Location = new System.Drawing.Point(774, 90);
			this.BobBucks.Name = "BobBucks";
			this.BobBucks.Size = new System.Drawing.Size(21, 15);
			this.BobBucks.TabIndex = 10;
			this.BobBucks.Text = "0$";
			// 
			// AlBucks
			// 
			this.AlBucks.AutoSize = true;
			this.AlBucks.Location = new System.Drawing.Point(774, 132);
			this.AlBucks.Name = "AlBucks";
			this.AlBucks.Size = new System.Drawing.Size(21, 15);
			this.AlBucks.TabIndex = 10;
			this.AlBucks.Text = "0$";
			// 
			// label15
			// 
			this.label15.AutoSize = true;
			this.label15.Location = new System.Drawing.Point(50, 283);
			this.label15.Name = "label15";
			this.label15.Size = new System.Drawing.Size(28, 15);
			this.label15.TabIndex = 10;
			this.label15.Text = "Guy";
			// 
			// TargetDog
			// 
			this.TargetDog.FormattingEnabled = true;
			this.TargetDog.Items.AddRange(new object[] {
            "1",
            "2",
            "3",
            "4"});
			this.TargetDog.Location = new System.Drawing.Point(274, 280);
			this.TargetDog.Name = "TargetDog";
			this.TargetDog.Size = new System.Drawing.Size(98, 23);
			this.TargetDog.TabIndex = 9;
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(1230, 656);
			this.Controls.Add(this.RaceStart);
			this.Controls.Add(this.BetButton);
			this.Controls.Add(this.label12);
			this.Controls.Add(this.label15);
			this.Controls.Add(this.label11);
			this.Controls.Add(this.AlBucks);
			this.Controls.Add(this.label14);
			this.Controls.Add(this.BobBucks);
			this.Controls.Add(this.JoeBucks);
			this.Controls.Add(this.label13);
			this.Controls.Add(this.label10);
			this.Controls.Add(this.TargetDog);
			this.Controls.Add(this.SelectGuy);
			this.Controls.Add(this.BettingBucks);
			this.Controls.Add(this.pictureBox4);
			this.Controls.Add(this.pictureBox3);
			this.Controls.Add(this.pictureBox2);
			this.Controls.Add(this.pictureBox1);
			this.Controls.Add(this.TrackImage);
			this.Controls.Add(this.SaveForm);
			this.Controls.Add(this.groupBox4);
			this.Controls.Add(this.groupBox3);
			this.Controls.Add(this.groupBox2);
			this.Controls.Add(this.TrackGroup);
			this.Name = "Form1";
			this.Text = "Racing";
			this.Load += new System.EventHandler(this.Form1_Load);
			this.TrackGroup.ResumeLayout(false);
			this.TrackGroup.PerformLayout();
			this.groupBox2.ResumeLayout(false);
			this.groupBox2.PerformLayout();
			this.groupBox3.ResumeLayout(false);
			this.groupBox3.PerformLayout();
			this.groupBox4.ResumeLayout(false);
			this.groupBox4.PerformLayout();
			((System.ComponentModel.ISupportInitialize)(this.TrackImage)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.pictureBox3)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.pictureBox4)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.GroupBox TrackGroup;
		private System.Windows.Forms.TextBox NumberOfDog;
		private System.Windows.Forms.TextBox TrackLength;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.GroupBox groupBox2;
		private System.Windows.Forms.TextBox DogMaxSpeed;
		private System.Windows.Forms.TextBox DogMinSpeed;
		private System.Windows.Forms.Label label4;
		private System.Windows.Forms.Label label3;
		private System.Windows.Forms.ComboBox ChooseName;
		private System.Windows.Forms.GroupBox groupBox3;
		private System.Windows.Forms.Button ChangeGuy;
		private System.Windows.Forms.TextBox InitBuck;
		private System.Windows.Forms.Label label5;
		private System.Windows.Forms.TextBox GuyName;
		private System.Windows.Forms.Label label6;
		private System.Windows.Forms.Label label7;
		private System.Windows.Forms.GroupBox groupBox4;
		private System.Windows.Forms.TextBox MaxBettingBuck;
		private System.Windows.Forms.Label label8;
		private System.Windows.Forms.TextBox MinBettingBuck;
		private System.Windows.Forms.Label label9;
		private System.Windows.Forms.Button SaveForm;
		private System.Windows.Forms.PictureBox TrackImage;
		private System.Windows.Forms.PictureBox pictureBox1;
		private System.Windows.Forms.PictureBox pictureBox2;
		private System.Windows.Forms.PictureBox pictureBox3;
		private System.Windows.Forms.PictureBox pictureBox4;
		private System.Windows.Forms.ComboBox SelectGuy;
		private System.Windows.Forms.TextBox BettingBucks;
		private System.Windows.Forms.Label label10;
		private System.Windows.Forms.Label label11;
		private System.Windows.Forms.Label label12;
		private System.Windows.Forms.Button BetButton;
		private System.Windows.Forms.Button RaceStart;
		private System.Windows.Forms.Label label13;
		private System.Windows.Forms.Label label14;
		private System.Windows.Forms.Label JoeBucks;
		private System.Windows.Forms.Label BobBucks;
		private System.Windows.Forms.Label AlBucks;
		private System.Windows.Forms.Label label15;
		private System.Windows.Forms.ComboBox TargetDog;
	}
}

