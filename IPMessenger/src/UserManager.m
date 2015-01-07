/*============================================================================*
 * (C) 2001-2011 G.Ishiwata, All Rights Reserved.
 *
 *	Project		: IP Messenger for Mac OS X
 *	File		: UserManager.m
 *	Module		: ユーザ一覧管理クラス-------用户列表管理类
 *============================================================================*/

#import <Foundation/Foundation.h>
#import "UserManager.h"
#import "UserInfo.h"
#import "DebugLog.h"

#import <netinet/in.h>

/*============================================================================*
 * クラス実装-------实现类
 *============================================================================*/

@implementation UserManager

/*----------------------------------------------------------------------------*
 * ファクトリ-----工厂
 *----------------------------------------------------------------------------*/

// 共有インスタンスを返す-----------------共享的实例/单例
+ (UserManager*)sharedManager {
	static UserManager* sharedManager = nil;
	if (!sharedManager) {
		sharedManager = [[UserManager alloc] init];
	}
	return sharedManager;
}

/*----------------------------------------------------------------------------*
 * 初期化／解放
 *----------------------------------------------------------------------------*/

// 初期化
- (id)init {
	self		= [super init];
	userList	= [[NSMutableArray alloc] init];
	dialupSet	= [[NSMutableSet alloc] init];
	lock		= [[NSRecursiveLock alloc] init];
	[lock setName:@"UserManagerLock"];
	return self;
}

// 解放
- (void)dealloc {
	[userList release];
	[dialupSet release];
	[lock release];
	[super dealloc];
}

/*----------------------------------------------------------------------------*
 * ユーザ情報取得---------用户信息获取
 *----------------------------------------------------------------------------*/

// ユーザリストを返す------返回用户列表
- (NSArray*)users {
	[lock lock];
	NSArray* array = [NSArray arrayWithArray:userList];
	[lock unlock];
	return array;
}

// ユーザ数を返す-----------返回用户数
- (int)numberOfUsers {
	[lock lock];
	int count = [userList count];
	[lock unlock];
	return count;
}

// 指定インデックスのユーザ情報を返す（見つからない場合nil）
// 返回指定索引用户信息（如果没有返回nil）
- (UserInfo*)userAtIndex:(int)index {
	[lock lock];
	UserInfo* info = [[[userList objectAtIndex:index] retain] autorelease];
	[lock unlock];
	return info;
}

// 指定キーのユーザ情報を返す（見つからない場合nil）
// 返回指定指定键值的用户信息（如果没有返回nil）
- (UserInfo*)userForLogOnUser:(NSString*)logOn address:(UInt32)addr port:(UInt16)port {
	UserInfo*	info = nil;
	int			i;
	[lock lock];
	for (i = 0; i < [userList count]; i++) {
		UserInfo* u = [userList objectAtIndex:i];
		if ([u.logOnName isEqualToString:logOn] &&
			(u.ipAddressNumber == addr) &&
			(u.portNo == port)) {
			info = [[u retain] autorelease];
			break;
		}
	}
	[lock unlock];
	return info;
}

/*----------------------------------------------------------------------------*
 * ユーザ情報追加／削除-------用户信息添加/删除
 *----------------------------------------------------------------------------*/

// ユーザ一覧変更通知発行
// 用户列表变更通知
- (void)fireUserListChangeNotice {
	[[NSNotificationCenter defaultCenter] postNotificationName:NOTICE_USER_LIST_CHANGED object:nil];
}

// ユーザ追加---------添加用户
- (void)appendUser:(UserInfo*)info {
	if (info) {
		[lock lock];
		int index = [userList indexOfObject:info];
		if (index == NSNotFound) {
			// なければ追加-------不存在，则添加
			[userList addObject:info];
		} else {
			// あれば置き換え-----存在，则替换
			[userList replaceObjectAtIndex:index withObject:info];
		}
		// ダイアルアップユーザであればアドレス一覧を更新
        // 如果拨号用户,更新地址列表，
		if (info.dialupConnect) {
			[dialupSet addObject:[[info.ipAddress copy] autorelease]];
		}
		[lock unlock];
		[self fireUserListChangeNotice];
	}
}

// バージョン情報設定-------版本信息设置
- (void)setVersion:(NSString*)version ofUser:(UserInfo*)user {
	if (user) {
		[lock lock];
		int index = [userList indexOfObject:user];
		if (index != NSNotFound) {
			// あれば設定---设置version
			user.version = version;
			[self fireUserListChangeNotice];
		}
		[lock unlock];
	}
}

// ユーザ削除----------删除用户
- (void)removeUser:(UserInfo*)info {
	if (info) {
		[lock lock];
		int index = [userList indexOfObject:info];
		if (index != NSNotFound) {
			// あれば削除--------删除，同时删除拨号连接
			[userList removeObjectAtIndex:index];
			if ([dialupSet containsObject:info.ipAddress]) {
				[dialupSet removeObject:info.ipAddress];
			}
			[self fireUserListChangeNotice];
		}
		[lock unlock];
	}
}

// ずべてのユーザを削除-----------删除所有用户
- (void)removeAllUsers {
	[lock lock];
	[userList removeAllObjects];
	[dialupSet removeAllObjects];
	[lock unlock];
	[self fireUserListChangeNotice];
}

// ダイアルアップアドレス一覧------------拨接地址列表
- (NSArray*)dialupAddresses {
	[lock lock];
	NSArray* array = [dialupSet allObjects];
	[lock unlock];
	return array;
}

@end
