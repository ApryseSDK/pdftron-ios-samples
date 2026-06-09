//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------
//
//  IMPORTANT:
//  PDFNet must be initialized with a trial key. Please see https://www.pdftron.com/kb_init_ios
//  for more information.

#include <PDFNet/PDFNetDefines.h>
#include <PDFNet/PDFNetOBJC.h>

NS_ASSUME_NONNULL_BEGIN

@class PTPDFViewCtrl;
@protocol PTPDFViewCtrlDelegate;
@protocol PTPDFViewCtrlToolDelegate;

typedef enum {
    e_trn_fit_page,
    e_trn_fit_width,
    e_trn_fit_height,
    e_trn_zoom
} TrnPageViewMode;

typedef enum {
    e_trn_single_page = 1, 	
    e_trn_single_continuous, 	
    e_trn_facing, 	
    e_trn_facing_continuous, 	
    e_trn_facing_cover, 	
    e_trn_facing_continuous_cover 
} TrnPagePresentationMode;

typedef enum {
    e_trn_zoom_limit_absolute = 1,
    e_trn_zoom_limit_relative,
    e_trn_zoom_limit_none
} TrnZoomLimitMode;

/**
 * The paging direction for non-continuous page presentation modes.
 */
typedef NS_ENUM(NSUInteger, PTPDFViewCtrlPagingDirection) {
    
    /**
     * Pages are arranged horizontally.
     */
    PTPDFViewCtrlPagingDirectionHorizontal,
    
    /**
     * Pages are arranged vertically.
     */
    PTPDFViewCtrlPagingDirectionVertical,
    
} NS_SWIFT_NAME(PTPDFViewCtrl.PagingDirection);

/**
 * PTPDFViewCtrl is a utility class that can be used for interactive rendering of PDF documents.
 *
 * On iOS, PTPDFViewCtrl derives from UIView.
 *
 * PTPDFViewCtrl defines several coordinate spaces and it is important to understand their
 * differences:
 *
 * - Page Space refers to the space in which a PDF page is defined. It is determined by
 * a page itself and the origin is at the lower-left corner of the page. Note that Page
 * Space is independent of how a page is viewed in PDFView and each page has its own Page
 * space.
 *
 * - Canvas Space refers to the tightest axis-aligned bounding box of all the pages given
 * the current page presentation mode in PDFView. For example, if the page presentation
 * mode is e_single_continuous, all the pages are arranged vertically with one page in each
 * row, and therefore the Canvas Space is a rectangle with possibly large height value. For
 * this reason, Canvas Space is also, like Page Space, independent of the zoom factor. Also
 * note that since PDFView adds gaps between adjacent pages, the Canvas Space is larger than
 * the space occupied by all the pages. The origin of the Canvas Space is located at the
 * upper-left corner.
 *
 * - Screen Space (or Client Space) is the space occupied by PDFView and its origin is at
 * the upper-left corner. Note that the virtual size of this space can extend beyond the
 * visible region.
 *
 * - Scrollable Space is the virtual space within which PDFView can scroll. It is determined
 * by the Canvas Space and the current zoom factor. Roughly speaking, the dimensions of the
 * Scrollable Space is the dimensions of the Canvas Space timed by the zoom. Therefore, a large
 * zoom factor will result in a larger Scrollable region given the same Canvas region. For this
 * reason, Scrollable Space might also be referred to as Zoomed Canvas Space. Note that since
 * PDFView adds gaps between pages in Canvas Space and these gaps are not scaled when rendered,
 * the scrollable range is not exactly what the zoom factor times the Canvas range. For
 * functions such as `-SetHScrollPos:`, `-SetVScrollPos:`, `-GetCanvasHeight`, and
 * `-GetCanvasWidth`, it is the Scrollable Space that is involved.
 *
 */
PDFNET_EXTERN
PDFNET_OBJC_RUNTIME_NAME(PTPDFViewCtrl)
@interface PTPDFViewCtrl : UIView <UIScrollViewDelegate, UIGestureRecognizerDelegate> {
    
    @public
    /**
     * Deprecated
     * The view that displays the PDF, that is the content view of a UIScrollView.
	 * Please use `overlayView` or `toolsView` for displaying content on top of the PDF.
     */
    UIView* ContainerView  __deprecated_msg("Use the overlayView or toolOverlayView property instead.");

    @private
    UIScrollView* innerScrollView;
    UIScrollView* outerScrollView;
}


#pragma mark - Properties
/** @name Properties
 */


/**
 * A view that extends over the entire scrollable area of `PTPDFViewCtrl`. This view can be used to
 * attach subviews for drawing custom content on top of the PDF.
 */
@property (nonatomic, retain, readonly) UIView* overlayView;

/**
 * A view that extends over the entire scrollable area of `PTPDFViewCtrl`, but under the `overlayView`.
 * This view can be used to attach subviews for annotation handling (by default used by the included
 * tools library).
 */
@property (nonatomic, retain, readonly) UIView* toolOverlayView;

/**
 * The scroll view responsible for paging in non-continuous page presentation modes.
 *
 * The delegate of this scroll view is the owning `PTPDFViewCtrl` instance and should
 * not be re-assigned.
 */
@property (nonatomic, retain, readonly) UIScrollView *pagingScrollView;

/**
 * The scroll view responsible for panning and zooming of page content.
 *
 * The delegate of this scroll view is the owning `PTPDFViewCtrl` instance and should
 * not be re-assigned.
 */
@property (nonatomic, retain, readonly) UIScrollView *contentScrollView;

/**
 * An object that conforms to the PTPDFViewCtrlDelegate protocol.
 *
 */
@property (nonatomic, weak, nullable) id<PTPDFViewCtrlDelegate> delegate;

/**
 * An object that conforms to the `PTPDFViewCtrlToolDelegate` protocol.
 *
 */
@property (nonatomic, weak, nullable) id<PTPDFViewCtrlToolDelegate> toolDelegate;

/**
 * Enables or disables the ability for the user to scroll the content.
 *
 */
@property (nonatomic, assign) BOOL scrollEnabled;

/**
 * Enables or disables the ability for the user to pinch-zoom the control.
 *
 */
@property (nonatomic, assign) BOOL zoomEnabled;

/**
 * Enables or disables the document's use of a retina display. If it is disabled,
 * the document will display at a non-retina resolution. Default is enabled.
 *
 */
@property (nonatomic, assign) BOOL retinaEnabled;

/**
 * Enables or disables automatically calling PurgeMemory when a low memory
 * warning is received. Default YES.
 *
 */
@property (nonatomic, assign) BOOL purgeMemoryOnMemoryWarning;


/**
 * A Boolean value that determines whether scrolling is disabled in a particular direction.
 */
@property(nonatomic, getter=isDirectionalLockEnabled) BOOL directionalLockEnabled;

/**
 * The behavior for determining the adjusted content offsets. This property specifies how
 * the safe area insets are used to modify the content area of the scroll view. The default
 * value of this property is Never.
 */
@property(nonatomic) UIScrollViewContentInsetAdjustmentBehavior contentInsetAdjustmentBehavior API_AVAILABLE(ios(11.0),tvos(11.0));

/**
 * A double value that determines the extra vertical content accounted for by the on-screen keyboard
 */
@property(assign, nonatomic, readonly) double extraVerticalContentForKeyboard;

#pragma mark - Document Loading and Closing
/** @name Document Loading and Closing
 */

/**
 * Associates this PTPDFViewCtrl with a given PDF document.
 *
 * @param doc A document to be displayed in the view.
 *
 * @note SetDoc acquires a write lock on the document, so the document
 * must be unlocked when this method is called or an exception will be
 * thrown.
 *
 */
-(void)SetDoc:(PTPDFDoc*)doc;

/**
 * @return Currently associated document with this PTPDFViewCtrl.
 */
-(nullable PTPDFDoc*)GetDoc;

/**
 * Closes the document currently opened in PTPDFViewCtrl.
 *
 * @note CloseDoc acquires a write lock on the document, so the document
 * must be unlocked when this method is called or an exception will be
 * thrown.
 */
-(void)CloseDoc;

/**
 * Sets the PDF document from a URL. If the PDF is linearized, PTPDFViewCtrl will
 * display it incrementally while downloading it. If the PDF is not linearized,
 * it will display blank pages until the entire document is downloaded.
 *
 * @param url The URL of the document to open.
 *
 * @note This method will acquire a write lock on the document that is displayed in the viewer
 * when this method is called, so it must be free of locks or an exception will be thrown.
 */
-(void)OpenUrlAsync:(NSString*)url;

/**
 * Sets the PDF document from a URL. If the PDF is linearized, PTPDFViewCtrl will
 * display it incrementally while downloading it. If the PDF is not linearized,
 * it will display blank pages until the entire document is downloaded.
 *
 * @param url The URL of the document to open.
 *
 * @param password The password used to open the PDF document if it is password
 * protected.
 *
 * @note This method will acquire a write lock on the document that is displayed in the viewer
 * when this method is called, so it must be free of locks or an exception will be thrown.
 */
-(void)OpenUrlAsync:(NSString*)url WithPDFPassword:(nullable NSString*)password;

/**
 * Sets the PDF document from a URL. If the PDF is linearized, PTPDFViewCtrl will
 * display it incrementally while downloading it. If the PDF is not linearized,
 * it will display blank pages until the entire document is downloaded.
 *
 * @param url The URL of the document to open.
 *
 * @param password The password used to open the PDF document if it is password
 * protected.
 *
 * @param fullPath The path to a file that will be used to cache the downloaded file which
 * will be used to resume a download. If no cache file is specified, a file is created in
 * the temporary directory.
 *
 * @note This method will acquire a write lock on the document that is displayed in the viewer
 * when this method is called, so it must be free of locks or an exception will be thrown.
 */
-(void)OpenUrlAsync:(NSString*)url WithPDFPassword:(nullable NSString*)password WithCacheFile:(nullable NSString*)fullPath;

/**
 * Sets the PDF document from a URL. If the PDF is linearized, PTPDFViewCtrl will
 * display it incrementally while downloading it. If the PDF is not linearized,
 * it will display blank pages until the entire document is downloaded.
 *
 * @param url The URL of the document to open.
 *
 * @param password The password used to open the PDF document if it is password
 * protected.
 *
 * @param fullPath The path to a file that will be used to cache the downloaded file which
 * will be used to resume a download. If no cache file is specified, a file is created in
 * the temporary directory.
 *
 * @param options HTTP request options to use with every HTTP request
 *
 * @note This method will acquire a write lock on the document that is displayed in the viewer
 * when this method is called, so it must be free of locks or an exception will be thrown.
 */
-(void)OpenUrlAsync:(NSString*)url WithPDFPassword:(nullable NSString*)password WithCacheFile:(nullable NSString*)fullPath WithOptions:(nullable PTHTTPRequestOptions*)options;


/**
 *
 * Opens a streamable document type that requires conversion, such as .doc, .docx, .pptx, .xlsx.
 * The `PTPDFViewCtrl` will show the document incrementally as it is converted.
 *
 * @param conversion The conversion object
 */
-(void)openUniversalDocumentWithConversion:(PTDocumentConversion*)conversion;


/**
 * @return The document conversion object passed into `-openUniversalDocumentWithConversion:`.
 */
-(PTDocumentConversion*)documentConversion;

#pragma mark - Page Navigation

/** @name Page Navigation
 */

/**
 * An array of NSNumbers with the pages currently visible on the screen.
 */
@property (nonatomic, readonly, getter=GetVisiblePages) NSArray<NSNumber* >* visiblePages;

/**
 * Get an array of NSNumbers with the pages currently visible on the screen.
 *
 * @return an array of NSNumbers of the pages currently visible on the screen.
 *
 * **Unavailable in Swift. Please use the property:**
 *
 * @see `visiblePages`
 */
-(NSArray<NSNumber* >*)GetVisiblePages;

/**
 * Find if a specific page is currently visible on the screen
 *
 * @param pageNumber The page number of the page to check.
 *
 * @return true if the page is on screen, false otherwise.
 */
-(BOOL)pageIsOnScreen:(int)pageNumber;

/**
 * The page number of the page displayed in the view.
 **/
@property (nonatomic, getter=GetCurrentPage, setter=PT_setCurrentPage:) int currentPage;

/**
 * Get the current page displayed in the view.
 *
 * @return the current page displayed in the view.
 *
 * **Unavailable in Swift. Please use the property:**
 *
 * @see `currentPage`
 */
-(int)GetCurrentPage;

/**
 * Sets the current page to the given page.
 *
 * @return true if successful, false otherwise.
 */
-(bool)SetCurrentPage:(int)page_num;

/**
 * Sets the current page to the first page in the document.
 *
 * @return true if successful, false otherwise.
 */
-(bool)GotoFirstPage;

/**
 * Sets the current page to the last page in the document.
 *
 * @return true if successful, false otherwise.
 */
-(bool)GotoLastPage;

/**
 * Sets the current page to the next page in the document.
 *
 * @return true if successful, false otherwise.
 */
-(bool)GotoNextPage;

/**
 * Sets the current page to the previous page in the document.
 *
 * @return true if successful, false otherwise.
 */
-(bool)GotoPreviousPage;

#pragma mark - Viewer scroll position and zoom level

/** @name Viewer scroll position and zoom level
 */

/**
 * Get the current horizontal scroll position. The returned value is expressed in the
 * canvas coordinate system. The canvas coordinate system is defined by a bounding box that
 * surrounds all pages in the view.
 *
 * @return the current horizontal scroll position.
 */
-(double)GetHScrollPos;

/**
 * Get the current vertical scroll position. The returned value is expressed in the
 * canvas coordinate system. The canvas coordinate system is defined by a bounding box that
 * surrounds all pages in the view.
 *
 * @return the current vertical scroll position.
 */
-(double)GetVScrollPos;

/**
 * Sets the horizontal scroll position. The position should be a number in the range
 * between 0 and `-GetCanvasWidth` and is expressed in the canvas coordinate system.
 * The canvas coordinate system is defined by a bounding box that surrounds all pages in the view.
 * If Animated is not specified, the default value is YES.
 *
 * @param pos the new horizontal scroll position.
 */
-(void)SetHScrollPos:(double)pos;

/**
 * Sets the horizontal scroll position. The position should be a number in the range
 * between 0 and `-GetCanvasWidth` and is expressed in the canvas coordinate system.
 * The canvas coordinate system is defined by a bounding box that surrounds all pages in the view.
 *
 * @param pos The new horizontal scroll position.
 *
 * @param animated Whether to animate the change in scroll position.
 */
-(void)SetHScrollPos:(double)pos Animated:(BOOL)animated;

/**
 * Sets the vertical scroll position. The position should be a number in the range
 * between 0 and `-GetCanvasHeight` and is expressed in the canvas coordinate system.
 * The canvas coordinate system is defined by a bounding box that surrounds all pages in the view.
 * If Animated is not specified, the default value is YES.
 *
 * @param pos The new vertical scroll position.
 */
-(void)SetVScrollPos:(double)pos;

/**
 * Sets the vertical scroll position. The position should be a number in the range
 * between 0 and `-GetCanvasHeight` and is expressed in the canvas coordinate system.
 * The canvas coordinate system is defined by a bounding box that surrounds all pages in the view.
 *
 * @param pos The new vertical scroll position.
 *
 * @param animated Whether to animate the change in scroll position.
 */
-(void)SetVScrollPos: (double)pos Animated:(BOOL)animated;

/**
 * The zoom level of the PDF.
 */
@property (nonatomic, getter=GetZoom, setter=SetZoom:) double zoom;

/**
 * Returns the current zoom level of the PDF.
 *
 * @return current zoom (or scaling) component used to display the page content.
 *
 * **Unavailable in Swift. Please use the property:**
 *
 * @see `zoom`
 */
-(double)GetZoom;

/**
 * Sets the zoom level of the PDF to a new value. The function zooms to a point at the
 * center of the rendering buffer.
 *
 * @param zoom new scaling component used to display the page content.
 *
 * **Unavailable in Swift. Please use the property:**
 *
 * @see `zoom`
 */
-(void)SetZoom:(double)zoom;

/**
 * Sets the zoom factor to a new value using the given pixel coordinate
 * (x,y) as a zoom center.
 *
 * The zoom point (x,y) is represented in the screen coordinate system, which
 * starts in the upper-left corner of the client window.
 *
 * @param x the horizontal coordinate to zoom in.
 * @param y the vertical coordinate to zoom in.
 * @param zoom new scaling component used to display the page content.
 */
-(void)SetZoomX:(int)x Y:(int)y Zoom:(double)zoom;

/**
 * Sets the zoom factor to a new value using the given pixel coordinate
 * (x,y) to find an intersecting paragraph.
 * The width of the paragraph helps to determine the zoom value, center
 * of the paragraph is used as a zoom center.
 * Paragraph has to contain more than one line and be wider than 1/5th of a page width.
 * When called on a paragraph wider than current zoom level, or smart zoom cannot
 * find something to zoom on, the method returns false.
 * The zoom point (x,y) is represented in the screen space, which
 * starts in the upper-left corner of the client window.
 *
 * @param in_x the horizontal coordinate to look for a text block.
 * @param in_y the vertical coordinate to look for a text block.
 * @param animated whether or not to animate the zooming
 *
 * @return true if successful, false if no zooming was performed.
 */
-(BOOL)SmartZoomX:(double)in_x y:(double)in_y animated:(BOOL)animated;

/**
 * Changes the viewing area to fit a rectangle rect on page `page_num`.
 * The rectangle must be specified in page coordinates.
 * This will adjust current page and zoom appropriately.
 *
 * @param page_num the specified page number
 * @param rect the rectangle to fit in
 * @return true if successful, false otherwise.
 */
-(BOOL)ShowRect:(int)page_num rect:(PTPDFRect*)rect;

/**
 * Changes the viewing area to fit a rectangle in viewer coordinates.
 *
 * @param rect the rectangle to zoom in, in viewer coordinates.
 * @param animated will animate zoom if YES, will not if NO.
 */
- (void)zoomToRect:(CGRect)rect animated:(BOOL)animated;


#pragma mark - Page View and Presentation Modes

/** @name Page View and Presentation Modes
 */

/**
 * The page view mode. The default PageView mode is `e_trn_fit_width`.
 */
@property (nonatomic, getter=GetPageViewMode, setter=SetPageViewMode:) TrnPageViewMode pageViewMode;

/**
 * Get the current page viewing mode.
 *
 * @return the current page viewing mode
 *
 * **Unavailable in Swift. Please use the property:**
 *
 * @see `pageViewMode`
 */
-(TrnPageViewMode)GetPageViewMode;

/**
 * Sets the page viewing mode. The default PageView mode is `e_trn_fit_width`.
 *
 * @param mode the new page viewing mode.
 *
 * **Unavailable in Swift. Please use the property:**
 *
 * @see `pageViewMode`
 */
-(void)SetPageViewMode:(TrnPageViewMode)mode;

/**
 * The reference page view mode.
 *
 * In a non-continous page presentation
 * mode, the reference page view mode is used to determine the page view
 * mode upon a page change event. For example, if the reference page view
 * mode is set to `e_trn_fit_width`, the new page coming in will
 * be displayed with width-fit mode.
 */
@property (nonatomic, getter=GetPageRefViewMode, setter=SetPageRefViewMode:) TrnPageViewMode pageRefViewMode;

/**
 * Sets the reference page view mode. In a non-continous page presentation
 * mode, the reference page view mode is used to determine the page view
 * mode upon a page change event. For example, if the reference page view
 * mode is set to `e_trn_fit_width`, the new page coming in will
 * be displayed with width-fit mode.
 *
 * @param mode
 *            The reference page view mode to set. Valid values are
 *            `e_trn_fit_page`, `e_trn_fit_width`, and
 *            `e_trn_fit_height`.
 *
 * **Unavailable in Swift. Please use the property:**
 *
 * @see `pageRefViewMode`
 */
-(void)SetPageRefViewMode:(TrnPageViewMode)mode;

/**
 * Gets the reference page view mode. See more details about reference
 * page view mode in `-SetPageRefViewMode:`.
 *
 * @return the reference page view mode.
 *
 * **Unavailable in Swift. Please use the property:**
 *
 * @see `pageRefViewMode`
 */
-(TrnPageViewMode) GetPageRefViewMode;

/**
 * The current page presentation mode.
 */
@property (nonatomic, getter=GetPagePresentationMode, setter=SetPagePresentationMode:) TrnPagePresentationMode pagePresentationMode;

/**
 * Get the current page presentation mode.
 *
 * @return the current page presentation mode.
 *
 * **Unavailable in Swift. Please use the property:**
 *
 * @see `pagePresentationMode`
 */
-(TrnPagePresentationMode)GetPagePresentationMode;

/**
 * Sets the current page presentation mode.
 * The default PagePresentationMode is `e_trn_single_continuous`.
 *
 * @param mode the new page presentation mode.
 *
 * **Unavailable in Swift. Please use the property:**
 *
 * @see `pagePresentationMode`
 */
-(void)SetPagePresentationMode:(TrnPagePresentationMode)mode;

/**
 * Determine if the current page presentation mode is continuous
 *
 * @return true if the page presentation mode is continuous, false otherwise.
 */
-(BOOL)pagePresentationModeIsContinuous;

/**
 * The direction of paging for non-continuous page presentation modes.
 *
 * @note The default value of this property is `PTPDFViewCtrlPagingDirectionHorizontal`.
 */
@property (nonatomic, assign) PTPDFViewCtrlPagingDirection pagingDirection;

#pragma mark - Viewer Options

/** @name Viewer Options
 */

/**
 * Enables or disables URL extraction. By default URL extraction is disabled.
 *
 * @param enabled if true URL extraction is enabled, if false URL extraction is
 * disabled.
 *
 * @note If set to enabled when the document is already opened, it may not
 * find links on pages that were already rendered. It is suggested to
 * set this flag before opening the document.
 */
- (void)SetUrlExtraction:(BOOL)enabled;

/**
 * Enables or disables drawing of a thin border around each page.
 *
 * @param border_visible if true, the border will be visible.
 */
-(void)SetPageBorderVisibility:(BOOL)border_visible;

/**
 * Enables or disables the transparency grid (check board pattern) to reflect
 * page transparency.
 * @param trans_grid_visible if true, the grid is turned on.
 */
-(void)SetPageTransparencyGrid:(BOOL)trans_grid_visible;

/**
 * Sets the default 'paper' color used to draw the background of each page.
 *
 * @param r red RGB color component
 * @param g green RGB color component
 * @param b blue RGB color component
 */
-(void)SetDefaultPageColor:(unsigned char)r g:(unsigned char)g b:(unsigned char)b;

/**
 * Sets the default background color used to paint the area surrounding each page.
 *
 * @param r red RGBA color component
 * @param g green RGBA color component
 * @param b blue RGBA color component
 * @param a alpha RGBA color component
 */
-(void)SetBackgroundColor:(unsigned char)r g:(unsigned char)g b:(unsigned char)b a:(unsigned char)a;

/**
 * Sets the horizontal alignment used for rendering pages within the view.
 *
 * @param align an integer specifying the horizontal alignment. Depending
 * of whether align is positive, negative, or zero, pages will be right,
 * left, or center aligned:
 * `align<0`, pages are top aligned;
 * `align=0`, pages are centered;
 * `align>0`, pages are bottom aligned.
 */
-(void)SetHorizontalAlign: (int)align;

/**
 * Sets the vertical alignment used for rendering pages within the view.
 *
 * @param align an integer specifying the vertical alignment. Depending
 * of whether align is positive, negative, or zero, pages will be bottom,
 * top, or center aligned:
 * `align<0`, pages are top aligned;
 * `align=0`, pages are centered;
 * `align>0`, pages are bottom aligned.
 */
-(void)SetVerticalAlign: (int)align;

/**
 * Sets the vertical and horizontal padding and column spacing between adjacent pages in the view.
 *
 * @param horiz_col_space horizontal column spacing (represented in pixels) between
 * adjacent pages in the view. Default is 10.
 * @param vert_col_space vertical column spacing (represented in pixels) between adjacent
 * pages in the view. Default is 10.
 * @param horiz_pad horizontal padding (represented in pixels) on the left and right side
 * of the view. Default is 10.
 * @param vert_pad vertical padding (represented in pixels) on the top and bottom side
 * of the view. Default is 10.
 */
-(void)SetPageSpacing: (int)horiz_col_space vert_col_space:  (int)vert_col_space horiz_pad:  (int)horiz_pad vert_pad:  (int)vert_pad;

/**
 * Rotates all pages in the document 90 degrees clockwise.
 */
-(void)RotateClockwise;

/**
 * Rotates all pages in the document 90 degrees counter-clockwise.
 */
-(void)RotateCounterClockwise;

/**
 * The current rotation applied to all pages in PTPDFViewCtrl.
 *
 * Rotation can be applied to all pages using `-RotateClockwise` and `-RotateCounterClockwise`.
 */
@property (nonatomic, readonly, getter=GetRotation) PTRotate rotation;

/**
 * Get the current rotation applied to all pages in PTPDFViewCtrl.
 *
 * @return The current rotation applied to all pages in PTPDFViewCtrl.
 *
 * **Unavailable in Swift. Please use the property:**
 *
 * @see `rotation`
 */
-(PTRotate)GetRotation;

/**
 * The color post processing transformation.
 * This transform is applied to the rasterized bitmap as the final step
 * in the rasterization process, and is applied directly to the resulting
 * bitmap (disregarding any color space information). Color post
 * processing is only supported for RGBA output.
 *
 * @note When setting this property to `e_ptpostprocess_gradient_map`,
 * the colors used for gradient map should also be set using
 * `-SetColorPostProcessColors:black_color:`.
 */
@property (nonatomic, getter=GetColorPostProcessMode, setter=SetColorPostProcessMode:) PTColorPostProcessMode colorPostProcessMode;

/**
 * Get the current color post processing mode.
 *
 * @return the current color post processing mode.
 *
 * **Unavailable in Swift. Please use the property:**
 *
 * @see `colorPostProcessMode`
 */
-(PTColorPostProcessMode)GetColorPostProcessMode;

/**
 * Set the color post processing transformation.
 * This transform is applied to the rasterized bitmap as the final step
 * in the rasterization process, and is applied directly to the resulting
 * bitmap (disregarding any color space information). Color post
 * processing is only supported for RGBA output.
 *
 * @param mode the specific transform to be applied
 *
 * **Unavailable in Swift. Please use the property:**
 *
 * @see `colorPostProcessMode`
 */
-(void)SetColorPostProcessMode:(PTColorPostProcessMode)mode;


/**
*
* Sets the color post processing transformation. This transform is applied
* to the rasterized bitmap as the final step in the rasterization process,
* and is applied directly to the resulting bitmap (disregarding any color
* space information). Color post processing only supported for RGBA output.
*
* This mode will map the brightness of the original rasterized bitmap to a
* gradient in image_file_contents from left to right.
*
* @param image_file_contents A filter with image file contents.
*
*/
- (void)SetColorPostProcessMapFile: (PTFilter*)image_file_contents;

/**
 * Sets the color post processing transformation. This transform is
 * applied to the rasterized bitmap as the final step in the rasterization
 * process, and is applied directly to the resulting bitmap (disregarding
 * any color space information). Color post processing only supported for
 * RGBA output. This mode will map the brightness of the original
 * rasterized bitmap to a gradient between whiteColor and blackColor
 *
 * @param white_color The white color of the page.
 *
 * @param black_color The black color of the page.
 */
-(void)SetColorPostProcessColors:(UIColor*)white_color black_color:(UIColor*)black_color;

/**
 * Converts a color based on the view's color post processing transformation.
 *
 * @param color the color to be converted
 *
 * @return the post-processed color
 */
-(PTColorPt*)GetPostProcessedColor:(PTColorPt*)color;


#pragma mark - Rendering Options

/** @name Rendering Options
 */

/**
 * Sets whether the control will render progressively or will just
 * draw once the entire view has been rendered.
 *
 * @param progressive if true the view will be rendered progressively
 *
 * @param delayMilliseconds delay before the progressive rendering timer is started.
 *
 * @param intervalMilliseconds delay between refreshes. Default is 750 ms.
 *
 * @note Progressive rendering is useful when a PDF page contain lots of elements
 * (e.g. many vector paths, text, or many little images). When progressive rendering
 * is enabled PDFNet will use painter algorithm to draw the page. This way user may
 * be able to see partially rendered page. If a page contains only a single large
 * image, there would be no visible benefit from progressive rendering.
 */
-(void)SetProgressiveRendering:(BOOL)progressive withInitialDelay:(int)delayMilliseconds withInterval:(int)intervalMilliseconds;


/**
 * Enable or disable path hinting.
 *
 * Path hinting is used to slightly adjust paths in order to avoid or
 * alleviate artifacts of hair line cracks between certain graphical elements.
 *
 * This option is enabled by default.
 *
 * @param enabled if YES path hinting is enabled.
 */
-(void)SetPathHinting:(BOOL)enabled;

/**
 * Enable or disable anti-aliasing.
 *
 * Anti-Aliasing is a technique used to improve the visual
 * quality of images when displaying them on low resolution
 * devices (for example, low DPI computer monitors).
 *
 * Anti-aliasing is enabled by default.
 */
-(void)SetAntiAliasing:(bool)enabled;

/**
 * Set thin line adjustment parameters.
 *
 * @param pixel_grid if true (horizontal/vertical) thin lines will be snapped to
 * integer pixel positions. This helps make thin lines look sharper and clearer. This
 * option is turned off by default.
 *
 * @param stroke_adjust if true auto stroke adjustment is enabled. Currently, this would
 * make lines with sub-pixel width to be one-pixel wide. This option is turned on by default.
 */
-(void)SetThinLineAdjustment:(bool)pixel_grid StrokeAdjust:(bool)stroke_adjust;

/**
 * Enable or disable image smoothing.
 *
 * The rasterizer allows a trade-off between rendering quality and rendering speed.
 * This function can be used to indicate the preference between rendering speed and quality.
 *
 * @note The image smoothing option has effect only if the source image has higher resolution
 * that the output resolution of the image on the rasterized page. PDFNet automatically
 * controls at what resolution/zoom factor, 'image smoothing' needs to take effect.
 *
 * Image smoothing is enabled by default.
 *
 * @param enabled True to enable image smoothing, false otherwise.
 */
-(void)SetImageSmoothing:(bool)enabled;

/**
 * Sets the gamma factor used for anti-aliased rendering.
 *
 * Gamma correction can be used to improve the quality of anti-aliased
 * image output and can (to some extent) decrease the appearance of common
 * anti-aliasing artifacts (such as pixel width lines between polygons).
 *
 * @note Gamma correction is used only in the built-in rasterizer.
 *
 * @param exp the exponent value of the gamma function. Typical values
 * are in the range from 0.1 to 3.
 */
-(void)SetGamma:(double)exp;

/**
 * Enable or disable annotation and forms rendering. By default, all annotations
 * and form fields are rendered.
 *
 * @param render_annots True to draw annotations, false otherwise.
 */
-(void)SetDrawAnnotations:(BOOL)render_annots;

/**
 * Enable or disable highlighting form fields. Default is disabled.
 *
 * @param highlight_fields YES to highlight, NO otherwise.
 */
-(void)SetHighlightFields:(BOOL)highlight_fields;

/**
 * Set the highlight color for fields.
 *
 * This option only has an effect if field highlighting is turned on using `-SetHighlightFields:`.
 *
 * @param highlightColor The new highlight color.
 *
 * @note Signature fields have their own highlight color, independent of this one (see `-SetSignatureHighlightColor:`).
 */
- (void)SetFieldHighlightColor:(UIColor *)highlightColor;

/**
 * Set the border color for required fields.
 *
 * This option only has an effect if field highlighting is turned on using `-SetHighlightFields:`.
 *
 * @param borderColor The new border color.
 */
- (void)SetRequiredFieldBorderColor:(UIColor *)borderColor;

/**
 * Set the highlight color for signature fields.
 *
 * This option only has an effect if field highlighting is turned on using `-SetHighlightFields:`.
 *
 * @note Non-signature fields have their own highlight color, independent of this one (see `-SetFieldHighlightColor:`).
 *
 * @param highlightColor The new signature highlight color.
 */
- (void)SetSignatureHighlightColor:(UIColor *)highlightColor;

/**
 * Enable or disable support for overprint and overprint simulation.
 * Overprint is a device dependent feature and the results will vary depending on
 * the output color space and supported colorants (i.e. CMYK, CMYK+spot, RGB, etc).
 *
 * By default overprint is only enabled for PDF/X files.
 *
 * @param op
 *      `e_ptop_on`: always enabled;
 *      `e_ptop_off`: always disabled;
 *      `e_ptop_pdfx_on`: enabled for PDF/X files only.
 */
-(void)SetOverprint: (PTOverprintPreviewMode)op;

/**
 * Sets the Optional Content Group (OCG) context that should be used when
 * viewing the document. This function can be used to change the current
 * OCG context. Optional content (such as PDF layers) will be selectively
 * rendered based on the states of optional content groups in the given
 * context.
 *
 * @param ctx Optional Content Group (OCG) context, or `nil` if the rasterizer
 * should render all content on the page.
 *
 * @note Unlike `-[PTPDFDraw SetOCGContext:]` this method copies the given context.
 * As a result, in order to modify the state of OCG groups in the current
 * context use `-GetOCGContext` to obtain the currently selected content
 * and then modify states.
 */
-(void)SetOCGContext: (PTContext*)ctx;

/**
 * Get the Optional Content Group (OCG) context associated with this
 * PTPDFViewCtrl.
 *
 * @return the Optional Content Group (OCG) context associated with this
 * PTPDFViewCtrl, or `nil` (i.e. `-[PTContext IsValid]` is `NO`) if there is no OCG
 * context associated with the view. If there is an OCG context associated with the
 * view, optional content (such as PDF layers) will be selectively rendered
 * based on the states of optional content groups in the given context.
 *
 * @see `OCGContext`
 */
-(nullable PTContext*)GetOCGContext;

/**
 * Prompts the PDFViewCtrl to update its list of optional content groups.
 * Call this method if you modify the PDFDoc in a way that adds or removes
 * a layer. For example, after using Stamper to create a stamp.
 */
- (void)UpdateOCGContext;

/**
 * Disable rendering of a particular annotation. This does not change the
 * annotation itself, just how it is displayed in this viewer instance.
 *
 * @param annot The annotation object to cease drawing for.
 */
- (void)HideAnnotation:(PTAnnot *)annot;

/**
 * Enable rendering of a particular annotation. Only has an effect if
 * `-HideAnnotation:` has previously been called on the same annot.
 *
 * @param annot The annotation object to resume rendering.
 */
- (void)ShowAnnotation:(PTAnnot *)annot;

#pragma mark - Text Search

/** @name Text Search
 */

/**
 * Selects text by searching for a given string of text.
 *
 * @param searchString The text to search for
 * @param matchCase Indicates if it is case sensitive
 * @param matchWholeWord Indicates if it matches an entire word only
 * @param searchUp If it searches upward
 * @param regExp Indicates if it uses regular expressions.
 *
 * @note This function runs in asynchronous mode: it launches a search thread and returns immediately.
 * If a matched string is found, the corresponding text is highlighted; otherwise, a message box is
 * shown. Users can use SetCustomEventHandlers() to set a TextFindDoneHandler to customize a different
 * behavior.
 */
-(BOOL)FindText:(NSString*)searchString MatchCase:(BOOL)matchCase MatchWholeWord:(BOOL)matchWholeWord SearchUp:(BOOL)searchUp RegExp:(BOOL)regExp;

/**
 * Cancel the text search thread if `-FindText:MatchCase:MatchWholeWord:SearchUp:RegExp:`
 * is started in a different thread.
 *
 * @note If the text search thread is currently being suspended by the render thread,
 * it will only be canceled after it is awaken by the render thread.
 */
-(void)CancelFindText;

#pragma mark - Text Selection

/** @name Text Selection
 */

/**
 * Sets the selection mode used for text highlighting.
 * @param tm the text selection mode.
 */
-(void)SetTextSelectionMode: (PTTextSelectionMode)tm;

/**
 * Places a rectangle over text that has been selected.
 *
 * @param selection A selection object.
 *
 * @param color The color of the drawn rectangle. Set the alpha value to less than 1.0 to give transparency.
 */
-(void)highlightSelection:(PTSelection*)selection withColor:(UIColor*)color;

/**
 * Places a rectangle over text that has been selected.
 *
 * @param selections An array of PTSelection objects.
 *
 * @param color The color of the drawn rectangle. Set the alpha value to less than 1.0 to give transparency.
 */
-(void)highlightSelections:(NSArray<PTSelection*>*)selections withColor:(UIColor*)color;

/**
 * Clears the rectangle drawn by `highlightSelection:withColor:`.
 */
-(void)hideSelectedTextHighlights;

/**
 * Checks if there is any text selection.
 *
 * @return return true if there is selection, false otherwise.
 */
-(BOOL)HasSelection;

/**
 * Remove any text selection.
 */
-(void)ClearSelection;

/**
 * Get the text selection for a given page.
 *
 * @return the current text selection for a given page.
 * If there is only selection on one page, then page number
 * does not need to be provided.
 */
-(nullable PTSelection*)GetSelection: (int)pagenum;

/**
 * The first page number that has text selection on it.
 * Useful when there are selections on multiple pages at the same time.
 */
@property (nonatomic, readonly, getter=GetSelectionBeginPage) int selectionBeginPage;

/**
 * Get the first page number that has text selection on it.
 * Useful when there are selections on multiple pages at the same time.
 *
 * @return the first page number that has text selection on it.
 *
 * **Unavailable in Swift. Please use the property:**
 *
 * @see `selectionBeginPage`
 */
-(int)GetSelectionBeginPage;

/**
 * The last page number that has text selection on it.
 * Useful when there are selections on multiple pages at the same time.
 */
@property (nonatomic, readonly, getter=GetSelectionEndPage) int selectionEndPage;

/**
 * Get the last page number that has text selection on it.
 * Useful when there are selections on multiple pages at the same time.
 *
 * @return the last page number that has text selection on it.
 *
 * **Unavailable in Swift. Please use the property:**
 *
 * @see `selectionEndPage`
 */
-(int)GetSelectionEndPage;

/**
 * Checks if there is any text selection on a given page.
 * Useful when there are selections on multiple pages at the same time.
 *
 * @return returns true if given page number has any text selection on it.
 */
-(BOOL)HasSelectionOnPage: (int)ipage;

/**
 * Selects text within the given region using the current text selection mode. (x1, y1) and (x2, y2)
 * are two points (screen coordinates, origin located at the upper-left corner of this view)
 * defining the opposite corners of a selection rectangle.
 *
 * @return true if some text was selected, false otherwise.
 */
-(BOOL)SelectX1:(double)x1 Y1:(double)y1 X2:(double)x2 Y2:(double)y2;

/**
 * Selects text using structural mode. Point (x1, y1) is the start selection point (in page coordinates space)
 * on page `pageNumber1` and point (x2, y2) is the end selection point on page `pageNumber2`.
 *
 * @return true if some text were selected, false otherwise.
 */
-(BOOL)SelectX1:(double)x1 Y1:(double)y1 PageNumber1:(int)pageNumber1 X2:(double)x2 Y2:(double)y2 PageNumber2:(int)pageNumber2;

/**
 * Selects text identified by Highlights.
 *
 * @return true if some text was selected, false otherwise.
 * @param highlights an instance of the Highlights class.
 */
-(BOOL)SelectWithHighlights: (PTHighlights*)highlights;

/**
 * Selects text identified by Selection.
 *
 * @return true if some text was selected, false otherwise.
 * @param select an instance of the Selection class.
 */
-(BOOL)SelectWithSelection: (PTSelection*)select;

/**
 * Selects all text on the page.
 */
-(void)SelectAll;

/**
* Requests for preparing words of the given page.
* Note: Words are going to be prepared asynchronously
*
* @param page_num - page number
*/
- (void)PrepareWords: (int)page_num;

/**
* @return true if words of the given page has been prepared, false otherwise
* @param page_num - page number
*/
- (BOOL)WereWordsPrepared: (int)page_num;


/**
* @return true if there is a text in the given rectangle, false otherwise
* and point (x2, y2) is the end selection point. The points are defined in screen space.
*/
- (BOOL)IsThereTextInRect: (double)x1 y1:(double)y1 x2:(double)x2 y2:(double)y2;

/**
* Requests for preparing annotations of the given page.
* Note: Annotations are going to be prepared asynchronously
*
* @param page_num - page number
* @param distance_threshold - Maximum distance from the point (x, y) to the annotation for the annot to be considered a hit.
* @param minimum_line_weight - For very thin lines, it is almost impossible to hit the actual line.
* This specifies a minimum line thickness (in screen coordinates) for the purpose of calculating whether
* a point is inside the annotation or not
*/
- (void)PrepareAnnotsForMouse: (int)page_num distance_threshold:(double)distance_threshold minimum_line_weight:  (double)minimum_line_weight;

/**
* @return true if annotations of the given page have been prepared, false otherwise
* @param page_num - page number
*/
- (BOOL)WereAnnotsForMousePrepared: (int)page_num;

/**
* @return annotation type at the given point
* @param x - x coordinate of the input point
* @param y - y coordinate in the input point
*/
- (PTAnnotType)GetAnnotTypeUnder: (double)x y:(double)y;

#pragma mark - Add UIViews to a PDF page

/**
 *
 * Adds a UIView that will "stick" to a PDF page. The frame of the UIView is assumed to be in the PDFViewCtrl's
 * coordinate system, and the view will "stick" to page over which it is positioned.
 *
 * @param view The view to "stick" to a PDF page.
 *
 */
-(void)addFloatingView:(UIView*)view;


/**
 *
 * Adds a UIView that will "stick" to the specified PDF page with the specified rect.
 *
 * @param view The view to add to the page.
 *
 * @param pageNumber The sequence number of the page to add the view to.
 *
 * @param pageSpaceRect The rectangle, in PDF coordinates, to add the page to.
 *
 * @param noZoom If true, the view will be scaled to the screen size which corresponds to the PDF being viewed at 100%,
 * regardless of the actual viewer zoom level. If false, the view will scale with the other elements on the PDF page.
 *
 */
-(void)addFloatingView:(UIView*)view toPage:(int)pageNumber withPageRect:(PTPDFRect*)pageSpaceRect noZoom:(BOOL)noZoom;


/**
 *
 * Adds a view that will "stick" to the specified page at the specified point. The size of the view is determined by
 * the input view's `frame.size`, and is maintained regardless of the viewer's zoom level.
 *
 * @param view The view to add to the page.
 *
 * @param pageNumber The sequence number of the page to add the view to.
 *
 * @param pageSpacePoint The point, in PDF coordinates, to add the view to.
 *
 */
-(void)addFloatingView:(UIView*)view toPage:(int)pageNumber atPagePoint:(PTPDFPoint*)pageSpacePoint;


/**
 * Removes all views added via a `-addFloatingView:` method.
 */
-(void)clearFloatingViews;

/**
 * Removes the specified view that was added via a `-addFloatingView:` method.
 *
 * @param view The view to remove.
 */
-(void)removeFloatingView:(UIView*)view;


/**
 * Removes views that were added via a `-addFloatingView:` method.
 *
 * @param views An array of views to remove.
 */
-(void)removeFloatingViews:(NSArray<UIView*>*)views;

/**
  * Repositions the floating views that were added via a `-addFloatingView:` method.
 */
-(void)repositionFloatingViews;

/**
 * Returns an array of views added via a `-addFloatingView` method on the specified page.
 *
 * @param pageNumber The page from which to return views that were added with an `-addFloatingView` method.
 */
-(NSArray<UIView*>*)floatingViewsOnPage:(int)pageNumber;

/**
 * This method is unlikley to be needed for most use cases, as explained below.
 *
 * The control's floating views are associated with each page via its PDF "object number".
 * During most document opertions (editing annotations, re-ordering pages, deleting pages, adding new pages), page PDF
 * object numbers do not change. However if saving with the `e_ptlinearized` flag, or if using low-level APIs to
 * purposefully change object numbers, this method must be called to ensure that each floating view is associated with
 * the correct page.
 *
 */
-(void)clearFloatingViewPageCache;

#pragma mark - User Interaction Queries

/** @name User Interaction Queries
 */

/**
 * Returns the annotation bounding box present at the specified page number.
 *
 * @param annot The target annotation
 * @param page_num The page number of the page where the annotation is on
 *
 * @return the annotation bounding box in screen points
 */
- (nullable PTPDFRect*)GetScreenRectForAnnot:(PTAnnot*)annot page_num:(int)page_num;

/**
 * Returns the annotation present at screen coordinates (x, y). If no annotation is present,
 * callling IsValid on the returned annotation will return false.
 * You must acquire a read lock for the doc when retrieving an annotation.
 *
 * @param x The x location in screen coordinates
 * @param y The y location in screen coordinates
 * @param distanceThreshold Maximum distance from the point (x, y) to the annotation for the annot to be considered a hit.
 * The value used in versions of the SDK prior to 6.3 was 22.
 * @param minimumLineWeight For very thin lines, it is almost impossible to hit the actual line. 
 * This specifies a minimum line thickness (in screen coordinates) for the purpose of calculating whether a point is inside the annotation or not. 
 * The value used in versions of the SDK prior to 6.3 was 10.
 * @return the annotation at (x, y). If there is no annotation at (x, y), the returned annotation's IsValid method will return false.
 */
- (nullable PTAnnot*)GetAnnotationAt:(int)x y:(int)y distanceThreshold:(double)distanceThreshold minimumLineWeight:(double)minimumLineWeight;

/**
 * Returns an array of annotations under the line (x1, y1, x2, y2) expressed in screen coordinates.
 * Does not include form field annotations.
 *
 * @param x1 The x-coordinate of the first point of the line.
 * @param y1 The y-coordinate of the first point of the line.
 * @param x2 The x-coordinate of the second point of the line.
 * @param y2 The y-coordinate of the second point of the line.
 *
 * @returns An array of annotations under the line (x1, y1, x2, y2) expressed in screen coordinates.
 *
 */
- (NSArray<PTAnnot*>*)GetAnnotationListAt:(int)x1 y1:(int)y1 x2:(int)x2 y2:(int)y2;


/**
 *
 * Returns an array of all of the annotations on a given page.
 *
 * @param page_num The number of the PDF page on which to look for annotaitons.
 *
 * @return An array of annotations that are on the page.
 *
 */
- (NSArray<PTAnnot *> *)GetAnnotationsOnPage: (int)page_num;


/**
 * Set device DPI, and scale factor. This affects the rendering of certain content, such as annotations with the no_zoom flag.
 *
 * @param dpi Scale relative to the internal DPI of 96 (default 1.0).
 * @param scale_factor Some DPI sensitive content, sush as annotations, can be scaled up, to make the content larger, which can make user interaction easier (default 1.0).
 */
- (void)SetDevicePixelDensity:(double) dpi scale_factor:(double)scale_factor;

/**
 * Returns the annotation present at screen coordinates (x, y). If no link is present,
 * callling length on the string returned by getUrl of the returned LinkInfo object will be <= 0.
 * You must acquire a read lock for doc when retrieving a LinkInfo object.
 *
 * @param x The x location in screen coordinates
 * @param y The y location in screen coordinates
 *
 * @return link information for a link present at screen coordinates (x, y).
 */
-(nullable PTLinkInfo*)GetLinkAt:(int)x y:(int)y;

/**
 *
 * Enables or disables requiring two fingers to scroll the viewer.
 *
 * @param enabled To require two fingers to scroll send YES; otherwise NO.
 *
 */
-(void)setMinimumTwoFingersToScrollEnabled:(bool)enabled;

#pragma mark - Gesture Recognizer Targets

/** @name Gesture Recognizer Targets
 */

// These methods are called in response to gesture recognizers and are
// included in the header file so that subclasses may extend or override the functionality.

/**
 * Called in response to a single tap gesture and is
 * included here so that subclasses may extend or override the functionality.
 *
 * @param gestureRecognizer The gesture recognizer that trigger the callback.
 */
-(void)handleTap:(UITapGestureRecognizer *)gestureRecognizer;

/**
 * Called in response to a long press gesture and is
 * included here so that subclasses may extend or override the functionality.
 *
 * @param gestureRecognizer The gesture recognizer that trigger the callback.
 */
-(void)handleLongPress:(UILongPressGestureRecognizer*)gestureRecognizer;

#pragma mark - Document Locking/Unlocking

/** @name Document Locking/Unlocking
 */

// Write Locks

/**
 * Acquires a write lock for PTPDFDoc instance used by PTPDFViewCtrl.
 * Simultaneous write access to a PTPDFDoc instance is not allowed.
 * A write lock cannot be acquired if the thread already holds a read lock.
 * Attempting to do so will throw an exception.
 * 
 * @param cancelThreads 
 *            If true, other threads accessing the document are terminated before
 *            trying to lock the document. This ensures a quick return from this
 *            function. Otherwise, this function can halt the UI and the app
 *            may be unresponsive before the other thread finishes. If
 *            the rendering thread is canceled, unlocking the document
 *            UnlockDoc will restart the rendering thread.
 */
-(void)DocLock:(BOOL)cancelThreads;

/**
 * Tries to acquire a write lock on the PTPDFDoc instance used by PTPDFViewCtrl.
 * Returns true if it succeeds and false otherwise.
 *
 * @param milliseconds time that the selector will block while trying to aquire 
 * the lock before returning.
 *
 * @return true if the lock was aquired, false otherwise. 
 */
-(BOOL)DocTryLock:(int)milliseconds;

/**
 * Releases a write lock on the PTPDFDoc instance used by PTPDFViewCtrl and restarts the
 * rendering thread if it was canceled.
 */
-(void)DocUnlock;

// Read Locks

/**
 * Acquires a read lock for PTPDFDoc instance used by PTPDFViewCtrl.
 */
-(void)DocLockRead;

/**
 * Tries to acquire read lock on the PTPDFDoc instance used by PTPDFViewCtrl.
 * Returns true if it succeeds and false otherwise.
 *
 * @param milliseconds time that the selector will block while trying to aquire
 * the lock before returning.
 *
 * @return true if the lock was aquired, false otherwise.
 */
-(BOOL)DocTryLockRead:(int)milliseconds;

/**
 * Releases a read lock on the PTPDFDoc instance used by PTPDFViewCtrl.
 */
-(void)DocUnlockRead;

/**
 * Sets the minimum and maximum zoom bounds of PTPDFViewCtrl.
 *
 * @param mode defines how the zoom bounds are to be used
 *
 * @param min the minimum zoom bound
 *
 * @param max the maximum zoom bound
 *
 * @note if the zoom limits are relative, 1.0 is defined as the zoom level
 * where the document is displayed in page fit mode, where the entire page
 * is visible on screen.
 */
-(void)SetZoomLimits:(TrnZoomLimitMode)mode Minimum:(double)min Maxiumum:(double)max;

/**
 * Gets the zoom limit mode of the PTPDFViewCtrl.
 *
 * @see `zoomLimitMode`
 */
-(TrnZoomLimitMode)GetZoomLimitMode;

/**
 * Gets the minimum zoom bound of the PTPDFViewCtrl.
 *
 * @see `zoomMinimumLimit`
 */
-(double)GetZoomMinimumLimit;

/**
 * Gets the maximum zoom bound of the PTPDFViewCtrl.
 *
 * @see `zoomMaximumLimit`
 */
-(double)GetZoomMaximumLimit;

#pragma mark - Coordinate Coversion

/** @name Coordinate Coversion
 */

/**
 * @return  the number of the page located under the given screen 
 * coordinate. The positive number indicates a valid page, whereas 
 * number less than 1 means that no page was found. 
 */
-(int)GetPageNumberFromScreenPt:(double)x y:(double)y;

/**
 * Converts a point expressed in screen coordinates to a point on canvas.
 */
-(PTPDFPoint*)ConvScreenPtToCanvasPt:(PTPDFPoint*)pt;

/**
 * Converts a point expressed in canvas coordinates to a point on screen.
 */
-(PTPDFPoint*)ConvCanvasPtToScreenPt:(PTPDFPoint*)pt;

/**
 * Converts a point expressed in canvas coordinates to a point on a given page.
 * 
 * @param page_num the page number for the page used as the origin of the destination 
 * coordinate system. Negative values are used to represent the current page.
 * Pages are indexed starting from one.
 */
-(PTPDFPoint*)ConvCanvasPtToPagePt:(PTPDFPoint*)pt page_num:(int)page_num;

/**
 * Converts a point from a coordinate system of a given page to a point on canvas.
 * 
 * @param page_num the page number for the page used as the origin of the destination 
 * coordinate system. Negative values are used to represent the current page.
 * Pages are indexed starting from one.
 */
-(PTPDFPoint*)ConvPagePtToCanvasPt:(PTPDFPoint*)pt page_num:(int)page_num;

/**
 * Converts a point expressed in screen coordinates to a point on a given page.
 * 
 * @param page_num the page number for the page used as the origin of the destination 
 * coordinate system. Negative values are used to represent the current page.
 * Pages are indexed starting from one.
 */
-(PTPDFPoint*)ConvScreenPtToPagePt:(PTPDFPoint*)pt page_num:(int)page_num;

/**
 * Converts a point from a coordinate system of a given page to a point on screen.
 * If PDFView is in a non-continous page view mode, and the page is not visible,
 * the result is undefined.
 * 
 * @param page_num the page number for the page used as the origin of the destination 
 * coordinate system. Negative values are used to represent the current page.
 * Pages are indexed starting from one.
 */
-(PTPDFPoint*)ConvPagePtToScreenPt:(PTPDFPoint*)pt page_num:(int)page_num;

/**
 * Converts a `PTPDFRect` in PDF page coordinates to a `CGRect` in screen
 * (`PTPDFViewCtrl`) coordinates.
 *
 * @param pdfRect The rectangle in PDF coordinates
 *
 * @param pageNumber The page number that the rectangle is on.
 *
 * @returns The equivalent rectangle, in screen coordinates.
 */
-(CGRect)PDFRectPage2CGRectScreen:(PTPDFRect*)pdfRect PageNumber:(int)pageNumber;


/**
 * Converts a `CGRect` in screen (`PTPDFViewCtrl`) coordinates to a `PTPDFRect`
 * in PDF page coordinates.
 *
 * @param cgRect The rectangle in screen coordinates
 *
 * @param pageNumber The page number for which the returned coordinates should reference
 *
 * @returns The equivalent rectangle, in page coordinates.
 */
-(PTPDFRect*)CGRectScreen2PDFRectPage:(CGRect)cgRect PageNumber:(int)pageNumber;

/**
 * Snaps a point (in screen space) to the nearest piece of
 * document geometry.
 * @param screen_pt the point to snap.
 *
 * @returns The nearest point in document geometry.
 */
-(PTPDFPoint*)SnapToNearestInDoc:(PTPDFPoint*)screen_pt;

/**
 * Set the point snapping mode for the `-SnapToNearestInDoc:` method.
 *
 * By default `-SnapToNearestInDoc:` will snap to line endpoints, midpoints, and intersections
 * (ie. the `e_ptDefaultSnapMode` snapping mode).
 *
 * @param mode_flags a bitwise combination of the members of `PTGeometryCollectionSnappingMode`
 */
-(void)SetSnappingMode:(unsigned int)mode_flags;

/**
 * @return the device transformation matrix. The device transformation 
 * matrix maps the page coordinate system to screen (or device) coordinate 
 * system.
 * 
 * @param page_num same as for PTPDFViewCtrl.Conv???() methods.
 *
 * @note to obtain a transformation matrix that maps screen 
 * coordinates to page coordinates, you can invert the device matrix. 
 * For example: 
 * @code
 *   Common::Matrix2D scr2page(pdfviewctrl.GetDeviceTransform());
 *   scr2page.Inverse();
 * @endcode 
 */
-(nullable PTMatrix2D*)GetDeviceTransform:(int)page_num;

#pragma mark - Viewer Dimensions

/** @name Viewer Dimensions
 */

/**
 * The current width of the canvas.
 * The canvas coordinate system is defined by a bounding box that surrounds all pages
 * in the view.
 */
@property (nonatomic, readonly, getter=GetCanvasWidth) double canvasWidth;

/**
 * Returns the current canvas width.
 *
 * **Unavailable in Swift. Please use the property:**
 *
 * @see `canvasWidth`
 */
-(double)GetCanvasWidth;

/**
 * The current height of the canvas.
 * The canvas coordinate system is defined by a bounding box that surrounds all pages
 * in the view.
 */
@property (nonatomic, readonly, getter=GetCanvasHeight) double canvasHeight;

/**
 * Returns the current canvas height.
 *
 * **Unavailable in Swift. Please use the property:**
 *
 * @see `canvasHeight`
 */
-(double)GetCanvasHeight;

#pragma mark - Rendering Starting/Stopping

/** @name Rendering Starting/Stopping
 */

/**
 *
 * @param visible_region_only Specifies if the method refers only to currently
 * visible content.
 *
 * @return true is the rendering thread finished rendering the view,
 * false if the rendering is still in progress.
 */
- (BOOL)IsFinishedRendering: (BOOL)visible_region_only;

/**
 * Cancels rendering in progress. If PTPDFViewCtrl is not busy rendering the page,
 * the function has no side effects.
 */
-(void)CancelRendering;

/**
 * Redraws the contents of the buffer.
 * Equivalent to Update:NO
 */
-(void)Update;

/**
 * Redraws the contents of the buffer.
 * @param all if true, all of the rendered content is discarded and re-rendered; otherwise, only the visible region
 * will be re-rendered.
 */
-(void)Update:(bool)all;

/**
 * Redraws the area covered with a given annotation.
 * @param annot The annotation to update.
 * @param page_num The page number on which the annotation is located.
 */
-(void)UpdateWithAnnot: (PTAnnot*)annot page_num: (int)page_num;

/**
 * Redraws the given area in the buffer.
 * @param update The rectangle to update expressed in screen coordinates.
 */
-(void)UpdateWithRect: (PTPDFRect*)update;

/**
 * Redraws the given area covered by the given field. Useful when a field is
 * connected to other fields.
 * @param field The field to update.
 */
-(void)UpdateWithField:(PTField*)field;

/**
 * Helper function that will refresh annotation and/or field appearances if needed, and then
 * render modified page areas, all based on the contents of the view_change parameter.
 *
 * @param view_change contains all the updated fields and rectangles.
 */
- (void)RefreshAndUpdate: (PTViewChangeCollection*)view_change;

/**
 * Renders content that requires rendering. May be called to resume rendering after CancelRendering.
 */
-(void)RequestRendering;

#pragma mark - Memory control

/** @name Memory control
 */

/**
 * Set the suggested memory size of the rendered content.
 *
 * PTPDFViewCtrl keeps off-screen content in order to achieve better viewing
 * experience; however, this increases memory usage. By default, PTPDFViewCtrl
 * will use 80% of available memory to render on-screen and off-screen content.
 * The value set here will be overidden if PurgeMemory is called.
 *
 * @param allowedMax the allowed heap memory usage in MB.
 *
 * @note <p>
 *       If you want to minimize memory usage at the cost of
 *       viewing experience quality, you can set `allowedMax` to 0 and
 *       PTPDFViewCtrl will not keep any off-screen content. Also note that
 *       this function only controls the memory used to store rendered content
 *       not the entire memory footprint of the control.
 *       </p>
 */
-(void)SetRenderedContentBufferSize:(long)allowedMax;

/**
 * Removes all non-visible portions of document to reduce memory consumption. This will
 * reset the value set via SetContentBufferSize back to the default of 80% of available
 * memory.
 *
 * Suggested use is in response to a low memory warning.
 * May slightly slow down the time to complete rendering.
 *
 */
-(void)PurgeMemory;

/**
 * Enables of disables caching of images, fonts, and other resources. Disabling caching
 * can lower memory requirements at the expense of rendering speed.
 *
 * @param enabled if true caching is enabled, if false caching is disabled.
 * @default by default caching is enabled
 */
-(void)SetCaching: (BOOL)enabled;


/**
 * Sets the cache parameters of the page cache on disk (which caches content streams and
 * mipmapped images) for this specific document.  These parameters will override the default cache
 * parameters.  Note that if this function is called after the document has been rasterized, it has no
 * effect.
 *
 * @param document The document whose settings will be modified
 * @param max_cache_size The maximum size, in bytes, of the entire document's page cache
 * @param on_disk Whether or not to store the cache on disk
 *
 */
+ (void)SetViewerCache: (PTSDFDoc*)document max_cache_size:  (unsigned long)max_cache_size  on_disk:  (BOOL)on_disk;

#pragma mark - Thumbnails

/** @name Thumbnails
 */

/**
 * Specify the different thumbnail settings for the viewer.
 *
 * @param use_embedded Enables or disables using thumbnails embedded in the PDF document as a preview of the rendered page.
 * @param generate_at_runtime Enables or disables generating thumbnails at runtime.
 * @param use_disk_cache Enables or disables caching thumbnails in a temporary disk file.
 * @param thumb_max_side_length The maximum size, in pixels, of a dimension of generated thumbnails.
 * @param max_abs_cache_size The absolute maximum size on disk, in bytes, for the temporary thumbnail cache.
 * @param max_perc_cache_size The maximum percentage of free disk space, in the range 0 - 1.0, that the cache can take up.
 */
- (void)SetupThumbnails: (BOOL)use_embedded generate_at_runtime:  (BOOL)generate_at_runtime use_disk_cache:  (BOOL)use_disk_cache thumb_max_side_length:  (int)thumb_max_side_length max_abs_cache_size:  (unsigned long)max_abs_cache_size max_perc_cache_size:  (double)max_perc_cache_size;

/**
 * Clears the thumbnail cache.
 */
- (void)ClearThumbCache;

/**
 * Requests a thumbnail from the document, which is returned in the delegate method GotThumbAsync:(int)page_num thumbImage:(UIImage*)image;
 *
 * If there is no document set on the control, it will throw an exception.
 */
-(void)GetThumbAsync:(int)page_num;

/**
 * Requests a thumbnail from the document, which is returned in the provided completion block.
 * If there is no document set on the control, this method will throw an exception.
 */
-(void)GetThumbAsync:(int)page_num completion:(void (^)(UIImage * _Nullable image))completion;

/**
 * Cancels all outstanding thumbnail requests queued by GetThumbAsync:
 */
- (void)CancelAllThumbRequests;

#pragma mark - Miscellaneous

/** @name Miscellaneous
 */

/**
 * The total number of pages in the document displayed by this PDFViewCtrl.
 *
 * If pages are added, moved, or removed from the current document then it is necessary to call the
 * `-UpdatePageLayout` method to synchronize the PDFViewCtrl's displayed pages with the document's.
 *
 * @see `-UpdatePageLayout`
 */
@property (nonatomic, readonly, getter=GetPageCount) int pageCount;

/**
 * @return the total number of pages in the document.
 *
 * **Unavailable in Swift. Please use the property:**
 *
 * @see `pageCount`
 */
-(int)GetPageCount;

/**
 * Updates the page layout within the view.
 *
 * This function must be called after the document page sequence is modified (such as when a page is
 * being added to or removed from the document) or after changes to page dimensions (e.g. after a page
 * is rotated or resized).
 */
-(void)UpdatePageLayout;

/**
 * Used to add extra vertical scroll space to the PDF scroll view (inner scroll view)
 * when the keyboard would otherwise block the bottom of the document when editing
 * interactive forms.
 */
-(void)setExtraVerticalContent:(int)points;

/**
 * Will cause PTPDFViewCtrl to scroll the content so that the onscreen keyboard does not hide the
 * content being edited. See FormFillTool.m in the standard libTools distribution for example usage.
 *
 * @param notification The notification object returned by a UIKeyboardWillShowNotification notification.
 * @param rect The rectangle, in screen coordinates, that the keyboard should not
 * overlap with.
 *
 */
-(void)keyboardWillShow:(NSNotification*)notification rectToNotOverlapWith:(CGRect)rect;

/**
 * Will cause PTPDFViewCtrl to scroll the content so that the onscreen keyboard does not hide the
 * content being edited. See FormFillTool.m in the standard libTools distribution for example usage.
 *
 * @param notification The notification object returned by a UIKeyboardWillShowNotification notification.
 * @param rect The rectangle, in screen coordinates, that the keyboard should not
 * overlap with.
 * @param topEdge The top screen coordinate above which the rectangle should not be scrolled under.
 *
 */
-(void)keyboardWillShow:(NSNotification*)notification rectToNotOverlapWith:(CGRect)rect topEdge:(CGFloat)topEdge;

/**
 * Will cause PTPDFViewCtrl to reset the scroll position after a call to keyboardWillShow:rectToNotOverlapWith.
 *
 * @param notification The notificaion object returned by a UIKeyboardWillHideNotification notification.
 *
 */
-(void)keyboardWillHide:(NSNotification*)notification;

/**
 * The zoomScale of PTPDFViewCtrl. This will return 1.0 except when the control is actively being scaled
 * for example by a pinch gesture. To get/set the zoom level of the displayed PDF, use GetZoom and SetZoom.
 *
 */
-(double)zoomScale;

/**
 * Requests action object to be executed by PTPDFViewCtrl. Action must belong to the document
 * currently displayed in PTPDFViewCtrl.
 *
 * @param action object that is to be executed.
 */
-(void)ExecuteAction: (PTAction*)action;

/**
 * Requests action object to be executed by PTPDFViewCtrl. Action must belong to the document
 * currently displayed in PTPDFViewCtrl.
 *
 * @param action_param Container for parameters used in handling various actions.
 */
-(void)ExecuteActionWithActionParameter: (PTActionParameter*)action_param;

/**
 * Sets if document is to be presented for a left-to-right or right-to-left language.
 * Default is left-to-right.
 *
 * @param isRightToLeft true if language is right-to-left; false otherwise.
 *
 */
-(void)SetRightToLeftLanguage:(BOOL)isRightToLeft;

/**
 * @return true if PTPDFViewCtrl is set to display a PDF with a right-to-left language; false otherwise.
 */
-(BOOL)GetRightToLeftLanguage;

/**
 * Gets the box used by `PDFViewCtrl` for displaying.
 */
- (PTBox)GetPageBox;

/**
 * Sets the box to display in the viewer.
 *
 * @param region the new `PTBox` to display.
 */
- (void)SetPageBox:(PTBox)region;

/**
 * Enable undo/redo in this PDFViewCtrl.
 */
- (void)EnableUndoRedo;

/**
 * Whether undo/redo is enabled in this PDFViewCtrl. The default value is `NO`.
 */
@property (nonatomic, readonly, assign, getter=isUndoRedoEnabled) BOOL undoRedoEnabled;

/**
 * Returns whether there is an undo state in the undo/redo chain.
 *
 * @return whether there is an undo state in the undo/redo chain
 */
- (BOOL)CanUndo;

/**
 * Returns whether there is a redo state in the undo/redo chain.
 *
 * @return whether there is a redo state in the undo/redo chain
 */
- (BOOL)CanRedo;

/**
 * Return to the previous state in the undo/redo chain. Returns any meta-data associated with that state.
 *
 * @return meta-data associated with the current state in the undo/redo chain after undoing one state.
 */
- (NSString *)Undo;

/**
 * Go to the next state in the undo/redo chain. Returns any meta-data associated with that state.
 *
 * @return meta-data associated with the current state in the undo/redo chain after redoing one state.
 */
- (NSString *)Redo;

/**
 * Returns whether the document has been modified since the last undo/redo snapshot was taken.
 *
 * @return true if the document was modified since the last snapshot, false otherwise.
 */
- (BOOL)HasChangesSinceSnapshot;

/**
 * Creates a new state at the top of the undo/redo chain by taking a snapshot.
 *
 * @param meta_info meta-data to be attached to this new state.
 */
- (void)TakeUndoSnapshot:(NSString *)meta_info;

/**
 * Returns any meta-data associated with the previous sate in the undo/redo chain.
 *
 * @return meta-data associated with the previous sate in the undo/redo chain.
 */
- (NSString *)GetNextUndoInfo;

/**
 * Returns any meta-data associated with the next sate in the undo/redo chain.
 *
 * @return meta-data associated with the next sate in the undo/redo chain.
 */
- (NSString *)GetNextRedoInfo;

/**
 * Restores the document to the state of the last undo/redo snapshot, if it has been modified
 * since.
 *
 * @see `-HasChangesSinceSnapshot`
 */
- (void)RevertChangesSinceSnapshot;

/**
 * Returns to the initial state in the undo/redo chain.
 */
- (void)RevertAllChanges;

/**
 * The `NSUndoManager` instance used by this PDFViewCtrl.
 *
 * When `-isUndoRedoEnabled` is `NO`, this property returns the default `UIResponder` value obtained
 * by walking up the responder chain to find the first `NSUndoManager`.
 *
 * When `-isUndoRedoEnabled` is `YES`, this property returns a local `NSUndoManager` instance.
 */
@property (nonatomic, readonly, strong, nullable) NSUndoManager *undoManager;

/**
 * The `PTExternalAnnotManager` that is created and returned by `-EnableAnnotationManager:`.
 *
 * For example usage, please see the `PTCollaborationManager` class in `Tools.framework`.
 */
@property (nonatomic, readonly, strong, nullable) PTExternalAnnotManager *externalAnnotManager;

/**
 * Enables the collaboration annotation manager. The `e_ptadmin_undo_own` mode is used by default.
 *
 * @param userID The name of the author to associate with new annotations.
 *
 * @return the `PTExternalAnnotManager` created for and associated with this `PTPDFViewCtrl`
 */
- (PTExternalAnnotManager *)EnableAnnotationManager:(NSString *)userID;

/**
 * Enables the collaboration annotation manager.
 *
 * @param userID The name of the author to associate with new annotations.
 *
 * @param mode The `PTExternalAnnotManagerMode` to use.
 *
 * @return the `PTExternalAnnotManager` created for and associated with this `PTPDFViewCtrl`
 */
- (PTExternalAnnotManager *)EnableAnnotationManager:(NSString *)userID mode:(PTExternalAnnotManagerMode)mode;


/**
 * The extra left (x) and top (y) scrollable area
 *
 * @returns The extra left (x) and top (y) scrollable area
 */
-(CGPoint)getInsetOffsets;

@property (nonatomic, assign) CGFloat additionalYOffset;

@end

#pragma mark - PTPDFViewCtrl Notifications

/**
 * Posted by a `PTPDFViewCtrl` instance before it sets the current document with the
 * `-[PTPDFViewCtrl SetDoc:]` method.
 *
 * The current document, which will be closed, can be retrieved with the `-[PTPDFViewCtrl GetDoc]`
 * method.
 *
 * The notification object is the `PTPDFViewCtrl` instance that posted the notification.
 * The `userInfo` dictionary contains an entry for the `PTPDFViewCtrlPDFDocUserInfoKey` key that
 * corresponds to the `PTPDFDoc` instance that will be set as the current document.
 */
PDFNET_EXTERN const NSNotificationName PTPDFViewCtrlWillSetDocNotification;

/**
 * Posted by a `PTPDFViewCtrl` instance after it sets the current document with the
 * `-[PTPDFViewCtrl SetDoc:]` method. The current document can be retrieved with the
 * `-[PTPDFViewCtrl GetDoc]` method.
 *
 * The notification object is the `PTPDFViewCtrl` instance that posted the notification.
 * The `userInfo` dictionary is empty.
 */
PDFNET_EXTERN const NSNotificationName PTPDFViewCtrlDidSetDocNotification;

/**
 * Posted when the `PTPDFViewCtrl`'s page number has changed.
 *
 * The notification object is the pdfViewCtrl that posted the notification. The `userInfo` dictionary
 * contains entries for the `PTPDFViewCtrlPreviousPageNumberUserInfoKey` and
 * `PTPDFViewCtrlCurrentPageNumberUserInfoKey` keys.
 */
PDFNET_EXTERN const NSNotificationName PTPDFViewCtrlPageDidChangeNotification;

/**
 * Posted when the `PTPDFViewCtrl` has closed the current document.
 *
 * The notification object is the pdfViewCtrl that posted the notification. The `userInfo` dictionary
 * is empty.
 */
PDFNET_EXTERN const NSNotificationName PTPDFViewCtrlDidCloseDocNotification;

/**
 * Posted when the `PTPDFViewCtrl` has streaming event notification. These are generated when
 * downloading a document via `-[PTPDFViewCtrl OpenURLAync:]`, and when opening a non-PDF document with
 * `-[PTPDFViewCtrl openUniversalDocumentWithConversion:]`.
 *
 * The notification object is the pdfViewCtrl that posted the notification. The `userInfo` dictionary
 * contains entries for the `PTPDFViewCtrlStreamingEventTypeUserInfoKey` and
 * `PTPDFViewCtrlPageNumberUserInfoKey` keys. The `PTPDFViewCtrlStreamingEventMessageUserInfoKey` key
 * is present when there is a streaming event message.
 */
PDFNET_EXTERN const NSNotificationName PTPDFViewCtrlStreamingEventNotification;

/**
 * Posted when the `PTPDFViewCtrl`'s color post process mode changes.
 *
 * The notification object is the pdfViewCtrl that posted the notification. The `userInfo` dictionary
 * contains an entry for the `PTPDFViewCtrlColorPostProcessModeUserInfoKey` key. It may also contain
 * entries for the `PTPDFViewCtrlWhiteColorUserInfoKey` and `PTPDFViewCtrlBlackColorUserInfoKey` keys
 * when the post-process colors are changed with the
 * `-[PTPDFViewCtrl SetColorPostProcessColors:black_color:]` method.
 */
PDFNET_EXTERN const NSNotificationName PTPDFViewCtrlColorPostProcessModeDidChangeNotification;

/**
 * Posted when the `PTPDFViewCtrl`'s page presentation mode changes.
 *
 * The notification object is the `PTPDFViewCtrl` that posted the notification. The `userInfo` dictionary
 * contains an entry for the `PTPDFViewCtrlPagePresentationModeUserInfoKey` key with the new page
 * presentation mode.
*/
PDFNET_EXTERN const NSNotificationName PTPDFViewCtrlPagePresentationModeDidChangeNotification;

/**
 * Posted when the `PTPDFViewCtrl` will execute an action with an action parameter.
 *
 * The notification object is the `PTPDFViewCtrl` that posted the notification. The `userInfo`
 * dictionary contains an entry for the `PTPDFViewCtrlActionParameterUserInfoKey` key with the
 * action parameter.
 */
PDFNET_EXTERN const NSNotificationName PTPDFViewCtrlWillExecuteActionNotification;

/**
 * Posted when the `PTPDFViewCtrl` has executed an action with an action parameter.
 *
 * The notification object is the `PTPDFViewCtrl` that posted the notification. The `userInfo`
 * dictionary contains an entry for the `PTPDFViewCtrlActionParameterUserInfoKey` key with the
 * action parameter.
 */
PDFNET_EXTERN const NSNotificationName PTPDFViewCtrlDidExecuteActionNotification;

#pragma mark User info keys

/**
 * The key for a `PTPDFDoc` object.
 */
PDFNET_EXTERN NSString * const PTPDFViewCtrlPDFDocUserInfoKey;

/**
 * The key for a `NSNumber` object containing an `int` page number.
 */
PDFNET_EXTERN NSString * const PTPDFViewCtrlPreviousPageNumberUserInfoKey;

/**
 * The key for a `NSNumber` object containing an `int` page number.
 */
PDFNET_EXTERN NSString * const PTPDFViewCtrlCurrentPageNumberUserInfoKey;

/**
 * The key for a `NSNumber` object containing an `int` page number.
 */
PDFNET_EXTERN NSString * const PTPDFViewCtrlPageNumberUserInfoKey;

/**
 * The key for a `NSNumber` object containing a PTDownloadedType.
 */
PDFNET_EXTERN NSString * const PTPDFViewCtrlStreamingEventTypeUserInfoKey;

/**
 * The key for a `NSString` object containing the message for a streaming event.
 */
PDFNET_EXTERN NSString * const PTPDFViewCtrlStreamingEventMessageUserInfoKey;

/**
 * The key for a `NSNumber` object containing a PTColorPostProcessMode.
 */
PDFNET_EXTERN NSString * const PTPDFViewCtrlColorPostProcessModeUserInfoKey;

/**
 * The key for a `UIColor` object containing the color that black is mapped to.
 */
PDFNET_EXTERN NSString * const PTPDFViewCtrlBlackColorUserInfoKey;

/**
 * The key for a `UIColor` object containing the color that white is mapped to.
 */
PDFNET_EXTERN NSString * const PTPDFViewCtrlWhiteColorUserInfoKey;

/**
 * The key for a `NSNumber` object containing a `TrnPagePresentationMode`.
 */
PDFNET_EXTERN NSString * const PTPDFViewCtrlPagePresentationModeUserInfoKey;

/**
 * The key for a `PTActionParameter` object.
 */
PDFNET_EXTERN NSString * const PTPDFViewCtrlActionParameterUserInfoKey;

#pragma mark - PTPDFViewCtrlDelegate Protocol

/**
 * The methods declared by the PTPDFViewCtrlDelegate protocol allow the adopting delegate to respond to messages from
 * the PTPDFViewCtrl class.
 *
 */
PDFNET_OBJC_RUNTIME_NAME(PTPDFViewCtrlDelegate)
@protocol PTPDFViewCtrlDelegate <NSObject>

@optional

/**
 * Tells the delegate that a render job is complete.
 *
 * @param pdfViewCtrl The pdfViewCtrl for which rendering finished.
 *
 */
- (void)pdfViewCtrlOnRenderFinished:(PTPDFViewCtrl*)pdfViewCtrl;

/**
 * Tells the delegate that a render job encountered an error.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which a rendering error occurred.
 * @param errorMessage A description of the rendering error.
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl onRenderError:(NSString *)errorMessage;

/**
 * Tells the delegate that the page layout has changed (such as from cover to cover facing).
 *
 * @param pdfViewCtrl The pdfViewCtrl for which the layout changed.
 */
- (void)pdfViewCtrlOnLayoutChanged:(PTPDFViewCtrl*)pdfViewCtrl;

/** Tells the delegate that the current page number changes.
 *
 * @param pdfViewCtrl The pdfViewCtrl which changed page numbers.
 *
 * @param oldPageNumber The previous page number.
 *
 * @param newPageNumber The new page number.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl pageNumberChangedFrom:(int)oldPageNumber To:(int)newPageNumber;

/**
 * Tells the delegate that PTPDFViewCtrl has opened a new document via its selector setDoc.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param doc The new document displayed by the PTPDFViewCtrl.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl onSetDoc:(PTPDFDoc*)doc;

/**
 * Tells the delegate that PTPDFViewCtrl has closed the current document.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 */
- (void)pdfViewCtrlDidCloseDoc:(PTPDFViewCtrl*)pdfViewCtrl;

/**
 * Tells the delegate that text search has commenced.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 */
- (void)pdfViewCtrlTextSearchStart:(PTPDFViewCtrl*)pdfViewCtrl;

/** 
 * Tells the delegate that a text search result has been found. The selection object
 * can be passed to PDFViewCtrl's highlightSelection:withColor: to easily
 * highlight the text.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param selection An Selection object representing the location of the found text.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl textSearchResult:(PTSelection*) selection;

/**
 * Tells the delegate that a download event has occured. (Occurs when downloading a document with OpenUrl:)
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param type The type of the event.
 *
 * @param pageNum The number of the page that the event is for.
 *
 * @param message The message for the event, or `nil` if there is no message.
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl downloadEventType:(PTDownloadedType)type pageNumber:(int)pageNum message:(nullable NSString*)message;

/** 
 * Tells the delegate there was a download even error. (Occurs when downloading a document with OpenUrl:)
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param exception The type and reason for the error.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl downloadError:(NSException*)exception;


/**
 * Returns a thumbnail requested by PDFViewCtrl's selector GetThumbAsync:.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param page_num The page number of the thumbnail.
 *
 * @param image The thumbnail image.
 *
 */
-(void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl gotThumbAsync:(int)page_num thumbImage:(nullable UIImage*)image;


/** @name pdfScrollView methods
 */

/**
 * Tells the delegate when the user scrolls the content view within the receiver.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scrollview object in which the scrolling occurred.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl pdfScrollViewDidScroll:(UIScrollView *)scrollView;

/**
 * Tells the delegate when the scroll view is about to start scrolling the content.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scroll-view object that is about to scroll the content view.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl pdfScrollViewWillBeginDragging:(UIScrollView *)scrollView;

/**
 * Tells the delegate when dragging ended in the scroll view.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scroll-view object that is about to scroll the content view.
 *
 * @param decelerate `YES` if the scrolling movement will continue, but decelerate, after a touch-up gesture during a dragging operation. If the value is `NO`, scrolling stops immediately upon touch-up.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl pdfScrollViewDidEndDragging:(UIScrollView *)scrollView willDecelerate:(BOOL)decelerate;

/**
 *  Asks the delegate if the scroll view should scroll to the top of the content.
 *
 * If the delegate doesn’t implement this method, `YES` is assumed.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scroll-view object that perform the scrolling operation.
 *
 * @return YES to permit scrolling to the top of the content, NO to disallow it.
 *
 */
- (BOOL)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl pdfScrollViewShouldScrollToTop:(UIScrollView *)scrollView; // will respect result returned by delegate

/**
 * Tells the delegate that the scroll view scrolled to the top of the content.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scroll-view object that perform the scrolling operation.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl pdfScrollViewDidScrollToTop:(UIScrollView *)scrollView;

/**
 * Tells the delegate that the scroll view is starting to decelerate the scrolling movement.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scroll-view object that is decelerating the scrolling of the content view.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl pdfScrollViewWillBeginDecelerating:(UIScrollView *)scrollView;

/**
 * Tells the delegate that the scroll view has ended decelerating the scrolling movement.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scroll-view object that is decelerating the scrolling of the content view.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl pdfScrollViewDidEndDecelerating:(UIScrollView *)scrollView;

/**
 * Tells the delegate that zooming of the content in the scroll view is about to commence.
 *
 * This method is called at the beginning of zoom gestures and in cases where a change in zoom level is to be animated.
 * You can use this method to store state information or perform any additional actions prior to zooming the view’s content.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scrollview object displaying the content view.
 *
 * @param view The view object whose content is about to be zoomed.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl pdfScrollViewWillBeginZooming:(UIScrollView *)scrollView withView:(nullable UIView *)view;

/**
 * Tells the delegate when the user zooms the content view within the receiver.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scrollview object in which the scrolling occurred.
 *
 * @param view The view object representing that part of the content view that needs to be scaled.
 *
 * @param scale The scale factor to use for scaling.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl pdfScrollViewDidEndZooming:(UIScrollView *)scrollView withView:(nullable UIView *)view atScale:(float)scale;

/**
 * Tells the delegate that the scroll view’s zoom factor changed.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scroll-view object whose zoom factor changed.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl pdfScrollViewDidZoom:(UIScrollView *)scrollView;

/**
 *
 * Allows the delegate to control if the scroll view can zoom via a pinch
 * gesture.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @return YES to permit the pinch zoom to proceed; NO to ignore the pinch zoom.
 *
 */
- (BOOL)pdfViewCtrlShouldZoom:(PTPDFViewCtrl*)pdfViewCtrl;

/**
 * Tells the delegate when a scrolling animation in the scroll view concludes.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scroll-view object that is performing the scrolling animation.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl pdfScrollViewDidEndScrollingAnimation:(UIScrollView *)scrollView;

/**
 * Tells the delegate when the user taps on the scrollview.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param gestureRecognizer The gesture recognizer that detected the tap.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl pdfScrollViewTap:(UITapGestureRecognizer *)gestureRecognizer;

/**
 * Tells the delegate when the user double taps on the scrollview.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param gestureRecognizer The gesture recognizer that detected the taps.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl pdfScrollViewDoubleTap:(UITapGestureRecognizer*)gestureRecognizer;

/**
 * Tells the delegate when the user long presses on the scrollview.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param gestureRecognizer The gesture recognizer that deteted the longpress 
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl pdfScrollViewLongPress:(UILongPressGestureRecognizer *)gestureRecognizer;

// Outer scroll view delegates - holds PDF scroll view when in single page mode. //

/** @name outerScrollView methods
 */

/**
 * Tells the delegate when the user scrolls the content view within the receiver.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scrollview object in which the scrolling occurred.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl outerScrollViewDidScroll:(UIScrollView *)scrollView;

/**
 * Tells the delegate when the scroll view is about to start scrolling the content.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scroll-view object that is about to scroll the content view.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl outerScrollViewWillBeginDragging:(UIScrollView *)scrollView;

/**
 * Tells the delegate when dragging ended in the scroll view.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scroll-view object that is about to scroll the content view.
 *
 * @param decelerate `YES` if the scrolling movement will continue, but decelerate, after a touch-up gesture during a dragging operation. If the value is `NO`, scrolling stops immediately upon touch-up.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl outerScrollViewDidEndDragging:(UIScrollView *)scrollView willDecelerate:(BOOL)decelerate;

/**
 *  Asks the delegate if the scroll view should scroll to the top of the content.
 *
 * If the delegate doesn’t implement this method, `YES` is assumed.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scroll-view object that perform the scrolling operation.
 *
 * @return YES to permit scrolling to the top of the content, NO to disallow it.
 *
 */
- (BOOL)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl outerScrollViewShouldScrollToTop:(UIScrollView *)scrollView; // will respect result returned by delegate

/**
 * Tells the delegate that the scroll view scrolled to the top of the content.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scroll-view object that perform the scrolling operation.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl outerScrollViewDidScrollToTop:(UIScrollView *)scrollView;

/**
 * Tells the delegate that the scroll view is starting to decelerate the scrolling movement.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scroll-view object that is decelerating the scrolling of the content view.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl outerScrollViewWillBeginDecelerating:(UIScrollView *)scrollView;

/**
 * Tells the delegate that the scroll view has ended decelerating the scrolling movement.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scroll-view object that is decelerating the scrolling of the content view.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl outerScrollViewDidEndDecelerating:(UIScrollView *)scrollView;

/**
 * Tells the delegate that zooming of the content in the scroll view is about to commence.
 *
 * This method is called at the beginning of zoom gestures and in cases where a change in zoom level is to be animated.
 * You can use this method to store state information or perform any additional actions prior to zooming the view’s content.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scrollview object displaying the content view.
 *
 * @param view The view object whose content is about to be zoomed.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl outerScrollViewWillBeginZooming:(UIScrollView *)scrollView withView:(nullable UIView *)view;

/**
 * Tells the delegate when the user zooms the content view within the receiver.
 *
 * @param scrollView The scrollview object in which the scrolling occurred.
 *
 * @param view The view object representing that part of the content view that needs to be scaled.
 *
 * @param scale The scale factor to use for scaling.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl outerScrollViewDidEndZooming:(UIScrollView *)scrollView withView:(nullable UIView *)view atScale:(CGFloat)scale;

/**
 * Tells the delegate that the scroll view’s zoom factor changed.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scroll-view object whose zoom factor changed.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl outerScrollViewDidZoom:(UIScrollView *)scrollView;

/**
 * Tells the delegate when a scrolling animation in the scroll view concludes.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scroll-view object that is performing the scrolling animation.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl outerScrollViewDidEndScrollingAnimation:(UIScrollView *)scrollView;

/**
 * Generic event callback system for javascript action. Can be used to handle alert event which pops up
 * a window with alert message
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param event_type type name of the event, such as 'alert'
 * @param json the object that contains event data
 */
-(void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl javascriptCallback:(nullable const char*)event_type json:(nullable const char*)json;

/**
 * Tells the `PTPDFViewCtrl`'s delegate that the specified action parameter will be executed.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which the action parameter will be executed.
 *
 * @param actionParameter The action parameter to be executed.
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl *)pdfViewCtrl willExecuteActionWithActionParameter:(PTActionParameter *)actionParameter;

/**
 * Tells the `PTPDFViewCtrl`'s delegate that the specified action parameter was executed.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which the action parameter was executed.
 *
 * @param actionParameter The action parameter that was executed.
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl *)pdfViewCtrl didExecuteActionWithActionParameter:(PTActionParameter *)actionParameter;

@end

#pragma mark - PTPDFViewCtrlToolDelegate Protocol

/**
 * The methods declared by the `PTPDFViewCtrlToolDelegate` protocol allow the adopting delegate to be used as a "Tool", in which
 * specific responses to user input can be defined.
 *
 * PDFNet include the Tools framework (/Lib/Tools) and associated source code, that implements a set of tools for
 * annotation creation/modification, form filling, text selection, link following, and other UI operations.
 *
 */
PDFNET_OBJC_RUNTIME_NAME(PTPDFViewCtrlToolDelegate)
@protocol PTPDFViewCtrlToolDelegate <NSObject>
@optional

// touch gestures (on pdfScrollView)

/** @name Touch and Gesture Methods
 */

/**
 * Tells the receiver when one or more fingers touch down in the pdfScrollView.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param touches A set of UITouch instances that represent the touches for the starting phase of the event represented by event.
 *
 * @param event An object representing the event to which the touches belong.
 *
 * @return `YES` if the tool has handled the event, `NO` if it should be passed to a new tool of a different type.
 *
 */
- (BOOL)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl onTouchesBegan:(NSSet<UITouch *> *)touches withEvent:(nullable UIEvent *)event;

/**
 * Tells the receiver when one or more fingers associated with an event move within the pdfScrollView.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param touches A set of UITouch instances that represent the touches for the starting phase of the event represented by event.
 *
 * @param event An object representing the event to which the touches belong.
 *
 * @return `YES` if the tool has handled the event, `NO` if it should be passed to a new tool of a different type.
 *
 */
- (BOOL)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl onTouchesMoved:(NSSet<UITouch *> *)touches withEvent:(nullable UIEvent *)event;

/**
 * Tells the receiver when one or more fingers are raised from the pdfScrollView.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param touches A set of UITouch instances that represent the touches for the starting phase of the event represented by event.
 *
 * @param event An object representing the event to which the touches belong.
 *
 * @return `YES` if the tool has handled the event, `NO` if it should be passed to a new tool of a different type.
 *
 */
- (BOOL)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl onTouchesEnded:(NSSet<UITouch *> *)touches withEvent:(nullable UIEvent *)event;

/**
 * Sent to the receiver when a system event (such as a low-memory warning) cancels a touch event.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param touches A set of UITouch instances that represent the touches for the starting phase of the event represented by event.
 *
 * @param event An object representing the event to which the touches belong.
 *
 * @return `YES` if the tool has handled the event, `NO` if it should be passed to a new tool of a different type.
 *
 */
- (BOOL)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl onTouchesCancelled:(NSSet<UITouch *> *)touches withEvent:(nullable UIEvent *)event;

/**
 * Tells the delegate that a long press has occured on the pdfScrollView.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param gestureRecognizer The gesture recognizer that triggered the event.
 *
 * @return `YES` if the tool has handled the event, `NO` if it should be passed to a new tool of a different type.
 */
- (BOOL)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl handleLongPress:(UILongPressGestureRecognizer *)gestureRecognizer;

/**
 * Tells the delegate that a single tap has occured on the pdfScrollView.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param gestureRecognizer The gesture recognizer that trigger the event.
 *
 * @return `YES` if the tool has handled the event, `NO` if it should be passed to a new tool of a different type.
 */
- (BOOL)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl handleTap:(UITapGestureRecognizer *)gestureRecognizer;

/**
 * Tells the delegate that a double tap has occured on the pdfScrollView.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param gestureRecognizer The gesture recognizer that trigger the event.
 *
 * @return `YES` if the tool has handled the event, `NO` if it should be passed to a new tool of a different type.
 */
- (BOOL)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl handleDoubleTap:(UITapGestureRecognizer *)gestureRecognizer;

/**
 * Tells the delegate that a context menu interaction (right-click on macOS or long press on iOS) has occured on the pdfScrollView.
 *
 * @param pdfViewCtrl The `PTPDFViewCtrl` for which this event occurred.
 *
 * @param interaction The interaction that triggers the event.
 *
 * @param location The location of the interaction in the `PDFViewCtrl`.
 *
 * @param configuration A `UIContextMenuConfiguration` returned by reference which describes the menu to be presented.
 *
 * @return `YES` if the tool has handled the event, `NO` if it should be passed to a new tool of a different type.
 */
- (BOOL)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl contextMenuInteraction:(UIContextMenuInteraction *)interaction configurationForMenuAtLocation:(CGPoint)location configuration:(UIContextMenuConfiguration*_Nullable *_Nonnull)configuration API_AVAILABLE(ios(13.0));

/**
 * Returns whether to cancel touches related to the content subview and start dragging.
 *
 * This event cannot be forwarded to another tool.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param view The pdfScrollVIew.
 *
 * @return `YES to cancel further touch messages to pdfScrollView, NO to have view continue to receive those messages.
 */
- (BOOL)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl touchesShouldCancelInContentView:(UIView *)view;

/**
 * Implemented to customize the default behavior when a finger touches down in the pdfScrollView.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param touches A set of UITouch instances that represent the touches for the starting phase of the event represented by event.
 *
 * @param event An object representing the event to which the touch objects in touches belong.
 *
 * @param view The subview in the content where the touch-down gesture occurred.
 *
 * @return `YES` if the tool has handled the event, `NO` if it should be passed to a new tool of a different type.
 */
- (BOOL)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl touchesShouldBegin:(NSSet<UITouch *> *)touches withEvent:(nullable UIEvent *)event inContentView:(UIView *)view;

/**
 * Implemented to respond to Apple Pencil 2 interactions.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param interaction An object representing the interaction indicating that the user double-tapped their Apple Pencil.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl pencilInteractionDidTap:(UIPencilInteraction *)interaction API_AVAILABLE(ios(12.1));

/** @name pdfScrollView methods
 */

/**
 * Tells the delegate when the user scrolls the content view within the receiver.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scrollview object in which the scrolling occurred.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl pdfScrollViewDidScroll:(UIScrollView *)scrollView;

/**
 * Tells the delegate when the scroll view is about to start scrolling the content.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scroll-view object that is about to scroll the content view.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl pdfScrollViewWillBeginDragging:(UIScrollView *)scrollView;

/**
 * Tells the delegate when dragging ended in the scroll view.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scroll-view object that is about to scroll the content view.
 *
 * @param decelerate `YES` if the scrolling movement will continue, but decelerate, after a touch-up gesture during a dragging operation. If the value is `NO`, scrolling stops immediately upon touch-up.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl pdfScrollViewDidEndDragging:(UIScrollView *)scrollView willDecelerate:(BOOL)decelerate;

/**
 *  Asks the delegate if the scroll view should scroll to the top of the content.
 *
 * If the delegate doesn’t implement this method, `YES` is assumed.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scroll-view object that perform the scrolling operation.
 *
 * @return YES to permit scrolling to the top of the content, NO to disallow it.
 *
 */
- (BOOL)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl pdfScrollViewShouldScrollToTop:(UIScrollView *)scrollView; // will respect result returned by delegate

/**
 * Tells the delegate that the scroll view scrolled to the top of the content.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scroll-view object that perform the scrolling operation.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl pdfScrollViewDidScrollToTop:(UIScrollView *)scrollView;

/**
 * Tells the delegate that the scroll view is starting to decelerate the scrolling movement.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scroll-view object that is decelerating the scrolling of the content view.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl pdfScrollViewWillBeginDecelerating:(UIScrollView *)scrollView;

/**
 * Tells the delegate that the scroll view has ended decelerating the scrolling movement.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scroll-view object that is decelerating the scrolling of the content view.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl pdfScrollViewDidEndDecelerating:(UIScrollView *)scrollView;

/**
 * Tells the delegate that zooming of the content in the scroll view is about to commence.
 *
 * This method is called at the beginning of zoom gestures and in cases where a change in zoom level is to be animated.
 * You can use this method to store state information or perform any additional actions prior to zooming the view’s content.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scrollview object displaying the content view.
 *
 * @param view The view object whose content is about to be zoomed.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl pdfScrollViewWillBeginZooming:(UIScrollView *)scrollView withView:(nullable UIView *)view;

/**
 * Tells the delegate when the user zooms the content view within the receiver.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scrollview object in which the scrolling occurred.
 *
 * @param view The view object representing that part of the content view that needs to be scaled.
 *
 * @param scale The scale factor to use for scaling.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl pdfScrollViewDidEndZooming:(UIScrollView *)scrollView withView:(nullable UIView *)view atScale:(float)scale;

/**
 * Tells the delegate that the scroll view’s zoom factor changed.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scroll-view object whose zoom factor changed.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl pdfScrollViewDidZoom:(UIScrollView *)scrollView;

/**
 *
 * Allows the delegate to control if the scroll view can zoom via a pinch
 * gesture.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @return YES to permit the pinch zoom to proceed; NO to ignore the pinch zoom.
 *
 */
- (BOOL)pdfViewCtrlShouldZoom:(PTPDFViewCtrl*)pdfViewCtrl;

/**
 * Tells the delegate when a scrolling animation in the scroll view concludes.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scroll-view object that is performing the scrolling animation.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl pdfScrollViewDidEndScrollingAnimation:(UIScrollView *)scrollView;

// Outer scroll view delegates - holds scrollView when in single page mode. //

/** @name outerScrollView methods
 */

/**
 * Tells the delegate when the user scrolls the content view within the receiver.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scrollview object in which the scrolling occurred.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl outerScrollViewDidScroll:(UIScrollView *)scrollView;

/**
 * Tells the delegate when the scroll view is about to start scrolling the content.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scroll-view object that is about to scroll the content view.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl outerScrollViewWillBeginDragging:(UIScrollView *)scrollView;

/**
 * Tells the delegate when dragging ended in the scroll view.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scroll-view object that is about to scroll the content view.
 *
 * @param decelerate `YES` if the scrolling movement will continue, but decelerate, after a touch-up gesture during a dragging operation. If the value is `NO`, scrolling stops immediately upon touch-up.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl outerScrollViewDidEndDragging:(UIScrollView *)scrollView willDecelerate:(BOOL)decelerate;

/**
 *  Asks the delegate if the scroll view should scroll to the top of the content.
 *
 * If the delegate doesn’t implement this method, `YES` is assumed.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scroll-view object that perform the scrolling operation.
 *
 * @return YES to permit scrolling to the top of the content, NO to disallow it.
 *
 */
- (BOOL)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl outerScrollViewShouldScrollToTop:(UIScrollView *)scrollView; // will respect result returned by delegate

/**
 * Tells the delegate that the scroll view scrolled to the top of the content.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scroll-view object that perform the scrolling operation.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl outerScrollViewDidScrollToTop:(UIScrollView *)scrollView;

/**
 * Tells the delegate that the scroll view is starting to decelerate the scrolling movement.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scroll-view object that is decelerating the scrolling of the content view.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl outerScrollViewWillBeginDecelerating:(UIScrollView *)scrollView;

/**
 * Tells the delegate that the scroll view has ended decelerating the scrolling movement.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scroll-view object that is decelerating the scrolling of the content view.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl outerScrollViewDidEndDecelerating:(UIScrollView *)scrollView;

/**
 * Tells the delegate that zooming of the content in the scroll view is about to commence.
 *
 * This method is called at the beginning of zoom gestures and in cases where a change in zoom level is to be animated.
 * You can use this method to store state information or perform any additional actions prior to zooming the view’s content.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scrollview object displaying the content view.
 *
 * @param view The view object whose content is about to be zoomed.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl outerScrollViewWillBeginZooming:(UIScrollView *)scrollView withView:(nullable UIView *)view;

/**
 * Tells the delegate when the user zooms the content view within the receiver.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scrollview object in which the scrolling occurred.
 *
 * @param view The view object representing that part of the content view that needs to be scaled.
 *
 * @param scale The scale factor to use for scaling.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl outerScrollViewDidEndZooming:(UIScrollView *)scrollView withView:(nullable UIView *)view atScale:(float)scale;

/**
 * Tells the delegate that the scroll view’s zoom factor changed.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scroll-view object whose zoom factor changed.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl outerScrollViewDidZoom:(UIScrollView *)scrollView;

/**
 * Tells the delegate when a scrolling animation in the scroll view concludes.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param scrollView The scroll-view object that is performing the scrolling animation.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl outerScrollViewDidEndScrollingAnimation:(UIScrollView *)scrollView;

/**
 * Tells the delegate that the page layout has changed (such as from cover to cover facing).
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 */
- (void)pdfViewCtrlOnLayoutChanged:(PTPDFViewCtrl*)pdfViewCtrl;

/** Tells the delegate that the current page number changes.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param oldPageNumber The previous page number.
 *
 * @param newPageNumber The new page number.
 *
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl pageNumberChangedFrom:(int)oldPageNumber To:(int)newPageNumber;

/**
 * Tells the delegate that PTPDFViewCtrl has opened a new document via its selector setDoc.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 */
- (void)pdfViewCtrlOnSetDoc:(PTPDFViewCtrl*)pdfViewCtrl;

/**
 * Tells the delegate that PTPDFViewCtrl has closed the current document.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 */
- (void)pdfViewCtrlDidCloseDoc:(PTPDFViewCtrl*)pdfViewCtrl;

/**
 * Tells the delegate that a render job is complete.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 */
- (void)pdfViewCtrlOnRenderFinished:(PTPDFViewCtrl*)pdfViewCtrl;

/**
 * Tells the delegate that a render job encountered an error.
 *
 * @param pdfViewCtrl The PDFViewCtrl for which a rendering error occurred.
 * @param errorMessage A description of the rendering error.
 */
- (void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl onRenderError:(NSString *)errorMessage;

/**
 * Generic event callback system for javascript action. Can be used to handle alert event which pops up
 * a window with alert message
 *
 * @param pdfViewCtrl The PDFViewCtrl for which this event occurred.
 *
 * @param event_type type name of the event, such as 'alert'
 * @param json the object that contains event data
 */
-(void)pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl javascriptCallback:(nullable const char*)event_type json:(nullable const char*)json;

@end

NS_ASSUME_NONNULL_END
