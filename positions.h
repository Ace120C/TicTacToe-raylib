#ifndef POSITIONS_H
#define POSITIONS_H
typedef struct {
  int ZoneXL;
  int ZoneXR;
  int ZoneYL;
  int ZoneYR;
} ZoneArea;

typedef struct {
  int CrossX;
  int CrossY;
} CrossCord;

ZoneArea zone;
CrossCord Xcord;

                  // Box1
ZoneArea box[9] = {{3, 251, 255, 485},
                  // Box 5
                 {309, 485, 256, 490},
                 };
                        // Box1
CrossCord CrossPos[9] ={{40, 20},
                        // Box 2
                        {315, 20},
                        // Box 3
                        {570, 25},
                        // Box 4
                        {40, 290},
                        // Box 5
                        {315, 290},
                        // Box 6
                        {590, 300},
                        // Box 7
                        {40, 590},
                        // Box 8
                        {319, 590},
                        // Box 9
                        {580, 590},
                        };
#endif // POSITIONS_H
