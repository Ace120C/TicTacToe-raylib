#include <raylib.h>
#include <stdio.h>

int main()
{
  // Init 
  InitWindow(800, 800, "tictactoe");
  Texture2D Board = LoadTexture("./assets/board.png");
  SetTargetFPS(50);
  // Game loop
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawTexture(Board, 0, 0, RAYWHITE);
    EndDrawing();

    int MousePosX = GetMouseX();
    int MousePosY = GetMouseY();
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
      printf("X: %d\n", MousePosX);
      printf("Y: %d\n", MousePosY);
    }
  }

  UnloadTexture(Board);
  // Closing Window
  CloseWindow();
  return 0;
}
