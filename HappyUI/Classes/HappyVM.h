//
//  BaseVM.h
//  CCUIModel
//
//  Created by Aruisi on 4/20/18.
//

#import <Foundation/Foundation.h>
#import "HappyBIProtocal.h"

@class CollectionViewArray;
@class TableViewArray;
@class HappyBI;

@interface HappyVM : NSObject

/**
 refresh callback
 */
@property (nonatomic, copy) void(^startRefresh)(void);
@property (nonatomic, copy) void(^didRefresh)(void);

/**
 error view
 */
@property (nonatomic, strong) UIView* _Nullable errorView;

/**
 loading from empty
 */
@property (nonatomic, strong) UIView* _Nullable loadingView;

@property (nonatomic, strong) UIView<ScrollRefreshHeaderProtocal>* _Nullable refreshHeaderView;

@property (nonatomic, readonly) HappyBI * _Nullable model;

@property (nonatomic, readonly)  UICollectionView* _Nullable  collectionView;
@property (nonatomic, readonly)  UITableView* _Nullable  tableView;

//collectioView
-(instancetype _Nonnull )initWith:(HappyBI*_Nonnull)model collectionView:(UICollectionView*_Nonnull)collectionView;

//tableView
-(instancetype _Nonnull )initWith:(HappyBI *_Nonnull)model tableView:(UITableView *_Nonnull)tableView;

-(UIView<ScrollRefreshHeaderProtocal>*)defaultRefreshHeaderView;

#pragma mark sub class
/**
 The sub class need to do as following
 1. set collectionView with a layout
 2. compute cell size
 3. register nib for collectionView, used to create cell
 4. implement cellForItem block
 5. handel cell click
 */
-(void)setUpCollectionView:(CollectionViewArray*_Nonnull)binder collectionView:(UICollectionView*_Nonnull)collectionView;

/**
 The sub class need to do as following
 1. compute cell height
 2. register nib for tableview, used to create cell
 3. implement cellForRow block
 4. handel cell click
 */
-(void)setUpTableView:(TableViewArray*_Nonnull)binder tableView:(UITableView*_Nonnull)tableView;

-(UIView*)defaultEmptyView;
-(UIView*)defaultErrorView;
-(UIView*)defaultLoadingView;
@end
