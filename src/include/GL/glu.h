/*++ BUILD Version: 0004    // Increment this if a change has global effects

Copyright (c) 1985-95, Microsoft Corporation

Module Name:

    glu.h

Abstract:

    Procedure declarations, constant definitions and macros for the OpenGL
    Utility Library.

--*/

#ifndef __glu_h__
#ifndef __GLU_H__

#define __glu_h__
#define __GLU_H__

#include <windows.h>
#include <winapifamily.h>
#include "gl.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
** Copyright 1991-1993, Silicon Graphics, Inc.
** All Rights Reserved.
** 
** This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics, Inc.;
** the contents of this file may not be disclosed to third parties, copied or
** duplicated in any form, in whole or in part, without the prior written
** permission of Silicon Graphics, Inc.
** 
** RESTRICTED RIGHTS LEGEND:
** Use, duplication or disclosure by the Government is subject to restrictions
** as set forth in subdivision (c)(1)(ii) of the Rights in Technical Data
** and Computer Software clause at DFARS 252.227-7013, and/or in similar or
** successor clauses in the FAR, DOD or NASA FAR Supplement. Unpublished -
** rights reserved under the Copyright Laws of the United States.
*/

#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

/*
** Return the error string associated with a particular error code.
** This will return 0 for an invalid error code.
**
** The generic function prototype that can be compiled for ANSI or Unicode
** is defined as follows:
**
** LPCTSTR APIENTRY gluErrorStringWIN (GLenum errCode);
*/
#ifdef UNICODE
#define gluErrorStringWIN(errCode) ((LPCSTR)  gluErrorUnicodeStringEXT(errCode))
#else
#define gluErrorStringWIN(errCode) ((LPCWSTR) gluErrorString(errCode))
#endif

const GLubyte* APIENTRY gluErrorString (
    GLenum   errCode);

const wchar_t* APIENTRY gluErrorUnicodeStringEXT (
    GLenum   errCode);

const GLubyte* APIENTRY gluGetString (
    GLenum   name);

void APIENTRY gluOrtho2D (
    GLdouble left, 
    GLdouble right, 
    GLdouble bottom, 
    GLdouble top);

void APIENTRY gluPerspective (
    GLdouble fovy, 
    GLdouble aspect, 
    GLdouble zNear, 
    GLdouble zFar);

void APIENTRY gluPickMatrix (
    GLdouble x, 
    GLdouble y, 
    GLdouble width, 
    GLdouble height, 
    GLint    viewport[4]);

void APIENTRY gluLookAt (
    GLdouble eyex, 
    GLdouble eyey, 
    GLdouble eyez, 
    GLdouble centerx, 
    GLdouble centery, 
    GLdouble centerz, 
    GLdouble upx, 
    GLdouble upy, 
    GLdouble upz);

int APIENTRY gluProject (
    GLdouble        objx, 
    GLdouble        objy, 
    GLdouble        objz,  
    const GLdouble  modelMatrix[16], 
    const GLdouble  projMatrix[16], 
    const GLint     viewport[4], 
    GLdouble        *winx, 
    GLdouble        *winy, 
    GLdouble        *winz);

int APIENTRY gluUnProject (
    GLdouble       winx, 
    GLdouble       winy, 
    GLdouble       winz, 
    const GLdouble modelMatrix[16], 
    const GLdouble projMatrix[16], 
    const GLint    viewport[4], 
    GLdouble       *objx, 
    GLdouble       *objy, 
    GLdouble       *objz);


int APIENTRY gluScaleImage (
    GLenum      format, 
    GLint       widthin, 
    GLint       heightin, 
    GLenum      typein, 
    const void  *datain, 
    GLint       widthout, 
    GLint       heightout, 
    GLenum      typeout, 
    void        *dataout);


int APIENTRY gluBuild1DMipmaps (
    GLenum      target, 
    GLint       components, 
    GLint       width, 
    GLenum      format, 
    GLenum      type, 
    const void  *data);

int APIENTRY gluBuild2DMipmaps (
    GLenum      target, 
    GLint       components, 
    GLint       width, 
    GLint       height, 
    GLenum      format, 
    GLenum      type, 
    const void  *data);

#ifdef __cplusplus

class GLUnurbs;
class GLUquadric;
class GLUtesselator;

/* backwards compatibility: */
typedef class GLUnurbs GLUnurbsObj;
typedef class GLUquadric GLUquadricObj;
typedef class GLUtesselator GLUtesselatorObj;
typedef class GLUtesselator GLUtriangulatorObj;

#else

typedef struct GLUnurbs GLUnurbs;
typedef struct GLUquadric GLUquadric;
typedef struct GLUtesselator GLUtesselator;

/* backwards compatibility: */
typedef struct GLUnurbs GLUnurbsObj;
typedef struct GLUquadric GLUquadricObj;
typedef struct GLUtesselator GLUtesselatorObj;
typedef struct GLUtesselator GLUtriangulatorObj;

#endif


GLUquadric* APIENTRY gluNewQuadric (void);
void APIENTRY gluDeleteQuadric (
    GLUquadric          *state);

void APIENTRY gluQuadricNormals (
    GLUquadric          *quadObject, 
    GLenum              normals);

void APIENTRY gluQuadricTexture (
    GLUquadric          *quadObject, 
    GLboolean           textureCoords);

void APIENTRY gluQuadricOrientation (
    GLUquadric          *quadObject, 
    GLenum              orientation);

void APIENTRY gluQuadricDrawStyle (
    GLUquadric          *quadObject, 
    GLenum              drawStyle);

void APIENTRY gluCylinder (
    GLUquadric          *qobj, 
    GLdouble            baseRadius, 
    GLdouble            topRadius, 
    GLdouble            height, 
    GLint               slices, 
    GLint               stacks);

void APIENTRY gluDisk (
    GLUquadric          *qobj, 
    GLdouble            innerRadius, 
    GLdouble            outerRadius, 
    GLint               slices, 
    GLint               loops);

void APIENTRY gluPartialDisk (
    GLUquadric          *qobj, 
    GLdouble            innerRadius, 
    GLdouble            outerRadius, 
    GLint               slices, 
    GLint               loops, 
    GLdouble            startAngle, 
    GLdouble            sweepAngle);

void APIENTRY gluSphere (
    GLUquadric          *qobj, 
    GLdouble            radius, 
    GLint               slices, 
    GLint               stacks);

void APIENTRY gluQuadricCallback (
    GLUquadric          *qobj, 
    GLenum              which, 
    void                (CALLBACK* fn)());

GLUtesselator* APIENTRY  gluNewTess(          
    void );

void APIENTRY  gluDeleteTess(       
    GLUtesselator       *tess );

void APIENTRY  gluTessBeginPolygon( 
    GLUtesselator       *tess,
    void                *polygon_data );

void APIENTRY  gluTessBeginContour( 
    GLUtesselator       *tess );

void APIENTRY  gluTessVertex(       
    GLUtesselator       *tess,
    GLdouble            coords[3], 
    void                *data );

void APIENTRY  gluTessEndContour(   
    GLUtesselator       *tess );

void APIENTRY  gluTessEndPolygon(   
    GLUtesselator       *tess );

void APIENTRY  gluTessProperty(     
    GLUtesselator       *tess,
    GLenum              which, 
    GLdouble            value );
 
void APIENTRY  gluTessNormal(       
    GLUtesselator       *tess, 
    GLdouble            x,
    GLdouble            y, 
    GLdouble            z );

void APIENTRY  gluTessCallback(     
    GLUtesselator       *tess,
    GLenum              which, 
    void                (CALLBACK *fn)());

void APIENTRY  gluGetTessProperty(  
    GLUtesselator       *tess,
    GLenum              which, 
    GLdouble            *value );
 
GLUnurbs* APIENTRY gluNewNurbsRenderer (void);

void APIENTRY gluDeleteNurbsRenderer (
    GLUnurbs            *nobj);

void APIENTRY gluBeginSurface (
    GLUnurbs            *nobj);

void APIENTRY gluBeginCurve (
    GLUnurbs            *nobj);

void APIENTRY gluEndCurve (
    GLUnurbs            *nobj);

void APIENTRY gluEndSurface (
    GLUnurbs            *nobj);

void APIENTRY gluBeginTrim (
    GLUnurbs            *nobj);

void APIENTRY gluEndTrim (
    GLUnurbs            *nobj);

void APIENTRY gluPwlCurve (
    GLUnurbs            *nobj, 
    GLint               count, 
    GLfloat             *array, 
    GLint               stride, 
    GLenum              type);

void APIENTRY gluNurbsCurve (
    GLUnurbs            *nobj, 
    GLint               nknots, 
    GLfloat             *knot, 
    GLint               stride, 
    GLfloat             *ctlarray, 
    GLint               order, 
    GLenum              type);

void APIENTRY 
gluNurbsSurface(     
    GLUnurbs            *nobj, 
    GLint               sknot_count, 
    float               *sknot, 
    GLint               tknot_count, 
    GLfloat             *tknot, 
    GLint               s_stride, 
    GLint               t_stride, 
    GLfloat             *ctlarray, 
    GLint               sorder, 
    GLint               torder, 
    GLenum              type);

void APIENTRY 
gluLoadSamplingMatrices (
    GLUnurbs            *nobj, 
    const GLfloat       modelMatrix[16], 
    const GLfloat       projMatrix[16], 
    const GLint         viewport[4] );

void APIENTRY 
gluNurbsProperty (
    GLUnurbs            *nobj, 
    GLenum              property, 
    GLfloat             value );

void APIENTRY 
gluGetNurbsProperty (
    GLUnurbs            *nobj, 
    GLenum              property, 
    GLfloat             *value );

void APIENTRY 
gluNurbsCallback (
    GLUnurbs            *nobj, 
    GLenum              which, 
    void                (CALLBACK* fn)() );


/****           Callback function prototypes    ****/

/* gluQuadricCallback */
typedef void (CALLBACK* GLUquadricErrorProc) (GLenum);

/* gluTessCallback */
typedef void (CALLBACK* GLUtessBeginProc)        (GLenum);
typedef void (CALLBACK* GLUtessEdgeFlagProc)     (GLboolean);
typedef void (CALLBACK* GLUtessVertexProc)       (void *);
typedef void (CALLBACK* GLUtessEndProc)          (void);
typedef void (CALLBACK* GLUtessErrorProc)        (GLenum);
typedef void (CALLBACK* GLUtessCombineProc)      (GLdouble[3],
                                                  void*[4], 
                                                  GLfloat[4],
                                                  void** );
typedef void (CALLBACK* GLUtessBeginDataProc)    (GLenum, void *);
typedef void (CALLBACK* GLUtessEdgeFlagDataProc) (GLboolean, void *);
typedef void (CALLBACK* GLUtessVertexDataProc)   (void *, void *);
typedef void (CALLBACK* GLUtessEndDataProc)      (void *);
typedef void (CALLBACK* GLUtessErrorDataProc)    (GLenum, void *);
typedef void (CALLBACK* GLUtessCombineDataProc)  (GLdouble[3],
                                                  void*[4], 
                                                  GLfloat[4],
                                                  void**,
                                                  void* );

/* gluNurbsCallback */
typedef void (CALLBACK* GLUnurbsErrorProc)   (GLenum);


/****           Generic constants               ****/

/* Version */
#define GLU_VERSION_1_1                 1
#define GLU_VERSION_1_2                 1

/* Errors: (return value 0 = no error) */
#define GLU_INVALID_ENUM        100900
#define GLU_INVALID_VALUE       100901
#define GLU_OUT_OF_MEMORY       100902
#define GLU_INCOMPATIBLE_GL_VERSION     100903

/* StringName */
#define GLU_VERSION             100800
#define GLU_EXTENSIONS          100801

/* Boolean */
#define GLU_TRUE                GL_TRUE
#define GLU_FALSE               GL_FALSE


/****           Quadric constants               ****/

/* QuadricNormal */
#define GLU_SMOOTH              100000
#define GLU_FLAT                100001
#define GLU_NONE                100002

/* QuadricDrawStyle */
#define GLU_POINT               100010
#define GLU_LINE                100011
#define GLU_FILL                100012
#define GLU_SILHOUETTE          100013

/* QuadricOrientation */
#define GLU_OUTSIDE             100020
#define GLU_INSIDE              100021

/* Callback types: */
/*      GLU_ERROR               100103 */


/****           Tesselation constants           ****/

#define GLU_TESS_MAX_COORD              1.0e150

/* TessProperty */
#define GLU_TESS_WINDING_RULE           100140
#define GLU_TESS_BOUNDARY_ONLY          100141
#define GLU_TESS_TOLERANCE              100142

/* TessWinding */
#define GLU_TESS_WINDING_ODD            100130
#define GLU_TESS_WINDING_NONZERO        100131
#define GLU_TESS_WINDING_POSITIVE       100132
#define GLU_TESS_WINDING_NEGATIVE       100133
#define GLU_TESS_WINDING_ABS_GEQ_TWO    100134

/* TessCallback */
#define GLU_TESS_BEGIN          100100  /* void (CALLBACK*)(GLenum    type)  */
#define GLU_TESS_VERTEX         100101  /* void (CALLBACK*)(void      *data) */
#define GLU_TESS_END            100102  /* void (CALLBACK*)(void)            */
#define GLU_TESS_ERROR          100103  /* void (CALLBACK*)(GLenum    errno) */
#define GLU_TESS_EDGE_FLAG      100104  /* void (CALLBACK*)(GLboolean boundaryEdge)  */
#define GLU_TESS_COMBINE        100105  /* void (CALLBACK*)(GLdouble  coords[3],
                                                            void      *data[4],
                                                            GLfloat   weight[4],
                                                            void      **dataOut)     */
#define GLU_TESS_BEGIN_DATA     100106  /* void (CALLBACK*)(GLenum    type,  
                                                            void      *polygon_data) */
#define GLU_TESS_VERTEX_DATA    100107  /* void (CALLBACK*)(void      *data, 
                                                            void      *polygon_data) */
#define GLU_TESS_END_DATA       100108  /* void (CALLBACK*)(void      *polygon_data) */
#define GLU_TESS_ERROR_DATA     100109  /* void (CALLBACK*)(GLenum    errno, 
                                                            void      *polygon_data) */
#define GLU_TESS_EDGE_FLAG_DATA 100110  /* void (CALLBACK*)(GLboolean boundaryEdge,
                                                            void      *polygon_data) */
#define GLU_TESS_COMBINE_DATA   100111  /* void (CALLBACK*)(GLdouble  coords[3],
                                                            void      *data[4],
                                                            GLfloat   weight[4],
                                                            void      **dataOut,
                                                            void      *polygon_data) */

/* TessError */
#define GLU_TESS_ERROR1     100151
#define GLU_TESS_ERROR2     100152
#define GLU_TESS_ERROR3     100153
#define GLU_TESS_ERROR4     100154
#define GLU_TESS_ERROR5     100155
#define GLU_TESS_ERROR6     100156
#define GLU_TESS_ERROR7     100157
#define GLU_TESS_ERROR8     100158

#define GLU_TESS_MISSING_BEGIN_POLYGON  GLU_TESS_ERROR1
#define GLU_TESS_MISSING_BEGIN_CONTOUR  GLU_TESS_ERROR2
#define GLU_TESS_MISSING_END_POLYGON    GLU_TESS_ERROR3
#define GLU_TESS_MISSING_END_CONTOUR    GLU_TESS_ERROR4
#define GLU_TESS_COORD_TOO_LARGE        GLU_TESS_ERROR5
#define GLU_TESS_NEED_COMBINE_CALLBACK  GLU_TESS_ERROR6

/****           NURBS constants                 ****/

/* NurbsProperty */
#define GLU_AUTO_LOAD_MATRIX    100200
#define GLU_CULLING             100201
#define GLU_SAMPLING_TOLERANCE  100203
#define GLU_DISPLAY_MODE        100204
#define GLU_PARAMETRIC_TOLERANCE        100202
#define GLU_SAMPLING_METHOD             100205
#define GLU_U_STEP                      100206
#define GLU_V_STEP                      100207

/* NurbsSampling */
#define GLU_PATH_LENGTH                 100215
#define GLU_PARAMETRIC_ERROR            100216
#define GLU_DOMAIN_DISTANCE             100217


/* NurbsTrim */
#define GLU_MAP1_TRIM_2         100210
#define GLU_MAP1_TRIM_3         100211

/* NurbsDisplay */
/*      GLU_FILL                100012 */
#define GLU_OUTLINE_POLYGON     100240
#define GLU_OUTLINE_PATCH       100241

/* NurbsCallback */
/*      GLU_ERROR               100103 */

/* NurbsErrors */
#define GLU_NURBS_ERROR1        100251
#define GLU_NURBS_ERROR2        100252
#define GLU_NURBS_ERROR3        100253
#define GLU_NURBS_ERROR4        100254
#define GLU_NURBS_ERROR5        100255
#define GLU_NURBS_ERROR6        100256
#define GLU_NURBS_ERROR7        100257
#define GLU_NURBS_ERROR8        100258
#define GLU_NURBS_ERROR9        100259
#define GLU_NURBS_ERROR10       100260
#define GLU_NURBS_ERROR11       100261
#define GLU_NURBS_ERROR12       100262
#define GLU_NURBS_ERROR13       100263
#define GLU_NURBS_ERROR14       100264
#define GLU_NURBS_ERROR15       100265
#define GLU_NURBS_ERROR16       100266
#define GLU_NURBS_ERROR17       100267
#define GLU_NURBS_ERROR18       100268
#define GLU_NURBS_ERROR19       100269
#define GLU_NURBS_ERROR20       100270
#define GLU_NURBS_ERROR21       100271
#define GLU_NURBS_ERROR22       100272
#define GLU_NURBS_ERROR23       100273
#define GLU_NURBS_ERROR24       100274
#define GLU_NURBS_ERROR25       100275
#define GLU_NURBS_ERROR26       100276
#define GLU_NURBS_ERROR27       100277
#define GLU_NURBS_ERROR28       100278
#define GLU_NURBS_ERROR29       100279
#define GLU_NURBS_ERROR30       100280
#define GLU_NURBS_ERROR31       100281
#define GLU_NURBS_ERROR32       100282
#define GLU_NURBS_ERROR33       100283
#define GLU_NURBS_ERROR34       100284
#define GLU_NURBS_ERROR35       100285
#define GLU_NURBS_ERROR36       100286
#define GLU_NURBS_ERROR37       100287

/****           Backwards compatibility for old tesselator           ****/

void APIENTRY   gluBeginPolygon( GLUtesselator *tess );

void APIENTRY   gluNextContour(  GLUtesselator *tess, 
                                 GLenum        type );

void APIENTRY   gluEndPolygon(   GLUtesselator *tess );

/* Contours types -- obsolete! */
#define GLU_CW          100120
#define GLU_CCW         100121
#define GLU_INTERIOR    100122
#define GLU_EXTERIOR    100123
#define GLU_UNKNOWN     100124

/* Names without "TESS_" prefix */
#define GLU_BEGIN       GLU_TESS_BEGIN
#define GLU_VERTEX      GLU_TESS_VERTEX
#define GLU_END         GLU_TESS_END
#define GLU_ERROR       GLU_TESS_ERROR
#define GLU_EDGE_FLAG   GLU_TESS_EDGE_FLAG

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion

#ifdef __cplusplus
}
#endif

#endif /* __GLU_H__ */
#endif /* __glu_h__ */
