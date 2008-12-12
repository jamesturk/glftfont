// GLFT_Font (http://polimath.com/blog/code/glft_font/)
//  by James Turk (james.p.turk@gmail.com)
//  Based on work by Marijn Haverbeke (http://marijn.haverbeke.nl)
//
// Version 0.2.1 - Released 2 March 2008 - Updated contact information.
// Version 0.2.0 - Released 18 July 2005 - Added beginDraw/endDraw, 
//                                       Changed vsprintf to vsnprintf
// Version 0.1.0 - Released  1 July 2005 - Initial Release
//
// Copyright (c) 2005-2008, James Turk
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions are met:
//
//    * Redistributions of source code must retain the above copyright notice, 
//      this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above copyright 
//      notice, this list of conditions and the following disclaimer in the 
//      documentation and/or other materials provided with the distribution.
//    * Neither the name of the GLFT_Font nor the names of its contributors
//      may be used to endorse or promote products derived from this software 
//      without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
// POSSIBILITY OF SUCH DAMAGE.


#ifndef GLFT_FONT_HPP
#define GLFT_FONT_HPP

#include <GL/gl.h>

#include <ft2build.h>
#include FT_FREETYPE_H

#include <string>
#include <vector>
#include <stdexcept>
#include <cstdarg>
#include <sstream>

class FTLibraryContainer
{
public:
    FTLibraryContainer();
    ~FTLibraryContainer();

    FT_Library& getLibrary();

private:
    static FT_Library library_;
};

class StreamFlusher { };
std::ostream& operator<<(std::ostream& os, const StreamFlusher& rhs);

class GLFT_Font
{
public:
    GLFT_Font();
    GLFT_Font(const std::string& filename, unsigned int size);

    ~GLFT_Font();

    void open(const std::string& filename, unsigned int size);
    void release();
    
    bool isValid() const;

    void drawText(float x, float y, const char *str, ...) const;
    void drawText(float x, float y, const std::string& str) const;
    
    std::ostream& beginDraw(float x, float y);
    StreamFlusher endDraw();
    
    unsigned int calcStringWidth(const std::string& str) const;
    unsigned int getHeight() const;

private:
    // leave copy constructor and operator= undefined to make noncopyable
    GLFT_Font(const GLFT_Font&);
    const GLFT_Font& operator=(const GLFT_Font&);
    
private:
    // font data
    unsigned int texID_;
    unsigned int listBase_;
    std::vector<unsigned char> widths_;
    unsigned char height_;
    // stream drawing stuff
    std::ostringstream ss_;
    float drawX_;
    float drawY_;

    static const unsigned int SPACE = 32;
    static const unsigned int NUM_CHARS = 96;

    static FTLibraryContainer library_;
};

#endif //GLFT_FONT_HPP
