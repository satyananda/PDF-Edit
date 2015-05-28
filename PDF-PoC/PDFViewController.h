//
//  PDFViewController.h
//  PDF-PoC
//
//  Created by Rajeshkumar on 11/05/15.
//  Copyright (c) 2015 T-Mobile. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PDFView;
@class PDFDocument;

@interface PDFViewController : UIViewController <UICollectionViewDataSource, UICollectionViewDelegate>

/** The PDFDocument that represents the model for the PDFViewController
 */
@property (nonatomic, strong) PDFDocument *document;

/** The PDFView that represents the view for the PDFViewController
 */
@property (nonatomic, strong) PDFView *pdfView;

/**---------------------------------------------------------------------------------------
 * @name Creating a PDFViewController
 *  ---------------------------------------------------------------------------------------
 */

/** Creates a new instance of PDFViewController.
 
 @param data Content of the document.
 @return A new instance of PDFViewController initialized with data.
 */

//- (instancetype)initWithData:(NSData *)data NS_DESIGNATED_INITIALIZER;

/** Creates a new instance of PDFViewController.
 
 @param name Resource to load.
 @return A new instance of PDFViewController initialized with a PDF resource named name.
 */
//- (instancetype)initWithResource:(NSString *)name NS_DESIGNATED_INITIALIZER;

/** Creates a new instance of PDFViewController.
 
 @param path Points to PDF file to load.
 @return A new instance of PDFViewController initialized with a PDF located at path.
 */
//- (instancetype)initWithPath:(NSString *)path NS_DESIGNATED_INITIALIZER;

/**---------------------------------------------------------------------------------------
 * @name Reloading Content
 *  ---------------------------------------------------------------------------------------
 */

/** Reloads the entire PDF.
 */
- (void)reload;

@property (strong, nonatomic) NSString *pdfPath ;

@end
