//
//  NRGridView.h
//  Grid
//
//  Created by Louka Desroziers on 05/01/12.

/***********************************************************************************
 *
 * Copyright (c) 2012 Novedia Regions
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 * 
 ***********************************************************************************
 *
 * Referencing this project in your AboutBox is appreciated.
 * Please tell me if you use this class so we can cross-reference our projects.
 *
 ***********************************************************************************/


#import <UIKit/UIKit.h>
#import "NRGridViewDataSource.h"
#import "NRGridViewDelegate.h"
#import "NRGridViewCell.h"


@interface NSIndexPath (NRGridViewIndexPath)
+ (NSIndexPath*)indexPathForItemIndex:(NSInteger)itemIndex
                            inSection:(NSInteger)section;
@property (readonly) NSInteger itemIndex;
@end

enum{
    NRGridViewLayoutStyleVertical,
    NRGridViewLayoutStyleHorizontal
};
typedef NSInteger NRGridViewLayoutStyle;

static CGSize const kNRGridViewDefaultCellSize = {50, 70};

@interface NRGridView : UIScrollView
{
    @private
    NSMutableArray  *_sectionLayouts;
    NSMutableSet    *_reusableCellsSet;
    NSMutableSet    *_visibleCellsSet;
    NSIndexPath     *_selectedIndexPath;
    NRGridViewCell  *_highlightedCell;
}

- (id)initWithLayoutStyle:(NRGridViewLayoutStyle)layoutStyle;
@property (nonatomic, assign) NRGridViewLayoutStyle layoutStyle;

@property (nonatomic, assign) id<NRGridViewDelegate> delegate;
@property (nonatomic, assign) id<NRGridViewDataSource> dataSource;

/** Determines the size of every cells passed into the gridView. Default value is kNRGridViewDefaultCellSize */
@property (nonatomic, assign) CGSize cellSize;

@property (nonatomic, readonly) NSArray     *visibleCells;
@property (nonatomic, readonly) NSArray     *indexPathsForVisibleCells;
@property (nonatomic, readonly) NSIndexPath *indexPathForSelectedCell;

- (NRGridViewCell*)dequeueReusableCellWithIdentifier:(NSString*)identifier;
- (NRGridViewCell*)cellAtIndexPath:(NSIndexPath*)indexPath;

- (CGRect)rectForHeaderInSection:(NSInteger)section;

- (void)deselectedCellAtIndexPath:(NSIndexPath*)indexPath animated:(BOOL)animated;

- (void)reloadData;

@end
