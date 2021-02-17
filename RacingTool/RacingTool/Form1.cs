using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace RacingTool
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();
		}

		private void groupBox1_Enter(object sender, EventArgs e)
		{

		}

		private void Form1_Load(object sender, EventArgs e)
		{

		}

		private void SaveForm_Click(object sender, EventArgs e)
		{

		}

		private void TrackLength_TextChanged(object sender, EventArgs e)
		{

		}

		private void NumberOfDog_TextChanged(object sender, EventArgs e)
		{

		}

		private void ChooseName_SelectedIndexChanged(object sender, EventArgs e)
		{
			try
			{
				var data = guyData.Find(x => x.Key == ChooseName.Text);

				GuyName.Text = data.Key;
				InitBuck.Text = data.Value.ToString();
			}
			catch(ArgumentNullException error)
			{
				return;
			}
		}

		private void DogMinSpeed_TextChanged(object sender, EventArgs e)
		{

		}

		private void DogMaxSpeed_TextChanged(object sender, EventArgs e)
		{

		}

		private void MinBettingBuck_TextChanged(object sender, EventArgs e)
		{

		}

		private void MaxBettingBuck_TextChanged(object sender, EventArgs e)
		{

		}

		private void GuyName_TextChanged(object sender, EventArgs e)
		{

		}

		private void InitBuck_TextChanged(object sender, EventArgs e)
		{

		}

		private void ChangeGuy_Click(object sender, EventArgs e)
		{
			try
			{
				guyData.Remove(guyData.Find(x => x.Key == ChooseName.Text));
				guyData.Add(new KeyValuePair<string, int>(ChooseName.Text, Int32.Parse(InitBuck.Text)));

			}
			catch (ArgumentNullException error)
			{
				

			}
		}

		private void RaceStart_Click(object sender, EventArgs e)
		{
			while(true)
			{
				bool b1 = greyhounds[0].Run();
				bool b2 = greyhounds[1].Run();
				bool b3 = greyhounds[2].Run();
				bool b4 = greyhounds[3].Run();
				if (b1 || b2 || b3 || b4)
					break;
			}
			//if(b1)
				// 승리보상 제공
		}

		private void TrackImage_Click(object sender, EventArgs e)
		{

		}

		private void pictureBox1_Click(object sender, EventArgs e)
		{

		}
	}
}
