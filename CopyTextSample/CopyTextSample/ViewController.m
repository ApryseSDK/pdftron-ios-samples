#import "ViewController.h"

#import "MYDocumentViewController.h"

@interface ViewController ()

@property (nonatomic, strong, nullable) MYDocumentViewController *documentController;

@property (nonatomic, assign) BOOL needsOpenDocument;

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    MYDocumentViewController *documentController = [[MYDocumentViewController alloc] init];
    self.documentController = documentController;
    
    // Navigation controller.
    UINavigationController *navigationController = [[UINavigationController alloc] initWithRootViewController:documentController];
    
    [self addChildViewController:navigationController];
    
    [self.view addSubview:navigationController.view];
    
    navigationController.view.frame = self.view.bounds;
    navigationController.view.autoresizingMask = (UIViewAutoresizingFlexibleWidth |
                                                  UIViewAutoresizingFlexibleHeight);
    
    [navigationController didMoveToParentViewController:self];
    
    self.needsOpenDocument = YES;
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    
    if (self.needsOpenDocument) {
        [self openDocument];
        
        self.needsOpenDocument = NO;
    }
}

- (void)openDocument
{
    [self.documentController openDocumentWithURL:[NSURL URLWithString:@"https://www.pdftron.com/downloads/pdfref.pdf"]];
}

@end
