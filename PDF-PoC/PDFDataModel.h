//
//  pdfDataModel.h
//  PDF-PoC
//
//  Created by Rajeshkumar on 11/05/15.
//  Copyright (c) 2015 T-Mobile. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PDFDataModel : NSObject

+ (instancetype)sharedInstance;

@property (strong, nonatomic) NSMutableArray *pdfData;

@end
