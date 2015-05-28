// PDFSerializer.h
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

/**
    The PDFSerialzer class encapsulates the task of saving the changes in a PDF, such as form value changes, to the source PDF file itself.
 The file can then easily to be written to disk or sent over the internet with the changes intact. This class is a static class. 
 Support is currently incomplete and PDF with version numbers over 1.3 are unsupported.
 */
@interface PDFSerializer : NSObject


/** Attempts to save any changes in the PDF forms of a document to the document itself.
 
 @param baseData The data that represents the PDF file you are saving to.
 @param forms The collection of forms that contain the changes to save if they exist.
 @param completion Called after the save operation has completed.
 */
+ (void)saveDocumentChanges:(NSMutableData *)baseData basedOnForms:(id<NSFastEnumeration>)forms  completion:(void (^)(BOOL success))completion;
@end
