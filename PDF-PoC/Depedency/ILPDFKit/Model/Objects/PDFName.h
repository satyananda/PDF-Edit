// PDFName.h
// 
// Copyright (c) 2015 Iwe Labs
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>
#import "PDFObject.h"

#define PDFName NSString

/** PDFName is an alias for NSString. It represents Name PDF objects. Functionality is added via a category.
 */
@interface PDFName(PDFObject) <PDFObject>

/**
@return A C string representation of the key.
 */
- (const char *)pdfCString;

/**
 @param cString A null terminated C string.
 @return An initialized instance, based on the passed C string.
 */
- (instancetype)initWithPDFCString:(const char *)cString;

/**
 @return The UTF-8 string resulting when the bytes of the receiver are interpreted as UTF-8 text, after hash decoding any hash escaped bytes.
 */
- (NSString *)utf8DecodedString;


@end


