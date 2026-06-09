//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/AnnotTypes.h>
#import <Tools/PTLocalization.h>

#import <PDFNet/PDFNet.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Utility methods for the Tools framework.
 */
PT_OBJC_RUNTIME_NAME(ToolsUtil)
@interface PTToolsUtil : NSObject

/**
 * Returns an image in the tools bundle, regardless of extension.
 *
 * @param name The name of the image, with or without an extension.
 *
 * @return A UIImage created from the named file.
 */
+ (nullable UIImage*)toolImageNamed:(NSString*)name;

/**
 * Returns an image in the tools bundle, regardless of extension.
 *
 * @param name The name of the image, with or without an extension.
 *
 * @param inverted If true, returns a color-inverted version of the image
 *
 * @return A UIImage created from the named file.
 */
+ (nullable UIImage*)toolImageNamed:(NSString*)name inverted:(BOOL)inverted;

/**
 * Creates a 1 page `PTPDFDoc` from a `UIView`.
 *
 * @param aView The view to turn into a PDF
 *
 * @return a PDF created from the view.
 */
+(PTPDFDoc*)createPTPDFDocFromFromUIView:(UIView*)aView;

/**
 * Reset settings to defaults.
 */
+ (void)resetSettings;

/**
 * Returns the tool image for an annotation type.
 */
+ (nullable UIImage *)imageForAnnotationType:(PTExtendedAnnotType)annotationType;

/**
 * The Tools framework bundle.
 */
@property (nonatomic, class, readonly) NSBundle *toolsBundle;

/**
 * The directory URL for Tools-specific saved resources, data and configuration files, etc.
 */
@property (nonatomic, class, readonly, nullable) NSURL *toolsResourcesDirectoryURL;

@end

NS_ASSUME_NONNULL_END
