/*============================================================================*
 * (C) 2001-2011 G.Ishiwata, All Rights Reserved.
 *
 *	Project		: IP Messenger for Mac OS X
 *	File		: Config.h
 *	Module		: 初期設定情報管理クラス----初始设定信息管理类
 *============================================================================*/

#import <Cocoa/Cocoa.h>

@class UserInfo;
@class RefuseInfo;

/*============================================================================*
 * 定数定義-------常量定义
 *============================================================================*/

// ノンポップアップ受信アイコンバウンド種別------非弹出接收图标绑定类型
typedef enum
{
	IPMSG_BOUND_ONECE	= 0,
	IPMSG_BOUND_REPEAT	= 1,
	IPMSG_BOUND_NONE	= 2

} IPMsgIconBoundType;

/*============================================================================*
 * クラス定義---------类定义
 *============================================================================*/

@interface Config : NSObject
{
	//-------- 不揮発の設定値（永続化必要）　------非易失性（必要的持久性）的设定值----------------------
	NSString*				_userName;
	NSString*				_groupName;
	NSString*				_password;
	BOOL					_useStatusBar;
	NSInteger				_portNo;
	BOOL					_dialup;
	NSMutableArray*			_broadcastHostList;
	NSMutableArray*			_broadcastIPList;
	NSArray*				_broadcastAddresses;
	NSString*				_quoteString;
	NSMutableArray*			_absenceList;
	NSMutableArray*			_refuseList;
	BOOL					_openNewOnDockClick;
	BOOL					_sealCheckDefault;
	BOOL					_hideRcvWinOnReply;
	BOOL					_noticeSealOpened;
	BOOL					_allowSendingMultiUser;
	NSFont*					_sendMessageFont;
	NSMutableDictionary*	_sendUserListColDisp;
	NSSound*				_receiveSound;
	BOOL					_quoteCheckDefault;
	BOOL					_nonPopup;
	BOOL					_nonPopupWhenAbsence;
	IPMsgIconBoundType		_nonPopupIconBound;
	BOOL					_useClickableURL;
	NSFont*					_receiveMessageFont;
	BOOL					_standardLogEnabled;
	BOOL					_logChainedWhenOpen;
	NSString*				_standardLogFile;
	BOOL					_alternateLogEnabled;
	BOOL					_logWithSelectedRange;
	NSString*				_alternateLogFile;
	BOOL					_sndSearchUser;
	BOOL					_sndSearchGroup;
	BOOL					_sndSearchHost;
	BOOL					_sndSearchLogon;
	NSSize					_sndWinSize;
	float					_sndWinSplit;
	NSSize					_rcvWinSize;
	//-------- 揮発の設定値（永続化不要）　----设置挥发（需要持久性）的--------------------------
	NSInteger				_absenceIndex;
	NSFont*					_defaultMessageFont;
	NSArray*				_defaultAbsences;
}

// 全般
@property(copy,readwrite)	NSString*			userName;					// ユーザ名---------用户名
@property(copy,readwrite)	NSString*			groupName;					// グループ名------组名
@property(copy,readwrite)	NSString*			password;					// パスワード--------密码
@property(assign,readwrite)	BOOL				useStatusBar;				// メニューバーの右端にアイコンを追加するか
//----添加一个图标，在菜单栏的右侧

// ネットワーク------网络
@property(assign,readwrite)	NSInteger			portNo;						// ポート番号---------端口号
@property(assign,readwrite)	BOOL				dialup;						// ダイアルアップ接続-----------拨号连接
@property(retain,readonly)	NSArray*			broadcastAddresses;			// ブロードキャストアドレス一覧-----广播地址列表


// アップデート--------更新
@property(assign,readwrite)	BOOL				updateAutomaticCheck;		// 更新自動チェック---------自动更新检查
@property(assign,readwrite)	NSTimeInterval		updateCheckInterval;		// 更新チェック間隔---------更新检查间隔


// 不在モード-------不在线模式
@property(readonly)			BOOL				inAbsence;					// 不在モード中か-----不在线
@property(assign,readwrite)	NSInteger			absenceIndex;				// 不在モード--------不在线模式


// 送信------发信息
@property(copy,readwrite)	NSString*			quoteString;				// 引用文字列----------引号的字符串
@property(assign,readwrite)	BOOL				openNewOnDockClick;			// Dockクリック時送信ウィンドウオープン----dock下点击打开信息发送窗口
@property(assign,readwrite)	BOOL				sealCheckDefault;			// 封書チェックをデフォルト---------默认封装检查
@property(assign,readwrite)	BOOL				hideReceiveWindowOnReply;	// 送信時受信ウィンドウをクローズ----关闭接收窗口传输
@property(assign,readwrite)	BOOL				noticeSealOpened;			// 開封確認を行う--------------已读回执
@property(assign,readwrite)	BOOL				allowSendingToMultiUser;	// 複数ユーザ宛送信を許可-----------多用户发送许可
@property(retain,readwrite)	NSFont*				sendMessageFont;			// 送信ウィンドウメッセージ部フォント--------发送信息字体
@property(readonly)			NSFont*				defaultSendMessageFont;		// 送信ウィンドウメッセージ標準フォント------默认的发送信息字体


// 受信-----接收信息
@property(retain,readonly)	NSSound*			receiveSound;				// 受信音---------接收音
@property(copy,readwrite)	NSString*			receiveSoundName;			// 受信音名-------接收音名
@property(assign,readwrite)	BOOL				quoteCheckDefault;			// 引用チェックをデフォルト---------引用检查
@property(assign,readwrite)	BOOL				nonPopup;					// ノンポップアップ受信---------无弹出接收
@property(assign,readwrite)	BOOL				nonPopupWhenAbsence;		// 不在時ノンポップアップ受信------------不在时直接弹出接收
@property(assign,readwrite)	IPMsgIconBoundType	iconBoundModeInNonPopup;	// ノンポップアップ受信時アイコンバウンド種別
//------图标绑定类型接收时不弹出

@property(assign,readwrite)	BOOL				useClickableURL;			// クリッカブルURLを使用する-----------可点击的URL
@property(retain,readwrite)	NSFont*				receiveMessageFont;			// 受信ウィンドウメッセージ部フォント--------接收消息字体
@property(readonly)			NSFont*				defaultReceiveMessageFont;	// 受信ウィンドウメッセージ標準フォント--------默认接收消息字体

// ログ-----登录
@property(assign,readwrite)	BOOL				standardLogEnabled;			// 標準ログを使用する----------标准的日志
@property(assign,readwrite)	BOOL				logChainedWhenOpen;			// 錠前付きは開封時にログ-----logchain
@property(copy,readwrite)	NSString*			standardLogFile;			// 標準ログファイルパス------标准日志文件的路径
@property(assign,readwrite)	BOOL				alternateLogEnabled;		// 重要ログを使用する-------重要的日志
@property(assign,readwrite)	BOOL				logWithSelectedRange;		// 選択範囲を記録する-------记录的选择
@property(copy,readwrite)	NSString*			alternateLogFile;			// 重要ログファイルパス---------重要的日志文件路径


// 送受信ウィンドウ-------发送和接收
@property(assign,readwrite)	NSSize				sendWindowSize;				// 送信ウィンドウサイズ---------发送和接收窗口尺寸
@property(assign,readwrite)	float				sendWindowSplit;			// 送信ウィンドウ分割位置-----------提交窗口分割位置
@property(assign,readwrite)	BOOL				sendSearchByUserName;		// 送信ユーザ検索（ユーザ名）------提交搜索用户（用户名）
@property(assign,readwrite)	BOOL				sendSearchByGroupName;		// 送信ユーザ検索（グループ名）
@property(assign,readwrite)	BOOL				sendSearchByHostName;		// 送信ユーザ検索（ホスト名）
@property(assign,readwrite)	BOOL				sendSearchByLogOnName;		// 送信ユーザ検索（ログオン名）
@property(assign,readwrite)	NSSize				receiveWindowSize;			// 受信ウィンドウサイズ--------接收窗口大小

// ファクトリ------工厂方法
+ (Config*)sharedConfig;

// 永続化-------保存
- (void)save;

// ----- getter / setter ------
// ネットワーク-----网络
- (NSUInteger)numberOfBroadcasts;
- (NSString*)broadcastAtIndex:(NSUInteger)index;
- (BOOL)containsBroadcastWithAddress:(NSString*)address;
- (BOOL)containsBroadcastWithHost:(NSString*)host;
- (void)addBroadcastWithAddress:(NSString*)address;
- (void)addBroadcastWithHost:(NSString*)host;
- (void)removeBroadcastAtIndex:(NSUInteger)index;

// 不在-----离线
- (NSUInteger)numberOfAbsences;
- (NSString*)absenceTitleAtIndex:(NSUInteger)index;
- (NSString*)absenceMessageAtIndex:(NSUInteger)index;
- (BOOL)containsAbsenceTitle:(NSString*)title;
- (void)addAbsenceTitle:(NSString*)title message:(NSString*)msg;
- (void)insertAbsenceTitle:(NSString*)title message:(NSString*)msg atIndex:(NSUInteger)index;
- (void)setAbsenceTitle:(NSString*)title message:(NSString*)msg atIndex:(NSInteger)index;
- (void)upAbsenceAtIndex:(NSUInteger)index;
- (void)downAbsenceAtIndex:(NSUInteger)index;
- (void)removeAbsenceAtIndex:(NSUInteger)index;
- (void)resetAllAbsences;

// 通知拒否
- (NSUInteger)numberOfRefuseInfo;
- (RefuseInfo*)refuseInfoAtIndex:(NSUInteger)index;
- (void)addRefuseInfo:(RefuseInfo*)info;
- (void)insertRefuseInfo:(RefuseInfo*)info atIndex:(NSUInteger)index;
- (void)setRefuseInfo:(RefuseInfo*)info atIndex:(NSUInteger)index;
- (void)upRefuseInfoAtIndex:(NSUInteger)index;
- (void)downRefuseInfoAtIndex:(NSUInteger)index;
- (void)removeRefuseInfoAtIndex:(NSUInteger)index;
- (BOOL)matchRefuseCondition:(UserInfo*)user;

// 送信ウィンドウ設定
- (BOOL)sendWindowUserListColumnHidden:(id)identifier;
- (void)setSendWindowUserListColumn:(id)identifier hidden:(BOOL)hidden;

@end
