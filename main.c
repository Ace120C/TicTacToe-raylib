#include <raylib.h>

typedef struct {
  int ZoneXL;
  int ZoneXR;
  int ZoneYL;
  int ZoneYR;
} ZoneArea;

ZoneArea zone;

ZoneArea box = {309, 485, 256, 490};

bool IsInsideBox(ZoneArea zone, int x, int y)
{
  return x >= zone.ZoneXL && x <= zone.ZoneXR &&
      y >= zone.ZoneYL && y <= zone.ZoneYR ;
}

int main()
{
  // Init 
  InitWindow(800, 800, "tictactoe");
  Texture2D Board = LoadTexture("./assets/board.png");
  Texture2D Cross = LoadTexture("./assets/cross.png");
  bool PlacedCross = false;
  SetTargetFPS(50);

  // Game loop
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawTexture(Board, 0, 0, RAYWHITE);
    if (PlacedCross) {
      DrawTexture(Cross, 315, 290, RAYWHITE);
    }
    if (IsInsideBox(box, GetMouseX(), GetMouseY()) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
      PlacedCross = true;
    }
    EndDrawing();
    
  }

  UnloadTexture(Board);
  UnloadTexture(Cross);
  // Closing Window
  CloseWindow();
  return 0;
}
