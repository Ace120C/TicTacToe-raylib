#include <raylib.h>
#include <stdbool.h>
#include <stdio.h>
#include "positions.h"

CrossCord GetCrossPosition(CrossCord CrossPos[], int index)
{
  return CrossPos[index];
}

int Boxes = sizeof(box) / sizeof(box[0]);

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
  Texture2D Circle = LoadTexture("./assets/circle.png");
  bool PlacedCross = false;
  bool PlacedCircle = false;
  int PlacedIndex  = -1;
  bool IsCrossTurn = true;
  int MousePosX = GetMouseX();
  int MousePosY = GetMouseY();
  SetTargetFPS(50);

  // Game loop
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawTexture(Board, 0, 0, RAYWHITE);

    if (PlacedCross) {
      DrawTexture(Cross, CrossPos[4].CrossX, CrossPos[4].CrossY, RAYWHITE);
    }
    if (PlacedCircle) {
      DrawTexture(Circle, 50, 290, RAYWHITE);
    }

    for (int i = 0; i < Boxes; i++) {
      if (IsInsideBox(box[i], GetMouseX(), GetMouseY())&& IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        if (IsCrossTurn && !PlacedCross) {
          PlacedCross = true;
          IsCrossTurn = false;
        } else if (!IsCrossTurn && !PlacedCircle) {
          PlacedCircle = true;
          IsCrossTurn = true;
        }
      }
    }

    EndDrawing();

    if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
      printf("X: %d\n", MousePosX);
      printf("Y: %d\n", MousePosY);
    }
    
  }

  UnloadTexture(Board);
  UnloadTexture(Cross);
  UnloadTexture(Circle);
  // Closing Window
  CloseWindow();
  return 0;
}
