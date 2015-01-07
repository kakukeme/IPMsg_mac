/*============================================================================*
 * (C) 2001-2011 G.Ishiwata, All Rights Reserved.
 *
 *	Project		: IP Messenger for Mac OS X
 *	File		: RefuseInfo.h
 *	Module		: 通知拒否条件情報クラス---------通知拒绝条件类信息
 *============================================================================*/

#import <Foundation/Foundation.h>

@class UserInfo;

/*============================================================================*
 * 定数定義
 *============================================================================*/

// 拒否判定対象----拒绝判定对象/目标
typedef enum
{
	IP_REFUSE_USER,			// ユーザ名---------用户名
	IP_REFUSE_GROUP,		// グループ名--------组名
	IP_REFUSE_MACHINE,		// マシン名------机器名
	IP_REFUSE_LOGON,		// ログオン名-----登录名
	IP_REFUSE_ADDRESS		// IPアドレス------IP地址

} IPRefuseTarget;

// 拒否判定条件-------拒绝判定条件
typedef enum
{
	IP_REFUSE_MATCH,		// 一致する------一致/匹配
	IP_REFUSE_CONTAIN,		// 含む----------包含
	IP_REFUSE_START,		// 始まる-------开始
	IP_REFUSE_END			// 終わる-------结束

} IPRefuseCondition;

/*============================================================================*
 * クラス定義
 *============================================================================*/

@interface RefuseInfo : NSObject
{
	IPRefuseTarget		_target;
	NSString*			_string;
	IPRefuseCondition	_condition;
}

@property(assign,readwrite)	IPRefuseTarget		target;		// 判定対象/目标
@property(copy,readwrite)	NSString*			string;		// 文字列------字符串
@property(assign,readwrite) IPRefuseCondition	condition;	// 判定条件

// ファクトリ-------工厂方法
+ (id)refuseInfoWithTarget:(IPRefuseTarget)aTarget
					string:(NSString*)aString
				 condition:(IPRefuseCondition)aCondition;

// 初期化--------初始化
- (id)initWithTarget:(IPRefuseTarget)aTarget
			  string:(NSString*)aString
		   condition:(IPRefuseCondition)aCondition;

// 判定
- (BOOL)match:(UserInfo*)user;

@end
