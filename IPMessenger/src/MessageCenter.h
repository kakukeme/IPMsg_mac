/*============================================================================*
 * (C) 2001-2011 G.Ishiwata, All Rights Reserved.
 *
 *	Project		: IP Messenger for Mac OS X
 *	File		: MessageCenter.h
 *	Module		: メッセージ送受信管理クラス----------消息管理类
 *============================================================================*/

#import <Foundation/Foundation.h>
#import <SystemConfiguration/SCDynamicStore.h>

@class RecvMessage;
@class SendMessage;

/*============================================================================*
 * Notification キー
 *============================================================================*/

// ホスト名変更-------------主机名称变更
#define NOTICE_HOSTNAME_CHANGED		@"IPMsgHostNameChanged"
// ネットワーク検出/喪失---------网络获取/丢失
#define NOTICE_NETWORK_GAINED		@"IPMsgNetworkGained"
#define NOTICE_NETWORK_LOST			@"IPMsgNetworkLost"

/*============================================================================*
 * 構造体定義----------结构体定义
 *============================================================================*/

// IPMsg受信パケット解析構造体---------IPMsg消息数据包结构
typedef struct
{
	unsigned	version;			// バージョン番号-----------版本号
	unsigned	packetNo;			// パケット番号---------包号
	char		userName[256];		// ログインユーザ名-------登录用户名
	char		hostName[256];		// ホスト名-------主机名
	unsigned	command;			// コマンド番号------命令编号
	char		extension[4096];	// 拡張部----------扩展部分

} IPMsgData;
/*
 
 1) 数据包格式(版本1的格式)
 
	Ver(1) : Packet番号 : 自User名 : 自Host名 : Command番号 : 追加部
 
	版本号(1) : 包编号 : 发送者姓名 : 发送者主机名 : 命令字 : 附加信息
 
 2) 举例如下
 
	"1:100:shirouzu:jupiter:32:Hello"
*/

/*============================================================================*
 * クラス定義-----------类定义
 *============================================================================*/

@interface MessageCenter : NSObject
{
	// 送受信関連-----发送信息相关
	int						sockUDP;			// ソケットディスクリプタ----------套接字描述符
	NSLock*					sockLock;			// ソケット送信排他ロック-------------套接字发送独占锁
	NSMutableDictionary*	sendList;			// 応答待ちメッセージ一覧（再送用）-------待发送消息列表（重发）
    
	// 受信サーバ関連------关于服务器接收
	NSConnection*			serverConnection;	// メッセージ受信スレッドとのコネクション------服务器连接
	NSLock*					serverLock;			// サーバ待ち合わせ用ロック----------服务器等待锁
	BOOL					serverShutdown;		// サーバ停止フラグ----------服务器停止标志
    
	// 現在値--------现在值
	NSString*				primaryNIC;			// 有線ネットワークインタフェース----------有线网络接口
	unsigned long			myIPAddress;		// ローカルホストアドレス------------本地主机地址
	NSInteger				myPortNo;			// ソケットポート番号------套接字端口号
	NSString*				myHostName;			// コンピュータ名-----我的主机名
    
	// DynamicStore関連---DynamicStore相关
	CFRunLoopSourceRef		runLoopSource;		// Run Loop Source Obj for SC Notification
	SCDynamicStoreRef		scDynStore;			// DynamicStore
	SCDynamicStoreContext	scDSContext;		// DynamicStoreContext
	NSString*				scKeyHostName;		// DynamicStore Key [for LocalHostName]
	NSString*				scKeyNetIPv4;		// DynamicStore Key [for Global IPv4]
	NSString*				scKeyIFIPv4;		// DynamicStore Key [for IF IPv4 Address]
}

// ファクトリ-----单例，工厂
+ (MessageCenter*)sharedCenter;

// クラスメソッド-----------类方法
+ (long)nextMessageID;
+ (BOOL)isNetworkLinked;

// 受信Rawデータの分解---------接收数据解析
+ (BOOL)parseReceiveData:(char*)buffer length:(int)len into:(IPMsgData*)data;

// メッセージ送信（ブロードキャスト）------------信息传输（广播）
- (void)broadcastEntry;             // 用户上线
- (void)broadcastAbsence;           // 用户离线
- (void)broadcastExit;              // 用户退出

// メッセージ送信（通常）---------------信息传输（通常情况下）
- (void)sendMessage:(SendMessage*)msg to:(NSArray*)to;
- (void)sendOpenSealMessage:(RecvMessage*)info;
- (void)sendReleaseAttachmentMessage:(RecvMessage*)info;

// 情報取得----------情报取得
- (int)myPortNo;                // 获取端口
- (NSString*)myHostName;        // 获取主机名

@end
