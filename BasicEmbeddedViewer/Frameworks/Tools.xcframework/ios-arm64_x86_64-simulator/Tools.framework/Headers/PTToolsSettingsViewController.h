//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Tools/ToolsDefines.h>
#import <Tools/PTOverrides.h>
#import <Tools/PTToolsSettingsManager.h>

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *
 * A class that reads and writes settings stored by a `PTToolsSettingsManager` singleton object.
 *
 */
PT_OBJC_RUNTIME_NAME(ToolsSettingsViewController)
@interface PTToolsSettingsViewController : UITableViewController <PTOverridable>

/**
 * Initializes a newly created `PTToolsSettingsViewController` instance with the given parameters.
 *
 * @param style The `UITableViewStyle` to use
 *
 * @param plistName The name of the plist file containing the settings to display in this view controller.
 *
 * @return an initialized `PTToolsSettingsViewController` instance
 */
-(instancetype)initWithStyle:(UITableViewStyle)style plistName:(NSString*)plistName NS_DESIGNATED_INITIALIZER;

/**
 * Initializes a newly created `PTToolsSettingsViewController` instance with the given parameters.
 *
 * @param style The `UITableViewStyle` to use
 *
 * @param plistName The name of the plist file containing the settings to display in this view controller.
 *
 * @param settingsManager The PTToolsSettingsManager used to control the settings
 *
 * @return an initialized `PTToolsSettingsViewController` instance
 */
-(instancetype)initWithStyle:(UITableViewStyle)style plistName:(NSString*)plistName settingsManager:(PTToolsSettingsManager*)settingsManager NS_DESIGNATED_INITIALIZER;

/**
 *
 * The name of the settings plist file containing the settings shown by this view controller.
 *
 */
@property (nonatomic, copy, readonly) NSString* plistName;

@property (nonatomic, copy, readonly) PTToolsSettingsManager* toolsSettingsManager;


-(instancetype)initWithStyle:(UITableViewStyle)style NS_UNAVAILABLE;

PT_INIT_WITH_CODER_UNAVAILABLE

PT_INIT_WITH_NIB_NAME_BUNDLE_UNAVAILABLE

@end

NS_ASSUME_NONNULL_END
