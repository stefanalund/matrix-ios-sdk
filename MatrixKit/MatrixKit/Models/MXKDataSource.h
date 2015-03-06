/*
 Copyright 2015 OpenMarket Ltd

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#import <Foundation/Foundation.h>

@class MXKDataSource;
@protocol MXKDataSourceDelegate <NSObject>

/**
 Tells the delegate that the data source has changed.
 
 @param changes contains the index paths of objects that changed.
 */
- (void)dataSource:(MXKDataSource*)dataSource didChange:(id /* @TODO*/)changes;

@end


/**
 `MXKDataSource` is the base class for data sources managed by MatrixKit.
 */
@interface MXKDataSource : NSObject

/**
 The delegate notified when the data has been updated.
 */
@property (nonatomic) id<MXKDataSourceDelegate> delegate;

/**
 Register the MXKCellData class that will be used to process and store data for cells 
 with the designated identifier.
 
 @param cellDataClass a MXKCellData-inherited class that will handle data for cells.
 @param identifier the identifier of targeted cell.
 */
- (void)registerCellDataClass:(Class)cellDataClass forCellIdentifier:(NSString *)identifier;

/**
 Return the MXKCellData class that handles data for cells with the designated identifier.

 @param identifier the cell identifier.
 @return the associated MXKCellData-inherited class.
 */
- (Class)cellDataClassForCellIdentifier:(NSString *)identifier;


@end