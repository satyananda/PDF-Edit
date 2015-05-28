//
//  PDFViewController.m
//  PDF-PoC
//
//  Created by Rajeshkumar on 11/05/15.
//  Copyright (c) 2015 T-Mobile. All rights reserved.
//

#import "PDFViewController.h"
#import "MBProgressHUD.h"
#import "PDF.h"
#import "PDFFormContainer.h"
#import "PDFDataModel.h"

@interface PDFViewController ()
{
    PDFDataModel *pdfDataModel;
    BOOL isAnnotationEnabled;
}
@end

@implementation PDFViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    [self doInitialSetup];
}

- (void)viewDidAppear:(BOOL)animated
{
    _document = [[PDFDocument alloc] initWithPath:_pdfPath];
    [self loadPDFView];
    [self populateEnteredValues];
}

- (void)viewWillDisappear:(BOOL)animated
{
    NSMutableArray *formInfo = [NSMutableArray new];
    for (PDFForm *form in _document.forms)
    {
        if([form value].length != 0)
        {
            NSDictionary *formFieldInfo = @{@"name": form.name, @"value":form.value};
            [formInfo addObject:formFieldInfo];
        }
    }
    [pdfDataModel setPdfData:formInfo];
}

#pragma mark - IBAction

- (void)barBtnSaveTapped:(id)sender
{
    NSString *docDirPath = [self applicationDocumentsDirectory];
    NSString *newPdfPath = [docDirPath stringByAppendingPathComponent:@"new.pdf"];
    
    NSData *pdfData = [_document savedStaticPDFData];
    [pdfData writeToFile:newPdfPath atomically:true];
//    _document = [[PDFDocument alloc] initWithData:pdfData];
//    [self loadPDFView];
}

- (void)barBtnAnnotateTapped:(id)sender
{
//    [_pdfView addAnnotationView];
//    [[_pdfView pdfAnnotationView] setBackgroundColor:[UIColor redColor]];
//    [[_pdfView pdfAnnotationView] setAlpha:0.8];
}

#pragma mark - Private

- (NSString *)applicationDocumentsDirectory
{
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *basePath = ([paths count] > 0) ? [paths objectAtIndex:0] : nil;
    return basePath;
}

- (void)doInitialSetup
{
    pdfDataModel = [PDFDataModel sharedInstance];
    
    UIBarButtonItem *barBtnSave = [[UIBarButtonItem alloc] initWithTitle:@"Save" style:UIBarButtonItemStylePlain target:self action:@selector(barBtnSaveTapped:)];
    UIBarButtonItem *barBtnAnnotate = [[UIBarButtonItem alloc] initWithTitle:@"Annotate" style:UIBarButtonItemStylePlain target:self action:@selector(barBtnAnnotateTapped:)];
    [[self navigationItem] setRightBarButtonItems:@[barBtnAnnotate, barBtnSave] animated:true];
}

- (void)reload
{
    [_document refresh];
    [_pdfView removeFromSuperview];
    _pdfView = nil;
    [self loadPDFView];
}

- (void)loadPDFView
{
    id pass = (_document.documentPath ? _document.documentPath:_document.documentData);
    CGPoint margins = [self getMargins];
    NSArray *additionViews = [_document.forms createWidgetAnnotationViewsForSuperviewWithWidth:self.view.bounds.size.width margin:margins.x hMargin:margins.y];
    _pdfView = [[PDFView alloc] initWithFrame:self.view.bounds dataOrPath:pass additionViews:additionViews];
    [self.view addSubview:_pdfView];
}

- (void)populateEnteredValues
{
    for (NSDictionary *formFieldInfo in [pdfDataModel pdfData])
    {
        [_document.forms setValue:formFieldInfo[@"value"] forFormWithName:formFieldInfo[@"name"]];
    }
}

- (CGPoint)getMargins
{
    static const float PDFLandscapePadWMargin = 13.0f;
    static const float PDFLandscapePadHMargin = 7.25f;
    static const float PDFPortraitPadWMargin = 9.0f;
    static const float PDFPortraitPadHMargin = 6.10f;
    static const float PDFPortraitPhoneWMargin = 3.5f;
    static const float PDFPortraitPhoneHMargin = 6.7f;
    static const float PDFLandscapePhoneWMargin = 6.8f;
    static const float PDFLandscapePhoneHMargin = 6.5f;
    
    if (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad) {
        if (UIInterfaceOrientationIsPortrait(self.interfaceOrientation))return CGPointMake(PDFPortraitPadWMargin,PDFPortraitPadHMargin);
        else return CGPointMake(PDFLandscapePadWMargin,PDFLandscapePadHMargin);
    } else {
        if (UIInterfaceOrientationIsPortrait(self.interfaceOrientation))return CGPointMake(PDFPortraitPhoneWMargin,PDFPortraitPhoneHMargin);
        else return CGPointMake(PDFLandscapePhoneWMargin,PDFLandscapePhoneHMargin);
    }
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
