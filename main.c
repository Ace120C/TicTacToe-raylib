#include <raylib.h>

int main()
{
  // Init 
  InitWindow(800, 800, "tictactoe");
  Texture2D Board = LoadTexture("./assets/board.png");
  // Game loop
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawTexture(Board, 0, 0, RAYWHITE);
    EndDrawing();
  }

  UnloadTexture(Board);
  // Closing Window
  CloseWindow();
  return 0;
}
