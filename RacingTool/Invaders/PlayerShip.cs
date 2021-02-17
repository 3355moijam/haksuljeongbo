using System;
using System.Collections.Generic;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Invaders
{
	class PlayerShip
	{
		PictureBox picture = null;
		int speed = 10;
		public PlayerShip(PictureBox picture)
		{
			this.picture = picture;
		}

		public void Move(Direction direction)
		{
			Point location = picture.Location;
			switch (direction)
			{
				case Direction.Left:
					location.X -= speed;
					break;
				case Direction.Right:
					location.X += speed;
					break;
				case Direction.Up:
					location.Y -= speed;
					break;
				case Direction.Down:
					location.Y += speed;
					break;
				default:
					break;
			}
			picture.Location = location;
		}

		public Bullet FireShot()
		{
			Bullet bullet = new Bullet(this.picture.Location);
			return bullet;
		}

		

	}
}
