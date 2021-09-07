//  draw.h
//  artoolkitX Square Tracking Example


#ifndef __draw_h__
#define __draw_h__

#include <ARX/AR/config.h>
#include <ARX/ARG/arg.h>
#include <stdint.h>





#ifdef __cplusplus
extern "C" {
#endif


int drawLoadModel(const char *path);
void drawSetModel(int modelIndex, bool visible, float pose[16]); // Notwendig warum?
void draw(void);
void tts(void);

#ifdef __cplusplus
}
#endif

#endif // !__draw_h__

