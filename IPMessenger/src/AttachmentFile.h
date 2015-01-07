/*============================================================================*
 * (C) 2001-2011 G.Ishiwata, All Rights Reserved.
 *
 *	Project		: IP Messenger for Mac OS X
 *	File		: AttachmentFile.h
 *	Module		: 添付ファイルオブジェクトクラス-------附件对象
 *============================================================================*/

#import <Cocoa/Cocoa.h>

/*============================================================================*
 * クラス定義
 *============================================================================*/

@interface AttachmentFile : NSObject
{
	NSString*		_name;
	NSString*		_nameEscaped;       // 转义后的文件名，":"---->"::"
	NSString*		_path;
	UInt64			_size;
	UInt32			_attribute;
	NSDate*			_createTime;
	NSDate*			_modifyTime;

	OSType				hfsFileType;		// ファイルタイプ--------------文件类型
	OSType				hfsCreator;			// クリエータコード-------------文件创建者
	UInt16				finderFlags;		// Finder属性フラグ（Carbon）---Finder属性转折点（Carbon）
	unsigned			permission;			// POSIXファイルアクセス権-------POSIX文件存取权限
	NSFileHandle*		handle;				// 出力ハンドル-----------------文件handle
}

@property(readonly)			NSString*	name;			// ファイル名----------------文件名
@property(readonly)			NSString*	path;			// ファイルパス--------------文件路径
@property(readonly)			UInt64		size;			// ファイルサイズ------------文件大小
@property(readonly)			UInt32		attribute;		// ファイル属性(IPMsg形式)----文件属性（IPMsg形式）
@property(retain,readonly)	NSDate*		createTime;		// ファイル生成時刻-----------文件创建时间
@property(retain,readonly)	NSDate*		modifyTime;		// ファイル最終更新時刻(mtime)---文件最后更新时间(mtime)

// ファクトリ
// 类方法，初始化
+ (id)fileWithPath:(NSString*)path;
+ (id)fileWithDirectory:(NSString*)dir file:(NSString*)file;
+ (id)fileWithMessage:(NSString*)str;
+ (id)fileWithDirectory:(NSString*)dir header:(NSString*)header;

// 初始化
- (id)initWithPath:(NSString*)path;
- (id)initWithDirectory:(NSString*)dir file:(NSString*)file;
- (id)initWithMessage:(NSString*)str;
- (id)initWithDirectory:(NSString*)dir header:(NSString*)header;

// getter/setter
- (BOOL)isRegularFile;
- (BOOL)isDirectory;                    // 是否是目录
- (BOOL)isParentDirectory;              // 是否是父目录
- (BOOL)isExtensionHidden;              // 是否隐藏
- (void)setDirectory:(NSString*)dir;

// アイコン---------图标
- (NSImage*)iconImage;

// ファイル入出力関連-----------输入输出相关文件
- (BOOL)isFileExists;
- (BOOL)openFileForWrite;
- (BOOL)writeData:(void*)data length:(unsigned)len;
- (void)closeFile;

// 添付処理関連-----------处理相关附件
- (NSString*)makeExtendAttribute;

@end
