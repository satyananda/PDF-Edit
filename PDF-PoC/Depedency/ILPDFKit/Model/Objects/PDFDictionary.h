// PDFDictionary.h
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
#import "PDFName.h"

/** The PDFDictionary class encapsulates a PDF dictionary object contained in a PDFDocument. 
 Essentially, is is a wrapper class for a CGPDFDictionaryRef.
 
        CGPDFDictionaryRef pdfDRef = CGPDFDocumentGetCatalog(document);
        PDFDictionary* pdfDictionary = [[PDFDictionary alloc] initWithDictionary:pdfDRef];
 
 PDFDictionary provides a range of methods that mirror those of NSDictionary. PDFDictionary may also
 be instantiated based on a string representation of its contents without needing to be assoicated with
 a parent document.
 */

@interface PDFDictionary : NSObject <NSFastEnumeration, PDFObject>

/**
 The Core Graphics dictionary reference, if it exists.
 */
@property (nonatomic, readonly) CGPDFDictionaryRef dict;

/** The PDFDictionary that self is value of for some key, if it exists.
 @discussion If no such parent exists, parent is nil.
 */
@property (nonatomic, weak) PDFDictionary *parent;

/**---------------------------------------------------------------------------------------
 * @name Creating a PDFDictionary
 *  ---------------------------------------------------------------------------------------
 */ 

/** Creates a new instance of PDFDictionary wrapping a CGPDFDictionaryRef
 @param pdict A CGPDFDictionaryRef representing the PDF dictionary.
 @return A new PDFDictionary object. Initialization in memory occurs when the instance receives a key or value based query.
 */
- (instancetype)initWithDictionary:(CGPDFDictionaryRef)pdict NS_DESIGNATED_INITIALIZER;


/** Merges the receiver's elements with the elements of changes.
 @param changes The keys and values are merged with and take precedence over the receiver.
 @return The merged dictionary.
 */
- (PDFDictionary *)dictionaryByMergingDictionary:(NSDictionary *)changes;


/**---------------------------------------------------------------------------------------
 * @name Accessing Keys and Values
 *  ---------------------------------------------------------------------------------------
 */

/** Returns the value associated with a given key.
 
 @param key The key for which to return the corresponding value
 @return The value associated with key, or nil if no value is associated with key.
 */
- (id)objectForKey:(PDFName *)key;


/** Returns a new array containing the dictionary’s keys.
 
 @return A new array containing the dictionary’s keys, or an empty array if the dictionary has no entries.
 @discussion The order of the elements in the array is not defined.
 */
- (NSArray *)allKeys;


/** Returns a new array containing the dictionary’s values.
 @return A new array containing the dictionary’s values, or an empty array if the dictionary has no entries.
 @discussion The order of the elements in the array is not defined.
 */
- (NSArray *)allValues;


/** Returns an inheritable attribute based on a key.
 @param key The dictionary key
 @return The pdf object if found by searching up the parent chain, or nil if not found.
 */
- (id)inheritableValueForKey:(PDFName *)key;

/** Returns an array for all values for key found in parent dictionaries.
 @param key The dictionary key
 @return The array containing all values for key by successively searching up the parent chain.
 */
- (NSArray *)parentValuesForKey:(PDFName *)key;

/**---------------------------------------------------------------------------------------
 * @name Counting Entries
 *  ---------------------------------------------------------------------------------------
 */

/** Returns the number of entries in the dictionary.
 @return The number of entries in the dictionary.
 */
- (NSUInteger)count;

/**---------------------------------------------------------------------------------------
 * @name Comparing Dictionaries
 *  ---------------------------------------------------------------------------------------
 */

/** Returns a Boolean value that indicates whether the contents of the receiving dictionary are equal to the contents of another given dictionary.
 @param otherDictionary The dictionary with which to compare the receiving dictionary.
 @return YES if the contents of otherDictionary are equal to the contents of the receiving dictionary, otherwise NO.
 @discussion Two dictionaries have equal contents if they each hold the same number of entries and, for a given key, the corresponding value objects in each dictionary satisfy the isEqual: test.
 */
- (BOOL)isEqualToDictionary:(PDFDictionary *)otherDictionary;

////// This class supports keyed subscripting as in id<PDFObject> obj = pdfDictionary[@"key"];

- (id)objectForKeyedSubscript:(id <NSCopying>)key;

@end
