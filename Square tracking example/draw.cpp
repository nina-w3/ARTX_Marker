//
//  draw.cpp

#include "draw.h"
#include "AVFoundation/AVFoundation.h"


//#if HAVE_GL
//#  if ARX_TARGET_PLATFORM_MACOS
//#    include <OpenGL/gl.h>
//#  else
//#    include <GL/gl.h>
//#  endif
//#endif // HAVE_GL
#if HAVE_GLES2 || HAVE_GL3
#  include <ARX/ARG/mtx.h>
#  include <ARX/ARG/shader_gl.h>
//#  if HAVE_GLES2
//#    if ARX_TARGET_PLATFORM_IOS
//#      include <OpenGLES/ES2/gl.h>
//#    else
//#      include <GLES2/gl2.h>
//#    endif
//#  else
//#    if ARX_TARGET_PLATFORM_MACOS
//#    include <OpenGL/gl3.h>
//#    else
//#      ifndef _WIN32
//#			define GL_GLEXT_PROTOTYPES
//#      endif
//#      include "GL/glcorearb.h"
//#    endif
//#  endif
#endif // HAVE_GLES2 || HAVE_GL3

#define Models_MAX 32

#include <AudioToolbox/AudioServices.h>
//#import <AVFoundation/AVSpeechSynthesis.h>
#import <QuartzCore/QuartzCore.h>

//#include <AudioToolbox/AudioUnit.h>







#if HAVE_GLES2 || HAVE_GL3
// Indices of GL program uniforms.
enum {
    UNIFORM_MODELVIEW_PROJECTION_MATRIX,
    UNIFORM_COUNT
};
// Indices of of GL program attributes.
enum {
    ATTRIBUTE_VERTEX,
    ATTRIBUTE_COLOUR,
    ATTRIBUTE_COUNT
};
//static GLint uniforms[UNIFORM_COUNT] = {0};
//static GLuint program = 0;

#if HAVE_GL3
//static GLuint gCubeVAOs[2] = {0};
//static GLuint gCubeV3BO = 0;
//static GLuint gCubeC4BO = 0;
//static GLuint gCubeCb4BO = 0;
//static GLuint gCubeEABO = 0;
	/*
#if defined(_WIN32)
	# define ARGL_GET_PROC_ADDRESS wglGetProcAddress
	PFNGLBINDBUFFERPROC glBindBuffer = NULL; // (PFNGLGENBUFFERSPROC)ARGL_GET_PROC_ADDRESS("glGenBuffersARB");
	PFNGLDELETEBUFFERSPROC glDeleteBuffers = NULL;
	PFNGLGENBUFFERSPROC glGenBuffers = NULL;
	PFNGLBUFFERDATAPROC glBufferData = NULL;
	PFNGLATTACHSHADERPROC glAttachShader = NULL;
	PFNGLBINDATTRIBLOCATIONPROC glBindAttribLocation = NULL;
	PFNGLCREATEPROGRAMPROC glCreateProgram = NULL;
	PFNGLDELETEPROGRAMPROC glDeleteProgram = NULL;
	PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray = NULL;
	PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation = NULL;
	PFNGLUSEPROGRAMPROC glUseProgram = NULL;

	PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv = NULL;
	PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer = NULL;
	PFNGLBINDVERTEXARRAYPROC glBindVertexArray = NULL;
	PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays = NULL;
	PFNGLGENVERTEXARRAYSPROC glGenVertexArrays = NULL;
	#endif
     */
#endif // HAVE_GL3

#endif // HAVE_GLES2 || HAVE_GL3

//static ARG_API drawAPI = ARG_API_None;

static bool gModelLoaded[Models_MAX] = {false};
static float gModelPoses[Models_MAX][16];
static bool gModelVisbilities[Models_MAX];

//static void drawCube(float viewProjection[16], float pose[16]);

int drawLoadModel(const char *path)
{
    // Ignore path, we'll always draw a cube. -- Notwendig, aber wieso?
    for (int i = 0; i < Models_MAX; i++) {
        if (!gModelLoaded[i]) {
            gModelLoaded[i] = true;
            return i;
        }
    }
    return -1;
}

void drawSetModel(int modelIndex, bool visible, float pose[16])
{
    
    if (modelIndex < 0 || modelIndex >= Models_MAX) return;
    if (!gModelLoaded[modelIndex]) return;
    
    gModelVisbilities[modelIndex] = visible;
    if (visible) mtxLoadMatrixf(&(gModelPoses[modelIndex][0]), pose);
     
}

void draw()
{
    for (int i = 0; i < Models_MAX; i++) {
        if (gModelLoaded[i] && gModelVisbilities[i]) {
          
           // AudioServicesPlayAlertSound(kSystemSoundID_Vibrate); //wenn Sound ausgestellt ist am Iphone
            AudioServicesPlayAlertSound(1105); // Vibriert auch ohne die Zeile davor
     
         
    
        }
    }
    
}







