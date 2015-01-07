/*============================================================================*
 * (C) 2001-2011 G.Ishiwata, All Rights Reserved.
 *
 *	Project		: IP Messenger for Mac OS X
 *	File		: UserInfo.h
 *	Module		: ユーザ情報クラス-----用户信息类
 *============================================================================*/

#import <Foundation/Foundation.h>
#import <netinet/in.h>

@class RecvMessage;

/*============================================================================*
 * プロパティ識別定義--------标示符定义
 *============================================================================*/

extern NSString* const kIPMsgUserInfoUserNamePropertyIdentifier;
extern NSString* const kIPMsgUserInfoGroupNamePropertyIdentifier;
extern NSString* const kIPMsgUserInfoHostNamePropertyIdentifier;
extern NSString* const kIPMsgUserInfoLogOnNamePropertyIdentifier;
extern NSString* const kIPMsgUserInfoIPAddressPropertyIdentifier;
extern NSString* const kIPMsgUserInfoVersionPropertyIdentifer;

/*============================================================================*
 * クラス定義 ------类定义
 *============================================================================*/

@interface UserInfo : NSObject <NSCopying>
{
	NSString*			_userName;
	NSString*			_groupName;
	NSString*			_hostName;
	NSString*			_logOnName;
	struct sockaddr_in	_address;
	NSString*			_ipAddress;
	UInt32				_ipAddressNumber;
	UInt16				_portNo;
	NSString*			_version;
	BOOL				_absence;
	BOOL				_dialup;
	BOOL				_attachment;
	BOOL				_encrypt;
	BOOL				_UTF8;
}

@property(copy,readonly)	NSString*	userName;			// IPMsgユーザ名（ニックネーム）-----ipmsg用户名(昵称)
@property(copy,readonly)	NSString*	groupName;			// IPMsgグループ名 ------- IPMsg组名
@property(copy,readonly)	NSString*	hostName;			// マシン名----------机器名/主机名
@property(copy,readonly)	NSString*	logOnName;			// ログインユーザ名------登录用户名
@property(readonly)	struct sockaddr_in	address;			// 接続アドレス-------连接地址
@property(copy,readonly)	NSString*	ipAddress;			// IPアドレス（文字列）--------IP地址（字符串）
@property(readonly)			UInt32		ipAddressNumber;	// IPアドレス（数値）------------IP地址（数值）
@property(readonly)			UInt16		portNo;				// ポート番号---------端口号
@property(copy,readwrite)	NSString*	version;			// バージョン情報---------版本信息
@property(readonly)			BOOL		inAbsence;			// 不在--------------缺席/离线
@property(readonly)			BOOL		dialupConnect;		// ダイアルアップ接続------拨号连接
@property(readonly)			BOOL		supportsAttachment;	// ファイル添付サポート-------文件附件支持
@property(readonly)			BOOL		supportsEncrypt;	// 暗号化サポート----------加密支持
@property(readonly)			BOOL		supportsUTF8;		// UTF-8サポート---------UTF-8支持
@property(readonly)			NSString*	summaryString;		// 表示用文字列-----------显示字符串

// ファクトリ
// 工厂方法
+ (id)userWithUserName:(NSString*)user
			 groupName:(NSString*)group
			  hostName:(NSString*)host
			 logOnName:(NSString*)logOn
			   address:(struct sockaddr_in*)addr
			   command:(UInt32)cmd;

+ (id)userWithHostList:(NSArray*)itemArray fromIndex:(unsigned)index;

// 初期化
// 初始化
- (id)initWithUserName:(NSString*)user
			 groupName:(NSString*)group
			  hostName:(NSString*)host
			 logOnName:(NSString*)logOn
			   address:(struct sockaddr_in*)addr
			   command:(UInt32)cmd;

- (id)initWithHostList:(NSArray*)itemArray fromIndex:(unsigned)index;

@end
