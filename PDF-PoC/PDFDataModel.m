//
//  pdfDataModel.m
//  PDF-PoC
//
//  Created by Rajeshkumar on 11/05/15.
//  Copyright (c) 2015 T-Mobile. All rights reserved.
//

#import "PDFDataModel.h"

@implementation PDFDataModel

+ (instancetype)sharedInstance
{
    static PDFDataModel *sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[self alloc] init];
    });
    return sharedInstance;
}

@end
