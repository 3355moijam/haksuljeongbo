using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Invaders
{
	public partial class Form1 : Form
	{
		List<Keys> keysPressed = new List<Keys>();
		Game game;
		public Form1()
		{
			PreInit();
			InitializeComponent();
			PostInit();
		}

		private void pictureBox1_Click(object sender, EventArgs e)
		{

		}

		private void Form1_Load(object sender, EventArgs e)
		{

		}
		bool gameOver = false;
		private void Form1_KeyDown(object sender, KeyEventArgs e)
		{
			if (e.KeyCode == Keys.Q)
				Application.Exit();

			if(gameOver)
				if(e.KeyCode == Keys.S)
				{
					// code to reset the game and restart the timer
					return;
				}
			if (e.KeyCode == Keys.Space)
				game.FireShot();
			if (keysPressed.Contains(e.KeyCode))
				keysPressed.Remove(e.KeyCode);
			keysPressed.Add(e.KeyCode);
		}

		private void Form1_KeyUp(object sender, KeyEventArgs e)
		{
			if (keysPressed.Contains(e.KeyCode))
				keysPressed.Remove(e.KeyCode);
		}

		private void gameTimer_Tick(object sender, EventArgs e)
		{
			game.Go();
			foreach (Keys key in keysPressed)
			{
				if(key == Keys.Left)
				{
					game.MovePlayer(Direction.Left);
					return;
				}
				else if (key == Keys.Right)
				{
					game.MovePlayer(Direction.Right);
					return;
				}
			}
			
		}

		private void PreInit()
		{
			game = new Game();
			game.AddPictureBox = this.Controls.Add;
			game.RemovePictureBox = this.Controls.Remove;
		}

		private void PostInit()
		{
			game.SetPlayer(new PlayerShip(pictureBox1));
		}
	}

}
