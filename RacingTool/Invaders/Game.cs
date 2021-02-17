using System;
using System.Collections.Generic;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Invaders
{
	delegate void AddControl(Control control);
	class Game
	{
		int score = 0;
		int livesLeft = 2;
		int wave = 0;
		int framesSkipped = 0;

		Rectangle boundaries;
		Random random;
		public AddControl AddPictureBox;
		public AddControl RemovePictureBox;
		//Direction invaderDirection;
		//List<Invaders> invaders;

		PlayerShip playerShip;
		List<Bullet> bullets = new List<Bullet>();
		public void SetPlayer(PlayerShip ship) { playerShip = ship; }
		//List<Shot> playerShots;
		//List<Shot> invaderShots;

		//Stars stars;

		public event EventHandler GameOver;

		public void Draw(Graphics g, int animationCell)
		{
			
		}

		public void Twinkle()
		{

		}

		public void MovePlayer(Direction direction)
		{
			playerShip.Move(direction);
		}

		public void FireShot()
		{
			Console.WriteLine("Shot");
			Bullet bullet = playerShip.FireShot();
			bullets.Add(bullet);
			AddPictureBox(bullet.picture);
		}

		public void Go()
		{
			foreach (Bullet bullet in bullets)
			{
				bullet.Move();
			}

			for (int i = 0; i < bullets.Count; ++i)
			{
				if (bullets[i].IsOut())
				{
					Bullet bullet = bullets[i];
					bullet.picture.Visible = false;
					bullet.picture.InitialImage = null;
					RemovePictureBox(bullet.picture);
					bullets.Remove(bullet);
					bullet.Dispose();
					--i;
				}
			}
		}
	}
}
