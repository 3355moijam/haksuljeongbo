using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;
namespace RacingTool
{
	class Greyhound
	{
		public int StartingPosition = 50;
		public int RacetrackLength = 500;
		public PictureBox MyPictureBox = null;
		public int Location = 0;
		public Random Randomizer;
		public int MinSpeed = 0;
		public int MaxSpeed = 0;

		public Greyhound(PictureBox picture)
		{
			MyPictureBox = picture;
		}

		public bool Run()
		{
			Location += Randomizer.Next(MinSpeed, MaxSpeed);
			MyPictureBox.Location = new System.Drawing.Point(MyPictureBox.Location.X + Location, MyPictureBox.Location.Y);
			if (Location >= RacetrackLength)
				return true;
			return false;
		}
	}
}
