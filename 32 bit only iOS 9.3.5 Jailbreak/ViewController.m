//
//  ViewController.m
//  nalu935
//
//  Created by @iosusr
//  Copyright © 2017 @iosusr. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.

}
- (IBAction)gobuttontapped
{
    NSString *title = @"You Road The Wave!";
    NSString *message = @"Please reboot your Device";
    NSString *okText = @"OK";
    
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:
                                title message:message preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *okButton = [UIAlertAction actionWithTitle:okText style:
                               UIAlertActionStyleCancel handler:nil];
    [alert addAction:okButton];
    
    [self presentViewController:alert animated:YES completion:nil];
    
    
    
    
    



}


@end
