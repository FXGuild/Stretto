// MIT License
//
// Copyright (c) 2017 FXGuild
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef FXG_STRETTO_THEORY_NOTEDURATION
#define FXG_STRETTO_THEORY_NOTEDURATION

#include <stdint.h>

namespace FXG {
namespace Stretto {
namespace Theory {

enum class NoteDuration : uint8_t
{
   WHOLE,
   HALF,
   QUARTER,
   EIGHT,
   SIXTEENTH,
   THIRTYSECOND,
   SIXTYSECOND
};

uint32_t CountSubDurations(NoteDuration a_DurationToDivide, NoteDuration a_SubDuration);

}  // Namespace end
}
}

#endif FXG_STRETTO_THEORY_NOTEDURATION
