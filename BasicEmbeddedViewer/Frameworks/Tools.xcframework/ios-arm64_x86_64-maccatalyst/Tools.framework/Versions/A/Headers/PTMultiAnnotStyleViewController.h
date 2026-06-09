//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTAnnotStyleViewController.h>
#import <Tools/PTOverrides.h>
#import <Tools/PTToolManager.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTMultiAnnotStyleViewController;

PT_OBJC_RUNTIME_NAME(MultiAnnotStyleViewControllerDelegate)
@protocol PTMultiAnnotStyleViewControllerDelegate <NSObject>
@optional

- (nullable NSString *)multiAnnotStyleViewController:(PTMultiAnnotStyleViewController *)multiAnnotStyleViewController titleForStyle:(PTAnnotStyle *)style;

@end

PT_EXPORT
PT_OBJC_RUNTIME_NAME(MultiAnnotStyleViewController)
@interface PTMultiAnnotStyleViewController : UIViewController <PTOverridable>

- (instancetype)initWithStyles:(NSArray<PTAnnotStyle *> *)styles;
- (instancetype)initWithToolManager:(nullable PTToolManager *)toolManager styles:(NSArray<PTAnnotStyle *> *)styles NS_DESIGNATED_INITIALIZER;

@property (nonatomic, weak, nullable) id<PTMultiAnnotStyleViewControllerDelegate> delegate;

@property (nonatomic, readonly, strong, nullable) PTToolManager *toolManager;

@property (nonatomic, copy, nullable) NSArray<PTAnnotStyle *> *styles;

@property (nonatomic) NSUInteger selectedStyleIndex;
@property (nonatomic, strong, nullable) PTAnnotStyle *selectedStyle;

@property (nonatomic, readonly, copy, nullable) NSArray<PTAnnotStyleViewController *> *annotationStyleViewControllers;

@property (nonatomic, readonly, strong, nullable) PTAnnotStyleViewController *selectedAnnotationStyleViewController;


- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;

- (instancetype)initWithCoder:(NSCoder *)coder NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
