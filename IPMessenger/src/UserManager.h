/*============================================================================*
 * (C) 2001-2011 G.Ishiwata, All Rights Reserved.
 *
 *	Project		: IP Messenger for Mac OS X
 *	File		: UserManager.h
 *	Module		: ユーザ一覧管理クラス--------用户列表管理类
 *============================================================================*/

#import <Foundation/Foundation.h>

@class UserInfo;

/*============================================================================*
 * Notification 通知キー---------通知
 *============================================================================*/

// ユーザ一覧変更
// 用户列表的变化
#define NOTICE_USER_LIST_CHANGED		@"IPMsgUserListChanged"

/*============================================================================*
 * クラス定義-----类定义
 *============================================================================*/

@interface UserManager : NSObject {
	NSMutableArray*		userList;		// ユーザ一覧----------------用户列表
	NSMutableSet*		dialupSet;		// ダイアルアップアドレス一覧-----拨接地址列表
	NSRecursiveLock*	lock;			// 更新排他用ロック------更新排它锁/递归锁
}

// ファクトリ-----工厂
+ (UserManager*)sharedManager;

// ユーザ情報取得-----用户信息获取
- (NSArray*)users;
- (int)numberOfUsers;
- (UserInfo*)userForLogOnUser:(NSString*)logOn address:(UInt32)addr port:(UInt16)port;

// ユーザ情報追加／削除-------用户信息添加/删除
- (void)appendUser:(UserInfo*)info;
- (void)setVersion:(NSString*)version ofUser:(UserInfo*)user;
- (void)removeUser:(UserInfo*)info;
- (void)removeAllUsers;

// その他-----其他
- (NSArray*)dialupAddresses;

@end
