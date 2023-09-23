///////////////////////////////////////////////////////////////////////////////////////////
//
// Bismillah art project, based on:
// ALA library example: RgbStripButton
//
// Example to demonstrate how to switch animations using three buttons.
// The first button change the animation.
// The second button the color palette.
// The third button change the animation speed.
//
// Button library is required: http://playground.arduino.cc/Code/Button
//
// Web page: http://yaab-arduino.blogspot.com/p/ala-example-rgbstripbutton.html
//
///////////////////////////////////////////////////////////////////////////////////////////

#include <AlaLedRgb.h>
#include <OneButton.h>

AlaLedRgb rgbStrip;

int animation = 1;
int duration = 2;
int palette = 0;

OneButton button(3, true);

int animList[] = {
  ALA_OFF,
  ALA_ON,
  ALA_ON,
  ALA_ON,
  ALA_FADECOLORSLOOP,
  ALA_MOVINGGRADIENT,

  ALA_MOVINGBARS,
  ALA_COMET,
  ALA_COMETCOL,
  ALA_GLOW,
  ALA_CYCLECOLORS,
  ALA_FADECOLORS,
  ALA_FIRE,
  0
};

AlaColor colorGreen[] = { 0x008000 };
AlaPalette alaPalGreen = {1, colorGreen};

AlaColor colorWhite[] = { 0xFFFFFF };
AlaPalette alaPalWhite = {1, colorWhite};

AlaColor colorGray[] = { 0x202020 };
AlaPalette alaPalGray = {1, colorGray};

AlaPalette paletteList[] = {
  alaPalRgb,
  alaPalGray,
  alaPalWhite,
  alaPalGreen,
  alaPalRgb,
  alaPalRgb,
  alaPalRgb,
  alaPalRgb,
  alaPalRgb,
  alaPalGreen,
  alaPalRgb,
  alaPalRgb,
  alaPalRgb,
  alaPalRgb,
  alaPalRgb,
  alaPalRgb,
};
//AlaPalette paletteList[3] = {
//   alaPalRgb,
//  alaPalRainbow,
//   alaPalFire
//};

int durationList[3] = {
  1000,
  2000,
  5000
};



void buttonClick()
{
    animation++;
    if (animList[animation] == 0) animation = 0;
    updateAnimation();
}
void setup()
{
  delay(500);

  rgbStrip.initWS2812(24, 15);

  updateAnimation();

  button.attachClick(buttonClick);

}



void loop()
{

  button.tick();

  rgbStrip.runAnimation();

}

void updateAnimation()
{
  rgbStrip.setAnimation(animList[animation], durationList[duration % 3], paletteList[animation]);
}
