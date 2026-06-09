//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/PTAnnotEditTool.h>
#import <Tools/PTResizeWidgetView.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * The `PTCalloutEditTool` is used to edit free text callout
 * (`PTExtendedAnnotTypeCallout`) annotations.
 */
PT_OBJC_RUNTIME_NAME(CalloutEditTool)
@interface PTCalloutEditTool : PTAnnotEditTool

/**
 * The callout start point, in screen coordinates.
 */
@property (nonatomic, assign) CGPoint calloutStartPoint;

/**
 * The callout knee point, in screen coordinates.
 */
@property (nonatomic, assign) CGPoint calloutKneePoint;

/**
 * The callout end point, in screen coordinates.
 */
@property (nonatomic, assign) CGPoint calloutEndPoint;

/**
 * The callout content rect, in screen coordinates.
 */
@property (nonatomic, assign) CGRect contentRect;

/**
 * The callout start point resize widget.
 */
@property (nonatomic, strong) PTResizeWidgetView *calloutStartResizeWidget;

/**
 * The callout knee point resize widget.
 */
@property (nonatomic, strong) PTResizeWidgetView *calloutKneeResizeWidget;

/**
 * The currently selected resize widget.
 */
@property (nonatomic, weak, nullable) PTResizeWidgetView *selectedResizeWidget;

@end

NS_ASSUME_NONNULL_END
