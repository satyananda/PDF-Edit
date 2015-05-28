//
//  ViewController.m
//  PDF-PoC
//
//  Created by Rajeshkumar on 11/05/15.
//  Copyright (c) 2015 T-Mobile. All rights reserved.
//

#import "HomeViewController.h"
#import "PDFViewController.h"

#define kAnnotate @"Annotate form PDF through keyboard entry and free hand example"
#define kThumbnail @"PDF pagewise thumbnail example"
#define kPrint @"Print PDF and E-mail example"
#define kSign @"Digitally sign PDF example"
#define kTMobilePdf @"T-MobileTestPDF.pdf"

@interface HomeViewController ()
{
    NSString *selectedPdfPath;
    NSArray *tableviewContents;
}
@end

@implementation HomeViewController

#pragma mark - View Controller Life cycle methods
- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    [self doInitialSetup];
}

#pragma mark - UITableviewDatasource
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return [tableviewContents count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    
    static NSString *cellIdentifier = @"Cell";
    
    UITableViewCell *cell ;
    if(cell == nil){
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:cellIdentifier];
    }
    
    //cell customisation
    [cell setAccessoryType:UITableViewCellAccessoryDisclosureIndicator];
    [[cell textLabel] setText:[tableviewContents objectAtIndex:indexPath.row]];
    
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    NSString *pdfName = tableviewContents[[indexPath row]];
    if([kAnnotate isEqualToString:pdfName])
        pdfName = @"Annotate form PDF through keyboard entry and free hand example";
    else if ([kThumbnail isEqualToString:pdfName])
        pdfName = @"Head First Android Development";
    else if ([kSign isEqualToString:pdfName])
        pdfName = @"T-MobileTestPDF";
    else
        pdfName = @"Associate Observation Guide";
    
    selectedPdfPath = [[NSBundle mainBundle] pathForResource:pdfName ofType:@"pdf"];
    [self showPdf];
}

#pragma mark - Storyboard Segue

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    PDFViewController *pdfViewCtrl = [segue destinationViewController];
    [pdfViewCtrl setPdfPath:selectedPdfPath];
}

#pragma mark - Private Methods

- (void)showPdf
{
    [self performSegueWithIdentifier:@"PDF_VIEW_CTRL_SEGUE_ID" sender:self];
}

- (void)doInitialSetup
{
    tableviewContents = @[kAnnotate, kThumbnail, kPrint, kSign];
}

#pragma mark - Memory

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
