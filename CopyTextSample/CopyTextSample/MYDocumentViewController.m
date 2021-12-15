#import "MYDocumentViewController.h"

@interface MYDocumentViewController ()

@end

@implementation MYDocumentViewController

- (NSString *)toolManager:(PTToolManager *)toolManager willCopyReturnedText:(NSString *)selectedText toPasteboard:(UIPasteboard *)pasteboard
{
    // limit copied text to 100 characters.
    NSRange stringRange = NSMakeRange(0, MIN(selectedText.length, 100));
    stringRange = [selectedText rangeOfComposedCharacterSequencesForRange:stringRange];
    
    NSString *truncatedString = [selectedText substringWithRange:stringRange];
    
    return truncatedString;
}

@end
