#include "move.h"
class track {
    int ballx, bally, magentax, magentaa, gatex, gatea;
  public:
    track(byte ball_x, byte ball_y, byte magenta_x, byte magenta_a, byte gate_x, byte gate_a) {
      ballx = ball_x;
      bally = ball_y;
      magentax = magenta_x;
      magentaa = magenta_a;
      gatex = gate_x;
      gatea = gate_a;
    }

    void ball() {
      if (bally >= 379) {
        maju();
      }
      else {
        if (ballx <= 9) {
          putarkiri();
        }
        else if (ballx >= 10 && ballx <= 255) {
          geserkiri();
        }
        else if (ballx >= 256 && ballx <= 384) {
          maju();
        }
        else if (ballx >= 385 && ballx <= 629) {
          geserkanan();
        }
        else if (ballx <= 639) {
          putarkanan();
        }
      }
    }
    void magenta() {
      if (magentaa >= 10000 && magentaa <= 11000) {
        diam();
      }
      else if (magentaa > 11000) {
        mundur();
      }
      else {
        if (magentax <= 9) {
          putarkiri();
        }
        else if (magentax >= 10 && magentax <= 255) {
          geserkiri();
        }
        else if (magentax >= 256 && magentax <= 384) {
          maju();
        }
        else if (magentax >= 385 && magentax <= 629) {
          geserkanan();
        }
        else if (magentax <= 639) {
          putarkanan();
        }
      }
    }
    void gate() {
      if (gatea >= 10000 && gatea <= 11000) {
        diam();
      }
      else if (gatea > 11000) {
        mundur();
      }
      else {
        if (gatex <= 9) {
          putarkiri();
        }
        else if (gatex >= 10 && gatex <= 255) {
          geserkiri();
        }
        else if (gatex >= 256 && gatex <= 384) {
          maju();
        }
        else if (gatex >= 385 && gatex <= 629) {
          geserkanan();
        }
        else if (gatex <= 639) {
          putarkanan();
        }
      }
    }
};
