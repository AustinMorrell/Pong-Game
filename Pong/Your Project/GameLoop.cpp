#include "GameLoop.h"

void GameLoop::Loop()
{
	SDL_Event sdlEvent; // Will hold the next event to be parsed

	while (m_bRunning)
	{
		// Events get called one at a time, so if multiple things happen in one frame, they get parsed individually through 'SDL_PollEvent'
		// The next event to parse gets stored into 'sdlEvent', and then passed to the 'EventHandler' class which will call it's appropriate function here
		// 'SDL_PollEvent' returns 0 when there are no more events to parse
		while (SDL_PollEvent(&sdlEvent))
		{
			// Calls the redefined event function for the EventHandler class
			// Refer to its header file and cpp for more information on what each inherited function is capable of
			// and its syntax
			OnEvent(sdlEvent);
		}
		GetDeltaTime();

		Update();

		Draw();

		Graphics::Flip(); // Required to update the window with all the newly drawn content
	}

}

int GameLoop::Collisons(Vector2<int> speed, Vector2<int> C, Vector2<float> P1, Vector2<float> P2)
{
	if (movement == true)
	{
		CircleVecter = CircleVecter.Adding(CircleVecter, SpeedVecter);
	}

	if (movement == false)
	{
		CircleVecter = CircleVecter.Subtracting(CircleVecter, SpeedVecter);
	}
	// ---------------------------------------------------------------------------------------------------

	if ((C.x >= P2.x) && (C.x <= P2.x + 50) && (C.y >= P2.y) && (C.y <= P2.y + 100))
	{
		movement = false;
	}

	if ((C.x <= P1.x + 50) && (C.x >= P1.x) && (C.y >= P1.y) && (C.y <= P1.y + 100))
	{
		movement = true;
	}

	if ((C.x <= P1.x + 50) && (C.x >= P1.x) && (C.y >= P1.y) && (C.y <= P1.y + 33))
	{
		SpeedVecter.y = SpeedVecter.y - 2.5;
	}

	if ((C.x >= P2.x) && (C.x <= P2.x + 50) && (C.y >= P2.y) && (C.y <= P2.y + 33))
	{
		SpeedVecter.y = SpeedVecter.y - 2.5;
	}

	if (C.y <= 0 || C.y >= 800)
	{
		CircleVecter = { CircleVecter.x, -(CircleVecter.y) };
	}

	return 0;
}

void GameLoop::Update()
{
		if (CircleVecter.x >= 1600)
		{
			scoreLeft += 1;
			CircleVecter.x = 800;
			CircleVecter.y = 450;
		}

		if (CircleVecter.x <= 0)
		{
			scoreRight += 1;
			CircleVecter.x = 800;
			CircleVecter.y = 450;
		}

		Collisons(SpeedVecter, CircleVecter, RectVecter, RectVecter2);
//---------------------------------------------------------------------------------------------
	// This allows me to move both Players at the same time.
		if (ClickingS == true)
		{
			RectVecter.y += 10;
			if (RectVecter.y >= 800)
			{
				RectVecter.y -= 10;
			}
		}

		if (ClickingW == true)
		{
			RectVecter.y -= 10;
			if (RectVecter.y <= 0)
			{
				RectVecter.y += 10;
			}
		}

		if (ClickingDown == true)
		{
			RectVecter2.y += 10;
			if (RectVecter2.y >= 800)
			{
				RectVecter2.y -= 10;
			}
		}

		if (ClickingUp == true)
		{
			RectVecter2.y -= 10;
			if (RectVecter2.y <= 0)
			{
				RectVecter2.y += 10;
			}
		}
}

void GameLoop::GetDeltaTime()
{
	int now = SDL_GetTicks();
	DeltaTime = ((float)(now - last)) / 1000;
	last = now;
}

void GameLoop::Draw()
{
	// Objects are drawn in a painter's layer fashion meaning the first object drawn is on the bottom, and the last one drawn is on the top
	// just like a painter would paint onto a canvas

	Graphics::DrawLine({ 800, 1600 }, { 800, 0 }, { 255, 255, 0, 255 });
	Graphics::DrawCircle({ CircleVecter.x, CircleVecter.y }, 25, 25, { 0, 255, 255, 150 });
	Graphics::DrawRect({ RectVecter.x, RectVecter.y }, { 25, 100 }, { 160, 65, 255, 255 });
	Graphics::DrawRect({ RectVecter2.x, RectVecter2.y }, { 25, 100 }, { 160, 65, 255, 255 });
	GameLoop::Score(scoreLeft, scoreRight);
}

void GameLoop::OnMouseMove(const int ac_iMouseX, const int ac_iMouseY, const int ac_iVelX, const int ac_VelY, const bool ac_bLeft, const bool ac_bRight, const bool ac_bMiddle)
{
	if ((RectVecter.x != ac_iMouseX) && (RectVecter.y != ac_iMouseY) && (ac_bLeft == true))
	{
		RectVecter.x = RectVecter.x + ac_iVelX;
		RectVecter.y = RectVecter.y + ac_VelY;
	}
}

void GameLoop::OnKeyDown(const SDL_Keycode ac_sdlSym, const Uint16 ac_uiMod, const SDL_Scancode ac_sdlScancode)
{
//------------------------------------------------
	switch (ac_sdlSym)
	{
	case SDLK_s:
		ClickingS = true;
		break;

	case SDLK_w:
		ClickingW = true;
		break;

	case SDLK_DOWN:
		ClickingDown = true;
		break;

	case SDLK_UP:
		ClickingUp = true;
		break;

	case SDLK_ESCAPE: m_bRunning = false; break; // End the loop

	default: printf("%s\n", SDL_GetKeyName(ac_sdlSym)); break;
	}
}
void GameLoop::OnKeyUp(const SDL_Keycode ac_sdlSym, const Uint16 ac_uiMod, const SDL_Scancode ac_sdlScancode)
{
	switch (ac_sdlSym)
	{
	case SDLK_s:
		ClickingS = false;
		break;

	case SDLK_w:
		ClickingW = false;
		break;

	case SDLK_DOWN:
		ClickingDown = false;
		break;

	case SDLK_UP:
		ClickingUp = false;
		break;

	default: break;
	}
}

void GameLoop::Score(int L, int R)
{
	if (L == 1)
	{

	}

	if (L == 2)
	{

	}

	if (L == 3)
	{

	}

	if (L == 4)
	{

	}

	if (L == 5)
	{

	}

	if (L == 6)
	{

	}

	if (L == 7)
	{

	}
// -------------------------------------------

	if (R == 1)
	{

	}

	if (R == 2)
	{

	}

	if (R == 3)
	{

	}

	if (R == 4)
	{

	}

	if (R == 5)
	{

	}

	if (R == 6)
	{

	}

	if (R == 7)
	{

	}
}

void GameLoop::OnExit()
{
	m_bRunning = false; // End the loop
}

GameLoop::GameLoop()
{
	m_bRunning = true;
}
GameLoop::~GameLoop()
{

}