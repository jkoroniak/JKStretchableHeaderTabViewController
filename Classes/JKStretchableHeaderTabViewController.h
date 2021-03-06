//
//  JKStretchableHeaderTabViewController.h
//  Pods
//

#import <UIKit/UIKit.h>
#import "JKStretchableHeaderView.h"
#import "JKTabBar.h"
#import "JKTabViewController.h"

@class JKStretchableHeaderTabViewController;

@protocol JKStretchableHeaderTabViewControllerDelegate <NSObject>

@optional
- (void) stretchableHeaderTabViewController: (JKStretchableHeaderTabViewController*) stretchableHeaderTabViewController willShowTabController: (UIViewController*) tabController;

@end

@interface JKStretchableHeaderTabViewController : UIViewController <UIScrollViewDelegate, JKTabBarDelegate>
@property (nonatomic) NSUInteger selectedIndex;
@property (readwrite, nonatomic) JKTabViewController *selectedViewController;
@property (copy, nonatomic) NSArray *viewControllers;

@property (weak, nonatomic) IBOutlet JKStretchableHeaderView *headerView;
@property (readonly, nonatomic) JKTabBar *tabBar;
@property (weak, nonatomic) IBOutlet UIScrollView *containerView;
@property (nonatomic) BOOL shouldBounceHeaderView;

@property (nonatomic, assign) id <JKStretchableHeaderTabViewControllerDelegate> delegate;

- (void) selectTabViewControllerAtIndex: (NSInteger) index;

// Layout
- (void)layoutHeaderViewAndTabBar;
- (void)layoutViewControllers;
- (void)layoutSubViewControllerToSelectedViewController;
@end
