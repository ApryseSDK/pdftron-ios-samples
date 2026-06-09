//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <UIKit/UIKit.h>

#import <PDFNet/PDFNet.h>

NS_ASSUME_NONNULL_BEGIN

@class PTDiffViewController;

/**
 * The methods declared by the PTDiffViewControllerDelegate protocol allow the adopting delegate
 * to respond to messages from the `PTDiffViewController` class.
 */
PT_OBJC_RUNTIME_NAME(DiffViewControllerDelegate)
@protocol PTDiffViewControllerDelegate <NSObject>
@optional

/**
 * Informs the delegate of the output file location.
 */
- (void)diffViewController:(PTDiffViewController *)diffViewController didCreateDiffFileAtURL:(NSURL *)fileURL;

/**
 * Informs the delegate that an error occurred while comparing documents.
 */
- (void)diffViewController:(PTDiffViewController *)diffViewController didFailToCompareDocumentsWithError:(NSError*)error;

@end

/**
 * The PTDiffViewController class provides functionality to produce a document
 * representing the visual difference between two documents.
 * Instances of this class must be embedded inside a UINavigationController.
 */
PT_OBJC_RUNTIME_NAME(DiffViewController)
@interface PTDiffViewController : UIViewController

/**
 * Initializes a new `PTDiffViewController` instance with two documents to compare.
 *
 * @param firstDocument The first `PTPDFDoc` instance to compare.
 * @param secondDocument The second `PTPDFDoc` instance to compare.
 *
 * @return an initialized `PTDiffViewController`.
 */
- (instancetype)initWithDocument:(nullable PTPDFDoc *)firstDocument secondDocument:(nullable PTPDFDoc *)secondDocument;

/**
 * Initializes a new `PTDiffViewController` instance with two documents to compare and their display color.
 *
 * @param firstDocument The first `PTPDFDoc` instance to compare.
 * @param secondDocument The second `PTPDFDoc` instance to compare.
 * @param firstDocumentColor The display color for `firstDocument`.
 * @param secondDocumentColor The display color for `secondDocument`.
 *
 * @return an initialized `PTDiffViewController`.
 */
- (instancetype)initWithDocument:(nullable PTPDFDoc *)firstDocument secondDocument:(nullable PTPDFDoc *)secondDocument firstDocumentColor:(nullable UIColor *)firstDocumentColor secondDocumentColor:(nullable UIColor *)secondDocumentColor NS_DESIGNATED_INITIALIZER;

/**
 * An object conforming to the PTdiffViewControllerDelegate protocol.
 */
@property (nonatomic, weak, nullable) id<PTDiffViewControllerDelegate> delegate;

/**
 * The first document to compare.
 */
@property (nonatomic, strong, nullable) PTPDFDoc *firstDocument;

/**
 * The second document to compare.
 */
@property (nonatomic, strong, nullable) PTPDFDoc *secondDocument;

/**
 * The display color to use for the first document.
 */
@property (nonatomic, strong, nullable) UIColor *firstDocumentColor;

/**
 * The display color to use for the second document.
 */
@property (nonatomic, strong, nullable) UIColor *secondDocumentColor;

/**
 * The blend mode used for comparing documents.
 */
@property (nonatomic, assign) PTBlendMode blendMode;


- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
