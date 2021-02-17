using System;
using System.Collections.Generic;
using System.Text;
using System.Drawing;

namespace TheQuest
{
	class Bat : Enemy
	{
		public Bat(Game game, Point location) : base(game, location, 6) { }

		public override void Move(Random random)
		{
			// 50%로 플레이어 방향, 50%로 랜덤방향
			int r = random.Next(0, 2);
			if (r == 0)
			{
				Move(FindPlayerDirection(game.PlayerLocation), game.Boundaries);
			}
			else
			{
				r = random.Next(0, 4);
				Move((Direction)r, game.Boundaries);
			}
			if (NearPlayer())
				game.HitPlayer(2, random);
		}
	}
}
