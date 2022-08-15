#include "Framework.h"

Keyboard::Keyboard()
{
}

Keyboard::~Keyboard()
{
}

void Keyboard::Update()
{
	// memory copy : oldState에 curState 값 복사
	memcpy(oldState, curState, sizeof(oldState));

	// 결과값 4개 반환
	// 0, 1 -> 키보드 입력 X
	// 128, 129 -> 키보드 입력 O
	GetKeyboardState(curState);

	for (UINT i = 0; i < KEY_MAX; i++)
	{
		BYTE key = curState[i] & 0x80; // 16진수:80 ->10진수: 128
		// GetKeyBoardState의 반환값이 0,1이면 0 반환, 128,129이면 128 반환

		curState[i] = key ? 1 : 0; // 눌렸으면 1, 아닌경우 0

		BYTE old = oldState[i];
		BYTE cur = curState[i];

		if (old == 0 && cur == 1)
			mapState[i] = DOWN;
		else if(old == 1 && cur == 0)
			mapState[i] = UP;
		else if (old == 1 && cur == 1)
			mapState[i] = PRESS;
		else 
			mapState[i] = NONE;
	}
}
