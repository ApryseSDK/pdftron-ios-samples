//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2021 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

PT_EXTERN
PT_OBJC_RUNTIME_NAME(AnnotationSortMode)
@interface PTAnnotationSortMode : NSObject

- (instancetype)init NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithTitle:(nullable NSString *)title sortDescriptors:(nullable NSArray<NSSortDescriptor *> *)sortDescriptors identifier:(nullable NSString *)identifier ascending:(BOOL)ascending NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithTitle:(nullable NSString *)title identifier:(nullable NSString *)identifier;

+ (instancetype)sortModeWithTitle:(nullable NSString *)title sortDescriptors:(nullable NSArray<NSSortDescriptor *> *)sortDescriptors identifier:(nullable NSString *)identifier ascending:(BOOL)ascending;
+ (instancetype)sortModeWithTitle:(nullable NSString *)title identifier:(nullable NSString *)identifier;

@property (nonatomic, copy, nullable) NSString *title;

@property (nonatomic, copy, nullable) NSArray<NSSortDescriptor *> *sortDescriptors;

@property (nonatomic, copy, nullable) NSString *sectionNameKeyPath;

@property (nonatomic, assign, getter=isAscending) BOOL ascending;

@property (nonatomic, copy, nullable) NSString *identifier;

- (BOOL)isEqualToSortMode:(PTAnnotationSortMode *)sortMode;

@end

NS_ASSUME_NONNULL_END
