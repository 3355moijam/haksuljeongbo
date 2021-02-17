
namespace TheQuest
{
	partial class Form1
	{
		/// <summary>
		///  Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

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
			this.Map = new System.Windows.Forms.PictureBox();
			this.MoveUp = new System.Windows.Forms.Button();
			this.MoveLeft = new System.Windows.Forms.Button();
			this.MoveRight = new System.Windows.Forms.Button();
			this.MoveDown = new System.Windows.Forms.Button();
			this.MoveGroup = new System.Windows.Forms.GroupBox();
			this.AttackGroup = new System.Windows.Forms.GroupBox();
			this.AttackDown = new System.Windows.Forms.Button();
			this.AttackLeft = new System.Windows.Forms.Button();
			this.AttackRight = new System.Windows.Forms.Button();
			this.AttackUp = new System.Windows.Forms.Button();
			this.label1 = new System.Windows.Forms.Label();
			this.label2 = new System.Windows.Forms.Label();
			this.label3 = new System.Windows.Forms.Label();
			this.label4 = new System.Windows.Forms.Label();
			this.PlayerHP = new System.Windows.Forms.Label();
			this.BatHP = new System.Windows.Forms.Label();
			this.GhostHP = new System.Windows.Forms.Label();
			this.GhoulHP = new System.Windows.Forms.Label();
			this.HPGroup = new System.Windows.Forms.GroupBox();
			((System.ComponentModel.ISupportInitialize)(this.Map)).BeginInit();
			this.MoveGroup.SuspendLayout();
			this.AttackGroup.SuspendLayout();
			this.HPGroup.SuspendLayout();
			this.SuspendLayout();
			// 
			// Map
			// 
			this.Map.Image = ((System.Drawing.Image)(resources.GetObject("Map.Image")));
			this.Map.Location = new System.Drawing.Point(1, 1);
			this.Map.Name = "Map";
			this.Map.Size = new System.Drawing.Size(600, 400);
			this.Map.TabIndex = 0;
			this.Map.TabStop = false;
			// 
			// MoveUp
			// 
			this.MoveUp.Location = new System.Drawing.Point(50, 18);
			this.MoveUp.Name = "MoveUp";
			this.MoveUp.Size = new System.Drawing.Size(75, 23);
			this.MoveUp.TabIndex = 1;
			this.MoveUp.Text = "Up";
			this.MoveUp.UseVisualStyleBackColor = true;
			// 
			// MoveLeft
			// 
			this.MoveLeft.Location = new System.Drawing.Point(9, 47);
			this.MoveLeft.Name = "MoveLeft";
			this.MoveLeft.Size = new System.Drawing.Size(75, 23);
			this.MoveLeft.TabIndex = 1;
			this.MoveLeft.Text = "Left";
			this.MoveLeft.UseVisualStyleBackColor = true;
			// 
			// MoveRight
			// 
			this.MoveRight.Location = new System.Drawing.Point(90, 47);
			this.MoveRight.Name = "MoveRight";
			this.MoveRight.Size = new System.Drawing.Size(75, 23);
			this.MoveRight.TabIndex = 1;
			this.MoveRight.Text = "Right";
			this.MoveRight.UseVisualStyleBackColor = true;
			// 
			// MoveDown
			// 
			this.MoveDown.Location = new System.Drawing.Point(50, 76);
			this.MoveDown.Name = "MoveDown";
			this.MoveDown.Size = new System.Drawing.Size(75, 23);
			this.MoveDown.TabIndex = 1;
			this.MoveDown.Text = "Down";
			this.MoveDown.UseVisualStyleBackColor = true;
			// 
			// MoveGroup
			// 
			this.MoveGroup.Controls.Add(this.MoveDown);
			this.MoveGroup.Controls.Add(this.MoveLeft);
			this.MoveGroup.Controls.Add(this.MoveRight);
			this.MoveGroup.Controls.Add(this.MoveUp);
			this.MoveGroup.Location = new System.Drawing.Point(610, 23);
			this.MoveGroup.Name = "MoveGroup";
			this.MoveGroup.Size = new System.Drawing.Size(178, 109);
			this.MoveGroup.TabIndex = 2;
			this.MoveGroup.TabStop = false;
			this.MoveGroup.Text = "Move";
			// 
			// AttackGroup
			// 
			this.AttackGroup.Controls.Add(this.AttackDown);
			this.AttackGroup.Controls.Add(this.AttackLeft);
			this.AttackGroup.Controls.Add(this.AttackRight);
			this.AttackGroup.Controls.Add(this.AttackUp);
			this.AttackGroup.Location = new System.Drawing.Point(610, 177);
			this.AttackGroup.Name = "AttackGroup";
			this.AttackGroup.Size = new System.Drawing.Size(178, 109);
			this.AttackGroup.TabIndex = 3;
			this.AttackGroup.TabStop = false;
			this.AttackGroup.Text = "Attack";
			// 
			// AttackDown
			// 
			this.AttackDown.Location = new System.Drawing.Point(50, 76);
			this.AttackDown.Name = "AttackDown";
			this.AttackDown.Size = new System.Drawing.Size(75, 23);
			this.AttackDown.TabIndex = 1;
			this.AttackDown.Text = "Down";
			this.AttackDown.UseVisualStyleBackColor = true;
			// 
			// AttackLeft
			// 
			this.AttackLeft.Location = new System.Drawing.Point(9, 47);
			this.AttackLeft.Name = "AttackLeft";
			this.AttackLeft.Size = new System.Drawing.Size(75, 23);
			this.AttackLeft.TabIndex = 1;
			this.AttackLeft.Text = "Left";
			this.AttackLeft.UseVisualStyleBackColor = true;
			// 
			// AttackRight
			// 
			this.AttackRight.Location = new System.Drawing.Point(90, 47);
			this.AttackRight.Name = "AttackRight";
			this.AttackRight.Size = new System.Drawing.Size(75, 23);
			this.AttackRight.TabIndex = 1;
			this.AttackRight.Text = "Right";
			this.AttackRight.UseVisualStyleBackColor = true;
			// 
			// AttackUp
			// 
			this.AttackUp.Location = new System.Drawing.Point(50, 18);
			this.AttackUp.Name = "AttackUp";
			this.AttackUp.Size = new System.Drawing.Size(75, 23);
			this.AttackUp.TabIndex = 1;
			this.AttackUp.Text = "Up";
			this.AttackUp.UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Location = new System.Drawing.Point(12, 22);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(39, 15);
			this.label1.TabIndex = 4;
			this.label1.Text = "Player";
			// 
			// label2
			// 
			this.label2.AutoSize = true;
			this.label2.Location = new System.Drawing.Point(12, 47);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(24, 15);
			this.label2.TabIndex = 4;
			this.label2.Text = "Bat";
			// 
			// label3
			// 
			this.label3.AutoSize = true;
			this.label3.Location = new System.Drawing.Point(12, 71);
			this.label3.Name = "label3";
			this.label3.Size = new System.Drawing.Size(38, 15);
			this.label3.TabIndex = 4;
			this.label3.Text = "Ghost";
			// 
			// label4
			// 
			this.label4.AutoSize = true;
			this.label4.Location = new System.Drawing.Point(12, 97);
			this.label4.Name = "label4";
			this.label4.Size = new System.Drawing.Size(39, 15);
			this.label4.TabIndex = 4;
			this.label4.Text = "Ghoul";
			// 
			// PlayerHP
			// 
			this.PlayerHP.AutoSize = true;
			this.PlayerHP.Location = new System.Drawing.Point(65, 22);
			this.PlayerHP.Name = "PlayerHP";
			this.PlayerHP.Size = new System.Drawing.Size(14, 15);
			this.PlayerHP.TabIndex = 4;
			this.PlayerHP.Text = "6";
			// 
			// BatHP
			// 
			this.BatHP.AutoSize = true;
			this.BatHP.Location = new System.Drawing.Point(65, 47);
			this.BatHP.Name = "BatHP";
			this.BatHP.Size = new System.Drawing.Size(14, 15);
			this.BatHP.TabIndex = 4;
			this.BatHP.Text = "6";
			// 
			// GhostHP
			// 
			this.GhostHP.AutoSize = true;
			this.GhostHP.Location = new System.Drawing.Point(65, 71);
			this.GhostHP.Name = "GhostHP";
			this.GhostHP.Size = new System.Drawing.Size(14, 15);
			this.GhostHP.TabIndex = 4;
			this.GhostHP.Text = "8";
			// 
			// GhoulHP
			// 
			this.GhoulHP.AutoSize = true;
			this.GhoulHP.Location = new System.Drawing.Point(65, 97);
			this.GhoulHP.Name = "GhoulHP";
			this.GhoulHP.Size = new System.Drawing.Size(21, 15);
			this.GhoulHP.TabIndex = 4;
			this.GhoulHP.Text = "10";
			// 
			// HPGroup
			// 
			this.HPGroup.Controls.Add(this.GhoulHP);
			this.HPGroup.Controls.Add(this.label4);
			this.HPGroup.Controls.Add(this.GhostHP);
			this.HPGroup.Controls.Add(this.BatHP);
			this.HPGroup.Controls.Add(this.label3);
			this.HPGroup.Controls.Add(this.PlayerHP);
			this.HPGroup.Controls.Add(this.label2);
			this.HPGroup.Controls.Add(this.label1);
			this.HPGroup.Location = new System.Drawing.Point(607, 292);
			this.HPGroup.Name = "HPGroup";
			this.HPGroup.Size = new System.Drawing.Size(180, 118);
			this.HPGroup.TabIndex = 5;
			this.HPGroup.TabStop = false;
			this.HPGroup.Text = "HP";
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(800, 450);
			this.Controls.Add(this.HPGroup);
			this.Controls.Add(this.AttackGroup);
			this.Controls.Add(this.MoveGroup);
			this.Controls.Add(this.Map);
			this.Name = "Form1";
			this.Text = "The Quest";
			((System.ComponentModel.ISupportInitialize)(this.Map)).EndInit();
			this.MoveGroup.ResumeLayout(false);
			this.AttackGroup.ResumeLayout(false);
			this.HPGroup.ResumeLayout(false);
			this.HPGroup.PerformLayout();
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.PictureBox Map;
		private System.Windows.Forms.Button MoveUp;
		private System.Windows.Forms.Button MoveLeft;
		private System.Windows.Forms.Button MoveRight;
		private System.Windows.Forms.Button MoveDown;
		private System.Windows.Forms.GroupBox MoveGroup;
		private System.Windows.Forms.GroupBox AttackGroup;
		private System.Windows.Forms.Button AttackDown;
		private System.Windows.Forms.Button AttackLeft;
		private System.Windows.Forms.Button AttackRight;
		private System.Windows.Forms.Button AttackUp;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.Label label3;
		private System.Windows.Forms.Label label4;
		private System.Windows.Forms.Label PlayerHP;
		private System.Windows.Forms.Label BatHP;
		private System.Windows.Forms.Label GhostHP;
		private System.Windows.Forms.Label GhoulHP;
		private System.Windows.Forms.GroupBox HPGroup;
	}
}

