using System;
using System.Collections.Generic;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Invaders
{
	class Bullet : IDisposable
	{
		private bool disposed = false;
		public PictureBox picture { get; set; }
		Point location;
		public Bullet(Point location)
		{
			picture = new PictureBox();
			picture.Image = Properties.Resources.satellite1;
			this.location = location;
			picture.Location = this.location;
			picture.Size = Properties.Resources.satellite1.Size;
		}
		~Bullet()
		{
			Dispose(false);
		}
		public void Move()
		{
			location.Y -= 10;
			picture.Location = location;
		}

		public bool IsOut()
		{
			if (location.Y < 0)
				return true;
			return false;
		}

		public void Dispose()
		{
			Dispose(true);
			GC.SuppressFinalize(this);
		}

		private void Dispose(bool disposing)
		{
			if(!disposed)
			{
				if(disposing)
				{
					
				}
				picture = null;
				disposed = true;
			}
		}
	}
}
