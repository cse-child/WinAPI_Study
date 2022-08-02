class PaintTool
{
private:
	enum class Shape
	{
		POINT, LINE, RECT, ELLIPSE, PEN
	};

	enum class Color
	{
		BLACK, RED, GREEN, BLUE, MAX
	};
public:
	PaintTool(HWND hWnd);
	~PaintTool();

	void MouseKeyDown();
	void MouseKeyUp();
	void MouseKeyPress();

	void SetMousePos(LPARAM lParam);
	void ShowInfo();

	void DrawPoint();

	void InputKey(WPARAM wParam);

	void SetColors();

	void CreatePensAndBrushes();

	void Clear();

private:
	HDC hdc;
	HWND hWnd;

	Shape selectShape;
	Color selectColor;

	POINT curMousePos;
	POINT startMousePos;

	COLORREF colors[(int)Color::MAX];

	HPEN pens[(int)Color::MAX];
	HBRUSH brushes[(int)Color::MAX];

	bool isMouseDown = false;
};