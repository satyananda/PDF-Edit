// PDFWidgetAnnotationView.h
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

@class PDFWidgetAnnotationView;
@class PDFView;

/** The PDFWidgetAnnotationViewDelegate responds to user interaction with a PDFWidgetAnnotationView.
 */
@protocol PDFWidgetAnnotationViewDelegate <NSObject>
/** Called when the value changes.
 @param sender The sending PDFWidgetAnnotationView.
 */
- (void)widgetAnnotationValueChanged:(PDFWidgetAnnotationView *)sender;
/** Called when the the element is focused or expanded.
 @param sender The sending PDFWidgetAnnotationView.
 */
- (void)widgetAnnotationEntered:(PDFWidgetAnnotationView *)sender;
/** Called when the options changes for choice field views.
 @param sender The sending PDFWidgetAnnotationView.
 */
- (void)widgetAnnotationOptionsChanged:(PDFWidgetAnnotationView *)sender;
@end

/** The PDFWidgetAnnotationView represents a subview of a PDFView that represents an interactive or accessory element. A PDFForm is an example.
 */
@interface PDFWidgetAnnotationView : UIView {
    CGFloat _zoomScale;
}

/** The value of the element.
 @discussion If there is an associated PDFForm to the view, then set of values are synced using key value observing.
 */
@property (nonatomic, strong) NSString *value;

/** The options of the element.
 @discussion If there is an associated PDFForm to the view, then set of options are synced using key value observing.
 */
@property (nonatomic, strong) NSArray *options;

/** The initial frame of the view, without any transformations applied to its superview.
 */
@property (nonatomic, readonly) CGRect baseFrame;

/** The delegate.
 */
@property (nonatomic, weak) NSObject<PDFWidgetAnnotationViewDelegate> *delegate;

/** The parent view.
 */
@property (nonatomic, weak) PDFView *parentView;

/**---------------------------------------------------------------------------------------
 * @name Updating Metrics
 *  ---------------------------------------------------------------------------------------
 */

/** Updates the view based on the zoom level of its UIScrollView superview.
 @param zoom The new zoom level.
 */
- (void)updateWithZoom:(CGFloat)zoom;


/** For widget annotations with text, this method returns how font size should be initially scaled with respect to the bounding rect.
 @param rect The bounding frame of the widget in iOS screen space, not PDF canvas space.
 @param value The text to render.
 @param multiline YES if multiple lines of text are permitted.
 @param choice YES if the field is a choice field.
 */
+ (CGFloat)fontSizeForRect:(CGRect)rect value:(NSString *)value multiline:(BOOL)multiline choice:(BOOL)choice;

/**---------------------------------------------------------------------------------------
 * @name Updating Data
 *  ---------------------------------------------------------------------------------------
 */

/** Refreshes the contents.
 */
- (void)refresh;

/**---------------------------------------------------------------------------------------
 * @name Managing Focus
 *  ---------------------------------------------------------------------------------------
 */

/** Resigns th input focus.
 */
- (void)resign;

@end
