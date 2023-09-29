#include "fontbase.h"
#include "util.h"


//======================================================
//======================================================
FontBase::FontBase(unsigned int charWidth, unsigned int charHeight)
{
  this->charWidth = charWidth;
  this->charHeight = charHeight;
}

//======================================================
//======================================================
void FontBase::calculateTextureHeight(unsigned int imageWidth, unsigned int imageHeight)
{
  this->fontTextureWidth = smallestPowerOfTwo( imageWidth, 8 );
  this->fontTextureHeight = smallestPowerOfTwo( imageHeight, 8 );
}

//======================================================
//======================================================
FontBase::~FontBase()
{
}

//==============================================================
//==============================================================
void FontBase::destroy()
{
  XPLMBindTexture2d(this->fontTextureId, 0);
  GLuint t = this->fontTextureId;
  glDeleteTextures(1, &t);

  this->fontTextureId = 0;
}

//==============================================================
//==============================================================
void FontBase::bindTexture()
{
  if (this->fontTextureId == 0) return;

  XPLMBindTexture2d(this->fontTextureId, 0);
}
