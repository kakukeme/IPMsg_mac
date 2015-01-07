/*============================================================================*
 * (C) 2001-2011 G.Ishiwata, All Rights Reserved.
 *
 *	Project		: IP Messenger for Mac OS X
 *	File		: SendControl.h
 *	Module		: 送信メッセージウィンドウコントローラ-----发送消息窗口控制器
 *============================================================================*/

#import <Cocoa/Cocoa.h>

@class UserInfo;
@class RecvMessage;

/*============================================================================*
 * クラス定義-------类定义
 *============================================================================*/

@interface SendControl : NSObject
{
	IBOutlet NSWindow*		window;				// 送信ウィンドウ-----发送消息窗口
	IBOutlet NSSplitView*	splitView;
	IBOutlet NSView*		splitSubview1;
	IBOutlet NSView*		splitSubview2;
	IBOutlet NSSearchField*	searchField;		// ユーザ検索フィールド--------用户搜索栏
	IBOutlet NSMenu*		searchMenu;			// ユーザ検索メニュー--------用户搜索菜单
	IBOutlet NSTableView*	userTable;			// ユーザ一覧--------用户列表
	IBOutlet NSTextField*	userNumLabel;		// ユーザ数ラベル-----用户标签数
	IBOutlet NSButton*		refreshButton;		// 更新ボタン-------更新按钮
	IBOutlet NSButton*		passwordCheck;		// 鍵チェックボックス----Lock复选框
	IBOutlet NSButton*		sealCheck;			// 封書チェックボックス----seal复选框
	IBOutlet NSTextView*	messageArea;		// メッセージ入力欄------消息输入区域
	IBOutlet NSButton*		sendButton;			// 送信ボタン---------send按钮
	IBOutlet NSButton*		attachButton;		// 添付ファイルDrawerトグルボタン----附件抽屉切换按钮
	IBOutlet NSDrawer*		attachDrawer;		// 添付ファイルDrawer-----附件抽屉
	IBOutlet NSTableView*	attachTable;		// 添付ファイル一覧-------附加的文件列表
	IBOutlet NSButton*		attachAddButton;	// 添付追加ボタン-------添加附件按钮
	IBOutlet NSButton*		attachDelButton;	// 添付削除ボタン------删除附件按钮
    
	NSMutableArray*			attachments;		// 添付ファイル-------附件
	NSMutableDictionary*	attachmentsDic;		// 添付ファイル辞書----附件字典
	RecvMessage*			receiveMessage;		// 返信元メッセージ-----返回的答复消息
	NSMutableArray*			users;				// ユーザリスト--------用户列表
	NSPredicate*			userPredicate;		// ユーザ検索フィルタ-----用户搜索过滤器
	NSMutableArray*			selectedUsers;		// 選択ユーザリスト-------选择的用户列表
	NSLock*					selectedUsersLock;	// 選択ユーザリストロック------选择用户列表中的锁
}

// 初期化
- (id)initWithSendMessage:(NSString*)msg recvMessage:(RecvMessage*)recv;

// ハンドラ -----Action
- (IBAction)buttonPressed:(id)sender;
- (IBAction)checkboxChanged:(id)sender;

- (IBAction)searchUser:(id)sender;
- (IBAction)updateUserSearch:(id)sender;
- (IBAction)searchMenuItemSelected:(id)sender;

- (IBAction)sendPressed:(id)sender;
- (IBAction)sendMessage:(id)sender;
- (IBAction)userListUserMenuItemSelected:(id)sender;
- (IBAction)userListGroupMenuItemSelected:(id)sender;
- (IBAction)userListHostMenuItemSelected:(id)sender;
- (IBAction)userListIPAddressMenuItemSelected:(id)sender;
- (IBAction)userListLogonMenuItemSelected:(id)sender;
- (IBAction)userListVersionMenuItemSelected:(id)sender;
- (void)userListChanged:(NSNotification*)aNotification;

// 添付ファイル------附件
- (void)appendAttachmentByPath:(NSString*)path;

// その他----------其他
- (IBAction)updateUserList:(id)sender;
- (NSWindow*)window;
- (void)setAttachHeader;

@end
