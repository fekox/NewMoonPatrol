
//if (IsKeyPressed(KEY_SPACE) && spaceShip.position.y == spaceShip.startJumpPosition)
//{
//	spaceShip.isJumping = true;
//}
//
//if (spaceShip.isJumping)
//{
//	do
//	{
//		spaceShip.position.y -= spaceShip.gravity * GetFrameTime();
//
//		if (spaceShip.position.y <= spaceShip.maxHeightJump)
//		{
//			spaceShip.isJumping = false;
//			break;
//		}
//	} while (spaceShip.position.y < spaceShip.maxHeightJump);
//}
//else if (!spaceShip.isJumping && spaceShip.position.y != spaceShip.startJumpPosition)
//{
//	do
//	{
//		spaceShip.position.y += spaceShip.gravity * GetFrameTime();
//
//		if (spaceShip.position.y >= spaceShip.startJumpPosition)
//		{
//			spaceShip.position.y = spaceShip.startJumpPosition;
//			break;
//		}
//	} while (spaceShip.position.y > spaceShip.startJumpPosition);
//}
