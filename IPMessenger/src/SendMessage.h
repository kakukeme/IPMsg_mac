/*============================================================================*
 * (C) 2001-2011 G.Ishiwata, All Rights Reserved.
 *
 *	Project		: IP Messenger for Mac OS X
 *	File		: SendMessage.h
 *	Module		: 送信メッセージクラス--------发送消息类
 *============================================================================*/

#import <Foundation/Foundation.h>

/*============================================================================*
 * クラス定義--------类定义
 *============================================================================*/

@interface SendMessage : NSObject <NSCopying>
{
	NSInteger	_packetNo;
	NSString*	_message;
	NSArray*	_attach;
	BOOL		_sealed;
	BOOL		_locked;
}

@property(readonly)			NSInteger	packetNo;		// パケット番号---------包号
@property(copy,readonly)	NSString*	message;		// 送信メッセージ------发送的消息
@property(retain,readonly)	NSArray*	attachments;	// 添付ファイル------附件
@property(readonly)			BOOL		sealed;			// 封書フラグ-----书信密封标志
@property(readonly)			BOOL		locked;			// 施錠フラグ----锁定标志

// ファクトリ----工厂
+ (id)messageWithMessage:(NSString*)msg
			 attachments:(NSArray*)attach
					seal:(BOOL)seal
					lock:(BOOL)lock;

// 初期化-----初始化
- (id)initWithMessage:(NSString*)msg
		  attachments:(NSArray*)attach
				 seal:(BOOL)seal
				 lock:(BOOL)lock;

@end
