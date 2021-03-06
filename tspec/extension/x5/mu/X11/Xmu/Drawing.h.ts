# Copyright 2002-2011, The TenDRA Project.
# Copyright 1997, United Kingdom Secretary of State for Defence.
#
# See doc/copyright/ for the full copyright terms.


+USE ( "c/c89" ), "stdio.h.ts" (!?) ;
+USE "x5/t", "X11/Intrinsic.h.ts" ;

+FUNC void XmuDrawRoundedRectangle ( Display *, Drawable, GC, int, int,
    int, int, int, int ) ;
+FUNC void XmuFillRoundedRectangle ( Display *, Drawable, GC, int, int,
    int, int, int, int ) ;
+FUNC void XmuDrawLogo ( Display *, Drawable, GC, GC, int, int,
    unsigned int, unsigned int ) ;
+FUNC Pixmap XmuCreateStippledPixmap ( Screen *, Pixel, Pixel,
    unsigned int ) ;
+FUNC void XmuReleaseStippledPixmap ( Screen *, Pixmap ) ;
+FUNC int XmuReadBitmapData ( FILE *, unsigned int *, unsigned int *,
    unsigned char **, int *, int * ) ;
+FUNC int XmuReadBitmapDataFromFile ( char *, unsigned int *,
    unsigned int *, unsigned char **, int *, int * ) ;
+FUNC Pixmap XmuLocateBitmapFile ( Screen *, char *, char *, int,
    int *, int *, int *, int * ) ;
+FUNC Pixmap XmuCreatePixmapFromBitmap ( Display *, Drawable,
    Pixmap, unsigned int, unsigned int, unsigned int,
    unsigned long, unsigned long ) ;
