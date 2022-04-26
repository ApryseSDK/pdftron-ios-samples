//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2022 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import "ViewController.h"
#import <Tools/Tools.h>
@import PDFTronCollaboration;

@interface ViewController ()
@property (nonatomic) PTCollaborationDocumentController *documentController;
@property (nonatomic) CollabClient *collabClient;
@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    NSURL *subscriptionURL = [NSURL URLWithString:@"wss://collab-server.pdftron.com/subscribe"];
    NSURL *endpointURL = [NSURL URLWithString:@"https://collab-server.pdftron.com"];
    
    NSString *documentID = nil; // Leave blank or nil to generate a new document
    
    self.collabClient = [[CollabClient alloc] initWithEndpointURL:endpointURL subscriptionURL:subscriptionURL];
    // Login User
    [self.collabClient loginAnonymouslyWithUsername:@"Guest" completionHandler:^(User * _Nullable user) {
        if (user == nil){
            return;
        }
        [user getDocumentWithDocumentID:documentID completionHandler:^(Document * _Nullable document) {
            if (document == nil) {
                [user createDocumentWithDocumentID:documentID documentName:@"NewDocument" isPublic:YES annotations:@[] completionHandler:^(Document * _Nullable document) {
                    if (document == nil) {
                        return;
                    }
                    [document view];
                }];
                return;
            }
            [document joinWithCompletion:^(BOOL joined) {
                [document view];
            }];
        }];
    }];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    [self showViewer];
}

-(void)showViewer
{
    self.documentController = [[PTCollaborationDocumentController alloc] initWithCollaborationService:self.collabClient];
    // The PTDocumentController must be in a navigation controller before a document can be opened
    UINavigationController *navigationController = [[UINavigationController alloc] initWithRootViewController:self.documentController];
    navigationController.modalPresentationStyle = UIModalPresentationFullScreen;
    navigationController.navigationBar.translucent = NO;
    navigationController.toolbar.translucent = NO;
    // Open a file from URL.
    NSURL *fileURL = [[NSURL alloc] initWithString:@"https://pdftron.s3.amazonaws.com/downloads/pl/webviewer-demo.pdf"];
    [self.documentController openDocumentWithURL:fileURL];
    
    NSMutableArray<UIBarButtonItem*>* leftBarItems = [self.documentController.navigationItem.leftBarButtonItems mutableCopy];
    UIBarButtonItem *shareButton = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemAction target:self action:@selector(shareDocument)];
    [leftBarItems addObject:shareButton];
    self.documentController.navigationItem.leftBarButtonItems = [leftBarItems copy];
    
    // Show navigation (and document) controller.
    [self presentViewController:navigationController animated:YES completion:nil];
}

-(void)shareDocument
{
    NSString *documentID = self.documentController.service.documentID;

    UIAlertController *alertVC = [UIAlertController alertControllerWithTitle:@"Share Link" message:nil preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *copyAction = [UIAlertAction actionWithTitle:@"Copy DocumentID to Clipboard" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        [UIPasteboard.generalPasteboard setString:documentID];
    }];

    UIAlertAction *webViewerAction = [UIAlertAction actionWithTitle:@"Open in WebViewer Showcase" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        NSURL *URL = [[NSURL alloc] initWithString:[NSString stringWithFormat:@"https://www.pdftron.com/webviewer/demo/document-collaboration/?shareId=%@&mobile=1", documentID]];
        [UIApplication.sharedApplication openURL:URL options:[NSDictionary dictionary] completionHandler:nil];
    }];

    UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"Cancel" style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {
        
    }];
    [alertVC addAction:copyAction];
    [alertVC addAction:webViewerAction];
    [alertVC addAction:cancelAction];
    [self.documentController presentViewController:alertVC animated:YES completion:nil];
}

@end
