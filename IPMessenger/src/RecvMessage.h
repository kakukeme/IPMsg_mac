/*============================================================================*
 * (C) 2001-2011 G.Ishiwata, All Rights Reserved.
 *
 *	Project		: IP Messenger for Mac OS X
 *	File		: RecvMessage.h
 *	Module		: 受信メッセージクラス-------接收消息类
 *============================================================================*/

#import <Foundation/Foundation.h>
#import <netinet/in.h>

@class UserInfo;

/*============================================================================*
 * クラス定義--------类定义
 *============================================================================*/

@interface RecvMessage : NSObject <NSCopying>
{
	UserInfo*			fromUser;		// 送信元ユーザ--------源用户
	BOOL				unknownUser;	// 未知のユーザフラグ-----用户未知的标志
	NSString*			logOnUser;		// ログイン名--------登录名
	NSString*			hostName;		// ホスト名------主机名
	unsigned long		command;		// コマンド番号-------命令编号
	NSString*			appendix;		// 追加部-----------追加部分
	NSString*			appendixOption;	// 追加部オプション----追加单元选项
	NSMutableArray*		attachments;	// 添付ファイル-------附件
	NSMutableArray*		hostList;		// ホストリスト---------主机列表
	int					continueCount;	// ホストリスト継続ユーザ番号------主机列表用户继续数
	BOOL				needLog;		// ログ出力フラグ--------日志输出标志

	NSInteger			_packetNo;
	NSDate*				_date;
	struct sockaddr_in	_address;

}

@property(readonly)	NSInteger			packetNo;		// パケット番号------包号
@property(readonly)	NSDate*				receiveDate;	// 受信日時--------接收时间
//@property(readonly)	struct sockaddr_in	fromAddress;	// 送信元アドレス

// ファクトリ--------工厂
+ (RecvMessage*)messageWithBuffer:(const void*)buf
						   length:(NSUInteger)len
							 from:(struct sockaddr_in)addr;

// 初期化／解放
- (id)initWithBuffer:(const void*)buf
			  length:(NSUInteger)len
				from:(struct sockaddr_in)addr;

// getter（相手情報）
- (UserInfo*)fromUser;
- (BOOL)isUnknownUser;

// getter（共通）
//- (NSString*)logOnUser;
//- (NSString*)hostName;
- (unsigned long)command;
- (NSString*)appendix;
//- (NSString*)appendixOption;

// getter（IPMSG_SENDMSGのみ）
- (BOOL)sealed;
- (BOOL)locked;
- (BOOL)multicast;
- (BOOL)broadcast;
- (BOOL)absence;
- (NSArray*)attachments;

// getter（IPMSG_ANSLISTのみ）
- (NSArray*)hostList;
- (int)hostListContinueCount;

// その他----其他
- (void)removeDownloadedAttachments;
- (BOOL)needLog;
- (void)setNeedLog:(BOOL)flag;

@end
