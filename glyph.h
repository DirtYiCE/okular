
#ifndef _GLYPH_H
#define _GLYPH_H

#include <qbitmap.h>
#include <qimage.h>
#include <qpainter.h>


/*
 * Bitmap structure for raster ops.
 */
struct bitmap {
  unsigned short	w, h;		/* width and height in pixels */
  short		bytes_wide;	/* scan-line width in bytes */
  char		*bits;		/* pointer to the bits */
};

/*
 * Per-character information.
 * There is one of these for each character in a font (raster fonts only).
 * All fields are filled in at font definition time,
 * except for the bitmap, which is "faulted in"
 * when the character is first referenced.
 */

class glyph {
 public:
  glyph();
  ~glyph();

  long addr;		/* address of bitmap in font file */
  Q_INT32 dvi_advance_in_DVI_units;	/* DVI units to move reference point */
  short x, y;		/* x and y offset in pixels */
  // TODO: replace the bitmap by a Qbitmap
  struct bitmap bitmap;	/* bitmap for character */
  short x2, y2;		/* x and y offset in pixels (shrunken bitmap) */
};

#endif //ifndef _GLYPH_H
